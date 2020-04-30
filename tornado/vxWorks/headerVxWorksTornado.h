/*
 * Copyright(c) 1997-99 FRIDU a Free Software Company
 * 
 * File   	: libWtxHost.h Interface for VxWorks/Tornado test lib
 * Projet       : jWrap
 * SubModule    : VxWorks/Tornado Target interface
 * Author       : Fulup Le Foll (Fulup@frud.com)
 * 
 * Last: 
 *  Author      : $Author: Fulup $
 *  Date        : $Date: 1999/03/22 10:11:49 $
 *  Revision    : $Revision: 1.4 $
 *  Source      : $Source: /Master/jWrap/tornado/vxWorks/headerVxWorksTornado.h,v $
 * 
 * Modification History
 * -------------------
 * 01a,15feb99,Fulup,written
 * 
 * -----------------------------------------------------------------------*/

/* -------------------------------------------------------------
 *   Help     : VxWorks Target interface thru target server
 *   Interface: VxWorks
 *-------------------------------------------------------------*/



/* ----------------------------------------------
 * Only use VxWorks def for CPP
 * ---------------------------------------------*/
#ifndef JWRAP_CC2TORNADO
#  include <target/h/types/vxParams.h>
#  define PATH_MAX        _PARM_PATH_MAX  /* max pathname length excluding EOS */ 
#  define NAME_MAX        _PARM_NAME_MAX  /* max filename length excluding EOS */
#else
#  include <../../target/h/types/vxParams.h>
#endif


/* ----------------------------------------------
 * hack to compile standard type on host side
 * ---------------------------------------------*/

#define time_t    long
#define uint_t    unsigned int
#define clock_t   long
#define timespec  vx_timespec
#define va_list   void*
#define wchar_t   char
#define STATUS    int
#define UINT32    int
#define BOOL      int
#define FUNCPTR   void*

typedef void*     clockid_t;
typedef void*     timer_t;
typedef void*     MODULE_ID;
typedef void*     SYMTAB_ID;
typedef char*     dirpath;
/* -----------------------------
 *  vxTypeBase.h
 * ----------------------------*/
typedef struct {
  int quot;
  int rem;
} div_t;

/* -----------------------------
 * aio.h
 * ----------------------------*/
// type to map onto cookies 
typedef void* vx_off_t;
typedef void* vx_SigVect;
typedef void* vx_AIO_SYS;

// extract from WRS include file
struct aiocb
    {
    int			aio_fildes;		/* file descriptor */
    vx_off_t		aio_offset;		/* file offset */
    void *	        aio_buf;		/* location of buffer */
    size_t		aio_nbytes;		/* length of transfer */ 
    int			aio_reqprio;		/* request priority offset */
    vx_SigVect      	aio_sigevent;		/* signal number and value */
    int			aio_lio_opcode;		/* operation to be performed */

    /* WRS addition */
    vx_AIO_SYS		aio_sys;    		/* implementation-specific */
    };

/* aio_cancel() return values */

#define	AIO_CANCELED			1	/* operations canceled */
#define	AIO_NOTCANCELED			2	/* operations are in progress */
#define	AIO_ALLDONE			3	/* operations complete */

/* lio_listio()  modes */

#define	LIO_WAIT			4	/* wait for completion */
#define	LIO_NOWAIT			5	/* don't wait for completion */

/* lio_listio() operations */
					 	/* lio op codes */
#define	LIO_READ			0	/* read operation */
#define	LIO_WRITE			1	/* write operation */
#define	LIO_NOP				2	/* no transfer operation*/


/* -----------------------------
 * utime.h
 * ----------------------------*/
struct utimbuf
    {
    time_t	actime;		/* set the access time */
    time_t	modtime;	/* set the modification time */
    };

extern int utime (char * file, struct utimbuf * newTimes);


/* -----------------------------
 * time.h
 * ----------------------------*/

#define CLOCK_REALTIME	0x0	/* system wide realtime clock */
#define TIMER_ABSTIME	0x1	/* absolute time */


struct tm
	{
	int tm_sec;	/* seconds after the minute	- [0, 59] */
	int tm_min;	/* minutes after the hour	- [0, 59] */
	int tm_hour;	/* hours after midnight		- [0, 23] */
	int tm_mday;	/* day of the month		- [1, 31] */
	int tm_mon;	/* months since January		- [0, 11] */
	int tm_year;	/* years since 1900	*/
	int tm_wday;	/* days since Sunday		- [0, 6] */
	int tm_yday;	/* days since January 1		- [0, 365] */
	int tm_isdst;	/* Daylight Saving Time flag */
	};

struct timespec
    {
    					/* interval = tv_sec*10**9 + tv_nsec */
    time_t tv_sec;			/* seconds */
    long tv_nsec;			/* nanoseconds (0 - 1,000,000,000) */
    };

struct itimerspec
    {
    struct timespec it_interval;	/* timer period (reload value) */
    struct timespec it_value;		/* timer expiration */
    };

#define	_POSIX_CLOCKRES_MIN	20	/* milliseconds (1/50th second) */
#define	_POSIX_INTERVAL_MAX	1092	/* max. seconds */
#define	_POSIX_TIMER_MAX	32	/* max. per task */
#define	_POSIX_DELAYTIMER_MAX	32	/* max. expired timers */


// type to map onto cookies 

/* -----------------------------
 * signal.h
 * ----------------------------*/

#define SIGEV_NONE	0
#define SIGEV_SIGNAL	1
#define	SIGHUP	1	/* hangup */
#define	SIGINT	2	/* interrupt */
#define	SIGQUIT	3	/* quit */
#define	SIGILL	4	/* illegal instruction (not reset when caught) */
#define	SIGTRAP	5	/* trace trap (not reset when caught) */
#define	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#define	SIGEMT	7	/* EMT instruction */
#define	SIGFPE	8	/* floating point exception */
#define	SIGKILL	9	/* kill (cannot be caught or ignored) */
#define	SIGBUS	10	/* bus error */
#define	SIGSEGV	11	/* segmentation violation */
#define SIGFMT	12	/* STACK FORMAT ERROR (not posix) */
#define	SIGPIPE	13	/* write on a pipe with no one to read it */
#define	SIGALRM	14	/* alarm clock */
#define	SIGTERM	15	/* software termination signal from kill */

#define	SIGSTOP	17	/* sendable stop signal not from tty */
#define	SIGTSTP	18	/* stop signal from tty */
#define	SIGCONT	19	/* continue a stopped process */
#define	SIGCHLD	20	/* to parent on child stop or exit */
#define	SIGTTIN	21	/* to readers pgrp upon background tty read */
#define	SIGTTOU	22	/* like TTIN for output if (tp->t_local&LTOSTOP) */

#define	SIGUSR1 30	/* user defined signal 1 */
#define	SIGUSR2 31	/* user defined signal 2 */

#define SIGRTMIN	23	/* Realtime signal min */
#define SIGRTMAX	29	/* Realtime signal max */

/**
 * The sa_flags in struct sigaction
 */
#define SA_NOCLDSTOP	0x0001	/* Do not generate SIGCHLD when children stop */
#define SA_SIGINFO	0x0002	/* Pass additional siginfo structure */
#define SA_ONSTACK	0x0004	/* (Not posix) Run on sigstack */
#define SA_INTERRUPT	0x0008	/* (Not posix) Don't restart the function */
#define SA_RESETHAND	0x0010	/* (Not posix) Reset the handler, like sysV */

/**
 * The how in sigprocmask()
 */
#define SIG_BLOCK	1
#define SIG_UNBLOCK	2
#define SIG_SETMASK	3

/**
 * The si_code returned in siginfo
 */
#define SI_SYNC		0	/* (Not posix) gernerated by hardware */
#define SI_KILL		1	/* signal from .1 kill() function */
#define SI_QUEUE	2	/* signal from .4 sigqueue() function */
#define SI_TIMER	3	/* signal from expiration of a .4 timer */
#define SI_ASYNCIO	4	/* signal from completion of an async I/O */
#define SI_MESGQ	5	/* signal from arrival of a message */

typedef unsigned long sigset_t;
typedef unsigned char sig_atomic_t;

union sigval
    {
    int			sival_int;
    void		*sival_ptr;
    };

struct sigevent
    {
    int			sigev_signo;
    union sigval	sigev_value;
    int			sigev_notify;
    };

typedef struct siginfo
    {
    int			si_signo;
    int			si_code;
    union sigval	si_value;
    } siginfo_t;

struct sigaction
    {
    union
	{
	void		*handler;
	void		*action;
	}		sa_u;
    sigset_t		sa_mask;
    int			sa_flags;
    };

/* ---------------------------------------------------
 *  lstLib.h
 * ---------------------------------------------------*/
typedef struct node		/* Node of a linked list. */
    {
    struct node *next;		/* Points at the next node in the list */
    struct node *previous;	/* Points at the previous node in the list */
    } NODE;


typedef struct			/* Header for a linked list. */
    {
    NODE node;			/* Header list node */
    int count;			/* Number of nodes in list */
    } LIST;

/* ---------------------------------------------------
 *  bootLib.h
 * ---------------------------------------------------*/
#define BOOT_DEV_LEN		20	/* max chars in device name */
#define BOOT_HOST_LEN		20	/* max chars in host name */
#define BOOT_ADDR_LEN		30	/* max chars in net addr */
#define BOOT_FILE_LEN		80	/* max chars in file name */
#define BOOT_USR_LEN		20	/* max chars in user name */
#define BOOT_PASSWORD_LEN	20	/* max chars in password */
#define BOOT_OTHER_LEN		80	/* max chars in "other" field */

#define BOOT_FIELD_LEN		80	/* max chars in boot field */

typedef struct				/* BOOT_PARAMS */
    {
    char bootDev [BOOT_DEV_LEN];	/* boot device code */
    char hostName [BOOT_HOST_LEN];	/* name of host */
    char targetName [BOOT_HOST_LEN];	/* name of target */
    char ead [BOOT_ADDR_LEN];		/* ethernet internet addr */
    char bad [BOOT_ADDR_LEN];		/* backplane internet addr */
    char had [BOOT_ADDR_LEN];		/* host internet addr */
    char gad [BOOT_ADDR_LEN];		/* gateway internet addr */
    char bootFile [BOOT_FILE_LEN];	/* name of boot file */
    char startupScript [BOOT_FILE_LEN];	/* name of startup script file */
    char usr [BOOT_USR_LEN];		/* user name */
    char passwd [BOOT_PASSWORD_LEN];	/* password */
    char other [BOOT_OTHER_LEN];	/* available for applications */
    int  procNum;			/* processor number */
    int  flags;				/* configuration flags */
    } BOOT_PARAMS;


/* --------------------------------------------------------
 *  in.h
 * -------------------------------------------------------*/
/*
 * Protocols
 */
#define	IPPROTO_IP		0		/* dummy for IP */
#define	IPPROTO_ICMP		1		/* control message protocol */
#define	IPPROTO_GGP		3		/* gateway^2 (deprecated) */
#define	IPPROTO_TCP		6		/* tcp */
#define	IPPROTO_EGP		8		/* exterior gateway protocol */
#define	IPPROTO_PUP		12		/* pup */
#define	IPPROTO_UDP		17		/* user datagram protocol */
#define	IPPROTO_IDP		22		/* xns idp */

#define	IPPROTO_RAW		255		/* raw IP packet */
#define	IPPROTO_MAX		256


/*
 * Ports < IPPORT_RESERVED are reserved for
 * privileged processes (e.g. root).
 * Ports > IPPORT_USERRESERVED are reserved
 * for servers, not necessarily privileged.
 */
#define	IPPORT_RESERVED		1024
#define	IPPORT_USERRESERVED	5000

/*
 * Link numbers
 */
#define	IMPLINK_IP		155
#define	IMPLINK_LOWEXPER	156
#define	IMPLINK_HIGHEXPER	158

/*
 * Internet address (a structure for historical reasons)
 */
struct in_addr {
	u_long s_addr;
};

#define INADDR_ANY              0x00000000
#define INADDR_BROADCAST        0xffffffff      /* must be masked */
#define INADDR_NONE             0xffffffff              /* -1 return */

#define IN_LOOPBACKNET          127                     /* official! */


/*
 * Socket address, internet style.
 */
struct sockaddr_in {
	short	sin_family;
	u_short	sin_port;
	struct	in_addr sin_addr;
	char	sin_zero[8];
};

/*
 * Options for use with [gs]etsockopt at the IP level.
 */
#define	IP_OPTIONS	1		/* set/get IP per-packet options */



/* -----------------------------
 * hostlib.h
 * ----------------------------*/
#define MAXHOSTNAMELEN 	64

/* status messages */

#define S_hostLib_UNKNOWN_HOST			(M_hostLib | 1)
#define S_hostLib_HOST_ALREADY_ENTERED		(M_hostLib | 2)

typedef struct hostname_struct
    {
    struct hostname_struct *link;
    char *name;
    } HOSTNAME;

typedef struct
    {
    NODE node;
    HOSTNAME hostName;
    struct in_addr netAddr;
    } HOSTENTRY;

/* --------------------------------------------------------
 *  bottpLib.h
 * -------------------------------------------------------*/
#define IPPORT_BOOTPS           67
#define IPPORT_BOOTPC           68

#define BOOTREQUEST             1		/* BOOTP operations	*/
#define BOOTREPLY               2

#define SIZE_VEND		64
#define SIZE_FILE		128

typedef struct bootp_msg
    {
    unsigned char	bp_op;			/* packet opcode type	*/
    unsigned char	bp_htype;       	/* hardware addr type	*/
    unsigned char	bp_hlen;		/* hardware addr length */
    unsigned char	bp_hops;		/* gateway hops 	*/
    unsigned long	bp_xid;			/* transaction ID 	*/
    unsigned short	bp_secs;		/* seconds since boot 	*/
    unsigned short	bp_unused;
    struct in_addr	bp_ciaddr;		/* client IP address 	*/
    struct in_addr	bp_yiaddr;		/* 'your' IP address 	*/
    struct in_addr	bp_siaddr;		/* server IP address 	*/
    struct in_addr	bp_giaddr;		/* gateway IP address 	*/
    unsigned char	bp_chaddr [16];		/* client hardware addr	*/
    unsigned char	bp_sname [64];		/* server host name 	*/
    unsigned char	bp_file [SIZE_FILE];	/* boot file name 	*/
    unsigned char	bp_vend [SIZE_VEND];	/* vendor-specific area */
    } BOOTP_MSG;

#define TAG_PAD                 	0	/* 1048 vendor tags */
#define TAG_SUBNET_MASK         	1
#define TAG_TIME_OFFSET         	2
#define TAG_GATEWAY             	3
#define TAG_TIME_SERVER         	4
#define TAG_NAME_SERVER         	5
#define TAG_DOMAIN_SERVER       	6
#define TAG_LOG_SERVER          	7
#define TAG_COOKIE_SERVER       	8
#define TAG_LPR_SERVER          	9
#define TAG_IMPRESS_SERVER      	10
#define TAG_RLP_SERVER          	11
#define TAG_HOSTNAME            	12
#define TAG_BOOTSIZE            	13
#define TAG_END                 	255

/* error values */

#define S_bootpLib_INVALID_ARGUMENT	(M_bootpLib | 1)
#define S_bootpLib_INVALID_COOKIE	(M_bootpLib | 2)
#define S_bootpLib_NO_BROADCASTS	(M_bootpLib | 3)
#define S_bootpLib_PARSE_ERROR		(M_bootpLib | 4)
#define S_bootpLib_INVALID_TAG		(M_bootpLib | 5)
#define S_bootpLib_TIME_OUT		(M_bootpLib | 6)

/* -----------------------------
 * cache.h
 * ----------------------------*/
/* Cache types */

#define	_INSTRUCTION_CACHE 	0	/* Instruction Cache(s) */
#define	_DATA_CACHE		1	/* Data Cache(s) */
#define	_BRANCH_CACHE		2	/* Branch Cache(s) */

/* Cache mode soft bit masks */

#define	CACHE_DISABLED		0x00	/* No cache or disabled */

#define	CACHE_WRITETHROUGH	0x01	/* Write-through Mode */
#define	CACHE_COPYBACK		0x02	/* Copyback Mode */
#define	CACHE_WRITEALLOCATE	0x04	/* Write Allocate Mode */
#define	CACHE_NO_WRITEALLOCATE	0x08
#define	CACHE_SNOOP_ENABLE	0x10	/* Bus Snooping */
#define	CACHE_SNOOP_DISABLE	0x20
#define	CACHE_BURST_ENABLE	0x40	/* Cache Burst Cycles */
#define	CACHE_BURST_DISABLE	0x80

/* Errno values */

#define S_cacheLib_INVALID_CACHE	(M_cacheLib | 1)

/* Value for "entire cache" in length arguments */

#define	ENTIRE_CACHE		ULONG_MAX

typedef enum	        		/* CACHE_TYPE */
    {
    BRANCH_CACHE      = _BRANCH_CACHE,
    INSTRUCTION_CACHE = _INSTRUCTION_CACHE,
    DATA_CACHE        = _DATA_CACHE
    } CACHE_TYPE;

typedef	UINT	CACHE_MODE;		/* CACHE_MODE */

