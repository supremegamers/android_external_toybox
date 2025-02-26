// toys/android/log.c

struct log_data {
  char *t, *p;

  int pri;
};

// toys/example/demo_number.c

struct demo_number_data {
  long M, D;
};

// toys/example/hello.c

struct hello_data {
  int unused;
};

// toys/example/skeleton.c

struct skeleton_data {
  union {
    struct {
      char *b;
      long c;
      struct arg_list *d;
      long e;
      char *f, *g, *h, *also, *blubber;
    } s;
    struct {
      long b;
    } a;
  };

  int more_globals;
};

// toys/lsb/dmesg.c

struct dmesg_data {
  long n, s;

  int use_color;
  time_t tea;
};

// toys/lsb/gzip.c

struct gzip_data {
  int level;
};

// toys/lsb/hostname.c

struct hostname_data {
  char *F;
};

// toys/lsb/killall.c

struct killall_data {
  char *s;

  int signum;
  pid_t cur_pid;
  char **names;
  short *err;
  struct int_list { struct int_list *next; int val; } *pids;
};

// toys/lsb/md5sum.c

struct md5sum_data {
  int sawline;
  unsigned *rconsttable32;
  unsigned long long *rconsttable64; // for sha384,sha512

  // Crypto variables blanked after summing
  unsigned long long count, overflow;
  union {
    char c[128]; // bytes, 1024 bits
    unsigned i32[16]; // 512 bits for md5,sha1,sha224,sha256
    unsigned long long i64[16]; // 1024 bits for sha384,sha512
  } state, buffer;
};

// toys/lsb/mknod.c

struct mknod_data {
  char *Z, *m;
};

// toys/lsb/mktemp.c

struct mktemp_data {
  char *p, *tmpdir;
};

// toys/lsb/mount.c

struct mount_data {
  struct arg_list *o;
  char *t, *O;

  unsigned long flags;
  char *opts;
  int okuser;
};

// toys/lsb/passwd.c

struct passwd_data {
  char *a;
};

// toys/lsb/pidof.c

struct pidof_data {
  char *o;
};

// toys/lsb/seq.c

struct seq_data {
  char *s, *f;

  int precision, buflen;
};

// toys/lsb/su.c

struct su_data {
  char *s;
  char *c;
};

// toys/lsb/umount.c

struct umount_data {
  struct arg_list *t;

  char *types;
};

// toys/net/ftpget.c

struct ftpget_data {
  char *u, *p, *P;

  int fd;
};

// toys/net/host.c

struct host_data {
  char *t;

  char **nsname;
  unsigned nslen;
};

// toys/net/ifconfig.c

struct ifconfig_data {
  int sockfd;
};

// toys/net/microcom.c

struct microcom_data {
  long s;

  int fd, stok;
  struct termios old_stdin, old_fd;
};

// toys/net/netcat.c

struct netcat_data {
  char *f, *s;
  long q, p, W, w;
};

// toys/net/netstat.c

struct netstat_data {
  struct num_cache *inodes;
  int wpad;
};

// toys/net/ping.c

struct ping_data {
  char *I;
  long w, W, i, s, c, t, m;

  struct sockaddr *sa;
  int sock;
  unsigned long sent, recv, fugit, min, max;
};

// toys/net/sntp.c

struct sntp_data {
  long r, t;
  char *p, *m, *M;
};

// toys/net/tunctl.c

struct tunctl_data {
  char *u;
};

// toys/net/wget.c

struct wget_data {
  char *p, *O;
  long max_redirect;

  int sock, https;
  char *url;
#if CFG_WGET_LIBTLS
  struct tls *tls;
#elif CFG_TOYBOX_LIBCRYPTO
  struct ssl_ctx_st *ctx;
  struct ssl_st *ssl;
#endif
};

// toys/other/acpi.c

struct acpi_data {
  int ac, bat, therm, cool;
  char *cpath;
};

// toys/other/base64.c

struct base64_data {
  long w;

  unsigned total;
  unsigned n;  // number of bits used in encoding. 5 for base32, 6 for base64
  unsigned align;  // number of bits to align to
};

// toys/other/blkdiscard.c

struct blkdiscard_data {
  long o, l;
};

// toys/other/blkid.c

struct blkid_data {
  struct arg_list *s;
  char *o;
};

// toys/other/blockdev.c

struct blockdev_data {
  long setbsz, setra;
};

// toys/other/chrt.c

struct chrt_data {
  long p;
};

