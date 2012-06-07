typedef int _Bool;
# 1 "sort.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "sort.c"
# 23 "sort.c"
# 1 "../lib/config.h" 1
# 24 "sort.c" 2

# 1 "/usr/include/getopt.h" 1 3 4
# 35 "/usr/include/getopt.h" 3 4
# 1 "/usr/include/ctype.h" 1 3 4
# 27 "/usr/include/ctype.h" 3 4
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
# 28 "/usr/include/ctype.h" 2 3 4
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
# 29 "/usr/include/ctype.h" 2 3 4


# 41 "/usr/include/ctype.h" 3 4
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
# 42 "/usr/include/ctype.h" 2 3 4






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
# 233 "/usr/include/ctype.h" 3 4
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
# 234 "/usr/include/ctype.h" 2 3 4
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

# 36 "/usr/include/getopt.h" 2 3 4
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
# 26 "sort.c" 2
# 1 "/usr/include/sys/types.h" 1 3 4
# 29 "/usr/include/sys/types.h" 3 4






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
# 220 "/usr/include/sys/types.h" 3 4
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



# 27 "sort.c" 2
# 1 "/usr/include/sys/wait.h" 1 3 4
# 29 "/usr/include/sys/wait.h" 3 4


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




# 32 "/usr/include/sys/wait.h" 2 3 4
# 1 "/usr/include/sys/resource.h" 1 3 4
# 25 "/usr/include/sys/resource.h" 3 4
# 1 "/usr/include/bits/resource.h" 1 3 4
# 33 "/usr/include/bits/resource.h" 3 4
enum __rlimit_resource
{

  RLIMIT_CPU = 0,



  RLIMIT_FSIZE = 1,



  RLIMIT_DATA = 2,



  RLIMIT_STACK = 3,



  RLIMIT_CORE = 4,






  __RLIMIT_RSS = 5,



  RLIMIT_NOFILE = 7,
  __RLIMIT_OFILE = RLIMIT_NOFILE,




  RLIMIT_AS = 9,



  __RLIMIT_NPROC = 6,



  __RLIMIT_MEMLOCK = 8,



  __RLIMIT_LOCKS = 10,



  __RLIMIT_SIGPENDING = 11,



  __RLIMIT_MSGQUEUE = 12,





  __RLIMIT_NICE = 13,




  __RLIMIT_RTPRIO = 14,


  __RLIMIT_NLIMITS = 15,
  __RLIM_NLIMITS = __RLIMIT_NLIMITS


};
# 129 "/usr/include/bits/resource.h" 3 4
typedef __rlim64_t rlim_t;


typedef __rlim64_t rlim64_t;


struct rlimit
  {

    rlim_t rlim_cur;

    rlim_t rlim_max;
  };


struct rlimit64
  {

    rlim64_t rlim_cur;

    rlim64_t rlim_max;
 };



enum __rusage_who
{

  RUSAGE_SELF = 0,



  RUSAGE_CHILDREN = -1



  ,

  RUSAGE_THREAD = 1




};


# 1 "/usr/include/bits/time.h" 1 3 4
# 176 "/usr/include/bits/resource.h" 2 3 4


struct rusage
  {

    struct timeval ru_utime;

    struct timeval ru_stime;

    long int ru_maxrss;


    long int ru_ixrss;

    long int ru_idrss;

    long int ru_isrss;


    long int ru_minflt;

    long int ru_majflt;

    long int ru_nswap;


    long int ru_inblock;

    long int ru_oublock;

    long int ru_msgsnd;

    long int ru_msgrcv;

    long int ru_nsignals;



    long int ru_nvcsw;


    long int ru_nivcsw;
  };







enum __priority_which
{
  PRIO_PROCESS = 0,

  PRIO_PGRP = 1,

  PRIO_USER = 2

};
# 26 "/usr/include/sys/resource.h" 2 3 4













typedef enum __rlimit_resource __rlimit_resource_t;
typedef enum __rusage_who __rusage_who_t;
typedef enum __priority_which __priority_which_t;
# 55 "/usr/include/sys/resource.h" 3 4
extern int getrlimit (__rlimit_resource_t __resource, struct rlimit *__rlimits) __asm__ ("" "getrlimit64") __attribute__ ((__nothrow__));






extern int getrlimit64 (__rlimit_resource_t __resource,
   struct rlimit64 *__rlimits) __attribute__ ((__nothrow__));
# 74 "/usr/include/sys/resource.h" 3 4
extern int setrlimit (__rlimit_resource_t __resource, __const struct rlimit *__rlimits) __asm__ ("" "setrlimit64") __attribute__ ((__nothrow__));







extern int setrlimit64 (__rlimit_resource_t __resource,
   __const struct rlimit64 *__rlimits) __attribute__ ((__nothrow__));




extern int getrusage (__rusage_who_t __who, struct rusage *__usage) __attribute__ ((__nothrow__));





extern int getpriority (__priority_which_t __which, id_t __who) __attribute__ ((__nothrow__));



extern int setpriority (__priority_which_t __which, id_t __who, int __prio)
     __attribute__ ((__nothrow__));


# 33 "/usr/include/sys/wait.h" 2 3 4





