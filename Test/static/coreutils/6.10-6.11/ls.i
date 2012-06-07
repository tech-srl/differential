typedef int _Bool;
# 1 "ls.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "ls.c"
# 38 "ls.c"
# 1 "../lib/config.h" 1
# 39 "ls.c" 2
# 1 "/usr/include/sys/types.h" 1 3 4
# 27 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 313 "/usr/include/features.h" 3 4
# 1 "/usr/include/bits/predefs.h" 1 3 4
# 314 "/usr/include/features.h" 2 3 4
# 346 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 353 "/usr/include/sys/cdefs.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 354 "/usr/include/sys/cdefs.h" 2 3 4
# 347 "/usr/include/features.h" 2 3 4
# 378 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4



# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 5 "/usr/include/gnu/stubs.h" 2 3 4


# 1 "/usr/include/gnu/stubs-32.h" 1 3 4
# 8 "/usr/include/gnu/stubs.h" 2 3 4
# 379 "/usr/include/features.h" 2 3 4
# 28 "/usr/include/sys/types.h" 2 3 4



# 1 "/usr/include/bits/types.h" 1 3 4
# 28 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;




__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;







__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
# 131 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 132 "/usr/include/bits/types.h" 2 3 4


__extension__ typedef __u_quad_t __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef __u_quad_t __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef __quad_t __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct { int __val[2]; } __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef __u_quad_t __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;

__extension__ typedef int __daddr_t;
__extension__ typedef long int __swblk_t;
__extension__ typedef int __key_t;


__extension__ typedef int __clockid_t;


__extension__ typedef void * __timer_t;


__extension__ typedef long int __blksize_t;




__extension__ typedef long int __blkcnt_t;
__extension__ typedef __quad_t __blkcnt64_t;


__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef __u_quad_t __fsblkcnt64_t;


__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef __u_quad_t __fsfilcnt64_t;

__extension__ typedef int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


__extension__ typedef int __intptr_t;


__extension__ typedef unsigned int __socklen_t;
# 32 "/usr/include/sys/types.h" 2 3 4



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;





typedef __ino64_t ino_t;




typedef __ino64_t ino64_t;




typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;







typedef __off64_t off_t;




typedef __off64_t off64_t;




typedef __pid_t pid_t;




typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 133 "/usr/include/sys/types.h" 3 4
# 1 "../lib/time.h" 1 3 4
# 31 "../lib/time.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 58 "/usr/include/time.h" 3 4


typedef __clock_t clock_t;



# 74 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 32 "../lib/time.h" 2 3 4
# 134 "/usr/include/sys/types.h" 2 3 4



typedef __useconds_t useconds_t;



typedef __suseconds_t suseconds_t;





# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 211 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 3 4
typedef unsigned int size_t;
# 148 "/usr/include/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 195 "/usr/include/sys/types.h" 3 4
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
# 217 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/endian.h" 1 3 4
# 38 "/usr/include/endian.h" 2 3 4
# 61 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/byteswap.h" 1 3 4
# 28 "/usr/include/bits/byteswap.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/byteswap.h" 2 3 4
# 62 "/usr/include/endian.h" 2 3 4
# 218 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/select.h" 1 3 4
# 31 "/usr/include/sys/select.h" 3 4
# 1 "/usr/include/bits/select.h" 1 3 4
# 23 "/usr/include/bits/select.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 24 "/usr/include/bits/select.h" 2 3 4
# 32 "/usr/include/sys/select.h" 2 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 24 "/usr/include/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 35 "/usr/include/sys/select.h" 2 3 4



typedef __sigset_t sigset_t;





# 1 "../lib/time.h" 1 3 4
# 31 "../lib/time.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 120 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
# 32 "../lib/time.h" 2 3 4
# 45 "/usr/include/sys/select.h" 2 3 4

# 1 "/usr/include/bits/time.h" 1 3 4
# 69 "/usr/include/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 47 "/usr/include/sys/select.h" 2 3 4
# 55 "/usr/include/sys/select.h" 3 4
typedef long int __fd_mask;
# 67 "/usr/include/sys/select.h" 3 4
typedef struct
  {



    __fd_mask fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];





  } fd_set;






typedef __fd_mask fd_mask;
# 99 "/usr/include/sys/select.h" 3 4

# 109 "/usr/include/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 121 "/usr/include/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);



# 221 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/sysmacros.h" 1 3 4
# 30 "/usr/include/sys/sysmacros.h" 3 4
__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__));
# 224 "/usr/include/sys/types.h" 2 3 4




typedef __blksize_t blksize_t;
# 248 "/usr/include/sys/types.h" 3 4
typedef __blkcnt64_t blkcnt_t;



typedef __fsblkcnt64_t fsblkcnt_t;



typedef __fsfilcnt64_t fsfilcnt_t;





typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;





# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 24 "/usr/include/bits/pthreadtypes.h" 2 3 4
# 50 "/usr/include/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;


typedef union
{
  char __size[36];
  long int __align;
} pthread_attr_t;
# 67 "/usr/include/bits/pthreadtypes.h" 3 4
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;





typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;





    int __kind;





    unsigned int __nusers;
    __extension__ union
    {
      int __spins;
      __pthread_slist_t __list;
    };

  } __data;
  char __size[24];
  long int __align;
} pthread_mutex_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;





typedef union
{
# 170 "/usr/include/bits/pthreadtypes.h" 3 4
  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;


    unsigned char __flags;
    unsigned char __shared;
    unsigned char __pad1;
    unsigned char __pad2;
    int __writer;
  } __data;

  char __size[32];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[20];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 271 "/usr/include/sys/types.h" 2 3 4



# 40 "ls.c" 2


# 1 "/usr/include/termios.h" 1 3 4
# 36 "/usr/include/termios.h" 3 4




# 1 "/usr/include/bits/termios.h" 1 3 4
# 25 "/usr/include/bits/termios.h" 3 4
typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;


struct termios
  {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_line;
    cc_t c_cc[32];
    speed_t c_ispeed;
    speed_t c_ospeed;


  };
# 41 "/usr/include/termios.h" 2 3 4
# 49 "/usr/include/termios.h" 3 4
extern speed_t cfgetospeed (__const struct termios *__termios_p) __attribute__ ((__nothrow__));


extern speed_t cfgetispeed (__const struct termios *__termios_p) __attribute__ ((__nothrow__));


extern int cfsetospeed (struct termios *__termios_p, speed_t __speed) __attribute__ ((__nothrow__));


extern int cfsetispeed (struct termios *__termios_p, speed_t __speed) __attribute__ ((__nothrow__));



extern int cfsetspeed (struct termios *__termios_p, speed_t __speed) __attribute__ ((__nothrow__));




extern int tcgetattr (int __fd, struct termios *__termios_p) __attribute__ ((__nothrow__));



extern int tcsetattr (int __fd, int __optional_actions,
        __const struct termios *__termios_p) __attribute__ ((__nothrow__));




extern void cfmakeraw (struct termios *__termios_p) __attribute__ ((__nothrow__));



extern int tcsendbreak (int __fd, int __duration) __attribute__ ((__nothrow__));





extern int tcdrain (int __fd);



extern int tcflush (int __fd, int __queue_selector) __attribute__ ((__nothrow__));



extern int tcflow (int __fd, int __action) __attribute__ ((__nothrow__));




extern __pid_t tcgetsid (int __fd) __attribute__ ((__nothrow__));




# 1 "/usr/include/sys/ttydefaults.h" 1 3 4
# 106 "/usr/include/termios.h" 2 3 4



# 43 "ls.c" 2


# 1 "/usr/include/stropts.h" 1 3 4
# 24 "/usr/include/stropts.h" 3 4
# 1 "/usr/include/bits/xtitypes.h" 1 3 4
# 30 "/usr/include/bits/xtitypes.h" 3 4
typedef long int __t_scalar_t;
typedef unsigned long int __t_uscalar_t;
# 25 "/usr/include/stropts.h" 2 3 4
# 36 "/usr/include/stropts.h" 3 4
typedef __t_uscalar_t t_uscalar_t;


# 1 "/usr/include/bits/stropts.h" 1 3 4
# 174 "/usr/include/bits/stropts.h" 3 4
struct bandinfo
  {
    unsigned char bi_pri;
    int bi_flag;
  };

struct strbuf
  {
    int maxlen;
    int len;
    char *buf;
  };

struct strpeek
  {
    struct strbuf ctlbuf;
    struct strbuf databuf;
    t_uscalar_t flags;
  };

struct strfdinsert
  {
    struct strbuf ctlbuf;
    struct strbuf databuf;
    t_uscalar_t flags;
    int fildes;
    int offset;
  };

struct strioctl
  {
    int ic_cmd;
    int ic_timout;
    int ic_len;
    char *ic_dp;
  };

struct strrecvfd
  {
    int fd;
    uid_t uid;
    gid_t gid;
    char __fill[8];
  };


struct str_mlist
  {
    char l_name[8 + 1];
  };

struct str_list
  {
    int sl_nmods;
    struct str_mlist *sl_modlist;
  };
# 40 "/usr/include/stropts.h" 2 3 4





extern int isastream (int __fildes) __attribute__ ((__nothrow__));





extern int getmsg (int __fildes, struct strbuf *__restrict __ctlptr,
     struct strbuf *__restrict __dataptr,
     int *__restrict __flagsp);






extern int getpmsg (int __fildes, struct strbuf *__restrict __ctlptr,
      struct strbuf *__restrict __dataptr,
      int *__restrict __bandp, int *__restrict __flagsp);




extern int ioctl (int __fd, unsigned long int __request, ...) __attribute__ ((__nothrow__));





extern int putmsg (int __fildes, __const struct strbuf *__ctlptr,
     __const struct strbuf *__dataptr, int __flags);





extern int putpmsg (int __fildes, __const struct strbuf *__ctlptr,
      __const struct strbuf *__dataptr, int __band, int __flags);



extern int fattach (int __fildes, __const char *__path) __attribute__ ((__nothrow__));


extern int fdetach (__const char *__path) __attribute__ ((__nothrow__));


# 46 "ls.c" 2


# 1 "/usr/include/sys/ioctl.h" 1 3 4
# 24 "/usr/include/sys/ioctl.h" 3 4



# 1 "/usr/include/bits/ioctls.h" 1 3 4
# 24 "/usr/include/bits/ioctls.h" 3 4
# 1 "/usr/include/asm/ioctls.h" 1 3 4
# 1 "/usr/include/asm-generic/ioctls.h" 1 3 4



# 1 "/usr/include/linux/ioctl.h" 1 3 4



# 1 "/usr/include/asm/ioctl.h" 1 3 4
# 1 "/usr/include/asm-generic/ioctl.h" 1 3 4
# 1 "/usr/include/asm/ioctl.h" 2 3 4
# 5 "/usr/include/linux/ioctl.h" 2 3 4
# 5 "/usr/include/asm-generic/ioctls.h" 2 3 4
# 1 "/usr/include/asm/ioctls.h" 2 3 4
# 25 "/usr/include/bits/ioctls.h" 2 3 4
# 28 "/usr/include/sys/ioctl.h" 2 3 4


# 1 "/usr/include/bits/ioctl-types.h" 1 3 4
# 25 "/usr/include/bits/ioctl-types.h" 3 4
# 1 "/usr/include/asm/ioctls.h" 1 3 4
# 26 "/usr/include/bits/ioctl-types.h" 2 3 4


struct winsize
  {
    unsigned short int ws_row;
    unsigned short int ws_col;
    unsigned short int ws_xpixel;
    unsigned short int ws_ypixel;
  };


struct termio
  {
    unsigned short int c_iflag;
    unsigned short int c_oflag;
    unsigned short int c_cflag;
    unsigned short int c_lflag;
    unsigned char c_line;
    unsigned char c_cc[8];
};
# 31 "/usr/include/sys/ioctl.h" 2 3 4






# 1 "/usr/include/sys/ttydefaults.h" 1 3 4
# 38 "/usr/include/sys/ioctl.h" 2 3 4




extern int ioctl (int __fd, unsigned long int __request, ...) __attribute__ ((__nothrow__));


# 49 "ls.c" 2







# 1 "../lib/stdio.h" 1
# 33 "../lib/stdio.h"
# 1 "/usr/include/stdio.h" 1 3 4
# 30 "/usr/include/stdio.h" 3 4




# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 35 "/usr/include/stdio.h" 2 3 4
# 45 "/usr/include/stdio.h" 3 4
struct _IO_FILE;



typedef struct _IO_FILE FILE;





# 65 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 75 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 32 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 15 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 16 "/usr/include/_G_config.h" 2 3 4




# 1 "/usr/include/wchar.h" 1 3 4
# 83 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {

    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 21 "/usr/include/_G_config.h" 2 3 4

typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 53 "/usr/include/_G_config.h" 3 4
typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));
# 33 "/usr/include/libio.h" 2 3 4
# 53 "/usr/include/libio.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 54 "/usr/include/libio.h" 2 3 4
# 170 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;
# 180 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 203 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 271 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 319 "/usr/include/libio.h" 3 4
  __off64_t _offset;
# 328 "/usr/include/libio.h" 3 4
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 364 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
     size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);




typedef __io_read_fn cookie_read_function_t;
typedef __io_write_fn cookie_write_function_t;
typedef __io_seek_fn cookie_seek_function_t;
typedef __io_close_fn cookie_close_function_t;


typedef struct
{
  __io_read_fn *read;
  __io_write_fn *write;
  __io_seek_fn *seek;
  __io_close_fn *close;
} _IO_cookie_io_functions_t;
typedef _IO_cookie_io_functions_t cookie_io_functions_t;

struct _IO_cookie_file;


extern void _IO_cookie_init (struct _IO_cookie_file *__cfile, int __read_write,
        void *__cookie, _IO_cookie_io_functions_t __fns);







extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
# 460 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__));

extern int _IO_peekc_locked (_IO_FILE *__fp);





extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__));
# 490 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__));
# 76 "/usr/include/stdio.h" 2 3 4




typedef __gnuc_va_list va_list;
# 89 "/usr/include/stdio.h" 3 4




typedef _G_fpos64_t fpos_t;



typedef _G_fpos64_t fpos64_t;
# 141 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 142 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (__const char *__filename) __attribute__ ((__nothrow__));

extern int rename (__const char *__old, __const char *__new) __attribute__ ((__nothrow__));




extern int renameat (int __oldfd, __const char *__old, int __newfd,
       __const char *__new) __attribute__ ((__nothrow__));



# 175 "/usr/include/stdio.h" 3 4
extern FILE *tmpfile (void) __asm__ ("" "tmpfile64") ;






extern FILE *tmpfile64 (void) ;



extern char *tmpnam (char *__s) __attribute__ ((__nothrow__)) ;





extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__)) ;
# 204 "/usr/include/stdio.h" 3 4
extern char *tempnam (__const char *__dir, __const char *__pfx)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 229 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 239 "/usr/include/stdio.h" 3 4
extern int fcloseall (void);




# 260 "/usr/include/stdio.h" 3 4
extern FILE *fopen (__const char *__restrict __filename, __const char *__restrict __modes) __asm__ ("" "fopen64")

  ;
extern FILE *freopen (__const char *__restrict __filename, __const char *__restrict __modes, FILE *__restrict __stream) __asm__ ("" "freopen64")


  ;







extern FILE *fopen64 (__const char *__restrict __filename,
        __const char *__restrict __modes) ;
extern FILE *freopen64 (__const char *__restrict __filename,
   __const char *__restrict __modes,
   FILE *__restrict __stream) ;




extern FILE *fdopen (int __fd, __const char *__modes) __attribute__ ((__nothrow__)) ;





extern FILE *fopencookie (void *__restrict __magic_cookie,
     __const char *__restrict __modes,
     _IO_cookie_io_functions_t __io_funcs) __attribute__ ((__nothrow__)) ;




extern FILE *fmemopen (void *__s, size_t __len, __const char *__modes)
  __attribute__ ((__nothrow__)) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__)) ;






extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__));





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__));








extern int fprintf (FILE *__restrict __stream,
      __const char *__restrict __format, ...);




extern int printf (__const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      __const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));





extern int snprintf (char *__restrict __s, size_t __maxlen,
       __const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));






extern int vasprintf (char **__restrict __ptr, __const char *__restrict __f,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf (char **__restrict __ptr,
         __const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf (char **__restrict __ptr,
       __const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
# 394 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, __const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, __const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));








extern int fscanf (FILE *__restrict __stream,
     __const char *__restrict __format, ...) ;




extern int scanf (__const char *__restrict __format, ...) ;

extern int sscanf (__const char *__restrict __s,
     __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
# 445 "/usr/include/stdio.h" 3 4








extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (__const char *__restrict __s,
      __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 504 "/usr/include/stdio.h" 3 4









extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 532 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 543 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);

# 576 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;






extern char *gets (char *__s) ;

# 622 "/usr/include/stdio.h" 3 4
extern char *fgets_unlocked (char *__restrict __s, int __n,
        FILE *__restrict __stream) ;
# 638 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;








extern int fputs (__const char *__restrict __s, FILE *__restrict __stream);





extern int puts (__const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);

# 699 "/usr/include/stdio.h" 3 4
extern int fputs_unlocked (__const char *__restrict __s,
      FILE *__restrict __stream);
# 710 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);

# 754 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off64_t __off, int __whence) __asm__ ("" "fseeko64");


extern __off64_t ftello (FILE *__stream) __asm__ ("" "ftello64");








# 779 "/usr/include/stdio.h" 3 4
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos) __asm__ ("" "fgetpos64");

extern int fsetpos (FILE *__stream, __const fpos_t *__pos) __asm__ ("" "fsetpos64");









extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64 (FILE *__stream) ;
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos);
extern int fsetpos64 (FILE *__stream, __const fpos64_t *__pos);




extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__)) ;

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__)) ;




extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;








extern void perror (__const char *__s);






# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 27 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern __const char *__const sys_errlist[];


extern int _sys_nerr;
extern __const char *__const _sys_errlist[];
# 827 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__)) ;




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
# 846 "/usr/include/stdio.h" 3 4
extern FILE *popen (__const char *__command, __const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) __attribute__ ((__nothrow__));





extern char *cuserid (char *__s);




struct obstack;


extern int obstack_printf (struct obstack *__restrict __obstack,
      __const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3)));
extern int obstack_vprintf (struct obstack *__restrict __obstack,
       __const char *__restrict __format,
       __gnuc_va_list __args)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0)));







extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__)) ;


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__));
# 916 "/usr/include/stdio.h" 3 4

# 34 "../lib/stdio.h" 2




# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stdarg.h" 1 3 4
# 39 "../lib/stdio.h" 2
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 149 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 323 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 3 4
typedef int wchar_t;
# 40 "../lib/stdio.h" 2
# 117 "../lib/stdio.h"
extern int rpl_vfprintf (FILE *fp, const char *format, va_list args)
       __attribute__ ((__format__ (__printf__, 2, 0)));
# 155 "../lib/stdio.h"
extern int rpl_vprintf (const char *format, va_list args)
       __attribute__ ((__format__ (__printf__, 1, 0)));
# 239 "../lib/stdio.h"
  extern int rpl_asprintf (char **result, const char *format, ...)
    __attribute__ ((__format__ (__printf__, 2, 3)));
  extern int rpl_vasprintf (char **result, const char *format, va_list args)
    __attribute__ ((__format__ (__printf__, 2, 0)));
# 57 "ls.c" 2
# 1 "/usr/include/assert.h" 1 3 4
# 68 "/usr/include/assert.h" 3 4



extern void __assert_fail (__const char *__assertion, __const char *__file,
      unsigned int __line, __const char *__function)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, __const char *__file,
      unsigned int __line,
      __const char *__function)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));



# 58 "ls.c" 2
# 1 "/usr/include/setjmp.h" 1 3 4
# 28 "/usr/include/setjmp.h" 3 4


# 1 "/usr/include/bits/setjmp.h" 1 3 4
# 27 "/usr/include/bits/setjmp.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 28 "/usr/include/bits/setjmp.h" 2 3 4






typedef int __jmp_buf[6];
# 31 "/usr/include/setjmp.h" 2 3 4
# 1 "/usr/include/bits/sigset.h" 1 3 4
# 32 "/usr/include/setjmp.h" 2 3 4



struct __jmp_buf_tag
  {




    __jmp_buf __jmpbuf;
    int __mask_was_saved;
    __sigset_t __saved_mask;
  };




typedef struct __jmp_buf_tag jmp_buf[1];



extern int setjmp (jmp_buf __env) __attribute__ ((__nothrow__));






extern int __sigsetjmp (struct __jmp_buf_tag __env[1], int __savemask) __attribute__ ((__nothrow__));




extern int _setjmp (struct __jmp_buf_tag __env[1]) __attribute__ ((__nothrow__));
# 78 "/usr/include/setjmp.h" 3 4




extern void longjmp (struct __jmp_buf_tag __env[1], int __val)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));







extern void _longjmp (struct __jmp_buf_tag __env[1], int __val)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));







typedef struct __jmp_buf_tag sigjmp_buf[1];
# 110 "/usr/include/setjmp.h" 3 4
extern void siglongjmp (sigjmp_buf __env, int __val)
     __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
# 120 "/usr/include/setjmp.h" 3 4

# 59 "ls.c" 2
# 1 "/usr/include/grp.h" 1 3 4
# 28 "/usr/include/grp.h" 3 4





# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 34 "/usr/include/grp.h" 2 3 4
# 43 "/usr/include/grp.h" 3 4
struct group
  {
    char *gr_name;
    char *gr_passwd;
    __gid_t gr_gid;
    char **gr_mem;
  };




# 1 "../lib/stdio.h" 1 3 4
# 55 "/usr/include/grp.h" 2 3 4
# 63 "/usr/include/grp.h" 3 4
extern void setgrent (void);





extern void endgrent (void);





extern struct group *getgrent (void);
# 85 "/usr/include/grp.h" 3 4
extern struct group *fgetgrent (FILE *__stream);
# 95 "/usr/include/grp.h" 3 4
extern int putgrent (__const struct group *__restrict __p,
       FILE *__restrict __f);






extern struct group *getgrgid (__gid_t __gid);





extern struct group *getgrnam (__const char *__name);
# 133 "/usr/include/grp.h" 3 4
extern int getgrent_r (struct group *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct group **__restrict __result);






extern int getgrgid_r (__gid_t __gid, struct group *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct group **__restrict __result);





extern int getgrnam_r (__const char *__restrict __name,
         struct group *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct group **__restrict __result);
# 163 "/usr/include/grp.h" 3 4
extern int fgetgrent_r (FILE *__restrict __stream,
   struct group *__restrict __resultbuf,
   char *__restrict __buffer, size_t __buflen,
   struct group **__restrict __result);
# 175 "/usr/include/grp.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 176 "/usr/include/grp.h" 2 3 4


extern int setgroups (size_t __n, __const __gid_t *__groups) __attribute__ ((__nothrow__));
# 188 "/usr/include/grp.h" 3 4
extern int getgrouplist (__const char *__user, __gid_t __group,
    __gid_t *__groups, int *__ngroups);
# 199 "/usr/include/grp.h" 3 4
extern int initgroups (__const char *__user, __gid_t __group);




# 60 "ls.c" 2
# 1 "/usr/include/pwd.h" 1 3 4
# 28 "/usr/include/pwd.h" 3 4





# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 34 "/usr/include/pwd.h" 2 3 4
# 50 "/usr/include/pwd.h" 3 4
struct passwd
{
  char *pw_name;
  char *pw_passwd;
  __uid_t pw_uid;
  __gid_t pw_gid;
  char *pw_gecos;
  char *pw_dir;
  char *pw_shell;
};




# 1 "../lib/stdio.h" 1 3 4
# 65 "/usr/include/pwd.h" 2 3 4
# 73 "/usr/include/pwd.h" 3 4
extern void setpwent (void);





extern void endpwent (void);





extern struct passwd *getpwent (void);
# 95 "/usr/include/pwd.h" 3 4
extern struct passwd *fgetpwent (FILE *__stream);







extern int putpwent (__const struct passwd *__restrict __p,
       FILE *__restrict __f);






extern struct passwd *getpwuid (__uid_t __uid);





extern struct passwd *getpwnam (__const char *__name);
# 140 "/usr/include/pwd.h" 3 4
extern int getpwent_r (struct passwd *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct passwd **__restrict __result);


extern int getpwuid_r (__uid_t __uid,
         struct passwd *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct passwd **__restrict __result);

extern int getpwnam_r (__const char *__restrict __name,
         struct passwd *__restrict __resultbuf,
         char *__restrict __buffer, size_t __buflen,
         struct passwd **__restrict __result);
# 164 "/usr/include/pwd.h" 3 4
extern int fgetpwent_r (FILE *__restrict __stream,
   struct passwd *__restrict __resultbuf,
   char *__restrict __buffer, size_t __buflen,
   struct passwd **__restrict __result);
# 181 "/usr/include/pwd.h" 3 4
extern int getpw (__uid_t __uid, char *__buffer);



# 61 "ls.c" 2
# 1 "/usr/include/getopt.h" 1 3 4
# 59 "/usr/include/getopt.h" 3 4
extern char *optarg;
# 73 "/usr/include/getopt.h" 3 4
extern int optind;




extern int opterr;



extern int optopt;
# 106 "/usr/include/getopt.h" 3 4
struct option
{
  const char *name;


  int has_arg;
  int *flag;
  int val;
};
# 152 "/usr/include/getopt.h" 3 4
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__));
# 175 "/usr/include/getopt.h" 3 4
extern int getopt_long (int ___argc, char *const *___argv,
   const char *__shortopts,
          const struct option *__longopts, int *__longind)
       __attribute__ ((__nothrow__));
extern int getopt_long_only (int ___argc, char *const *___argv,
        const char *__shortopts,
               const struct option *__longopts, int *__longind)
       __attribute__ ((__nothrow__));
# 62 "ls.c" 2
# 1 "/usr/include/signal.h" 1 3 4
# 31 "/usr/include/signal.h" 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 104 "/usr/include/bits/sigset.h" 3 4
extern int __sigismember (__const __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);
# 34 "/usr/include/signal.h" 2 3 4







typedef __sig_atomic_t sig_atomic_t;

# 58 "/usr/include/signal.h" 3 4
# 1 "/usr/include/bits/signum.h" 1 3 4
# 59 "/usr/include/signal.h" 2 3 4
# 76 "/usr/include/signal.h" 3 4
# 1 "../lib/time.h" 1 3 4
# 31 "../lib/time.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 32 "../lib/time.h" 2 3 4
# 77 "/usr/include/signal.h" 2 3 4


# 1 "/usr/include/bits/siginfo.h" 1 3 4
# 25 "/usr/include/bits/siginfo.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 26 "/usr/include/bits/siginfo.h" 2 3 4







typedef union sigval
  {
    int sival_int;
    void *sival_ptr;
  } sigval_t;
# 51 "/usr/include/bits/siginfo.h" 3 4
typedef struct siginfo
  {
    int si_signo;
    int si_errno;

    int si_code;

    union
      {
 int _pad[((128 / sizeof (int)) - 3)];


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
   } _kill;


 struct
   {
     int si_tid;
     int si_overrun;
     sigval_t si_sigval;
   } _timer;


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     sigval_t si_sigval;
   } _rt;


 struct
   {
     __pid_t si_pid;
     __uid_t si_uid;
     int si_status;
     __clock_t si_utime;
     __clock_t si_stime;
   } _sigchld;


 struct
   {
     void *si_addr;
   } _sigfault;


 struct
   {
     long int si_band;
     int si_fd;
   } _sigpoll;
      } _sifields;
  } siginfo_t;
# 129 "/usr/include/bits/siginfo.h" 3 4
enum
{
  SI_ASYNCNL = -60,

  SI_TKILL = -6,

  SI_SIGIO,

  SI_ASYNCIO,

  SI_MESGQ,

  SI_TIMER,

  SI_QUEUE,

  SI_USER,

  SI_KERNEL = 0x80

};



enum
{
  ILL_ILLOPC = 1,

  ILL_ILLOPN,

  ILL_ILLADR,

  ILL_ILLTRP,

  ILL_PRVOPC,

  ILL_PRVREG,

  ILL_COPROC,

  ILL_BADSTK

};


enum
{
  FPE_INTDIV = 1,

  FPE_INTOVF,

  FPE_FLTDIV,

  FPE_FLTOVF,

  FPE_FLTUND,

  FPE_FLTRES,

  FPE_FLTINV,

  FPE_FLTSUB

};


enum
{
  SEGV_MAPERR = 1,

  SEGV_ACCERR

};


enum
{
  BUS_ADRALN = 1,

  BUS_ADRERR,

  BUS_OBJERR

};


enum
{
  TRAP_BRKPT = 1,

  TRAP_TRACE

};


enum
{
  CLD_EXITED = 1,

  CLD_KILLED,

  CLD_DUMPED,

  CLD_TRAPPED,

  CLD_STOPPED,

  CLD_CONTINUED

};


enum
{
  POLL_IN = 1,

  POLL_OUT,

  POLL_MSG,

  POLL_ERR,

  POLL_PRI,

  POLL_HUP

};
# 273 "/usr/include/bits/siginfo.h" 3 4
typedef struct sigevent
  {
    sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;

    union
      {
 int _pad[((64 / sizeof (int)) - 3)];



 __pid_t _tid;

 struct
   {
     void (*_function) (sigval_t);
     void *_attribute;
   } _sigev_thread;
      } _sigev_un;
  } sigevent_t;






enum
{
  SIGEV_SIGNAL = 0,

  SIGEV_NONE,

  SIGEV_THREAD,


  SIGEV_THREAD_ID = 4

};
# 80 "/usr/include/signal.h" 2 3 4




typedef void (*__sighandler_t) (int);




extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__));

extern __sighandler_t sysv_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__));







extern __sighandler_t signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__));
# 113 "/usr/include/signal.h" 3 4





extern __sighandler_t bsd_signal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__));






extern int kill (__pid_t __pid, int __sig) __attribute__ ((__nothrow__));






extern int killpg (__pid_t __pgrp, int __sig) __attribute__ ((__nothrow__));