typedef	struct				/* Cache Routine Pointers */
    {
    FUNCPTR	enableRtn;		/* cacheEnable() */
    FUNCPTR	disableRtn;		/* cacheDisable() */
    FUNCPTR	lockRtn;		/* cacheLock() */
    FUNCPTR	unlockRtn;		/* cacheUnlock() */
    FUNCPTR	flushRtn;		/* cacheFlush() */
    FUNCPTR	invalidateRtn;		/* cacheInvalidate() */
    FUNCPTR	clearRtn;		/* cacheClear() */

    FUNCPTR	textUpdateRtn;		/* cacheTextUpdate() */
    FUNCPTR	pipeFlushRtn;		/* cachePipeFlush() */
    FUNCPTR	dmaMallocRtn;		/* cacheDmaMalloc() */
    FUNCPTR	dmaFreeRtn;		/* cacheDmaFree() */
    FUNCPTR	dmaVirtToPhysRtn;	/* virtual-to-Physical Translation */
    FUNCPTR	dmaPhysToVirtRtn;	/* physical-to-Virtual Translation */
    } CACHE_LIB;

/* Cache flush and invalidate support for general use and drivers */

typedef	struct				/* Driver Cache Routine Pointers */
    {
    FUNCPTR	flushRtn;		/* cacheFlush() */
    FUNCPTR	invalidateRtn;		/* cacheInvalidate() */
    FUNCPTR	virtToPhysRtn;		/* Virtual-to-Physical Translation */
    FUNCPTR	physToVirtRtn;		/* Physical-to-Virtual Translation */
    } CACHE_FUNCS;


/* variable declarations */

IMPORT CACHE_LIB	cacheLib;
IMPORT CACHE_FUNCS	cacheNullFuncs;	/* functions for non-cached memory */
IMPORT CACHE_FUNCS	cacheDmaFuncs;	/* functions for dma memory */
IMPORT CACHE_FUNCS	cacheUserFuncs;	/* functions for user memory */

IMPORT FUNCPTR		cacheDmaMallocRtn;
IMPORT FUNCPTR		cacheDmaFreeRtn;
IMPORT CACHE_MODE	cacheDataMode;	/* data cache modes for funcptrs */
IMPORT BOOL		cacheDataEnabled;
IMPORT BOOL		cacheMmuAvailable;

/* -----------------------------
 * dbgLib.h
 * ----------------------------*/
typedef unsigned short event_t; 
typedef void * INSTR;

/* -----------------------------
 * dirent.h
 * ----------------------------*/
struct dirent		/* dirent */
{   // MAX_NAME not supported bu jWrap
    char	d_name [256];	/* file name, null-terminated */
    };

/* Directory descriptor */
typedef void* DIR;


/* -----------------------------
 * slLib.h
 * ----------------------------*/
typedef struct slnode		/* Node of a linked list. */
    {
    struct slnode *next;	/* Points at the next node in the list */
    } SL_NODE;

typedef void*  SL_LIST;

/* -----------------------------
 * hashLib.h
 * ----------------------------*/

/* status codes */
#define S_hashLib_KEY_CLASH		(M_hashLib | 1)


typedef void* HASH_TBL;
typedef SL_NODE   HASH_NODE;	/* HASH_NODE */
typedef HASH_TBL *HASH_ID;


/* These hash nodes are used by the hashing functions in hashLib(1) */

typedef struct			/* H_NODE_INT */
    {
    HASH_NODE	node;			/* linked list node (must be first) */
    int		key;			/* hash node key */
    int		data;			/* hash node data */
    } H_NODE_INT;

typedef struct			/* H_NODE_STRING */
    {
    HASH_NODE	node;			/* linked list node (must be first) */
    char	*string;		/* hash node key */
    int		data;			/* hash node data */
    } H_NODE_STRING;

/* -----------------------------
 * dllLib.h
 * ----------------------------*/
typedef struct dlnode		/* Node of a linked list. */
    {
    struct dlnode *next;	/* Points at the next node in the list */
    struct dlnode *previous;	/* Points at the previous node in the list */
    } DL_NODE;

typedef void *DL_LIST;


/* -----------------------------
 * qFifoLib.h
 * ----------------------------*/

/* fifo key defines */
#define	FIFO_KEY_HEAD	-1		/* put at head of queue */
#define	FIFO_KEY_TAIL	0		/* put at tail of q (any != -1) */


typedef DL_LIST Q_FIFO_HEAD;		/* Q_FIFO_HEAD */
typedef DL_NODE Q_FIFO_NODE;		/* Q_FIFO_NODE */

/* -----------------------------
 * iosLib.h
 * ----------------------------*/
#define S_iosLib_DEVICE_NOT_FOUND		(M_iosLib | 1)
#define S_iosLib_DRIVER_GLUT			(M_iosLib | 2)
#define S_iosLib_INVALID_FILE_DESCRIPTOR	(M_iosLib | 3)
#define S_iosLib_TOO_MANY_OPEN_FILES		(M_iosLib | 4)
#define S_iosLib_CONTROLLER_NOT_PRESENT		(M_iosLib | 5)
#define S_iosLib_DUPLICATE_DEVICE_NAME		(M_iosLib | 6)
#define S_iosLib_INVALID_ETHERNET_ADDRESS	(M_iosLib | 7)

typedef struct 		/* DEV_HDR - device header for all device structures */
    {
    DL_NODE	node;		/* device linked list node */
    short	drvNum;		/* driver number for this device */
    char *	name;		/* device name */
    } DEV_HDR;


/* -----------------------------
 * semLib.h
 * ----------------------------*/
/* generic status codes */

#define S_semLib_INVALID_STATE			(M_semLib | 101)
#define S_semLib_INVALID_OPTION			(M_semLib | 102)
#define S_semLib_INVALID_QUEUE_TYPE		(M_semLib | 103)
#define S_semLib_INVALID_OPERATION		(M_semLib | 104)

/* semaphore options */

#define SEM_Q_MASK		0x3	/* q-type mask */
#define SEM_Q_FIFO		0x0	/* first in first out queue */
#define SEM_Q_PRIORITY		0x1	/* priority sorted queue */
#define SEM_DELETE_SAFE		0x4	/* owner delete safe (mutex opt.) */
#define SEM_INVERSION_SAFE	0x8	/* no priority inversion (mutex opt.) */

/* binary semaphore initial state */

typedef enum		/* SEM_B_STATE */
    {
    SEM_EMPTY,			/* 0: semaphore not available */
    SEM_FULL			/* 1: semaphore available */
    } SEM_B_STATE;

typedef struct semaphore *SEM_ID;

/* -----------------------------
 * dosFsLib.h
 * ----------------------------*/
typedef void* BLK_DEV;

#define S_dosFsLib_VOLUME_NOT_AVAILABLE		(M_dosFsLib | 1)
#define S_dosFsLib_DISK_FULL			(M_dosFsLib | 2)
#define S_dosFsLib_FILE_NOT_FOUND		(M_dosFsLib | 3)
#define S_dosFsLib_NO_FREE_FILE_DESCRIPTORS	(M_dosFsLib | 4)
#define S_dosFsLib_INVALID_NUMBER_OF_BYTES	(M_dosFsLib | 5)
#define S_dosFsLib_FILE_ALREADY_EXISTS		(M_dosFsLib | 6)
#define S_dosFsLib_ILLEGAL_NAME			(M_dosFsLib | 7)
#define	S_dosFsLib_CANT_DEL_ROOT		(M_dosFsLib | 8)
#define S_dosFsLib_NOT_FILE			(M_dosFsLib | 9)
#define	S_dosFsLib_NOT_DIRECTORY		(M_dosFsLib | 10)
#define	S_dosFsLib_NOT_SAME_VOLUME		(M_dosFsLib | 11)
#define S_dosFsLib_READ_ONLY			(M_dosFsLib | 12)
#define S_dosFsLib_ROOT_DIR_FULL		(M_dosFsLib | 13)
#define S_dosFsLib_DIR_NOT_EMPTY		(M_dosFsLib | 14)
#define S_dosFsLib_BAD_DISK			(M_dosFsLib | 15)
#define S_dosFsLib_NO_LABEL			(M_dosFsLib | 16)
#define S_dosFsLib_INVALID_PARAMETER		(M_dosFsLib | 17)
#define S_dosFsLib_NO_CONTIG_SPACE		(M_dosFsLib | 18)
#define S_dosFsLib_CANT_CHANGE_ROOT		(M_dosFsLib | 19)
#define S_dosFsLib_FD_OBSOLETE			(M_dosFsLib | 20)
#define S_dosFsLib_DELETED			(M_dosFsLib | 21)
#define S_dosFsLib_NO_BLOCK_DEVICE		(M_dosFsLib | 22)
#define S_dosFsLib_BAD_SEEK			(M_dosFsLib | 23)
#define S_dosFsLib_INTERNAL_ERROR		(M_dosFsLib | 24)
#define S_dosFsLib_WRITE_ONLY			(M_dosFsLib | 25)


/* dosFs file system constants */

#define DOS_BOOT_SEC_NUM	0	/* sector number of boot sector */
#define	DOS_MIN_CLUST		2	/* lowest cluster number used */
#define DOS_MAX_CLUSTERS	0x10000	/* max number of clusters per volume */
#define	DOS_SYS_ID_LEN		8	/* length of system ID string */
#define DOS_LONG_NAME_LEN	40	/* length of filename w/ long option */
#define DOS_NAME_LEN		8	/* length of filename (no extension) */
#define	DOS_EXT_LEN		3	/* length of filename extension */
#define	DOS_FILENAME_LEN	(DOS_NAME_LEN + DOS_EXT_LEN + 2)
					/* includes "." and null-terminator */
#define	DOS_VOL_LABEL_LEN	(DOS_NAME_LEN + DOS_EXT_LEN)
					/* length of volume label */

#define DOS_RESERVED_LEN	10	/* reserved bytes in regular dir ent */
#define DOS_LONG_RESERVED_LEN	13	/* reserved bytes in longNames dir ent*/

#define	DOS_DEL_MARK		0xe5	/* file is deleted if name[0] == 0xe5 */
#define	DOS_NAME_E5		0x05	/* value used if name[0] really is e5 */

#define	DOS_MAX_NFATS		64	/* maximum expected number of FATs */
#define DOS_MAX_DIR_LEVELS	20	/* max expected directory levels */
#define	DOS_MAX_PATH_LEN 	(DOS_NAME_LEN+1) * DOS_MAX_DIR_LEVELS
					/* max length of full pathname */

/* File Allocation Table (FAT) values */
#define	DOS_FAT_AVAIL		0x0000	/* cluster is available */
#define	DOS_FAT_BAD		0xff7	/* bad cluster marker for 12-bit FATs */
#define	DOS_FAT16_BAD		0xfff7	/* bad cluster marker for 16-bit FATs */
#define	DOS_FAT_EOF		0xfff	/* end-of-file marker for 12-bit FATs */
#define	DOS_FAT16_EOF		0xffff	/* end-of-file marker for 16-bit FATs */

#define	DOS_FAT_12BIT_MAX	4085	/* max clusters for 12-bit FAT entries*/



/* Boot sector offsets */

/*   Because the MS-DOS boot sector format has word data items
 *   on odd-byte boundaries, it cannot be represented as a standard C
 *   structure.  Instead, the following symbolic offsets are used to
 *   isolate data items.  Non-string data values longer than 1 byte are
 *   in "Intel 8086" order.
 *
 *   These definitions include fields used by MS-DOS Version 4.0.
 */

#define	DOS_BOOT_JMP		0x00	/* 8086 jump instruction     (3 bytes)*/
#define	DOS_BOOT_SYS_ID		0x03	/* system ID string          (8 bytes)*/
#define	DOS_BOOT_BYTES_PER_SEC	0x0b	/* bytes per sector          (2 bytes)*/
#define	DOS_BOOT_SEC_PER_CLUST	0x0d	/* sectors per cluster       (1 byte) */
#define	DOS_BOOT_NRESRVD_SECS	0x0e	/* # of reserved sectors     (2 bytes)*/
#define	DOS_BOOT_NFATS		0x10	/* # of FAT copies           (1 byte) */
#define	DOS_BOOT_MAX_ROOT_ENTS	0x11	/* max # of root dir entries (2 bytes)*/
#define	DOS_BOOT_NSECTORS	0x13	/* total # of sectors on vol (2 bytes)*/
#define	DOS_BOOT_MEDIA_BYTE	0x15	/* media format ID byte      (1 byte) */
#define	DOS_BOOT_SEC_PER_FAT	0x16	/* # of sectors per FAT copy (2 bytes)*/
#define	DOS_BOOT_SEC_PER_TRACK	0x18	/* # of sectors per track    (2 bytes)*/
#define	DOS_BOOT_NHEADS		0x1a	/* # of heads (surfaces)     (2 bytes)*/
#define	DOS_BOOT_NHIDDEN_SECS	0x1c	/* # of hidden sectors       (4 bytes)*/
#define	DOS_BOOT_LONG_NSECTORS	0x20	/* total # of sectors on vol (4 bytes)*/
#define DOS_BOOT_DRIVE_NUM	0x24	/* physical drive number     (1 byte) */
#define DOS_BOOT_SIG_REC	0x26	/* boot signature record     (1 byte) */
#define DOS_BOOT_VOL_ID		0x27	/* binary volume ID number   (4 bytes)*/
#define DOS_BOOT_VOL_LABEL	0x2b	/* volume label string      (11 bytes)*/
#define	DOS_BOOT_PART_TBL	0x1be	/* first disk partition tbl (16 bytes)*/

#define DOS_EXT_BOOT_SIG	0x29	/* value written to boot signature
					 * record to indicate extended (DOS v4)
					 * boot record in use
					 */

/* Disk Partition Table */

/* This structure is used to define areas of a large disk as separate
 * partitions.  An array of such entries is placed in the boot sector, at
 * offset DOS_BOOT_PART_TBL (0x1be).  The first entry in the array describes
 * the currently active partition; the other entries contain static data
 * describing each of the defined disk partitions.
 *
 * Prior to MS-DOS release 4.0, this was the standard method of using
 * a device larger than 32 megabytes.  Since the MS-DOS 4.0 extensions
 * allow direct use of such a device without partitioning, the use of
 * partitions is normally not preferred.  This structure definition is
 * provided to assist you in using partitions, if your specific application
 * requires them.
 */

typedef struct		/* DOS_PART_TBL */
    {
    UINT8		dospt_status;		/* partition status */
    UINT8		dospt_startHead;	/* starting head */
    short		dospt_startSec;		/* starting sector/cylinder */
    UINT8		dospt_type;		/* partition type */
    UINT8		dospt_endHead;		/* ending head */
    short		dospt_endSec;		/* ending sector/cylinder */
    ULONG		dospt_absSec;		/* starting absolute sector */
    ULONG		dospt_nSectors;		/* number of sectors in part */
    }  DOS_PART_TBL;

/* Disk Partition Type values */

#define	DOS_PTYPE_FAT12		1		/* DOS with 12-bit FAT */
#define	DOS_PTYPE_FAT16		4		/* DOS with 16-bit FAT */
#define	DOS_PTYPE_EXTENDED	5		/* extended DOS */



/* Standard MS-DOS directory entry, as found on disk
 *   Non-string data values longer than 1 byte are in "Intel 8086" order,
 */

typedef struct		/* DOS_DISK_DIR_ENT */
    {
    UINT8		dosdde_name [DOS_NAME_LEN]; /* filename */
    UINT8		dosdde_ext [DOS_EXT_LEN];   /* filename extension */
    UINT8		dosdde_attrib;		/* attribute byte */
    char		dosdde_reserved[DOS_RESERVED_LEN];	/* reserved*/
    USHORT		dosdde_time;		/* time */
    USHORT		dosdde_date;		/* date */
    USHORT		dosdde_cluster;		/* starting cluster number */
    ULONG		dosdde_size;		/* file size (in bytes) */
    } DOS_DISK_DIR_ENT;

/* Extended VxWorks-specific directory entry, as found on disk
 *   This format is used when the DOS_OPT_LONGNAMES option is specified.
 *   Non-string data values longer than 1 byte are in "Intel 8086" order.
 */

typedef struct		/* DOS_DISK_EDIR_ENT */
    {
    UINT8		dosdee_name [DOS_LONG_NAME_LEN]; /* filename */
    char		dosdee_reserved[DOS_LONG_RESERVED_LEN];	/* reserved*/
    UINT8		dosdee_attrib;		/* attribute byte */
    USHORT		dosdee_time;		/* time */
    USHORT		dosdee_date;		/* date */
    USHORT		dosdee_cluster;		/* starting cluster number */
    ULONG		dosdee_size;		/* file size (in bytes) */
    } DOS_DISK_EDIR_ENT;


typedef void * DOS_DIR_ENT;


/* File attribute byte values */
#define	DOS_ATTR_RDONLY		0x01		/* read-only file */
#define	DOS_ATTR_HIDDEN		0x02		/* hidden file */
#define	DOS_ATTR_SYSTEM		0x04		/* system file */
#define	DOS_ATTR_VOL_LABEL	0x08		/* volume label (not a file) */
#define	DOS_ATTR_DIRECTORY	0x10		/* entry is a sub-directory */
#define	DOS_ATTR_ARCHIVE	0x20		/* file subject to archiving */



/* Volume configuration data */