# 1 "/usr/include/bits/waitflags.h" 1 3 4
# 39 "/usr/include/sys/wait.h" 2 3 4
# 63 "/usr/include/sys/wait.h" 3 4
typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));
# 80 "/usr/include/sys/wait.h" 3 4
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
# 81 "/usr/include/sys/wait.h" 2 3 4
# 102 "/usr/include/sys/wait.h" 3 4
typedef enum
{
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;
# 116 "/usr/include/sys/wait.h" 3 4
extern __pid_t wait (__WAIT_STATUS __stat_loc);
# 139 "/usr/include/sys/wait.h" 3 4
extern __pid_t waitpid (__pid_t __pid, int *__stat_loc, int __options);



# 1 "/usr/include/bits/siginfo.h" 1 3 4
# 25 "/usr/include/bits/siginfo.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 26 "/usr/include/bits/siginfo.h" 2 3 4
# 144 "/usr/include/sys/wait.h" 2 3 4
# 155 "/usr/include/sys/wait.h" 3 4
extern int waitid (idtype_t __idtype, __id_t __id, siginfo_t *__infop,
     int __options);





struct rusage;






extern __pid_t wait3 (__WAIT_STATUS __stat_loc, int __options,
        struct rusage * __usage) __attribute__ ((__nothrow__));




extern __pid_t wait4 (__pid_t __pid, __WAIT_STATUS __stat_loc, int __options,
        struct rusage *__usage) __attribute__ ((__nothrow__));




# 28 "sort.c" 2

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
# 323 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 3 4
typedef int wchar_t;
# 34 "/usr/include/stdlib.h" 2 3 4


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
# 27 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/bits/wchar.h" 1 3 4
# 28 "/usr/include/stdint.h" 2 3 4
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
# 149 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 3 4
typedef int ptrdiff_t;
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
# 30 "sort.c" 2
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
# 31 "sort.c" 2
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
# 32 "sort.c" 2
# 1 "../lib/hard-locale.h" 1
# 23 "../lib/hard-locale.h"
_Bool hard_locale (int);
# 33 "sort.c" 2
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
# 34 "sort.c" 2
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
# 35 "sort.c" 2
# 1 "../lib/md5.h" 1
# 26 "../lib/md5.h"
# 1 "../lib/stdio.h" 1
# 27 "../lib/md5.h" 2
# 60 "../lib/md5.h"
struct md5_ctx
{
  uint32_t A;
  uint32_t B;
  uint32_t C;
  uint32_t D;

  uint32_t total[2];
  uint32_t buflen;
  uint32_t buffer[32];
};
# 79 "../lib/md5.h"
extern void md5_init_ctx (struct md5_ctx *ctx) __attribute__ ((__nothrow__));





extern void md5_process_block (const void *buffer, size_t len,
     struct md5_ctx *ctx) __attribute__ ((__nothrow__));





extern void md5_process_bytes (const void *buffer, size_t len,
     struct md5_ctx *ctx) __attribute__ ((__nothrow__));
# 102 "../lib/md5.h"
extern void *md5_finish_ctx (struct md5_ctx *ctx, void *resbuf) __attribute__ ((__nothrow__));
# 111 "../lib/md5.h"
extern void *md5_read_ctx (const struct md5_ctx *ctx, void *resbuf) __attribute__ ((__nothrow__));





extern int md5_stream (FILE *stream, void *resblock) __attribute__ ((__nothrow__));





extern void *md5_buffer (const char *buffer, size_t len,
      void *resblock) __attribute__ ((__nothrow__));
# 36 "sort.c" 2
# 1 "../lib/physmem.h" 1
# 23 "../lib/physmem.h"
double physmem_total (void);
double physmem_available (void);
# 37 "sort.c" 2
# 1 "../lib/posixver.h" 1
int posix2_version (void);
# 38 "sort.c" 2
# 1 "../lib/quote.h" 1
# 20 "../lib/quote.h"
char const *quote_n (int n, char const *name);
char const *quote (char const *name);
# 39 "sort.c" 2
# 1 "../lib/randread.h" 1
# 23 "../lib/randread.h"
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 24 "../lib/randread.h" 2

struct randread_source;

struct randread_source *randread_new (char const *, size_t);
void randread (struct randread_source *, void *, size_t);
void randread_set_handler (struct randread_source *, void (*) (void const *));
void randread_set_handler_arg (struct randread_source *, void const *);
int randread_free (struct randread_source *);
# 40 "sort.c" 2
# 1 "../lib/stdio--.h" 1
# 20 "../lib/stdio--.h"
# 1 "../lib/stdio.h" 1
# 21 "../lib/stdio--.h" 2
# 1 "../lib/stdio-safer.h" 1
# 20 "../lib/stdio-safer.h"
# 1 "../lib/stdio.h" 1
# 21 "../lib/stdio-safer.h" 2

FILE *fopen_safer (char const *, char const *);
FILE *tmpfile_safer (void);
# 22 "../lib/stdio--.h" 2
# 41 "sort.c" 2
# 1 "../lib/stdlib--.h" 1
# 20 "../lib/stdlib--.h"
# 1 "../lib/stdlib.h" 1
# 21 "../lib/stdlib--.h" 2
# 1 "../lib/stdlib-safer.h" 1
# 20 "../lib/stdlib-safer.h"
int mkstemp_safer (char *);
# 22 "../lib/stdlib--.h" 2
# 42 "sort.c" 2
# 1 "../lib/strnumcmp.h" 1
int strintcmp (char const *, char const *);
int strnumcmp (char const *, char const *, int, int);
# 43 "sort.c" 2
# 1 "../lib/xmemcoll.h" 1
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 2 "../lib/xmemcoll.h" 2
int xmemcoll (char *, size_t, char *, size_t);
# 44 "sort.c" 2
# 1 "../lib/xmemxfrm.h" 1
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 1 3 4
# 2 "../lib/xmemxfrm.h" 2
size_t xmemxfrm (char *__restrict, size_t, char *__restrict, size_t);
# 45 "sort.c" 2
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
# 46 "sort.c" 2
# 61 "sort.c"
# 1 "/usr/include/langinfo.h" 1 3 4
# 24 "/usr/include/langinfo.h" 3 4
# 1 "/usr/include/nl_types.h" 1 3 4
# 31 "/usr/include/nl_types.h" 3 4



typedef void *nl_catd;


typedef int nl_item;





extern nl_catd catopen (__const char *__cat_name, int __flag) __attribute__ ((__nonnull__ (1)));



extern char *catgets (nl_catd __catalog, int __set, int __number,
        __const char *__string) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int catclose (nl_catd __catalog) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


# 25 "/usr/include/langinfo.h" 2 3 4

# 1 "/usr/include/bits/locale.h" 1 3 4
# 27 "/usr/include/langinfo.h" 2 3 4



# 42 "/usr/include/langinfo.h" 3 4
enum
{



  ABDAY_1 = (((__LC_TIME) << 16) | (0)),

  ABDAY_2,

  ABDAY_3,

  ABDAY_4,

  ABDAY_5,

  ABDAY_6,

  ABDAY_7,



  DAY_1,

  DAY_2,

  DAY_3,

  DAY_4,

  DAY_5,

  DAY_6,

  DAY_7,



  ABMON_1,

  ABMON_2,

  ABMON_3,

  ABMON_4,

  ABMON_5,

  ABMON_6,

  ABMON_7,

  ABMON_8,

  ABMON_9,

  ABMON_10,

  ABMON_11,

  ABMON_12,



  MON_1,

  MON_2,

  MON_3,

  MON_4,

  MON_5,

  MON_6,

  MON_7,

  MON_8,

  MON_9,

  MON_10,

  MON_11,

  MON_12,


  AM_STR,

  PM_STR,


  D_T_FMT,

  D_FMT,

  T_FMT,

  T_FMT_AMPM,


  ERA,

  __ERA_YEAR,



  ERA_D_FMT,

  ALT_DIGITS,

  ERA_D_T_FMT,

  ERA_T_FMT,


  _NL_TIME_ERA_NUM_ENTRIES,
  _NL_TIME_ERA_ENTRIES,

  _NL_WABDAY_1,
  _NL_WABDAY_2,
  _NL_WABDAY_3,
  _NL_WABDAY_4,
  _NL_WABDAY_5,
  _NL_WABDAY_6,
  _NL_WABDAY_7,


  _NL_WDAY_1,
  _NL_WDAY_2,
  _NL_WDAY_3,
  _NL_WDAY_4,
  _NL_WDAY_5,
  _NL_WDAY_6,
  _NL_WDAY_7,


  _NL_WABMON_1,
  _NL_WABMON_2,
  _NL_WABMON_3,
  _NL_WABMON_4,
  _NL_WABMON_5,
  _NL_WABMON_6,
  _NL_WABMON_7,
  _NL_WABMON_8,
  _NL_WABMON_9,
  _NL_WABMON_10,
  _NL_WABMON_11,
  _NL_WABMON_12,


  _NL_WMON_1,
  _NL_WMON_2,
  _NL_WMON_3,
  _NL_WMON_4,
  _NL_WMON_5,
  _NL_WMON_6,
  _NL_WMON_7,
  _NL_WMON_8,
  _NL_WMON_9,
  _NL_WMON_10,
  _NL_WMON_11,
  _NL_WMON_12,

  _NL_WAM_STR,
  _NL_WPM_STR,

  _NL_WD_T_FMT,
  _NL_WD_FMT,
  _NL_WT_FMT,
  _NL_WT_FMT_AMPM,

  _NL_WERA_YEAR,
  _NL_WERA_D_FMT,
  _NL_WALT_DIGITS,
  _NL_WERA_D_T_FMT,
  _NL_WERA_T_FMT,

  _NL_TIME_WEEK_NDAYS,
  _NL_TIME_WEEK_1STDAY,
  _NL_TIME_WEEK_1STWEEK,
  _NL_TIME_FIRST_WEEKDAY,
  _NL_TIME_FIRST_WORKDAY,
  _NL_TIME_CAL_DIRECTION,
  _NL_TIME_TIMEZONE,

  _DATE_FMT,

  _NL_W_DATE_FMT,

  _NL_TIME_CODESET,

  _NL_NUM_LC_TIME,




  _NL_COLLATE_NRULES = (((__LC_COLLATE) << 16) | (0)),
  _NL_COLLATE_RULESETS,
  _NL_COLLATE_TABLEMB,
  _NL_COLLATE_WEIGHTMB,
  _NL_COLLATE_EXTRAMB,
  _NL_COLLATE_INDIRECTMB,
  _NL_COLLATE_GAP1,
  _NL_COLLATE_GAP2,
  _NL_COLLATE_GAP3,
  _NL_COLLATE_TABLEWC,
  _NL_COLLATE_WEIGHTWC,
  _NL_COLLATE_EXTRAWC,
  _NL_COLLATE_INDIRECTWC,
  _NL_COLLATE_SYMB_HASH_SIZEMB,
  _NL_COLLATE_SYMB_TABLEMB,
  _NL_COLLATE_SYMB_EXTRAMB,
  _NL_COLLATE_COLLSEQMB,
  _NL_COLLATE_COLLSEQWC,
  _NL_COLLATE_CODESET,
  _NL_NUM_LC_COLLATE,




  _NL_CTYPE_CLASS = (((__LC_CTYPE) << 16) | (0)),
  _NL_CTYPE_TOUPPER,
  _NL_CTYPE_GAP1,
  _NL_CTYPE_TOLOWER,
  _NL_CTYPE_GAP2,
  _NL_CTYPE_CLASS32,
  _NL_CTYPE_GAP3,
  _NL_CTYPE_GAP4,
  _NL_CTYPE_GAP5,
  _NL_CTYPE_GAP6,
  _NL_CTYPE_CLASS_NAMES,
  _NL_CTYPE_MAP_NAMES,
  _NL_CTYPE_WIDTH,
  _NL_CTYPE_MB_CUR_MAX,
  _NL_CTYPE_CODESET_NAME,
  CODESET = _NL_CTYPE_CODESET_NAME,

  _NL_CTYPE_TOUPPER32,
  _NL_CTYPE_TOLOWER32,
  _NL_CTYPE_CLASS_OFFSET,
  _NL_CTYPE_MAP_OFFSET,
  _NL_CTYPE_INDIGITS_MB_LEN,
  _NL_CTYPE_INDIGITS0_MB,
  _NL_CTYPE_INDIGITS1_MB,
  _NL_CTYPE_INDIGITS2_MB,
  _NL_CTYPE_INDIGITS3_MB,
  _NL_CTYPE_INDIGITS4_MB,
  _NL_CTYPE_INDIGITS5_MB,
  _NL_CTYPE_INDIGITS6_MB,
  _NL_CTYPE_INDIGITS7_MB,
  _NL_CTYPE_INDIGITS8_MB,
  _NL_CTYPE_INDIGITS9_MB,
  _NL_CTYPE_INDIGITS_WC_LEN,
  _NL_CTYPE_INDIGITS0_WC,
  _NL_CTYPE_INDIGITS1_WC,
  _NL_CTYPE_INDIGITS2_WC,
  _NL_CTYPE_INDIGITS3_WC,
  _NL_CTYPE_INDIGITS4_WC,
  _NL_CTYPE_INDIGITS5_WC,
  _NL_CTYPE_INDIGITS6_WC,
  _NL_CTYPE_INDIGITS7_WC,
  _NL_CTYPE_INDIGITS8_WC,
  _NL_CTYPE_INDIGITS9_WC,
  _NL_CTYPE_OUTDIGIT0_MB,
  _NL_CTYPE_OUTDIGIT1_MB,
  _NL_CTYPE_OUTDIGIT2_MB,
  _NL_CTYPE_OUTDIGIT3_MB,
  _NL_CTYPE_OUTDIGIT4_MB,
  _NL_CTYPE_OUTDIGIT5_MB,
  _NL_CTYPE_OUTDIGIT6_MB,
  _NL_CTYPE_OUTDIGIT7_MB,
  _NL_CTYPE_OUTDIGIT8_MB,
  _NL_CTYPE_OUTDIGIT9_MB,
  _NL_CTYPE_OUTDIGIT0_WC,
  _NL_CTYPE_OUTDIGIT1_WC,
  _NL_CTYPE_OUTDIGIT2_WC,
  _NL_CTYPE_OUTDIGIT3_WC,
  _NL_CTYPE_OUTDIGIT4_WC,
  _NL_CTYPE_OUTDIGIT5_WC,
  _NL_CTYPE_OUTDIGIT6_WC,
  _NL_CTYPE_OUTDIGIT7_WC,
  _NL_CTYPE_OUTDIGIT8_WC,
  _NL_CTYPE_OUTDIGIT9_WC,
  _NL_CTYPE_TRANSLIT_TAB_SIZE,
  _NL_CTYPE_TRANSLIT_FROM_IDX,
  _NL_CTYPE_TRANSLIT_FROM_TBL,
  _NL_CTYPE_TRANSLIT_TO_IDX,
  _NL_CTYPE_TRANSLIT_TO_TBL,
  _NL_CTYPE_TRANSLIT_DEFAULT_MISSING_LEN,
  _NL_CTYPE_TRANSLIT_DEFAULT_MISSING,
  _NL_CTYPE_TRANSLIT_IGNORE_LEN,
  _NL_CTYPE_TRANSLIT_IGNORE,
  _NL_CTYPE_MAP_TO_NONASCII,
  _NL_CTYPE_NONASCII_CASE,
  _NL_CTYPE_EXTRA_MAP_1,
  _NL_CTYPE_EXTRA_MAP_2,
  _NL_CTYPE_EXTRA_MAP_3,
  _NL_CTYPE_EXTRA_MAP_4,
  _NL_CTYPE_EXTRA_MAP_5,
  _NL_CTYPE_EXTRA_MAP_6,
  _NL_CTYPE_EXTRA_MAP_7,
  _NL_CTYPE_EXTRA_MAP_8,
  _NL_CTYPE_EXTRA_MAP_9,
  _NL_CTYPE_EXTRA_MAP_10,
  _NL_CTYPE_EXTRA_MAP_11,
  _NL_CTYPE_EXTRA_MAP_12,
  _NL_CTYPE_EXTRA_MAP_13,
  _NL_CTYPE_EXTRA_MAP_14,
  _NL_NUM_LC_CTYPE,




  __INT_CURR_SYMBOL = (((__LC_MONETARY) << 16) | (0)),



  __CURRENCY_SYMBOL,



  __MON_DECIMAL_POINT,



  __MON_THOUSANDS_SEP,



  __MON_GROUPING,



  __POSITIVE_SIGN,



  __NEGATIVE_SIGN,



  __INT_FRAC_DIGITS,



  __FRAC_DIGITS,



  __P_CS_PRECEDES,



  __P_SEP_BY_SPACE,



  __N_CS_PRECEDES,



  __N_SEP_BY_SPACE,



  __P_SIGN_POSN,



  __N_SIGN_POSN,



  _NL_MONETARY_CRNCYSTR,

  __INT_P_CS_PRECEDES,



  __INT_P_SEP_BY_SPACE,



  __INT_N_CS_PRECEDES,



  __INT_N_SEP_BY_SPACE,



  __INT_P_SIGN_POSN,



  __INT_N_SIGN_POSN,



  _NL_MONETARY_DUO_INT_CURR_SYMBOL,
  _NL_MONETARY_DUO_CURRENCY_SYMBOL,
  _NL_MONETARY_DUO_INT_FRAC_DIGITS,
  _NL_MONETARY_DUO_FRAC_DIGITS,
  _NL_MONETARY_DUO_P_CS_PRECEDES,
  _NL_MONETARY_DUO_P_SEP_BY_SPACE,
  _NL_MONETARY_DUO_N_CS_PRECEDES,
  _NL_MONETARY_DUO_N_SEP_BY_SPACE,
  _NL_MONETARY_DUO_INT_P_CS_PRECEDES,
  _NL_MONETARY_DUO_INT_P_SEP_BY_SPACE,
  _NL_MONETARY_DUO_INT_N_CS_PRECEDES,
  _NL_MONETARY_DUO_INT_N_SEP_BY_SPACE,
  _NL_MONETARY_DUO_P_SIGN_POSN,
  _NL_MONETARY_DUO_N_SIGN_POSN,
  _NL_MONETARY_DUO_INT_P_SIGN_POSN,
  _NL_MONETARY_DUO_INT_N_SIGN_POSN,
  _NL_MONETARY_UNO_VALID_FROM,
  _NL_MONETARY_UNO_VALID_TO,
  _NL_MONETARY_DUO_VALID_FROM,
  _NL_MONETARY_DUO_VALID_TO,
  _NL_MONETARY_CONVERSION_RATE,
  _NL_MONETARY_DECIMAL_POINT_WC,
  _NL_MONETARY_THOUSANDS_SEP_WC,
  _NL_MONETARY_CODESET,
  _NL_NUM_LC_MONETARY,



  __DECIMAL_POINT = (((__LC_NUMERIC) << 16) | (0)),



  RADIXCHAR = __DECIMAL_POINT,

  __THOUSANDS_SEP,



  THOUSEP = __THOUSANDS_SEP,

  __GROUPING,



  _NL_NUMERIC_DECIMAL_POINT_WC,
  _NL_NUMERIC_THOUSANDS_SEP_WC,
  _NL_NUMERIC_CODESET,
  _NL_NUM_LC_NUMERIC,

  __YESEXPR = (((__LC_MESSAGES) << 16) | (0)),

  __NOEXPR,

  __YESSTR,



  __NOSTR,



  _NL_MESSAGES_CODESET,
  _NL_NUM_LC_MESSAGES,

  _NL_PAPER_HEIGHT = (((__LC_PAPER) << 16) | (0)),
  _NL_PAPER_WIDTH,
  _NL_PAPER_CODESET,
  _NL_NUM_LC_PAPER,

  _NL_NAME_NAME_FMT = (((__LC_NAME) << 16) | (0)),
  _NL_NAME_NAME_GEN,
  _NL_NAME_NAME_MR,
  _NL_NAME_NAME_MRS,
  _NL_NAME_NAME_MISS,
  _NL_NAME_NAME_MS,
  _NL_NAME_CODESET,
  _NL_NUM_LC_NAME,

  _NL_ADDRESS_POSTAL_FMT = (((__LC_ADDRESS) << 16) | (0)),
  _NL_ADDRESS_COUNTRY_NAME,
  _NL_ADDRESS_COUNTRY_POST,
  _NL_ADDRESS_COUNTRY_AB2,
  _NL_ADDRESS_COUNTRY_AB3,
  _NL_ADDRESS_COUNTRY_CAR,
  _NL_ADDRESS_COUNTRY_NUM,
  _NL_ADDRESS_COUNTRY_ISBN,
  _NL_ADDRESS_LANG_NAME,
  _NL_ADDRESS_LANG_AB,
  _NL_ADDRESS_LANG_TERM,
  _NL_ADDRESS_LANG_LIB,
  _NL_ADDRESS_CODESET,
  _NL_NUM_LC_ADDRESS,

  _NL_TELEPHONE_TEL_INT_FMT = (((__LC_TELEPHONE) << 16) | (0)),
  _NL_TELEPHONE_TEL_DOM_FMT,
  _NL_TELEPHONE_INT_SELECT,
  _NL_TELEPHONE_INT_PREFIX,
  _NL_TELEPHONE_CODESET,
  _NL_NUM_LC_TELEPHONE,

  _NL_MEASUREMENT_MEASUREMENT = (((__LC_MEASUREMENT) << 16) | (0)),
  _NL_MEASUREMENT_CODESET,
  _NL_NUM_LC_MEASUREMENT,

  _NL_IDENTIFICATION_TITLE = (((__LC_IDENTIFICATION) << 16) | (0)),
  _NL_IDENTIFICATION_SOURCE,
  _NL_IDENTIFICATION_ADDRESS,
  _NL_IDENTIFICATION_CONTACT,
  _NL_IDENTIFICATION_EMAIL,
  _NL_IDENTIFICATION_TEL,
  _NL_IDENTIFICATION_FAX,
  _NL_IDENTIFICATION_LANGUAGE,
  _NL_IDENTIFICATION_TERRITORY,
  _NL_IDENTIFICATION_AUDIENCE,
  _NL_IDENTIFICATION_APPLICATION,
  _NL_IDENTIFICATION_ABBREVIATION,
  _NL_IDENTIFICATION_REVISION,
  _NL_IDENTIFICATION_DATE,
  _NL_IDENTIFICATION_CATEGORY,
  _NL_IDENTIFICATION_CODESET,
  _NL_NUM_LC_IDENTIFICATION,


  _NL_NUM
};
# 584 "/usr/include/langinfo.h" 3 4
extern char *nl_langinfo (nl_item __item) __attribute__ ((__nothrow__));
# 595 "/usr/include/langinfo.h" 3 4
extern char *nl_langinfo_l (nl_item __item, __locale_t __l);



# 62 "sort.c" 2
# 87 "sort.c"
enum
  {


    SORT_OUT_OF_ORDER = 1,



    SORT_FAILURE = 2
  };

enum
  {




    MAX_FORK_TRIES_COMPRESS = 2,




    MAX_FORK_TRIES_DECOMPRESS = 8
  };


static int decimal_point;


static int thousands_sep;


static _Bool hard_LC_COLLATE;







enum blanktype { bl_start, bl_end, bl_both };


static char eolchar = '\n';


struct line
{
  char *text;
  size_t length;
  char *keybeg;
  char *keylim;
};


struct buffer
{
  char *buf;




  size_t used;
  size_t nlines;
  size_t alloc;
  size_t left;
  size_t line_bytes;
  _Bool eof;
};

struct keyfield
{
  size_t sword;
  size_t schar;
  size_t eword;
  size_t echar;
  _Bool const *ignore;
  char const *translate;
  _Bool skipsblanks;
  _Bool skipeblanks;
  _Bool numeric;


  _Bool random;
  _Bool general_numeric;

  _Bool month;
  _Bool reverse;
  struct keyfield *next;
};

struct month
{
  char const *name;
  int val;
};


char *program_name;
# 194 "sort.c"
static _Bool blanks[((127 * 2 + 1) + 1)];


static _Bool nonprinting[((127 * 2 + 1) + 1)];


static _Bool nondictionary[((127 * 2 + 1) + 1)];


static char fold_toupper[((127 * 2 + 1) + 1)];





static struct month monthtab[] =
{
  {"APR", 4},
  {"AUG", 8},
  {"DEC", 12},
  {"FEB", 2},
  {"JAN", 1},
  {"JUL", 7},
  {"JUN", 6},
  {"MAR", 3},
  {"MAY", 5},
  {"NOV", 11},
  {"OCT", 10},
  {"SEP", 9}
};
# 237 "sort.c"
static size_t merge_buffer_size = ((((2 + sizeof (struct line)))>(256 * 1024))?((2 + sizeof (struct line))):(256 * 1024));



static size_t sort_size;





static char const **temp_dirs;


static size_t temp_dir_count;


static size_t temp_dir_alloc;


static _Bool reverse;




static _Bool stable;


enum { TAB_DEFAULT = 127 + 1 };




static int tab = TAB_DEFAULT;



static _Bool unique;


static _Bool have_read_stdin;


static struct keyfield *keylist;


static char const *compress_program;

static void sortlines_temp (struct line *, size_t, struct line *);




static void die (char const *, char const *) __attribute__ ((__noreturn__));
static void
die (char const *message, char const *file)
{
  error (0, (*__errno_location ()), "%s: %s", message, file ? file : gettext ("standard output"));
  exit (SORT_FAILURE);
}

void
usage (int status)
{
  if (status != 0)
    fprintf (stderr, gettext ("Try `%s --help' for more information.\n"),
      program_name);
  else
    {
      printf (gettext ("Usage: %s [OPTION]... [FILE]...\n"),


       program_name);
      fputs_unlocked (gettext ("Write sorted concatenation of all FILE(s) to standard output.\n\n"),stdout);



      fputs_unlocked (gettext ("Mandatory arguments to long options are mandatory for short options too.\n"),stdout);


      fputs_unlocked (gettext ("Ordering options:\n\n"),stdout);



      fputs_unlocked (gettext ("  -b, --ignore-leading-blanks  ignore leading blanks\n  -d, --dictionary-order      consider only blanks and alphanumeric characters\n  -f, --ignore-case           fold lower case to upper case characters\n"),stdout);




      fputs_unlocked (gettext ("  -g, --general-numeric-sort  compare according to general numerical value\n  -i, --ignore-nonprinting    consider only printable characters\n  -M, --month-sort            compare (unknown) < `JAN' < ... < `DEC'\n  -n, --numeric-sort          compare according to string numerical value\n  -R, --random-sort           sort by random hash of keys\n      --random-source=FILE    get random bytes from FILE (default /dev/urandom)\n  -r, --reverse               reverse the result of comparisons\n\n"),stdout);
# 335 "sort.c"
      fputs_unlocked (gettext ("Other options:\n\n  -c, --check, --check=diagnose-first  check for sorted input; do not sort\n  -C, --check=quiet, --check=silent  like -c, but do not report first bad line\n      --compress-program=PROG  compress temporaries with PROG;\n                              decompress them with PROG -d\n  -k, --key=POS1[,POS2]     start a key at POS1, end it at POS2 (origin 1)\n  -m, --merge               merge already sorted files; do not sort\n"),stdout);
# 345 "sort.c"
      fputs_unlocked (gettext ("  -o, --output=FILE         write result to FILE instead of standard output\n  -s, --stable              stabilize sort by disabling last-resort comparison\n  -S, --buffer-size=SIZE    use SIZE for main memory buffer\n"),stdout);




      printf (gettext ("  -t, --field-separator=SEP  use SEP instead of non-blank to blank transition\n  -T, --temporary-directory=DIR  use DIR for temporaries, not $TMPDIR or %s;\n                              multiple options specify multiple directories\n  -u, --unique              with -c, check for strict ordering;\n                              without -c, output only the first of an equal run\n"), "/tmp");






      fputs_unlocked (gettext ("  -z, --zero-terminated     end lines with 0 byte, not newline\n"),stdout);


      fputs_unlocked (gettext ("      --help     display this help and exit\n"),stdout);
      fputs_unlocked (gettext ("      --version  output version information and exit\n"),stdout);
      fputs_unlocked (gettext ("\nPOS is F[.C][OPTS], where F is the field number and C the character position\nin the field; both are origin 1.  If neither -t nor -b is in effect, characters\nin a field are counted from the beginning of the preceding whitespace.  OPTS is\none or more single-letter ordering options, which override global ordering\noptions for that key.  If no key is given, use the entire line as the key.\n\nSIZE may be followed by the following multiplicative suffixes:\n"),stdout);
# 372 "sort.c"
      fputs_unlocked (gettext ("% 1% of memory, b 1, K 1024 (default), and so on for M, G, T, P, E, Z, Y.\n\nWith no FILE, or when FILE is -, read standard input.\n\n*** WARNING ***\nThe locale specified by the environment affects sort order.\nSet LC_ALL=C to get the traditional sort order that uses\nnative byte values.\n"),stdout);
# 382 "sort.c"
      emit_bug_reporting_address ();
    }

  exit (status);
}



enum
{
  CHECK_OPTION = 127 + 1,
  COMPRESS_PROGRAM_OPTION,
  RANDOM_SOURCE_OPTION
};

static char const short_options[] = "-bcCdfgik:mMno:rRsS:t:T:uy:z";

static struct option const long_options[] =
{
  {"ignore-leading-blanks", 0, ((void *)0), 'b'},
  {"check", 2, ((void *)0), CHECK_OPTION},
  {"compress-program", 1, ((void *)0), COMPRESS_PROGRAM_OPTION},
  {"dictionary-order", 0, ((void *)0), 'd'},
  {"ignore-case", 0, ((void *)0), 'f'},
  {"general-numeric-sort", 0, ((void *)0), 'g'},
  {"ignore-nonprinting", 0, ((void *)0), 'i'},
  {"key", 1, ((void *)0), 'k'},
  {"merge", 0, ((void *)0), 'm'},
  {"month-sort", 0, ((void *)0), 'M'},
  {"numeric-sort", 0, ((void *)0), 'n'},
  {"random-sort", 0, ((void *)0), 'R'},
  {"random-source", 1, ((void *)0), RANDOM_SOURCE_OPTION},
  {"output", 1, ((void *)0), 'o'},
  {"reverse", 0, ((void *)0), 'r'},
  {"stable", 0, ((void *)0), 's'},
  {"buffer-size", 1, ((void *)0), 'S'},
  {"field-separator", 1, ((void *)0), 't'},
  {"temporary-directory", 1, ((void *)0), 'T'},
  {"unique", 0, ((void *)0), 'u'},
  {"zero-terminated", 0, ((void *)0), 'z'},
  {"help", 0, ((void *)0), GETOPT_HELP_CHAR},
  {"version", 0, ((void *)0), GETOPT_VERSION_CHAR},
  {((void *)0), 0, ((void *)0), 0},
};

static char const *const check_args[] =
{
  "quiet", "silent", "diagnose-first", ((void *)0)
};
static char const check_types[] =
{
  'C', 'C', 'c'
};
extern int (* verify_function__ (void)) [(!!sizeof (struct { unsigned int verify_error_if_negative_size__: ((sizeof (check_args) / sizeof *(check_args)) == (sizeof (check_types) / sizeof *(check_types)) + 1) ? 1 : -1; }))];


static sigset_t caught_signals;


struct cs_status
{
  _Bool valid;
  sigset_t sigs;
};


static struct cs_status
cs_enter (void)
{
  struct cs_status status;
  status.valid = (sigprocmask (0, &caught_signals, &status.sigs) == 0);
  return status;
}


static void
cs_leave (struct cs_status status)
{
  if (status.valid)
    {

      sigprocmask (2, &status.sigs, ((void *)0));
    }
}


struct tempnode
{
  struct tempnode *volatile next;
  pid_t pid;
  char name[1];
};
static struct tempnode *volatile temphead;
static struct tempnode *volatile *temptail = &temphead;

struct sortfile
{
  char const *name;
  pid_t pid;
};





static Hash_table *proctab;

enum { INIT_PROCTAB_SIZE = 47 };

enum procstate { ALIVE, ZOMBIE };





struct procnode
{
  pid_t pid;
  enum procstate state;
  size_t count;
};

static size_t
proctab_hasher (const void *entry, size_t tabsize)
{
  const struct procnode *node = entry;
  return node->pid % tabsize;
}

static _Bool
proctab_comparator (const void *e1, const void *e2)
{
  const struct procnode *n1 = e1, *n2 = e2;
  return n1->pid == n2->pid;
}



static size_t nprocs;


enum { MAX_PROCS_BEFORE_REAP = 2 };






static pid_t
reap (pid_t pid)
{
  int status;
  pid_t cpid = waitpid (pid, &status, pid < 0 ? 1 : 0);

  if (cpid < 0)
    error (SORT_FAILURE, (*__errno_location ()), gettext ("waiting for %s [-d]"),
           compress_program);
  else if (0 < cpid)
    {
      if (! ((((__extension__ (((union { __typeof(status) __in; int __i; }) { .__in = (status) }).__i))) & 0x7f) == 0) || ((((__extension__ (((union { __typeof(status) __in; int __i; }) { .__in = (status) }).__i))) & 0xff00) >> 8))
 error (SORT_FAILURE, 0, gettext ("%s [-d] terminated abnormally"),
        compress_program);
      --nprocs;
    }

  return cpid;
}





static void
register_proc (pid_t pid)
{
  struct procnode test, *node;

  if (! proctab)
    {
      proctab = hash_initialize (INIT_PROCTAB_SIZE, ((void *)0),
     proctab_hasher,
     proctab_comparator,
     free);
      if (! proctab)
 xalloc_die ();
    }

  test.pid = pid;
  node = hash_lookup (proctab, &test);
  if (node)
    {
      node->state = ALIVE;
      ++node->count;
    }
  else
    {
      node = xmalloc (sizeof *node);
      node->pid = pid;
      node->state = ALIVE;
      node->count = 1;
      hash_insert (proctab, node);
    }
}







static void
update_proc (pid_t pid)
{
  struct procnode test, *node;

  test.pid = pid;
  node = hash_lookup (proctab, &test);
  if (node)
    node->state = ZOMBIE;
}
# 610 "sort.c"
static void
wait_proc (pid_t pid)
{
  struct procnode test, *node;

  test.pid = pid;
  node = hash_lookup (proctab, &test);
  if (node->state == ALIVE)
    reap (pid);

  node->state = ZOMBIE;
  if (! --node->count)
    {
      hash_delete (proctab, node);
      free (node);
    }
}





static void
reap_some (void)
{
  pid_t pid;

  while (0 < nprocs && (pid = reap (-1)))
    update_proc (pid);
}



static void
cleanup (void)
{
  struct tempnode const *node;

  for (node = temphead; node; node = node->next)
    unlink (node->name);
  temphead = ((void *)0);
}



static void
exit_cleanup (void)
{
  if (temphead)
    {


      struct cs_status cs = cs_enter ();
      cleanup ();
      cs_leave (cs);
    }

  close_stdout ();
}




static struct tempnode *
create_temp_file (int *pfd)
{
  static char const slashbase[] = "/sortXXXXXX";
  static size_t temp_dir_index;
  int fd;
  int saved_errno;
  char const *temp_dir = temp_dirs[temp_dir_index];
  size_t len = strlen (temp_dir);
  struct tempnode *node =
    xmalloc (__builtin_offsetof (struct tempnode, name) + len + sizeof slashbase);
  char *file = node->name;
  struct cs_status cs;

  memcpy (file, temp_dir, len);
  memcpy (file + len, slashbase, sizeof slashbase);
  node->next = ((void *)0);
  node->pid = 0;
  if (++temp_dir_index == temp_dir_count)
    temp_dir_index = 0;


  cs = cs_enter ();
  fd = mkstemp_safer (file);
  if (0 <= fd)
    {
      *temptail = node;
      temptail = &node->next;
    }
  saved_errno = (*__errno_location ());
  cs_leave (cs);
  (*__errno_location ()) = saved_errno;

  if (fd < 0)
    die (gettext ("cannot create temporary file"), file);

  *pfd = fd;
  return node;
}







static FILE *
xfopen (const char *file, const char *how)
{
  FILE *fp;

  if (!file)
    fp = stdout;
  else if ((strcmp (file, "-") == 0) && *how == 'r')
    {
      have_read_stdin = 1;
      fp = stdin;
    }
  else
    {
      fp = fopen_safer (file, how);
      if (! fp)
 die (gettext ("open failed"), file);
    }

  return fp;
}



static void
xfclose (FILE *fp, char const *file)
{
  switch (fileno (fp))
    {
    case 0:

      if (feof_unlocked (fp))
 clearerr_unlocked (fp);
      break;

    case 1:

      if (fflush_unlocked (fp) != 0)
 die (gettext ("fflush failed"), file);
      break;

    default:
      if (fclose (fp) != 0)
 die (gettext ("close failed"), file);
      break;
    }
}

static void
dup2_or_die (int oldfd, int newfd)
{
  if (dup2 (oldfd, newfd) < 0)
    error (SORT_FAILURE, (*__errno_location ()), gettext ("dup2 failed"));
}





static pid_t
pipe_fork (int pipefds[2], size_t tries)
{

  struct tempnode *saved_temphead;
  int saved_errno;
  unsigned int wait_retry = 1;
  pid_t pid ;
  struct cs_status cs;

  if (pipe (pipefds) < 0)
    return -1;

  while (tries--)
    {


      cs = cs_enter ();
      saved_temphead = temphead;
      temphead = ((void *)0);

      pid = fork ();
      saved_errno = (*__errno_location ());
      if (pid)
 temphead = saved_temphead;

      cs_leave (cs);
      (*__errno_location ()) = saved_errno;

      if (0 <= pid || (*__errno_location ()) != 11)
 break;
      else
 {
   sleep (wait_retry);
   wait_retry *= 2;
   reap_some ();
 }
    }

  if (pid < 0)
    {
      close (pipefds[0]);
      close (pipefds[1]);
    }
  else if (pid == 0)
    {
      close (0);
      close (1);
    }
  else
    ++nprocs;

  return pid;




}





static char *
create_temp (FILE **pfp, pid_t *ppid)
{
  int tempfd;
  struct tempnode *node = create_temp_file (&tempfd);
  char *name = node->name;

  if (compress_program)
    {
      int pipefds[2];

      node->pid = pipe_fork (pipefds, MAX_FORK_TRIES_COMPRESS);
      if (0 < node->pid)
 {
   close (tempfd);
   close (pipefds[0]);
   tempfd = pipefds[1];

   register_proc (node->pid);
 }
      else if (node->pid == 0)
 {
   close (pipefds[1]);
   dup2_or_die (tempfd, 1);
   close (tempfd);
   dup2_or_die (pipefds[0], 0);
   close (pipefds[0]);

   if (execlp (compress_program, compress_program, (char *) ((void *)0)) < 0)
     error (SORT_FAILURE, (*__errno_location ()), gettext ("couldn't execute %s"),
     compress_program);
 }
      else
 node->pid = 0;
    }

  *pfp = fdopen (tempfd, "w");
  if (! *pfp)
    die (gettext ("couldn't create temporary file"), name);

  if (ppid)
    *ppid = node->pid;

  return name;
}





static FILE *
open_temp (const char *name, pid_t pid)
{
  int tempfd, pipefds[2];
  pid_t child_pid;
  FILE *fp;

  wait_proc (pid);

  tempfd = open (name, 00);
  if (tempfd < 0)
    die (gettext ("couldn't open temporary file"), name);

  child_pid = pipe_fork (pipefds, MAX_FORK_TRIES_DECOMPRESS);
  if (0 < child_pid)
    {
      close (tempfd);
      close (pipefds[1]);
    }
  else if (child_pid == 0)
    {
      close (pipefds[0]);
      dup2_or_die (tempfd, 0);
      close (tempfd);
      dup2_or_die (pipefds[1], 1);
      close (pipefds[1]);

      if (execlp (compress_program, compress_program, "-d", (char *) ((void *)0)) < 0)
 error (SORT_FAILURE, (*__errno_location ()), gettext ("couldn't execute %s -d"),
        compress_program);
    }
  else
    error (SORT_FAILURE, (*__errno_location ()), gettext ("couldn't create process for %s -d"),
    compress_program);

  fp = fdopen (pipefds[0], "r");
  if (! fp)
    die (gettext ("couldn't create temporary file"), name);

  return fp;
}

static void
write_bytes (const char *buf, size_t n_bytes, FILE *fp, const char *output_file)
{
  if (fwrite_unlocked (buf,1,n_bytes,fp) != n_bytes)
    die (gettext ("write failed"), output_file);
}


static void
add_temp_dir (char const *dir)
{
  if (temp_dir_count == temp_dir_alloc)
    temp_dirs = ((void) (!!sizeof (struct { unsigned int verify_error_if_negative_size__: (sizeof *(temp_dirs) != 1) ? 1 : -1; })), x2nrealloc (temp_dirs, &temp_dir_alloc, sizeof *(temp_dirs)));

  temp_dirs[temp_dir_count++] = dir;
}



static void
zaptemp (const char *name)
{
  struct tempnode *volatile *pnode;
  struct tempnode *node;
  struct tempnode *next;
  int unlink_status;
  int unlink_errno = 0;
  struct cs_status cs;

  for (pnode = &temphead; (node = *pnode)->name != name; pnode = &node->next)
    continue;


  next = node->next;
  cs = cs_enter ();
  unlink_status = unlink (name);
  unlink_errno = (*__errno_location ());
  *pnode = next;
  cs_leave (cs);

  if (unlink_status != 0)
    error (0, unlink_errno, gettext ("warning: cannot remove: %s"), name);
  if (! next)
    temptail = pnode;
  free (node);
}
# 994 "sort.c"
static void
inittables (void)
{
  size_t i;

  for (i = 0; i < ((127 * 2 + 1) + 1); ++i)
    {
      blanks[i] = !! ((*__ctype_b_loc ())[(int) ((i))] & (unsigned short int) _ISblank);
      nonprinting[i] = ! ((*__ctype_b_loc ())[(int) ((i))] & (unsigned short int) _ISprint);
      nondictionary[i] = ! ((*__ctype_b_loc ())[(int) ((i))] & (unsigned short int) _ISalnum) && ! ((*__ctype_b_loc ())[(int) ((i))] & (unsigned short int) _ISblank);
      fold_toupper[i] = toupper (i);
    }
# 1031 "sort.c"
}


static void
specify_sort_size (int oi, char c, char const *s)
{
  uintmax_t n;
  char *suffix;
  enum strtol_error e = xstrtoumax (s, &suffix, 10, &n, "EgGkKmMPtTYZ");


  if (e == LONGINT_OK && ((unsigned int) (suffix[-1]) - '0' <= 9))
    {
      if (n <= (18446744073709551615ULL) / 1024)
 n *= 1024;
      else
 e = LONGINT_OVERFLOW;
    }


  if (e == LONGINT_INVALID_SUFFIX_CHAR && ((unsigned int) (suffix[-1]) - '0' <= 9) && ! suffix[1])
    switch (suffix[0])
      {
      case 'b':
 e = LONGINT_OK;
 break;

      case '%':
 {
   double mem = physmem_total () * n / 100;


   if (mem < (18446744073709551615ULL))
     {
       n = mem;
       e = LONGINT_OK;
     }
   else
     e = LONGINT_OVERFLOW;
 }
 break;
      }

  if (e == LONGINT_OK)
    {


      if (n < sort_size)
 return;

      sort_size = n;
      if (sort_size == n)
 {
   sort_size = (((sort_size)>((16 * (2 + sizeof (struct line)))))?(sort_size):((16 * (2 + sizeof (struct line)))));
   return;
 }

      e = LONGINT_OVERFLOW;
    }

  xstrtol_fatal (e, oi, c, long_options, s);
}


static size_t
default_sort_size (void)
{


  double avail = physmem_available ();
  double total = physmem_total ();
  double mem = (((avail)>(total / 8))?(avail):(total / 8));
  struct rlimit rlimit;






  size_t size = (4294967295U);
  if (mem < size)
    size = mem;
  if (getrlimit (RLIMIT_DATA, &rlimit) == 0 && rlimit.rlim_cur < size)
    size = rlimit.rlim_cur;

  if (getrlimit (RLIMIT_AS, &rlimit) == 0 && rlimit.rlim_cur < size)
    size = rlimit.rlim_cur;




  size /= 2;




  if (getrlimit (__RLIMIT_RSS, &rlimit) == 0 && rlimit.rlim_cur / 16 * 15 < size)
    size = rlimit.rlim_cur / 16 * 15;



  return (((size)>((16 * (2 + sizeof (struct line)))))?(size):((16 * (2 + sizeof (struct line)))));
}
# 1142 "sort.c"
static size_t
sort_buffer_size (FILE *const *fps, size_t nfps,
    char *const *files, size_t nfiles,
    size_t line_bytes)
{


  static size_t size_bound;


  size_t worst_case_per_input_byte = line_bytes + 1;



  size_t size = worst_case_per_input_byte + 1;

  size_t i;

  for (i = 0; i < nfiles; i++)
    {
      struct stat st;
      off_t file_size;
      size_t worst_case;

      if ((i < nfps ? fstat (fileno (fps[i]), &st)
    : (strcmp (files[i], "-") == 0) ? fstat (0, &st)
    : stat (files[i], &st))
   != 0)
 die (gettext ("stat failed"), files[i]);

      if (((((st.st_mode)) & 0170000) == (0100000)))
 file_size = st.st_size;
      else
 {


   if (sort_size)
     return sort_size;
   file_size = (1024 * 1024);
 }

      if (! size_bound)
 {
   size_bound = sort_size;
   if (! size_bound)
     size_bound = default_sort_size ();
 }




      worst_case = file_size * worst_case_per_input_byte + 1;
      if (file_size != worst_case / worst_case_per_input_byte
   || size_bound - size <= worst_case)
 return size_bound;
      size += worst_case;
    }

  return size;
}





static void
initbuf (struct buffer *buf, size_t line_bytes, size_t alloc)
{




  for (;;)
    {
      alloc += sizeof (struct line) - alloc % sizeof (struct line);
      buf->buf = malloc (alloc);
      if (buf->buf)
 break;
      alloc /= 2;
      if (alloc <= line_bytes + 1)
 xalloc_die ();
    }

  buf->line_bytes = line_bytes;
  buf->alloc = alloc;
  buf->used = buf->left = buf->nlines = 0;
  buf->eof = 0;
}



static inline struct line *
buffer_linelim (struct buffer const *buf)
{
  return (struct line *) (buf->buf + buf->alloc);
}




static char *
begfield (const struct line *line, const struct keyfield *key)
{
  char *ptr = line->text, *lim = ptr + line->length - 1;
  size_t sword = key->sword;
  size_t schar = key->schar;
  size_t remaining_bytes;




  if (tab != TAB_DEFAULT)
    while (ptr < lim && sword--)
      {
 while (ptr < lim && *ptr != tab)
   ++ptr;
 if (ptr < lim)
   ++ptr;
      }
  else
    while (ptr < lim && sword--)
      {
 while (ptr < lim && blanks[to_uchar (*ptr)])
   ++ptr;
 while (ptr < lim && !blanks[to_uchar (*ptr)])
   ++ptr;
      }

  if (key->skipsblanks)
    while (ptr < lim && blanks[to_uchar (*ptr)])
      ++ptr;


  remaining_bytes = lim - ptr;
  if (schar < remaining_bytes)
    ptr += schar;
  else
    ptr = lim;

  return ptr;
}




static char *
limfield (const struct line *line, const struct keyfield *key)
{
  char *ptr = line->text, *lim = ptr + line->length - 1;
  size_t eword = key->eword, echar = key->echar;
  size_t remaining_bytes;
# 1301 "sort.c"
  if (tab != TAB_DEFAULT)
    while (ptr < lim && eword--)
      {
 while (ptr < lim && *ptr != tab)
   ++ptr;
 if (ptr < lim && (eword | echar))
   ++ptr;
      }
  else
    while (ptr < lim && eword--)
      {
 while (ptr < lim && blanks[to_uchar (*ptr)])
   ++ptr;
 while (ptr < lim && !blanks[to_uchar (*ptr)])
   ++ptr;
      }
# 1372 "sort.c"
  if (key->skipeblanks)
    while (ptr < lim && blanks[to_uchar (*ptr)])
      ++ptr;


  remaining_bytes = lim - ptr;
  if (echar < remaining_bytes)
    ptr += echar;
  else
    ptr = lim;

  return ptr;
}







static _Bool
fillbuf (struct buffer *buf, FILE *fp, char const *file)
{
  struct keyfield const *key = keylist;
  char eol = eolchar;
  size_t line_bytes = buf->line_bytes;
  size_t mergesize = merge_buffer_size - (2 + sizeof (struct line));

  if (buf->eof)
    return 0;

  if (buf->used != buf->left)
    {
      memmove (buf->buf, buf->buf + buf->used - buf->left, buf->left);
      buf->used = buf->left;
      buf->nlines = 0;
    }

  for (;;)
    {
      char *ptr = buf->buf + buf->used;
      struct line *linelim = buffer_linelim (buf);
      struct line *line = linelim - buf->nlines;
      size_t avail = (char *) linelim - buf->nlines * line_bytes - ptr;
      char *line_start = buf->nlines ? line->text + line->length : buf->buf;

      while (line_bytes + 1 < avail)
 {





   size_t readsize = (avail - 1) / (line_bytes + 1);
   size_t bytes_read = fread_unlocked (ptr,1,readsize,fp);
   char *ptrlim = ptr + bytes_read;
   char *p;
   avail -= bytes_read;

   if (bytes_read != readsize)
     {
       if (ferror_unlocked (fp))
  die (gettext ("read failed"), file);
       if (feof_unlocked (fp))
  {
    buf->eof = 1;
    if (buf->buf == ptrlim)
      return 0;
    if (ptrlim[-1] != eol)
      *ptrlim++ = eol;
  }
     }


   while ((p = memchr (ptr, eol, ptrlim - ptr)))
     {
       ptr = p + 1;
       line--;
       line->text = line_start;
       line->length = ptr - line_start;
       mergesize = (((mergesize)>(line->length))?(mergesize):(line->length));
       avail -= line_bytes;

       if (key)
  {


    line->keylim = (key->eword == (4294967295U)
      ? p
      : limfield (line, key));

    if (key->sword != (4294967295U))
      line->keybeg = begfield (line, key);
    else
      {
        if (key->skipsblanks)
   while (blanks[to_uchar (*line_start)])
     line_start++;
        line->keybeg = line_start;
      }
  }

       line_start = ptr;
     }

   ptr = ptrlim;
   if (buf->eof)
     break;
 }

      buf->used = ptr - buf->buf;
      buf->nlines = buffer_linelim (buf) - line;
      if (buf->nlines != 0)
 {
   buf->left = ptr - line_start;
   merge_buffer_size = mergesize + (2 + sizeof (struct line));
   return 1;
 }

      {



 size_t line_alloc = buf->alloc / sizeof (struct line);
 buf->buf = x2nrealloc (buf->buf, &line_alloc, sizeof (struct line));
 buf->alloc = line_alloc * sizeof (struct line);
      }
    }
}





static int
numcompare (const char *a, const char *b)
{
  while (blanks[to_uchar (*a)])
    a++;
  while (blanks[to_uchar (*b)])
    b++;

  return strnumcmp (a, b, decimal_point, thousands_sep);
}

static int
general_numcompare (const char *sa, const char *sb)
{




  char *ea;
  char *eb;
  double a = strtod (sa, &ea);
  double b = strtod (sb, &eb);


  if (sa == ea)
    return sb == eb ? 0 : -1;
  if (sb == eb)
    return 1;




  return (a < b ? -1
   : a > b ? 1
   : a == b ? 0
   : b == b ? -1
   : a == a ? 1
   : memcmp ((char *) &a, (char *) &b, sizeof a));
}




static int
getmonth (char const *month, size_t len)
{
  size_t lo = 0;
  size_t hi = 12;
  char const *monthlim = month + len;

  for (;;)
    {
      if (month == monthlim)
 return 0;
      if (!blanks[to_uchar (*month)])
 break;
      ++month;
    }

  do
    {
      size_t ix = (lo + hi) / 2;
      char const *m = month;
      char const *n = monthtab[ix].name;

      for (;; m++, n++)
 {
   if (!*n)
     return monthtab[ix].val;
   if (m == monthlim || fold_toupper[to_uchar (*m)] < to_uchar (*n))
     {
       hi = ix;
       break;
     }
   else if (fold_toupper[to_uchar (*m)] > to_uchar (*n))
     {
       lo = ix + 1;
       break;
     }
 }
    }
  while (lo < hi);

  return 0;
}


static struct randread_source *randread_source;





static struct md5_ctx
random_state (size_t i)
{


  static struct md5_ctx *state;
  static size_t used;
  static size_t allocated;

  struct md5_ctx *s = &state[i];

  if (used <= i)
    {
      unsigned char buf[16];

      used++;

      if (allocated <= i)
 {
   state = ((void) (!!sizeof (struct { unsigned int verify_error_if_negative_size__: (sizeof *(state) != 1) ? 1 : -1; })), x2nrealloc (state, &allocated, sizeof *(state)));
   s = &state[i];
 }

      randread (randread_source, buf, sizeof buf);
      md5_init_ctx (s);
      md5_process_bytes (buf, sizeof buf, s);
    }

  return *s;
}





static int
cmp_hashes (char const *texta, size_t lena,
     char const *textb, size_t lenb)
{



  int diff;
  size_t i;
  for (i = 0; ; i++)
    {
      uint32_t dig[2][16 / sizeof (uint32_t)];
      struct md5_ctx s[2];
      s[0] = s[1] = random_state (i);
      md5_process_bytes (texta, lena, &s[0]); md5_finish_ctx (&s[0], dig[0]);
      md5_process_bytes (textb, lenb, &s[1]); md5_finish_ctx (&s[1], dig[1]);
      diff = memcmp (dig[0], dig[1], sizeof dig[0]);
      if (diff != 0)
 break;
      if (i == 0 && lena == lenb && memcmp (texta, textb, lena) == 0)
 break;
    }

  return diff;
}




static int
compare_random (char *__restrict texta, size_t lena,
  char *__restrict textb, size_t lenb)
{
  int diff;

  if (! hard_LC_COLLATE)
    diff = cmp_hashes (texta, lena, textb, lenb);
  else
    {




      char *buf = ((void *)0);
      char stackbuf[4000];
      size_t tlena = xmemxfrm (stackbuf, sizeof stackbuf, texta, lena);
      _Bool a_fits = tlena <= sizeof stackbuf;
      size_t tlenb = xmemxfrm ((a_fits ? stackbuf + tlena : ((void *)0)),
          (a_fits ? sizeof stackbuf - tlena : 0),
          textb, lenb);

      if (a_fits && tlena + tlenb <= sizeof stackbuf)
 buf = stackbuf;
      else
 {


   buf = xmalloc (tlena + tlenb + 1);
   xmemxfrm (buf, tlena + 1, texta, lena);
   xmemxfrm (buf + tlena, tlenb + 1, textb, lenb);
 }

      diff = cmp_hashes (buf, tlena, buf + tlena, tlenb);

      if (buf != stackbuf)
 free (buf);
    }

  return diff;
}




static int
keycompare (const struct line *a, const struct line *b)
{
  struct keyfield const *key = keylist;



  char *texta = a->keybeg;
  char *textb = b->keybeg;
  char *lima = a->keylim;
  char *limb = b->keylim;

  int diff;

  for (;;)
    {
      char const *translate = key->translate;
      _Bool const *ignore = key->ignore;


      size_t lena = lima <= texta ? 0 : lima - texta;
      size_t lenb = limb <= textb ? 0 : limb - textb;



      if (key->random)
 diff = compare_random (texta, lena, textb, lenb);
      else if (key->numeric | key->general_numeric)
 {
   char savea = *lima, saveb = *limb;

   *lima = *limb = '\0';
   diff = ((key->numeric ? numcompare : general_numcompare)
    (texta, textb));
   *lima = savea, *limb = saveb;
 }
      else if (key->month)
 diff = getmonth (texta, lena) - getmonth (textb, lenb);


      else if (hard_LC_COLLATE)
 {
   if (ignore || translate)
     {
       char buf[4000];
       size_t size = lena + 1 + lenb + 1;
       char *copy_a = (size <= sizeof buf ? buf : xmalloc (size));
       char *copy_b = copy_a + lena + 1;
       size_t new_len_a, new_len_b, i;


       for (new_len_a = new_len_b = i = 0; i < (((lena)>(lenb))?(lena):(lenb)); i++)
  {
    if (i < lena)
      {
        copy_a[new_len_a] = (translate
        ? translate[to_uchar (texta[i])]
        : texta[i]);
        if (!ignore || !ignore[to_uchar (texta[i])])
   ++new_len_a;
      }
    if (i < lenb)
      {
        copy_b[new_len_b] = (translate
        ? translate[to_uchar (textb[i])]
        : textb [i]);
        if (!ignore || !ignore[to_uchar (textb[i])])
   ++new_len_b;
      }
  }

       diff = xmemcoll (copy_a, new_len_a, copy_b, new_len_b);

       if (sizeof buf < size)
  free (copy_a);
     }
   else if (lena == 0)
     diff = - ((lenb) != 0);
   else if (lenb == 0)
     goto greater;
   else
     diff = xmemcoll (texta, lena, textb, lenb);
 }
      else if (ignore)
 {
# 1815 "sort.c"
   if (translate)
     do { for (;;) { while (texta < lima && ignore[to_uchar (*texta)]) ++texta; while (textb < limb && ignore[to_uchar (*textb)]) ++textb; if (! (texta < lima && textb < limb)) break; diff = to_uchar (translate[to_uchar (*texta)]) - to_uchar (translate[to_uchar (*textb)]); if (diff) goto not_equal; ++texta; ++textb; } diff = (texta < lima) - (textb < limb); } while (0);

   else
     do { for (;;) { while (texta < lima && ignore[to_uchar (*texta)]) ++texta; while (textb < limb && ignore[to_uchar (*textb)]) ++textb; if (! (texta < lima && textb < limb)) break; diff = to_uchar (*texta) - to_uchar (*textb); if (diff) goto not_equal; ++texta; ++textb; } diff = (texta < lima) - (textb < limb); } while (0);
 }
      else if (lena == 0)
 diff = - ((lenb) != 0);
      else if (lenb == 0)
 goto greater;
      else
 {
   if (translate)
     {
       while (texta < lima && textb < limb)
  {
    diff = (to_uchar (translate[to_uchar (*texta++)])
     - to_uchar (translate[to_uchar (*textb++)]));
    if (diff)
      goto not_equal;
  }
     }
   else
     {
       diff = memcmp (texta, textb, (((lena)<(lenb))?(lena):(lenb)));
       if (diff)
  goto not_equal;
     }
   diff = lena < lenb ? -1 : lena != lenb;
 }

      if (diff)
 goto not_equal;

      key = key->next;
      if (! key)
 break;


      if (key->eword != (4294967295U))
 lima = limfield (a, key), limb = limfield (b, key);
      else
 lima = a->text + a->length - 1, limb = b->text + b->length - 1;

      if (key->sword != (4294967295U))
 texta = begfield (a, key), textb = begfield (b, key);
      else
 {
   texta = a->text, textb = b->text;
   if (key->skipsblanks)
     {
       while (texta < lima && blanks[to_uchar (*texta)])
  ++texta;
       while (textb < limb && blanks[to_uchar (*textb)])
  ++textb;
     }
 }
    }

  return 0;

 greater:
  diff = 1;
 not_equal:
  return key->reverse ? -diff : diff;
}




static int
compare (const struct line *a, const struct line *b)
{
  int diff;
  size_t alen, blen;




  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff | unique | stable)
 return diff;
    }



  alen = a->length - 1, blen = b->length - 1;

  if (alen == 0)
    diff = - ((blen) != 0);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    diff = xmemcoll (a->text, alen, b->text, blen);
  else if (! (diff = memcmp (a->text, b->text, (((alen)<(blen))?(alen):(blen)))))
    diff = alen < blen ? -1 : alen != blen;

  return reverse ? -diff : diff;
}