extern int raise (int __sig) __attribute__ ((__nothrow__));




extern __sighandler_t ssignal (int __sig, __sighandler_t __handler)
     __attribute__ ((__nothrow__));
extern int gsignal (int __sig) __attribute__ ((__nothrow__));




extern void psignal (int __sig, __const char *__s);




extern void psiginfo (__const siginfo_t *__pinfo, __const char *__s);
# 168 "/usr/include/signal.h" 3 4
extern int __sigpause (int __sig_or_mask, int __is_sig);
# 177 "/usr/include/signal.h" 3 4
extern int sigpause (int __sig) __asm__ ("__xpg_sigpause");
# 196 "/usr/include/signal.h" 3 4
extern int sigblock (int __mask) __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__));


extern int sigsetmask (int __mask) __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__));


extern int siggetmask (void) __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__));
# 211 "/usr/include/signal.h" 3 4
typedef __sighandler_t sighandler_t;




typedef __sighandler_t sig_t;





extern int sigemptyset (sigset_t *__set) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int sigfillset (sigset_t *__set) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int sigaddset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int sigdelset (sigset_t *__set, int __signo) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int sigismember (__const sigset_t *__set, int __signo)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int sigisemptyset (__const sigset_t *__set) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int sigandset (sigset_t *__set, __const sigset_t *__left,
        __const sigset_t *__right) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2, 3)));


extern int sigorset (sigset_t *__set, __const sigset_t *__left,
       __const sigset_t *__right) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2, 3)));




# 1 "/usr/include/bits/sigaction.h" 1 3 4
# 25 "/usr/include/bits/sigaction.h" 3 4
struct sigaction
  {


    union
      {

 __sighandler_t sa_handler;

 void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;







    __sigset_t sa_mask;


    int sa_flags;


    void (*sa_restorer) (void);
  };
# 253 "/usr/include/signal.h" 2 3 4


extern int sigprocmask (int __how, __const sigset_t *__restrict __set,
   sigset_t *__restrict __oset) __attribute__ ((__nothrow__));






extern int sigsuspend (__const sigset_t *__set) __attribute__ ((__nonnull__ (1)));


extern int sigaction (int __sig, __const struct sigaction *__restrict __act,
        struct sigaction *__restrict __oact) __attribute__ ((__nothrow__));


extern int sigpending (sigset_t *__set) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern int sigwait (__const sigset_t *__restrict __set, int *__restrict __sig)
     __attribute__ ((__nonnull__ (1, 2)));






extern int sigwaitinfo (__const sigset_t *__restrict __set,
   siginfo_t *__restrict __info) __attribute__ ((__nonnull__ (1)));






extern int sigtimedwait (__const sigset_t *__restrict __set,
    siginfo_t *__restrict __info,
    __const struct timespec *__restrict __timeout)
     __attribute__ ((__nonnull__ (1)));



extern int sigqueue (__pid_t __pid, int __sig, __const union sigval __val)
     __attribute__ ((__nothrow__));
# 310 "/usr/include/signal.h" 3 4
extern __const char *__const _sys_siglist[65];
extern __const char *__const sys_siglist[65];


struct sigvec
  {
    __sighandler_t sv_handler;
    int sv_mask;

    int sv_flags;

  };
# 334 "/usr/include/signal.h" 3 4
extern int sigvec (int __sig, __const struct sigvec *__vec,
     struct sigvec *__ovec) __attribute__ ((__nothrow__));



# 1 "/usr/include/bits/sigcontext.h" 1 3 4
# 26 "/usr/include/bits/sigcontext.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 27 "/usr/include/bits/sigcontext.h" 2 3 4

struct _fpreg
{
  unsigned short significand[4];
  unsigned short exponent;
};

struct _fpxreg
{
  unsigned short significand[4];
  unsigned short exponent;
  unsigned short padding[3];
};

struct _xmmreg
{
  __uint32_t element[4];
};





struct _fpstate
{

  __uint32_t cw;
  __uint32_t sw;
  __uint32_t tag;
  __uint32_t ipoff;
  __uint32_t cssel;
  __uint32_t dataoff;
  __uint32_t datasel;
  struct _fpreg _st[8];
  unsigned short status;
  unsigned short magic;


  __uint32_t _fxsr_env[6];
  __uint32_t mxcsr;
  __uint32_t reserved;
  struct _fpxreg _fxsr_st[8];
  struct _xmmreg _xmm[8];
  __uint32_t padding[56];
};
# 81 "/usr/include/bits/sigcontext.h" 3 4
struct sigcontext
{
  unsigned short gs, __gsh;
  unsigned short fs, __fsh;
  unsigned short es, __esh;
  unsigned short ds, __dsh;
  unsigned long edi;
  unsigned long esi;
  unsigned long ebp;
  unsigned long esp;
  unsigned long ebx;
  unsigned long edx;
  unsigned long ecx;
  unsigned long eax;
  unsigned long trapno;
  unsigned long err;
  unsigned long eip;
  unsigned short cs, __csh;
  unsigned long eflags;
  unsigned long esp_at_signal;
  unsigned short ss, __ssh;
  struct _fpstate * fpstate;
  unsigned long oldmask;
  unsigned long cr2;
};
# 340 "/usr/include/signal.h" 2 3 4


extern int sigreturn (struct sigcontext *__scp) __attribute__ ((__nothrow__));






# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 350 "/usr/include/signal.h" 2 3 4




extern int siginterrupt (int __sig, int __interrupt) __attribute__ ((__nothrow__));

# 1 "/usr/include/bits/sigstack.h" 1 3 4
# 26 "/usr/include/bits/sigstack.h" 3 4
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };



enum
{
  SS_ONSTACK = 1,

  SS_DISABLE

};
# 50 "/usr/include/bits/sigstack.h" 3 4
typedef struct sigaltstack
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
# 357 "/usr/include/signal.h" 2 3 4


# 1 "/usr/include/sys/ucontext.h" 1 3 4
# 23 "/usr/include/sys/ucontext.h" 3 4
# 1 "/usr/include/signal.h" 1 3 4
# 24 "/usr/include/sys/ucontext.h" 2 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 25 "/usr/include/sys/ucontext.h" 2 3 4
# 148 "/usr/include/sys/ucontext.h" 3 4
typedef int greg_t;





typedef greg_t gregset_t[19];



enum
{
  REG_GS = 0,

  REG_FS,

  REG_ES,

  REG_DS,

  REG_EDI,

  REG_ESI,

  REG_EBP,

  REG_ESP,

  REG_EBX,

  REG_EDX,

  REG_ECX,

  REG_EAX,

  REG_TRAPNO,

  REG_ERR,

  REG_EIP,

  REG_CS,

  REG_EFL,

  REG_UESP,

  REG_SS

};



struct _libc_fpreg
{
  unsigned short int significand[4];
  unsigned short int exponent;
};

struct _libc_fpstate
{
  unsigned long int cw;
  unsigned long int sw;
  unsigned long int tag;
  unsigned long int ipoff;
  unsigned long int cssel;
  unsigned long int dataoff;
  unsigned long int datasel;
  struct _libc_fpreg _st[8];
  unsigned long int status;
};


typedef struct _libc_fpstate *fpregset_t;


typedef struct
  {
    gregset_t gregs;


    fpregset_t fpregs;
    unsigned long int oldmask;
    unsigned long int cr2;
  } mcontext_t;


typedef struct ucontext
  {
    unsigned long int uc_flags;
    struct ucontext *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    __sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
  } ucontext_t;
# 360 "/usr/include/signal.h" 2 3 4





extern int sigstack (struct sigstack *__ss, struct sigstack *__oss)
     __attribute__ ((__nothrow__)) __attribute__ ((__deprecated__));



extern int sigaltstack (__const struct sigaltstack *__restrict __ss,
   struct sigaltstack *__restrict __oss) __attribute__ ((__nothrow__));







extern int sighold (int __sig) __attribute__ ((__nothrow__));


extern int sigrelse (int __sig) __attribute__ ((__nothrow__));


extern int sigignore (int __sig) __attribute__ ((__nothrow__));


extern __sighandler_t sigset (int __sig, __sighandler_t __disp) __attribute__ ((__nothrow__));






# 1 "/usr/include/bits/sigthread.h" 1 3 4
# 31 "/usr/include/bits/sigthread.h" 3 4
extern int pthread_sigmask (int __how,
       __const __sigset_t *__restrict __newmask,
       __sigset_t *__restrict __oldmask)__attribute__ ((__nothrow__));


extern int pthread_kill (pthread_t __threadid, int __signo) __attribute__ ((__nothrow__));



extern int pthread_sigqueue (pthread_t __threadid, int __signo,
        const union sigval __value) __attribute__ ((__nothrow__));
# 396 "/usr/include/signal.h" 2 3 4






extern int __libc_current_sigrtmin (void) __attribute__ ((__nothrow__));

extern int __libc_current_sigrtmax (void) __attribute__ ((__nothrow__));




# 63 "ls.c" 2
# 1 "../lib/selinux/selinux.h" 1




# 1 "/usr/include/errno.h" 1 3 4
# 32 "/usr/include/errno.h" 3 4




# 1 "/usr/include/bits/errno.h" 1 3 4
# 25 "/usr/include/bits/errno.h" 3 4
# 1 "/usr/include/linux/errno.h" 1 3 4



# 1 "/usr/include/asm/errno.h" 1 3 4
# 1 "/usr/include/asm-generic/errno.h" 1 3 4



# 1 "/usr/include/asm-generic/errno-base.h" 1 3 4
# 5 "/usr/include/asm-generic/errno.h" 2 3 4
# 1 "/usr/include/asm/errno.h" 2 3 4
# 5 "/usr/include/linux/errno.h" 2 3 4
# 26 "/usr/include/bits/errno.h" 2 3 4
# 43 "/usr/include/bits/errno.h" 3 4
extern int *__errno_location (void) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
# 37 "/usr/include/errno.h" 2 3 4
# 55 "/usr/include/errno.h" 3 4
extern char *program_invocation_name, *program_invocation_short_name;




# 69 "/usr/include/errno.h" 3 4
typedef int error_t;
# 6 "../lib/selinux/selinux.h" 2
# 16 "../lib/selinux/selinux.h"
typedef unsigned short security_class_t;



static inline int getcon (char* *con) { (*__errno_location ()) = 95; return -1; }
static inline void freecon (char* con) {}


static inline int getfscreatecon (char* *con)
  { (*__errno_location ()) = 95; return -1; }
static inline int setfscreatecon (char* con)
  { (*__errno_location ()) = 95; return -1; }
static inline int matchpathcon (char const *s, mode_t m,
    char* *con)
  { (*__errno_location ()) = 95; return -1; }

static inline int getfilecon (char const *s, char* *con)
  { (*__errno_location ()) = 95; return -1; }
static inline int lgetfilecon (char const *s, char* *con)
  { (*__errno_location ()) = 95; return -1; }
static inline int setfilecon (char const *s, char* con)
  { (*__errno_location ()) = 95; return -1; }
static inline int lsetfilecon (char const *s, char* con)
  { (*__errno_location ()) = 95; return -1; }
static inline int fsetfilecon (int fd, char* con)
  { (*__errno_location ()) = 95; return -1; }

static inline int security_check_context (char* con)
  { (*__errno_location ()) = 95; return -1; }
static inline int security_check_context_raw (char* con)
  { (*__errno_location ()) = 95; return -1; }
static inline int setexeccon (char* con)
  { (*__errno_location ()) = 95; return -1; }
static inline int security_compute_create (char* scon,
        char* tcon,
        security_class_t tclass,
        char* *newcon)
  { (*__errno_location ()) = 95; return -1; }
static inline int matchpathcon_init_prefix (char const *path,
         char const *prefix)
  { (*__errno_location ()) = 95; return -1; }
# 64 "ls.c" 2
# 1 "/usr/include/wchar.h" 1 3 4
# 37 "/usr/include/wchar.h" 3 4
# 1 "../lib/stdio.h" 1 3 4
# 38 "/usr/include/wchar.h" 2 3 4




# 1 "/usr/include/bits/wchar.h" 1 3 4
# 43 "/usr/include/wchar.h" 2 3 4
# 52 "/usr/include/wchar.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 352 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 3 4
typedef unsigned int wint_t;
# 53 "/usr/include/wchar.h" 2 3 4
# 104 "/usr/include/wchar.h" 3 4


typedef __mbstate_t mbstate_t;



# 129 "/usr/include/wchar.h" 3 4





struct tm;









extern wchar_t *wcscpy (wchar_t *__restrict __dest,
   __const wchar_t *__restrict __src) __attribute__ ((__nothrow__));

extern wchar_t *wcsncpy (wchar_t *__restrict __dest,
    __const wchar_t *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__));


extern wchar_t *wcscat (wchar_t *__restrict __dest,
   __const wchar_t *__restrict __src) __attribute__ ((__nothrow__));

extern wchar_t *wcsncat (wchar_t *__restrict __dest,
    __const wchar_t *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__));


extern int wcscmp (__const wchar_t *__s1, __const wchar_t *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));

extern int wcsncmp (__const wchar_t *__s1, __const wchar_t *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));




extern int wcscasecmp (__const wchar_t *__s1, __const wchar_t *__s2) __attribute__ ((__nothrow__));


extern int wcsncasecmp (__const wchar_t *__s1, __const wchar_t *__s2,
   size_t __n) __attribute__ ((__nothrow__));



# 1 "/usr/include/xlocale.h" 1 3 4
# 28 "/usr/include/xlocale.h" 3 4
typedef struct __locale_struct
{

  struct locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;
# 178 "/usr/include/wchar.h" 2 3 4

extern int wcscasecmp_l (__const wchar_t *__s1, __const wchar_t *__s2,
    __locale_t __loc) __attribute__ ((__nothrow__));

extern int wcsncasecmp_l (__const wchar_t *__s1, __const wchar_t *__s2,
     size_t __n, __locale_t __loc) __attribute__ ((__nothrow__));





extern int wcscoll (__const wchar_t *__s1, __const wchar_t *__s2) __attribute__ ((__nothrow__));



extern size_t wcsxfrm (wchar_t *__restrict __s1,
         __const wchar_t *__restrict __s2, size_t __n) __attribute__ ((__nothrow__));








extern int wcscoll_l (__const wchar_t *__s1, __const wchar_t *__s2,
        __locale_t __loc) __attribute__ ((__nothrow__));




extern size_t wcsxfrm_l (wchar_t *__s1, __const wchar_t *__s2,
    size_t __n, __locale_t __loc) __attribute__ ((__nothrow__));


extern wchar_t *wcsdup (__const wchar_t *__s) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__));










extern wchar_t *wcschr (__const wchar_t *__wcs, wchar_t __wc)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
# 234 "/usr/include/wchar.h" 3 4
extern wchar_t *wcsrchr (__const wchar_t *__wcs, wchar_t __wc)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));






extern wchar_t *wcschrnul (__const wchar_t *__s, wchar_t __wc)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));





extern size_t wcscspn (__const wchar_t *__wcs, __const wchar_t *__reject)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));


extern size_t wcsspn (__const wchar_t *__wcs, __const wchar_t *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
# 263 "/usr/include/wchar.h" 3 4
extern wchar_t *wcspbrk (__const wchar_t *__wcs, __const wchar_t *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));
# 274 "/usr/include/wchar.h" 3 4
extern wchar_t *wcsstr (__const wchar_t *__haystack, __const wchar_t *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));



extern wchar_t *wcstok (wchar_t *__restrict __s,
   __const wchar_t *__restrict __delim,
   wchar_t **__restrict __ptr) __attribute__ ((__nothrow__));


extern size_t wcslen (__const wchar_t *__s) __attribute__ ((__nothrow__)) __attribute__ ((__pure__));

# 296 "/usr/include/wchar.h" 3 4
extern wchar_t *wcswcs (__const wchar_t *__haystack, __const wchar_t *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));





extern size_t wcsnlen (__const wchar_t *__s, size_t __maxlen)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));




# 317 "/usr/include/wchar.h" 3 4
extern wchar_t *wmemchr (__const wchar_t *__s, wchar_t __c, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));



extern int wmemcmp (__const wchar_t *__restrict __s1,
      __const wchar_t *__restrict __s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__));


extern wchar_t *wmemcpy (wchar_t *__restrict __s1,
    __const wchar_t *__restrict __s2, size_t __n) __attribute__ ((__nothrow__));



extern wchar_t *wmemmove (wchar_t *__s1, __const wchar_t *__s2, size_t __n)
     __attribute__ ((__nothrow__));


extern wchar_t *wmemset (wchar_t *__s, wchar_t __c, size_t __n) __attribute__ ((__nothrow__));





extern wchar_t *wmempcpy (wchar_t *__restrict __s1,
     __const wchar_t *__restrict __s2, size_t __n)
     __attribute__ ((__nothrow__));






extern wint_t btowc (int __c) __attribute__ ((__nothrow__));



extern int wctob (wint_t __c) __attribute__ ((__nothrow__));



extern int mbsinit (__const mbstate_t *__ps) __attribute__ ((__nothrow__)) __attribute__ ((__pure__));



extern size_t mbrtowc (wchar_t *__restrict __pwc,
         __const char *__restrict __s, size_t __n,
         mbstate_t *__p) __attribute__ ((__nothrow__));


extern size_t wcrtomb (char *__restrict __s, wchar_t __wc,
         mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));


extern size_t __mbrlen (__const char *__restrict __s, size_t __n,
   mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));
extern size_t mbrlen (__const char *__restrict __s, size_t __n,
        mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));

# 403 "/usr/include/wchar.h" 3 4



extern size_t mbsrtowcs (wchar_t *__restrict __dst,
    __const char **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));



extern size_t wcsrtombs (char *__restrict __dst,
    __const wchar_t **__restrict __src, size_t __len,
    mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));






extern size_t mbsnrtowcs (wchar_t *__restrict __dst,
     __const char **__restrict __src, size_t __nmc,
     size_t __len, mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));



extern size_t wcsnrtombs (char *__restrict __dst,
     __const wchar_t **__restrict __src,
     size_t __nwc, size_t __len,
     mbstate_t *__restrict __ps) __attribute__ ((__nothrow__));






extern int wcwidth (wchar_t __c) __attribute__ ((__nothrow__));



extern int wcswidth (__const wchar_t *__s, size_t __n) __attribute__ ((__nothrow__));






extern double wcstod (__const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr) __attribute__ ((__nothrow__));





extern float wcstof (__const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__));
extern long double wcstold (__const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr) __attribute__ ((__nothrow__));







extern long int wcstol (__const wchar_t *__restrict __nptr,
   wchar_t **__restrict __endptr, int __base) __attribute__ ((__nothrow__));



extern unsigned long int wcstoul (__const wchar_t *__restrict __nptr,
      wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__));






__extension__
extern long long int wcstoll (__const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__));



__extension__
extern unsigned long long int wcstoull (__const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr,
     int __base) __attribute__ ((__nothrow__));






__extension__
extern long long int wcstoq (__const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__));



__extension__
extern unsigned long long int wcstouq (__const wchar_t *__restrict __nptr,
           wchar_t **__restrict __endptr,
           int __base) __attribute__ ((__nothrow__));
# 528 "/usr/include/wchar.h" 3 4
extern long int wcstol_l (__const wchar_t *__restrict __nptr,
     wchar_t **__restrict __endptr, int __base,
     __locale_t __loc) __attribute__ ((__nothrow__));

extern unsigned long int wcstoul_l (__const wchar_t *__restrict __nptr,
        wchar_t **__restrict __endptr,
        int __base, __locale_t __loc) __attribute__ ((__nothrow__));

__extension__
extern long long int wcstoll_l (__const wchar_t *__restrict __nptr,
    wchar_t **__restrict __endptr,
    int __base, __locale_t __loc) __attribute__ ((__nothrow__));

__extension__
extern unsigned long long int wcstoull_l (__const wchar_t *__restrict __nptr,
       wchar_t **__restrict __endptr,
       int __base, __locale_t __loc)
     __attribute__ ((__nothrow__));

extern double wcstod_l (__const wchar_t *__restrict __nptr,
   wchar_t **__restrict __endptr, __locale_t __loc)
     __attribute__ ((__nothrow__));

extern float wcstof_l (__const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr, __locale_t __loc)
     __attribute__ ((__nothrow__));

extern long double wcstold_l (__const wchar_t *__restrict __nptr,
         wchar_t **__restrict __endptr,
         __locale_t __loc) __attribute__ ((__nothrow__));






extern wchar_t *wcpcpy (wchar_t *__dest, __const wchar_t *__src) __attribute__ ((__nothrow__));



extern wchar_t *wcpncpy (wchar_t *__dest, __const wchar_t *__src, size_t __n)
     __attribute__ ((__nothrow__));
# 578 "/usr/include/wchar.h" 3 4
extern __FILE *open_wmemstream (wchar_t **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__));






extern int fwide (__FILE *__fp, int __mode) __attribute__ ((__nothrow__));






extern int fwprintf (__FILE *__restrict __stream,
       __const wchar_t *__restrict __format, ...)
                                                           ;




extern int wprintf (__const wchar_t *__restrict __format, ...)
                                                           ;

extern int swprintf (wchar_t *__restrict __s, size_t __n,
       __const wchar_t *__restrict __format, ...)
     __attribute__ ((__nothrow__)) ;





extern int vfwprintf (__FILE *__restrict __s,
        __const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
                                                           ;




extern int vwprintf (__const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                           ;


extern int vswprintf (wchar_t *__restrict __s, size_t __n,
        __const wchar_t *__restrict __format,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) ;






extern int fwscanf (__FILE *__restrict __stream,
      __const wchar_t *__restrict __format, ...)
                                                          ;




extern int wscanf (__const wchar_t *__restrict __format, ...)
                                                          ;

extern int swscanf (__const wchar_t *__restrict __s,
      __const wchar_t *__restrict __format, ...)
     __attribute__ ((__nothrow__)) ;
# 678 "/usr/include/wchar.h" 3 4









extern int vfwscanf (__FILE *__restrict __s,
       __const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
                                                          ;




extern int vwscanf (__const wchar_t *__restrict __format,
      __gnuc_va_list __arg)
                                                          ;

extern int vswscanf (__const wchar_t *__restrict __s,
       __const wchar_t *__restrict __format,
       __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) ;
# 734 "/usr/include/wchar.h" 3 4









extern wint_t fgetwc (__FILE *__stream);
extern wint_t getwc (__FILE *__stream);





extern wint_t getwchar (void);






extern wint_t fputwc (wchar_t __wc, __FILE *__stream);
extern wint_t putwc (wchar_t __wc, __FILE *__stream);





extern wint_t putwchar (wchar_t __wc);







extern wchar_t *fgetws (wchar_t *__restrict __ws, int __n,
   __FILE *__restrict __stream);





extern int fputws (__const wchar_t *__restrict __ws,
     __FILE *__restrict __stream);






extern wint_t ungetwc (wint_t __wc, __FILE *__stream);

# 799 "/usr/include/wchar.h" 3 4
extern wint_t getwc_unlocked (__FILE *__stream);
extern wint_t getwchar_unlocked (void);







extern wint_t fgetwc_unlocked (__FILE *__stream);







extern wint_t fputwc_unlocked (wchar_t __wc, __FILE *__stream);
# 825 "/usr/include/wchar.h" 3 4
extern wint_t putwc_unlocked (wchar_t __wc, __FILE *__stream);
extern wint_t putwchar_unlocked (wchar_t __wc);
# 835 "/usr/include/wchar.h" 3 4
extern wchar_t *fgetws_unlocked (wchar_t *__restrict __ws, int __n,
     __FILE *__restrict __stream);







extern int fputws_unlocked (__const wchar_t *__restrict __ws,
       __FILE *__restrict __stream);







extern size_t wcsftime (wchar_t *__restrict __s, size_t __maxsize,
   __const wchar_t *__restrict __format,
   __const struct tm *__restrict __tp) __attribute__ ((__nothrow__));







extern size_t wcsftime_l (wchar_t *__restrict __s, size_t __maxsize,
     __const wchar_t *__restrict __format,
     __const struct tm *__restrict __tp,
     __locale_t __loc) __attribute__ ((__nothrow__));
# 889 "/usr/include/wchar.h" 3 4

# 65 "ls.c" 2
# 80 "ls.c"
# 1 "system.h" 1
# 17 "system.h"
# 1 "../lib/alloca.h" 1
# 18 "system.h" 2
# 27 "system.h"
# 1 "../lib/sys/stat.h" 1
# 30 "../lib/sys/stat.h"
# 1 "/usr/include/sys/stat.h" 1 3 4
# 39 "/usr/include/sys/stat.h" 3 4
# 1 "../lib/time.h" 1 3 4
# 31 "../lib/time.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 32 "../lib/time.h" 2 3 4
# 40 "/usr/include/sys/stat.h" 2 3 4
# 105 "/usr/include/sys/stat.h" 3 4


# 1 "/usr/include/bits/stat.h" 1 3 4
# 43 "/usr/include/bits/stat.h" 3 4
struct stat
  {
    __dev_t st_dev;

    unsigned short int __pad1;




    __ino_t __st_ino;


    __mode_t st_mode;
    __nlink_t st_nlink;




    __uid_t st_uid;
    __gid_t st_gid;



    __dev_t st_rdev;

    unsigned short int __pad2;




    __off64_t st_size;

    __blksize_t st_blksize;



    __blkcnt64_t st_blocks;
# 88 "/usr/include/bits/stat.h" 3 4
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
# 109 "/usr/include/bits/stat.h" 3 4
    __ino64_t st_ino;


  };



struct stat64
  {
    __dev_t st_dev;





    unsigned int __pad1;
    __ino_t __st_ino;
    __mode_t st_mode;
    __nlink_t st_nlink;

    __uid_t st_uid;
    __gid_t st_gid;





    __dev_t st_rdev;
    unsigned int __pad2;
    __off64_t st_size;

    __blksize_t st_blksize;
    __blkcnt64_t st_blocks;







    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
# 166 "/usr/include/bits/stat.h" 3 4
    __ino64_t st_ino;

  };
# 108 "/usr/include/sys/stat.h" 2 3 4
# 217 "/usr/include/sys/stat.h" 3 4
extern int stat (__const char *__restrict __file, struct stat *__restrict __buf) __asm__ ("" "stat64") __attribute__ ((__nothrow__))

     __attribute__ ((__nonnull__ (1, 2)));
extern int fstat (int __fd, struct stat *__buf) __asm__ ("" "fstat64") __attribute__ ((__nothrow__))
     __attribute__ ((__nonnull__ (2)));






extern int stat64 (__const char *__restrict __file,
     struct stat64 *__restrict __buf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fstat64 (int __fd, struct stat64 *__buf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
# 243 "/usr/include/sys/stat.h" 3 4
extern int fstatat (int __fd, __const char *__restrict __file, struct stat *__restrict __buf, int __flag) __asm__ ("" "fstatat64") __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
# 253 "/usr/include/sys/stat.h" 3 4
extern int fstatat64 (int __fd, __const char *__restrict __file,
        struct stat64 *__restrict __buf, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
# 267 "/usr/include/sys/stat.h" 3 4
extern int lstat (__const char *__restrict __file, struct stat *__restrict __buf) __asm__ ("" "lstat64") __attribute__ ((__nothrow__))


     __attribute__ ((__nonnull__ (1, 2)));





extern int lstat64 (__const char *__restrict __file,
      struct stat64 *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));





extern int chmod (__const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int lchmod (__const char *__file, __mode_t __mode)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));




extern int fchmod (int __fd, __mode_t __mode) __attribute__ ((__nothrow__));





extern int fchmodat (int __fd, __const char *__file, __mode_t __mode,
       int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;






extern __mode_t umask (__mode_t __mask) __attribute__ ((__nothrow__));




extern __mode_t getumask (void) __attribute__ ((__nothrow__));



extern int mkdir (__const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int mkdirat (int __fd, __const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));






extern int mknod (__const char *__path, __mode_t __mode, __dev_t __dev)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int mknodat (int __fd, __const char *__path, __mode_t __mode,
      __dev_t __dev) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));





extern int mkfifo (__const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int mkfifoat (int __fd, __const char *__path, __mode_t __mode)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));





extern int utimensat (int __fd, __const char *__path,
        __const struct timespec __times[2],
        int __flags)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));




extern int futimens (int __fd, __const struct timespec __times[2]) __attribute__ ((__nothrow__));
# 410 "/usr/include/sys/stat.h" 3 4
extern int __fxstat (int __ver, int __fildes, struct stat *__stat_buf) __asm__ ("" "__fxstat64") __attribute__ ((__nothrow__))

     __attribute__ ((__nonnull__ (3)));
extern int __xstat (int __ver, __const char *__filename, struct stat *__stat_buf) __asm__ ("" "__xstat64") __attribute__ ((__nothrow__))

     __attribute__ ((__nonnull__ (2, 3)));
extern int __lxstat (int __ver, __const char *__filename, struct stat *__stat_buf) __asm__ ("" "__lxstat64") __attribute__ ((__nothrow__))

     __attribute__ ((__nonnull__ (2, 3)));
extern int __fxstatat (int __ver, int __fildes, __const char *__filename, struct stat *__stat_buf, int __flag) __asm__ ("" "__fxstatat64") __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4)));
# 432 "/usr/include/sys/stat.h" 3 4
extern int __fxstat64 (int __ver, int __fildes, struct stat64 *__stat_buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3)));
extern int __xstat64 (int __ver, __const char *__filename,
        struct stat64 *__stat_buf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
extern int __lxstat64 (int __ver, __const char *__filename,
         struct stat64 *__stat_buf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
extern int __fxstatat64 (int __ver, int __fildes, __const char *__filename,
    struct stat64 *__stat_buf, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4)));

extern int __xmknod (int __ver, __const char *__path, __mode_t __mode,
       __dev_t *__dev) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));

extern int __xmknodat (int __ver, int __fd, __const char *__path,
         __mode_t __mode, __dev_t *__dev)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 5)));
# 534 "/usr/include/sys/stat.h" 3 4

# 31 "../lib/sys/stat.h" 2
# 28 "system.h" 2