typedef struct		/* DOS_VOL_CONFIG */
    {
    char	dosvc_mediaByte;	/* media descriptor byte */
    UINT8	dosvc_secPerClust;	/* sectors per cluster (minimum 1) */
    short	dosvc_nResrvd;		/* number of reserved sectors (min 1) */
    char	dosvc_nFats;		/* number of FAT copies (minimum 1) */
    UINT16	dosvc_secPerFat;	/* number of sectors per FAT copy */
    short	dosvc_maxRootEnts;	/* max number of entries in root dir */
    UINT	dosvc_nHidden;		/* number of hidden sectors */
    UINT	dosvc_options;		/* volume options */
    UINT	dosvc_reserved;		/* reserved for future use */
    } DOS_VOL_CONFIG;



/* Volume descriptor */

typedef struct		/* DOS_VOL_DESC */
    {
    DEV_HDR	dosvd_devHdr;		/* i/o system device header */
    short	dosvd_status;		/* (OK | ERROR) */
    char	dosvd_sysId [DOS_SYS_ID_LEN];	/* system ID string */
    SEM_ID	dosvd_semId;		/* volume semaphore id */

    void	*dosvd_pBlkDev;		/* pointer to block device info */

    char	dosvd_mediaByte;	/* media format byte */
    UINT8	dosvd_secPerClust;	/* number of sectors per cluster */
    UINT	dosvd_bytesPerClust;	/* bytes-per-cluster */

    UINT8	dosvd_nFats;		/* number of copies of FAT */
    UINT16	dosvd_secPerFat;	/* number of sectors per FAT */
    int		dosvd_nFatEnts;		/* number of entries in FAT */
    BOOL	dosvd_fat12Bit;		/* FAT uses 12 (vs. 16) bit entries */
    BOOL	dosvd_fatModified;	/* TRUE if FAT has been changed */
    UINT8	*dosvd_pFatBuf;		/* pointer to FAT buffer */
    int		dosvd_fatEntFreeCnt;	/* count of free clusters */

    USHORT	dosvd_maxRootEnts;	/* max num of root directory entries */
    ULONG	dosvd_nRootEnts;	/* current num of root dir entries */
    int		dosvd_rootSec;		/* starting sector number of root dir */
    DOS_DIR_ENT	*dosvd_pRoot;		/* pointer to root directory entry */

    USHORT	dosvd_nResrvdSecs;	/* number of reserved sectors */
    ULONG	dosvd_nHiddenSecs;	/* number of hidden sectors */
    UINT	dosvd_dataSec;		/* starting sector number of data area*/

    UINT8	dosvd_driveNum;		/* physical drive number */
    UINT8	dosvd_bootSigRec;	/* extended boot signature record */
    ULONG	dosvd_volId;		/* binary volume ID number */
    char	dosvd_volLabel [DOS_VOL_LABEL_LEN];
					/* volume label string */

    int		dosvd_state;		/* state of volume (see below) */
    int		dosvd_retry;		/* retry count of disk operations */
    UINT	dosvd_options;		/* volume options (see below) */

    UINT8	*dosvd_pFatModTbl;	/* ptr to table of mod'd FAT sectors */
    HASH_ID	dosvd_hashTbl;	        /* hash table for volume */
    int         dosvd_uid;	        /* user id to report from stat () */
    int         dosvd_gid;              /* group id to report from stat () */
    int         dosvd_mode;	        /* file mode to report from stat () */
    } DOS_VOL_DESC;


/* Volume states */

#define DOS_VD_READY_CHANGED	0	/* vol not accessed since ready change*/
#define DOS_VD_RESET		1	/* volume reset but not mounted */
#define DOS_VD_MOUNTED		2	/* volume mounted */
#define DOS_VD_CANT_RESET	3	/* volume reset failed */
#define DOS_VD_CANT_MOUNT	4	/* volume mount failed */

/* Volume options */

#define DOS_OPT_CHANGENOWARN	0x1	/* disk may be changed w/out warning */
#define DOS_OPT_AUTOSYNC	0x2	/* autoSync mode enabled */
#define DOS_OPT_LONGNAMES	0x4	/* long file names enabled */
#define DOS_OPT_EXPORT		0x8	/* file sytem export enabled */
#define DOS_OPT_LOWERCASE	0x40	/* filenames use lower-case chars */


/* dosFs Date and Time Structure */

typedef struct		/* DOS_DATE_TIME */
    {
    int		dosdt_year;		/* current year */
    int		dosdt_month;		/* current month */
    int		dosdt_day;		/* current day */
    int		dosdt_hour;		/* current hour */
    int		dosdt_minute;		/* current minute */
    int		dosdt_second;		/* current second */
    } DOS_DATE_TIME;


/* -----------------------------
 * evtBufferLib.h
 * ----------------------------*/
struct buffers
    {
    char * bufferIndexInUse;		/* 0x0 index into buffer 
					 * MUST BE FIRST IN STRUCTURE */
    char * bufferInUse;			/* 0x4 pointer to buffer */
    char * bufferInReserve;		/* 0x8 pointer to reserve buffer */
    char * bufferIndexInReserve;	/* 0x12 index to reserve buffer */
    };

/* -----------------------------
 * excLib.h
 * ----------------------------*/
typedef struct  excfaultTab
    {
    int faultType;		/* fault type */
    int subtype;		/* fault sub type */
    int signal;			/* signal */
    int code;			/* code */
    } EXC_FAULT_TAB;


/* -----------------------------
 * ftpLib.h
 * ----------------------------*/

/* For FTP specification see RFC-765 */

/* Reply codes. */

#define FTP_PRELIM	1	/* positive preliminary */
#define FTP_COMPLETE	2	/* positive completion */
#define FTP_CONTINUE	3	/* positive intermediate */
#define FTP_TRANSIENT	4	/* transient negative completion */
#define FTP_ERROR	5	/* permanent negative completion */

#define FTP_NOACTION    550     /* requested action not taken */

/* Type codes */

#define	TYPE_A		1	/* ASCII */
#define	TYPE_E		2	/* EBCDIC */
#define	TYPE_I		3	/* image */
#define	TYPE_L		4	/* local byte size */

/* Form codes */

#define	FORM_N		1	/* non-print */
#define	FORM_T		2	/* telnet format effectors */
#define	FORM_C		3	/* carriage control (ASA) */

/* Structure codes */

#define	STRU_F		1	/* file (no record structure) */
#define	STRU_R		2	/* record structure */
#define	STRU_P		3	/* page structure */

/* Mode types */

#define	MODE_S		1	/* stream */
#define	MODE_B		2	/* block */
#define	MODE_C		3	/* compressed */

/* Record Tokens */

#define	REC_ESC		'\377'	/* Record-mode Escape */
#define	REC_EOR		'\001'	/* Record-mode End-of-Record */
#define REC_EOF		'\002'	/* Record-mode End-of-File */

/* Block Header */

#define	BLK_EOR		0x80	/* Block is End-of-Record */
#define	BLK_EOF		0x40	/* Block is End-of-File */
#define BLK_ERRORS	0x20	/* Block is suspected of containing errors */
#define	BLK_RESTART	0x10	/* Block is Restart Marker */

#define	BLK_BYTECOUNT	2	/* Bytes in this block */



/* -----------------------------
 * if_bp.h
 * ----------------------------*/
#define BP_INT_NONE		0	/* no interrupt - poll instead */

#define BP_INT_MAILBOX_1	1	/* mailbox write byte to bus adrs */
#define BP_INT_MAILBOX_2	2	/* mailbox write word to bus adrs */
#define BP_INT_MAILBOX_4	3	/* mailbox write long to bus adrs */
					/*    arg1 = bus address space
					 *    arg2 = bus address
					 *    arg3 = value
					 */

#define BP_INT_BUS		4	/* generate bus interrupt */
					/*    arg1 = interrupt level
					 *    arg2 = interrupt vector
					 */

#define BP_INT_MAILBOX_R1	5	/* mailbox read byte to bus adrs */
#define BP_INT_MAILBOX_R2	6	/* mailbox read word to bus adrs */
#define BP_INT_MAILBOX_R4	7	/* mailbox read long to bus adrs */
					/*    arg1 = bus address space
					 *    arg2 = bus address
					 *    arg3 = value
					 */

/* -----------------------------
 * if_sl.h
 * ----------------------------*/
#define S_if_sl_INVALID_UNIT_NUMBER			(M_if_sl | 1)
#define S_if_sl_UNIT_UNINITIALIZED			(M_if_sl | 2)
#define S_if_sl_UNIT_ALREADY_INITIALIZED		(M_if_sl | 3)

/* -------------------------------------
 * loadLib.h
 * -------------------------------------*/

#define S_loadLib_ROUTINE_NOT_INSTALLED		(M_loadLib | 1)
#define S_loadLib_TOO_MANY_SYMBOLS		(M_loadLib | 2)

#define NO_SYMBOLS      -1
#define GLOBAL_SYMBOLS  0
#define ALL_SYMBOLS     1

/* new load flags */
#define LOAD_NO_SYMBOLS	        2
#define LOAD_LOCAL_SYMBOLS	4
#define LOAD_GLOBAL_SYMBOLS	8
#define LOAD_ALL_SYMBOLS	(LOAD_LOCAL_SYMBOLS | LOAD_GLOBAL_SYMBOLS)
#define HIDDEN_MODULE	        16 /* Don't display module from moduleShow() */
#define LOAD_MODULE_INFO_ONLY	0x1000000	/* host/target symtbls sync */
#define LOAD_LOADED_BY_TGTSVR	0x2000000	/* host/target symtbls sync */

#define LD_NO_ADDRESS   ((char *) NONE)

typedef struct
    {
    char * addrText;	/* text segment address */
    char * addrData;	/* data segment address */
    char * addrBss;	/* bss segment address */
    UINT   sizeText;	/* text segment size */
    UINT   sizeProtectedText;	/* protected text segment size */
    UINT   sizeData;	/* data segment size */
    UINT   sizeBss;	/* bss segment size */
    int	   flagsText;	/* text flags for module */
    int	   flagsData;	/* data flags for module */
    int	   flagsBss;	/* bss flags for module */
    } SEG_INFO;

/* -----------------------------
 * loginLib.h
 * ----------------------------*/
#ifndef DOC
#define MAX_LOGIN_NAME_LEN    80
#define MAX_LOGIN_ENTRY       80
#endif	/* DOC */

/* status messages */

#define S_loginLib_UNKNOWN_USER			(M_loginLib | 1)
#define S_loginLib_USER_ALREADY_EXISTS		(M_loginLib | 2)
#define S_loginLib_INVALID_PASSWORD		(M_loginLib | 3)

/* -------------------------------------
 *  memLib.h
 * -------------------------------------*/

#define S_memLib_NOT_ENOUGH_MEMORY		(M_memLib | 1)
#define S_memLib_INVALID_NBYTES			(M_memLib | 2)
#define S_memLib_BLOCK_ERROR			(M_memLib | 3)
#define S_memLib_NO_PARTITION_DESTROY		(M_memLib | 4)
#define S_memLib_PAGE_SIZE_UNAVAILABLE		(M_memLib | 5)

/* types */

typedef struct mem_part *PART_ID;

/* Partition statistics structure */

typedef struct
    {

    unsigned long numBytesFree,	   /* Number of Free Bytes in Partition       */
		  numBlocksFree,   /* Number of Free Blocks in Partition      */
		  maxBlockSizeFree,/* Maximum block size that is free.	      */
		  numBytesAlloc,   /* Number of Allocated Bytes in Partition  */
		  numBlocksAlloc;  /* Number of Allocated Blocks in Partition */

    }  MEM_PART_STATS;

/* partition options */

/* optional check for bad blocks */

#define MEM_BLOCK_CHECK			0x10

/* response to errors when allocating memory */

#define MEM_ALLOC_ERROR_LOG_FLAG	0x20
#define MEM_ALLOC_ERROR_SUSPEND_FLAG	0x40

/* response to errors when freeing memory */

#define MEM_BLOCK_ERROR_LOG_FLAG	0x80
#define MEM_BLOCK_ERROR_SUSPEND_FLAG	0x100

/* old style allocation errors - block too big, insufficient space */

#define MEM_ALLOC_ERROR_MASK		0x03
#define MEM_ALLOC_ERROR_RETURN		0
#define MEM_ALLOC_ERROR_LOG_MSG		0x01
#define MEM_ALLOC_ERROR_LOG_AND_SUSPEND	0x02

/* old style bad block found */

#define MEM_BLOCK_ERROR_MASK		0x0c
#define MEM_BLOCK_ERROR_RETURN		0
#define MEM_BLOCK_ERROR_LOG_MSG		0x04
#define MEM_BLOCK_ERROR_LOG_AND_SUSPEND	0x08

/* -----------------------------------------------------
 *  libModule.h
 * -----------------------------------------------------*/
#define S_moduleLib_MODULE_NOT_FOUND             (M_moduleLib | 1)
#define S_moduleLib_HOOK_NOT_FOUND               (M_moduleLib | 2)
#define S_moduleLib_BAD_CHECKSUM                 (M_moduleLib | 3)
#define S_moduleLib_MAX_MODULES_LOADED           (M_moduleLib | 4)

/* max number of module groups */

#define MODULE_GROUP_MAX	65535

/* Types of object module formats */

#define MODULE_A_OUT 0		/* format is a.out */
#define MODULE_B_OUT 1		/* format is b.out */
#define MODULE_ECOFF 2		/* format is ECOFF */
#define MODULE_ELF   3		/* format is ELF */

/* Types of segments */

/* Note - These are specific to a.out */

#define SEGMENT_TEXT	2	/* text segment */
#define SEGMENT_DATA	4	/* data segment */
#define SEGMENT_BSS	8	/* bss segment */

/* These are needed for the HP-PA SOM COFF */

#define SEGMENT_UNWIND  0x10000
#define SEGMENT_STUB    0x20000

/* segment flag bits */

#define SEG_FREE_MEMORY		1 /* Free memory when deleting this segment */
#define SEG_WRITE_PROTECTION	2 /* Segment's memory is write-protected,
				   * need to call memory managment routines
				   * to unprotect when deleting */

/* display options */

#define MODDISPLAY_CODESIZE  	1 /* Display size of the code segments */
#define MODDISPLAY_IS_DLL_NODE 	2 /* Display routine is being called with
				   * DLL_NODE instead of MODULE_ID -
				   * used by moduleShow() */

#define MODDISPLAY_ALL  	(MODDISPLAY_CODESIZE) /* Display all possible
						       * information */

/* moduleCheck() options */

#define MODCHECK_NOPRINT	1 /* Don't print module names during check */

#define MODCHECK_TEXT		(SEGMENT_TEXT) /* check text segment */
#define MODCHECK_DATA		(SEGMENT_DATA) /* check data segment */
#define MODCHECK_BSS	       	(SEGMENT_BSS)  /* check bss segment */

/* module status information */

#define MODULE_REPLACED	0x00010000 /* set if the module is loaded twice */

typedef struct
    {
    DL_NODE	segmentNode;	/* double-linked list node information*/
    void *	address;	/* segment address */
    int		size;		/* segment size */
    int		type;		/* segment type*/
    int		flags;		/* segment flags */
    u_short	checksum;	/* segment checksum; u_short is returned by
				 * checksum() */
    } SEGMENT;

typedef SEGMENT *SEGMENT_ID;


typedef struct
    {
    void *	textAddr;	/* address of text segment */
    void *	dataAddr;	/* address of data segment */
    void *	bssAddr;	/* address of bss segment */
    int 	textSize;	/* size of text segment */
    int 	dataSize;	/* size of data segment */
    int 	bssSize;	/* size of bss segment */
    } MODULE_SEG_INFO;

typedef struct
    {
    char        	name [NAME_MAX]; /* module name */
    int         	format;          /* object module format */
    int			group;		 /* group number */
    MODULE_SEG_INFO	segInfo; 	 /* segment info */
    } MODULE_INFO;

/* -----------------------------
 * mountLib.h
 * ----------------------------*/
/* mountLib status codes */
#define S_mountLib_ILLEGAL_MODE             (M_mountLib | 1)

/* mountLib defaults */
#define MAX_EXPORTED_FILESYSTEMS 30
#define MOUNTD_PRIORITY_DEFAULT  55
#define MOUNTD_STACKSIZE_DEFAULT 10240

/* Exported file systems */
typedef struct
    {
    char * next;		/* next and prev are used by lstLib */
    char * prev;
    char   dirName [PATH_MAX];
    int    dirFd;		/* File descriptor for the exported directory */
    ULONG  fsId;
    int    volumeId;            /* Identifier for the file system */
    BOOL   readOnly;
    } NFS_EXPORT_ENTRY;

typedef union
    {
    char* mountproc_mnt_1_arg;
    char* mountproc_umnt_1_arg;
    } MOUNTD_ARGUMENT;

/* -------------------------------------
 * mqueue.h
 * -------------------------------------*/
typedef void* mqd_t;

/* -------------------------------------
 * msgQLib.h
 * -------------------------------------*/
/* generic status codes */
#define S_msgQLib_INVALID_MSG_LENGTH		(M_msgQLib | 1)
#define S_msgQLib_NON_ZERO_TIMEOUT_AT_INT_LEVEL	(M_msgQLib | 2)
#define S_msgQLib_INVALID_QUEUE_TYPE		(M_msgQLib | 3)