static _Bool
check (char const *file_name, char checkonly)
{
  FILE *fp = xfopen (file_name, "r");
  struct buffer buf;
  struct line temp;
  size_t alloc = 0;
  uintmax_t line_number = 0;
  struct keyfield const *key = keylist;
  _Bool nonunique = ! unique;
  _Bool ordered = 1;

  initbuf (&buf, sizeof (struct line),
    (((merge_buffer_size)>(sort_size))?(merge_buffer_size):(sort_size)));
  temp.text = ((void *)0);

  while (fillbuf (&buf, fp, file_name))
    {
      struct line const *line = buffer_linelim (&buf);
      struct line const *linebase = line - buf.nlines;



      if (alloc && nonunique <= compare (&temp, line - 1))
 {
 found_disorder:
   {
     if (checkonly == 'c')
       {
  struct line const *disorder_line = line - 1;
  uintmax_t disorder_line_number =
    buffer_linelim (&buf) - disorder_line + line_number;
  char hr_buf[(((sizeof (uintmax_t) * 8 - (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1))) * 146 / 485 + (! ((__typeof__ (uintmax_t)) 0 < (__typeof__ (uintmax_t)) -1)) + 1) + 1)];
  fprintf (stderr, gettext ("%s: %s:%s: disorder: "),
    program_name, file_name,
    umaxtostr (disorder_line_number, hr_buf));
  write_bytes (disorder_line->text, disorder_line->length,
        stderr, gettext ("standard error"));
       }

     ordered = 0;
     break;
   }
 }


      while (linebase < --line)
 if (nonunique <= compare (line, line - 1))
   goto found_disorder;

      line_number += buf.nlines;


      if (alloc < line->length)
 {
   do
     {
       alloc *= 2;
       if (! alloc)
  {
    alloc = line->length;
    break;
  }
     }
   while (alloc < line->length);

   temp.text = xrealloc (temp.text, alloc);
 }
      memcpy (temp.text, line->text, line->length);
      temp.length = line->length;
      if (key)
 {
   temp.keybeg = temp.text + (line->keybeg - line->text);
   temp.keylim = temp.text + (line->keylim - line->text);
 }
    }

  xfclose (fp, file_name);
  free (buf.buf);
  free (temp.text);
  return ordered;
}
# 2013 "sort.c"
static void
mergefps (struct sortfile *files, size_t ntemps, size_t nfiles,
   FILE *ofp, char const *output_file)
{
  FILE *fps[16];
  struct buffer buffer[16];
  struct line saved;
  struct line const *savedline = ((void *)0);

  size_t savealloc = 0;
  struct line const *cur[16];
  struct line const *base[16];
  size_t ord[16];


  size_t i;
  size_t j;
  size_t t;
  struct keyfield const *key = keylist;
  saved.text = ((void *)0);


  for (i = 0; i < nfiles; )
    {
      fps[i] = (files[i].pid
  ? open_temp (files[i].name, files[i].pid)
  : xfopen (files[i].name, "r"));
      initbuf (&buffer[i], sizeof (struct line),
        (((merge_buffer_size)>(sort_size / nfiles))?(merge_buffer_size):(sort_size / nfiles)));
      if (fillbuf (&buffer[i], fps[i], files[i].name))
 {
   struct line const *linelim = buffer_linelim (&buffer[i]);
   cur[i] = linelim - 1;
   base[i] = linelim - buffer[i].nlines;
   i++;
 }
      else
 {

   xfclose (fps[i], files[i].name);
   if (i < ntemps)
     {
       ntemps--;
       zaptemp (files[i].name);
     }
   free (buffer[i].buf);
   --nfiles;
   for (j = i; j < nfiles; ++j)
     files[j] = files[j + 1];
 }
    }

  if (! ofp)
    ofp = xfopen (output_file, "w");




  for (i = 0; i < nfiles; ++i)
    ord[i] = i;
  for (i = 1; i < nfiles; ++i)
    if (0 < compare (cur[ord[i - 1]], cur[ord[i]]))
      t = ord[i - 1], ord[i - 1] = ord[i], ord[i] = t, i = 0;


  while (nfiles)
    {
      struct line const *smallest = cur[ord[0]];



      if (unique)
 {
   if (savedline && compare (savedline, smallest))
     {
       savedline = ((void *)0);
       write_bytes (saved.text, saved.length, ofp, output_file);
     }
   if (!savedline)
     {
       savedline = &saved;
       if (savealloc < smallest->length)
  {
    do
      if (! savealloc)
        {
   savealloc = smallest->length;
   break;
        }
    while ((savealloc *= 2) < smallest->length);

    saved.text = xrealloc (saved.text, savealloc);
  }
       saved.length = smallest->length;
       memcpy (saved.text, smallest->text, saved.length);
       if (key)
  {
    saved.keybeg =
      saved.text + (smallest->keybeg - smallest->text);
    saved.keylim =
      saved.text + (smallest->keylim - smallest->text);
  }
     }
 }
      else
 write_bytes (smallest->text, smallest->length, ofp, output_file);


      if (base[ord[0]] < smallest)
 cur[ord[0]] = smallest - 1;
      else
 {
   if (fillbuf (&buffer[ord[0]], fps[ord[0]], files[ord[0]].name))
     {
       struct line const *linelim = buffer_linelim (&buffer[ord[0]]);
       cur[ord[0]] = linelim - 1;
       base[ord[0]] = linelim - buffer[ord[0]].nlines;
     }
   else
     {

       for (i = 1; i < nfiles; ++i)
  if (ord[i] > ord[0])
    --ord[i];
       --nfiles;
       xfclose (fps[ord[0]], files[ord[0]].name);
       if (ord[0] < ntemps)
  {
    ntemps--;
    zaptemp (files[ord[0]].name);
  }
       free (buffer[ord[0]].buf);
       for (i = ord[0]; i < nfiles; ++i)
  {
    fps[i] = fps[i + 1];
    files[i] = files[i + 1];
    buffer[i] = buffer[i + 1];
    cur[i] = cur[i + 1];
    base[i] = base[i + 1];
  }
       for (i = 0; i < nfiles; ++i)
  ord[i] = ord[i + 1];
       continue;
     }
 }





      {
 size_t lo = 1;
 size_t hi = nfiles;
 size_t probe = lo;
 size_t ord0 = ord[0];
 size_t count_of_smaller_lines;

 while (lo < hi)
   {
     int cmp = compare (cur[ord0], cur[ord[probe]]);
     if (cmp < 0 || (cmp == 0 && ord0 < ord[probe]))
       hi = probe;
     else
       lo = probe + 1;
     probe = (lo + hi) / 2;
   }

 count_of_smaller_lines = lo - 1;
 for (j = 0; j < count_of_smaller_lines; j++)
   ord[j] = ord[j + 1];
 ord[count_of_smaller_lines] = ord0;
      }


      if (MAX_PROCS_BEFORE_REAP < nprocs)
 reap_some ();
    }

  if (unique && savedline)
    {
      write_bytes (saved.text, saved.length, ofp, output_file);
      free (saved.text);
    }

  xfclose (ofp, output_file);
}






