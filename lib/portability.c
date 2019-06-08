/* portability.c - code to workaround the deficiencies of various platforms.
 *
 * Copyright 2012 Rob Landley <rob@landley.net>
 * Copyright 2012 Georgi Chorbadzhiyski <gf@unixsol.org>
 */

#include "toys.h"

// We can't fork() on nommu systems, and vfork() requires an exec() or exit()
// before resuming the parent (because they share a heap until then). And no,
// we can't implement our own clone() call that does the equivalent of fork()
// because nommu heaps use physical addresses so if we copy the heap all our
// pointers are wrong. (You need an mmu in order to map two heaps to the same
// address range without interfering with each other.) In the absence of
// a portable way to tell malloc() to start a new heap without freeing the old
// one, you pretty much need the exec().)

// So we exec ourselves (via /proc/self/exe, if anybody knows a way to
// re-exec self without depending on the filesystem, I'm all ears),
// and use the arguments to signal reentry.

#if CFG_TOYBOX_FORK
pid_t xfork(void)
{
  pid_t pid = fork();

  if (pid < 0) perror_exit("fork");

  return pid;
}
#endif

int xgetrandom(void *buf, unsigned buflen, unsigned flags)
{
  int fd;

#if CFG_TOYBOX_GETRANDOM
  if (buflen == getrandom(buf, buflen, flags&~WARN_ONLY)) return 1;
  if (errno!=ENOSYS && !(flags&WARN_ONLY)) perror_exit("getrandom");
#endif
  fd = xopen(flags ? "/dev/random" : "/dev/urandom",O_RDONLY|(flags&WARN_ONLY));
  if (fd == -1) return 0;
  xreadall(fd, buf, buflen);
  close(fd);

  return 1;
}

// Get a linked list of mount points, with stat information.
#if defined(__APPLE__) || defined(__FreeBSD__)

// Not implemented for macOS.
// See <sys/mount.h>'s getmntinfo(3) for the BSD API.

#else

#include <mntent.h>

static void octal_deslash(char *s)
{
  char *o = s;

  while (*s) {
    if (*s == '\\') {
      int i, oct = 0;

      for (i = 1; i < 4; i++) {
        if (!isdigit(s[i])) break;
        oct = (oct<<3)+s[i]-'0';
      }
      if (i == 4) {
        *o++ = oct;
        s += i;
        continue;
      }
    }
    *o++ = *s++;
  }

  *o = 0;
}

// Check if this type matches list.
// Odd syntax: typelist all yes = if any, typelist all no = if none.

int mountlist_istype(struct mtab_list *ml, char *typelist)
{
  int len, skip;
  char *t;

  if (!typelist) return 1;

  skip = strncmp(typelist, "no", 2);

  for (;;) {
    if (!(t = comma_iterate(&typelist, &len))) break;
    if (!skip) {
      // If one -t starts with "no", the rest must too
      if (strncmp(t, "no", 2)) error_exit("bad typelist");
      if (!strncmp(t+2, ml->type, len-2)) {
        skip = 1;
        break;
      }
    } else if (!strncmp(t, ml->type, len) && !ml->type[len]) {
      skip = 0;
      break;
    }
  }

  return !skip;
}

// Get list of mounted filesystems, including stat and statvfs info.
// Returns a reversed list, which is good for finding overmounts and such.

struct mtab_list *xgetmountlist(char *path)
{
  struct mtab_list *mtlist = 0, *mt;
  struct mntent *me;
  FILE *fp;
  char *p = path ? path : "/proc/mounts";

  if (!(fp = setmntent(p, "r"))) perror_exit("bad %s", p);

  // The "test" part of the loop is done before the first time through and
  // again after each "increment", so putting the actual load there avoids
  // duplicating it. If the load was NULL, the loop stops.

  while ((me = getmntent(fp))) {
    mt = xzalloc(sizeof(struct mtab_list) + strlen(me->mnt_fsname) +
      strlen(me->mnt_dir) + strlen(me->mnt_type) + strlen(me->mnt_opts) + 4);
    dlist_add_nomalloc((void *)&mtlist, (void *)mt);

    // Collect details about mounted filesystem
    // Don't report errors, just leave data zeroed
    if (!path) {
      stat(me->mnt_dir, &(mt->stat));
      statvfs(me->mnt_dir, &(mt->statvfs));
    }

    // Remember information from /proc/mounts
    mt->dir = stpcpy(mt->type, me->mnt_type)+1;
    mt->device = stpcpy(mt->dir, me->mnt_dir)+1;
    mt->opts = stpcpy(mt->device, me->mnt_fsname)+1;
    strcpy(mt->opts, me->mnt_opts);

    octal_deslash(mt->dir);
    octal_deslash(mt->device);
  }
  endmntent(fp);

  return mtlist;
}

#endif

#ifdef __APPLE__

#include <sys/event.h>

struct xnotify *xnotify_init(int max)
{
  struct xnotify *not = xzalloc(sizeof(struct xnotify));

  not->max = max;
  if ((not->kq = kqueue()) == -1) perror_exit("kqueue");
  not->paths = xmalloc(max * sizeof(char *));
  not->fds = xmalloc(max * sizeof(int));

  return not;
}

int xnotify_add(struct xnotify *not, int fd, char *path)
{
  struct kevent event;

  if (not->count == not->max) error_exit("xnotify_add overflow");
  EV_SET(&event, fd, EVFILT_VNODE, EV_ADD|EV_CLEAR, NOTE_WRITE, 0, NULL);
  if (kevent(not->kq, &event, 1, NULL, 0, NULL) == -1 || event.flags & EV_ERROR)
    return -1;
  not->paths[not->count] = path;
  not->fds[not->count++] = fd;

  return 0;
}

int xnotify_wait(struct xnotify *not, char **path)
{
  struct kevent event;
  int i;

  for (;;) {
    if (kevent(not->kq, NULL, 0, &event, 1, NULL) != -1) {
      // We get the fd for free, but still have to search for the path.
      for (i = 0; i<not->count; i++) if (not->fds[i]==event.ident) {
        *path = not->paths[i];

        return event.ident;
      }
    }
  }
}

#else

#include <sys/inotify.h>

struct xnotify *xnotify_init(int max)
{
  struct xnotify *not = xzalloc(sizeof(struct xnotify));

  not->max = max;
  if ((not->kq = inotify_init()) < 0) perror_exit("inotify_init");
  not->paths = xmalloc(max * sizeof(char *));
  not->fds = xmalloc(max * 2 * sizeof(int));

  return not;
}

int xnotify_add(struct xnotify *not, int fd, char *path)
{
  int i = 2*not->count;

  if (not->max == not->count) error_exit("xnotify_add overflow");
  if ((not->fds[i] = inotify_add_watch(not->kq, path, IN_MODIFY))==-1)
    return -1;
  not->fds[i+1] = fd;
  not->paths[not->count++] = path;

  return 0;
}

int xnotify_wait(struct xnotify *not, char **path)
{
  struct inotify_event ev;
  int i;

  for (;;) {
    if (sizeof(ev)!=read(not->kq, &ev, sizeof(ev))) perror_exit("inotify");

    for (i = 0; i<not->count; i++) if (ev.wd==not->fds[2*i]) {
      *path = not->paths[i];

      return not->fds[2*i+1];
    }
  }
}

#endif