/* message queue options */
#define MSG_Q_TYPE_MASK	0x01	/* mask for pend queue type in options */
#define MSG_Q_FIFO	0x00	/* tasks wait in FIFO order */
#define MSG_Q_PRIORITY	0x01	/* tasks wait in PRIORITY order */


/* message send priorities */
#define MSG_PRI_NORMAL	0	/* normal priority message */
#define MSG_PRI_URGENT	1	/* urgent priority message */

/* message queue typedefs */
typedef void* MSG_Q_ID;	/* message queue ID */

typedef struct			/* MSG_Q_INFO */
    {
    int     numMsgs;		/* OUT: number of messages queued */
    int     numTasks;		/* OUT: number of tasks waiting on msg q */

    int     sendTimeouts;	/* OUT: count of send timeouts */
    int     recvTimeouts;	/* OUT: count of receive timeouts */

    int     options;		/* OUT: options with which msg q was created */
    int     maxMsgs;		/* OUT: max messages that can be queued */
    int     maxMsgLength;	/* OUT: max byte length of each message */

    int     taskIdListMax;	/* IN: max tasks to fill in taskIdList */
    int *   taskIdList;		/* PTR: array of task ids waiting on msg q */

    int     msgListMax;		/* IN: max msgs to fill in msg lists */
    void *  msgPtrList;		/* PTR: array of msg ptrs queued to msg q */
    int *   msgLenList;		/* PTR: array of lengths of msgs */

    } MSG_Q_INFO;


/* -----------------------------
 * msgQSmLib.h
 * ----------------------------*/
typedef void* SM_MSG_Q_ID;	

/* -----------------------------
 * nfsdLib.h
 * ----------------------------*/

typedef struct 
    {
    int    volumeId;            /* Volume identifier for the file system */
    ULONG  fsId;                /* Inode of the exported directory */
    ULONG  inode;		/* Inode of the file as returned from stat */
    INT8   reserved [24];       /* NFS file handles have 32 bytes */
    } NFS_FILE_HANDLE;

/* nfsdStatusGet() information */

typedef struct
    {
    int nullCalls;
    int getattrCalls;
    int setattrCalls;
    int rootCalls;
    int lookupCalls;
    int readlinkCalls;
    int readCalls;
    int writecacheCalls;
    int writeCalls;
    int createCalls;
    int removeCalls;
    int renameCalls;
    int linkCalls;
    int symlinkCalls;
    int mkdirCalls;
    int rmdirCalls;
    int readdirCalls;
    int statfsCalls;
    } NFS_SERVER_STATUS;


/* -----------------------------
 * nfsLib.h
 * ----------------------------*/
#define NFS_FSTAT_DIR		0040000		/* directory */
#define NFS_FSTAT_CHR		0020000		/* character special file */
#define NFS_FSTAT_BLK		0060000		/* block special file */
#define NFS_FSTAT_REG		0100000		/* regular file */
#define NFS_FSTAT_LNK		0120000		/* symbolic link file */
#define NFS_FSTAT_NON		0140000		/* named socket */

/* nfsLib status codes */

#define	S_nfsLib_NFS_AUTH_UNIX_FAILED		(M_nfsLib | 1)
#define	S_nfsLib_NFS_INAPPLICABLE_FILE_TYPE	(M_nfsLib | 2)

/* nfsLib status codes derived from Sun's NFS specification (see xdr_nfs.h)  */

#define S_nfsLib_NFS_OK			(M_nfsStat | (int) NFS_OK)
#define S_nfsLib_NFSERR_PERM		(M_nfsStat | (int) NFSERR_PERM)
#define S_nfsLib_NFSERR_NOENT		(M_nfsStat | (int) NFSERR_NOENT)
#define S_nfsLib_NFSERR_IO		(M_nfsStat | (int) NFSERR_IO)
#define S_nfsLib_NFSERR_NXIO		(M_nfsStat | (int) NFSERR_NXIO)
#define S_nfsLib_NFSERR_ACCES		(M_nfsStat | (int) NFSERR_ACCES)
#define S_nfsLib_NFSERR_EXIST		(M_nfsStat | (int) NFSERR_EXIST)
#define S_nfsLib_NFSERR_NODEV		(M_nfsStat | (int) NFSERR_NODEV)
#define S_nfsLib_NFSERR_NOTDIR		(M_nfsStat | (int) NFSERR_NOTDIR)
#define S_nfsLib_NFSERR_ISDIR		(M_nfsStat | (int) NFSERR_ISDIR)
#define S_nfsLib_NFSERR_FBIG		(M_nfsStat | (int) NFSERR_FBIG)
#define S_nfsLib_NFSERR_NOSPC		(M_nfsStat | (int) NFSERR_NOSPC)
#define S_nfsLib_NFSERR_ROFS		(M_nfsStat | (int) NFSERR_ROFS)
#define S_nfsLib_NFSERR_NAMETOOLONG	(M_nfsStat | (int) NFSERR_NAMETOOLONG)
#define S_nfsLib_NFSERR_NOTEMPTY	(M_nfsStat | (int) NFSERR_NOTEMPTY)
#define S_nfsLib_NFSERR_DQUOT		(M_nfsStat | (int) NFSERR_DQUOT)
#define S_nfsLib_NFSERR_STALE		(M_nfsStat | (int) NFSERR_STALE)
#define S_nfsLib_NFSERR_WFLUSH		(M_nfsStat | (int) NFSERR_WFLUSH)


/* default NFS parameters */

#define NFS_TIMEOUT_SEC         25
#define NFS_TIMEOUT_USEC        0
#define NFS_SOCKOPTVAL          10000
#define NFS_REXMIT_SEC		5
#define NFS_REXMIT_USEC		0

#define AUTH_UNIX_FIELD_LEN	50	/* UNIX authentication info */
#define MAX_GRPS		20	/* max. # of groups that user is in */

/* -----------------------------
 * nfsDrv.h
 * ----------------------------*/
typedef struct
    {

    char hostName   [MAXHOSTNAMELEN];	/* Host of imported NFS     */
    char remFileSys [PATH_MAX + 1];	/* Remote File System Name  */
    char locFileSys [PATH_MAX + 1];	/* Local File System Name   */

    } NFS_DEV_INFO;

/* nfsDrv status codes */

#define S_nfsDrv_INVALID_NUMBER_OF_BYTES	(M_nfsDrv | 1)
#define S_nfsDrv_BAD_FLAG_MODE			(M_nfsDrv | 2)
#define S_nfsDrv_CREATE_NO_FILE_NAME		(M_nfsDrv | 3)
#define	S_nfsDrv_FATAL_ERR_FLUSH_INVALID_CACHE	(M_nfsDrv | 4)
#define	S_nfsDrv_WRITE_ONLY_CANNOT_READ		(M_nfsDrv | 5)
#define	S_nfsDrv_READ_ONLY_CANNOT_WRITE		(M_nfsDrv | 6)
#define	S_nfsDrv_NOT_AN_NFS_DEVICE		(M_nfsDrv | 7)
#define	S_nfsDrv_NO_HOST_NAME_SPECIFIED		(M_nfsDrv | 8)

/* -----------------------------
 * pingLib.h
 * ----------------------------*/
/* defines */
#define PING_MAXPACKET		4096	/* max packet size */
#define PING_INTERVAL		1	/* default packet interval in seconds */
#define PING_TMO		5	/* default packet timeout in seconds */
#define ICMP_PROTO		1	/* icmp socket proto id */
#define ICMP_TYPENUM		20	/* icmp proto type identifier */
#define PING_TASK_NAME_LEN	20	/* max ping Tx task name length */

/* status codes */

#define	S_pingLib_NOT_INITIALIZED		(M_pingLib | 1)
#define	S_pingLib_TIMEOUT			(M_pingLib | 2)
 
/* flags */

#define	PING_OPT_SILENT		0x1	/* work silently */
#define	PING_OPT_DONTROUTE	0x2	/* dont route option */
#define	PING_OPT_DEBUG		0x4	/* print debugging messages */

/* -----------------------------
 * proxyArpLib.h
 * ----------------------------*/
#define	S_proxyArpLib_INVALID_PARAMETER		(M_proxyArpLib | 1)
#define S_proxyArpLib_INVALID_INTERFACE		(M_proxyArpLib | 2)
#define	S_proxyArpLib_INVALID_PROXY_NET		(M_proxyArpLib | 3)
#define	S_proxyArpLib_INVALID_CLIENT		(M_proxyArpLib | 4)
#define S_proxyArpLib_INVALID_ADDRESS		(M_proxyArpLib | 5)
#define S_proxyArpLib_TIMEOUT			(M_proxyArpLib | 6)

/* -----------------------------
 * remLib.h
 * ----------------------------*/
#define MAX_IDENTITY_LEN	100

/* status messages */
#define S_remLib_ALL_PORTS_IN_USE		(M_remLib | 1)
#define S_remLib_RSH_ERROR			(M_remLib | 2)
#define S_remLib_IDENTITY_TOO_BIG		(M_remLib | 3)

/* -----------------------------
 * rngLib.h
 * ----------------------------*/
typedef void* RING_ID;

/* -----------------------------
 * routeLib.h
 * ----------------------------*/
#define S_routeLib_ILLEGAL_INTERNET_ADDRESS		(M_routeLib | 1)
#define S_routeLib_ILLEGAL_NETWORK_NUMBER		(M_routeLib | 2)

/* -----------------------------
 * semSmLib.h
 * ----------------------------*/
typedef void* SM_SEM_ID;

/* -----------------------------
 * sigLib.h
 * ----------------------------*/
#define NUM_SIGNALS	32

#define SIGIO		(SIGRTMIN + 0)
#define SIGXCPU		(SIGRTMIN + 1)
#define SIGXFSZ		(SIGRTMIN + 2)
#define SIGVTALRM	(SIGRTMIN + 3)
#define SIGPROF		(SIGRTMIN + 4)
#define SIGWINCH	(SIGRTMIN + 5)
#define SIGLOST		(SIGRTMIN + 6)
#define SIGURG		16

#define SIGIOT		SIGABRT
#define SIGCLD		SIGCHLD
#define SIGPOLL		SIGIO
#define SIGSYS		SIGFMT

#define NUM_SIGNALS	32

/* -----------------------------
 * smMemLib.h
 * ----------------------------*/
typedef void* SM_PART_ID;

/* -----------------------------
 * smNameLib.h
 * ----------------------------*/
#define S_smNameLib_NOT_INITIALIZED           (M_smNameLib | 1)
#define S_smNameLib_NAME_TOO_LONG             (M_smNameLib | 2)
#define S_smNameLib_NAME_NOT_FOUND            (M_smNameLib | 3)
#define S_smNameLib_VALUE_NOT_FOUND           (M_smNameLib | 4)
#define S_smNameLib_NAME_ALREADY_EXIST        (M_smNameLib | 5)
#define S_smNameLib_DATABASE_FULL             (M_smNameLib | 6)
#define S_smNameLib_INVALID_WAIT_TYPE         (M_smNameLib | 7)

#define MAX_NAME_LENGTH 19	/* maximum lengh of a name in database */

/* default object types */

#define MAX_DEF_TYPE   5	/* number of predefined types */

#define T_SM_SEM_B   0		/* shared binary semaphore type */
#define T_SM_SEM_C   1		/* shared counting semaphore type */
#define T_SM_MSG_Q   2		/* shared message queue type */
#define T_SM_PART_ID 3		/* shared memory partition type */
#define T_SM_BLOCK   4		/* shared memory allocated block type */

/* -----------------------------
 * smObjLib.h
 * ----------------------------*/
#define S_smObjLib_NOT_INITIALIZED        (M_smObjLib | 1)
#define S_smObjLib_NOT_A_GLOBAL_ADRS      (M_smObjLib | 2)
#define S_smObjLib_NOT_A_LOCAL_ADRS       (M_smObjLib | 3)
#define S_smObjLib_SHARED_MEM_TOO_SMALL   (M_smObjLib | 4)
#define S_smObjLib_TOO_MANY_CPU           (M_smObjLib | 5)
#define S_smObjLib_LOCK_TIMEOUT           (M_smObjLib | 6)
#define S_smObjLib_NO_OBJECT_DESTROY      (M_smObjLib | 7)

#define SM_OBJ_MAX_CPU		20      /* absolute maximum number of CPU */

/* -----------------------------
 * symbol.h
 * ----------------------------*/
#define SYM_UNDF        0x0     /* undefined */
#define SYM_LOCAL       0x0     /* local */
#define SYM_GLOBAL      0x1     /* global (external) (ORed) */
#define SYM_ABS         0x2     /* absolute */
#define SYM_TEXT        0x4     /* text */
#define SYM_DATA        0x6     /* data */
#define SYM_BSS         0x8     /* bss */
#define SYM_COMM        0x12    /* common symbol */
#define SYM_SDA         0x40    /* symbols related to a PowerPC SDA section */
#define SYM_SDA2        0x80    /* symbols related to a PowerPC SDA2 section */

/* symbol masks */
#define SYM_MASK_ALL	0xff		/* all bits of symbol type valid */
#define SYM_MASK_NONE	0x00		/* no bits of symbol type valid */
#define SYM_MASK_EXACT	0x1ff		/* match symbol pointer exactly */
#define SYM_SDA_MASK    0xc0            /* for SDA and SDA2 symbols */

typedef signed char SYM_TYPE;	
typedef void* SYMBOL;

/* -----------------------------
 * symLib.h
 * ----------------------------*/
#define S_symLib_SYMBOL_NOT_FOUND	(M_symLib | 1)
#define S_symLib_NAME_CLASH		(M_symLib | 2)
#define S_symLib_TABLE_NOT_EMPTY	(M_symLib | 3)
#define S_symLib_SYMBOL_STILL_IN_TABLE	(M_symLib | 4)

// typedef void* SYMTAB_ID; place at top of file

/* -----------------------------
 * sysLib.h
 * ----------------------------*/
typedef struct  /* NETIF - network interface table */
    {
    char *ifName;  		     	/* interface name */
    FUNCPTR attachRtn;  		/* attach routine */
    char *arg1;				/* address */
    int arg2;				/* vector */
    int arg3;				/* level */
    int arg4;
    int arg5;
    int arg6;
    int arg7;
    int arg8;
    } NETIF;

/* system restart types */
#define	BOOT_NORMAL		0x00	/* normal reboot with countdown */
#define BOOT_NO_AUTOBOOT	0x01	/* no autoboot if set */
#define BOOT_CLEAR		0x02	/* clear memory if set */
#define BOOT_QUICK_AUTOBOOT	0x04	/* fast autoboot if set */

/* for backward compatibility */
#define BOOT_WARM_AUTOBOOT		BOOT_NORMAL
#define BOOT_WARM_NO_AUTOBOOT		BOOT_NO_AUTOBOOT
#define BOOT_WARM_QUICK_AUTOBOOT	BOOT_QUICK_AUTOBOOT
#define BOOT_COLD			BOOT_CLEAR


/* system configuration flags in sysFlags */

/* Some targets have system controllers that can be enabled in software.
 * By default, the system controller is enabled for processor 0.
 * When set this flag inhibits enabling the system controller even
 * for processor 0.
 */

#define SYSFLG_NO_SYS_CONTROLLER 0x01

/* System debug option:
 * load kernel symbol table with all symbols (not just globals)
 */
#define SYSFLG_DEBUG             0x02

#define SYSFLG_NO_AUTOBOOT	 0x04	/* Don't start autoboot sequence */
#define SYSFLG_QUICK_AUTOBOOT	 0x08	/* Immediate autoboot (no countdown) */
#define SYSFLG_NO_STARTUP_SCRIPT 0x10	/* Don't read startup script */
#define SYSFLG_NO_SECURITY	 0x20   /* Don't ask passwd on network login */
#define SYSFLG_BOOTP		 0x40   /* Use bootp to get boot parameters */
#define SYSFLG_TFTP		 0x80   /* Use tftp to get boot image */
#define SYSFLG_PROXY		 0x100	/* Use proxy arp */
#define SYSFLG_WDB		 0x200	/* Use WDB agent */

#define SYSFLG_VENDOR_0		 0x1000	/* vendor defined flag 0 */
#define SYSFLG_VENDOR_1		 0x2000	/* vendor defined flag 1 */
#define SYSFLG_VENDOR_2		 0x4000	/* vendor defined flag 2 */
#define SYSFLG_VENDOR_3		 0x8000	/* vendor defined flag 3 */

/* -----------------------------
 * taskinfo.h
 * ----------------------------*/
#define S_taskLib_NAME_NOT_FOUND		(M_taskLib | 101)
#define S_taskLib_TASK_HOOK_TABLE_FULL		(M_taskLib | 102)
#define S_taskLib_TASK_HOOK_NOT_FOUND		(M_taskLib | 103)
#define S_taskLib_TASK_SWAP_HOOK_REFERENCED	(M_taskLib | 104)
#define S_taskLib_TASK_SWAP_HOOK_SET		(M_taskLib | 105)
#define S_taskLib_TASK_SWAP_HOOK_CLEAR		(M_taskLib | 106)
#define S_taskLib_TASK_VAR_NOT_FOUND		(M_taskLib | 107)
#define S_taskLib_TASK_UNDELAYED		(M_taskLib | 108)
#define S_taskLib_ILLEGAL_PRIORITY		(M_taskLib | 109)