// toys/other/dos2unix.c

struct dos2unix_data {
  char *tempfile;
};

// toys/other/fallocate.c

struct fallocate_data {
  long o, l;
};

// toys/other/fmt.c

struct fmt_data {
  long width;

  int level, pos;
};

// toys/other/free.c

struct free_data {
  unsigned bits;
  unsigned long long units;
  char *buf;
};

// toys/other/gpiod.c

struct gpiod_data {
  struct double_list *chips;
  int chip_count;
};

// toys/other/hexedit.c

struct hexedit_data {
  char *data, *search, keybuf[16], input[80];
  long long len, base, pos;
  int numlen, undo, undolen, mode;
  unsigned rows, cols;
};

// toys/other/hwclock.c

struct hwclock_data {
  char *f;
};

// toys/other/i2ctools.c

struct i2ctools_data {
  long F;
};

// toys/other/ionice.c

struct ionice_data {
  long p, n, c;
};

// toys/other/login.c

struct login_data {
  char *h, *f;

  int login_timeout, login_fail_timeout;
};

// toys/other/losetup.c

struct losetup_data {
  char *j;
  long o, S;

  int openflags;
  dev_t jdev;
  ino_t jino;
  char *dir;
};

// toys/other/lsattr.c

struct lsattr_data {
  long v, p;

  unsigned add, rm, set;
  // !add and !rm tell us whether they were used, but `chattr =` is meaningful.
  int have_set;
};

// toys/other/lsusb.c

struct lsusb_data {
  char *i;
  long x, n;

  void *ids, *class;
  int count;
};

// toys/other/makedevs.c

struct makedevs_data {
  char *d;
};

// toys/other/mix.c

struct mix_data {
   long r, l;
   char *d, *c;
};

// toys/other/mkpasswd.c

struct mkpasswd_data {
  long P;
  char *m, *S;
};

// toys/other/mkswap.c

struct mkswap_data {
  char *L;
};

// toys/other/modinfo.c

struct modinfo_data {
  char *F, *k, *b;

  long mod;
  int count;
};

// toys/other/nbd_client.c

struct nbd_client_data {
  long b;

  int nbd;
};

// toys/other/nsenter.c

struct nsenter_data {
  char *UupnmiC[7];
  long t;
};

// toys/other/oneit.c

struct oneit_data {
  char *c;
};

// toys/other/openvt.c

struct openvt_data {
  long c;
};

// toys/other/pwgen.c

struct pwgen_data {
  char *r;
};

// toys/other/readelf.c

struct readelf_data {
  char *x, *p;

  char *elf, *shstrtab, *f;
  unsigned long long shoff, phoff, size, shstrtabsz;
  int bits, endian, shnum, shentsize, phentsize;
};

// toys/other/readlink.c

struct readlink_data {
  char *R, *relative_base;
};

// toys/other/reboot.c

struct reboot_data {
  char *d;
};

// toys/other/rtcwake.c

struct rtcwake_data {
  long t, s;
  char *m, *d;
};

// toys/other/setfattr.c

struct setfattr_data {
  char *x, *v, *n;
};

// toys/other/sha3sum.c

struct sha3sum_data {
  long a;
  unsigned long long rc[24];
};

// toys/other/shred.c

struct shred_data {
  long o, n, s;
};

// toys/other/shuf.c

struct shuf_data {
  long n;

  char **lines;
  long count;
};

// toys/other/stat.c

struct stat_data {
  char *c;

  union {
    struct stat st;
    struct statfs sf;
  } stat;
  char *file, *pattern;
  int patlen;
};

// toys/other/swapon.c

struct swapon_data {
  long p;
};

// toys/other/switch_root.c

struct switch_root_data {
  char *c;

  struct stat new;
  dev_t rootdev;
};

// toys/other/tac.c

struct tac_data {
  struct double_list *dl;
};

// toys/other/timeout.c

struct timeout_data {
  char *s, *k;

  struct pollfd pfd;
  sigjmp_buf sj;
  int fds[2], pid;
};

// toys/other/truncate.c

struct truncate_data {
  char *s;

  long size;
  int type;
};

// toys/other/uclampset.c

struct uclampset_data {
  long M, m, p;
};

// toys/other/watch.c

struct watch_data {
  int n;

  pid_t pid, oldpid;
};

// toys/other/watchdog.c

struct watchdog_data {
  long T, t;

  int fd;
};

// toys/other/xxd.c

struct xxd_data {
  long s, g, o, l, c;
};