static inline void
mergelines (struct line *t,
     struct line const *lo, size_t nlo,
     struct line const *hi, size_t nhi)
{
  for (;;)
    if (compare (lo - 1, hi - 1) <= 0)
      {
 *--t = *--lo;
 if (! --nlo)
   {



     return;
   }
      }
    else
      {
 *--t = *--hi;
 if (! --nhi)
   {
     do
       *--t = *--lo;
     while (--nlo);

     return;
   }
      }
}
# 2248 "sort.c"
static void
sortlines (struct line *lines, size_t nlines, struct line *temp)
{
  if (nlines == 2)
    {
      if (0 < compare (&lines[-1], &lines[-2]))
 {
   struct line tmp = lines[-1];
   lines[-1] = lines[-2];
   lines[-2] = tmp;
 }
    }
  else
    {
      size_t nlo = nlines / 2;
      size_t nhi = nlines - nlo;
      struct line *lo = lines;
      struct line *hi = lines - nlo;
      struct line *sorted_lo = temp;

      sortlines (hi, nhi, temp);
      if (1 < nlo)
 sortlines_temp (lo, nlo, sorted_lo);
      else
 sorted_lo[-1] = lo[-1];

      mergelines (lines, sorted_lo, nlo, hi, nhi);
    }
}




static void
sortlines_temp (struct line *lines, size_t nlines, struct line *temp)
{
  if (nlines == 2)
    {



      int swap = (0 < compare (&lines[-1], &lines[-2]));
      temp[-1] = lines[-1 - swap];
      temp[-2] = lines[-2 + swap];
    }
  else
    {
      size_t nlo = nlines / 2;
      size_t nhi = nlines - nlo;
      struct line *lo = lines;
      struct line *hi = lines - nlo;
      struct line *sorted_hi = temp - nlo;

      sortlines_temp (hi, nhi, sorted_hi);
      if (1 < nlo)
 sortlines (lo, nlo, temp);

      mergelines (temp, lo, nlo, sorted_hi, nhi);
    }
}
# 2326 "sort.c"
static size_t
avoid_trashing_input (struct sortfile *files, size_t ntemps,
        size_t nfiles, char const *outfile)
{
  size_t i;
  _Bool got_outstat = 0;
  struct stat outstat;

  for (i = ntemps; i < nfiles; i++)
    {
      _Bool is_stdin = (strcmp (files[i].name, "-") == 0);
      _Bool same;
      struct stat instat;

      if (outfile && (strcmp (outfile, files[i].name) == 0) && !is_stdin)
 same = 1;
      else
 {
   if (! got_outstat)
     {
       if ((outfile
     ? stat (outfile, &outstat)
     : fstat (1, &outstat))
    != 0)
  break;
       got_outstat = 1;
     }

   same = (((is_stdin
      ? fstat (0, &instat)
      : stat (files[i].name, &instat))
     == 0)
    && ((instat).st_ino == (outstat).st_ino && (instat).st_dev == (outstat).st_dev));
 }

      if (same)
 {
   FILE *tftp;
   pid_t pid;
   char *temp = create_temp (&tftp, &pid);
   mergefps (&files[i],0, nfiles - i, tftp, temp);
   files[i].name = temp;
   files[i].pid = pid;
   return i + 1;
 }
    }

  return nfiles;
}