# 1 "/usr/include/sys/param.h" 1 3 4
# 26 "/usr/include/sys/param.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/limits.h" 1 3 4
# 11 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/limits.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/syslimits.h" 1 3 4






# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/limits.h" 1 3 4
# 122 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/limits.h" 3 4
# 1 "/usr/include/limits.h" 1 3 4
# 145 "/usr/include/limits.h" 3 4
# 1 "/usr/include/bits/posix1_lim.h" 1 3 4
# 157 "/usr/include/bits/posix1_lim.h" 3 4
# 1 "/usr/include/bits/local_lim.h" 1 3 4
# 39 "/usr/include/bits/local_lim.h" 3 4
# 1 "/usr/include/linux/limits.h" 1 3 4
# 40 "/usr/include/bits/local_lim.h" 2 3 4
# 158 "/usr/include/bits/posix1_lim.h" 2 3 4
# 146 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/bits/posix2_lim.h" 1 3 4
# 150 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/bits/xopen_lim.h" 1 3 4
# 34 "/usr/include/bits/xopen_lim.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 35 "/usr/include/bits/xopen_lim.h" 2 3 4
# 154 "/usr/include/limits.h" 2 3 4
# 123 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/limits.h" 2 3 4
# 8 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/syslimits.h" 2 3 4
# 12 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/limits.h" 2 3 4
# 27 "/usr/include/sys/param.h" 2 3 4

# 1 "/usr/include/linux/param.h" 1 3 4



# 1 "/usr/include/asm/param.h" 1 3 4
# 1 "/usr/include/asm-generic/param.h" 1 3 4
# 1 "/usr/include/asm/param.h" 2 3 4
# 5 "/usr/include/linux/param.h" 2 3 4
# 29 "/usr/include/sys/param.h" 2 3 4
# 35 "system.h" 2


# 1 "../lib/unistd.h" 1
# 25 "../lib/unistd.h"
# 1 "/usr/include/unistd.h" 1 3 4
# 28 "/usr/include/unistd.h" 3 4

# 203 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/bits/posix_opt.h" 1 3 4
# 204 "/usr/include/unistd.h" 2 3 4



# 1 "/usr/include/bits/environments.h" 1 3 4
# 23 "/usr/include/bits/environments.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 24 "/usr/include/bits/environments.h" 2 3 4
# 208 "/usr/include/unistd.h" 2 3 4
# 227 "/usr/include/unistd.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 228 "/usr/include/unistd.h" 2 3 4
# 268 "/usr/include/unistd.h" 3 4
typedef __intptr_t intptr_t;






typedef __socklen_t socklen_t;
# 288 "/usr/include/unistd.h" 3 4
extern int access (__const char *__name, int __type) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));




extern int euidaccess (__const char *__name, int __type)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int eaccess (__const char *__name, int __type)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern int faccessat (int __fd, __const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;
# 334 "/usr/include/unistd.h" 3 4
extern __off64_t lseek (int __fd, __off64_t __offset, int __whence) __asm__ ("" "lseek64") __attribute__ ((__nothrow__));







extern __off64_t lseek64 (int __fd, __off64_t __offset, int __whence)
     __attribute__ ((__nothrow__));






extern int close (int __fd);






extern ssize_t read (int __fd, void *__buf, size_t __nbytes) ;





extern ssize_t write (int __fd, __const void *__buf, size_t __n) ;
# 385 "/usr/include/unistd.h" 3 4
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes, __off64_t __offset) __asm__ ("" "pread64") ;


extern ssize_t pwrite (int __fd, __const void *__buf, size_t __nbytes, __off64_t __offset) __asm__ ("" "pwrite64") ;
# 401 "/usr/include/unistd.h" 3 4
extern ssize_t pread64 (int __fd, void *__buf, size_t __nbytes,
   __off64_t __offset) ;


extern ssize_t pwrite64 (int __fd, __const void *__buf, size_t __n,
    __off64_t __offset) ;







extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__)) ;




extern int pipe2 (int __pipedes[2], int __flags) __attribute__ ((__nothrow__)) ;
# 429 "/usr/include/unistd.h" 3 4
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__));
# 441 "/usr/include/unistd.h" 3 4
extern unsigned int sleep (unsigned int __seconds);






extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__));






extern int usleep (__useconds_t __useconds);
# 465 "/usr/include/unistd.h" 3 4
extern int pause (void);



extern int chown (__const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;



extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__)) ;




extern int lchown (__const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;






extern int fchownat (int __fd, __const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;



extern int chdir (__const char *__path) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;



extern int fchdir (int __fd) __attribute__ ((__nothrow__)) ;
# 507 "/usr/include/unistd.h" 3 4
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__)) ;





extern char *get_current_dir_name (void) __attribute__ ((__nothrow__));






extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) ;




extern int dup (int __fd) __attribute__ ((__nothrow__)) ;


extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__));




extern int dup3 (int __fd, int __fd2, int __flags) __attribute__ ((__nothrow__));



extern char **__environ;

extern char **environ;





extern int execve (__const char *__path, char *__const __argv[],
     char *__const __envp[]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));




extern int fexecve (int __fd, char *__const __argv[], char *__const __envp[])
     __attribute__ ((__nothrow__));




extern int execv (__const char *__path, char *__const __argv[])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int execle (__const char *__path, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int execl (__const char *__path, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int execvp (__const char *__file, char *__const __argv[])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));




extern int execlp (__const char *__file, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));




extern int execvpe (__const char *__file, char *__const __argv[],
      char *__const __envp[])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int nice (int __inc) __attribute__ ((__nothrow__)) ;




extern void _exit (int __status) __attribute__ ((__noreturn__));





# 1 "/usr/include/bits/confname.h" 1 3 4
# 26 "/usr/include/bits/confname.h" 3 4
enum
  {
    _PC_LINK_MAX,

    _PC_MAX_CANON,

    _PC_MAX_INPUT,

    _PC_NAME_MAX,

    _PC_PATH_MAX,

    _PC_PIPE_BUF,

    _PC_CHOWN_RESTRICTED,

    _PC_NO_TRUNC,

    _PC_VDISABLE,

    _PC_SYNC_IO,

    _PC_ASYNC_IO,

    _PC_PRIO_IO,

    _PC_SOCK_MAXBUF,

    _PC_FILESIZEBITS,

    _PC_REC_INCR_XFER_SIZE,

    _PC_REC_MAX_XFER_SIZE,

    _PC_REC_MIN_XFER_SIZE,

    _PC_REC_XFER_ALIGN,

    _PC_ALLOC_SIZE_MIN,

    _PC_SYMLINK_MAX,

    _PC_2_SYMLINKS

  };


enum
  {
    _SC_ARG_MAX,

    _SC_CHILD_MAX,

    _SC_CLK_TCK,

    _SC_NGROUPS_MAX,

    _SC_OPEN_MAX,

    _SC_STREAM_MAX,

    _SC_TZNAME_MAX,

    _SC_JOB_CONTROL,

    _SC_SAVED_IDS,

    _SC_REALTIME_SIGNALS,

    _SC_PRIORITY_SCHEDULING,

    _SC_TIMERS,

    _SC_ASYNCHRONOUS_IO,

    _SC_PRIORITIZED_IO,

    _SC_SYNCHRONIZED_IO,

    _SC_FSYNC,

    _SC_MAPPED_FILES,

    _SC_MEMLOCK,

    _SC_MEMLOCK_RANGE,

    _SC_MEMORY_PROTECTION,

    _SC_MESSAGE_PASSING,

    _SC_SEMAPHORES,

    _SC_SHARED_MEMORY_OBJECTS,

    _SC_AIO_LISTIO_MAX,

    _SC_AIO_MAX,

    _SC_AIO_PRIO_DELTA_MAX,

    _SC_DELAYTIMER_MAX,

    _SC_MQ_OPEN_MAX,

    _SC_MQ_PRIO_MAX,

    _SC_VERSION,

    _SC_PAGESIZE,


    _SC_RTSIG_MAX,

    _SC_SEM_NSEMS_MAX,

    _SC_SEM_VALUE_MAX,

    _SC_SIGQUEUE_MAX,

    _SC_TIMER_MAX,




    _SC_BC_BASE_MAX,

    _SC_BC_DIM_MAX,

    _SC_BC_SCALE_MAX,

    _SC_BC_STRING_MAX,

    _SC_COLL_WEIGHTS_MAX,

    _SC_EQUIV_CLASS_MAX,

    _SC_EXPR_NEST_MAX,

    _SC_LINE_MAX,

    _SC_RE_DUP_MAX,

    _SC_CHARCLASS_NAME_MAX,


    _SC_2_VERSION,

    _SC_2_C_BIND,

    _SC_2_C_DEV,

    _SC_2_FORT_DEV,

    _SC_2_FORT_RUN,

    _SC_2_SW_DEV,

    _SC_2_LOCALEDEF,


    _SC_PII,

    _SC_PII_XTI,

    _SC_PII_SOCKET,

    _SC_PII_INTERNET,

    _SC_PII_OSI,

    _SC_POLL,

    _SC_SELECT,

    _SC_UIO_MAXIOV,

    _SC_IOV_MAX = _SC_UIO_MAXIOV,

    _SC_PII_INTERNET_STREAM,

    _SC_PII_INTERNET_DGRAM,

    _SC_PII_OSI_COTS,

    _SC_PII_OSI_CLTS,

    _SC_PII_OSI_M,

    _SC_T_IOV_MAX,



    _SC_THREADS,

    _SC_THREAD_SAFE_FUNCTIONS,

    _SC_GETGR_R_SIZE_MAX,

    _SC_GETPW_R_SIZE_MAX,

    _SC_LOGIN_NAME_MAX,

    _SC_TTY_NAME_MAX,

    _SC_THREAD_DESTRUCTOR_ITERATIONS,

    _SC_THREAD_KEYS_MAX,

    _SC_THREAD_STACK_MIN,

    _SC_THREAD_THREADS_MAX,

    _SC_THREAD_ATTR_STACKADDR,

    _SC_THREAD_ATTR_STACKSIZE,

    _SC_THREAD_PRIORITY_SCHEDULING,

    _SC_THREAD_PRIO_INHERIT,

    _SC_THREAD_PRIO_PROTECT,

    _SC_THREAD_PROCESS_SHARED,


    _SC_NPROCESSORS_CONF,

    _SC_NPROCESSORS_ONLN,

    _SC_PHYS_PAGES,

    _SC_AVPHYS_PAGES,

    _SC_ATEXIT_MAX,

    _SC_PASS_MAX,


    _SC_XOPEN_VERSION,

    _SC_XOPEN_XCU_VERSION,

    _SC_XOPEN_UNIX,

    _SC_XOPEN_CRYPT,

    _SC_XOPEN_ENH_I18N,

    _SC_XOPEN_SHM,


    _SC_2_CHAR_TERM,

    _SC_2_C_VERSION,

    _SC_2_UPE,


    _SC_XOPEN_XPG2,

    _SC_XOPEN_XPG3,

    _SC_XOPEN_XPG4,


    _SC_CHAR_BIT,

    _SC_CHAR_MAX,

    _SC_CHAR_MIN,

    _SC_INT_MAX,

    _SC_INT_MIN,

    _SC_LONG_BIT,

    _SC_WORD_BIT,

    _SC_MB_LEN_MAX,

    _SC_NZERO,

    _SC_SSIZE_MAX,

    _SC_SCHAR_MAX,

    _SC_SCHAR_MIN,

    _SC_SHRT_MAX,

    _SC_SHRT_MIN,

    _SC_UCHAR_MAX,

    _SC_UINT_MAX,

    _SC_ULONG_MAX,

    _SC_USHRT_MAX,


    _SC_NL_ARGMAX,

    _SC_NL_LANGMAX,

    _SC_NL_MSGMAX,

    _SC_NL_NMAX,

    _SC_NL_SETMAX,

    _SC_NL_TEXTMAX,


    _SC_XBS5_ILP32_OFF32,

    _SC_XBS5_ILP32_OFFBIG,

    _SC_XBS5_LP64_OFF64,

    _SC_XBS5_LPBIG_OFFBIG,


    _SC_XOPEN_LEGACY,

    _SC_XOPEN_REALTIME,

    _SC_XOPEN_REALTIME_THREADS,


    _SC_ADVISORY_INFO,

    _SC_BARRIERS,

    _SC_BASE,

    _SC_C_LANG_SUPPORT,

    _SC_C_LANG_SUPPORT_R,

    _SC_CLOCK_SELECTION,

    _SC_CPUTIME,

    _SC_THREAD_CPUTIME,

    _SC_DEVICE_IO,

    _SC_DEVICE_SPECIFIC,

    _SC_DEVICE_SPECIFIC_R,

    _SC_FD_MGMT,

    _SC_FIFO,

    _SC_PIPE,

    _SC_FILE_ATTRIBUTES,

    _SC_FILE_LOCKING,

    _SC_FILE_SYSTEM,

    _SC_MONOTONIC_CLOCK,

    _SC_MULTI_PROCESS,

    _SC_SINGLE_PROCESS,

    _SC_NETWORKING,

    _SC_READER_WRITER_LOCKS,

    _SC_SPIN_LOCKS,

    _SC_REGEXP,

    _SC_REGEX_VERSION,

    _SC_SHELL,

    _SC_SIGNALS,

    _SC_SPAWN,

    _SC_SPORADIC_SERVER,

    _SC_THREAD_SPORADIC_SERVER,

    _SC_SYSTEM_DATABASE,

    _SC_SYSTEM_DATABASE_R,

    _SC_TIMEOUTS,

    _SC_TYPED_MEMORY_OBJECTS,

    _SC_USER_GROUPS,

    _SC_USER_GROUPS_R,

    _SC_2_PBS,

    _SC_2_PBS_ACCOUNTING,

    _SC_2_PBS_LOCATE,

    _SC_2_PBS_MESSAGE,

    _SC_2_PBS_TRACK,

    _SC_SYMLOOP_MAX,

    _SC_STREAMS,

    _SC_2_PBS_CHECKPOINT,


    _SC_V6_ILP32_OFF32,

    _SC_V6_ILP32_OFFBIG,

    _SC_V6_LP64_OFF64,

    _SC_V6_LPBIG_OFFBIG,


    _SC_HOST_NAME_MAX,

    _SC_TRACE,

    _SC_TRACE_EVENT_FILTER,

    _SC_TRACE_INHERIT,

    _SC_TRACE_LOG,


    _SC_LEVEL1_ICACHE_SIZE,

    _SC_LEVEL1_ICACHE_ASSOC,

    _SC_LEVEL1_ICACHE_LINESIZE,

    _SC_LEVEL1_DCACHE_SIZE,

    _SC_LEVEL1_DCACHE_ASSOC,

    _SC_LEVEL1_DCACHE_LINESIZE,

    _SC_LEVEL2_CACHE_SIZE,

    _SC_LEVEL2_CACHE_ASSOC,

    _SC_LEVEL2_CACHE_LINESIZE,

    _SC_LEVEL3_CACHE_SIZE,

    _SC_LEVEL3_CACHE_ASSOC,

    _SC_LEVEL3_CACHE_LINESIZE,

    _SC_LEVEL4_CACHE_SIZE,

    _SC_LEVEL4_CACHE_ASSOC,

    _SC_LEVEL4_CACHE_LINESIZE,



    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,

    _SC_RAW_SOCKETS,


    _SC_V7_ILP32_OFF32,

    _SC_V7_ILP32_OFFBIG,

    _SC_V7_LP64_OFF64,

    _SC_V7_LPBIG_OFFBIG,


    _SC_SS_REPL_MAX,


    _SC_TRACE_EVENT_NAME_MAX,

    _SC_TRACE_NAME_MAX,

    _SC_TRACE_SYS_MAX,

    _SC_TRACE_USER_EVENT_MAX,


    _SC_XOPEN_STREAMS,


    _SC_THREAD_ROBUST_PRIO_INHERIT,

    _SC_THREAD_ROBUST_PRIO_PROTECT

  };


enum
  {
    _CS_PATH,


    _CS_V6_WIDTH_RESTRICTED_ENVS,



    _CS_GNU_LIBC_VERSION,

    _CS_GNU_LIBPTHREAD_VERSION,


    _CS_V5_WIDTH_RESTRICTED_ENVS,



    _CS_V7_WIDTH_RESTRICTED_ENVS,



    _CS_LFS_CFLAGS = 1000,

    _CS_LFS_LDFLAGS,

    _CS_LFS_LIBS,

    _CS_LFS_LINTFLAGS,

    _CS_LFS64_CFLAGS,

    _CS_LFS64_LDFLAGS,

    _CS_LFS64_LIBS,

    _CS_LFS64_LINTFLAGS,


    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

    _CS_XBS5_ILP32_OFF32_LDFLAGS,

    _CS_XBS5_ILP32_OFF32_LIBS,

    _CS_XBS5_ILP32_OFF32_LINTFLAGS,

    _CS_XBS5_ILP32_OFFBIG_CFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LIBS,

    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

    _CS_XBS5_LP64_OFF64_CFLAGS,

    _CS_XBS5_LP64_OFF64_LDFLAGS,

    _CS_XBS5_LP64_OFF64_LIBS,

    _CS_XBS5_LP64_OFF64_LINTFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LIBS,

    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LIBS,

    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V6_LP64_OFF64_CFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LIBS,

    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LIBS,

    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V7_LP64_OFF64_CFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LIBS,

    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS

  };
# 605 "/usr/include/unistd.h" 2 3 4


extern long int pathconf (__const char *__path, int __name)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__));


extern long int sysconf (int __name) __attribute__ ((__nothrow__));



extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__));




extern __pid_t getpid (void) __attribute__ ((__nothrow__));


extern __pid_t getppid (void) __attribute__ ((__nothrow__));




extern __pid_t getpgrp (void) __attribute__ ((__nothrow__));
# 641 "/usr/include/unistd.h" 3 4
extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__));

extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__));






extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__));
# 667 "/usr/include/unistd.h" 3 4
extern int setpgrp (void) __attribute__ ((__nothrow__));
# 684 "/usr/include/unistd.h" 3 4
extern __pid_t setsid (void) __attribute__ ((__nothrow__));



extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__));



extern __uid_t getuid (void) __attribute__ ((__nothrow__));


extern __uid_t geteuid (void) __attribute__ ((__nothrow__));


extern __gid_t getgid (void) __attribute__ ((__nothrow__));


extern __gid_t getegid (void) __attribute__ ((__nothrow__));




extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__)) ;



extern int group_member (__gid_t __gid) __attribute__ ((__nothrow__));






extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__));




extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__));




extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__));






extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__));




extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__));




extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__));





extern int getresuid (__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid)
     __attribute__ ((__nothrow__));



extern int getresgid (__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid)
     __attribute__ ((__nothrow__));



extern int setresuid (__uid_t __ruid, __uid_t __euid, __uid_t __suid)
     __attribute__ ((__nothrow__));



extern int setresgid (__gid_t __rgid, __gid_t __egid, __gid_t __sgid)
     __attribute__ ((__nothrow__));






extern __pid_t fork (void) __attribute__ ((__nothrow__));






extern __pid_t vfork (void) __attribute__ ((__nothrow__));





extern char *ttyname (int __fd) __attribute__ ((__nothrow__));



extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;



extern int isatty (int __fd) __attribute__ ((__nothrow__));





extern int ttyslot (void) __attribute__ ((__nothrow__));




extern int link (__const char *__from, __const char *__to)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern int linkat (int __fromfd, __const char *__from, int __tofd,
     __const char *__to, int __flags)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4))) ;




extern int symlink (__const char *__from, __const char *__to)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern ssize_t readlink (__const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern int symlinkat (__const char *__from, int __tofd,
        __const char *__to) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3))) ;


extern ssize_t readlinkat (int __fd, __const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3))) ;



extern int unlink (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int unlinkat (int __fd, __const char *__name, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));



extern int rmdir (__const char *__path) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__));


extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__));






extern char *getlogin (void);







extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)));




extern int setlogin (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 895 "/usr/include/unistd.h" 3 4
extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern int sethostname (__const char *__name, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;



extern int sethostid (long int __id) __attribute__ ((__nothrow__)) ;





extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int setdomainname (__const char *__name, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





extern int vhangup (void) __attribute__ ((__nothrow__));


extern int revoke (__const char *__file) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;







extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int acct (__const char *__name) __attribute__ ((__nothrow__));



extern char *getusershell (void) __attribute__ ((__nothrow__));
extern void endusershell (void) __attribute__ ((__nothrow__));
extern void setusershell (void) __attribute__ ((__nothrow__));





extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__)) ;






extern int chroot (__const char *__path) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;



extern char *gnu_getpass (__const char *__prompt) __attribute__ ((__nonnull__ (1)));
# 973 "/usr/include/unistd.h" 3 4
extern int fsync (int __fd);






extern long int gethostid (void);


extern void sync (void) __attribute__ ((__nothrow__));




extern int getpagesize (void) __attribute__ ((__nothrow__)) __attribute__ ((__const__));




extern int getdtablesize (void) __attribute__ ((__nothrow__));
# 1002 "/usr/include/unistd.h" 3 4
extern int truncate (__const char *__file, __off64_t __length) __asm__ ("" "truncate64") __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;







extern int truncate64 (__const char *__file, __off64_t __length)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 1023 "/usr/include/unistd.h" 3 4
extern int ftruncate (int __fd, __off64_t __length) __asm__ ("" "ftruncate64") __attribute__ ((__nothrow__)) ;






extern int ftruncate64 (int __fd, __off64_t __length) __attribute__ ((__nothrow__)) ;
# 1040 "/usr/include/unistd.h" 3 4
extern int brk (void *__addr) __attribute__ ((__nothrow__)) ;





extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__));
# 1061 "/usr/include/unistd.h" 3 4
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__));
# 1087 "/usr/include/unistd.h" 3 4
extern int lockf (int __fd, int __cmd, __off64_t __len) __asm__ ("" "lockf64") ;






extern int lockf64 (int __fd, int __cmd, __off64_t __len) ;
# 1115 "/usr/include/unistd.h" 3 4
extern int fdatasync (int __fildes);







extern char *crypt (__const char *__key, __const char *__salt)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));



extern void encrypt (char *__block, int __edflag) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern void swab (__const void *__restrict __from, void *__restrict __to,
    ssize_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));







extern char *ctermid (char *__s) __attribute__ ((__nothrow__));
# 1153 "/usr/include/unistd.h" 3 4

# 26 "../lib/unistd.h" 2
# 37 "../lib/unistd.h"
# 1 "../lib/stdlib.h" 1
# 30 "../lib/stdlib.h"
# 1 "/usr/include/stdlib.h" 1 3 4
# 33 "/usr/include/stdlib.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 34 "/usr/include/stdlib.h" 2 3 4








# 1 "/usr/include/bits/waitflags.h" 1 3 4
# 43 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/bits/waitstatus.h" 1 3 4
# 67 "/usr/include/bits/waitstatus.h" 3 4
union wait
  {
    int w_status;
    struct
      {

 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;







      } __wait_terminated;
    struct
      {

 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;






      } __wait_stopped;
  };
# 44 "/usr/include/stdlib.h" 2 3 4
# 68 "/usr/include/stdlib.h" 3 4
typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));
# 96 "/usr/include/stdlib.h" 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;







__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;


# 140 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__)) ;




extern double atof (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





__extension__ extern long long int atoll (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





extern double strtod (__const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





extern float strtof (__const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern long double strtold (__const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





extern long int strtol (__const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern unsigned long int strtoul (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;




__extension__
extern long long int strtoq (__const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





__extension__
extern long long int strtoll (__const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

# 240 "/usr/include/stdlib.h" 3 4
extern long int strtol_l (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base,
     __locale_t __loc) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 4))) ;

extern unsigned long int strtoul_l (__const char *__restrict __nptr,
        char **__restrict __endptr,
        int __base, __locale_t __loc)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 4))) ;

__extension__
extern long long int strtoll_l (__const char *__restrict __nptr,
    char **__restrict __endptr, int __base,
    __locale_t __loc)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 4))) ;

__extension__
extern unsigned long long int strtoull_l (__const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, __locale_t __loc)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 4))) ;

extern double strtod_l (__const char *__restrict __nptr,
   char **__restrict __endptr, __locale_t __loc)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3))) ;

extern float strtof_l (__const char *__restrict __nptr,
         char **__restrict __endptr, __locale_t __loc)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3))) ;

extern long double strtold_l (__const char *__restrict __nptr,
         char **__restrict __endptr,
         __locale_t __loc)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3))) ;
# 311 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) __attribute__ ((__nothrow__)) ;


extern long int a64l (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
# 327 "/usr/include/stdlib.h" 3 4
extern long int random (void) __attribute__ ((__nothrow__));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));






extern int rand (void) __attribute__ ((__nothrow__));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__));




extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__));







extern double drand48 (void) __attribute__ ((__nothrow__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));









extern void *malloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;










extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__warn_unused_result__));

extern void free (void *__ptr) __attribute__ ((__nothrow__));




extern void cfree (void *__ptr) __attribute__ ((__nothrow__));
# 502 "/usr/include/stdlib.h" 3 4
extern void *valloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;




extern void abort (void) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 527 "/usr/include/stdlib.h" 3 4
extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));







extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern void exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));







extern void quick_exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));







extern void _Exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));






extern char *getenv (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;




extern char *__secure_getenv (__const char *__name)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





extern int putenv (char *__string) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int setenv (__const char *__name, __const char *__value, int __replace)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (__const char *__name) __attribute__ ((__nothrow__));






extern int clearenv (void) __attribute__ ((__nothrow__));
# 604 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 618 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __asm__ ("" "mkstemp64")
     __attribute__ ((__nonnull__ (1))) ;





extern int mkstemp64 (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 640 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __asm__ ("" "mkstemps64") __attribute__ ((__nonnull__ (1))) ;






extern int mkstemps64 (char *__template, int __suffixlen)
     __attribute__ ((__nonnull__ (1))) ;
# 658 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 672 "/usr/include/stdlib.h" 3 4
extern int mkostemp (char *__template, int __flags) __asm__ ("" "mkostemp64")
     __attribute__ ((__nonnull__ (1))) ;





extern int mkostemp64 (char *__template, int __flags) __attribute__ ((__nonnull__ (1))) ;
# 693 "/usr/include/stdlib.h" 3 4
extern int mkostemps (char *__template, int __suffixlen, int __flags) __asm__ ("" "mkostemps64")

     __attribute__ ((__nonnull__ (1))) ;





extern int mkostemps64 (char *__template, int __suffixlen, int __flags)
     __attribute__ ((__nonnull__ (1))) ;









extern int system (__const char *__command) ;






extern char *canonicalize_file_name (__const char *__name)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 729 "/usr/include/stdlib.h" 3 4
extern char *realpath (__const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__)) ;






typedef int (*__compar_fn_t) (__const void *, __const void *);


typedef __compar_fn_t comparison_fn_t;



typedef int (*__compar_d_fn_t) (__const void *, __const void *, void *);





extern void *bsearch (__const void *__key, __const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;



extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));

extern void qsort_r (void *__base, size_t __nmemb, size_t __size,
       __compar_d_fn_t __compar, void *__arg)
  __attribute__ ((__nonnull__ (1, 4)));




extern int abs (int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;



__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;







extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;




__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

# 802 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));







extern int mblen (__const char *__s, size_t __n) __attribute__ ((__nothrow__)) ;


extern int mbtowc (wchar_t *__restrict __pwc,
     __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__)) ;


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__)) ;



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__));

extern size_t wcstombs (char *__restrict __s,
   __const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__));








extern int rpmatch (__const char *__response) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 890 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *__const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;





extern void setkey (__const char *__key) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));







extern int posix_openpt (int __oflag) ;







extern int grantpt (int __fd) __attribute__ ((__nothrow__));



extern int unlockpt (int __fd) __attribute__ ((__nothrow__));




extern char *ptsname (int __fd) __attribute__ ((__nothrow__)) ;






extern int ptsname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));


extern int getpt (void);






extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 958 "/usr/include/stdlib.h" 3 4

# 31 "../lib/stdlib.h" 2
# 188 "../lib/stdlib.h"
# 1 "../lib/unistd.h" 1
# 189 "../lib/stdlib.h" 2
# 38 "../lib/unistd.h" 2
# 139 "../lib/unistd.h"
# 1 "../lib/stdlib.h" 1
# 140 "../lib/unistd.h" 2
# 152 "../lib/unistd.h"
extern char * rpl_getcwd (char *buf, size_t size);
# 38 "system.h" 2
# 54 "system.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/limits.h" 1 3 4
# 55 "system.h" 2

# 1 "../lib/pathmax.h" 1
# 25 "../lib/pathmax.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/limits.h" 1 3 4
# 26 "../lib/pathmax.h" 2
# 57 "system.h" 2

# 1 "../lib/configmake.h" 1
# 59 "system.h" 2


# 1 "/usr/include/sys/time.h" 1 3 4
# 27 "/usr/include/sys/time.h" 3 4
# 1 "../lib/time.h" 1 3 4
# 31 "../lib/time.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 32 "../lib/time.h" 2 3 4
# 28 "/usr/include/sys/time.h" 2 3 4

# 1 "/usr/include/bits/time.h" 1 3 4
# 30 "/usr/include/sys/time.h" 2 3 4
# 39 "/usr/include/sys/time.h" 3 4

# 57 "/usr/include/sys/time.h" 3 4
struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };

typedef struct timezone *__restrict __timezone_ptr_t;
# 73 "/usr/include/sys/time.h" 3 4
extern int gettimeofday (struct timeval *__restrict __tv,
    __timezone_ptr_t __tz) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));




extern int settimeofday (__const struct timeval *__tv,
    __const struct timezone *__tz)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int adjtime (__const struct timeval *__delta,
      struct timeval *__olddelta) __attribute__ ((__nothrow__));




enum __itimer_which
  {

    ITIMER_REAL = 0,


    ITIMER_VIRTUAL = 1,



    ITIMER_PROF = 2

  };



struct itimerval
  {

    struct timeval it_interval;

    struct timeval it_value;
  };