// toys/pending/arp.c

struct arp_data {
    char *hw_type;
    char *af_type_A;
    char *af_type_p;
    char *interface;

    int sockfd;
    char *device;
};

// toys/pending/arping.c

struct arping_data {
    long count;
    unsigned long time_out;
    char *iface;
    char *src_ip;

    int sockfd;
    unsigned long start, end;
    unsigned sent_at, sent_nr, rcvd_nr, brd_sent, rcvd_req, brd_rcv,
             unicast_flag;
};

// toys/pending/bc.c

struct bc_data {
  // This actually needs to be a BcVm*, but the toybox build
  // system complains if I make it so. Instead, we'll just cast.
  char *vm;

  size_t nchars;
  char *file, sig, max_ibase;
  uint16_t line_len;
};

// toys/pending/bootchartd.c

struct bootchartd_data {
  char timestamp[32];
  long msec;
  int proc_accounting;

  pid_t pid;
};

// toys/pending/brctl.c

struct brctl_data {
    int sockfd;
};

// toys/pending/chsh.c

struct chsh_data {
  char *s;
};

// toys/pending/crond.c

struct crond_data {
  char *crontabs_dir;
  char *logfile;
  int loglevel_d;
  int loglevel;

  time_t crontabs_dir_mtime;
  uint8_t flagd;
};

// toys/pending/crontab.c

struct crontab_data {
  char *user;
  char *cdir;
};

// toys/pending/dhcp.c

struct dhcp_data {
    char *iface;
    char *pidfile;
    char *script;
    long retries;
    long timeout;
    long tryagain;
    struct arg_list *req_opt;
    char *req_ip;
    struct arg_list *pkt_opt;
    char *fdn_name;
    char *hostname;
    char *vendor_cls;
};

// toys/pending/dhcp6.c

struct dhcp6_data {
  char *interface_name, *pidfile, *script;
  long retry, timeout, errortimeout;
  char *req_ip;
  int length, state, request_length, sock, sock1, status, retval, retries;
  struct timeval tv;
  uint8_t transction_id[3];
  struct sockaddr_in6 input_socket6;
};

// toys/pending/dhcpd.c

struct dhcpd_data {
    char *iface;
    long port;
};

// toys/pending/diff.c

struct diff_data {
  long U;
  struct arg_list *L;
  char *F, *S, *new_line_format, *old_line_format, *unchanged_line_format;

  int dir_num, size, is_binary, differ, change, len[2], *offset[2];
  struct stat st[2];
  struct {
    char **list;
    int nr_elm;
  } dir[2];
  struct {
    FILE *fp;
    int len;
  } file[2];
};

// toys/pending/dumpleases.c

struct dumpleases_data {
    char *file;
};

// toys/pending/expr.c

struct expr_data {
  char **tok, *delete;
};

// toys/pending/fdisk.c

struct fdisk_data {
  long sect_sz;
  long sectors;
  long heads;
  long cylinders;
};

// toys/pending/fold.c

struct fold_data {
  int width;
};

// toys/pending/fsck.c

struct fsck_data {
  int fd_num;
  char *t_list;

  struct double_list *devices;
  char *arr_flag;
  char **arr_type;
  int negate;
  int sum_status;
  int nr_run;
  int sig_num;
  long max_nr_run;
};

// toys/pending/getfattr.c

struct getfattr_data {
  char *n;
};

// toys/pending/getopt.c

struct getopt_data {
  struct arg_list *l;
  char *o, *n;
};

// toys/pending/getty.c

struct getty_data {
  char *f, *l, *I, *H;
  long t;

  char *tty_name, buff[128];
  int speeds[20], sc;
  struct termios termios;
};

// toys/pending/git.c

struct git_data {
  char *url, *name; //git repo remote url and init directory name
  struct IndexV2 *i; //git creates a index for each pack file, git clone just needs one index for the received pack file
};

// toys/pending/groupadd.c

struct groupadd_data {
  long gid;
};

// toys/pending/hexdump.c

struct hexdump_data {
    long s, n;

    long long len, pos, ppos;
    const char *fmt;
    unsigned int fn, bc;  // file number and byte count
    char linebuf[16];  // line buffer - serves double duty for sqeezing repeat
                       // lines and for accumulating full lines accross file
                       // boundaries if necessesary.
};

// toys/pending/ip.c

struct ip_data {
  char stats, singleline, flush, *filter_dev, gbuf[8192];
  int sockfd, connected, from_ok, route_cmd;
  int8_t addressfamily, is_addr;
};