static void
merge (struct sortfile *files, size_t ntemps, size_t nfiles,
       char const *output_file)
{
  while (16 < nfiles)
    {

      size_t in;


      size_t out;



      size_t remainder;


      size_t cheap_slots;


      for (out = in = 0; out < nfiles / 16; out++, in += 16)
 {
   FILE *tfp;
   pid_t pid;
   char *temp = create_temp (&tfp, &pid);
   size_t nt = (((ntemps)<(16))?(ntemps):(16));
   ntemps -= nt;
   mergefps (&files[in], nt, 16, tfp, temp);
   files[out].name = temp;
   files[out].pid = pid;
 }

      remainder = nfiles - in;
      cheap_slots = 16 - out % 16;

      if (cheap_slots < remainder)
 {



   size_t nshortmerge = remainder - cheap_slots + 1;
   FILE *tfp;
   pid_t pid;
   char *temp = create_temp (&tfp, &pid);
   size_t nt = (((ntemps)<(nshortmerge))?(ntemps):(nshortmerge));
   ntemps -= nt;
   mergefps (&files[in], nt, nshortmerge, tfp, temp);
   files[out].name = temp;
   files[out++].pid = pid;
   in += nshortmerge;
 }



      memmove(&files[out], &files[in], (nfiles - in) * sizeof *files);
      ntemps += out;
      nfiles -= in - out;
    }

  nfiles = avoid_trashing_input (files, ntemps, nfiles, output_file);
  mergefps (files, ntemps, nfiles, ((void *)0), output_file);
}