/* miscellaneous */

#define MAX_TASK_ARGS		10	/* max args passed to a task */
#define VX_MAX_TASK_SWITCH_RTNS	16	/* max task switch callout routines */
#define VX_MAX_TASK_SWAP_RTNS	16	/* max task swap callout routines */
#define VX_MAX_TASK_DELETE_RTNS	16	/* max task delete callout routines */
#define VX_MAX_TASK_CREATE_RTNS	16	/* max task create callout routines */

/* task option bits */

#define VX_SUPERVISOR_MODE	0x0001	/* OBSOLETE: tasks always in sup mode */
#define VX_UNBREAKABLE	  	0x0002	/* INTERNAL: breakpoints ignored */
#define VX_DEALLOC_STACK  	0x0004	/* INTERNAL: deallocate stack */
#define VX_FP_TASK	   	0x0008	/* 1 = f-point coprocessor support */
#define VX_STDIO	   	0x0010	/* OBSOLETE: need not be set for stdio*/
#define VX_ADA_DEBUG	   	0x0020	/* 1 = VADS debugger support */
#define VX_FORTRAN	   	0x0040	/* 1 = NKR FORTRAN support */
#define VX_PRIVATE_ENV 		0x0080	/* 1 = private environment variables */
#define VX_NO_STACK_FILL	0x0100	/* 1 = avoid stack fill of 0xee */

typedef void* WIND_TCB_ID;

typedef struct 			/* TASK_DESC - information structure */
    {
    int			td_id;		/* task id */
    char *		td_name;	/* name of task */
    int			td_priority;	/* task priority */
    int			td_status;	/* task status */
    int			td_options;	/* task option bits (see below) */
    FUNCPTR		td_entry;	/* original entry point of task */
    char *		td_sp;		/* saved stack pointer */
    char *		td_pStackBase;	/* the bottom of the stack */
    char *		td_pStackLimit;	/* the effective end of the stack */
    char *		td_pStackEnd;	/* the actual end of the stack */
    int			td_stackSize;	/* size of stack in bytes */
    int			td_stackCurrent;/* current stack usage in bytes */
    int			td_stackHigh;	/* maximum stack usage in bytes */
    int			td_stackMargin;	/* current stack margin in bytes */
    int			td_errorStatus;	/* most recent task error status */
    int			td_delay;	/* delay/timeout ticks */
    } TASK_DESC;

/* -----------------------------
 * taskVarLib.h
 * ----------------------------*/
typedef struct taskVar	/* TASK_VAR */
    {
    struct taskVar *	next;	/* ptr to next task variable */
    int *		address;/* address of variable to swap */
    int			value;	/* when task is not running: save of task's val;
				 * when task is running: save of orig. val */
    } TASK_VAR;

/* -----------------------------
 * tickLib.h
 * ----------------------------*/
typedef struct		/* TICK */
    {
    ULONG lower;		/* 00: least significant 32 bits */
    ULONG upper;		/* 04: most significant 32 bits */
    } TICK;

/* -----------------------------
 * unldLib.h
 * ----------------------------*/
/* unldLib Status Codes */
#define S_unldLib_MODULE_NOT_FOUND             (M_unldLib | 1)
#define S_unldLib_TEXT_IN_USE                  (M_unldLib | 2)

/* options for unld */
#define UNLD_KEEP_BREAKPOINTS	1 /* don't delete breakpoints from unld() */
#define UNLD_SYNC		2 /* already synchronizing a module */

/* -----------------------------
 * wdLib.h
 * ----------------------------*/
typedef void*  WDOG_ID;		/* watchdog id */

/* -----------------------------
 * wvLib.h
 * ----------------------------*/
/* The following defines are used to idicate which category of instrumentation
 * to turn on via wvEvtLogEnable (). 
 */
#define CONTEXT_SWITCH  1	/* context switch category */
#define TASK_STATE	2	/* Task state transition category */
#define OBJECT_STATUS	3	/* object status category */

/* The following defines are used to idicate which object type to set
 * or reset instrumentation via wvObjectEvtLog ().
 */
#define OBJ_TASK        1	/* task objects */
#define OBJ_SEM         2	/* semaphore objects */
#define OBJ_MSG         3	/* message queue objects */
#define OBJ_WD          4	/* watch-dog timer objects */

/* The following defines are used to idicate if created objects
 * should be instrumented or not. 
 */
#define INSTRUMENT_ON   1	/* object instrumentation on */
#define INSTRUMENT_OFF  2	/* object instrumentation off */


/* ========================================================================
 *  PROTO We need proto for wraping but not for compiling
 * ========================================================================*/
#ifndef JWRAP_CC2TORNADO

/* -----------------------------
 * signal.h
 * ----------------------------*/
extern int      raise(int __signo);
extern int	kill(int __tid, int __signo);

extern int 	sigemptyset(sigset_t *__set);
extern int 	sigfillset(sigset_t *__set);
extern int 	sigaddset(sigset_t *__set, int __signo);
extern int 	sigdelset(sigset_t *__set, int __signo);
extern int 	sigismember( sigset_t *__set, int __signo);
extern int 	sigaction(int __sig, struct sigaction *__act,
			  struct sigaction *__oact);
extern int 	sigprocmask(int __how, sigset_t *__set, sigset_t *__oset);
extern int 	sigpending(sigset_t *__set);
extern int 	sigsuspend(sigset_t *__sigmask);
extern int 	sigwait(sigset_t *__set);
extern int 	sigwaitinfo(sigset_t *__set, struct siginfo *__value);
extern int 	sigtimedwait(sigset_t *__set, struct siginfo *__value,
				struct timespec *);
extern int	sigqueue (int tid, int signo, union sigval value);

/* -----------------------------
 * time.h
 * ----------------------------*/
extern uint_t      _clocks_per_sec(void);
extern char *	   asctime ( struct tm *_tptr);
extern clock_t	   clock (void);
extern char *	   ctime ( time_t *_cal);
extern double	   difftime (time_t _t1, time_t _t0);
extern struct tm * gmtime ( time_t *_tod);
extern struct tm * localtime ( time_t *_tod);
extern time_t	   mktime (struct tm *_tptr);
extern size_t	   strftime (char *_s, size_t _n,  char *_format,
		   	       struct tm *_tptr);
extern time_t	   time (time_t *_tod);

extern int 	clock_gettime (clockid_t clock_id, struct timespec *tp);
extern int 	clock_settime (clockid_t clock_id,  struct timespec *tp);
extern int 	clock_getres (clockid_t clock_id, struct timespec *res);

extern int 	timer_create (clockid_t clock_id, struct sigevent *evp,
			      timer_t *ptimer);
extern int 	timer_delete (timer_t timerid);
extern int 	timer_gettime (timer_t timerid, struct itimerspec *value);
extern int 	timer_settime (timer_t timerid, int flags,
		                struct itimerspec *value,
			       struct itimerspec *ovalue);
extern int 	timer_getoverrun (timer_t timerid);

extern int      timer_connect (timer_t timerid, void* routine, int arg);
extern int      timer_cancel (timer_t timerid);
extern int      timer_show (timer_t timerid);
extern int 	nanosleep ( struct timespec *rqtp, struct timespec *rmtp);


/* -----------------------------
 * aio.h
 * ----------------------------*/
extern int   	aio_read (struct aiocb *);
extern int 	aio_write (struct aiocb *);
extern int 	lio_listio (int, struct aiocb **, int, 
		    	    struct sigevent *);
extern int 	aio_error (struct aiocb *);
extern size_t	aio_return (struct agiocb *);
extern int 	aio_cancel (int, struct aiocb *);
extern int 	aio_suspend (struct aiocb **, int , 
		             struct timespec *);
extern STATUS   aioPxLibInit (int lioMax);
extern STATUS   aioShow (int drvNum);


/* -----------------------------
 * stdio.h
 * ----------------------------*/
extern void	clearerr (FILE *);
extern int	fclose (FILE *);
extern int	feof (FILE *);
extern int	ferror (FILE *);
extern int	fflush (FILE *);
extern int	fgetc (FILE *);
extern int	fgetpos (FILE *, fpos_t *);
extern char *	fgets (char *, size_t, FILE *);
extern FILE *	fopen (const char *, const char *);
// extern int	fprintf (FILE *, const char *, ...);
extern int	fputc (int, FILE *);
extern int	fputs (const char *, FILE *);
extern int	fread (void *, size_t, size_t, FILE *);
extern FILE *	freopen (const char *, const char *, FILE *);
// extern int	fscanf (FILE *, const char *, ...);
extern int	fseek (FILE *, long, int);
extern int	fsetpos (FILE *, const fpos_t *);
extern long	ftell (FILE *);
extern int	fwrite (const void *, size_t, size_t, FILE *);
extern int	getc (FILE *);
extern int	getchar (void);
extern char *	gets (char *);
extern void	perror (const char *);
// extern int	printf (const char *, ...);
extern int	putc (int, FILE *);
extern int	putchar (int);
extern int	puts (const char *);
extern int	remove (const char *);
extern int	rename  (const char *, const char *);
extern void	rewind (FILE *);
// extern int	scanf (const char *, ...);
extern void	setbuf (FILE *, char *);
extern int	setvbuf (FILE *, char *, int, size_t);
// extern int	sprintf (char *, const char *, ...);
// extern int	sscanf (const char *, const char *, ...);
extern FILE *	tmpfile (void);
extern char *	tmpnam (char *);
extern int	ungetc (int, FILE *);
extern int	vfprintf (FILE *, const char *, va_list);
extern int	vprintf (const char *, va_list);
extern int	vsprintf (char *, const char *, va_list);

/* _EXTENSION_POSIX_1003 */
extern FILE *	fdopen (int, const char *);
extern int	fileno (FILE *);


/* ----------------------------------------------------------------
 *  stdlib.h 
 * ---------------------------------------------------------------*/
extern void	abort (void);
extern int	abs (int __i);
extern int	atexit (void *exit_handler);
extern double	atof ( char *__s);
extern int	atoi ( char *__s);
extern long	atol ( char *__s);
extern void *	bsearch ( void *__key,  void *__base,
		         size_t __nelem, size_t __size,
		         void* compare_function);
extern div_t	div (int __numer, int __denom);
extern long	labs (long __i);
extern div_t	ldiv (long __numer, long __denom);
extern int	mblen ( char *__s, size_t __n);
extern size_t	mbstowcs (wchar_t *__wcs,  char *__s, size_t __n);
extern int	mbtowc (wchar_t *__pwc,  char *__s, size_t __n);
extern void	qsort (void *__base, size_t __nelem, size_t __size,
		       int  (*__cmp)( void *__e1,  void *__e2));
extern int	rand (void);
extern void *	srand (unsigned int __seed);
//extern double	strtod ( char *__s, char **__endptr);
//extern long	strtol ( char *__s, char **__endptr, int __base);
//extern unsigned long strtoul ( char *__s, char **__endptr, int __base);
extern int	system ( char *__s);
extern size_t	wcstombs (char *__s,  wchar_t *__wcs, size_t __n);
extern int	wctomb (char *__s, wchar_t __wchar);

extern void *	calloc (size_t __nelem, size_t __size);
extern void	exit (int __status);
extern void	free (void *__ptr);
extern char *	getenv ( char *__name);
extern void *	malloc (size_t __size);
extern void *	realloc (void *__ptr, size_t __size);

/* -----------------------------------------------------------------------
 *  string.h 
 * ----------------------------------------------------------------------*/
extern void *	memchr ( void *__s, int __c, size_t __n);
extern int 	memcmp ( void *__s1,  void *__s2, size_t __n);
extern void *	memcpy (void *__s1,  void *__s2, size_t __n);
extern void *	memmove (void *__s1,  void *__s2, size_t __n);
extern void *	memset (void *__s, int __c, size_t __n);

extern char *	strcat (char *__s1,  char *__s2);
extern char *	strchr ( char *__s, int __c);
extern int 	strcmp ( char *__s1,  char *__s2);
extern int 	strcoll ( char *__s1,  char *__s2);
extern char *	strcpy (char *__s1,  char *__s2);
extern size_t 	strcspn ( char *__s1,  char *__s2);
extern size_t 	strlen ( char *__s);
extern char *	strncat (char *__s1,  char *__s2, size_t __n);
extern int 	strncmp ( char *__s1,  char *__s2, size_t __n);
extern char *	strncpy (char *__s1,  char *__s2, size_t __n);
extern char *	strpbrk ( char *__s1,  char *__s2);
extern char *	strrchr ( char *__s, int __c);
extern size_t 	strspn ( char *__s1,  char *__s2);
extern char *	strstr ( char *__s1,  char *__s2);
extern char *	strtok (char *__s,  char *__sep);
extern size_t 	strxfrm (char *__s1,  char *__s2, size_t __n);
extern char *	strerror(int __errcode);
//extern char *	strtok_r (char *__s,  char *__sep, char **__ppLast);

extern int	strerror_r (int __errcode, char *__buf);
extern void 	bcopy (const char *source, char *dest, int nbytes);
extern void 	bcopyBytes (char *source, char *dest, int nbytes);
extern void 	bcopyWords (char *source, char *dest, int nwords);
extern void 	bcopyLongs (char *source, char *dest, int nlongs);
extern void 	bfill (char *buf, int nbytes, int ch);
extern void 	bfillBytes (char *buf, int nbytes, int ch);
extern void 	bzero (char *buffer, int nbytes);
extern int 	bcmp (char *buf1, char *buf2, int nbytes);
extern void 	binvert (char *buf, int nbytes);
extern void 	bswap (char *buf1, char *buf2, int nbytes);
extern void 	uswab (char *source, char *destination, int nbytes);
extern void 	swab (char *source, char *dest, int nbytes);
extern char *	index (const char *s, int c);
extern char *	rindex (const char *s, int c);

/* ---------------------------------------------------------
 *  arp.h
 * ---------------------------------------------------------*/
extern STATUS 	arpAdd (char *host, char *eaddr, int flags);
extern STATUS 	arpDelete (char *host);
extern STATUS 	arpCmd (int cmd, struct in_addr * pIpAddr, u_char *pHwAddr,
			int *pFlags);
extern void 	arpFlush (void);

/* ---------------------------------------------------------
 *  bootLib.h
 * ---------------------------------------------------------*/
// extern STATUS 	bootBpAnchorExtract (char *string, char ** pAnchorAdrs);
extern STATUS 	bootNetmaskExtract (char *string, int *pNetmask);
// extern STATUS 	bootScanNum (char ** ppString, int *pValue, BOOL hex);
extern STATUS 	bootStructToString (char *paramString, BOOT_PARAMS
		*pBootParams);
extern char *	bootStringToStruct (char *bootString, BOOT_PARAMS *pBootParams);
extern void 	bootParamsErrorPrint (char *bootString, char *pError);
extern void 	bootParamsPrompt (char *string);
extern void 	bootParamsShow (char *paramString);

/* ---------------------------------------------------------
 *  boottLib.h
 * ---------------------------------------------------------*/
STATUS 	bootpParamsGet (char *ifName, int port, char *pInetAddr,
		        char *pHostAddr, char *pBootFile,
    		        int *pSizeFile, int *pSubnet, char* pGateway,
			u_int timeOut);

STATUS 	bootpMsgSend (char *ifName, struct in_addr *pIpDest, int port,
		      BOOTP_MSG *pBootpMsg, u_int timeOut);

u_char * bootpTagFind (u_char *pVend, int tag, int *pSize);

/* ---------------------------------------------------------
 *  hostLib.h
 * ---------------------------------------------------------*/
extern STATUS 	hostAdd (char *hostName, char *hostAddr);
extern STATUS 	hostDelete (char *name, char *addr);
extern STATUS 	hostGetByAddr (int addr, char *name);
extern int 	gethostname (char *name, int nameLen);
extern int 	hostGetByName (char *name);
extern int 	sethostname (char *name, int nameLen);
extern void 	hostTblInit (void);

/* -----------------------------
 * inet.h
 * ----------------------------*/
unsigned long inet_addr();
char    *inet_ntoa();
struct  in_addr inet_makeaddr();
unsigned long inet_network();

/* ---------------------------------------------------
 *  lstLib.h
 * ---------------------------------------------------*/
extern NODE *	lstFirst (LIST *pList);
extern NODE *	lstGet (LIST *pList);
extern NODE *	lstLast (LIST *pList);
extern NODE *	lstNStep (NODE *pNode, int nStep);
extern NODE *	lstNext (NODE *pNode);
extern NODE *	lstNth (LIST *pList, int nodenum);
extern NODE *	lstPrevious (NODE *pNode);
extern int 	lstCount (LIST *pList);
extern int 	lstFind (LIST *pList, NODE *pNode);
extern void 	lstAdd (LIST *pList, NODE *pNode);
extern void 	lstConcat (LIST *pDstList, LIST *pAddList);
extern void 	lstDelete (LIST *pList, NODE *pNode);
extern void 	lstExtract (LIST *pSrcList, NODE *pStartNode, NODE *pEndNode,
	  		    LIST *pDstList);
extern void 	lstFree (LIST *pList);
extern void 	lstInit (LIST *pList);
extern void 	lstInsert (LIST *pList, NODE *pPrev, NODE *pNode);