// toys/pending/ipcrm.c

struct ipcrm_data {
  struct arg_list *qkey;
  struct arg_list *qid;
  struct arg_list *skey;
  struct arg_list *sid;
  struct arg_list *mkey;
  struct arg_list *mid;
};

// toys/pending/ipcs.c

struct ipcs_data {
  int id;
};

// toys/pending/klogd.c

struct klogd_data {
  long level;

  int fd;
};

// toys/pending/last.c

struct last_data {
  char *file;

  struct arg_list *list;
};

// toys/pending/lsof.c

struct lsof_data {
  struct arg_list *p;

  struct stat *sought_files;
  struct double_list *all_sockets, *files;
  int last_shown_pid, shown_header;
};

// toys/pending/man.c

struct man_data {
  char *M, *k;

  char any, cell, ex, *f, k_done, *line, *m, **sct, **scts, **sufs;
  regex_t reg;
};

// toys/pending/mke2fs.c

struct mke2fs_data {
  // Command line arguments.
  long blocksize;
  long bytes_per_inode;
  long inodes;           // Total inodes in filesystem.
  long reserved_percent; // Integer precent of space to reserve for root.
  char *gendir;          // Where to read dirtree from.

  // Internal data.
  struct dirtree *dt;    // Tree of files to copy into the new filesystem.
  unsigned treeblocks;   // Blocks used by dt
  unsigned treeinodes;   // Inodes used by dt

  unsigned blocks;       // Total blocks in the filesystem.
  unsigned freeblocks;   // Free blocks in the filesystem.
  unsigned inodespg;     // Inodes per group
  unsigned groups;       // Total number of block groups.
  unsigned blockbits;    // Bits per block.  (Also blocks per group.)

  // For gene2fs
  unsigned nextblock;    // Next data block to allocate
  unsigned nextgroup;    // Next group we'll be allocating from
  int fsfd;              // File descriptor of filesystem (to output to).
};

// toys/pending/modprobe.c

struct modprobe_data {
  struct arg_list *dirs;

  struct arg_list *probes, *dbase[256];
  char *cmdopts;
  int nudeps, symreq;
};

// toys/pending/more.c

struct more_data {
  struct termios inf;
  int cin_fd;
};

// toys/pending/route.c

struct route_data {
  char *A;
};

// toys/pending/sh.c

struct sh_data {
  union {
    struct {
      char *c;
    } sh;
    struct {
      char *a;
    } exec;
  };

  // keep SECONDS here: used to work around compiler limitation in run_command()
  long long SECONDS;
  char *isexec, *wcpat;
  unsigned options, jobcnt, LINENO;
  int hfd, pid, bangpid, srclvl, recursion;

  // Callable function array
  struct sh_function {
    char *name;
    struct sh_pipeline {  // pipeline segments: linked list of arg w/metadata
      struct sh_pipeline *next, *prev, *end;
      int count, here, type, lineno;
      struct sh_arg {
        char **v;
        int c;
      } arg[1];
    } *pipeline;
    unsigned long refcount;
  } **functions;
  long funcslen;

  // runtime function call stack
  struct sh_fcall {
    struct sh_fcall *next, *prev;

    // This dlist in reverse order: TT.ff current function, TT.ff->prev globals
    struct sh_vars {
      long flags;
      char *str;
    } *vars;
    long varslen, varscap, shift, oldlineno;

    struct sh_function *func; // TODO wire this up
    struct sh_pipeline *pl;
    char *ifs, *omnom;
    struct sh_arg arg;
    struct arg_list *delete;

    // Runtime stack of nested if/else/fi and for/do/done contexts.
    struct sh_blockstack {
      struct sh_blockstack *next;
      struct sh_pipeline *start, *middle;
      struct sh_process *pp;       // list of processes piping in to us
      int run, loop, *urd, pout, pipe;
      struct sh_arg farg;          // for/select arg stack, case wildcard deck
      struct arg_list *fdelete;    // farg's cleanup list
      char *fvar;                  // for/select's iteration variable name
    } *blk;
  } *ff;

// TODO ctrl-Z suspend should stop script
  struct sh_process {
    struct sh_process *next, *prev; // | && ||
    struct arg_list *delete;   // expanded strings
    // undo redirects, a=b at start, child PID, exit status, has !, job #
    int *urd, envlen, pid, exit, flags, job, dash;
    long long when; // when job backgrounded/suspended
    struct sh_arg *raw, arg;
  } *pp; // currently running process