static void
sort (char * const *files, size_t nfiles, char const *output_file)
{
  struct buffer buf;
  size_t ntemps = 0;
  _Bool output_file_created = 0;

  buf.alloc = 0;

  while (nfiles)
    {
      char const *temp_output;
      char const *file = *files;
      FILE *fp = xfopen (file, "r");
      FILE *tfp;
      size_t bytes_per_line = (2 * sizeof (struct line)
          - sizeof (struct line) / 2);

      if (! buf.alloc)
 initbuf (&buf, bytes_per_line,
   sort_buffer_size (&fp, 1, files, nfiles, bytes_per_line));
      buf.eof = 0;
      files++;
      nfiles--;

      while (fillbuf (&buf, fp, file))
 {
   struct line *line;
   struct line *linebase;

   if (buf.eof && nfiles
       && (bytes_per_line + 1
    < (buf.alloc - buf.used - bytes_per_line * buf.nlines)))
     {



       buf.left = buf.used;
       break;
     }

   line = buffer_linelim (&buf);
   linebase = line - buf.nlines;
   if (1 < buf.nlines)
     sortlines (line, buf.nlines, linebase);
   if (buf.eof && !nfiles && !ntemps && !buf.left)
     {
       xfclose (fp, file);
       tfp = xfopen (output_file, "w");
       temp_output = output_file;
       output_file_created = 1;
     }
   else
     {
       ++ntemps;
       temp_output = create_temp (&tfp, ((void *)0));
     }

   do
     {
       line--;
       write_bytes (line->text, line->length, tfp, temp_output);
       if (unique)
  while (linebase < line && compare (line, line - 1) == 0)
    line--;
     }
   while (linebase < line);

   xfclose (tfp, temp_output);


   if (MAX_PROCS_BEFORE_REAP < nprocs)
     reap_some ();

   if (output_file_created)
     goto finish;
 }
      xfclose (fp, file);
    }

 finish:
  free (buf.buf);

  if (! output_file_created)
    {
      size_t i;
      struct tempnode *node = temphead;
      struct sortfile *tempfiles = xnmalloc (ntemps, sizeof *tempfiles);
      for (i = 0; node; i++)
 {
   tempfiles[i].name = node->name;
   tempfiles[i].pid = node->pid;
   node = node->next;
 }
      merge (tempfiles, ntemps, ntemps, output_file);
      free (tempfiles);
    }
}