/* ---------------------------------------------------------
 * cacheLib.h
 * ---------------------------------------------------------*/
extern STATUS	cacheLibInit (CACHE_MODE inst, CACHE_MODE data);
extern STATUS	cacheArchLibInit (CACHE_MODE inst, CACHE_MODE data);
extern STATUS	cacheEnable (CACHE_TYPE cache);
extern STATUS	cacheDisable (CACHE_TYPE cache);
extern STATUS	cacheLock (CACHE_TYPE cache, void * adrs, size_t bytes);
extern STATUS	cacheUnlock (CACHE_TYPE cache, void * adrs, size_t bytes);
extern STATUS	cacheFlush (CACHE_TYPE cache, void * adrs, size_t bytes);
extern STATUS	cacheInvalidate (CACHE_TYPE cache, void *adrs, size_t bytes);
extern STATUS	cacheClear (CACHE_TYPE cache, void * adrs, size_t bytes);
extern STATUS	cacheTextUpdate (void * adrs, size_t bytes);
extern STATUS	cachePipeFlush (void);

extern void *	cacheDmaMalloc (size_t bytes);
extern STATUS	cacheDmaFree (void * pBuf);

extern STATUS	cacheDrvFlush (CACHE_FUNCS * pFuncs, void * adrs, size_t bytes);
extern STATUS	cacheDrvInvalidate (CACHE_FUNCS * pFuncs, void * adrs,
				    size_t bytes);
extern void *   cacheDrvVirtToPhys (CACHE_FUNCS * pFuncs, void * adrs);
extern void *   cacheDrvPhysToVirt (CACHE_FUNCS * pFuncs, void * adrs);

extern void	cacheFuncsSet (void);

/* ---------------------------------------------------------
 * dbgLib.h
 * ---------------------------------------------------------*/
extern STATUS 	c (int taskNameOrId, INSTR * addr, INSTR * addr1);
extern STATUS 	s (int taskNameOrId, INSTR * addr, INSTR * addr1);

extern void 	dbgHelp (void);
extern STATUS 	dbgInit (void);
extern STATUS 	b (INSTR * addr, int taskNameOrId, int count, BOOL quiet);
extern STATUS 	e (INSTR * addr, event_t eventId, int taskNameOrId,
			void *evtRtn, int arg);

extern STATUS 	bd (INSTR * addr, int taskNameOrId);
extern STATUS 	bdall (int taskNameOrId);
extern STATUS 	cret (int taskNameOrId);
extern STATUS 	so (int taskNameOrId);
extern void 	l (INSTR * addr, int count);
extern STATUS 	tt (int taskNameOrId);

extern void 	dbgPrintCall (INSTR * callAdrs, int funcAdrs, int nargs,
			      UINT32 * pArgs);
extern BOOL	dbgBrkExists (INSTR * addr, int task);
extern void	dbgBreakNotifyInstall (FUNCPTR breakpointRtn);
extern STATUS	dbgStepQuiet (int task);
extern STATUS	bdTask (int task);

/* ---------------------------------------------------------
 * dirEnt.h
 * ---------------------------------------------------------*/
extern DIR *	opendir (char *dirName);
extern STATUS 	closedir (DIR *pDir);
extern struct 	dirent *readdir (DIR *pDir);
extern void 	rewinddir (DIR *pDir);

/* ---------------------------------------------------------
 * dosFsLib.h
 * ---------------------------------------------------------*/
extern STATUS 		dosFsConfigGet (DOS_VOL_DESC *vdptr,
					DOS_VOL_CONFIG *pConfig);
extern STATUS 		dosFsConfigInit (DOS_VOL_CONFIG *pConfig,
					 char mediaByte, UINT8 secPerClust,
					 short nResrvd, char nFats,
					 UINT16 secPerFat, short maxRootEnts,
					 UINT nHidden, UINT options);
extern STATUS 		dosFsConfigShow (char *devName);
extern STATUS 		dosFsDateSet (int year, int month, int day);
extern void 		dosFsDateTimeInstall (FUNCPTR pDateTimeFunc);
extern DOS_VOL_DESC *	dosFsDevInit (char *devName, BLK_DEV *pBlkDev,
		                      DOS_VOL_CONFIG *pConfig);
extern STATUS		dosFsDevInitOptionsSet (UINT options);
extern STATUS 		dosFsInit (int maxFiles);
extern DOS_VOL_DESC *	dosFsMkfs (char *volName, BLK_DEV *pBlkDev);
extern STATUS		dosFsMkfsOptionsSet (UINT options);
extern void 		dosFsModeChange (DOS_VOL_DESC *vdptr, int newMode);
extern void 		dosFsReadyChange (DOS_VOL_DESC *vdptr);
extern STATUS 		dosFsTimeSet (int hour, int minute, int second);
extern STATUS 		dosFsVolOptionsGet (DOS_VOL_DESC *vdptr, 
					    UINT *pOptions);
extern STATUS 		dosFsVolOptionsSet (DOS_VOL_DESC *vdptr, UINT options);
extern STATUS 		dosFsVolUnmount (DOS_VOL_DESC *vdptr);

/* ---------------------------------------------------------
 * slLib.h
 * ---------------------------------------------------------*/
extern SL_LIST *sllCreate (void);
extern SL_NODE *sllEach (SL_LIST *pList, FUNCPTR routine, int routineArg);
extern SL_NODE *sllGet (SL_LIST *pList);
extern SL_NODE *sllPrevious (SL_LIST *pList, SL_NODE *pNode);
extern STATUS 	sllDelete (SL_LIST *pList);
extern STATUS 	sllInit (SL_LIST *pList);
extern STATUS 	sllTerminate (SL_LIST *pList);
extern int 	sllCount (SL_LIST *pList);
extern void 	sllPutAtHead (SL_LIST *pList, SL_NODE *pNode);
extern void 	sllPutAtTail (SL_LIST *pList, SL_NODE *pNode);
extern void 	sllRemove (SL_LIST *pList, SL_NODE *pDeleteNode,
			   SL_NODE *pPrevNode);

/* ---------------------------------------------------------
 * hashLib.h
 * ---------------------------------------------------------*/
extern BOOL 		hashKeyCmp (H_NODE_INT *pMatchHNode,
				    H_NODE_INT *pHNode, int keyCmpArg);
extern BOOL 		hashKeyStrCmp (H_NODE_STRING *pMatchHNode,
				       H_NODE_STRING *pHNode, int keyCmpArg);
extern HASH_ID 		hashTblCreate (int sizeLog2, FUNCPTR keyCmpRtn,
				       FUNCPTR keyRtn, int keyArg);
extern HASH_NODE *	hashTblEach (HASH_ID hashId, FUNCPTR routine,
				     int routineArg);
extern HASH_NODE *	hashTblFind (HASH_ID hashId, HASH_NODE *pMatchNode,
				     int keyCmpArg);
extern STATUS 		hashLibInit (void);
extern STATUS 		hashTblDelete (HASH_ID hashId);
extern STATUS 		hashTblDestroy (HASH_ID hashId, BOOL dealloc);
extern STATUS 		hashTblInit (HASH_TBL *pHashTbl, SL_LIST *pTblMem,
				     int sizeLog2, FUNCPTR keyCmpRtn,
				     FUNCPTR keyRtn, int keyArg);
extern STATUS 		hashTblPut (HASH_ID hashId, HASH_NODE *pHashNode);
extern STATUS 		hashTblRemove (HASH_ID hashId, HASH_NODE *pHashNode);
extern STATUS 		hashTblTerminate (HASH_ID hashId);
extern int 		hashFuncIterScale (int elements, H_NODE_STRING *pHNode,
					   int seed);
extern int 		hashFuncModulo (int elements, H_NODE_INT *pHNode,
					int divisor);
extern int 		hashFuncMultiply (int elements, H_NODE_INT *pHNode,
					  int multiplier);
/* ---------------------------------------------------------
 * iosLib.h
 * ---------------------------------------------------------*/
extern STATUS 	iosInit (int max_drivers, int max_files, char *nullDevName);
extern void 	iosShowInit (void);
//extern DEV_HDR *iosDevFind (char *name, char ** pNameTail);
extern DEV_HDR *iosFdDevFind (int fd);
extern DEV_HDR *iosNextDevGet (DEV_HDR *pDev);
extern STATUS 	iosClose (int fd);
extern STATUS 	iosDevAdd (DEV_HDR *pDevHdr, char *name, int drvnum);
extern STATUS 	iosDrvRemove (int drvnum, BOOL forceClose);
extern int 	iosCreate (DEV_HDR *pDevHdr, char *fileName, int mode);
extern int 	iosDelete (DEV_HDR *pDevHdr, char *fileName);
extern int 	iosDrvInstall (FUNCPTR pCreate, FUNCPTR pDelete, FUNCPTR pOpen,
			       FUNCPTR pClose, FUNCPTR pRead, FUNCPTR pWrite,
			       FUNCPTR pIoctl);
extern int 	iosFdNew (DEV_HDR *pDevHdr, char *name, int value);
extern int 	iosFdValue (int fd);
extern int 	iosIoctl (int fd, int function, int arg);
extern int 	iosOpen (DEV_HDR *pDevHdr, char *fileName, int flags, int mode);
extern int 	iosRead (int fd, char *buffer, int maxbytes);
extern int 	iosWrite (int fd, char *buffer, int nbytes);
extern void 	iosDevDelete (DEV_HDR *pDevHdr);
extern void 	iosDevShow (void);
extern void 	iosDrvShow (void);
extern void 	iosFdFree (int fd);
extern void 	iosFdSet (int fd, DEV_HDR *pDevHdr, char *name, int value);
extern void 	iosFdShow (void);

/* ---------------------------------------------------------
 * dllLib.h
 * ---------------------------------------------------------*/
extern DL_LIST *dllCreate (void);
extern DL_NODE *dllEach (DL_LIST *pList, FUNCPTR routine, int routineArg);
extern DL_NODE *dllGet (DL_LIST *pList);
extern STATUS 	dllDelete (DL_LIST *pList);
extern STATUS 	dllInit (DL_LIST *pList);
extern STATUS 	dllTerminate (DL_LIST *pList);
extern int 	dllCount (DL_LIST *pList);
extern void 	dllAdd (DL_LIST *pList, DL_NODE *pNode);
extern void 	dllInsert (DL_LIST *pList, DL_NODE *pPrev, DL_NODE *pNode);
extern void 	dllRemove (DL_LIST *pList, DL_NODE *pNode);


/* ---------------------------------------------------------
 * qFifoLib.h
 * ---------------------------------------------------------*/
extern Q_FIFO_HEAD *	qFifoCreate (void);
extern Q_FIFO_NODE *	qFifoGet (Q_FIFO_HEAD *pQFifoHead);
extern STATUS 		qFifoDelete (Q_FIFO_HEAD *pQFifoHead);
extern STATUS 		qFifoInit (Q_FIFO_HEAD *pQFifoHead);
extern int 		qFifoInfo (Q_FIFO_HEAD *pQFifoHead, int *nodeArray,
			   	   int maxNodes);
extern void 		qFifoPut (Q_FIFO_HEAD *pQFifoHead,
				  Q_FIFO_NODE *pQFifoNode, ULONG key);
extern STATUS 		qFifoRemove (Q_FIFO_HEAD *pQFifoHead,
				     Q_FIFO_NODE *pQFifoNode);
extern Q_FIFO_NODE *	qFifoEach (Q_FIFO_HEAD *pQHead, FUNCPTR routine, int
				   routineArg);

/* ---------------------------------------------------------
 * semLib.h
 * ---------------------------------------------------------*/
extern STATUS 	semGive (SEM_ID semId);
extern STATUS 	semTake (SEM_ID semId, int timeout);
extern STATUS 	semFlush (SEM_ID semId);
extern STATUS 	semDelete (SEM_ID semId);
extern int 	semInfo (SEM_ID semId, int *idList, int maxTasks);
extern STATUS 	semBLibInit (void);
extern SEM_ID 	semBCreate (int options, SEM_B_STATE initialState);
extern STATUS 	semCLibInit (void);
extern SEM_ID 	semCCreate (int options, int initialCount);
extern STATUS 	semMLibInit (void);
extern SEM_ID 	semMCreate (int options);
extern STATUS   semMGiveForce (SEM_ID semId);
extern STATUS 	semOLibInit (void);
extern SEM_ID 	semCreate (void);
extern void 	semShowInit (void);
extern STATUS 	semShow (SEM_ID semId, int level);

/* ---------------------------------------------------------
 * envLib.h
 * ---------------------------------------------------------*/
extern STATUS 	envLibInit ();
extern STATUS 	envPrivateCreate ();
extern STATUS 	envPrivateDestroy ();
extern STATUS 	putenv ();
extern void 	envShow ();

/* ---------------------------------------------------------
 * errnoLib.h
 * ---------------------------------------------------------*/
extern STATUS   errnoOfTaskSet (int taskId, int errorValue);
extern STATUS   errnoSet (int errorValue);
extern int      errnoGet (void);
extern int      errnoOfTaskGet (int taskId);

/* ---------------------------------------------------------
 * etherLib.h
 * ---------------------------------------------------------*/
extern STATUS 	etherAddrResolve (struct ifnet *pIf, char *targetAddr,
				  char *eHdr, int numTries, int numTicks);
extern STATUS 	etherInputHookAdd (FUNCPTR inputHook);
extern STATUS 	etherOutput (struct ifnet *pIf, struct ether_header
		*pEtherHeader, char *pData, int dataLength);
extern STATUS 	etherOutputHookAdd (FUNCPTR outputHook);
extern void 	etherInputHookDelete (void);
extern void 	etherOutputHookDelete (void);

/* -----------------------------
 * evtBufferLib.h
 * ----------------------------*/
extern BOOL   evtBufferIsEmpty (void);
extern char * evtBufferAddress (void);
extern STATUS evtBufferToFile ( char * filename);
extern void   evtBufferUpLoad (void);

/* -----------------------------
 * excLib.h
 * ----------------------------*/
extern STATUS 	excVecInit (void);
extern STATUS 	excShowInit (void);
extern STATUS 	excInit (void);
extern void 	excHookAdd (FUNCPTR excepHook);
extern void 	excTask (void);
extern STATUS 	excJobAdd (VOIDFUNCPTR func, int arg1, int arg2, int arg3,
			   int arg4, int arg5, int arg6);

/* -----------------------------
 * ftpLib.h
 * ----------------------------*/
extern STATUS 	ftpLogin (int ctrlSock, char *user, char *passwd,
			  char *account);
extern STATUS 	ftpXfer (char *host, char *user, char *passwd, char *acct,
			 char *cmd, char *dirname, char *filename,
			 int *pCtrlSock, int *pDataSock);
extern int 	ftpCommand (int ctrlSock, char *fmt, int arg1, int arg2,
			    int arg3, int arg4, int arg5, int arg6);
extern int 	ftpDataConnGet (int dataSock);
extern int 	ftpDataConnInit (int ctrlSock);
extern int 	ftpHookup (char *host);
extern int 	ftpReplyGet (int ctrlSock, BOOL expecteof);

/* -----------------------------
 * ftpdLib.h
 * ----------------------------*/
extern STATUS 	ftpdInit (int stackSize);
extern STATUS 	ftpdTask (void);
extern void 	ftpdDelete (void);

/* -----------------------------
 * ifLib.h
 * ----------------------------*/
extern STATUS 	ifAddrSet (char *interfaceName, char *interfaceAddress);
extern STATUS 	ifAddrGet (char *interfaceName, char *interfaceAddress);
extern STATUS 	ifBroadcastSet (char *interfaceName, char *broadcastAddress);
extern STATUS 	ifBroadcastGet (char *interfaceName, char *broadcastAddress);
extern STATUS 	ifDstAddrSet (char *interfaceName, char *dstAddress);
extern STATUS 	ifDstAddrGet (char *interfaceName, char *dstAddress);
extern STATUS 	ifMaskSet (char *interfaceName, int netMask);
extern STATUS 	ifMaskGet (char *interfaceName, int *netMask);
extern STATUS 	ifFlagChange (char *interfaceName, int flags, BOOL on);
extern STATUS 	ifFlagSet (char *interfaceName, int flags);
extern STATUS 	ifFlagGet (char *interfaceName, int *flags);
extern STATUS 	ifMetricSet (char *interfaceName, int metric);
extern STATUS 	ifMetricGet (char *interfaceName, int *pMetric);
extern int 	ifRouteDelete (char *ifName, int unit);
extern struct 	ifnet *ifunit (char *ifname);

/* -----------------------------
 * if_bp.h
 * ----------------------------*/
extern STATUS	bpattach (int unit, char *pAnchor, int procNum, int intType,
			  int intArg1, int intArg2, int intArg3);
extern STATUS	bpInit (char *pAnchor, char *pMem, int memSize, BOOL tasOK);
extern void	bpShow (char *bpName, BOOL zero);

/* -----------------------------
 * if_sl.h
 * ----------------------------*/
extern STATUS	slipInit (int unit, char *devName, char *myAddr,
		    char *peerAddr, int baud, BOOL compressEnable,
		    BOOL compressAllow, int mtu);
extern STATUS	slipBaudSet (int unit, int baud);