  // job list, command line for $*, scratch space for do_wildcard_files()
  struct sh_arg jobs, *wcdeck;
};

// toys/pending/strace.c

struct strace_data {
  long s, p;

  char ioctl[32], *fmt;
  long regs[256/sizeof(long)], syscall;
  pid_t pid;
  int arg;
};

// toys/pending/stty.c

struct stty_data {
  char *F;

  int fd, col;
  unsigned output_cols;
};

// toys/pending/sulogin.c

struct sulogin_data {
  long timeout;
  struct termios crntio;
};

// toys/pending/syslogd.c

struct syslogd_data {
  char *socket;
  char *config_file;
  char *unix_socket;
  char *logfile;
  long interval;
  long rot_size;
  long rot_count;
  char *remote_log;
  long log_prio;

  struct unsocks *lsocks;  // list of listen sockets
  struct logfile *lfiles;  // list of write logfiles
  int sigfd[2];
};

// toys/pending/tcpsvd.c

struct tcpsvd_data {
  char *l, *u, *C;
  long b, c;

  int maxc;
  int count_all;
  int udp;
};

// toys/pending/telnet.c

struct telnet_data {
  int sock;
  char buf[2048]; // Half sizeof(toybuf) allows a buffer full of IACs.
  struct termios old_term;
  struct termios raw_term;
  uint8_t mode;
  int echo, sga;
  int state, request;
};

// toys/pending/telnetd.c

struct telnetd_data {
    char *login_path;
    char *issue_path;
    int port;
    char *host_addr;
    long w_sec;

    int gmax_fd;
    pid_t fork_pid;
};

// toys/pending/tftp.c

struct tftp_data {
  char *local_file;
  char *remote_file;
  long block_size;

  struct sockaddr_storage inaddr;
  int af;
};

// toys/pending/tftpd.c

struct tftpd_data {
  char *user;

  long sfd;
  struct passwd *pw;
};

// toys/pending/tr.c

struct tr_data {
  short map[256]; //map of chars
  int len1, len2;
};

// toys/pending/traceroute.c

struct traceroute_data {
  long max_ttl;
  long port;
  long ttl_probes;
  char *src_ip;
  long tos;
  long wait_time;
  struct arg_list *loose_source;
  long pause_time;
  long first_ttl;
  char *iface;

  uint32_t gw_list[9];
  int recv_sock;
  int snd_sock;
  unsigned msg_len;
  char *packet;
  uint32_t ident;
  int istraceroute6;
};

// toys/pending/useradd.c

struct useradd_data {
  char *dir;
  char *gecos;
  char *shell;
  char *u_grp;
  long uid;

  long gid;
};

// toys/pending/vi.c

struct vi_data {
  char *s;

  char *filename;
  int vi_mode, tabstop, list;
  int cur_col, cur_row, scr_row;
  int drawn_row, drawn_col;
  int count0, count1, vi_mov_flag;
  unsigned screen_height, screen_width;
  char vi_reg, *last_search;
  struct str_line {
    int alloc;
    int len;
    char *data;
  } *il;
  size_t screen, cursor; //offsets
  //yank buffer
  struct yank_buf {
    char reg;
    int alloc;
    char* data;
  } yank;

  size_t filesize;
// mem_block contains RO data that is either original file as mmap
// or heap allocated inserted data
  struct block_list {
    struct block_list *next, *prev;
    struct mem_block {
      size_t size;
      size_t len;
      enum alloc_flag {
        MMAP,  //can be munmap() before exit()
        HEAP,  //can be free() before exit()
        STACK, //global or stack perhaps toybuf
      } alloc;
      const char *data;
    } *node;
  } *text;

// slices do not contain actual allocated data but slices of data in mem_block
// when file is first opened it has only one slice.
// after inserting data into middle new mem_block is allocated for insert data
// and 3 slices are created, where first and last slice are pointing to original
// mem_block with offsets, and middle slice is pointing to newly allocated block
// When deleting, data is not freed but mem_blocks are sliced more such way that
// deleted data left between 2 slices
  struct slice_list {
    struct slice_list *next, *prev;
    struct slice {
      size_t len;
      const char *data;
    } *node;
  } *slices;
};

// toys/posix/basename.c

struct basename_data {
  char *s;
};

// toys/posix/cal.c

struct cal_data {
  struct tm *now;
};

// toys/posix/chgrp.c