static void
insertkey (struct keyfield *key_arg)
{
  struct keyfield **p;
  struct keyfield *key = xmemdup (key_arg, sizeof *key);

  for (p = &keylist; *p; p = &(*p)->next)
    continue;
  *p = key;
  key->next = ((void *)0);
}



static void badfieldspec (char const *, char const *)
     __attribute__ ((__noreturn__));
static void
badfieldspec (char const *spec, char const *msgid)
{
  error (SORT_FAILURE, 0, gettext ("%s: invalid field specification %s"),
  gettext (msgid), quote (spec));
  abort ();
}



static void incompatible_options (char const *) __attribute__ ((__noreturn__));
static void
incompatible_options (char const *opts)
{
  error (SORT_FAILURE, 0, gettext ("options `-%s' are incompatible"), opts);
  abort ();
}



static void
check_ordering_compatibility (void)
{
  struct keyfield const *key;

  for (key = keylist; key; key = key->next)
    if ((1 < (key->random + key->numeric + key->general_numeric + key->month
       + !!key->ignore))
 || (key->random && key->translate))
      {
 char opts[7];
 char *p = opts;
 if (key->ignore == nondictionary)
   *p++ = 'd';
 if (key->translate)
   *p++ = 'f';
 if (key->general_numeric)
   *p++ = 'g';
 if (key->ignore == nonprinting)
   *p++ = 'i';
 if (key->month)
   *p++ = 'M';
 if (key->numeric)
   *p++ = 'n';
 if (key->random)
   *p++ = 'R';
 *p = '\0';
 incompatible_options (opts);
      }
}







static char const *
parse_field_count (char const *string, size_t *val, char const *msgid)
{
  char *suffix;
  uintmax_t n;

  switch (xstrtoumax (string, &suffix, 10, &n, ""))
    {
    case LONGINT_OK:
    case LONGINT_INVALID_SUFFIX_CHAR:
      *val = n;
      if (*val == n)
 break;

    case LONGINT_OVERFLOW:
    case LONGINT_OVERFLOW | LONGINT_INVALID_SUFFIX_CHAR:
      *val = (4294967295U);
      break;

    case LONGINT_INVALID:
      if (msgid)
 error (SORT_FAILURE, 0, gettext ("%s: invalid count at start of %s"),
        gettext (msgid), quote (string));
      return ((void *)0);
    }

  return suffix;
}



static void
sighandler (int sig)
{
  if (! 1)
    signal (sig, ((__sighandler_t) 1));

  cleanup ();

  signal (sig, ((__sighandler_t) 0));
  raise (sig);
}