typedef enum __itimer_which __itimer_which_t;






extern int getitimer (__itimer_which_t __which,
        struct itimerval *__value) __attribute__ ((__nothrow__));




extern int setitimer (__itimer_which_t __which,
        __const struct itimerval *__restrict __new,
        struct itimerval *__restrict __old) __attribute__ ((__nothrow__));




extern int utimes (__const char *__file, __const struct timeval __tvp[2])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int lutimes (__const char *__file, __const struct timeval __tvp[2])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int futimes (int __fd, __const struct timeval __tvp[2]) __attribute__ ((__nothrow__));






extern int futimesat (int __fd, __const char *__file,
        __const struct timeval __tvp[2]) __attribute__ ((__nothrow__));
# 191 "/usr/include/sys/time.h" 3 4

# 62 "system.h" 2
# 1 "../lib/time.h" 1
# 37 "../lib/time.h"
# 1 "/usr/include/time.h" 1 3 4
# 30 "/usr/include/time.h" 3 4








# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 39 "/usr/include/time.h" 2 3 4



# 1 "/usr/include/bits/time.h" 1 3 4
# 43 "/usr/include/time.h" 2 3 4
# 131 "/usr/include/time.h" 3 4


struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  __const char *tm_zone;




};








struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };


struct sigevent;
# 180 "/usr/include/time.h" 3 4



extern clock_t clock (void) __attribute__ ((__nothrow__));


extern time_t time (time_t *__timer) __attribute__ ((__nothrow__));


extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__));





extern size_t strftime (char *__restrict __s, size_t __maxsize,
   __const char *__restrict __format,
   __const struct tm *__restrict __tp) __attribute__ ((__nothrow__));





extern char *strptime (__const char *__restrict __s,
         __const char *__restrict __fmt, struct tm *__tp)
     __attribute__ ((__nothrow__));







extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     __const char *__restrict __format,
     __const struct tm *__restrict __tp,
     __locale_t __loc) __attribute__ ((__nothrow__));



extern char *strptime_l (__const char *__restrict __s,
    __const char *__restrict __fmt, struct tm *__tp,
    __locale_t __loc) __attribute__ ((__nothrow__));






extern struct tm *gmtime (__const time_t *__timer) __attribute__ ((__nothrow__));



extern struct tm *localtime (__const time_t *__timer) __attribute__ ((__nothrow__));





extern struct tm *gmtime_r (__const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__));



extern struct tm *localtime_r (__const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__));





extern char *asctime (__const struct tm *__tp) __attribute__ ((__nothrow__));


extern char *ctime (__const time_t *__timer) __attribute__ ((__nothrow__));







extern char *asctime_r (__const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__));


extern char *ctime_r (__const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__));




extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;




extern char *tzname[2];



extern void tzset (void) __attribute__ ((__nothrow__));



extern int daylight;
extern long int timezone;





extern int stime (__const time_t *__when) __attribute__ ((__nothrow__));
# 313 "/usr/include/time.h" 3 4
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__));


extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__));


extern int dysize (int __year) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
# 328 "/usr/include/time.h" 3 4
extern int nanosleep (__const struct timespec *__requested_time,
        struct timespec *__remaining);



extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__));


extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__));


extern int clock_settime (clockid_t __clock_id, __const struct timespec *__tp)
     __attribute__ ((__nothrow__));






extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       __const struct timespec *__req,
       struct timespec *__rem);


extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__));




extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__));


extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__));


extern int timer_settime (timer_t __timerid, int __flags,
     __const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__));


extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__));


extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__));
# 390 "/usr/include/time.h" 3 4
extern int getdate_err;
# 399 "/usr/include/time.h" 3 4
extern struct tm *getdate (__const char *__string);
# 413 "/usr/include/time.h" 3 4
extern int getdate_r (__const char *__restrict __string,
        struct tm *__restrict __resbufp);



# 38 "../lib/time.h" 2
# 63 "system.h" 2
# 98 "system.h"
# 1 "../lib/string.h" 1
# 25 "../lib/string.h"
# 1 "/usr/include/string.h" 1 3 4
# 28 "/usr/include/string.h" 3 4





# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4









extern void *memcpy (void *__restrict __dest,
       __const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, __const void *__src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));






extern void *memccpy (void *__restrict __dest, __const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 94 "/usr/include/string.h" 3 4
extern void *memchr (__const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 108 "/usr/include/string.h" 3 4
extern void *rawmemchr (__const void *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 119 "/usr/include/string.h" 3 4
extern void *memrchr (__const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






extern char *strcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, __const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

# 164 "/usr/include/string.h" 3 4
extern int strcoll_l (__const char *__s1, __const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

extern size_t strxfrm_l (char *__dest, __const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));




extern char *strdup (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (__const char *__string, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 208 "/usr/include/string.h" 3 4

# 233 "/usr/include/string.h" 3 4
extern char *strchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 260 "/usr/include/string.h" 3 4
extern char *strrchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 274 "/usr/include/string.h" 3 4
extern char *strchrnul (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






extern size_t strcspn (__const char *__s, __const char *__reject)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 312 "/usr/include/string.h" 3 4
extern char *strpbrk (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 340 "/usr/include/string.h" 3 4
extern char *strstr (__const char *__haystack, __const char *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));




extern char *__strtok_r (char *__restrict __s,
    __const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
# 371 "/usr/include/string.h" 3 4
extern char *strcasestr (__const char *__haystack, __const char *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));







extern void *memmem (__const void *__haystack, size_t __haystacklen,
       __const void *__needle, size_t __needlelen)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)));



extern void *__mempcpy (void *__restrict __dest,
   __const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *mempcpy (void *__restrict __dest,
        __const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));





extern size_t strlen (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strnlen (__const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern char *strerror (int __errnum) __attribute__ ((__nothrow__));

# 436 "/usr/include/string.h" 3 4
extern char *strerror_r (int __errnum, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));





extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__));





extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern void bcopy (__const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 487 "/usr/include/string.h" 3 4
extern char *index (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 515 "/usr/include/string.h" 3 4
extern char *rindex (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern int ffs (int __i) __attribute__ ((__nothrow__)) __attribute__ ((__const__));




extern int ffsl (long int __l) __attribute__ ((__nothrow__)) __attribute__ ((__const__));

__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__));




extern int strcasecmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));





extern int strcasecmp_l (__const char *__s1, __const char *__s2,
    __locale_t __loc)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

extern int strncasecmp_l (__const char *__s1, __const char *__s2,
     size_t __n, __locale_t __loc)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));





extern char *strsep (char **__restrict __stringp,
       __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__));


extern char *__stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));




extern int strverscmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strfry (char *__string) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern void *memfrob (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 604 "/usr/include/string.h" 3 4
extern char *basename (__const char *__filename) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 644 "/usr/include/string.h" 3 4

# 26 "../lib/string.h" 2
# 461 "../lib/string.h"
extern int mbscasecmp (const char *s1, const char *s2);
# 99 "system.h" 2

# 1 "/usr/include/errno.h" 1 3 4
# 101 "system.h" 2
# 116 "system.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stdbool.h" 1 3 4
# 117 "system.h" 2
# 1 "../lib/stdlib.h" 1
# 118 "system.h" 2


enum
{
  EXIT_CANNOT_INVOKE = 126,
  EXIT_ENOENT = 127
};

# 1 "../lib/exitfail.h" 1
# 18 "../lib/exitfail.h"
extern int volatile exit_failure;
# 127 "system.h" 2


static inline void
initialize_exit_failure (int status)
{
  if (status != 1)
    exit_failure = status;
}

# 1 "../lib/fcntl.h" 1
# 27 "../lib/fcntl.h"
# 1 "/usr/include/fcntl.h" 1 3 4
# 30 "/usr/include/fcntl.h" 3 4




# 1 "/usr/include/bits/fcntl.h" 1 3 4
# 25 "/usr/include/bits/fcntl.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 26 "/usr/include/bits/fcntl.h" 2 3 4

# 1 "/usr/include/bits/uio.h" 1 3 4
# 44 "/usr/include/bits/uio.h" 3 4
struct iovec
  {
    void *iov_base;
    size_t iov_len;
  };
# 28 "/usr/include/bits/fcntl.h" 2 3 4
# 160 "/usr/include/bits/fcntl.h" 3 4
struct flock
  {
    short int l_type;
    short int l_whence;




    __off64_t l_start;
    __off64_t l_len;

    __pid_t l_pid;
  };


struct flock64
  {
    short int l_type;
    short int l_whence;
    __off64_t l_start;
    __off64_t l_len;
    __pid_t l_pid;
  };




enum __pid_type
  {
    F_OWNER_TID = 0,
    F_OWNER_PID,
    F_OWNER_GID
  };


struct f_owner_ex
  {
    enum __pid_type type;
    __pid_t pid;
  };
# 257 "/usr/include/bits/fcntl.h" 3 4





extern ssize_t readahead (int __fd, __off64_t __offset, size_t __count)
    __attribute__ ((__nothrow__));



extern int sync_file_range (int __fd, __off64_t __from, __off64_t __to,
       unsigned int __flags);



extern ssize_t vmsplice (int __fdout, const struct iovec *__iov,
    size_t __count, unsigned int __flags);


extern ssize_t splice (int __fdin, __off64_t *__offin, int __fdout,
         __off64_t *__offout, size_t __len,
         unsigned int __flags);


extern ssize_t tee (int __fdin, int __fdout, size_t __len,
      unsigned int __flags);






extern int fallocate (int __fd, int __mode, __off64_t __offset, __off64_t __len) __asm__ ("" "fallocate64");







extern int fallocate64 (int __fd, int __mode, __off64_t __offset,
   __off64_t __len);




# 35 "/usr/include/fcntl.h" 2 3 4
# 64 "/usr/include/fcntl.h" 3 4
extern int fcntl (int __fd, int __cmd, ...);
# 76 "/usr/include/fcntl.h" 3 4
extern int open (__const char *__file, int __oflag, ...) __asm__ ("" "open64")
     __attribute__ ((__nonnull__ (1)));





extern int open64 (__const char *__file, int __oflag, ...) __attribute__ ((__nonnull__ (1)));
# 101 "/usr/include/fcntl.h" 3 4
extern int openat (int __fd, __const char *__file, int __oflag, ...) __asm__ ("" "openat64") __attribute__ ((__nonnull__ (2)));






extern int openat64 (int __fd, __const char *__file, int __oflag, ...)
     __attribute__ ((__nonnull__ (2)));
# 121 "/usr/include/fcntl.h" 3 4
extern int creat (__const char *__file, __mode_t __mode) __asm__ ("" "creat64") __attribute__ ((__nonnull__ (1)));






extern int creat64 (__const char *__file, __mode_t __mode) __attribute__ ((__nonnull__ (1)));
# 168 "/usr/include/fcntl.h" 3 4
extern int posix_fadvise (int __fd, __off64_t __offset, __off64_t __len, int __advise) __asm__ ("" "posix_fadvise64") __attribute__ ((__nothrow__));







extern int posix_fadvise64 (int __fd, __off64_t __offset, __off64_t __len,
       int __advise) __attribute__ ((__nothrow__));
# 189 "/usr/include/fcntl.h" 3 4
extern int posix_fallocate (int __fd, __off64_t __offset, __off64_t __len) __asm__ ("" "posix_fallocate64");







extern int posix_fallocate64 (int __fd, __off64_t __offset, __off64_t __len);
# 208 "/usr/include/fcntl.h" 3 4

# 28 "../lib/fcntl.h" 2
# 137 "system.h" 2
# 145 "system.h"
# 1 "/usr/include/dirent.h" 1 3 4
# 28 "/usr/include/dirent.h" 3 4

# 62 "/usr/include/dirent.h" 3 4
# 1 "/usr/include/bits/dirent.h" 1 3 4
# 23 "/usr/include/bits/dirent.h" 3 4
struct dirent
  {




    __ino64_t d_ino;
    __off64_t d_off;

    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];
  };


struct dirent64
  {
    __ino64_t d_ino;
    __off64_t d_off;
    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];
  };
# 63 "/usr/include/dirent.h" 2 3 4
# 98 "/usr/include/dirent.h" 3 4
enum
  {
    DT_UNKNOWN = 0,

    DT_FIFO = 1,

    DT_CHR = 2,

    DT_DIR = 4,

    DT_BLK = 6,

    DT_REG = 8,

    DT_LNK = 10,

    DT_SOCK = 12,

    DT_WHT = 14

  };
# 128 "/usr/include/dirent.h" 3 4
typedef struct __dirstream DIR;






extern DIR *opendir (__const char *__name) __attribute__ ((__nonnull__ (1)));






extern DIR *fdopendir (int __fd);







extern int closedir (DIR *__dirp) __attribute__ ((__nonnull__ (1)));
# 166 "/usr/include/dirent.h" 3 4
extern struct dirent *readdir (DIR *__dirp) __asm__ ("" "readdir64")
     __attribute__ ((__nonnull__ (1)));






extern struct dirent64 *readdir64 (DIR *__dirp) __attribute__ ((__nonnull__ (1)));
# 190 "/usr/include/dirent.h" 3 4
extern int readdir_r (DIR *__restrict __dirp, struct dirent *__restrict __entry, struct dirent **__restrict __result) __asm__ ("" "readdir64_r") __attribute__ ((__nonnull__ (1, 2, 3)));
# 201 "/usr/include/dirent.h" 3 4
extern int readdir64_r (DIR *__restrict __dirp,
   struct dirent64 *__restrict __entry,
   struct dirent64 **__restrict __result)
     __attribute__ ((__nonnull__ (1, 2, 3)));




extern void rewinddir (DIR *__dirp) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern void seekdir (DIR *__dirp, long int __pos) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern long int telldir (DIR *__dirp) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int dirfd (DIR *__dirp) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 245 "/usr/include/dirent.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 246 "/usr/include/dirent.h" 2 3 4
# 260 "/usr/include/dirent.h" 3 4
extern int scandir (__const char *__restrict __dir, struct dirent ***__restrict __namelist, int (*__selector) (__const struct dirent *), int (*__cmp) (__const struct dirent **, __const struct dirent **)) __asm__ ("" "scandir64") __attribute__ ((__nonnull__ (1, 2)));
# 275 "/usr/include/dirent.h" 3 4
extern int scandir64 (__const char *__restrict __dir,
        struct dirent64 ***__restrict __namelist,
        int (*__selector) (__const struct dirent64 *),
        int (*__cmp) (__const struct dirent64 **,
        __const struct dirent64 **))
     __attribute__ ((__nonnull__ (1, 2)));
# 290 "/usr/include/dirent.h" 3 4
extern int alphasort (__const struct dirent **__e1, __const struct dirent **__e2) __asm__ ("" "alphasort64") __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 300 "/usr/include/dirent.h" 3 4
extern int alphasort64 (__const struct dirent64 **__e1,
   __const struct dirent64 **__e2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 319 "/usr/include/dirent.h" 3 4
extern __ssize_t getdirentries (int __fd, char *__restrict __buf, size_t __nbytes, __off64_t *__restrict __basep) __asm__ ("" "getdirentries64") __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));
# 330 "/usr/include/dirent.h" 3 4
extern __ssize_t getdirentries64 (int __fd, char *__restrict __buf,
      size_t __nbytes,
      __off64_t *__restrict __basep)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));
# 345 "/usr/include/dirent.h" 3 4
extern int versionsort (__const struct dirent **__e1, __const struct dirent **__e2) __asm__ ("" "versionsort64") __attribute__ ((__nothrow__))



     __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));






extern int versionsort64 (__const struct dirent64 **__e1,
     __const struct dirent64 **__e2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




# 146 "system.h" 2




enum
{
  NOT_AN_INODE_NUMBER = 0
};
# 239 "system.h"
# 1 "../lib/stat-macros.h" 1
# 240 "system.h" 2

# 1 "../lib/timespec.h" 1
# 21 "../lib/timespec.h"
# 1 "../lib/time.h" 1
# 22 "../lib/timespec.h" 2



static inline int
timespec_cmp (struct timespec a, struct timespec b)
{
  return (a.tv_sec < b.tv_sec ? -1
   : a.tv_sec > b.tv_sec ? 1
   : a.tv_nsec - b.tv_nsec);
}

void gettime (struct timespec *);
int settime (struct timespec const *);
# 242 "system.h" 2

# 1 "../lib/inttypes.h" 1
# 30 "../lib/inttypes.h"
# 1 "/usr/include/inttypes.h" 1 3 4
# 28 "/usr/include/inttypes.h" 3 4
# 1 "/usr/include/stdint.h" 1 3 4
# 28 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/stdint.h" 2 3 4
# 49 "/usr/include/stdint.h" 3 4
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;





__extension__
typedef unsigned long long int uint64_t;






typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;



__extension__
typedef long long int int_least64_t;



typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;



__extension__
typedef unsigned long long int uint_least64_t;






typedef signed char int_fast8_t;





typedef int int_fast16_t;
typedef int int_fast32_t;
__extension__
typedef long long int int_fast64_t;



typedef unsigned char uint_fast8_t;





typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
__extension__
typedef unsigned long long int uint_fast64_t;
# 129 "/usr/include/stdint.h" 3 4
typedef unsigned int uintptr_t;
# 138 "/usr/include/stdint.h" 3 4
__extension__
typedef long long int intmax_t;
__extension__
typedef unsigned long long int uintmax_t;
# 29 "/usr/include/inttypes.h" 2 3 4






typedef int __gwchar_t;
# 274 "/usr/include/inttypes.h" 3 4

# 288 "/usr/include/inttypes.h" 3 4
typedef struct
  {
    long long int quot;
    long long int rem;
  } imaxdiv_t;





extern intmax_t imaxabs (intmax_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern intmax_t strtoimax (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base) __attribute__ ((__nothrow__));


extern uintmax_t strtoumax (__const char *__restrict __nptr,
       char ** __restrict __endptr, int __base) __attribute__ ((__nothrow__));


extern intmax_t wcstoimax (__const __gwchar_t *__restrict __nptr,
      __gwchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__));


extern uintmax_t wcstoumax (__const __gwchar_t *__restrict __nptr,
       __gwchar_t ** __restrict __endptr, int __base)
     __attribute__ ((__nothrow__));
# 442 "/usr/include/inttypes.h" 3 4

# 31 "../lib/inttypes.h" 2
# 40 "../lib/inttypes.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/limits.h" 1 3 4
# 41 "../lib/inttypes.h" 2
# 244 "system.h" 2

# 1 "/usr/include/ctype.h" 1 3 4
# 30 "/usr/include/ctype.h" 3 4

# 48 "/usr/include/ctype.h" 3 4
enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 81 "/usr/include/ctype.h" 3 4
extern __const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__nothrow__)) __attribute__ ((__const));
extern __const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__nothrow__)) __attribute__ ((__const));
extern __const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__nothrow__)) __attribute__ ((__const));
# 96 "/usr/include/ctype.h" 3 4






extern int isalnum (int) __attribute__ ((__nothrow__));
extern int isalpha (int) __attribute__ ((__nothrow__));
extern int iscntrl (int) __attribute__ ((__nothrow__));
extern int isdigit (int) __attribute__ ((__nothrow__));
extern int islower (int) __attribute__ ((__nothrow__));
extern int isgraph (int) __attribute__ ((__nothrow__));
extern int isprint (int) __attribute__ ((__nothrow__));
extern int ispunct (int) __attribute__ ((__nothrow__));
extern int isspace (int) __attribute__ ((__nothrow__));
extern int isupper (int) __attribute__ ((__nothrow__));
extern int isxdigit (int) __attribute__ ((__nothrow__));



extern int tolower (int __c) __attribute__ ((__nothrow__));


extern int toupper (int __c) __attribute__ ((__nothrow__));








extern int isblank (int) __attribute__ ((__nothrow__));






extern int isctype (int __c, int __mask) __attribute__ ((__nothrow__));






extern int isascii (int __c) __attribute__ ((__nothrow__));



extern int toascii (int __c) __attribute__ ((__nothrow__));



extern int _toupper (int) __attribute__ ((__nothrow__));
extern int _tolower (int) __attribute__ ((__nothrow__));
# 247 "/usr/include/ctype.h" 3 4
extern int isalnum_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isalpha_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int iscntrl_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isdigit_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int islower_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isgraph_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isprint_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int ispunct_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isspace_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isupper_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isxdigit_l (int, __locale_t) __attribute__ ((__nothrow__));

extern int isblank_l (int, __locale_t) __attribute__ ((__nothrow__));



extern int __tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
extern int tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));


extern int __toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
extern int toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
# 323 "/usr/include/ctype.h" 3 4

# 246 "system.h" 2
# 263 "system.h"
static inline unsigned char to_uchar (char ch) { return ch; }

# 1 "/usr/include/locale.h" 1 3 4
# 29 "/usr/include/locale.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 30 "/usr/include/locale.h" 2 3 4
# 1 "/usr/include/bits/locale.h" 1 3 4
# 27 "/usr/include/bits/locale.h" 3 4
enum
{
  __LC_CTYPE = 0,
  __LC_NUMERIC = 1,
  __LC_TIME = 2,
  __LC_COLLATE = 3,
  __LC_MONETARY = 4,
  __LC_MESSAGES = 5,
  __LC_ALL = 6,
  __LC_PAPER = 7,
  __LC_NAME = 8,
  __LC_ADDRESS = 9,
  __LC_TELEPHONE = 10,
  __LC_MEASUREMENT = 11,
  __LC_IDENTIFICATION = 12
};
# 31 "/usr/include/locale.h" 2 3 4


# 51 "/usr/include/locale.h" 3 4



struct lconv
{


  char *decimal_point;
  char *thousands_sep;





  char *grouping;





  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;

  char p_cs_precedes;

  char p_sep_by_space;

  char n_cs_precedes;

  char n_sep_by_space;






  char p_sign_posn;
  char n_sign_posn;


  char int_p_cs_precedes;

  char int_p_sep_by_space;

  char int_n_cs_precedes;

  char int_n_sep_by_space;






  char int_p_sign_posn;
  char int_n_sign_posn;
# 121 "/usr/include/locale.h" 3 4
};



extern char *setlocale (int __category, __const char *__locale) __attribute__ ((__nothrow__));


extern struct lconv *localeconv (void) __attribute__ ((__nothrow__));


# 152 "/usr/include/locale.h" 3 4
extern __locale_t newlocale (int __category_mask, __const char *__locale,
        __locale_t __base) __attribute__ ((__nothrow__));
# 187 "/usr/include/locale.h" 3 4
extern __locale_t duplocale (__locale_t __dataset) __attribute__ ((__nothrow__));



extern void freelocale (__locale_t __dataset) __attribute__ ((__nothrow__));






extern __locale_t uselocale (__locale_t __dataset) __attribute__ ((__nothrow__));








# 266 "system.h" 2



# 1 "../lib/gettext.h" 1
# 27 "../lib/gettext.h"
# 1 "/usr/include/libintl.h" 1 3 4
# 35 "/usr/include/libintl.h" 3 4





extern char *gettext (__const char *__msgid)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (1)));



extern char *dgettext (__const char *__domainname, __const char *__msgid)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (2)));
extern char *__dgettext (__const char *__domainname, __const char *__msgid)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (2)));



extern char *dcgettext (__const char *__domainname,
   __const char *__msgid, int __category)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (2)));
extern char *__dcgettext (__const char *__domainname,
     __const char *__msgid, int __category)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (2)));




extern char *ngettext (__const char *__msgid1, __const char *__msgid2,
         unsigned long int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (1))) __attribute__ ((__format_arg__ (2)));



extern char *dngettext (__const char *__domainname, __const char *__msgid1,
   __const char *__msgid2, unsigned long int __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (2))) __attribute__ ((__format_arg__ (3)));



extern char *dcngettext (__const char *__domainname, __const char *__msgid1,
    __const char *__msgid2, unsigned long int __n,
    int __category)
     __attribute__ ((__nothrow__)) __attribute__ ((__format_arg__ (2))) __attribute__ ((__format_arg__ (3)));





extern char *textdomain (__const char *__domainname) __attribute__ ((__nothrow__));



extern char *bindtextdomain (__const char *__domainname,
        __const char *__dirname) __attribute__ ((__nothrow__));



extern char *bind_textdomain_codeset (__const char *__domainname,
          __const char *__codeset) __attribute__ ((__nothrow__));
# 122 "/usr/include/libintl.h" 3 4

# 28 "../lib/gettext.h" 2
# 128 "../lib/gettext.h"
__inline





static const char *
pgettext_aux (const char *domain,
       const char *msg_ctxt_id, const char *msgid,
       int category)
{
  const char *translation = dcgettext (domain, msg_ctxt_id, category);
  if (translation == msg_ctxt_id)
    return msgid;
  else
    return translation;
}


__inline





static const char *
npgettext_aux (const char *domain,
        const char *msg_ctxt_id, const char *msgid,
        const char *msgid_plural, unsigned long int n,
        int category)
{
  const char *translation =
    dcngettext (domain, msg_ctxt_id, msgid_plural, n, category);
  if (translation == msg_ctxt_id || translation == msgid_plural)
    return (n == 1 ? msgid : msgid_plural);
  else
    return translation;
}
# 187 "../lib/gettext.h"
__inline





static const char *
dcpgettext_expr (const char *domain,
   const char *msgctxt, const char *msgid,
   int category)
{
  size_t msgctxt_len = strlen (msgctxt) + 1;
  size_t msgid_len = strlen (msgid) + 1;
  const char *translation;

  char msg_ctxt_id[msgctxt_len + msgid_len];
# 211 "../lib/gettext.h"
    {
      memcpy (msg_ctxt_id, msgctxt, msgctxt_len - 1);
      msg_ctxt_id[msgctxt_len - 1] = '\004';
      memcpy (msg_ctxt_id + msgctxt_len, msgid, msgid_len);
      translation = dcgettext (domain, msg_ctxt_id, category);




      if (translation != msg_ctxt_id)
 return translation;
    }
  return msgid;
}







__inline





static const char *
dcnpgettext_expr (const char *domain,
    const char *msgctxt, const char *msgid,
    const char *msgid_plural, unsigned long int n,
    int category)
{
  size_t msgctxt_len = strlen (msgctxt) + 1;
  size_t msgid_len = strlen (msgid) + 1;
  const char *translation;

  char msg_ctxt_id[msgctxt_len + msgid_len];
# 257 "../lib/gettext.h"
    {
      memcpy (msg_ctxt_id, msgctxt, msgctxt_len - 1);
      msg_ctxt_id[msgctxt_len - 1] = '\004';
      memcpy (msg_ctxt_id + msgctxt_len, msgid, msgid_len);
      translation = dcngettext (domain, msg_ctxt_id, msgid_plural, n, category);




      if (!(translation == msg_ctxt_id || translation == msgid_plural))
 return translation;
    }
  return (n == 1 ? msgid : msgid_plural);
}
# 270 "system.h" 2
# 282 "system.h"
static inline unsigned long int
select_plural (uintmax_t n)
{


  enum { PLURAL_REDUCER = 1000000 };
  return (n <= (2147483647L * 2UL + 1UL) ? n : n % PLURAL_REDUCER + PLURAL_REDUCER);
}
# 341 "system.h"
# 1 "../lib/xalloc.h" 1
# 22 "../lib/xalloc.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 23 "../lib/xalloc.h" 2
# 45 "../lib/xalloc.h"
extern void xalloc_die (void) __attribute__ ((__noreturn__));

void *xmalloc (size_t s);
void *xzalloc (size_t s);
void *xcalloc (size_t n, size_t s);
void *xrealloc (void *p, size_t s);
void *x2realloc (void *p, size_t *pn);
void *xmemdup (void const *p, size_t s);
char *xstrdup (char const *str);
# 100 "../lib/xalloc.h"
   void *xnmalloc (size_t n, size_t s);
   void *xnrealloc (void *p, size_t n, size_t s);
   void *x2nrealloc (void *p, size_t *pn, size_t s);
   char *xcharalloc (size_t n);
# 342 "system.h" 2
# 1 "../lib/verify.h" 1
# 343 "system.h" 2
# 358 "system.h"
# 1 "../lib/unlocked-io.h" 1
# 34 "../lib/unlocked-io.h"
# 1 "../lib/stdio.h" 1
# 35 "../lib/unlocked-io.h" 2
# 359 "system.h" 2
# 1 "../lib/same-inode.h" 1
# 360 "system.h" 2

# 1 "../lib/dirname.h" 1
# 22 "../lib/dirname.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 23 "../lib/dirname.h" 2
# 61 "../lib/dirname.h"
char *base_name (char const *file);
char *dir_name (char const *file);
size_t base_len (char const *file);
size_t dir_len (char const *file);
char *last_component (char const *file);

_Bool strip_trailing_slashes (char *file);
# 362 "system.h" 2

static inline _Bool
dot_or_dotdot (char const *file_name)
{
  if (file_name[0] == '.')
    {
      char sep = file_name[(file_name[1] == '.') + 1];
      return (! sep || ((sep) == '/'));
    }
  else
    return 0;
}


static inline struct dirent const *
readdir_ignoring_dot_and_dotdot (DIR *dirp)
{
  while (1)
    {
      struct dirent const *dp = readdir (dirp);
      if (dp == ((void *)0) || ! dot_or_dotdot (dp->d_name))
 return dp;
    }
}






enum
{
  GETOPT_HELP_CHAR = ((-127 - 1) - 2),
  GETOPT_VERSION_CHAR = ((-127 - 1) - 3)
};
# 423 "system.h"
# 1 "../lib/closein.h" 1
# 25 "../lib/closein.h"
void close_stdin_set_file_name (const char *file);
void close_stdin (void);
# 424 "system.h" 2
# 1 "../lib/closeout.h" 1
# 25 "../lib/closeout.h"
void close_stdout_set_file_name (const char *file);
void close_stdout (void);
# 425 "system.h" 2
# 1 "../lib/version-etc.h" 1
# 23 "../lib/version-etc.h"
# 1 "../lib/stdio.h" 1
# 24 "../lib/version-etc.h" 2

extern const char version_etc_copyright[];

extern void version_etc_va (FILE *stream,
       const char *command_name, const char *package,
       const char *version, va_list authors);