struct chgrp_data {
  uid_t owner;
  gid_t group;
  char *owner_name, *group_name;
  int symfollow;
};

// toys/posix/chmod.c

struct chmod_data {
  char *mode;
};

// toys/posix/cksum.c

struct cksum_data {
  unsigned crc_table[256];
};

// toys/posix/cmp.c

struct cmp_data {
  long n;

  int fd;
  char *name;
};

// toys/posix/cp.c

struct cp_data {
  union {
    // install's options
    struct {
      char *g, *o, *m, *t;
    } i;
    // cp's options
    struct {
      char *t, *preserve;
    } c;
  };

  char *destname;
  struct stat top;
  int (*callback)(struct dirtree *try);
  uid_t uid;
  gid_t gid;
  int pflags;
};

// toys/posix/cpio.c

struct cpio_data {
  char *F, *H, *R;
};

// toys/posix/cut.c

struct cut_data {
  char *d, *O;
  struct arg_list *select[5]; // we treat them the same, so loop through

  unsigned line;
  int pairs;
  regex_t reg;
};

// toys/posix/date.c

struct date_data {
  char *s, *r, *I, *D, *d;

  unsigned nano;
};

// toys/posix/dd.c

struct dd_data {
  // Display fields
  int show_xfer, show_records;
  unsigned long long bytes, in_full, in_part, out_full, out_part, start;
};

// toys/posix/df.c

struct df_data {
  struct arg_list *t;

  int units, width[6];
};

// toys/posix/du.c

struct du_data {
  long d;

  unsigned long depth, total;
  dev_t st_dev;
  void *inodes;
};

// toys/posix/env.c

struct env_data {
  struct arg_list *u;
};

// toys/posix/expand.c

struct expand_data {
  struct arg_list *t;

  unsigned tabcount, *tab;
};

// toys/posix/file.c

struct file_data {
  int max_name_len;
  off_t len;
};

// toys/posix/find.c

struct find_data {
  char **filter;
  struct double_list *argdata;
  int topdir, xdev, depth;
  time_t now;
  long max_bytes;
  char *start;
};

// toys/posix/grep.c

struct grep_data {
  long m, A, B, C;
  struct arg_list *f, *e, *M, *S, *exclude_dir;
  char *color;

  char *purple, *cyan, *red, *green, *grey;
  struct double_list *reg;
  int found, tried, delim;
  struct arg_list *fixed[256];
};

// toys/posix/head.c

struct head_data {
  long c, n;

  int file_no;
};

// toys/posix/iconv.c

struct iconv_data {
  char *f, *t;

  void *ic;
};

// toys/posix/id.c

struct id_data {
  int is_groups;
};

// toys/posix/kill.c

struct kill_data {
  char *s;
  struct arg_list *o;
};

// toys/posix/ln.c

struct ln_data {
  char *t;
};

// toys/posix/logger.c

struct logger_data {
  char *p, *t;

  int priority;
};

// toys/posix/ls.c

struct ls_data {
  long w, l, block_size;
  char *color, *sort;

  struct dirtree *files, *singledir;
  unsigned screen_width;
  int nl_title;
  char *escmore;
};

// toys/posix/mkdir.c

struct mkdir_data {
  char *m, *Z;
};

// toys/posix/mkfifo.c

struct mkfifo_data {
  char *m;
  char *Z;

  mode_t mode;
};

// toys/posix/nice.c

struct nice_data {
  long n;
};

// toys/posix/nl.c

struct nl_data {
  char *s, *n, *b;
  long w, l, v;

  // Count of consecutive blank lines for -l has to persist between files
  long lcount, slen;
};

// toys/posix/od.c

struct od_data {
  struct arg_list *t;
  char *A;
  long N, w, j;

  int address_idx;
  unsigned types, leftover, star;
  char *buf; // Points to buffers[0] or buffers[1].
  char *bufs[2]; // Used to detect duplicate lines.
  off_t pos;
};

// toys/posix/paste.c

struct paste_data {
  char *d;

  int files;
};

// toys/posix/patch.c

struct patch_data {
  char *i, *d;
  long v, p, g, F;

  void *current_hunk;
  long oldline, oldlen, newline, newlen, linenum, outnum;
  int context, state, filein, fileout, filepatch, hunknum;
  char *tempname;
};

// toys/posix/ps.c