/* -----------------------------
 * intLib.h
 * ----------------------------*/
extern STATUS 	intConnect (FUNCPTR *vector, FUNCPTR routine,
	       	    	    int parameter);
extern FUNCPTR 	intHandlerCreate (FUNCPTR routine, int parameter);
extern void 	intLockLevelSet (int newLevel);
extern int 	intLockLevelGet (void);
extern BOOL 	intContext (void);
extern int 	intCount (void);
extern void 	intVecBaseSet (FUNCPTR *baseAddr);
extern FUNCPTR *intVecBaseGet (void);
extern void 	intVecSet (FUNCPTR *vector, FUNCPTR function);
extern FUNCPTR 	intVecGet (FUNCPTR *vector);
extern int 	intLevelSet (int level);
extern int 	intLock (void);
extern int 	intUnlock (int oldSR);
//extern int 	intRegsLock (REG_SET *pRegs);
//extern void 	intRegsUnlock (REG_SET *pRegs, int lockKey);
extern STATUS   intVecTableWriteProtect (void);

#if (CPU_FAMILY == MIPS)
extern int    intCRGet(void);
extern void   intCRSet(int value);
extern int    intSRGet(void);
extern int    intSRSet(int value);
#endif /* (CPU_FAMILY == MIPS) */

#if	(CPU_FAMILY == SPARC)
extern void 	intAckConfig ();
extern void 	intTBRSet (FUNCPTR *baseAddr);
extern STATUS   intVecTableWriteEnable (void);
#endif

#if	(CPU_FAMILY == AM29XXX)
extern FUNCPTR	intHandlerCreateAm29k (FUNCPTR *vector, FUNCPTR routine,
				       int parameter);
#endif /* (CPU_FAMILY == AM29XXX) */

#if	(CPU == AM29200)
extern STATUS	am29200Intr3DeMuxConnect (VOIDFUNCPTR deMuxFct, int parameter);
#endif /* (CPU == AM29200) */

#if	((CPU_FAMILY == PPC) || (CPU_FAMILY == MIPS))
extern int	intDisable (int);
extern int	intEnable (int);
#endif	/* ((CPU_FAMILY == PPC) || ((CPU_FAMILY == MIPS)) */

/* -------------------------------------
 * loadLib.h
 * -------------------------------------*/
extern MODULE_ID loadModule (int fd, int symFlag);
//extern MODULE_ID loadModuleAt (int fd, int symFlag, char **ppText,
//			       char **ppData, char **ppBss);
//extern MODULE_ID loadModuleAtSym (int fd, int symFlag, char **ppText,
//				  char **ppData, char **ppBss,
//				  SYMTAB_ID symTbl);
extern MODULE_ID loadModuleGet (char *fileName, int format, int *symFlag);
extern void addSegNames (int fd, char *pText, char *pData, char *pBss,
			 SYMTAB_ID symTbl, UINT16 group);
extern STATUS loadSegmentsAllocate (SEG_INFO *pSeg);

/* -------------------------------------
 * loginLib.h
 * -------------------------------------*/
extern STATUS 	loginDefaultEncrypt (char *in, char *out);
extern STATUS 	loginPrompt (char *userName);
extern STATUS 	loginUserAdd (char *name, char *passwd);
extern STATUS 	loginUserDelete (char *name, char *passwd);
extern STATUS 	loginUserVerify (char *name, char *passwd);
extern void 	loginEncryptInstall (FUNCPTR rtn, int var);
extern void 	loginInit (void);
extern void 	loginStringSet (char *newString);
extern void 	loginUserShow (void);


/* -------------------------------------
 * logLib.h
 * -------------------------------------*/
extern STATUS 	logFdAdd (int fd);
extern STATUS 	logFdDelete (int fd);
extern STATUS 	logInit (int fd, int maxMsgs);
extern int	logMsg (char *fmt, int arg1, int arg2,
			int arg3, int arg4, int arg5, int arg6);
extern void 	logFdSet (int fd);
extern void 	logShow (void);
extern void 	logTask (void);

/* -------------------------------------
 * memDrv.h
 * -------------------------------------*/
extern STATUS 	memDrv (void);
extern STATUS 	memDevCreate (char *name, char *base, int length);

/* -------------------------------------
 * memLib.h
 * -------------------------------------*/
extern STATUS 	memInit (char *pPool, unsigned int poolSize);
extern STATUS 	memPartLibInit (char *pPool, unsigned int poolSize);
extern PART_ID 	memPartCreate (char *pPool, unsigned int poolSize);
extern void 	memPartInit (PART_ID partId, char *pPool, unsigned int poolSize);
extern STATUS 	memPartAddToPool (PART_ID partId, char *pPool,
				  unsigned int poolSize);
extern void 	memAddToPool (char *pPool, unsigned int poolSize);
extern void *	memPartAlloc (PART_ID partId, unsigned int nBytes);
extern void *   memPartAlignedAlloc (PART_ID partId, unsigned int nBytes,
				     unsigned int alignment);
extern void *	memalign (unsigned int alignment, unsigned int size);
extern void *   valloc (unsigned int size);
extern STATUS 	memPartFree (PART_ID partId, char *pBlock);
extern STATUS 	memPartOptionsSet (PART_ID partId, unsigned int options);
extern int 	memFindMax (void);
extern int 	memPartFindMax (PART_ID partId);
extern void *	memPartRealloc (PART_ID partId, char *pBlock, unsigned int nBytes);
extern void 	memOptionsSet (unsigned int options);
extern STATUS 	cfree (char *pBlock);
extern void 	memShowInit (void);
extern void 	memShow (int type);
extern STATUS 	memPartShow (PART_ID partId, int type);
extern STATUS   memPartInfoGet (PART_ID	partId, MEM_PART_STATS * ppartStats);

/* -------------------------------------
 * moduleLib.h
 * -------------------------------------*/
extern STATUS moduleLibInit (void);
extern MODULE_ID moduleCreate (char *name, int format, int flags);
extern STATUS moduleInit (MODULE_ID moduleId, char *name, int format,
			  int flags);
extern STATUS moduleTerminate (MODULE_ID moduleId);
extern STATUS moduleDelete (MODULE_ID moduleId);
extern MODULE_ID moduleIdFigure (void *moduleNameOrId);
extern STATUS moduleShow (char *moduleNameOrId, int options);
extern STATUS moduleSegAdd (MODULE_ID moduleId, int type, void *location,
			    int length, int flags);
extern SEGMENT_ID moduleSegGet (MODULE_ID moduleId);
extern SEGMENT_ID moduleSegFirst (MODULE_ID moduleId);
extern SEGMENT_ID moduleSegNext (SEGMENT_ID segmentId);
extern SEGMENT_ID moduleSegEach (MODULE_ID moduleId, FUNCPTR routine,
				 int userArg);
extern STATUS moduleCreateHookAdd (FUNCPTR moduleCreateHookRtn);
extern STATUS moduleCreateHookDelete (FUNCPTR moduleCreateHookRtn);
extern MODULE_ID moduleFindByName (char *moduleName);
extern MODULE_ID moduleFindByNameAndPath (char *moduleName, char *pathName);
extern MODULE_ID moduleFindByGroup (int groupNumber);
extern MODULE_ID moduleEach (FUNCPTR routine, int userArg);
extern int moduleIdListGet (MODULE_ID *idList, int maxModules);
extern STATUS moduleInfoGet (MODULE_ID moduleId, MODULE_INFO *pModuleInfo);
extern char * moduleNameGet (MODULE_ID moduleId);
extern int moduleFlagsGet (MODULE_ID moduleId);
STATUS moduleCheck (int options);

/* -------------------------------------
 * mountLib.h
 * -------------------------------------*/
extern STATUS mountdInit (int priority, int stackSize, FUNCPTR authHook,
			  int nExports, int options);
extern void mountd (void);
extern STATUS nfsExport (char * directory, int id, int mode, int options);
extern STATUS nfsUnexport (char * dirName);
extern NFS_EXPORT_ENTRY * nfsExportFindByName (char * dirName);
extern NFS_EXPORT_ENTRY * nfsExportFindById (int volumeId);
extern int fdToInode (int fd);
extern int nameToInode (char * fileName);

/* -------------------------------------
 * mqueue.h
 * -------------------------------------*/
// extern mqd_t mq_open (const char *, int, ...);
extern int mq_close (mqd_t);
extern int mq_unlink (const char *);
extern int mq_send (mqd_t handle, const void *, size_t, int);
extern int mq_receive (mqd_t handle, void *, size_t, int *);
extern int mq_notify (mqd_t handle, struct sigevent *);
extern int mq_setattr (mqd_t handle, struct mq_attr *, struct mq_attr *);
extern int mq_getattr (mqd_t handle, struct mq_attr *);

/* -------------------------------------
 * msgQLib.h
 * -------------------------------------*/
extern STATUS 	msgQLibInit (void);
extern MSG_Q_ID msgQCreate (int maxMsgs, int maxMsgLength, int options);
extern STATUS 	msgQDelete (MSG_Q_ID msgQId);
extern STATUS 	msgQSend (MSG_Q_ID msgQId, char *buffer, UINT nBytes,
			  int timeout, int priority);
extern int 	msgQReceive (MSG_Q_ID msgQId, char *buffer, UINT maxNBytes,
			     int timeout);
extern STATUS 	msgQInfoGet (MSG_Q_ID msgQId, MSG_Q_INFO *pInfo);
extern int 	msgQNumMsgs (MSG_Q_ID msgQId);
extern void 	msgQShowInit (void);
extern STATUS 	msgQShow (MSG_Q_ID msgQId, int level);

/* -----------------------------
 * msgQSmLib.h
 * ----------------------------*/
extern MSG_Q_ID  msgQSmCreate (int maxMsgs, int maxMsgLength, int options);
extern void      msgQSmShowInit ();

/* -----------------------------
 * netShow.h
 * ----------------------------*/
extern void 	arptabShow (void);
extern void 	arpShow (void);
extern void 	icmpstatShow (void);
extern void 	ifShow (char *ifName);
extern void 	inetstatShow (void);
extern void 	ipstatShow (BOOL zero);
extern void 	mbufShow (void);
extern void 	netShowInit (void);
extern void 	tcpDebugShow (int numPrint, int verbose);
extern void 	tcpstatShow (void);
extern void 	udpstatShow (void);
extern void 	routeShow (void);
extern void 	hostShow (void);

/* -----------------------------
 * nfsdLib.h
 * ----------------------------*/
extern STATUS nfsdInit (int nServers, int nExportedFs, int priority,
			FUNCPTR authHook, FUNCPTR mountAuthHook, int options);
extern void nfsdRequestProcess (void);
extern void nfsd (void);
extern STATUS nfsdStatusGet (NFS_SERVER_STATUS * serverStats);
extern STATUS nfsdStatusShow (int options);
extern STATUS nfsdFhCreate (NFS_FILE_HANDLE * parentDir, char * fileName,
			    NFS_FILE_HANDLE * fh);
extern STATUS nfsdFhToName (NFS_FILE_HANDLE * fh, char * fileName);
extern STATUS nfsdFattrGet (NFS_FILE_HANDLE * fh,
			    struct fattr * fileAttributes);
// extern nfsstat nfsdErrToNfs (int theErr);
extern void nfsdFhHton (NFS_FILE_HANDLE * fh);
extern void nfsdFhNtoh (NFS_FILE_HANDLE * fh);

/* -----------------------------
 * nfsLib.h
 * ----------------------------*/
extern STATUS 	nfsExportShow (char *hostName);
extern void 	nfsAuthUnixGet (char *machname, int *pUid, int *pGid,
			        int *pNgids, int *gids);
extern void 	nfsAuthUnixSet (char *machname, int uid, int gid,
			        int ngids, int *aup_gids);
extern void 	nfsAuthUnixPrompt (void);
extern void 	nfsAuthUnixShow (void);
extern void 	nfsHelp (void);
extern void 	nfsIdSet (int uid);

/* -----------------------------
 * nfsDrv.h
 * ----------------------------*/
extern STATUS 	nfsDrv (void);
extern STATUS 	nfsMount (char *host, char *fileSystem, char *localName);
extern STATUS 	nfsMountAll (char *host, char *clientName, BOOL quiet);
extern void 	nfsDevShow (void);
extern STATUS 	nfsUnmount (char *localName);
extern int      nfsDevListGet (unsigned long *nfsDevList, int listSize);
extern STATUS   nfsDevInfoGet (unsigned long nfsDevHandle, 
			       NFS_DEV_INFO  * pnfsInfo);
/* -----------------------------
 * pingLib.h
 * ----------------------------*/
extern STATUS	 pingLibInit (void);
extern STATUS	 ping (char *host, int numPackets, ULONG options);

/* -----------------------------
 * pipeDrv.h
 * ----------------------------*/
extern STATUS 	pipeDevCreate (char *name, int nMessages, int nBytes);
extern STATUS 	pipeDrv (void);

/* -----------------------------
 * proxyArpLib.h
 * ----------------------------*/
extern STATUS 	proxyArpLibInit (int clientSizeLog2, int portSizeLog2);
extern void 	proxyPortShow (void);
extern STATUS 	proxyPortFwdOn (int port);
extern STATUS 	proxyPortFwdOff (int port);
extern STATUS 	proxyNetCreate (char * proxyAddr, char * mainAddr);
extern STATUS 	proxyNetDelete (char * proxyAddr);
extern STATUS 	proxyClientAdd (struct in_addr * pProxyNetAddr,
			        struct in_addr * pClientAddr);
extern STATUS 	proxyClientDelete (struct in_addr * pClientAddr);

/* -----------------------------
 * proxyLib.h
 * ----------------------------*/
extern STATUS 	proxyReg (char *ifName, char *proxyAddr);
extern STATUS 	proxyUnreg (char *ifName, char *proxyAddr);

/* -----------------------------
 * ramDrv.h
 * ----------------------------*/
extern STATUS 	ramDrv (void);
extern BLK_DEV *ramDevCreate (char *ramAddr, int bytesPerSec, int secPerTrack,
			      int nSectors, int secOffset);

/* -----------------------------
 * rebootLib.h
 * ----------------------------*/
extern STATUS 	rebootHookAdd (FUNCPTR rebootHook);
extern void 	reboot (int startType);

/* -----------------------------
 * remLib.h
 * ----------------------------*/
extern STATUS 	bindresvport (int sd, struct sockaddr_in *sin);
extern STATUS 	iam (char *newUser, char *newPasswd);
extern STATUS 	remCurIdSet (char *newUser, char *newPasswd);
extern int 	rcmd (char *host, int remotePort, char *localUser,
		      char *remoteUser, char *cmd, int *fd2p);
extern int 	rresvport (int *alport);
extern void 	remCurIdGet (char *user, char *passwd);
extern void 	whoami (void);

/* -----------------------------
 * rlogLib.h
 * ----------------------------*/
extern STATUS 	rlogInit (void);
extern STATUS 	rlogin (char *host);
extern void 	rlogChildTask (void);
extern void 	rlogInTask (int sock, int ptyMfd);
extern void 	rlogOutTask (int sock, int ptyMfd);
extern void 	rlogind (void);

/* -----------------------------
 * rngLib.h
 * ----------------------------*/
extern BOOL 	rngIsEmpty (RING_ID ringId);
extern BOOL 	rngIsFull (RING_ID ringId);
extern RING_ID 	rngCreate (int nbytes);
extern int 	rngBufGet (RING_ID rngId, char *buffer, int maxbytes);
extern int 	rngBufPut (RING_ID rngId, char *buffer, int nbytes);
extern int 	rngFreeBytes (RING_ID ringId);
extern int 	rngNBytes (RING_ID ringId);
extern void 	rngDelete (RING_ID ringId);
extern void 	rngFlush (RING_ID ringId);
extern void 	rngMoveAhead (RING_ID ringId, int n);
extern void 	rngPutAhead (RING_ID ringId, char byte, int offset);

/* -----------------------------
 * routeLib.h
 * ----------------------------*/
extern STATUS 	routeAdd (char *destination, char *gateway);
extern STATUS 	routeDelete (char *destination, char *gateway);
extern STATUS 	routeNetAdd (char *destination, char *gateway);
extern STATUS 	routeCmd (int destInetAddr, int gateInetAddr, int ioctlCmd);

/* -----------------------------
 * semSmLib.h
 * ----------------------------*/
extern    SEM_ID       semBSmCreate (int options, SEM_B_STATE initialState);
extern    SEM_ID       semCSmCreate (int options, int initialCount);
extern    void         semSmShowInit ();

/* -----------------------------
 * smMemLib.h
 * ----------------------------*/
extern PART_ID 	  memPartSmCreate (char * pPool, unsigned int poolSize);
extern STATUS     smMemFree (void * ptr);
extern int        smMemFindMax (void);
extern void *     smMemMalloc (unsigned int nBytes);
extern void *     smMemCalloc (int elemNum, int elemSize);
extern void *     smMemRealloc (void * pBlock, unsigned int newSize);
extern STATUS     smMemAddToPool (char * pPool, unsigned int poolSize);
extern STATUS     smMemOptionsSet (unsigned int options);
extern void       smMemShowInit (void);
extern void       smMemShow (int type);

/* -----------------------------
 * smNameLib.h
 * ----------------------------*/