extern void version_etc (FILE *stream,
    const char *command_name, const char *package,
    const char *version,
                                         ...);
# 426 "system.h" 2
# 442 "system.h"
# 1 "../lib/intprops.h" 1
# 20 "../lib/intprops.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/limits.h" 1 3 4
# 21 "../lib/intprops.h" 2
# 443 "system.h" 2
# 515 "system.h"
static inline size_t
gcd (size_t u, size_t v)
{
  do
    {
      size_t t = u % v;
      u = v;
      v = t;
    }
  while (v);

  return u;
}





static inline size_t
lcm (size_t u, size_t v)
{
  return u * (v / gcd (u, v));
}






static inline void *
ptr_align (void const *ptr, size_t alignment)
{
  char const *p0 = ptr;
  char const *p1 = p0 + alignment - 1;
  return (void *) (p1 - (size_t) p1 % alignment);
}
# 573 "system.h"
static inline void
emit_bug_reporting_address (void)
{




  printf (gettext ("\nReport bugs to <%s>.\n"), "bug-coreutils@gnu.org");
}
# 81 "ls.c" 2
# 1 "/usr/include/fnmatch.h" 1 3 4
# 65 "/usr/include/fnmatch.h" 3 4
extern int fnmatch (const char *__pattern, const char *__name,
      int __flags);
# 82 "ls.c" 2

# 1 "../lib/acl.h" 1
# 31 "../lib/acl.h"
int file_has_acl (char const *, struct stat const *);
int copy_acl (char const *, int, char const *, int, mode_t);
int set_acl (char const *, int, mode_t);
int qset_acl (char const *, int, mode_t);
int chmod_or_fchmod (char const *, int, mode_t);
# 84 "ls.c" 2
# 1 "../lib/argmatch.h" 1
# 25 "../lib/argmatch.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 26 "../lib/argmatch.h" 2

# 1 "../lib/verify.h" 1
# 28 "../lib/argmatch.h" 2
# 42 "../lib/argmatch.h"
ptrdiff_t argmatch (char const *arg, char const *const *arglist,
      char const *vallist, size_t valsize);







typedef void (*argmatch_exit_fn) (void);
extern argmatch_exit_fn argmatch_die;



void argmatch_invalid (char const *context, char const *value,
         ptrdiff_t problem);
# 68 "../lib/argmatch.h"
void argmatch_valid (char const *const *arglist,
       char const *vallist, size_t valsize);
# 79 "../lib/argmatch.h"
ptrdiff_t __xargmatch_internal (char const *context,
    char const *arg, char const *const *arglist,
    char const *vallist, size_t valsize,
    argmatch_exit_fn exit_fn);
# 94 "../lib/argmatch.h"
char const *argmatch_to_argument (char const *value,
      char const *const *arglist,
      char const *vallist, size_t valsize);
# 85 "ls.c" 2
# 1 "../lib/dev-ino.h" 1






struct dev_ino
{
  ino_t st_ino;
  dev_t st_dev;
};
# 86 "ls.c" 2
# 1 "../lib/dirfd.h" 1
# 87 "ls.c" 2
# 1 "../lib/error.h" 1
# 42 "../lib/error.h"
extern void error (int __status, int __errnum, const char *__format, ...)
     __attribute__ ((__format__ (__printf__, 3, 4)));

extern void error_at_line (int __status, int __errnum, const char *__fname,
      unsigned int __lineno, const char *__format, ...)
     __attribute__ ((__format__ (__printf__, 5, 6)));




extern void (*error_print_progname) (void);


extern unsigned int error_message_count;



extern int error_one_per_line;
# 88 "ls.c" 2
# 1 "../lib/filenamecat.h" 1
# 20 "../lib/filenamecat.h"
char *file_name_concat (char const *dir, char const *base,
   char **base_in_result);

char *mfile_name_concat (char const *dir, char const *base,
    char **base_in_result);
# 89 "ls.c" 2
# 1 "../lib/hard-locale.h" 1
# 23 "../lib/hard-locale.h"
_Bool hard_locale (int);
# 90 "ls.c" 2
# 1 "../lib/hash.h" 1
# 26 "../lib/hash.h"
# 1 "../lib/stdio.h" 1
# 27 "../lib/hash.h" 2


typedef size_t (*Hash_hasher) (const void *, size_t);
typedef _Bool (*Hash_comparator) (const void *, const void *);
typedef void (*Hash_data_freer) (void *);
typedef _Bool (*Hash_processor) (void *, void *);

struct hash_entry
  {
    void *data;
    struct hash_entry *next;
  };

struct hash_tuning
  {



    float shrink_threshold;
    float shrink_factor;
    float growth_threshold;
    float growth_factor;
    _Bool is_n_buckets;
  };

typedef struct hash_tuning Hash_tuning;

struct hash_table;

typedef struct hash_table Hash_table;


size_t hash_get_n_buckets (const Hash_table *);
size_t hash_get_n_buckets_used (const Hash_table *);
size_t hash_get_n_entries (const Hash_table *);
size_t hash_get_max_bucket_length (const Hash_table *);
_Bool hash_table_ok (const Hash_table *);
void hash_print_statistics (const Hash_table *, FILE *);
void *hash_lookup (const Hash_table *, const void *);


void *hash_get_first (const Hash_table *);
void *hash_get_next (const Hash_table *, const void *);
size_t hash_get_entries (const Hash_table *, void **, size_t);
size_t hash_do_for_each (const Hash_table *, Hash_processor, void *);


size_t hash_string (const char *, size_t);
void hash_reset_tuning (Hash_tuning *);
Hash_table *hash_initialize (size_t, const Hash_tuning *,
        Hash_hasher, Hash_comparator,
        Hash_data_freer);
void hash_clear (Hash_table *);
void hash_free (Hash_table *);


_Bool hash_rehash (Hash_table *, size_t);
void *hash_insert (Hash_table *, const void *);
void *hash_delete (Hash_table *, const void *);
# 91 "ls.c" 2
# 1 "../lib/human.h" 1
# 24 "../lib/human.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/limits.h" 1 3 4
# 25 "../lib/human.h" 2




# 1 "../lib/xstrtol.h" 1
# 23 "../lib/xstrtol.h"
# 1 "../lib/inttypes.h" 1
# 24 "../lib/xstrtol.h" 2


enum strtol_error
  {
    LONGINT_OK = 0,



    LONGINT_OVERFLOW = 1,
    LONGINT_INVALID_SUFFIX_CHAR = 2,

    LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = (LONGINT_INVALID_SUFFIX_CHAR
       | LONGINT_OVERFLOW),
    LONGINT_INVALID = 4
  };
typedef enum strtol_error strtol_error;




strtol_error xstrtol (const char *, char **, int, long int *, const char *);
strtol_error xstrtoul (const char *, char **, int, unsigned long int *, const char *);
strtol_error xstrtoimax (const char *, char **, int, intmax_t *, const char *);
strtol_error xstrtoumax (const char *, char **, int, uintmax_t *, const char *);
# 74 "../lib/xstrtol.h"
void xstrtol_fatal (enum strtol_error,
      int, char, struct option const *,
      char const *) __attribute__ ((__noreturn__));
# 30 "../lib/human.h" 2
# 44 "../lib/human.h"
enum
{




  human_ceiling = 0,

  human_round_to_nearest = 1,

  human_floor = 2,




  human_group_digits = 4,


  human_suppress_point_zero = 8,


  human_autoscale = 16,


  human_base_1024 = 32,


  human_space_before_unit = 64,


  human_SI = 128,


  human_B = 256
};

char *human_readable (uintmax_t, char *, int, uintmax_t, uintmax_t);

enum strtol_error human_options (char const *, int *, uintmax_t *);
# 92 "ls.c" 2
# 1 "../lib/filemode.h" 1
# 27 "../lib/filemode.h"
void strmode (mode_t mode, char *str);


void filemodestring (struct stat const *statp, char *str);
# 93 "ls.c" 2
# 1 "../lib/idcache.h" 1





extern char *getuser (uid_t uid);
extern char *getgroup (gid_t gid);
extern uid_t *getuidbyname (const char *user);
extern gid_t *getgidbyname (const char *group);
# 94 "ls.c" 2
# 1 "../lib/inttostr.h" 1
# 24 "../lib/inttostr.h"
# 1 "../lib/intprops.h" 1
# 20 "../lib/intprops.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include-fixed/limits.h" 1 3 4
# 21 "../lib/intprops.h" 2
# 25 "../lib/inttostr.h" 2

char *offtostr (off_t, char *);
char *imaxtostr (intmax_t, char *);
char *umaxtostr (uintmax_t, char *);
char *uinttostr (unsigned int, char *);
# 95 "ls.c" 2
# 1 "ls.h" 1
# 10 "ls.h"
extern int ls_mode;
# 96 "ls.c" 2
# 1 "../lib/lstat.h" 1
# 97 "ls.c" 2
# 1 "../lib/mbswidth.h" 1
# 17 "../lib/mbswidth.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 18 "../lib/mbswidth.h" 2
# 51 "../lib/mbswidth.h"
extern int gnu_mbswidth (const char *string, int flags);



extern int mbsnwidth (const char *buf, size_t nbytes, int flags);
# 98 "ls.c" 2
# 1 "../lib/mpsort.h" 1
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 2 "../lib/mpsort.h" 2
void mpsort (void const **, size_t, int (*) (void const *, void const *));
# 99 "ls.c" 2
# 1 "../lib/obstack.h" 1
# 142 "../lib/obstack.h"
struct _obstack_chunk
{
  char *limit;
  struct _obstack_chunk *prev;
  char contents[4];
};

struct obstack
{
  long chunk_size;
  struct _obstack_chunk *chunk;
  char *object_base;
  char *next_free;
  char *chunk_limit;
  union
  {
    int tempint;
    void *tempptr;
  } temp;
  int alignment_mask;



  struct _obstack_chunk *(*chunkfun) (void *, long);
  void (*freefun) (void *, struct _obstack_chunk *);
  void *extra_arg;
  unsigned use_extra_arg:1;
  unsigned maybe_empty_object:1;



  unsigned alloc_failed:1;


};



extern void _obstack_newchunk (struct obstack *, int);
extern int _obstack_begin (struct obstack *, int, int,
       void *(*) (long), void (*) (void *));
extern int _obstack_begin_1 (struct obstack *, int, int,
        void *(*) (void *, long),
        void (*) (void *, void *), void *);
extern int _obstack_memory_used (struct obstack *);






extern void obstack_free (struct obstack *obstack, void *block);






extern void (*obstack_alloc_failed_handler) (void);


extern int obstack_exit_failure;
# 100 "ls.c" 2
# 1 "../lib/quote.h" 1
# 20 "../lib/quote.h"
char const *quote_n (int n, char const *name);
char const *quote (char const *name);
# 101 "ls.c" 2
# 1 "../lib/quotearg.h" 1
# 24 "../lib/quotearg.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 25 "../lib/quotearg.h" 2


enum quoting_style
  {

    literal_quoting_style,



    shell_quoting_style,



    shell_always_quoting_style,


    c_quoting_style,



    escape_quoting_style,



    locale_quoting_style,



    clocale_quoting_style
  };







extern char const *const quoting_style_args[];
extern enum quoting_style const quoting_style_vals[];

struct quoting_options;







struct quoting_options *clone_quoting_options (struct quoting_options *o);


enum quoting_style get_quoting_style (struct quoting_options *o);



void set_quoting_style (struct quoting_options *o, enum quoting_style s);






int set_char_quoting (struct quoting_options *o, char c, int i);
# 97 "../lib/quotearg.h"
size_t quotearg_buffer (char *buffer, size_t buffersize,
   char const *arg, size_t argsize,
   struct quoting_options const *o);



char *quotearg_alloc (char const *arg, size_t argsize,
        struct quoting_options const *o);






char *quotearg_n (int n, char const *arg);


char *quotearg (char const *arg);




char *quotearg_n_style (int n, enum quoting_style s, char const *arg);




char *quotearg_n_style_mem (int n, enum quoting_style s,
       char const *arg, size_t argsize);


char *quotearg_style (enum quoting_style s, char const *arg);


char *quotearg_char (char const *arg, char ch);


char *quotearg_colon (char const *arg);


void quotearg_free (void);
# 102 "ls.c" 2
# 1 "../lib/same.h" 1
# 24 "../lib/same.h"
_Bool same_name (const char *source, const char *dest);
# 103 "ls.c" 2
# 1 "../lib/stat-time.h" 1
# 24 "../lib/stat-time.h"
# 1 "../lib/time.h" 1
# 25 "../lib/stat-time.h" 2
# 49 "../lib/stat-time.h"
static inline long int
get_stat_atime_ns (struct stat const *st)
{

  return ((st)->st_atim).tv_nsec;





}


static inline long int
get_stat_ctime_ns (struct stat const *st)
{

  return ((st)->st_ctim).tv_nsec;





}


static inline long int
get_stat_mtime_ns (struct stat const *st)
{

  return ((st)->st_mtim).tv_nsec;





}


static inline long int
get_stat_birthtime_ns (struct stat const *st)
{





  return 0;

}


static inline struct timespec
get_stat_atime (struct stat const *st)
{

  return ((st)->st_atim);






}


static inline struct timespec
get_stat_ctime (struct stat const *st)
{

  return ((st)->st_ctim);






}


static inline struct timespec
get_stat_mtime (struct stat const *st)
{

  return ((st)->st_mtim);






}



static inline struct timespec
get_stat_birthtime (struct stat const *st)
{
  struct timespec t;
# 163 "../lib/stat-time.h"
  t.tv_sec = -1;
  t.tv_nsec = -1;
# 180 "../lib/stat-time.h"
  return t;
}
# 104 "ls.c" 2
# 1 "../lib/strftime.h" 1
# 18 "../lib/strftime.h"
# 1 "../lib/time.h" 1
# 19 "../lib/strftime.h" 2

size_t nstrftime (char *, size_t, char const *, struct tm const *, int, int);
# 105 "ls.c" 2
# 1 "../lib/strverscmp.h" 1
# 24 "../lib/strverscmp.h"
int strverscmp (const char *, const char *);
# 106 "ls.c" 2

# 1 "../lib/areadlink.h" 1
# 20 "../lib/areadlink.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 21 "../lib/areadlink.h" 2

extern char *areadlink (char const *filename);
extern char *areadlink_with_size (char const *filename, size_t size_hint);
# 108 "ls.c" 2
# 126 "ls.c"
enum filetype
  {
    unknown,
    fifo,
    chardev,
    directory,
    blockdev,
    normal,
    symbolic_link,
    sock,
    whiteout,
    arg_directory
  };



static char const filetype_letter[] = "?pcdb-lswd";



extern int (* verify_function__ (void)) [(!!sizeof (struct { unsigned int verify_error_if_negative_size__: (sizeof filetype_letter - 1 == arg_directory + 1) ? 1 : -1; }))];
# 155 "ls.c"
struct fileinfo
  {

    char *name;


    char *linkname;

    struct stat stat;

    enum filetype filetype;



    mode_t linkmode;


    char* scontext;

    _Bool stat_ok;



    _Bool linkok;



    _Bool have_acl;
  };







struct bin_str
  {
    size_t len;
    const char *string;
  };





static size_t quote_name (FILE *out, const char *name,
     struct quoting_options const *options,
     size_t *width);
static char *make_link_name (char const *name, char const *linkname);
static int decode_switches (int argc, char **argv);
static _Bool file_ignored (char const *name);
static uintmax_t gobble_file (char const *name, enum filetype type,
         ino_t inode, _Bool command_line_arg,
         char const *dirname);
static void print_color_indicator (const char *name, mode_t mode, int linkok,
       _Bool stat_ok, enum filetype type);
static void put_indicator (const struct bin_str *ind);
static void add_ignore_pattern (const char *pattern);
static void attach (char *dest, const char *dirname, const char *name);
static void clear_files (void);
static void extract_dirs_from_files (char const *dirname,
         _Bool command_line_arg);
static void get_link_name (char const *filename, struct fileinfo *f,
      _Bool command_line_arg);
static void indent (size_t from, size_t to);
static size_t calculate_columns (_Bool by_columns);
static void print_current_files (void);
static void print_dir (char const *name, char const *realname,
         _Bool command_line_arg);
static void print_file_name_and_frills (const struct fileinfo *f);
static void print_horizontal (void);
static int format_user_width (uid_t u);
static int format_group_width (gid_t g);
static void print_long_format (const struct fileinfo *f);
static void print_many_per_line (void);
static void print_name_with_quoting (const char *p, mode_t mode,
         int linkok, _Bool stat_ok,
         enum filetype type,
         struct obstack *stack);
static void prep_non_filename_text (void);
static void print_type_indicator (_Bool stat_ok, mode_t mode,
      enum filetype type);
static void print_with_commas (void);
static void queue_directory (char const *name, char const *realname,
        _Bool command_line_arg);
static void sort_files (void);
static void parse_ls_color (void);
void usage (int status);


char *program_name;
# 259 "ls.c"
static Hash_table *active_dir_set;
# 270 "ls.c"
static struct fileinfo *cwd_file;


static size_t cwd_n_alloc;


static size_t cwd_n_used;



static void **sorted_file;
static size_t sorted_file_alloc;






static _Bool color_symlink_as_referent;
# 298 "ls.c"
struct pending
  {
    char *name;



    char *realname;
    _Bool command_line_arg;
    struct pending *next;
  };

static struct pending *pending_dirs;




static time_t current_time = ((time_t) (! (! ((time_t) 0 < (time_t) -1)) ? (time_t) 0 : ((time_t) ~ (time_t) 0 < (time_t) -1) ? ~ (time_t) 0 : ~ (time_t) 0 << (sizeof (time_t) * 8 - 1)));
static int current_time_ns = -1;

static _Bool print_scontext;
static char UNKNOWN_SECURITY_CONTEXT[] = "?";




static _Bool any_has_acl;





static int inode_number_width;
static int block_size_width;
static int nlink_width;
static int scontext_width;
static int owner_width;
static int group_width;
static int author_width;
static int major_device_number_width;
static int minor_device_number_width;
static int file_size_width;
# 351 "ls.c"
enum format
  {
    long_format,
    one_per_line,
    many_per_line,
    horizontal,
    with_commas
  };

static enum format format;




enum time_style
  {
    full_iso_time_style,
    long_iso_time_style,
    iso_time_style,
    locale_time_style
  };

static char const *const time_style_args[] =
{
  "full-iso", "long-iso", "iso", "locale", ((void *)0)
};
static enum time_style const time_style_types[] =
{
  full_iso_time_style, long_iso_time_style, iso_time_style,
  locale_time_style
};
extern int (* verify_function__ (void)) [(!!sizeof (struct { unsigned int verify_error_if_negative_size__: ((sizeof (time_style_args) / sizeof *(time_style_args)) == (sizeof (time_style_types) / sizeof *(time_style_types)) + 1) ? 1 : -1; }))];





enum time_type
  {
    time_mtime,
    time_ctime,
    time_atime,
    time_numtypes
  };

static enum time_type time_type;





enum sort_type
  {
    sort_none = -1,
    sort_name,
    sort_extension,
    sort_size,
    sort_version,
    sort_time,
    sort_numtypes
  };

static enum sort_type sort_type;







static _Bool sort_reverse;



static _Bool print_owner = 1;



static _Bool print_author;



static _Bool print_group = 1;




static _Bool numeric_ids;



static _Bool print_block_size;


static int human_output_opts;


static uintmax_t output_block_size;


static uintmax_t file_output_block_size = 1;




static _Bool dired;
# 465 "ls.c"
enum indicator_style
  {
    none,
    slash,
    file_type,
    classify
  };

static enum indicator_style indicator_style;


static char const *const indicator_style_args[] =
{
  "none", "slash", "file-type", "classify", ((void *)0)
};
static enum indicator_style const indicator_style_types[] =
{
  none, slash, file_type, classify
};
extern int (* verify_function__ (void)) [(!!sizeof (struct { unsigned int verify_error_if_negative_size__: ((sizeof (indicator_style_args) / sizeof *(indicator_style_args)) == (sizeof (indicator_style_types) / sizeof *(indicator_style_types)) + 1) ? 1 : -1; }))];





static _Bool print_with_color;

enum color_type
  {
    color_never,
    color_always,
    color_if_tty
  };

enum Dereference_symlink
  {
    DEREF_UNDEFINED = 1,
    DEREF_NEVER,
    DEREF_COMMAND_LINE_ARGUMENTS,
    DEREF_COMMAND_LINE_SYMLINK_TO_DIR,
    DEREF_ALWAYS
  };

enum indicator_no
  {
    C_LEFT, C_RIGHT, C_END, C_NORM, C_FILE, C_DIR, C_LINK, C_FIFO, C_SOCK,
    C_BLK, C_CHR, C_MISSING, C_ORPHAN, C_EXEC, C_DOOR, C_SETUID, C_SETGID,
    C_STICKY, C_OTHER_WRITABLE, C_STICKY_OTHER_WRITABLE
  };

static const char *const indicator_name[]=
  {
    "lc", "rc", "ec", "no", "fi", "di", "ln", "pi", "so",
    "bd", "cd", "mi", "or", "ex", "do", "su", "sg", "st",
    "ow", "tw", ((void *)0)
  };

struct color_ext_type
  {
    struct bin_str ext;
    struct bin_str seq;
    struct color_ext_type *next;
  };

static struct bin_str color_indicator[] =
  {
    { sizeof ("\033[") - 1, "\033[" },
    { sizeof ("m") - 1, "m" },
    { 0, ((void *)0) },
    { sizeof ("0") - 1, "0" },
    { sizeof ("0") - 1, "0" },
    { sizeof ("01;34") - 1, "01;34" },
    { sizeof ("01;36") - 1, "01;36" },
    { sizeof ("33") - 1, "33" },
    { sizeof ("01;35") - 1, "01;35" },
    { sizeof ("01;33") - 1, "01;33" },
    { sizeof ("01;33") - 1, "01;33" },
    { 0, ((void *)0) },
    { 0, ((void *)0) },
    { sizeof ("01;32") - 1, "01;32" },
    { sizeof ("01;35") - 1, "01;35" },
    { sizeof ("37;41") - 1, "37;41" },
    { sizeof ("30;43") - 1, "30;43" },
    { sizeof ("37;44") - 1, "37;44" },
    { sizeof ("34;42") - 1, "34;42" },
    { sizeof ("30;42") - 1, "30;42" },
  };


static struct color_ext_type *color_ext_list = ((void *)0);


static char *color_buf;




static _Bool check_symlink_color;



static _Bool print_inode;




static enum Dereference_symlink dereference;




static _Bool recursive;




static _Bool immediate_dirs;



static _Bool directories_first;



static enum
{


  IGNORE_DEFAULT,


  IGNORE_DOT_AND_DOTDOT,


  IGNORE_MINIMAL
} ignore_mode;






struct ignore_pattern
  {
    const char *pattern;
    struct ignore_pattern *next;
  };

static struct ignore_pattern *ignore_patterns;



static struct ignore_pattern *hide_patterns;
# 628 "ls.c"
static _Bool qmark_funny_chars;



static struct quoting_options *filename_quoting_options;
static struct quoting_options *dirname_quoting_options;



static size_t tabsize;



static _Bool print_dir_name;




static size_t line_length;




static _Bool format_needs_stat;




static _Bool format_needs_type;







enum { TIME_STAMP_LEN_MAXIMUM = (((1000)>(((sizeof (time_t) * 8 - (! ((__typeof__ (time_t)) 0 < (__typeof__ (time_t)) -1))) * 146 / 485 + (! ((__typeof__ (time_t)) 0 < (__typeof__ (time_t)) -1)) + 1)))?(1000):(((sizeof (time_t) * 8 - (! ((__typeof__ (time_t)) 0 < (__typeof__ (time_t)) -1))) * 146 / 485 + (! ((__typeof__ (time_t)) 0 < (__typeof__ (time_t)) -1)) + 1))) };




static char const *long_time_format[2] =
  {







    "%b %e  %Y",







    "%b %e %H:%M"
  };



static sigset_t caught_signals;



static sig_atomic_t volatile interrupt_signal;



static sig_atomic_t volatile stop_signal_count;



static int exit_status;


enum
  {


    LS_MINOR_PROBLEM = 1,


    LS_FAILURE = 2
  };



enum
{
  AUTHOR_OPTION = 127 + 1,
  BLOCK_SIZE_OPTION,
  COLOR_OPTION,
  DEREFERENCE_COMMAND_LINE_SYMLINK_TO_DIR_OPTION,
  FILE_TYPE_INDICATOR_OPTION,
  FORMAT_OPTION,
  FULL_TIME_OPTION,
  GROUP_DIRECTORIES_FIRST_OPTION,
  HIDE_OPTION,
  INDICATOR_STYLE_OPTION,
  QUOTING_STYLE_OPTION,
  SHOW_CONTROL_CHARS_OPTION,
  SI_OPTION,
  SORT_OPTION,
  TIME_OPTION,
  TIME_STYLE_OPTION
};

static struct option const long_options[] =
{
  {"all", 0, ((void *)0), 'a'},
  {"escape", 0, ((void *)0), 'b'},
  {"directory", 0, ((void *)0), 'd'},
  {"dired", 0, ((void *)0), 'D'},
  {"full-time", 0, ((void *)0), FULL_TIME_OPTION},
  {"group-directories-first", 0, ((void *)0),
   GROUP_DIRECTORIES_FIRST_OPTION},
  {"human-readable", 0, ((void *)0), 'h'},
  {"inode", 0, ((void *)0), 'i'},
  {"numeric-uid-gid", 0, ((void *)0), 'n'},
  {"no-group", 0, ((void *)0), 'G'},
  {"hide-control-chars", 0, ((void *)0), 'q'},
  {"reverse", 0, ((void *)0), 'r'},
  {"size", 0, ((void *)0), 's'},
  {"width", 1, ((void *)0), 'w'},
  {"almost-all", 0, ((void *)0), 'A'},
  {"ignore-backups", 0, ((void *)0), 'B'},
  {"classify", 0, ((void *)0), 'F'},
  {"file-type", 0, ((void *)0), FILE_TYPE_INDICATOR_OPTION},
  {"si", 0, ((void *)0), SI_OPTION},
  {"dereference-command-line", 0, ((void *)0), 'H'},
  {"dereference-command-line-symlink-to-dir", 0, ((void *)0),
   DEREFERENCE_COMMAND_LINE_SYMLINK_TO_DIR_OPTION},
  {"hide", 1, ((void *)0), HIDE_OPTION},
  {"ignore", 1, ((void *)0), 'I'},
  {"indicator-style", 1, ((void *)0), INDICATOR_STYLE_OPTION},
  {"dereference", 0, ((void *)0), 'L'},
  {"literal", 0, ((void *)0), 'N'},
  {"quote-name", 0, ((void *)0), 'Q'},
  {"quoting-style", 1, ((void *)0), QUOTING_STYLE_OPTION},
  {"recursive", 0, ((void *)0), 'R'},
  {"format", 1, ((void *)0), FORMAT_OPTION},
  {"show-control-chars", 0, ((void *)0), SHOW_CONTROL_CHARS_OPTION},
  {"sort", 1, ((void *)0), SORT_OPTION},
  {"tabsize", 1, ((void *)0), 'T'},
  {"time", 1, ((void *)0), TIME_OPTION},
  {"time-style", 1, ((void *)0), TIME_STYLE_OPTION},
  {"color", 2, ((void *)0), COLOR_OPTION},
  {"block-size", 1, ((void *)0), BLOCK_SIZE_OPTION},
  {"context", 0, 0, 'Z'},
  {"author", 0, ((void *)0), AUTHOR_OPTION},
  {"help", 0, ((void *)0), GETOPT_HELP_CHAR},
  {"version", 0, ((void *)0), GETOPT_VERSION_CHAR},
  {((void *)0), 0, ((void *)0), 0}
};

static char const *const format_args[] =
{
  "verbose", "long", "commas", "horizontal", "across",
  "vertical", "single-column", ((void *)0)
};
static enum format const format_types[] =
{
  long_format, long_format, with_commas, horizontal, horizontal,
  many_per_line, one_per_line
};
extern int (* verify_function__ (void)) [(!!sizeof (struct { unsigned int verify_error_if_negative_size__: ((sizeof (format_args) / sizeof *(format_args)) == (sizeof (format_types) / sizeof *(format_types)) + 1) ? 1 : -1; }))];

static char const *const sort_args[] =
{
  "none", "time", "size", "extension", "version", ((void *)0)
};
static enum sort_type const sort_types[] =
{
  sort_none, sort_time, sort_size, sort_extension, sort_version
};
extern int (* verify_function__ (void)) [(!!sizeof (struct { unsigned int verify_error_if_negative_size__: ((sizeof (sort_args) / sizeof *(sort_args)) == (sizeof (sort_types) / sizeof *(sort_types)) + 1) ? 1 : -1; }))];

static char const *const time_args[] =
{
  "atime", "access", "use", "ctime", "status", ((void *)0)
};
static enum time_type const time_types[] =
{
  time_atime, time_atime, time_atime, time_ctime, time_ctime
};
extern int (* verify_function__ (void)) [(!!sizeof (struct { unsigned int verify_error_if_negative_size__: ((sizeof (time_args) / sizeof *(time_args)) == (sizeof (time_types) / sizeof *(time_types)) + 1) ? 1 : -1; }))];

static char const *const color_args[] =
{

  "always", "yes", "force",
  "never", "no", "none",
  "auto", "tty", "if-tty", ((void *)0)
};
static enum color_type const color_types[] =
{
  color_always, color_always, color_always,
  color_never, color_never, color_never,
  color_if_tty, color_if_tty, color_if_tty
};
extern int (* verify_function__ (void)) [(!!sizeof (struct { unsigned int verify_error_if_negative_size__: ((sizeof (color_args) / sizeof *(color_args)) == (sizeof (color_types) / sizeof *(color_types)) + 1) ? 1 : -1; }))];


struct column_info
{
  _Bool valid_len;
  size_t line_len;
  size_t *col_arr;
};


static struct column_info *column_info;