struct ps_data {
  union {
    struct {
      struct arg_list *G, *g, *U, *u, *t, *s, *p, *O, *o, *P, *k;
    } ps;
    struct {
      long n, m, d, s;
      struct arg_list *u, *p, *o, *k, *O;
    } top;
    struct {
      char *L;
      struct arg_list *G, *g, *P, *s, *t, *U, *u;
      char *d;

      void *regexes, *snapshot;
      int signal;
      pid_t self, match;
    } pgrep;
  };

  struct ps_ptr_len {
    void *ptr;
    long len;
  } gg, GG, pp, PP, ss, tt, uu, UU;
  struct dirtree *threadparent;
  unsigned width, height, scroll;
  dev_t tty;
  void *fields, *kfields;
  long long ticks, bits, time;
  int kcount, forcek, sortpos, pidlen;
  int (*match_process)(long long *slot);
  void (*show_process)(void *tb);
};

// toys/posix/renice.c

struct renice_data {
  long n;
};

// toys/posix/sed.c

struct sed_data {
  char *i;
  struct arg_list *f, *e;

  // processed pattern list
  struct double_list *pattern;

  char *nextline, *remember, *tarxform;
  void *restart, *lastregex;
  long nextlen, rememberlen, count;
  int fdout, noeol;
  unsigned xx, tarxlen, xflags;
  char delim, xftype;
};

// toys/posix/sort.c

struct sort_data {
  char *t;
  struct arg_list *k;
  char *o, *T, S;

  void *key_list;
  unsigned linecount;
  char **lines, *name;
};

// toys/posix/split.c

struct split_data {
  long n, l, b, a;

  char *outfile;
};

// toys/posix/strings.c

struct strings_data {
  long n;
  char *t;
};

// toys/posix/tail.c

struct tail_data {
  long n, c;
  char *s;

  int file_no, last_fd, ss;
  struct xnotify *not;
  struct {
    char *path;
    int fd;
    struct dev_ino di;
  } *F;
};

// toys/posix/tar.c

struct tar_data {
  char *f, *C, *I;
  struct arg_list *T, *X, *xform;
  long strip;
  char *to_command, *owner, *group, *mtime, *mode, *sort;
  struct arg_list *exclude;

  struct double_list *incl, *excl, *seen;
  struct string_list *dirs;
  char *cwd, **xfsed;
  int fd, ouid, ggid, hlc, warn, sparselen, pid, xfpipe[2];
  struct dev_ino archive_di;
  long long *sparse;
  time_t mtt;

  // hardlinks seen so far (hlc many)
  struct {
    char *arg;
    struct dev_ino di;
  } *hlx;

  // Parsed information about a tar header.
  struct tar_header {
    char *name, *link_target, *uname, *gname;
    long long size, ssize;
    uid_t uid;
    gid_t gid;
    mode_t mode;
    time_t mtime;
    dev_t device;
  } hdr;
};

// toys/posix/tee.c

struct tee_data {
  void *outputs;
  int out;
};

// toys/posix/touch.c

struct touch_data {
  char *t, *r, *d;
};

// toys/posix/ulimit.c

struct ulimit_data {
  long P;
};

// toys/posix/uniq.c

struct uniq_data {
  long w, s, f;

  long repeats;
};

// toys/posix/uudecode.c

struct uudecode_data {
  char *o;
};

// toys/posix/wc.c

struct wc_data {
  unsigned long totals[4];
};

// toys/posix/xargs.c

struct xargs_data {
  long s, n, P;
  char *E;

  long entries, bytes, np;
  char delim;
  FILE *tty;
};