extern    STATUS       smNameAdd (char * name, void * value, int type);
extern    STATUS       smNameFind (char * name, void ** pValue,
                                   int * pType, int waitType);
extern    STATUS       smNameFindByValue (void * value, char * name, 
                                          int * pType, int waitType);
extern    STATUS       smNameRemove (char * name);
extern    void         smNameShowInit (void);
extern    STATUS       smNameShow (int level);

/* -----------------------------
 * smObjLib.h
 * ----------------------------*/
extern STATUS smObjLibInit (void);
extern void * smObjLocalToGlobal (void * localAdrs);
extern void * smObjGlobalToLocal (void * globalAdrs);
extern void   smObjTimeoutLogEnable (BOOL timeoutLogEnable);
extern void   smObjShowInit (void);
extern STATUS smObjShow (void);

/* -----------------------------
 * sockLib.h
 * ----------------------------*/
extern STATUS 	sockLibInit (int fdMax);
extern STATUS 	sockLibAdd (FUNCPTR sockLibInitRtn, int domainMap,
		    int domainReal);
extern STATUS 	bind (int s, struct sockaddr *name, int namelen);
extern STATUS 	connect (int s, struct sockaddr *name, int namelen);
extern STATUS 	connectWithTimeout (int sock, struct sockaddr *adrs,
				    int adrsLen, struct timeval *timeVal);
extern STATUS 	getpeername (int s, struct sockaddr *name, int *namelen);
extern STATUS 	getsockname (int s, struct sockaddr *name, int *namelen);
extern STATUS 	getsockopt (int s, int level, int optname, char *optval,
			    int *optlen);
extern STATUS 	listen (int s, int backlog);
extern STATUS 	setsockopt (int s, int level, int optname, char *optval,
			    int optlen);
extern STATUS 	shutdown (int s, int how);
extern int 	accept (int s, struct sockaddr *addr, int *addrlen);
extern int 	recv (int s, char *buf, int bufLen, int flags);
extern int 	recvfrom (int s, char *buf, int bufLen, int flags,
			  struct sockaddr *from, int *pFromLen);
extern int 	recvmsg (int sd, struct msghdr *mp, int flags);
extern int 	send (int s, char *buf, int bufLen, int flags);
extern int 	sendmsg (int sd, struct msghdr *mp, int flags);
extern int 	sendto (int s, caddr_t buf, int bufLen, int flags,
			struct sockaddr *to, int tolen);
extern int 	socket (int domain, int type, int protocol);

/* -----------------------------
 * spyLib.h
 * ----------------------------*/
extern void 	spyLibInit (void);
extern STATUS 	spyClkStartCommon (int intsPerSec, FUNCPTR printRtn);
extern void 	spyCommon (int freq, int ticksPerSec, FUNCPTR printRtn);
extern void 	spyClkStopCommon (void);
extern void 	spyReportCommon (FUNCPTR printRtn);
extern void 	spyStopCommon (void);
extern void 	spyComTask (int freq, FUNCPTR printRtn);

/* -----------------------------
 * symLib.h
 * ----------------------------*/
extern STATUS 	symLibInit (void);
extern SYMBOL *	symEach (SYMTAB_ID symTblId, FUNCPTR routine, int routineArg);
extern char *	symName (SYMTAB_ID symTbl, char *value);
extern void 	symShowInit (void);
extern STATUS 	symShow (SYMTAB_ID pSymTbl, char *substr);
extern STATUS 	symTblDelete (SYMTAB_ID symTblId);
extern STATUS 	symTblTerminate (SYMTAB_ID symTblId);
extern STATUS 	symTblDestroy (SYMTAB_ID symTblId, BOOL dealloc);
extern STATUS 	symFree (SYMTAB_ID symTblId, SYMBOL *pSymbol);
extern STATUS   symSAdd (SYMTAB_ID symTblId, char *name, char *value,
			SYM_TYPE type, UINT16 group);
extern STATUS   symAdd (SYMTAB_ID symTblId, char *name, char *value,
			SYM_TYPE type, UINT16 group);
extern STATUS 	symTblAdd (SYMTAB_ID symTblId, SYMBOL *pSymbol);
extern STATUS 	symRemove (SYMTAB_ID symTblId, char *name, SYM_TYPE type);
extern STATUS 	symTblRemove (SYMTAB_ID symTblId, SYMBOL *pSymbol);
extern STATUS 	symInit (SYMBOL *pSymbol, char *name, char *value,
		         SYM_TYPE type, UINT16 group);
extern SYMBOL *	symAlloc (SYMTAB_ID symTblId, char *name, char *value,
			  SYM_TYPE type, UINT16 group);
extern STATUS 	symTblInit (SYMTAB_ID pSymTbl, BOOL sameNameOk,
			    PART_ID symPartId, HASH_ID symHashTblId);
extern SYMTAB_ID symTblCreate (int hashSizeLog2, BOOL sameNameOk,
			       PART_ID symPartId);
extern STATUS 	symFindSymbol (SYMTAB_ID symTblId, char *name, SYM_TYPE type,
			       SYM_TYPE mask, SYMBOL **ppSymbol);
//extern STATUS 	symFindByName (SYMTAB_ID symTblId, char *name, char **pValue,
//			       SYM_TYPE *pType);
extern STATUS 	symFindByValue (SYMTAB_ID symTblId, UINT value, char *name,
				int *pValue, SYM_TYPE *pType);
//extern STATUS 	symFindByCName (SYMTAB_ID symTblId, char *name, char **pValue,
//				SYM_TYPE *pType);
//extern STATUS 	symFindByNameAndType (SYMTAB_ID symTblId, char *name,
//				      char **pValue, SYM_TYPE *pType,
//				      SYM_TYPE sType, SYM_TYPE mask);
extern STATUS 	symFindByValueAndType (SYMTAB_ID symTblId, UINT value,
				       char *name, int *pValue, SYM_TYPE *pType,
				       SYM_TYPE sType, SYM_TYPE mask);

/* -----------------------------
 * sysLib.h
 * ----------------------------*/
extern char *	sysModel (void);
extern char *	sysBspRev (void);
extern char *	sysMemTop (void);
extern char *	sysPhysMemTop (void);
extern STATUS 	sysToMonitor (int startType);
extern int 	sysProcNumGet (void);
extern void 	sysProcNumSet (int procNum);
extern BOOL 	sysBusTas (char *adrs);
extern STATUS 	sysNvRamGet (char *string, int strLen, int offset);
extern STATUS 	sysNvRamSet (char *string, int strLen, int offset);
extern void	sysSerialReset (void);
// extern STATUS	sysLocalToBusAdrs (int adrsSpace, char *localAdrs,
//				   char **pBusAdrs);
//extern STATUS	sysBusToLocalAdrs (int adrsSpace, char *busAdrs,
//				   char **pLocalAdrs);
extern int	sysBusIntAck (int intLevel);
extern STATUS	sysBusIntGen (int level, int vector);
extern STATUS	sysMailboxConnect (FUNCPTR routine, int arg);
extern STATUS	sysMailboxEnable (char *mailboxAdrs);

/* -----------------------------
 * taskHookLib.h
 * ----------------------------*/
extern void	taskHookInit (void);
extern STATUS 	taskCreateHookAdd (FUNCPTR createHook);
extern STATUS 	taskCreateHookDelete (FUNCPTR createHook);
extern STATUS 	taskDeleteHookAdd (FUNCPTR deleteHook);
extern STATUS 	taskDeleteHookDelete (FUNCPTR deleteHook);
extern STATUS 	taskSwapHookAdd (FUNCPTR swapHook);
extern STATUS 	taskSwapHookAttach (FUNCPTR swapHook,int tid,BOOL in,BOOL out);
extern STATUS 	taskSwapHookDelete (FUNCPTR swapHook);
extern STATUS 	taskSwapHookDetach (FUNCPTR swapHook,int tid,BOOL in,BOOL out);
extern STATUS 	taskSwitchHookAdd (FUNCPTR switchHook);
extern STATUS 	taskSwitchHookDelete (FUNCPTR switchHook);
extern void	taskHookShowInit (void);
extern void 	taskCreateHookShow (void);
extern void 	taskDeleteHookShow (void);
extern void 	taskSwapHookShow (void);
extern void 	taskSwitchHookShow (void);



/* -----------------------------
 * taskLib.h
 * ----------------------------*/
extern int 	taskSpawn (char *name, int priority, int options, int stackSize,
		      	   FUNCPTR entryPt, int arg1, int arg2, int arg3,
		      	   int arg4, int arg5, int arg6, int arg7,
		      	   int arg8, int arg9, int arg10);

extern STATUS 	taskInit (WIND_TCB_ID pTcb, char *name, int priority, int options,
			  char *pStackBase, int stackSize, FUNCPTR entryPt,
			  int arg1, int arg2, int arg3, int arg4, int arg5,
			  int arg6, int arg7, int arg8, int arg9, int arg10);
extern STATUS 	taskActivate (int tid);
extern STATUS 	taskDelete (int tid);
extern STATUS 	taskDeleteForce (int tid);
extern STATUS 	taskSuspend (int tid);
extern STATUS 	taskResume (int tid);
extern STATUS 	taskRestart (int tid);
extern STATUS 	taskPrioritySet (int tid, int newPriority);
extern STATUS 	taskPriorityGet (int tid, int *pPriority);
extern STATUS 	taskLock (void);
extern STATUS 	taskUnlock (void);
extern STATUS 	taskSafe (void);
extern STATUS 	taskUnsafe (void);
extern STATUS 	taskDelay (int ticks);
extern STATUS 	taskOptionsSet (int tid, int mask, int newOptions);
extern STATUS 	taskOptionsGet (int tid, int *pOptions);
extern char *	taskName (int tid);
extern int 	taskNameToId (char *name);
extern STATUS 	taskIdVerify (int tid);
extern int 	taskIdSelf (void);
extern int 	taskIdDefault (int tid);
extern BOOL 	taskIsReady (int tid);
extern BOOL 	taskIsSuspended (int tid);
extern WIND_TCB_ID taskTcb (int tid);
extern int 	taskIdListGet (int *idList, int maxTasks);
extern STATUS 	taskInfoGet (int tid, TASK_DESC *pTaskDesc);
extern STATUS 	taskStatusString (int tid, char *pString);
extern STATUS 	taskOptionsString (int tid, char *pString);
// extern STATUS 	taskRegsGet (int tid, REG_SET *pRegs);
// extern STATUS 	taskRegsSet (int tid, REG_SET *pRegs);
extern void 	taskRegsShow (int tid);
extern void *	taskStackAllot (int tid, unsigned int nBytes);
extern void 	taskShowInit (void);
extern STATUS 	taskShow (int tid, int level);


/* -----------------------------------------------
 *  TaskVarLib.h
 * -----------------------------------------------*/
extern STATUS 	taskVarAdd (int tid, int *pVar);
extern STATUS 	taskVarDelete (int tid, int *pVar);
extern STATUS 	taskVarInit (void);
extern STATUS 	taskVarSet (int tid, int *pVar, int value);
extern int 	taskVarGet (int tid, int *pVar);
extern int 	taskVarInfo (int tid, TASK_VAR *varList, int maxVars);

/* -----------------------------
 * tickLib.h
 * ----------------------------*/
extern void 	tickAnnounce (void);
extern void 	tickSet (ULONG ticks);
extern ULONG 	tickGet (void);

/* -----------------------------
 * timexLib.h
 * ----------------------------*/
extern void 	timex (FUNCPTR func, int arg1, int arg2, int arg3, int arg4,
		       int arg5, int arg6, int arg7, int arg8);
extern void 	timexClear (void);
extern void 	timexFunc (int i, FUNCPTR func, int arg1, int arg2, int arg3,
			   int arg4, int arg5, int arg6, int arg7, int arg8);
extern void 	timexHelp (void);
extern void 	timexInit (void);
extern void 	timexN (FUNCPTR func, int arg1, int arg2, int arg3, int arg4,
			int arg5, int arg6, int arg7, int arg8);
extern void 	timexPost (int i, FUNCPTR func, int arg1, int arg2, int arg3,
			   int arg4, int arg5, int arg6, int arg7, int arg8);
extern void 	timexPre (int i, FUNCPTR func, int arg1, int arg2, int arg3,
			  int arg4, int arg5, int arg6, int arg7, int arg8);
extern void 	timexShow (void);


/* -----------------------------
 * unldLib.h
 * ----------------------------*/
extern STATUS unld (void *name, int options);
extern STATUS unldByNameAndPath (char *name, char *path, int options);
extern STATUS unldByGroup (UINT16 group, int options);
extern STATUS unldByModuleId (MODULE_ID moduleId, int options);
MODULE_ID reld (void * nameOrId, int options);

/* -----------------------------
 * usrLib.h
 * ----------------------------*/
extern void 	help (void);
extern void 	netHelp (void);
extern void 	bootChange (void);
extern void 	periodRun (int sec,FUNCPTR rtn,int,int,int,int,int,int,int,int);
extern int 	period (int secs, FUNCPTR func,int,int,int,int,int,int,int,int);
extern void 	repeatRun (int n, FUNCPTR func,int,int,int,int,int,int,int,int);
extern int 	repeat (int n, FUNCPTR func, int,int,int,int,int,int,int,int);
extern int 	sp (FUNCPTR func, int,int,int,int,int,int,int,int,int);
extern int 	taskIdFigure (int taskNameOrId);
extern void 	checkStack (int taskNameOrId);
extern void 	i (int taskNameOrId);
extern void 	ts (int taskNameOrId);
extern void 	tr (int taskNameOrId);
extern void 	td (int taskNameOrId);
extern void 	ti (int taskNameOrId);
extern void 	version (void);
extern void 	m (void *adrs, int width);
extern void 	d (void *adrs, int nwords, int width);
extern STATUS 	cd (char *name);
extern void 	pwd (void);
extern STATUS 	copy (char *in, char *out);
extern STATUS 	copyStreams (int inFd, int outFd);
extern STATUS 	diskFormat (char *devName);
extern STATUS 	diskInit (char *devName);
extern STATUS 	squeeze (char *devName);
extern MODULE_ID ld (int syms, BOOL noAbort, char *name);
extern STATUS 	ls (char *dirName, BOOL doLong);
extern STATUS 	ll (char *dirName);
extern STATUS 	lsOld (char *dirName);
extern STATUS 	rm (char *fileName);
extern void 	devs (void);
extern void 	lkup (char *substr);
extern void 	lkAddr (unsigned int addr);
extern STATUS 	mRegs (char *regName, int taskNameOrId);
extern void 	printErrno (int errNo);
extern void 	printLogo (void);
extern void 	logout (void);
extern void 	h (int size);
extern int 	pc (int task);
extern void 	show (int objId, int level);
extern STATUS	spyClkStart (int intsPerSec);
extern void	spyClkStop (void);
extern void	spy (int freq, int ticksPerSec);
extern void	spyStop (void);
extern void	spyHelp (void);
extern void	spyReport (void);
extern void	spyTask (int freq);

/* --------------------------------------------------
 *  vxLib.h
 * --------------------------------------------------*/
extern STATUS 	sysMemProbe (char * adrs);
extern STATUS 	vxMemProbe (char * adrs, int mode, int length, char * pVal);
extern BOOL 	vxTas (void * address);

/* -----------------------------
 * wdLib.h
 * ----------------------------*/
extern STATUS 	wdLibInit (void);
extern WDOG_ID 	wdCreate (void);
extern STATUS 	wdDelete (WDOG_ID wdId);
extern STATUS 	wdStart (WDOG_ID wdId, int delay, FUNCPTR pRoutine,
			 int parameter);
extern STATUS 	wdCancel (WDOG_ID wdId);
extern void 	wdShowInit (void);
extern STATUS 	wdShow (WDOG_ID wdId);

/* -----------------------------
 * wvLib.h
 * ----------------------------*/
extern STATUS wvEvtLogEnable (int category);
extern STATUS wvEvtLogDisable (void);
extern void   wvOn (int category);
extern void   wvOff (void);
extern void   wvEvtLogStop (void);
extern void   wvEvtTaskInit (int stackSize, int priority);
extern void * wvInstInit (char * buffer, size_t bufferSize, int option);
extern void   wvLibInit (void);
extern STATUS wvObjInstModeSet (int mode);
extern STATUS wvObjInst (int objType, void * objId, BOOL evtLoggingOn);
extern STATUS wvSigInst (int mode);
extern STATUS wvHostInfoInit (char * ipAddress, unsigned int port);
extern STATUS wvServerInit (int serverStackSize, int serverPriority);


#endif // ===================== wrapping mode 

// define library time stamp
#ifndef VxWorks_CUSTOM_STAMP    
# define VxWorks_CUSTOM_STAMP &vStamp_libRuntimeVxWorks[15]
#endif

#define VxWorks_CUSTOM_INIT  customInit(interp)
// Force init of Internal jWrap submodule
LOCAL int customInit (Tcl_Interp *interp)
{ 
  // Check jWrap as been correctelly inited
  if (Tornado_Init (interp) != TCL_OK) {
     jWrapPanic (interp,"VxWorks jWrap Custom Init failled\n");
  }

  return TCL_OK;
} // end localInit

#ifndef JWRAP
#include "libRuntimeTornado.h"
#include "libRuntimeVxWorks.i"
#endif