static size_t max_idx;
# 857 "ls.c"
static size_t dired_pos;
# 878 "ls.c"
static struct obstack dired_obstack;






static struct obstack subdired_obstack;
# 899 "ls.c"
static struct obstack dev_ino_obstack;
# 915 "ls.c"
static struct dev_ino
dev_ino_pop (void)
{
  ((sizeof (struct dev_ino) <= __extension__ ({ struct obstack const *__o = (&dev_ino_obstack); (unsigned) (__o->next_free - __o->object_base); })) ? (void) (0) : __assert_fail ("sizeof (struct dev_ino) <= __extension__ ({ struct obstack const *__o = (&dev_ino_obstack); (unsigned) (__o->next_free - __o->object_base); })", "ls.c", 918, __PRETTY_FUNCTION__));
  __extension__ ({ struct obstack *__o = (&dev_ino_obstack); int __len = (-(int) (sizeof (struct dev_ino))); if (__o->chunk_limit - __o->next_free < __len) _obstack_newchunk (__o, __len); ((__o)->next_free += (__len)); (void) 0; });
  return *(struct dev_ino *) ((&dev_ino_obstack)->next_free);
}
# 938 "ls.c"
static void
dired_dump_obstack (const char *prefix, struct obstack *os)
{
  size_t n_pos;

  n_pos = __extension__ ({ struct obstack const *__o = (os); (unsigned) (__o->next_free - __o->object_base); }) / sizeof (dired_pos);
  if (n_pos > 0)
    {
      size_t i;
      size_t *pos;

      pos = (size_t *) __extension__ ({ struct obstack *__o1 = (os); void *__value = (void *) __o1->object_base; if (__o1->next_free == __value) __o1->maybe_empty_object = 1; __o1->next_free = ((sizeof (int) < sizeof (void *) ? (__o1->object_base) : (char *) 0) + (((__o1->next_free) - (sizeof (int) < sizeof (void *) ? (__o1->object_base) : (char *) 0) + (__o1->alignment_mask)) & ~(__o1->alignment_mask))); if (__o1->next_free - (char *)__o1->chunk > __o1->chunk_limit - (char *)__o1->chunk) __o1->next_free = __o1->chunk_limit; __o1->object_base = __o1->next_free; __value; });
      fputs_unlocked (prefix,stdout);
      for (i = 0; i < n_pos; i++)
 printf (" %lu", (unsigned long int) pos[i]);
      putchar_unlocked ('\n');
    }
}

static size_t
dev_ino_hash (void const *x, size_t table_size)
{
  struct dev_ino const *p = x;
  return (uintmax_t) p->st_ino % table_size;
}

static _Bool
dev_ino_compare (void const *x, void const *y)
{
  struct dev_ino const *a = x;
  struct dev_ino const *b = y;
  return ((*a).st_ino == (*b).st_ino && (*a).st_dev == (*b).st_dev) ? 1 : 0;
}

static void
dev_ino_free (void *x)
{
  free (x);
}





static _Bool
visit_dir (dev_t dev, ino_t ino)
{
  struct dev_ino *ent;
  struct dev_ino *ent_from_table;
  _Bool found_match;

  ent = xmalloc (sizeof *ent);
  ent->st_ino = ino;
  ent->st_dev = dev;


  ent_from_table = hash_insert (active_dir_set, ent);

  if (ent_from_table == ((void *)0))
    {

      xalloc_die ();
    }

  found_match = (ent_from_table != ent);

  if (found_match)
    {

      free (ent);
    }

  return found_match;
}

static void
free_pending_ent (struct pending *p)
{
  free (p->name);
  free (p->realname);
  free (p);
}

static _Bool
is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  return ! (len == 0
     || (len == 1 && strncmp (s, "0", 1) == 0)
     || (len == 2 && strncmp (s, "00", 2) == 0));
}

static void
restore_default_color (void)
{
  put_indicator (&color_indicator[C_LEFT]);
  put_indicator (&color_indicator[C_RIGHT]);
}



static void
sighandler (int sig)
{
  if (! 1)
    signal (sig, ((__sighandler_t) 1));
  if (! interrupt_signal)
    interrupt_signal = sig;
}



static void
stophandler (int sig)
{
  if (! 1)
    signal (sig, stophandler);
  if (! interrupt_signal)
    stop_signal_count++;
}







static void
process_signals (void)
{
  while (interrupt_signal | stop_signal_count)
    {
      int sig;
      int stops;
      sigset_t oldset;

      restore_default_color ();
      fflush_unlocked (stdout);

      sigprocmask (0, &caught_signals, &oldset);



      sig = interrupt_signal;
      stops = stop_signal_count;




      if (stops)
 {
   stop_signal_count = stops - 1;
   sig = 19;
 }
      else
 signal (sig, ((__sighandler_t) 0));


      raise (sig);
      sigprocmask (2, &oldset, ((void *)0));



    }
}

int
main (int argc, char **argv)
{
  int i;
  struct pending *thispend;
  int n_files;


  static int const sig[] =
    {

      20,


      14, 1, 2, 13, 3, 15,

      29,


      27,


      26,


      24,


      25,

    };
  enum { nsigs = sizeof sig / sizeof sig[0] };





  ;
  program_name = argv[0];
  setlocale (__LC_ALL, "");
  bindtextdomain ("coreutils", "/usr/local/share/locale");
  textdomain ("coreutils");

  initialize_exit_failure (LS_FAILURE);
  atexit (close_stdout);


  (((sizeof color_indicator / sizeof *(color_indicator)) + 1 == (sizeof indicator_name / sizeof *(indicator_name))) ? (void) (0) : __assert_fail ("(sizeof color_indicator / sizeof *(color_indicator)) + 1 == (sizeof indicator_name / sizeof *(indicator_name))", "ls.c", 1152, __PRETTY_FUNCTION__));

  exit_status = 0;
  print_dir_name = 1;
  pending_dirs = ((void *)0);

  i = decode_switches (argc, argv);

  if (print_with_color)
    parse_ls_color ();



  if (print_with_color)
    {

      if (is_colored (C_ORPHAN)
   || (is_colored (C_EXEC) && color_symlink_as_referent)
   || (is_colored (C_MISSING) && format == long_format))
 check_symlink_color = 1;





      if (0 <= tcgetpgrp (1))
 {
   int j;

   struct sigaction act;

   sigemptyset (&caught_signals);
   for (j = 0; j < nsigs; j++)
     {
       sigaction (sig[j], ((void *)0), &act);
       if (act.__sigaction_handler.sa_handler != ((__sighandler_t) 1))
  sigaddset (&caught_signals, sig[j]);
     }

   act.sa_mask = caught_signals;
   act.sa_flags = 0x10000000;

   for (j = 0; j < nsigs; j++)
     if (sigismember (&caught_signals, sig[j]))
       {
  act.__sigaction_handler.sa_handler = sig[j] == 20 ? stophandler : sighandler;
  sigaction (sig[j], &act, ((void *)0));
       }
# 1211 "ls.c"
 }

      prep_non_filename_text ();
    }

  if (dereference == DEREF_UNDEFINED)
    dereference = ((immediate_dirs
      || indicator_style == classify
      || format == long_format)
     ? DEREF_NEVER
     : DEREF_COMMAND_LINE_SYMLINK_TO_DIR);



  if (recursive)
    {
      active_dir_set = hash_initialize (30, ((void *)0),
     dev_ino_hash,
     dev_ino_compare,
     dev_ino_free);
      if (active_dir_set == ((void *)0))
 xalloc_die ();

      _obstack_begin ((&dev_ino_obstack), 0, 0, (void *(*) (long)) malloc, (void (*) (void *)) free);
    }

  format_needs_stat = sort_type == sort_time || sort_type == sort_size
    || format == long_format
    || print_scontext
    || print_block_size;
  format_needs_type = (! format_needs_stat
         && (recursive
      || print_with_color
      || indicator_style != none
      || directories_first));

  if (dired)
    {
      _obstack_begin ((&dired_obstack), 0, 0, (void *(*) (long)) malloc, (void (*) (void *)) free);
      _obstack_begin ((&subdired_obstack), 0, 0, (void *(*) (long)) malloc, (void (*) (void *)) free);
    }

  cwd_n_alloc = 100;
  cwd_file = xnmalloc (cwd_n_alloc, sizeof *cwd_file);
  cwd_n_used = 0;

  clear_files ();

  n_files = argc - i;

  if (n_files <= 0)
    {
      if (immediate_dirs)
 gobble_file (".", directory, NOT_AN_INODE_NUMBER, 1, "");
      else
 queue_directory (".", ((void *)0), 1);
    }
  else
    do
      gobble_file (argv[i++], unknown, NOT_AN_INODE_NUMBER, 1, "");
    while (i < argc);

  if (cwd_n_used)
    {
      sort_files ();
      if (!immediate_dirs)
 extract_dirs_from_files (((void *)0), 1);

    }





  if (cwd_n_used)
    {
      print_current_files ();
      if (pending_dirs)
 do {putchar_unlocked (('\n')); ++dired_pos;} while (0);
    }
  else if (n_files <= 1 && pending_dirs && pending_dirs->next == 0)
    print_dir_name = 0;

  while (pending_dirs)
    {
      thispend = pending_dirs;
      pending_dirs = pending_dirs->next;

      if ((!!active_dir_set))
 {
   if (thispend->name == ((void *)0))
     {




       struct dev_ino di = dev_ino_pop ();
       struct dev_ino *found = hash_delete (active_dir_set, &di);

       ((found) ? (void) (0) : __assert_fail ("found", "ls.c", 1310, __PRETTY_FUNCTION__));
       dev_ino_free (found);
       free_pending_ent (thispend);
       continue;
     }
 }

      print_dir (thispend->name, thispend->realname,
   thispend->command_line_arg);

      free_pending_ent (thispend);
      print_dir_name = 1;
    }

  if (print_with_color)
    {
      int j;

      restore_default_color ();
      fflush_unlocked (stdout);



      for (j = 0; j < nsigs; j++)
 if (sigismember (&caught_signals, sig[j]))
   signal (sig[j], ((__sighandler_t) 0));
# 1346 "ls.c"
      for (j = stop_signal_count; j; j--)
 raise (19);
      j = interrupt_signal;
      if (j)
 raise (j);
    }

  if (dired)
    {

      dired_dump_obstack ("//DIRED//", &dired_obstack);
      dired_dump_obstack ("//SUBDIRED//", &subdired_obstack);
      printf ("//DIRED-OPTIONS// --quoting-style=%s\n",
       quoting_style_args[get_quoting_style (filename_quoting_options)]);
    }

  if ((!!active_dir_set))
    {
      ((hash_get_n_entries (active_dir_set) == 0) ? (void) (0) : __assert_fail ("hash_get_n_entries (active_dir_set) == 0", "ls.c", 1364, __PRETTY_FUNCTION__));
      hash_free (active_dir_set);
    }

  exit (exit_status);
}




static int
decode_switches (int argc, char **argv)
{
  char *time_style_option = ((void *)0);


  _Bool sort_type_specified = 0;

  qmark_funny_chars = 0;



  switch (ls_mode)
    {
    case 2:

      format = many_per_line;
      set_quoting_style (((void *)0), escape_quoting_style);
      break;

    case 3:

      format = long_format;
      set_quoting_style (((void *)0), escape_quoting_style);
      break;

    case 1:

      if (isatty (1))
 {
   format = many_per_line;

   qmark_funny_chars = 1;
 }
      else
 {
   format = one_per_line;
   qmark_funny_chars = 0;
 }
      break;

    default:
      abort ();
    }

  time_type = time_mtime;
  sort_type = sort_name;
  sort_reverse = 0;
  numeric_ids = 0;
  print_block_size = 0;
  indicator_style = none;
  print_inode = 0;
  dereference = DEREF_UNDEFINED;
  recursive = 0;
  immediate_dirs = 0;
  ignore_mode = IGNORE_DEFAULT;
  ignore_patterns = ((void *)0);
  hide_patterns = ((void *)0);
  print_scontext = 0;


  {
    char const *q_style = getenv ("QUOTING_STYLE");
    if (q_style)
      {
 int i = argmatch (q_style, quoting_style_args, (char const *) (quoting_style_vals), sizeof *(quoting_style_vals));
 if (0 <= i)
   set_quoting_style (((void *)0), quoting_style_vals[i]);
 else
   error (0, 0,
  gettext ("ignoring invalid value of environment variable QUOTING_STYLE: %s"),
   quotearg (q_style));
      }
  }

  {
    char const *ls_block_size = getenv ("LS_BLOCK_SIZE");
    human_options (ls_block_size,
     &human_output_opts, &output_block_size);
    if (ls_block_size || getenv ("BLOCK_SIZE"))
      file_output_block_size = output_block_size;
  }

  line_length = 80;
  {
    char const *p = getenv ("COLUMNS");
    if (p && *p)
      {
 unsigned long int tmp_ulong;
 if (xstrtoul (p, ((void *)0), 0, &tmp_ulong, ((void *)0)) == LONGINT_OK
     && 0 < tmp_ulong && tmp_ulong <= (4294967295U))
   {
     line_length = tmp_ulong;
   }
 else
   {
     error (0, 0,
        gettext ("ignoring invalid width in environment variable COLUMNS: %s"),
     quotearg (p));
   }
      }
  }


  {
    struct winsize ws;

    if (ioctl (1, 0x5413, &ws) != -1
 && 0 < ws.ws_col && ws.ws_col == (size_t) ws.ws_col)
      line_length = ws.ws_col;
  }


  {
    char const *p = getenv ("TABSIZE");
    tabsize = 8;
    if (p)
      {
 unsigned long int tmp_ulong;
 if (xstrtoul (p, ((void *)0), 0, &tmp_ulong, ((void *)0)) == LONGINT_OK
     && tmp_ulong <= (4294967295U))
   {
     tabsize = tmp_ulong;
   }
 else
   {
     error (0, 0,
      gettext ("ignoring invalid tab size in environment variable TABSIZE: %s"),
     quotearg (p));
   }
      }
  }

  for (;;)
    {
      int oi = -1;
      int c = getopt_long (argc, argv,
      "abcdfghiklmnopqrstuvw:xABCDFGHI:LNQRST:UXZ1",
      long_options, &oi);
      if (c == -1)
 break;

      switch (c)
 {
 case 'a':
   ignore_mode = IGNORE_MINIMAL;
   break;

 case 'b':
   set_quoting_style (((void *)0), escape_quoting_style);
   break;

 case 'c':
   time_type = time_ctime;
   break;

 case 'd':
   immediate_dirs = 1;
   break;

 case 'f':

   ignore_mode = IGNORE_MINIMAL;
   sort_type = sort_none;
   sort_type_specified = 1;

   if (format == long_format)
     format = (isatty (1) ? many_per_line : one_per_line);
   print_block_size = 0;
   print_with_color = 0;
   break;

 case FILE_TYPE_INDICATOR_OPTION:
   indicator_style = file_type;
   break;

 case 'g':
   format = long_format;
   print_owner = 0;
   break;

 case 'h':
   human_output_opts = human_autoscale | human_SI | human_base_1024;
   file_output_block_size = output_block_size = 1;
   break;

 case 'i':
   print_inode = 1;
   break;

 case 'k':
   human_output_opts = 0;
   file_output_block_size = output_block_size = 1024;
   break;

 case 'l':
   format = long_format;
   break;

 case 'm':
   format = with_commas;
   break;

 case 'n':
   numeric_ids = 1;
   format = long_format;
   break;

 case 'o':
   format = long_format;
   print_group = 0;
   break;

 case 'p':
   indicator_style = slash;
   break;

 case 'q':
   qmark_funny_chars = 1;
   break;

 case 'r':
   sort_reverse = 1;
   break;

 case 's':
   print_block_size = 1;
   break;

 case 't':
   sort_type = sort_time;
   sort_type_specified = 1;
   break;

 case 'u':
   time_type = time_atime;
   break;

 case 'v':
   sort_type = sort_version;
   sort_type_specified = 1;
   break;

 case 'w':
   {
     unsigned long int tmp_ulong;
     if (xstrtoul (optarg, ((void *)0), 0, &tmp_ulong, ((void *)0)) != LONGINT_OK
  || ! (0 < tmp_ulong && tmp_ulong <= (4294967295U)))
       error (LS_FAILURE, 0, gettext ("invalid line width: %s"),
       quotearg (optarg));
     line_length = tmp_ulong;
     break;
   }

 case 'x':
   format = horizontal;
   break;

 case 'A':
   if (ignore_mode == IGNORE_DEFAULT)
     ignore_mode = IGNORE_DOT_AND_DOTDOT;
   break;

 case 'B':
   add_ignore_pattern ("*~");
   add_ignore_pattern (".*~");
   break;

 case 'C':
   format = many_per_line;
   break;

 case 'D':
   dired = 1;
   break;

 case 'F':
   indicator_style = classify;
   break;

 case 'G':
   print_group = 0;
   break;

 case 'H':
   dereference = DEREF_COMMAND_LINE_ARGUMENTS;
   break;

 case DEREFERENCE_COMMAND_LINE_SYMLINK_TO_DIR_OPTION:
   dereference = DEREF_COMMAND_LINE_SYMLINK_TO_DIR;
   break;

 case 'I':
   add_ignore_pattern (optarg);
   break;

 case 'L':
   dereference = DEREF_ALWAYS;
   break;

 case 'N':
   set_quoting_style (((void *)0), literal_quoting_style);
   break;

 case 'Q':
   set_quoting_style (((void *)0), c_quoting_style);
   break;

 case 'R':
   recursive = 1;
   break;

 case 'S':
   sort_type = sort_size;
   sort_type_specified = 1;
   break;

 case 'T':
   {
     unsigned long int tmp_ulong;
     if (xstrtoul (optarg, ((void *)0), 0, &tmp_ulong, ((void *)0)) != LONGINT_OK
  || (4294967295U) < tmp_ulong)
       error (LS_FAILURE, 0, gettext ("invalid tab size: %s"),
       quotearg (optarg));
     tabsize = tmp_ulong;
     break;
   }

 case 'U':
   sort_type = sort_none;
   sort_type_specified = 1;
   break;

 case 'X':
   sort_type = sort_extension;
   sort_type_specified = 1;
   break;

 case '1':

   if (format != long_format)
     format = one_per_line;
   break;

        case AUTHOR_OPTION:
          print_author = 1;
          break;

 case HIDE_OPTION:
   {
     struct ignore_pattern *hide = xmalloc (sizeof *hide);
     hide->pattern = optarg;
     hide->next = hide_patterns;
     hide_patterns = hide;
   }
   break;

 case SORT_OPTION:
   sort_type = ((sort_types) [__xargmatch_internal ("--sort", optarg, sort_args, (char const *) (sort_types), sizeof *(sort_types), argmatch_die)]);
   sort_type_specified = 1;
   break;

 case GROUP_DIRECTORIES_FIRST_OPTION:
   directories_first = 1;
   break;

 case TIME_OPTION:
   time_type = ((time_types) [__xargmatch_internal ("--time", optarg, time_args, (char const *) (time_types), sizeof *(time_types), argmatch_die)]);
   break;

 case FORMAT_OPTION:
   format = ((format_types) [__xargmatch_internal ("--format", optarg, format_args, (char const *) (format_types), sizeof *(format_types), argmatch_die)]);
   break;

 case FULL_TIME_OPTION:
   format = long_format;
   time_style_option = "full-iso";
   break;

 case COLOR_OPTION:
   {
     int i;
     if (optarg)
       i = ((color_types) [__xargmatch_internal ("--color", optarg, color_args, (char const *) (color_types), sizeof *(color_types), argmatch_die)]);
     else


       i = color_always;

     print_with_color = (i == color_always
    || (i == color_if_tty
        && isatty (1)));

     if (print_with_color)
       {



  tabsize = 0;
       }
     break;
   }

 case INDICATOR_STYLE_OPTION:
   indicator_style = ((indicator_style_types) [__xargmatch_internal ("--indicator-style", optarg, indicator_style_args, (char const *) (indicator_style_types), sizeof *(indicator_style_types), argmatch_die)]);


   break;

 case QUOTING_STYLE_OPTION:
   set_quoting_style (((void *)0),
        ((quoting_style_vals) [__xargmatch_internal ("--quoting-style", optarg, quoting_style_args, (char const *) (quoting_style_vals), sizeof *(quoting_style_vals), argmatch_die)]));


   break;

 case TIME_STYLE_OPTION:
   time_style_option = optarg;
   break;

 case SHOW_CONTROL_CHARS_OPTION:
   qmark_funny_chars = 0;
   break;

 case BLOCK_SIZE_OPTION:
   {
     enum strtol_error e = human_options (optarg, &human_output_opts,
       &output_block_size);
     if (e != LONGINT_OK)
       xstrtol_fatal (e, oi, 0, long_options, optarg);
     file_output_block_size = output_block_size;
   }
   break;

 case SI_OPTION:
   human_output_opts = human_autoscale | human_SI;
   file_output_block_size = output_block_size = 1;
   break;

 case 'Z':
   print_scontext = 1;
   break;

 case GETOPT_HELP_CHAR: usage (0); break;;

 case GETOPT_VERSION_CHAR: version_etc (stdout, (ls_mode == 1 ? "ls" : (ls_mode == 2 ? "dir" : "vdir")), "GNU coreutils", "6.10", "Richard Stallman", "David MacKenzie", (char *) ((void *)0)); exit (0); break;;

 default:
   usage (LS_FAILURE);
 }
    }

  max_idx = (((1)>(line_length / 3))?(1):(line_length / 3));

  filename_quoting_options = clone_quoting_options (((void *)0));
  if (get_quoting_style (filename_quoting_options) == escape_quoting_style)
    set_char_quoting (filename_quoting_options, ' ', 1);
  if (file_type <= indicator_style)
    {
      char const *p;
      for (p = "*=>@|" + indicator_style - file_type; *p; p++)
 set_char_quoting (filename_quoting_options, *p, 1);
    }

  dirname_quoting_options = clone_quoting_options (((void *)0));
  set_char_quoting (dirname_quoting_options, ':', 1);




  if (dired && format != long_format)
    dired = 0;
# 1855 "ls.c"
  if ((time_type == time_ctime || time_type == time_atime)
      && !sort_type_specified && format != long_format)
    {
      sort_type = sort_time;
    }

  if (format == long_format)
    {
      char *style = time_style_option;
      static char const posix_prefix[] = "posix-";

      if (! style)
 if (! (style = getenv ("TIME_STYLE")))
   style = "locale";

      while (strncmp (style, posix_prefix, sizeof posix_prefix - 1) == 0)
 {
   if (! hard_locale (__LC_TIME))
     return optind;
   style += sizeof posix_prefix - 1;
 }

      if (*style == '+')
 {
   char *p0 = style + 1;
   char *p1 = strchr (p0, '\n');
   if (! p1)
     p1 = p0;
   else
     {
       if (strchr (p1 + 1, '\n'))
  error (LS_FAILURE, 0, gettext ("invalid time style format %s"),
         quote (p0));
       *p1++ = '\0';
     }
   long_time_format[0] = p0;
   long_time_format[1] = p1;
 }
      else
 switch (((time_style_types) [__xargmatch_internal ("time style", style, time_style_args, (char const *) (time_style_types), sizeof *(time_style_types), argmatch_die)]))


   {
   case full_iso_time_style:
     long_time_format[0] = long_time_format[1] =
       "%Y-%m-%d %H:%M:%S.%N %z";
     break;

   case long_iso_time_style:
   case_long_iso_time_style:
     long_time_format[0] = long_time_format[1] = "%Y-%m-%d %H:%M";
     break;

   case iso_time_style:
     long_time_format[0] = "%Y-%m-%d ";
     long_time_format[1] = "%m-%d %H:%M";
     break;

   case locale_time_style:
     if (hard_locale (__LC_TIME))
       {


  int i;
  for (i = 0; i < 2; i++)
    {
      char const *locale_format =
        dcgettext (((void *)0), long_time_format[i], __LC_TIME);
      if (locale_format == long_time_format[i])
        goto case_long_iso_time_style;
      long_time_format[i] = locale_format;
    }
       }
   }
    }

  return optind;
}
# 1947 "ls.c"
static _Bool
get_funky_string (char **dest, const char **src, _Bool equals_end,
    size_t *output_count)
{
  char num;
  size_t count;
  enum {
    ST_GND, ST_BACKSLASH, ST_OCTAL, ST_HEX, ST_CARET, ST_END, ST_ERROR
  } state;
  const char *p;
  char *q;

  p = *src;
  q = *dest;

  count = 0;
  num = 0;

  state = ST_GND;
  while (state < ST_END)
    {
      switch (state)
 {
 case ST_GND:
   switch (*p)
     {
     case ':':
     case '\0':
       state = ST_END;
       break;
     case '\\':
       state = ST_BACKSLASH;
       ++p;
       break;
     case '^':
       state = ST_CARET;
       ++p;
       break;
     case '=':
       if (equals_end)
  {
    state = ST_END;
    break;
  }

     default:
       *(q++) = *(p++);
       ++count;
       break;
     }
   break;

 case ST_BACKSLASH:
   switch (*p)
     {
     case '0':
     case '1':
     case '2':
     case '3':
     case '4':
     case '5':
     case '6':
     case '7':
       state = ST_OCTAL;
       num = *p - '0';
       break;
     case 'x':
     case 'X':
       state = ST_HEX;
       num = 0;
       break;
     case 'a':
       num = '\a';
       break;
     case 'b':
       num = '\b';
       break;
     case 'e':
       num = 27;
       break;
     case 'f':
       num = '\f';
       break;
     case 'n':
       num = '\n';
       break;
     case 'r':
       num = '\r';
       break;
     case 't':
       num = '\t';
       break;
     case 'v':
       num = '\v';
       break;
     case '?':
              num = 127;
       break;
     case '_':
       num = ' ';
       break;
     case '\0':
       state = ST_ERROR;
       break;
     default:
       num = *p;
       break;
     }
   if (state == ST_BACKSLASH)
     {
       *(q++) = num;
       ++count;
       state = ST_GND;
     }
   ++p;
   break;

 case ST_OCTAL:
   if (*p < '0' || *p > '7')
     {
       *(q++) = num;
       ++count;
       state = ST_GND;
     }
   else
     num = (num << 3) + (*(p++) - '0');
   break;

 case ST_HEX:
   switch (*p)
     {
     case '0':
     case '1':
     case '2':
     case '3':
     case '4':
     case '5':
     case '6':
     case '7':
     case '8':
     case '9':
       num = (num << 4) + (*(p++) - '0');
       break;
     case 'a':
     case 'b':
     case 'c':
     case 'd':
     case 'e':
     case 'f':
       num = (num << 4) + (*(p++) - 'a') + 10;
       break;
     case 'A':
     case 'B':
     case 'C':
     case 'D':
     case 'E':
     case 'F':
       num = (num << 4) + (*(p++) - 'A') + 10;
       break;
     default:
       *(q++) = num;
       ++count;
       state = ST_GND;
       break;
     }
   break;

 case ST_CARET:
   state = ST_GND;
   if (*p >= '@' && *p <= '~')
     {
       *(q++) = *(p++) & 037;
       ++count;
     }
   else if (*p == '?')
     {
       *(q++) = 127;
       ++count;
     }
   else
     state = ST_ERROR;
   break;

 default:
   abort ();
 }
    }

  *dest = q;
  *src = p;
  *output_count = count;

  return state != ST_ERROR;
}

static void
parse_ls_color (void)
{
  const char *p;
  char *buf;
  int state;
  int ind_no;
  char label[3];
  struct color_ext_type *ext;

  if ((p = getenv ("LS_COLORS")) == ((void *)0) || *p == '\0')
    return;

  ext = ((void *)0);
  strcpy (label, "??");





  buf = color_buf = xstrdup (p);

  state = 1;
  while (state > 0)
    {
      switch (state)
 {
 case 1:
   switch (*p)
     {
     case ':':
       ++p;
       break;

     case '*':





       ext = xmalloc (sizeof *ext);
       ext->next = color_ext_list;
       color_ext_list = ext;

       ++p;
       ext->ext.string = buf;

       state = (get_funky_string (&buf, &p, 1, &ext->ext.len)
         ? 4 : -1);
       break;

     case '\0':
       state = 0;
       break;

     default:
       label[0] = *(p++);
       state = 2;
       break;
     }
   break;

 case 2:
   if (*p)
     {
       label[1] = *(p++);
       state = 3;
     }
   else
     state = -1;
   break;

 case 3:
   state = -1;
   if (*(p++) == '=')
     {
       for (ind_no = 0; indicator_name[ind_no] != ((void *)0); ++ind_no)
  {
    if ((strcmp (label, indicator_name[ind_no]) == 0))
      {
        color_indicator[ind_no].string = buf;
        state = (get_funky_string (&buf, &p, 0,
       &color_indicator[ind_no].len)
          ? 1 : -1);
        break;
      }
  }
       if (state == -1)
  error (0, 0, gettext ("unrecognized prefix: %s"), quotearg (label));
     }
   break;

 case 4:
   if (*(p++) == '=')
     {
       ext->seq.string = buf;
       state = (get_funky_string (&buf, &p, 0, &ext->seq.len)
         ? 1 : -1);
     }
   else
     state = -1;
   break;
 }
    }

  if (state < 0)
    {
      struct color_ext_type *e;
      struct color_ext_type *e2;

      error (0, 0,
      gettext ("unparsable value for LS_COLORS environment variable"));
      free (color_buf);
      for (e = color_ext_list; e != ((void *)0); )
 {
   e2 = e;
   e = e->next;
   free (e2);
 }
      print_with_color = 0;
    }

  if (color_indicator[C_LINK].len == 6
      && !strncmp (color_indicator[C_LINK].string, "target", 6))
    color_symlink_as_referent = 1;
}




static void
set_exit_status (_Bool serious)
{
  if (serious)
    exit_status = LS_FAILURE;
  else if (exit_status == 0)
    exit_status = LS_MINOR_PROBLEM;
}