extern union global_union {
	struct log_data log;
	struct demo_number_data demo_number;
	struct hello_data hello;
	struct skeleton_data skeleton;
	struct dmesg_data dmesg;
	struct gzip_data gzip;
	struct hostname_data hostname;
	struct killall_data killall;
	struct md5sum_data md5sum;
	struct mknod_data mknod;
	struct mktemp_data mktemp;
	struct mount_data mount;
	struct passwd_data passwd;
	struct pidof_data pidof;
	struct seq_data seq;
	struct su_data su;
	struct umount_data umount;
	struct ftpget_data ftpget;
	struct host_data host;
	struct ifconfig_data ifconfig;
	struct microcom_data microcom;
	struct netcat_data netcat;
	struct netstat_data netstat;
	struct ping_data ping;
	struct sntp_data sntp;
	struct tunctl_data tunctl;
	struct wget_data wget;
	struct acpi_data acpi;
	struct base64_data base64;
	struct blkdiscard_data blkdiscard;
	struct blkid_data blkid;
	struct blockdev_data blockdev;
	struct chrt_data chrt;
	struct dos2unix_data dos2unix;
	struct fallocate_data fallocate;
	struct fmt_data fmt;
	struct free_data free;
	struct gpiod_data gpiod;
	struct hexedit_data hexedit;
	struct hwclock_data hwclock;
	struct i2ctools_data i2ctools;
	struct ionice_data ionice;
	struct login_data login;
	struct losetup_data losetup;
	struct lsattr_data lsattr;
	struct lsusb_data lsusb;
	struct makedevs_data makedevs;
	struct mix_data mix;
	struct mkpasswd_data mkpasswd;
	struct mkswap_data mkswap;
	struct modinfo_data modinfo;
	struct nbd_client_data nbd_client;
	struct nsenter_data nsenter;
	struct oneit_data oneit;
	struct openvt_data openvt;
	struct pwgen_data pwgen;
	struct readelf_data readelf;
	struct readlink_data readlink;
	struct reboot_data reboot;
	struct rtcwake_data rtcwake;
	struct setfattr_data setfattr;
	struct sha3sum_data sha3sum;
	struct shred_data shred;
	struct shuf_data shuf;
	struct stat_data stat;
	struct swapon_data swapon;
	struct switch_root_data switch_root;
	struct tac_data tac;
	struct timeout_data timeout;
	struct truncate_data truncate;
	struct uclampset_data uclampset;
	struct watch_data watch;
	struct watchdog_data watchdog;
	struct xxd_data xxd;
	struct arp_data arp;
	struct arping_data arping;
	struct bc_data bc;
	struct bootchartd_data bootchartd;
	struct brctl_data brctl;
	struct chsh_data chsh;
	struct crond_data crond;
	struct crontab_data crontab;
	struct dhcp_data dhcp;
	struct dhcp6_data dhcp6;
	struct dhcpd_data dhcpd;
	struct diff_data diff;
	struct dumpleases_data dumpleases;
	struct expr_data expr;
	struct fdisk_data fdisk;
	struct fold_data fold;
	struct fsck_data fsck;
	struct getfattr_data getfattr;
	struct getopt_data getopt;
	struct getty_data getty;
	struct git_data git;
	struct groupadd_data groupadd;
	struct hexdump_data hexdump;
	struct ip_data ip;
	struct ipcrm_data ipcrm;
	struct ipcs_data ipcs;
	struct klogd_data klogd;
	struct last_data last;
	struct lsof_data lsof;
	struct man_data man;
	struct mke2fs_data mke2fs;
	struct modprobe_data modprobe;
	struct more_data more;
	struct route_data route;
	struct sh_data sh;
	struct strace_data strace;
	struct stty_data stty;
	struct sulogin_data sulogin;
	struct syslogd_data syslogd;
	struct tcpsvd_data tcpsvd;
	struct telnet_data telnet;
	struct telnetd_data telnetd;
	struct tftp_data tftp;
	struct tftpd_data tftpd;
	struct tr_data tr;
	struct traceroute_data traceroute;
	struct useradd_data useradd;
	struct vi_data vi;
	struct basename_data basename;
	struct cal_data cal;
	struct chgrp_data chgrp;
	struct chmod_data chmod;
	struct cksum_data cksum;
	struct cmp_data cmp;
	struct cp_data cp;
	struct cpio_data cpio;
	struct cut_data cut;
	struct date_data date;
	struct dd_data dd;
	struct df_data df;
	struct du_data du;
	struct env_data env;
	struct expand_data expand;
	struct file_data file;
	struct find_data find;
	struct grep_data grep;
	struct head_data head;
	struct iconv_data iconv;
	struct id_data id;
	struct kill_data kill;
	struct ln_data ln;
	struct logger_data logger;
	struct ls_data ls;
	struct mkdir_data mkdir;
	struct mkfifo_data mkfifo;
	struct nice_data nice;
	struct nl_data nl;
	struct od_data od;
	struct paste_data paste;
	struct patch_data patch;
	struct ps_data ps;
	struct renice_data renice;
	struct sed_data sed;
	struct sort_data sort;
	struct split_data split;
	struct strings_data strings;
	struct tail_data tail;
	struct tar_data tar;
	struct tee_data tee;
	struct touch_data touch;
	struct ulimit_data ulimit;
	struct uniq_data uniq;
	struct uudecode_data uudecode;
	struct wc_data wc;
	struct xargs_data xargs;
} this;