static char *
set_ordering (const char *s, struct keyfield *key, enum blanktype blanktype)
{
  while (*s)
    {
      switch (*s)
 {
 case 'b':
   if (blanktype == bl_start || blanktype == bl_both)
     key->skipsblanks = 1;
   if (blanktype == bl_end || blanktype == bl_both)
     key->skipeblanks = 1;
   break;
 case 'd':
   key->ignore = nondictionary;
   break;
 case 'f':
   key->translate = fold_toupper;
   break;
 case 'g':
   key->general_numeric = 1;
   break;
 case 'i':


   if (! key->ignore)
     key->ignore = nonprinting;
   break;
 case 'M':
   key->month = 1;
   break;
 case 'n':
   key->numeric = 1;
   break;
 case 'R':
   key->random = 1;
   break;
 case 'r':
   key->reverse = 1;
   break;
 default:
   return (char *) s;
 }
      ++s;
    }
  return (char *) s;
}

static struct keyfield *
key_init (struct keyfield *key)
{
  memset (key, 0, sizeof *key);
  key->eword = (4294967295U);
  return key;
}

int
main (int argc, char **argv)
{
  struct keyfield *key;
  struct keyfield key_buf;
  struct keyfield gkey;
  char const *s;
  int c = 0;
  char checkonly = 0;
  _Bool mergeonly = 0;
  char *random_source = ((void *)0);
  _Bool need_random = 0;
  size_t nfiles = 0;
  _Bool posixly_correct = (getenv ("POSIXLY_CORRECT") != ((void *)0));
  _Bool obsolete_usage = (posix2_version () < 200112);
  char **files;
  char const *outfile = ((void *)0);

  ;
  program_name = argv[0];
  setlocale (__LC_ALL, "");
  bindtextdomain ("coreutils", "/usr/local/share/locale");
  textdomain ("coreutils");

  initialize_exit_failure (SORT_FAILURE);

  hard_LC_COLLATE = hard_locale (__LC_COLLATE);





  {
    struct lconv const *locale = localeconv ();




    decimal_point = to_uchar (locale->decimal_point[0]);
    if (! decimal_point || locale->decimal_point[1])
      decimal_point = '.';


    thousands_sep = to_uchar (*locale->thousands_sep);
    if (! thousands_sep || locale->thousands_sep[1])
      thousands_sep = -1;
  }

  have_read_stdin = 0;
  inittables ();

  {
    size_t i;
    static int const sig[] =
      {

 14, 1, 2, 13, 3, 15,

 29,


 27,


 26,


 24,


 25,

      };
    enum { nsigs = sizeof sig / sizeof sig[0] };


    struct sigaction act;

    sigemptyset (&caught_signals);
    for (i = 0; i < nsigs; i++)
      {
 sigaction (sig[i], ((void *)0), &act);
 if (act.__sigaction_handler.sa_handler != ((__sighandler_t) 1))
   sigaddset (&caught_signals, sig[i]);
      }

    act.__sigaction_handler.sa_handler = sighandler;
    act.sa_mask = caught_signals;
    act.sa_flags = 0;

    for (i = 0; i < nsigs; i++)
      if (sigismember (&caught_signals, sig[i]))
 sigaction (sig[i], &act, ((void *)0));
# 2825 "sort.c"
  }


  atexit (exit_cleanup);

  gkey.sword = gkey.eword = (4294967295U);
  gkey.ignore = ((void *)0);
  gkey.translate = ((void *)0);
  gkey.numeric = gkey.general_numeric = gkey.random = 0;
  gkey.month = gkey.reverse = 0;
  gkey.skipsblanks = gkey.skipeblanks = 0;

  files = xnmalloc (argc, sizeof *files);

  for (;;)
    {




      int oi = -1;

      if (c == -1
   || (posixly_correct && nfiles != 0
       && ! (obsolete_usage
      && ! checkonly
      && optind != argc
      && argv[optind][0] == '-' && argv[optind][1] == 'o'
      && (argv[optind][2] || optind + 1 != argc)))
   || ((c = getopt_long (argc, argv, short_options,
    long_options, &oi))
       == -1))
 {
   if (argc <= optind)
     break;
   files[nfiles++] = argv[optind++];
 }
      else switch (c)
 {
 case 1:
   key = ((void *)0);
   if (optarg[0] == '+')
     {
       _Bool minus_pos_usage = (optind != argc && argv[optind][0] == '-'
          && ((unsigned int) (argv[optind][1]) - '0' <= 9));
       obsolete_usage |= minus_pos_usage & ~posixly_correct;
       if (obsolete_usage)
  {


    key = key_init (&key_buf);
    s = parse_field_count (optarg + 1, &key->sword, ((void *)0));
    if (s && *s == '.')
      s = parse_field_count (s + 1, &key->schar, ((void *)0));
    if (! (key->sword | key->schar))
      key->sword = (4294967295U);
    if (! s || *set_ordering (s, key, bl_start))
      key = ((void *)0);
    else
      {
        if (minus_pos_usage)
   {
     char const *optarg1 = argv[optind++];
     s = parse_field_count (optarg1 + 1, &key->eword,
          "invalid number after `-'");
     if (*s == '.')
       s = parse_field_count (s + 1, &key->echar,
            "invalid number after `.'");
     if (*set_ordering (s, key, bl_end))
       badfieldspec (optarg1,
          "stray character in field spec");
   }
        insertkey (key);
      }
  }
     }
   if (! key)
     files[nfiles++] = optarg;
   break;

 case 'b':
 case 'd':
 case 'f':
 case 'g':
 case 'i':
 case 'M':
 case 'n':
 case 'r':
 case 'R':
   {
     char str[2];
     str[0] = c;
     str[1] = '\0';
     set_ordering (str, &gkey, bl_both);
   }
   break;

 case CHECK_OPTION:
   c = (optarg
        ? ((check_types) [__xargmatch_internal ("--check", optarg, check_args, (char const *) (check_types), sizeof *(check_types), argmatch_die)])
        : 'c');

 case 'c':
 case 'C':
   if (checkonly && checkonly != c)
     incompatible_options ("cC");
   checkonly = c;
   break;

 case COMPRESS_PROGRAM_OPTION:
   if (compress_program && !(strcmp (compress_program, optarg) == 0))
     error (SORT_FAILURE, 0, gettext ("multiple compress programs specified"));
   compress_program = optarg;
   break;

 case 'k':
   key = key_init (&key_buf);


   s = parse_field_count (optarg, &key->sword,
     "invalid number at field start");
   if (! key->sword--)
     {

       badfieldspec (optarg, "field number is zero");
     }
   if (*s == '.')
     {
       s = parse_field_count (s + 1, &key->schar,
         "invalid number after `.'");
       if (! key->schar--)
  {

    badfieldspec (optarg, "character offset is zero");
  }
     }
   if (! (key->sword | key->schar))
     key->sword = (4294967295U);
   s = set_ordering (s, key, bl_start);
   if (*s != ',')
     {
       key->eword = (4294967295U);
       key->echar = 0;
     }
   else
     {

       s = parse_field_count (s + 1, &key->eword,
         "invalid number after `,'");
       if (! key->eword--)
  {

    badfieldspec (optarg, "field number is zero");
  }
       if (*s == '.')
  s = parse_field_count (s + 1, &key->echar,
           "invalid number after `.'");
       else
  {

    key->eword++;
  }
       s = set_ordering (s, key, bl_end);
     }
   if (*s)
     badfieldspec (optarg, "stray character in field spec");
   insertkey (key);
   break;

 case 'm':
   mergeonly = 1;
   break;

 case 'o':
   if (outfile && !(strcmp (outfile, optarg) == 0))
     error (SORT_FAILURE, 0, gettext ("multiple output files specified"));
   outfile = optarg;
   break;

 case RANDOM_SOURCE_OPTION:
   if (random_source && !(strcmp (random_source, optarg) == 0))
     error (SORT_FAILURE, 0, gettext ("multiple random sources specified"));
   random_source = optarg;
   break;

 case 's':
   stable = 1;
   break;

 case 'S':
   specify_sort_size (oi, c, optarg);
   break;

 case 't':
   {
     char newtab = optarg[0];
     if (! newtab)
       error (SORT_FAILURE, 0, gettext ("empty tab"));
     if (optarg[1])
       {
  if ((strcmp (optarg, "\\0") == 0))
    newtab = '\0';
  else
    {




      error (SORT_FAILURE, 0, gettext ("multi-character tab %s"),
      quote (optarg));
    }
       }
     if (tab != TAB_DEFAULT && tab != newtab)
       error (SORT_FAILURE, 0, gettext ("incompatible tabs"));
     tab = newtab;
   }
   break;

 case 'T':
   add_temp_dir (optarg);
   break;

 case 'u':
   unique = 1;
   break;

 case 'y':
# 3062 "sort.c"
   if (optarg == argv[optind - 1])
     {
       char const *p;
       for (p = optarg; ((unsigned int) (*p) - '0' <= 9); p++)
  continue;
       optind -= (*p != '\0');
     }
   break;

 case 'z':
   eolchar = 0;
   break;

 case GETOPT_HELP_CHAR: usage (0); break;;

 case GETOPT_VERSION_CHAR: version_etc (stdout, "sort", "GNU coreutils", "6.10", "Mike Haertel", "Paul Eggert", (char *) ((void *)0)); exit (0); break;;

 default:
   usage (SORT_FAILURE);
 }
    }


  for (key = keylist; key; key = key->next)
    {
      if (! (key->ignore || key->translate
             || (key->skipsblanks | key->reverse
                 | key->skipeblanks | key->month | key->numeric
                 | key->general_numeric
                 | key->random)))
        {
          key->ignore = gkey.ignore;
          key->translate = gkey.translate;
          key->skipsblanks = gkey.skipsblanks;
          key->skipeblanks = gkey.skipeblanks;
          key->month = gkey.month;
          key->numeric = gkey.numeric;
          key->general_numeric = gkey.general_numeric;
          key->random = gkey.random;
          key->reverse = gkey.reverse;
        }

      need_random |= key->random;
    }

  if (!keylist && (gkey.ignore || gkey.translate
     || (gkey.skipsblanks | gkey.skipeblanks | gkey.month
         | gkey.numeric | gkey.general_numeric
                       | gkey.random)))
    {
      insertkey (&gkey);
      need_random |= gkey.random;
    }

  check_ordering_compatibility ();

  reverse = gkey.reverse;

  if (need_random)
    {
      randread_source = randread_new (random_source, 16);
      if (! randread_source)
 die (gettext ("open failed"), random_source);
    }

  if (temp_dir_count == 0)
    {
      char const *tmp_dir = getenv ("TMPDIR");
      add_temp_dir (tmp_dir ? tmp_dir : "/tmp");
    }

  if (nfiles == 0)
    {
      static char *minus = "-";
      nfiles = 1;
      free (files);
      files = &minus;
    }

  if (checkonly)
    {
      if (nfiles > 1)
 error (SORT_FAILURE, 0, gettext ("extra operand %s not allowed with -%c"),
        quote (files[1]), checkonly);

      if (outfile)
 {
   static char opts[] = {0, 'o', 0};
   opts[0] = checkonly;
   incompatible_options (opts);
 }



      exit (check (files[0], checkonly) ? 0 : SORT_OUT_OF_ORDER);
    }

  if (mergeonly)
    {
      struct sortfile *sortfiles = xcalloc (nfiles, sizeof *sortfiles);
      size_t i;

      for (i = 0; i < nfiles; ++i)
 sortfiles[i].name = files[i];

      merge (sortfiles, 0, nfiles, outfile);
      ;
    }
  else
    sort (files, nfiles, outfile);

  if (have_read_stdin && fclose (stdin) == (-1))
    die (gettext ("close failed"), "-");

  exit (0);
}