static void
file_failure (_Bool serious, char const *message, char const *file)
{
  error (0, (*__errno_location ()), message, quotearg_colon (file));
  set_exit_status (serious);
}
# 2302 "ls.c"
static void
queue_directory (char const *name, char const *realname, _Bool command_line_arg)
{
  struct pending *new = xmalloc (sizeof *new);
  new->realname = realname ? xstrdup (realname) : ((void *)0);
  new->name = name ? xstrdup (name) : ((void *)0);
  new->command_line_arg = command_line_arg;
  new->next = pending_dirs;
  pending_dirs = new;
}






static void
print_dir (char const *name, char const *realname, _Bool command_line_arg)
{
  DIR *dirp;
  struct dirent *next;
  uintmax_t total_blocks = 0;
  static _Bool first = 1;

  (*__errno_location ()) = 0;
  dirp = opendir (name);
  if (!dirp)
    {
      file_failure (command_line_arg, gettext ("cannot open directory %s"), name);
      return;
    }

  if ((!!active_dir_set))
    {
      struct stat dir_stat;
      int fd = dirfd (dirp);


      if ((0 <= fd
    ? fstat (fd, &dir_stat)
    : stat (name, &dir_stat)) < 0)
 {
   file_failure (command_line_arg,
   gettext ("cannot determine device and inode of %s"), name);
   closedir (dirp);
   return;
 }



      if (visit_dir (dir_stat.st_dev, dir_stat.st_ino))
 {
   error (0, 0, gettext ("%s: not listing already-listed directory"),
   quotearg_colon (name));
   closedir (dirp);
   return;
 }

      do { struct dev_ino *di; __extension__ ({ struct obstack *__o = (&dev_ino_obstack); int __len = (sizeof (struct dev_ino)); if (__o->chunk_limit - __o->next_free < __len) _obstack_newchunk (__o, __len); ((__o)->next_free += (__len)); (void) 0; }); di = -1 + (struct dev_ino *) ((&dev_ino_obstack)->next_free); di->st_dev = (dir_stat.st_dev); di->st_ino = (dir_stat.st_ino); } while (0);
    }




  clear_files ();

  while (1)
    {


      (*__errno_location ()) = 0;
      next = readdir (dirp);
      if (next)
 {
   if (! file_ignored (next->d_name))
     {
       enum filetype type = unknown;


       switch (next->d_type)
  {
  case DT_BLK: type = blockdev; break;
  case DT_CHR: type = chardev; break;
  case DT_DIR: type = directory; break;
  case DT_FIFO: type = fifo; break;
  case DT_LNK: type = symbolic_link; break;
  case DT_REG: type = normal; break;
  case DT_SOCK: type = sock; break;

  case DT_WHT: type = whiteout; break;

  }

       total_blocks += gobble_file (next->d_name, type, (next)->d_ino,
        0, name);
     }
 }
      else if ((*__errno_location ()) != 0)
 {
   file_failure (command_line_arg, gettext ("reading directory %s"), name);
   if ((*__errno_location ()) != 75)
     break;
 }
      else
 break;
    }

  if (closedir (dirp) != 0)
    {
      file_failure (command_line_arg, gettext ("closing directory %s"), name);

    }


  sort_files ();




  if (recursive)
    extract_dirs_from_files (name, command_line_arg);

  if (recursive | print_dir_name)
    {
      if (!first)
 do {putchar_unlocked (('\n')); ++dired_pos;} while (0);
      first = 0;
      do { if (dired) do {fputs_unlocked ("  ",stdout); dired_pos += sizeof ("  ") - 1;} while (0); } while (0);
      do { if (dired) __extension__ ({ struct obstack *__o = (&subdired_obstack); int __len = (sizeof (dired_pos)); if (__o->next_free + __len > __o->chunk_limit) _obstack_newchunk (__o, __len); memcpy (__o->next_free, &dired_pos, __len); __o->next_free += __len; (void) 0; }); } while (0);
      dired_pos += quote_name (stdout, realname ? realname : name,
          dirname_quoting_options, ((void *)0));
      do { if (dired) __extension__ ({ struct obstack *__o = (&subdired_obstack); int __len = (sizeof (dired_pos)); if (__o->next_free + __len > __o->chunk_limit) _obstack_newchunk (__o, __len); memcpy (__o->next_free, &dired_pos, __len); __o->next_free += __len; (void) 0; }); } while (0);
      do {fputs_unlocked (":\n",stdout); dired_pos += sizeof (":\n") - 1;} while (0);
    }

  if (format == long_format || print_block_size)
    {
      const char *p;
      char buf[((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 1];

      do { if (dired) do {fputs_unlocked ("  ",stdout); dired_pos += sizeof ("  ") - 1;} while (0); } while (0);
      p = gettext ("total");
      do {fputs_unlocked (p,stdout); dired_pos += strlen (p);} while (0);
      do {putchar_unlocked ((' ')); ++dired_pos;} while (0);
      p = human_readable (total_blocks, buf, human_output_opts,
     512, output_block_size);
      do {fputs_unlocked (p,stdout); dired_pos += strlen (p);} while (0);
      do {putchar_unlocked (('\n')); ++dired_pos;} while (0);
    }

  if (cwd_n_used)
    print_current_files ();
}




static void
add_ignore_pattern (const char *pattern)
{
  struct ignore_pattern *ignore;

  ignore = xmalloc (sizeof *ignore);
  ignore->pattern = pattern;

  ignore->next = ignore_patterns;
  ignore_patterns = ignore;
}



static _Bool
patterns_match (struct ignore_pattern const *patterns, char const *file)
{
  struct ignore_pattern const *p;
  for (p = patterns; p; p = p->next)
    if (fnmatch (p->pattern, file, (1 << 2)) == 0)
      return 1;
  return 0;
}



static _Bool
file_ignored (char const *name)
{
  return ((ignore_mode != IGNORE_MINIMAL
    && name[0] == '.'
    && (ignore_mode == IGNORE_DEFAULT || ! name[1 + (name[1] == '.')]))
   || (ignore_mode == IGNORE_DEFAULT
       && patterns_match (hide_patterns, name))
   || patterns_match (ignore_patterns, name));
}





static uintmax_t
unsigned_file_size (off_t size)
{
  return size + (size < 0) * ((uintmax_t) ((off_t) (! (! ((off_t) 0 < (off_t) -1)) ? (off_t) -1 : ~ (~ (off_t) 0 << (sizeof (off_t) * 8 - 1)))) - ((off_t) (! (! ((off_t) 0 < (off_t) -1)) ? (off_t) 0 : ((off_t) ~ (off_t) 0 < (off_t) -1) ? ~ (off_t) 0 : ~ (off_t) 0 << (sizeof (off_t) * 8 - 1))) + 1);
}





static void
clear_files (void)
{
  size_t i;

  for (i = 0; i < cwd_n_used; i++)
    {
      struct fileinfo *f = sorted_file[i];
      free (f->name);
      free (f->linkname);
      if (f->scontext != UNKNOWN_SECURITY_CONTEXT)
 freecon (f->scontext);
    }

  cwd_n_used = 0;
  any_has_acl = 0;
  inode_number_width = 0;
  block_size_width = 0;
  nlink_width = 0;
  owner_width = 0;
  group_width = 0;
  author_width = 0;
  scontext_width = 0;
  major_device_number_width = 0;
  minor_device_number_width = 0;
  file_size_width = 0;
}





static uintmax_t
gobble_file (char const *name, enum filetype type, ino_t inode,
      _Bool command_line_arg, char const *dirname)
{
  uintmax_t blocks = 0;
  struct fileinfo *f;



  ((! command_line_arg || inode == NOT_AN_INODE_NUMBER) ? (void) (0) : __assert_fail ("! command_line_arg || inode == NOT_AN_INODE_NUMBER", "ls.c", 2551, __PRETTY_FUNCTION__));

  if (cwd_n_used == cwd_n_alloc)
    {
      cwd_file = xnrealloc (cwd_file, cwd_n_alloc, 2 * sizeof *cwd_file);
      cwd_n_alloc *= 2;
    }

  f = &cwd_file[cwd_n_used];
  memset (f, '\0', sizeof *f);
  f->stat.st_ino = inode;
  f->filetype = type;

  if (command_line_arg
      || format_needs_stat



      || (type == directory && print_with_color)


      || ((print_inode || format_needs_type)
   && (type == symbolic_link || type == unknown)
   && (dereference == DEREF_ALWAYS
       || (command_line_arg && dereference != DEREF_NEVER)
       || color_symlink_as_referent || check_symlink_color))


      || (print_inode && inode == NOT_AN_INODE_NUMBER)
      || (format_needs_type
   && (type == unknown || command_line_arg



       || (type == normal && (indicator_style == classify




         || (print_with_color
      && is_colored (C_EXEC))
         )))))

    {

      char *absolute_name;
      _Bool do_deref;
      int err;

      if (name[0] == '/' || dirname[0] == 0)
 absolute_name = (char *) name;
      else
 {
   absolute_name = __builtin_alloca (strlen (name) + strlen (dirname) + 2);
   attach (absolute_name, dirname, name);
 }

      switch (dereference)
 {
 case DEREF_ALWAYS:
   err = stat (absolute_name, &f->stat);
   do_deref = 1;
   break;

 case DEREF_COMMAND_LINE_ARGUMENTS:
 case DEREF_COMMAND_LINE_SYMLINK_TO_DIR:
   if (command_line_arg)
     {
       _Bool need_lstat;
       err = stat (absolute_name, &f->stat);
       do_deref = 1;

       if (dereference == DEREF_COMMAND_LINE_ARGUMENTS)
  break;

       need_lstat = (err < 0
       ? (*__errno_location ()) == 2
       : ! ((((f->stat.st_mode)) & 0170000) == (0040000)));
       if (!need_lstat)
  break;





     }

 default:
   err = lstat (absolute_name, &f->stat);
   do_deref = 0;
   break;
 }

      if (err != 0)
 {



   file_failure (command_line_arg,
   gettext ("cannot access %s"), absolute_name);
   if (command_line_arg)
     return 0;

   f->name = xstrdup (name);
   cwd_n_used++;

   return 0;
 }

      f->stat_ok = 1;

      if (format == long_format || print_scontext)
 {
   _Bool have_acl = 0;
   int attr_len = (do_deref
     ? getfilecon (absolute_name, &f->scontext)
     : lgetfilecon (absolute_name, &f->scontext));
   err = (attr_len < 0);

   if (err == 0)
     have_acl = ! (strcmp ("unlabeled", f->scontext) == 0);
   else
     {
       f->scontext = UNKNOWN_SECURITY_CONTEXT;





       if ((*__errno_location ()) == 95 || (*__errno_location ()) == 61)
  err = 0;
     }

   if (err == 0 && ! have_acl && format == long_format)
     {
       int n = file_has_acl (absolute_name, &f->stat);
       err = (n < 0);
       have_acl = (0 < n);
     }

   f->have_acl = have_acl;
   any_has_acl |= have_acl;

   if (err)
     error (0, (*__errno_location ()), "%s", quotearg_colon (absolute_name));
 }

      if (((((f->stat.st_mode)) & 0170000) == (0120000))
   && (format == long_format || check_symlink_color))
 {
   char *linkname;
   struct stat linkstats;

   get_link_name (absolute_name, f, command_line_arg);
   linkname = make_link_name (absolute_name, f->linkname);



   if (linkname
       && (file_type <= indicator_style || check_symlink_color)
       && stat (linkname, &linkstats) == 0)
     {
       f->linkok = 1;




       if (!command_line_arg || format == long_format
    || !((((linkstats.st_mode)) & 0170000) == (0040000)))
  {


    f->linkmode = linkstats.st_mode;
  }
     }
   free (linkname);
 }




      if (((((f->stat.st_mode)) & 0170000) == (0120000)) && !check_symlink_color)
 f->linkok = 1;

      if (((((f->stat.st_mode)) & 0170000) == (0120000)))
 f->filetype = symbolic_link;
      else if (((((f->stat.st_mode)) & 0170000) == (0040000)))
 {
   if (command_line_arg & !immediate_dirs)
     f->filetype = arg_directory;
   else
     f->filetype = directory;
 }
      else
 f->filetype = normal;

      blocks = ((f->stat).st_blocks);
      if (format == long_format || print_block_size)
 {
   char buf[((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 1];
   int len = gnu_mbswidth (human_readable (blocks, buf, human_output_opts,
           512, output_block_size),
         0);
   if (block_size_width < len)
     block_size_width = len;
 }

      if (format == long_format)
 {
   if (print_owner)
     {
       int len = format_user_width (f->stat.st_uid);
       if (owner_width < len)
  owner_width = len;
     }

   if (print_group)
     {
       int len = format_group_width (f->stat.st_gid);
       if (group_width < len)
  group_width = len;
     }

   if (print_author)
     {
       int len = format_user_width (f->stat.st_uid);
       if (author_width < len)
  author_width = len;
     }
 }

      if (print_scontext)
 {
   int len = strlen (f->scontext);
   if (scontext_width < len)
     scontext_width = len;
 }

      if (format == long_format)
 {
   char b[(((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)];
   int b_len = strlen (umaxtostr (f->stat.st_nlink, b));
   if (nlink_width < b_len)
     nlink_width = b_len;

   if (((((f->stat.st_mode)) & 0170000) == (0020000)) || ((((f->stat.st_mode)) & 0170000) == (0060000)))
     {
       char buf[(((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)];
       int len = strlen (umaxtostr (gnu_dev_major (f->stat.st_rdev), buf));
       if (major_device_number_width < len)
  major_device_number_width = len;
       len = strlen (umaxtostr (gnu_dev_minor (f->stat.st_rdev), buf));
       if (minor_device_number_width < len)
  minor_device_number_width = len;
       len = major_device_number_width + 2 + minor_device_number_width;
       if (file_size_width < len)
  file_size_width = len;
     }
   else
     {
       char buf[((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 1];
       uintmax_t size = unsigned_file_size (f->stat.st_size);
       int len = gnu_mbswidth (human_readable (size, buf, human_output_opts,
        1, file_output_block_size),
      0);
       if (file_size_width < len)
  file_size_width = len;
     }
 }
    }

  if (print_inode)
    {
      char buf[(((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)];
      int len = strlen (umaxtostr (f->stat.st_ino, buf));
      if (inode_number_width < len)
 inode_number_width = len;
    }

  f->name = xstrdup (name);
  cwd_n_used++;

  return blocks;
}


static _Bool
is_directory (const struct fileinfo *f)
{
  return f->filetype == directory || f->filetype == arg_directory;
}





static void
get_link_name (char const *filename, struct fileinfo *f, _Bool command_line_arg)
{
  f->linkname = areadlink_with_size (filename, f->stat.st_size);
  if (f->linkname == ((void *)0))
    file_failure (command_line_arg, gettext ("cannot read symbolic link %s"),
    filename);
}






static char *
make_link_name (char const *name, char const *linkname)
{
  char *linkbuf;
  size_t bufsiz;

  if (!linkname)
    return ((void *)0);

  if (*linkname == '/')
    return xstrdup (linkname);



  linkbuf = strrchr (name, '/');
  if (linkbuf == 0)
    return xstrdup (linkname);

  bufsiz = linkbuf - name + 1;
  linkbuf = xmalloc (bufsiz + strlen (linkname) + 1);
  strncpy (linkbuf, name, bufsiz);
  strcpy (linkbuf + bufsiz, linkname);
  return linkbuf;
}




static _Bool
basename_is_dot_or_dotdot (const char *name)
{
  char const *base = last_component (name);
  return dot_or_dotdot (base);
}
# 2904 "ls.c"
static void
extract_dirs_from_files (char const *dirname, _Bool command_line_arg)
{
  size_t i;
  size_t j;
  _Bool ignore_dot_and_dot_dot = (dirname != ((void *)0));

  if (dirname && (!!active_dir_set))
    {



      queue_directory (((void *)0), dirname, 0);
    }



  for (i = cwd_n_used; i-- != 0; )
    {
      struct fileinfo *f = sorted_file[i];

      if (is_directory (f)
   && (! ignore_dot_and_dot_dot
       || ! basename_is_dot_or_dotdot (f->name)))
 {
   if (!dirname || f->name[0] == '/')
     queue_directory (f->name, f->linkname, command_line_arg);
   else
     {
       char *name = file_name_concat (dirname, f->name, ((void *)0));
       queue_directory (name, f->linkname, command_line_arg);
       free (name);
     }
   if (f->filetype == arg_directory)
     free (f->name);
 }
    }




  for (i = 0, j = 0; i < cwd_n_used; i++)
    {
      struct fileinfo *f = sorted_file[i];
      sorted_file[j] = f;
      j += (f->filetype != arg_directory);
    }
  cwd_n_used = j;
}




static jmp_buf failed_strcoll;

static int
xstrcoll (char const *a, char const *b)
{
  int diff;
  (*__errno_location ()) = 0;
  diff = strcoll (a, b);
  if ((*__errno_location ()))
    {
      error (0, (*__errno_location ()), gettext ("cannot compare file names %s and %s"),
      quote_n (0, a), quote_n (1, b));
      set_exit_status (0);
      longjmp (failed_strcoll, 1);
    }
  return diff;
}



typedef void const *V;
typedef int (*qsortFunc)(V a, V b);
# 3025 "ls.c"
static inline int
cmp_ctime (struct fileinfo const *a, struct fileinfo const *b,
    int (*cmp) (char const *, char const *))
{
  int diff = timespec_cmp (get_stat_ctime (&b->stat),
      get_stat_ctime (&a->stat));
  return diff ? diff : cmp (a->name, b->name);
}

static inline int
cmp_mtime (struct fileinfo const *a, struct fileinfo const *b,
    int (*cmp) (char const *, char const *))
{
  int diff = timespec_cmp (get_stat_mtime (&b->stat),
      get_stat_mtime (&a->stat));
  return diff ? diff : cmp (a->name, b->name);
}

static inline int
cmp_atime (struct fileinfo const *a, struct fileinfo const *b,
    int (*cmp) (char const *, char const *))
{
  int diff = timespec_cmp (get_stat_atime (&b->stat),
      get_stat_atime (&a->stat));
  return diff ? diff : cmp (a->name, b->name);
}

static inline int
cmp_size (struct fileinfo const *a, struct fileinfo const *b,
   int (*cmp) (char const *, char const *))
{
  int diff = ((b->stat.st_size) < (a->stat.st_size) ? -1 : (b->stat.st_size) > (a->stat.st_size));
  return diff ? diff : cmp (a->name, b->name);
}

static inline int
cmp_name (struct fileinfo const *a, struct fileinfo const *b,
   int (*cmp) (char const *, char const *))
{
  return cmp (a->name, b->name);
}




static inline int
cmp_extension (struct fileinfo const *a, struct fileinfo const *b,
        int (*cmp) (char const *, char const *))
{
  char const *base1 = strrchr (a->name, '.');
  char const *base2 = strrchr (b->name, '.');
  int diff = cmp (base1 ? base1 : "", base2 ? base2 : "");
  return diff ? diff : cmp (a->name, b->name);
}

static int xstrcoll_ctime (V a, V b) { return cmp_ctime (a, b, xstrcoll); } static int strcmp_ctime (V a, V b) { return cmp_ctime (a, b, strcmp); } static int rev_xstrcoll_ctime (V a, V b) { return cmp_ctime (b, a, xstrcoll); } static int rev_strcmp_ctime (V a, V b) { return cmp_ctime (b, a, strcmp); } static int xstrcoll_df_ctime (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_ctime (a, b, xstrcoll); } static int strcmp_df_ctime (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_ctime (a, b, strcmp); } static int rev_xstrcoll_df_ctime (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_ctime (b, a, xstrcoll); } static int rev_strcmp_df_ctime (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_ctime (b, a, strcmp); }
static int xstrcoll_mtime (V a, V b) { return cmp_mtime (a, b, xstrcoll); } static int strcmp_mtime (V a, V b) { return cmp_mtime (a, b, strcmp); } static int rev_xstrcoll_mtime (V a, V b) { return cmp_mtime (b, a, xstrcoll); } static int rev_strcmp_mtime (V a, V b) { return cmp_mtime (b, a, strcmp); } static int xstrcoll_df_mtime (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_mtime (a, b, xstrcoll); } static int strcmp_df_mtime (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_mtime (a, b, strcmp); } static int rev_xstrcoll_df_mtime (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_mtime (b, a, xstrcoll); } static int rev_strcmp_df_mtime (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_mtime (b, a, strcmp); }
static int xstrcoll_atime (V a, V b) { return cmp_atime (a, b, xstrcoll); } static int strcmp_atime (V a, V b) { return cmp_atime (a, b, strcmp); } static int rev_xstrcoll_atime (V a, V b) { return cmp_atime (b, a, xstrcoll); } static int rev_strcmp_atime (V a, V b) { return cmp_atime (b, a, strcmp); } static int xstrcoll_df_atime (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_atime (a, b, xstrcoll); } static int strcmp_df_atime (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_atime (a, b, strcmp); } static int rev_xstrcoll_df_atime (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_atime (b, a, xstrcoll); } static int rev_strcmp_df_atime (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_atime (b, a, strcmp); }
static int xstrcoll_size (V a, V b) { return cmp_size (a, b, xstrcoll); } static int strcmp_size (V a, V b) { return cmp_size (a, b, strcmp); } static int rev_xstrcoll_size (V a, V b) { return cmp_size (b, a, xstrcoll); } static int rev_strcmp_size (V a, V b) { return cmp_size (b, a, strcmp); } static int xstrcoll_df_size (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_size (a, b, xstrcoll); } static int strcmp_df_size (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_size (a, b, strcmp); } static int rev_xstrcoll_df_size (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_size (b, a, xstrcoll); } static int rev_strcmp_df_size (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_size (b, a, strcmp); }
static int xstrcoll_name (V a, V b) { return cmp_name (a, b, xstrcoll); } static int strcmp_name (V a, V b) { return cmp_name (a, b, strcmp); } static int rev_xstrcoll_name (V a, V b) { return cmp_name (b, a, xstrcoll); } static int rev_strcmp_name (V a, V b) { return cmp_name (b, a, strcmp); } static int xstrcoll_df_name (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_name (a, b, xstrcoll); } static int strcmp_df_name (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_name (a, b, strcmp); } static int rev_xstrcoll_df_name (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_name (b, a, xstrcoll); } static int rev_strcmp_df_name (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_name (b, a, strcmp); }
static int xstrcoll_extension (V a, V b) { return cmp_extension (a, b, xstrcoll); } static int strcmp_extension (V a, V b) { return cmp_extension (a, b, strcmp); } static int rev_xstrcoll_extension (V a, V b) { return cmp_extension (b, a, xstrcoll); } static int rev_strcmp_extension (V a, V b) { return cmp_extension (b, a, strcmp); } static int xstrcoll_df_extension (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_extension (a, b, xstrcoll); } static int strcmp_df_extension (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_extension (a, b, strcmp); } static int rev_xstrcoll_df_extension (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_extension (b, a, xstrcoll); } static int rev_strcmp_df_extension (V a, V b) { do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_extension (b, a, strcmp); }
# 3096 "ls.c"
static inline int
cmp_version (struct fileinfo const *a, struct fileinfo const *b)
{
  return strverscmp (a->name, b->name);
}

static int xstrcoll_version (V a, V b)
{ return cmp_version (a, b); }
static int rev_xstrcoll_version (V a, V b)
{ return cmp_version (b, a); }
static int xstrcoll_df_version (V a, V b)
{ do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_version (a, b); }
static int rev_xstrcoll_df_version (V a, V b)
{ do { _Bool a_is_dir = is_directory ((struct fileinfo const *) a); _Bool b_is_dir = is_directory ((struct fileinfo const *) b); if (a_is_dir && !b_is_dir) return -1; if (!a_is_dir && b_is_dir) return 1; } while (0); return cmp_version (b, a); }
# 3134 "ls.c"
static qsortFunc sort_functions[][2][2][2] =
  {
    { { { xstrcoll_name, xstrcoll_df_name }, { rev_xstrcoll_name, rev_xstrcoll_df_name }, }, { { strcmp_name, strcmp_df_name }, { rev_strcmp_name, rev_strcmp_df_name }, } },
    { { { xstrcoll_extension, xstrcoll_df_extension }, { rev_xstrcoll_extension, rev_xstrcoll_df_extension }, }, { { strcmp_extension, strcmp_df_extension }, { rev_strcmp_extension, rev_strcmp_df_extension }, } },
    { { { xstrcoll_size, xstrcoll_df_size }, { rev_xstrcoll_size, rev_xstrcoll_df_size }, }, { { strcmp_size, strcmp_df_size }, { rev_strcmp_size, rev_strcmp_df_size }, } },

    {
      {
        { xstrcoll_version, xstrcoll_df_version },
        { rev_xstrcoll_version, rev_xstrcoll_df_version },
      },





      {
        { ((void *)0), ((void *)0) },
        { ((void *)0), ((void *)0) },
      }
    },


    { { { xstrcoll_mtime, xstrcoll_df_mtime }, { rev_xstrcoll_mtime, rev_xstrcoll_df_mtime }, }, { { strcmp_mtime, strcmp_df_mtime }, { rev_strcmp_mtime, rev_strcmp_df_mtime }, } },
    { { { xstrcoll_ctime, xstrcoll_df_ctime }, { rev_xstrcoll_ctime, rev_xstrcoll_df_ctime }, }, { { strcmp_ctime, strcmp_df_ctime }, { rev_strcmp_ctime, rev_strcmp_df_ctime }, } },
    { { { xstrcoll_atime, xstrcoll_df_atime }, { rev_xstrcoll_atime, rev_xstrcoll_df_atime }, }, { { strcmp_atime, strcmp_df_atime }, { rev_strcmp_atime, rev_strcmp_df_atime }, } }
  };
# 3170 "ls.c"
extern int (* verify_function__ (void)) [(!!sizeof (struct { unsigned int verify_error_if_negative_size__: ((sizeof (sort_functions) / sizeof *(sort_functions)) == sort_numtypes + time_numtypes - 1) ? 1 : -1; }))];




static void
initialize_ordering_vector (void)
{
  size_t i;
  for (i = 0; i < cwd_n_used; i++)
    sorted_file[i] = &cwd_file[i];
}



static void
sort_files (void)
{
  _Bool use_strcmp;

  if (sorted_file_alloc < cwd_n_used + cwd_n_used / 2)
    {
      free (sorted_file);
      sorted_file = xnmalloc (cwd_n_used, 3 * sizeof *sorted_file);
      sorted_file_alloc = 3 * cwd_n_used;
    }

  initialize_ordering_vector ();

  if (sort_type == sort_none)
    return;






  if (! _setjmp (failed_strcoll))
    use_strcmp = 0;
  else
    {
      use_strcmp = 1;
      ((sort_type != sort_version) ? (void) (0) : __assert_fail ("sort_type != sort_version", "ls.c", 3212, __PRETTY_FUNCTION__));
      initialize_ordering_vector ();
    }


  mpsort ((void const **) sorted_file, cwd_n_used,
   sort_functions[sort_type + (sort_type == sort_time ? time_type : 0)]
   [use_strcmp][sort_reverse]
   [directories_first]);
}



static void
print_current_files (void)
{
  size_t i;

  switch (format)
    {
    case one_per_line:
      for (i = 0; i < cwd_n_used; i++)
 {
   print_file_name_and_frills (sorted_file[i]);
   putchar_unlocked ('\n');
 }
      break;

    case many_per_line:
      print_many_per_line ();
      break;

    case horizontal:
      print_horizontal ();
      break;

    case with_commas:
      print_with_commas ();
      break;

    case long_format:
      for (i = 0; i < cwd_n_used; i++)
 {
   print_long_format (sorted_file[i]);
   do {putchar_unlocked (('\n')); ++dired_pos;} while (0);
 }
      break;
    }
}




static int
long_time_expected_width (void)
{
  static int width = -1;

  if (width < 0)
    {
      time_t epoch = 0;
      struct tm const *tm = localtime (&epoch);
      char buf[TIME_STAMP_LEN_MAXIMUM + 1];
# 3283 "ls.c"
      if (tm)
 {
   size_t len =
     nstrftime (buf, sizeof buf, long_time_format[0], tm, 0, 0);
   if (len != 0)
     width = mbsnwidth (buf, len, 0);
 }

      if (width < 0)
 width = 0;
    }

  return width;
}



static void
get_current_time (void)
{

  {
    struct timespec timespec;
    if (clock_gettime (0, &timespec) == 0)
      {
 current_time = timespec.tv_sec;
 current_time_ns = timespec.tv_nsec;
 return;
      }
  }
# 3322 "ls.c"
  {
    struct timeval timeval;
    gettimeofday (&timeval, ((void *)0));
    current_time = timeval.tv_sec;
    current_time_ns = timeval.tv_usec * 1000 + 999;
  }




}




static void
format_user_or_group (char const *name, unsigned long int id, int width)
{
  size_t len;

  if (name)
    {
      int width_gap = width - gnu_mbswidth (name, 0);
      int pad = (((0)>(width_gap))?(0):(width_gap));
      fputs_unlocked (name,stdout);
      len = strlen (name) + pad;

      do
 putchar_unlocked (' ');
      while (pad--);
    }
  else
    {
      printf ("%*lu ", width, id);
      len = width;
    }

  dired_pos += len + 1;
}




static void
format_user (uid_t u, int width, _Bool stat_ok)
{
  format_user_or_group (! stat_ok ? "?" :
   (numeric_ids ? ((void *)0) : getuser (u)), u, width);
}



static void
format_group (gid_t g, int width, _Bool stat_ok)
{
  format_user_or_group (! stat_ok ? "?" :
   (numeric_ids ? ((void *)0) : getgroup (g)), g, width);
}



static int
format_user_or_group_width (char const *name, unsigned long int id)
{
  if (name)
    {
      int len = gnu_mbswidth (name, 0);
      return (((0)>(len))?(0):(len));
    }
  else
    {
      char buf[(((sizeof (unsigned long int) * 8 - (! ((__typeof__ (unsigned long int)) 0 < (__typeof__ (unsigned long int)) -1))) * 146 / 485 + (! ((__typeof__ (unsigned long int)) 0 < (__typeof__ (unsigned long int)) -1)) + 1) + 1)];
      sprintf (buf, "%lu", id);
      return strlen (buf);
    }
}



static int
format_user_width (uid_t u)
{
  return format_user_or_group_width (numeric_ids ? ((void *)0) : getuser (u), u);
}



static int
format_group_width (gid_t g)
{
  return format_user_or_group_width (numeric_ids ? ((void *)0) : getgroup (g), g);
}




static void
print_long_format (const struct fileinfo *f)
{
  char modebuf[12];
  char buf
    [((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 1
     + ((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 1
     + sizeof (modebuf) - 1 + 1
     + (((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)
     + ((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 2
     + ((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 1
     + TIME_STAMP_LEN_MAXIMUM + 1
     ];
  size_t s;
  char *p;
  time_t when;
  int when_ns;
  struct timespec when_timespec;
  struct tm *when_local;



  if (f->stat_ok)
    filemodestring (&f->stat, modebuf);
  else
    {
      modebuf[0] = filetype_letter[f->filetype];
      memset (modebuf + 1, '?', 10);
      modebuf[11] = '\0';
    }
  if (! any_has_acl)
    modebuf[10] = '\0';
  else if (f->have_acl)
    modebuf[10] = '+';

  switch (time_type)
    {
    case time_ctime:
      when_timespec = get_stat_ctime (&f->stat);
      break;
    case time_mtime:
      when_timespec = get_stat_mtime (&f->stat);
      break;
    case time_atime:
      when_timespec = get_stat_atime (&f->stat);
      break;
    default:
      abort ();
    }

  when = when_timespec.tv_sec;
  when_ns = when_timespec.tv_nsec;

  p = buf;

  if (print_inode)
    {
      char hbuf[(((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)];
      sprintf (p, "%*s ", inode_number_width,
        (f->stat.st_ino == NOT_AN_INODE_NUMBER
  ? "?"
  : umaxtostr (f->stat.st_ino, hbuf)));


      p += strlen (p);
    }

  if (print_block_size)
    {
      char hbuf[((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 1];
      char const *blocks =
 (! f->stat_ok
  ? "?"
  : human_readable (((f->stat).st_blocks), hbuf, human_output_opts,
      512, output_block_size));
      int pad;
      for (pad = block_size_width - gnu_mbswidth (blocks, 0); 0 < pad; pad--)
 *p++ = ' ';
      while ((*p++ = *blocks++))
 continue;
      p[-1] = ' ';
    }



  {
    char hbuf[(((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)];
    sprintf (p, "%s %*s ", modebuf, nlink_width,
      ! f->stat_ok ? "?" : umaxtostr (f->stat.st_nlink, hbuf));
  }



  p += strlen (p);

  do { if (dired) do {fputs_unlocked ("  ",stdout); dired_pos += sizeof ("  ") - 1;} while (0); } while (0);

  if (print_owner | print_group | print_author | print_scontext)
    {
      do {fputs_unlocked (buf,stdout); dired_pos += p - buf;} while (0);

      if (print_owner)
 format_user (f->stat.st_uid, owner_width, f->stat_ok);

      if (print_group)
 format_group (f->stat.st_gid, group_width, f->stat_ok);

      if (print_author)
 format_user (f->stat.st_uid, author_width, f->stat_ok);

      if (print_scontext)
 format_user_or_group (f->scontext, 0, scontext_width);

      p = buf;
    }

  if (f->stat_ok
      && (((((f->stat.st_mode)) & 0170000) == (0020000)) || ((((f->stat.st_mode)) & 0170000) == (0060000))))
    {
      char majorbuf[(((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)];
      char minorbuf[(((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)];
      int blanks_width = (file_size_width
     - (major_device_number_width + 2
        + minor_device_number_width));
      sprintf (p, "%*s, %*s ",
        major_device_number_width + (((0)>(blanks_width))?(0):(blanks_width)),
        umaxtostr (gnu_dev_major (f->stat.st_rdev), majorbuf),
        minor_device_number_width,
        umaxtostr (gnu_dev_minor (f->stat.st_rdev), minorbuf));
      p += file_size_width + 1;
    }
  else
    {
      char hbuf[((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 1];
      char const *size =
 (! f->stat_ok
  ? "?"
  : human_readable (unsigned_file_size (f->stat.st_size),
      hbuf, human_output_opts, 1, file_output_block_size));
      int pad;
      for (pad = file_size_width - gnu_mbswidth (size, 0); 0 < pad; pad--)
 *p++ = ' ';
      while ((*p++ = *size++))
 continue;
      p[-1] = ' ';
    }

  when_local = localtime (&when_timespec.tv_sec);
  s = 0;
  *p = '\1';

  if (f->stat_ok && when_local)
    {
      time_t six_months_ago;
      _Bool recent;
      char const *fmt;




      if (current_time < when
   || (current_time == when && current_time_ns < when_ns))
 {




   get_current_time ();
 }





      six_months_ago = current_time - 31556952 / 2;
      recent = (six_months_ago <= when
  && (when < current_time
      || (when == current_time && when_ns <= current_time_ns)));
      fmt = long_time_format[recent];

      s = nstrftime (p, TIME_STAMP_LEN_MAXIMUM + 1, fmt,
       when_local, 0, when_ns);
    }

  if (s || !*p)
    {
      p += s;
      *p++ = ' ';


      *p = '\0';
    }
  else
    {


      char hbuf[(((sizeof (intmax_t) * 8 - (! ((__typeof__ (intmax_t)) 0 < (__typeof__ (intmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (intmax_t)) 0 < (__typeof__ (intmax_t)) -1)) + 1) + 1)];
      sprintf (p, "%*s ", long_time_expected_width (),
        (! f->stat_ok
  ? "?"
  : ((! ((time_t) 0 < (time_t) -1))
     ? imaxtostr (when, hbuf)
     : umaxtostr (when, hbuf))));
      p += strlen (p);
    }

  do {fputs_unlocked (buf,stdout); dired_pos += p - buf;} while (0);
  print_name_with_quoting (f->name, ((color_symlink_as_referent & (f)->linkok) ? (f)->linkmode : (f)->stat.st_mode), f->linkok,
      f->stat_ok, f->filetype, &dired_obstack);

  if (f->filetype == symbolic_link)
    {
      if (f->linkname)
 {
   do {fputs_unlocked (" -> ",stdout); dired_pos += sizeof (" -> ") - 1;} while (0);
   print_name_with_quoting (f->linkname, f->linkmode, f->linkok - 1,
       f->stat_ok, f->filetype, ((void *)0));
   if (indicator_style != none)
     print_type_indicator (1, f->linkmode, unknown);
 }
    }
  else if (indicator_style != none)
    print_type_indicator (f->stat_ok, f->stat.st_mode, f->filetype);
}







static size_t
quote_name (FILE *out, const char *name, struct quoting_options const *options,
     size_t *width)
{
  char smallbuf[8192];
  size_t len = quotearg_buffer (smallbuf, sizeof smallbuf, name, -1, options);
  char *buf;
  size_t displayed_width ;

  if (len < sizeof smallbuf)
    buf = smallbuf;
  else
    {
      buf = __builtin_alloca (len + 1);
      quotearg_buffer (buf, len + 1, name, -1, options);
    }

  if (qmark_funny_chars)
    {

      if ((__ctype_get_mb_cur_max ()) > 1)
 {
   char const *p = buf;
   char const *plimit = buf + len;
   char *q = buf;
   displayed_width = 0;

   while (p < plimit)
     switch (*p)
       {
  case ' ': case '!': case '"': case '#': case '%':
  case '&': case '\'': case '(': case ')': case '*':
  case '+': case ',': case '-': case '.': case '/':
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
  case ':': case ';': case '<': case '=': case '>':
  case '?':
  case 'A': case 'B': case 'C': case 'D': case 'E':
  case 'F': case 'G': case 'H': case 'I': case 'J':
  case 'K': case 'L': case 'M': case 'N': case 'O':
  case 'P': case 'Q': case 'R': case 'S': case 'T':
  case 'U': case 'V': case 'W': case 'X': case 'Y':
  case 'Z':
  case '[': case '\\': case ']': case '^': case '_':
  case 'a': case 'b': case 'c': case 'd': case 'e':
  case 'f': case 'g': case 'h': case 'i': case 'j':
  case 'k': case 'l': case 'm': case 'n': case 'o':
  case 'p': case 'q': case 'r': case 's': case 't':
  case 'u': case 'v': case 'w': case 'x': case 'y':
  case 'z': case '{': case '|': case '}': case '~':

    *q++ = *p++;
    displayed_width += 1;
    break;
  default:



    {
      mbstate_t mbstate = { 0, };
      do
        {
   wchar_t wc;
   size_t bytes;
   int w;

   bytes = mbrtowc (&wc, p, plimit - p, &mbstate);

   if (bytes == (size_t) -1)
     {



       p++;
       *q++ = '?';
       displayed_width += 1;
       break;
     }

   if (bytes == (size_t) -2)
     {



       p = plimit;
       *q++ = '?';
       displayed_width += 1;
       break;
     }

   if (bytes == 0)

     bytes = 1;

   w = wcwidth (wc);
   if (w >= 0)
     {


       for (; bytes > 0; --bytes)
         *q++ = *p++;
       displayed_width += w;
     }
   else
     {



       p += bytes;
       *q++ = '?';
       displayed_width += 1;
     }
        }
      while (! mbsinit (&mbstate));
    }
    break;
       }


   len = q - buf;
 }
      else

 {
   char *p = buf;
   char const *plimit = buf + len;

   while (p < plimit)
     {
       if (! ((*__ctype_b_loc ())[(int) ((to_uchar (*p)))] & (unsigned short int) _ISprint))
  *p = '?';
       p++;
     }
   displayed_width = len;
 }
    }
  else if (width != ((void *)0))
    {

      if ((__ctype_get_mb_cur_max ()) > 1)
 displayed_width = mbsnwidth (buf, len, 0);
      else

 {
   char const *p = buf;
   char const *plimit = buf + len;

   displayed_width = 0;
   while (p < plimit)
     {
       if (((*__ctype_b_loc ())[(int) ((to_uchar (*p)))] & (unsigned short int) _ISprint))
  displayed_width++;
       p++;
     }
 }
    }

  if (out != ((void *)0))
    fwrite_unlocked (buf,1,len,out);
  if (width != ((void *)0))
    *width = displayed_width;
  return len;
}

static void
print_name_with_quoting (const char *p, mode_t mode, int linkok,
    _Bool stat_ok, enum filetype type,
    struct obstack *stack)
{
  if (print_with_color)
    print_color_indicator (p, mode, linkok, stat_ok, type);

  if (stack)
    do { if (dired) __extension__ ({ struct obstack *__o = (stack); int __len = (sizeof (dired_pos)); if (__o->next_free + __len > __o->chunk_limit) _obstack_newchunk (__o, __len); memcpy (__o->next_free, &dired_pos, __len); __o->next_free += __len; (void) 0; }); } while (0);

  dired_pos += quote_name (stdout, p, filename_quoting_options, ((void *)0));

  if (stack)
    do { if (dired) __extension__ ({ struct obstack *__o = (stack); int __len = (sizeof (dired_pos)); if (__o->next_free + __len > __o->chunk_limit) _obstack_newchunk (__o, __len); memcpy (__o->next_free, &dired_pos, __len); __o->next_free += __len; (void) 0; }); } while (0);

  if (print_with_color)
    {
      process_signals ();
      prep_non_filename_text ();
    }
}

static void
prep_non_filename_text (void)
{
  if (color_indicator[C_END].string != ((void *)0))
    put_indicator (&color_indicator[C_END]);
  else
    {
      put_indicator (&color_indicator[C_LEFT]);
      put_indicator (&color_indicator[C_NORM]);
      put_indicator (&color_indicator[C_RIGHT]);
    }
}





static void
print_file_name_and_frills (const struct fileinfo *f)
{
  char buf[(((((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 1)>((((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)))?(((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 1):((((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)))];

  if (print_inode)
    printf ("%*s ", format == with_commas ? 0 : inode_number_width,
     umaxtostr (f->stat.st_ino, buf));

  if (print_block_size)
    printf ("%*s ", format == with_commas ? 0 : block_size_width,
     human_readable (((f->stat).st_blocks), buf, human_output_opts,
       512, output_block_size));

  if (print_scontext)
    printf ("%*s ", format == with_commas ? 0 : scontext_width, f->scontext);

  print_name_with_quoting (f->name, ((color_symlink_as_referent & (f)->linkok) ? (f)->linkmode : (f)->stat.st_mode), f->linkok,
      f->stat_ok, f->filetype, ((void *)0));

  if (indicator_style != none)
    print_type_indicator (f->stat_ok, f->stat.st_mode, f->filetype);
}



static char
get_type_indicator (_Bool stat_ok, mode_t mode, enum filetype type)
{
  char c;

  if (stat_ok ? ((((mode)) & 0170000) == (0100000)) : type == normal)
    {
      if (stat_ok && indicator_style == classify && (mode & (0100 | (0100 >> 3) | ((0100 >> 3) >> 3))))
 c = '*';
      else
 c = 0;
    }
  else
    {
      if (stat_ok ? ((((mode)) & 0170000) == (0040000)) : type == directory || type == arg_directory)
 c = '/';
      else if (indicator_style == slash)
 c = 0;
      else if (stat_ok ? ((((mode)) & 0170000) == (0120000)) : type == symbolic_link)
 c = '@';
      else if (stat_ok ? ((((mode)) & 0170000) == (0010000)) : type == fifo)
 c = '|';
      else if (stat_ok ? ((((mode)) & 0170000) == (0140000)) : type == sock)
 c = '=';
      else if (stat_ok && 0)
 c = '>';
      else
 c = 0;
    }
  return c;
}

static void
print_type_indicator (_Bool stat_ok, mode_t mode, enum filetype type)
{
  char c = get_type_indicator (stat_ok, mode, type);
  if (c)
    do {putchar_unlocked ((c)); ++dired_pos;} while (0);
}

static void
print_color_indicator (const char *name, mode_t mode, int linkok,
         _Bool stat_ok, enum filetype filetype)
{
  int type;
  struct color_ext_type *ext;
  size_t len;



  if (linkok == -1 && color_indicator[C_MISSING].string != ((void *)0))
    type = C_MISSING;
  else if (! stat_ok)
    {
      static enum indicator_no filetype_indicator[] = { C_ORPHAN, C_FIFO, C_CHR, C_DIR, C_BLK, C_FILE, C_LINK, C_SOCK, C_FILE, C_DIR };
      type = filetype_indicator[filetype];
    }
  else
    {
      if (((((mode)) & 0170000) == (0100000)))
 {
   type = C_FILE;
   if ((mode & 04000) != 0)
     type = C_SETUID;
   else if ((mode & 02000) != 0)
     type = C_SETGID;
   else if ((mode & (0100 | (0100 >> 3) | ((0100 >> 3) >> 3))) != 0)
     type = C_EXEC;
 }
      else if (((((mode)) & 0170000) == (0040000)))
 {
   if ((mode & 01000) && (mode & ((0200 >> 3) >> 3)))
     type = C_STICKY_OTHER_WRITABLE;
   else if ((mode & ((0200 >> 3) >> 3)) != 0)
     type = C_OTHER_WRITABLE;
   else if ((mode & 01000) != 0)
     type = C_STICKY;
   else
     type = C_DIR;
 }
      else if (((((mode)) & 0170000) == (0120000)))
 type = ((!linkok && color_indicator[C_ORPHAN].string)
  ? C_ORPHAN : C_LINK);
      else if (((((mode)) & 0170000) == (0010000)))
 type = C_FIFO;
      else if (((((mode)) & 0170000) == (0140000)))
 type = C_SOCK;
      else if (((((mode)) & 0170000) == (0060000)))
 type = C_BLK;
      else if (((((mode)) & 0170000) == (0020000)))
 type = C_CHR;
      else if (0)
 type = C_DOOR;
      else
 {

   type = C_ORPHAN;
 }
    }


  ext = ((void *)0);
  if (type == C_FILE)
    {


      len = strlen (name);
      name += len;
      for (ext = color_ext_list; ext != ((void *)0); ext = ext->next)
 {
   if (ext->ext.len <= len
       && strncmp (name - ext->ext.len, ext->ext.string,
     ext->ext.len) == 0)
     break;
 }
    }

  put_indicator (&color_indicator[C_LEFT]);
  put_indicator (ext ? &(ext->seq) : &color_indicator[type]);
  put_indicator (&color_indicator[C_RIGHT]);
}


static void
put_indicator (const struct bin_str *ind)
{
  size_t i;
  const char *p;

  p = ind->string;

  for (i = ind->len; i != 0; --i)
    putchar_unlocked (*(p++));
}

static size_t
length_of_file_name_and_frills (const struct fileinfo *f)
{
  size_t len = 0;
  size_t name_width;
  char buf[(((((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 1)>((((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)))?(((2 * sizeof (uintmax_t) * 8 * 146 / 485 + 1) * (16 + 1) - 16 + 1 + 3) + 1):((((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)))];

  if (print_inode)
    len += 1 + (format == with_commas
  ? strlen (umaxtostr (f->stat.st_ino, buf))
  : inode_number_width);

  if (print_block_size)
    len += 1 + (format == with_commas
  ? strlen (human_readable (((f->stat).st_blocks), buf,
       human_output_opts, 512,
       output_block_size))
  : block_size_width);

  if (print_scontext)
    len += 1 + (format == with_commas ? strlen (f->scontext) : scontext_width);

  quote_name (((void *)0), f->name, filename_quoting_options, &name_width);
  len += name_width;

  if (indicator_style != none)
    {
      char c = get_type_indicator (f->stat_ok, f->stat.st_mode, f->filetype);
      len += (c != 0);
    }

  return len;
}

static void
print_many_per_line (void)
{
  size_t row;
  size_t cols = calculate_columns (1);
  struct column_info const *line_fmt = &column_info[cols - 1];



  size_t rows = cwd_n_used / cols + (cwd_n_used % cols != 0);

  for (row = 0; row < rows; row++)
    {
      size_t col = 0;
      size_t filesno = row;
      size_t pos = 0;


      while (1)
 {
   struct fileinfo const *f = sorted_file[filesno];
   size_t name_length = length_of_file_name_and_frills (f);
   size_t max_name_length = line_fmt->col_arr[col++];
   print_file_name_and_frills (f);

   filesno += rows;
   if (filesno >= cwd_n_used)
     break;

   indent (pos + name_length, pos + max_name_length);
   pos += max_name_length;
 }
      putchar_unlocked ('\n');
    }
}

static void
print_horizontal (void)
{
  size_t filesno;
  size_t pos = 0;
  size_t cols = calculate_columns (0);
  struct column_info const *line_fmt = &column_info[cols - 1];
  struct fileinfo const *f = sorted_file[0];
  size_t name_length = length_of_file_name_and_frills (f);
  size_t max_name_length = line_fmt->col_arr[0];


  print_file_name_and_frills (f);


  for (filesno = 1; filesno < cwd_n_used; ++filesno)
    {
      size_t col = filesno % cols;

      if (col == 0)
 {
   putchar_unlocked ('\n');
   pos = 0;
 }
      else
 {
   indent (pos + name_length, pos + max_name_length);
   pos += max_name_length;
 }

      f = sorted_file[filesno];
      print_file_name_and_frills (f);

      name_length = length_of_file_name_and_frills (f);
      max_name_length = line_fmt->col_arr[col];
    }
  putchar_unlocked ('\n');
}

static void
print_with_commas (void)
{
  size_t filesno;
  size_t pos = 0;

  for (filesno = 0; filesno < cwd_n_used; filesno++)
    {
      struct fileinfo const *f = sorted_file[filesno];
      size_t len = length_of_file_name_and_frills (f);

      if (filesno != 0)
 {
   char separator;

   if (pos + len + 2 < line_length)
     {
       pos += 2;
       separator = ' ';
     }
   else
     {
       pos = 0;
       separator = '\n';
     }

   putchar_unlocked (',');
   putchar_unlocked (separator);
 }

      print_file_name_and_frills (f);
      pos += len;
    }
  putchar_unlocked ('\n');
}




static void
indent (size_t from, size_t to)
{
  while (from < to)
    {
      if (tabsize != 0 && to / tabsize > (from + 1) / tabsize)
 {
   putchar_unlocked ('\t');
   from += tabsize - from % tabsize;
 }
      else
 {
   putchar_unlocked (' ');
   from++;
 }
    }
}





static void
attach (char *dest, const char *dirname, const char *name)
{
  const char *dirnamep = dirname;


  if (dirname[0] != '.' || dirname[1] != 0)
    {
      while (*dirnamep)
 *dest++ = *dirnamep++;

      if (dirnamep > dirname && dirnamep[-1] != '/')
 *dest++ = '/';
    }
  while (*name)
    *dest++ = *name++;
  *dest = 0;
}





static void
init_column_info (void)
{
  size_t i;
  size_t max_cols = (((max_idx)<(cwd_n_used))?(max_idx):(cwd_n_used));


  static size_t column_info_alloc;

  if (column_info_alloc < max_cols)
    {
      size_t new_column_info_alloc;
      size_t *p;

      if (max_cols < max_idx / 2)
 {





   column_info = xnrealloc (column_info, max_cols,
       2 * sizeof *column_info);
   new_column_info_alloc = 2 * max_cols;
 }
      else
 {
   column_info = xnrealloc (column_info, max_idx, sizeof *column_info);
   new_column_info_alloc = max_idx;
 }





      {
 size_t column_info_growth = new_column_info_alloc - column_info_alloc;
 size_t s = column_info_alloc + 1 + new_column_info_alloc;
 size_t t = s * column_info_growth;
 if (s < new_column_info_alloc || t / column_info_growth != s)
   xalloc_die ();
 p = xnmalloc (t / 2, sizeof *p);
      }


      for (i = column_info_alloc; i < new_column_info_alloc; i++)
 {
   column_info[i].col_arr = p;
   p += i + 1;
 }

      column_info_alloc = new_column_info_alloc;
    }

  for (i = 0; i < max_cols; ++i)
    {
      size_t j;

      column_info[i].valid_len = 1;
      column_info[i].line_len = (i + 1) * 3;
      for (j = 0; j <= i; ++j)
 column_info[i].col_arr[j] = 3;
    }
}




static size_t
calculate_columns (_Bool by_columns)
{
  size_t filesno;
  size_t cols;




  size_t max_cols = (((max_idx)<(cwd_n_used))?(max_idx):(cwd_n_used));

  init_column_info ();


  for (filesno = 0; filesno < cwd_n_used; ++filesno)
    {
      struct fileinfo const *f = sorted_file[filesno];
      size_t name_length = length_of_file_name_and_frills (f);
      size_t i;

      for (i = 0; i < max_cols; ++i)
 {
   if (column_info[i].valid_len)
     {
       size_t idx = (by_columns
       ? filesno / ((cwd_n_used + i) / (i + 1))
       : filesno % (i + 1));
       size_t real_length = name_length + (idx == i ? 0 : 2);

       if (column_info[i].col_arr[idx] < real_length)
  {
    column_info[i].line_len += (real_length
           - column_info[i].col_arr[idx]);
    column_info[i].col_arr[idx] = real_length;
    column_info[i].valid_len = (column_info[i].line_len
           < line_length);
  }
     }
 }
    }


  for (cols = max_cols; 1 < cols; --cols)
    {
      if (column_info[cols - 1].valid_len)
 break;
    }

  return cols;
}

void
usage (int status)
{
  if (status != 0)
    fprintf (stderr, gettext ("Try `%s --help' for more information.\n"),
      program_name);
  else
    {
      printf (gettext ("Usage: %s [OPTION]... [FILE]...\n"), program_name);
      fputs_unlocked (gettext ("List information about the FILEs (the current directory by default).\nSort entries alphabetically if none of -cftuvSUX nor --sort.\n\n"),stdout);




      fputs_unlocked (gettext ("Mandatory arguments to long options are mandatory for short options too.\n"),stdout);


      fputs_unlocked (gettext ("  -a, --all                  do not ignore entries starting with .\n  -A, --almost-all           do not list implied . and ..\n      --author               with -l, print the author of each file\n  -b, --escape               print octal escapes for nongraphic characters\n"),stdout);





      fputs_unlocked (gettext ("      --block-size=SIZE      use SIZE-byte blocks\n  -B, --ignore-backups       do not list implied entries ending with ~\n  -c                         with -lt: sort by, and show, ctime (time of last\n                               modification of file status information)\n                               with -l: show ctime and sort by name\n                               otherwise: sort by ctime\n"),stdout);







      fputs_unlocked (gettext ("  -C                         list entries by columns\n      --color[=WHEN]         control whether color is used to distinguish file\n                               types.  WHEN may be `never', `always', or `auto'\n  -d, --directory            list directory entries instead of contents,\n                               and do not dereference symbolic links\n  -D, --dired                generate output designed for Emacs' dired mode\n"),stdout);







      fputs_unlocked (gettext ("  -f                         do not sort, enable -aU, disable -ls --color\n  -F, --classify             append indicator (one of */=>@|) to entries\n      --file-type            likewise, except do not append `*'\n      --format=WORD          across -x, commas -m, horizontal -x, long -l,\n                               single-column -1, verbose -l, vertical -C\n      --full-time            like -l --time-style=full-iso\n"),stdout);







      fputs_unlocked (gettext ("  -g                         like -l, but do not list owner\n"),stdout);


      fputs_unlocked (gettext ("      --group-directories-first\n                             group directories before files\n"),stdout);



      fputs_unlocked (gettext ("  -G, --no-group             in a long listing, don't print group names\n  -h, --human-readable       with -l, print sizes in human readable format\n                               (e.g., 1K 234M 2G)\n      --si                   likewise, but use powers of 1000 not 1024\n"),stdout);





      fputs_unlocked (gettext ("  -H, --dereference-command-line\n                             follow symbolic links listed on the command line\n      --dereference-command-line-symlink-to-dir\n                             follow each command line symbolic link\n                             that points to a directory\n      --hide=PATTERN         do not list implied entries matching shell PATTERN\n                               (overridden by -a or -A)\n"),stdout);
# 4395 "ls.c"
      fputs_unlocked (gettext ("      --indicator-style=WORD  append indicator with style WORD to entry names:\n                               none (default), slash (-p),\n                               file-type (--file-type), classify (-F)\n  -i, --inode                print the index number of each file\n  -I, --ignore=PATTERN       do not list implied entries matching shell PATTERN\n  -k                         like --block-size=1K\n"),stdout);







      fputs_unlocked (gettext ("  -l                         use a long listing format\n  -L, --dereference          when showing file information for a symbolic\n                               link, show information for the file the link\n                               references rather than for the link itself\n  -m                         fill width with a comma separated list of entries\n"),stdout);






      fputs_unlocked (gettext ("  -n, --numeric-uid-gid      like -l, but list numeric user and group IDs\n  -N, --literal              print raw entry names (don't treat e.g. control\n                               characters specially)\n  -o                         like -l, but do not list group information\n  -p, --indicator-style=slash\n                             append / indicator to directories\n"),stdout);







      fputs_unlocked (gettext ("  -q, --hide-control-chars   print ? instead of non graphic characters\n      --show-control-chars   show non graphic characters as-is (default\n                             unless program is `ls' and output is a terminal)\n  -Q, --quote-name           enclose entry names in double quotes\n      --quoting-style=WORD   use quoting style WORD for entry names:\n                               literal, locale, shell, shell-always, c, escape\n"),stdout);







      fputs_unlocked (gettext ("  -r, --reverse              reverse order while sorting\n  -R, --recursive            list subdirectories recursively\n  -s, --size                 print the size of each file, in blocks\n"),stdout);




      fputs_unlocked (gettext ("  -S                         sort by file size\n      --sort=WORD            sort by WORD instead of name: none -U,\n                             extension -X, size -S, time -t, version -v\n      --time=WORD            with -l, show time as WORD instead of modification\n                             time: atime -u, access -u, use -u, ctime -c,\n                             or status -c; use specified time as sort key\n                             if --sort=time\n"),stdout);
# 4440 "ls.c"
      fputs_unlocked (gettext ("      --time-style=STYLE     with -l, show times using style STYLE:\n                             full-iso, long-iso, iso, locale, +FORMAT.\n                             FORMAT is interpreted like `date'; if FORMAT is\n                             FORMAT1<newline>FORMAT2, FORMAT1 applies to\n                             non-recent files and FORMAT2 to recent files;\n                             if STYLE is prefixed with `posix-', STYLE\n                             takes effect only outside the POSIX locale\n"),stdout);
# 4449 "ls.c"
      fputs_unlocked (gettext ("  -t                         sort by modification time\n  -T, --tabsize=COLS         assume tab stops at each COLS instead of 8\n"),stdout);



      fputs_unlocked (gettext ("  -u                         with -lt: sort by, and show, access time\n                               with -l: show access time and sort by name\n                               otherwise: sort by access time\n  -U                         do not sort; list entries in directory order\n  -v                         sort by version\n"),stdout);






      fputs_unlocked (gettext ("  -w, --width=COLS           assume screen width instead of current value\n  -x                         list entries by lines instead of by columns\n  -X                         sort alphabetically by entry extension\n  -Z, --context              print any SELinux security context of each file\n  -1                         list one file per line\n"),stdout);






      fputs_unlocked (gettext ("      --help     display this help and exit\n"),stdout);
      fputs_unlocked (gettext ("      --version  output version information and exit\n"),stdout);
      fputs_unlocked (gettext ("\nSIZE may be (or may be an integer optionally followed by) one of following:\nkB 1000, K 1024, MB 1000*1000, M 1024*1024, and so on for G, T, P, E, Z, Y.\n"),stdout);



      fputs_unlocked (gettext ("\nBy default, color is not used to distinguish types of files.  That is\nequivalent to using --color=none.  Using the --color option without the\noptional WHEN argument is equivalent to using --color=always.  With\n--color=auto, color codes are output only if standard output is connected\nto a terminal (tty).  The environment variable LS_COLORS can influence the\ncolors, and can be set easily by the dircolors command.\n"),stdout);
# 4482 "ls.c"
      fputs_unlocked (gettext ("\nExit status is 0 if OK, 1 if minor problems, 2 if serious trouble.\n"),stdout);



      emit_bug_reporting_address ();
    }
  exit (status);
}
