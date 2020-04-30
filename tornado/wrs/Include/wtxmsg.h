/* wtxmsg.h - WTX message definition */

/* Copyright 1984-1996 Wind River Systems, Inc. */

/*
modification history
--------------------
02l,06dec96,dgp  doc: correct spelling
02k,30sep96,elp  put in share/, added WTX_OBJ_MODULE_UNDEF_SYM_ADD (SPR# 6775).
02j,17jun96,p_m	  changed flags type in WTX_MSG_OPEN_DESC (SPR# 4941).
02i,10jun96,elp	  re-installed WTX_MSG_SYM_TBL_INFO type to prevent
		  compatibility problems.
02h,20may96,elp	  added WTX_SYM_TBL_INFO type (SPR# 6502).
02g,25oct95,p_m   added WTX_AGENT_MODE_GET service (SPR# 5231) and 
		  WTX_DIRECT_CALL.
02f,17jul95,p_m   cleaned comments for manual generation.
02d,06jun95,p_m   replaced moduleNameOrId in WTX_MSG_SYM_MATCH_DESC by an union.
02c,01jun95,p_m   removed WTX_MSG_CALL_PARAM. added returnType and pReserved
		  and replaced isText by contextType in WTX_MSG_CONTEXT_DESC.
02b,30may95,p_m   completed WTX_MEM_SCAN and WTX_MEM_MOVE implementation.
02a,26may95,p_m   added match field in WTX_MSG_MEM_SCAN_DESC.
01z,23may95,p_m   made missing name changes.
01y,22may95,jcf   name revision.
01x,18may95,p_m   added WTX_VIO_CHAN_GET and WTX_VIO_CHAN_RELEASE.
                  removed DETECTION in enventpoint.
01w,16may95,p_m   added WTX_MSG_KILL_DESC and WTX_TARGET_ATTACH.
01v,10may95,pad   modified WTX_MSG_SYM_LIST and WTX_MSG_SYM_MATCH_DESC to get
		  defined or unknown symbols associated with a module.
01u,09may95,p_m   added wtxregd related messages. added Target Server version
		  in WTX_MSG_TS_INFO.
01t,04may95,s_w   Put in WTX_xxx message numbers previously in private/wtxp.h
01s,02may95,pad   changed WTX_MSG_MODULE_INFO format field from UINT32 to char *
01r,04apr95,p_m   fixed WTX_MSG_CONTEXT_DESC.stackBase comment.
01q,29mar95,p_m   added comments. removed #include "comtypes.h".
		  changed addr type in OBJ_SEGMENT to TGT_ADDR_T.
01p,28mar95,p_m   took care of comments line length for manual generation.
01o,24mar95,p_m   changed addr type in LD_M_SECTION to TGT_ADDR_T.
01n,19mar95,c_s   updated gopher structures.
01m,20mar95,f_v   fix few syntax error to work with mgtools
01l,16mar95,p_m   added WTX_MSG_VIO_FILE_LIST.
01k,15mar95,p_m   changed #include "vxWorks.h" to #include "host.h".
01j,10mar95,p_m	  made endian field a UINT32.
01i,03mar95,p_m	  replaced WRAPSTRING by char *.
		  added gopher structure for WTX.
01h,27feb95,p_m	  cleanup up WTX_MSG_MEM_SCAN_DESC.
		  added symTblId to WTX_MSG_SYM_TBL_INFO.
		  simplified WTX_WDB_SERVICE_DESC.
01g,25feb95,jcf	  extended WTX_TS_INFO.  converted spaces to tabs.
01f,20feb95,pad	  added WTX_WTX_SERVICE_DESC type. Modified type
		  WTX_MSG_SERVICE_DESC.
01e,09feb95,p_m	  renamed structures for more coherency.
		  get rid of structures shared with WDB.
		  added comments and cleanup.
01d,08feb95,p_m	  added loadFlag in WTX_MODULE_INFO.
01c,30jan95,p_m	  added additional routines and filenames in SERVICE_DESC.
		  changed rtnObjFile to svcObjFile in SERVICE_DESC.
		  added WTX_MEM_XFER; added WTX_MEM_SET_DESC;
		  added WTX_REG_WRITE;
01b,22jan95,p_m	  added TOOL_DESC field in WTX_TS_INFO.
		  replaced #include "wdb/wdbtypes.h" by #include "wdbtypes.h".
		  replaced rtnName with initRtnName in SERVICE_DESC.
01a,20jan95,p_m	  written.
*/

#ifndef __INCwtxmsgh
#define __INCwtxmsgh

#ifdef __cplusplus
extern "C" {
#endif

#ifdef HOST
#include "host.h"
#else
#include "vxWorks.h"
#endif /* HOST */
#include "wtxtypes.h"		/* basic wtx types */

/* WTX requests */

#define	WTX_TOOL_ATTACH		1
#define	WTX_TOOL_DETACH		2
#define	WTX_TS_INFO_GET		3
#define	WTX_TARGET_RESET	4
#define	WTX_TS_LOCK		5
#define	WTX_TS_UNLOCK		6
#define	WTX_TARGET_ATTACH	7

#define	WTX_CONTEXT_CREATE	10
#define	WTX_CONTEXT_KILL	11
#define	WTX_CONTEXT_SUSPEND	12
#define	WTX_CONTEXT_CONT	13
#define	WTX_CONTEXT_RESUME	14
#define	WTX_CONTEXT_STEP	15

#define	WTX_EVENTPOINT_ADD	20
#define	WTX_EVENTPOINT_DELETE	21
#define	WTX_EVENTPOINT_LIST	22

#define	WTX_MEM_CHECKSUM	30
#define	WTX_MEM_READ		31
#define	WTX_MEM_WRITE		32
#define	WTX_MEM_SET		33
#define	WTX_MEM_SCAN		34
#define	WTX_MEM_MOVE		35
#define	WTX_MEM_ALLOC		36
#define	WTX_MEM_FREE		37
#define	WTX_MEM_INFO_GET	38
#define	WTX_MEM_ALIGN		39
#define	WTX_MEM_REALLOC		40
#define	WTX_MEM_ADD_TO_POOL	41

#define	WTX_REGS_GET		50
#define	WTX_REGS_SET		51

#define	WTX_OPEN		60
#define	WTX_VIO_READ		61
#define	WTX_VIO_WRITE		62
#define	WTX_CLOSE		63
#define	WTX_VIO_CTL		64
#define	WTX_VIO_FILE_LIST	65
#define	WTX_VIO_CHAN_GET	66
#define	WTX_VIO_CHAN_RELEASE	67

#define	WTX_OBJ_MODULE_LOAD		70
#define	WTX_OBJ_MODULE_UNLOAD		71
#define	WTX_OBJ_MODULE_LIST		72
#define	WTX_OBJ_MODULE_INFO_GET		73
#define	WTX_OBJ_MODULE_FIND		74
#define WTX_OBJ_MODULE_UNDEF_SYM_ADD	75

#define	WTX_SYM_TBL_CREATE	80
#define	WTX_SYM_TBL_DELETE	81
#define	WTX_SYM_TBL_LIST_GET	82
#define	WTX_SYM_LIST_GET	83
#define	WTX_SYM_TBL_INFO_GET	84
#define	WTX_SYM_FIND		85
#define	WTX_SYM_ADD		86
#define	WTX_SYM_REMOVE		87

#define	WTX_EVENT_GET		100
#define	WTX_REGISTER_FOR_EVENT	101
#define	WTX_UN_REGIS_FOR_EVENT	102
#define	WTX_EVENT_ADD		103

#define	WTX_GOPHER_EVAL		110
#define	WTX_FUNC_CALL		111
#define	WTX_SERVICE_ADD		112
#define	WTX_WTX_SERVICE_LIST	113
#define	WTX_WDB_SERVICE_LIST	114
#define	WTX_CONSOLE_CREATE	115
#define	WTX_CONSOLE_KILL	116
#define	WTX_AGENT_MODE_SET	117
#define	WTX_AGENT_MODE_GET	118
#define	WTX_DIRECT_CALL		119

#define	WTX_OBJ_KILL		120
#define	WTX_OBJ_RESTART		121

#define WTX_REGISTER		201
#define WTX_UNREGISTER		202
#define WTX_INFO_GET		203
#define WTX_INFO_Q_GET		204

/* typedefs */

typedef enum wtx_value_t	/* simple types definitions */
    {
    V_INT8		= 0,	/* 8  bit signed integer */
    V_INT16		= 1,	/* 16 bit signed integer */
    V_INT32		= 2,	/* 32 bit signed integer */
    V_UINT8		= 3,	/* 8  bit unsigned integer */
    V_UINT16		= 4,	/* 16 bit unsigned integer */
    V_UINT32		= 5,	/* 32 bit unsigned integer */
    V_DOUBLE		= 6,	/* double floating point */
    V_BOOL32		= 7,	/* 32 bit boolean */
    V_PCHAR		= 8,	/* character pointer */
    V_PVOID		= 9,	/* void pointer */
    V_TGT_ADDR		= 10,	/* target address */
    V_TGT_ARG		= 11	/* target task argument */
    } WTX_VALUE_T;

typedef struct wtx_value		/* simple type value */
    {
    WTX_VALUE_T valueType;		/* value type */
    union
	{
	INT8		v_int8;		/* 8  bit signed value */
	INT16		v_int16;	/* 16 bit signed value */
	INT32		v_int32;	/* 32 bit signed value */
	UINT8		v_uint8;	/* 8  bit unsigned value */
	UINT16		v_uint16;	/* 16 bit unsigned value */
	UINT32		v_uint32;	/* 32 bit unsigned value */
	double		v_double;	/* double value */
	BOOL32		v_bool32;	/* 32 bit boolean value */
	char *		v_pchar;	/* string value */
	void *		v_pvoid;	/* void pointer value */
	TGT_ADDR_T	v_tgt_addr;	/* target address value */
	TGT_ARG_T	v_tgt_arg;	/* target task arg. value */
	} value_u;
    } WTX_VALUE;

typedef struct wtx_msg_result		/* simple request result */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_VALUE		val;		/* result value of call */
    } WTX_MSG_RESULT;

typedef struct wtx_msg_param		/* simple request parameter */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_VALUE		param;		/* param value of call */
    } WTX_MSG_PARAM;

typedef struct wtx_mem_region		/* memory region desc. */
    {
    TGT_ADDR_T		baseAddr;	/* mem. region base address */
    UINT32		size;		/* mem. region size */
    UINT32		attribute;	/* mem. region attributes */
    } WTX_MEM_REGION;

typedef struct wtx_rt_info		/* target runtime info. */	
    {
    UINT32		rtType;		/* runtime type */
    char *		rtVersion;	/* run time version */
    UINT32		cpuType;	/* target processor type */
    BOOL32		hasFpp;		/* floating point unit avail. */
    BOOL32		hasWriteProtect;/* text write protect avail. */
    UINT32		pageSize;	/* size of a page */
    UINT32		endian;		/* endianness (LITTLE or BIG) */
    char *		bspName;	/* board support package name */
    char *		bootline;	/* boot file name */
    TGT_ADDR_T		memBase;	/* target main mem. base addr. */
    UINT32		memSize;	/* target main mem. size */
    UINT32		numRegions;	/* number of mem. regions */
    WTX_MEM_REGION *	memRegion;	/* mem. region descriptor(s) */
    TGT_ADDR_T		hostPoolBase;	/* tgtsvr mem. pool */
    UINT32		hostPoolSize;	/* tgtsvr mem. pool size */
    } WTX_RT_INFO;

typedef struct wtx_agent_info		/* target agent information */
    {
    char *		agentVersion;	/* WDB agent version */
    UINT32		mtu;		/* max. transfer size (bytes) */
    UINT32		mode;		/* available agent modes */
    } WTX_AGENT_INFO;

typedef struct wtx_tgt_info		/* target information */
    {
    WTX_AGENT_INFO	agentInfo;	/* info on the agent */
    WTX_RT_INFO		rtInfo;		/* info on the run time system */
    } WTX_TGT_INFO;

typedef struct wtx_tgt_link_desc 	/* link descriptor */
    {
    char *		name;		/* target/host link name */
    UINT32		type;		/* target/host link type */
    UINT32		speed;		/* target/host link speed */
    } WTX_TGT_LINK_DESC;

typedef struct wtx_tool_desc		/* tool descriptor */
    {
    UINT32		id;		/* unique tool identifier */
    char *		toolName;	/* tool name */
    char *		toolArgv;	/* tool argv parameters */
    char *		toolVersion;	/* tool version */
    char *		userName;	/* user name */
    void *		pReserved;	/* reserved */
    struct wtx_tool_desc * next;	/* ptr to next tool desc. */
    } WTX_TOOL_DESC;

typedef WTX_TOOL_DESC * TOOL_ID;

typedef struct wtx_msg_ts_info		/* TS information message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_TGT_LINK_DESC	tgtLinkDesc;	/* Target link descriptor */
    WTX_TGT_INFO	tgtInfo;	/* info obtained from Target */
    WTX_TOOL_DESC *	pWtxToolDesc;	/* info about attached Tools */
    char *		version;	/* Target Server version */
    char *		userName;	/* target server user name */
    char *		startTime;	/* target server start time */
    char *		accessTime;	/* target server access time */
    char *		lockMsg;	/* lock/authorization message */
    void *		pReserved;	/* reserved */
    } WTX_MSG_TS_INFO;

typedef struct wtx_msg_ts_lock		/* lock message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    UINT32		lockType;	/* lock type to use */
    } WTX_MSG_TS_LOCK;

typedef struct wtx_msg_ts_unlock	/* unlock message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    BOOL32		force;		/* force unlock type to use */
    } WTX_MSG_TS_UNLOCK;

typedef struct wtx_msg_tool_desc 	/* tool desc. message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_TOOL_DESC	wtxToolDesc;	/* tool descriptor */
    } WTX_MSG_TOOL_DESC;

typedef struct wtx_msg_tool_id		/* tool identifier message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */
    } WTX_MSG_TOOL_ID;

typedef struct wtx_msg_kill_desc	/* kill descriptor message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    UINT32		request;	/* object kill flag */
    WTX_VALUE		arg;		/* object kill additional arg */
    } WTX_MSG_KILL_DESC;

typedef struct wtx_symbol		/* symbol desc. */
    {
    UINT32		status;		/* ret. val. for FIND request */
    UINT32		symTblId;	/* Symbol table id */ 
    char *		name;		/* Symbol name */	
    BOOL32		exactName;	/* FALSE if _name is OK */
    TGT_ADDR_T		value;		/* Sym. value */	
    UINT8		type;		/* Sym. type */	
    UINT8		typeMask;	/* Sym. type mask for lookup */	
    UINT16		group;		/* Sym. group */
    char *		moduleName;	/* module name */
    void *		pReserved;	/* reserved */
    struct wtx_symbol * next;		/* ptr to next symbol in list */
    } WTX_SYMBOL;

typedef struct wtx_msg_symbol_desc	/* symbol message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_SYMBOL		symbol;		/* symbol */
    } WTX_MSG_SYMBOL_DESC;

typedef struct wtx_sym_list		/* symbol list */
    {
    WTX_SYMBOL *	pSymbol;	/* start of symbol list */
    } WTX_SYM_LIST;

typedef struct wtx_msg_sym_list		/* symbol list message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_SYM_LIST 	symList;	/* symbol list */
    BOOL32              moreToCome;     /* TRUE if symbols are remaining */
    } WTX_MSG_SYM_LIST;

typedef struct wtx_msg_open_desc	/* file opening desc. */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    char *		filename;	/* filename */
    WTX_OPEN_FLAG	flags;		/* unix style open flags */
    INT32		mode;		/* unix style mode */
    INT32		channel;	/* channel id for redirection */
    } WTX_MSG_OPEN_DESC;

typedef struct wtx_msg_vio_ctl_desc	/* VIO control descriptor */
    {
    WTX_CORE		wtxCore; 	/* WTX message core */

    INT32		channel;	/* VIO channel number */
    UINT32		request;	/* control operation */
    UINT32		arg;		/* control argument */
    } WTX_MSG_VIO_CTL_DESC;

typedef struct wtx_msg_vio_copy_desc	/* virtual I/O data */
    {
    WTX_CORE		wtxCore; 	/* WTX message core */

    UINT32		channel;	/* virtual I/O channel */
    UINT32		maxBytes;	/* maximum bytes to transfer */
    void *		baseAddr;	/* base address of data */
    } WTX_MSG_VIO_COPY_DESC;

typedef struct wtx_vio_file_desc	/* virtual file descriptor */
    {
    char *	name;		/* file or device name */
    INT32	fd;		/* file descriptor */
    INT32	channel;	/* channel for redirection */
    INT32	fp;		/* file pointer for streams */
    INT32	type;		/* file type */
    INT32	mode;		/* open mode (O_RDONLY, O_WRONLY etc) */
    INT32	status;		/* open or closed */
    INT32	addlInfo;	/* additional info. (eg: process id) */
    struct wtx_vio_file_desc *	next; /* ptr to next desc. for list */
    } WTX_VIO_FILE_DESC;

typedef struct wtx_msg_vio_file_list	/* VIO files list message */
    {
    WTX_CORE		wtxCore; 	/* WTX message core */

    WTX_VIO_FILE_DESC * pVioFileList;	/* VIO file list */
    } WTX_MSG_VIO_FILE_LIST;

typedef struct ld_m_section		/* object module section desc. */
    {
    UINT32		flags;		/* SEC_LOAD, etc. */
    TGT_ADDR_T		addr;	  	/* section address */
    UINT32		length;		/* section length */
    } LD_M_SECTION;

typedef struct wtx_msg_ld_m_file_desc	/* object module file desc. */ 
    {
    WTX_CORE	   	wtxCore;	/* WTX message core */

    char *	   	filename;	/* object file name */
    INT32	   	loadFlag;	/* behavior control flags */
    UINT32	  	moduleId;	/* module identifier */
    UINT32	   	nSections;	/* number of sections */
    LD_M_SECTION * 	section;	/* section description */
    WTX_SYM_LIST   	undefSymList;	/* list of undefined symbols */
    } WTX_MSG_LD_M_FILE_DESC;

typedef struct wtx_msg_module_list	/* object module list */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    UINT32		numObjMod; 	/* number of module in list */
    UINT32 *	 	modIdList; 	/* list of object module id */
    } WTX_MSG_MODULE_LIST;

typedef struct obj_segment		/* object module segment */
    {
    UINT32		flags;		/* segment flags */
    TGT_ADDR_T		addr;		/* segment address */
    UINT32		length;		/* segment length */
    UINT32		reserved1;	/* reserved */
    UINT32		reserved2;	/* reserved */
    } OBJ_SEGMENT;

typedef struct wtx_msg_module_info	/* object module information */
    {
    WTX_CORE	  	wtxCore;	/* WTX message core */

    UINT32	  	moduleId;	/* module Id */
    char *	  	moduleName;	/* module name */
    char *	  	format;		/* object file format */
    UINT32	  	group;		/* group number */
    int		  	loadFlag;	/* flags used to load mod. */
    UINT32	  	nSegments;	/* number of segments */
    OBJ_SEGMENT *	segment;	/* segment description */
    void *	  	pReserved;	/* reserved */
    } WTX_MSG_MODULE_INFO;

typedef struct wtx_msg_mod_name_or_id	/* module name or identifier */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    UINT32		moduleId;	/* module Id */
    char *		filename;	/* module file name */
    } WTX_MSG_MOD_NAME_OR_ID;

typedef struct wtx_sym_tbl_info
    {
    UINT32		symTblId;	/* symbol table identifier */
    UINT32		symNum;		/* number of symbols */
    BOOL32		sameNameOk;	/* name clash policy */
    } WTX_SYM_TBL_INFO;

typedef struct wtx_msg_sym_tbl_info	/* symbol table information */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    UINT32		symTblId;	/* symbol table identifier */
    UINT32		symNum;		/* number of symbols */
    BOOL32		sameNameOk;	/* name clash policy */
    } WTX_MSG_SYM_TBL_INFO;

typedef struct wtx_msg_sym_match_desc	/* symbol lookup descriptor */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    UINT32		symTblId;	/* symbol table to look at */
    BOOL32		matchString;	/* match string if TRUE, look */
					/* around adrs if FALSE */
    TGT_ADDR_T		adrs;		/* addr. around which to look */
    char *		stringToMatch;	/* substring to match */

    BOOL32		byModuleName;	/* TRUE if module name is given */
    union
	{
	UINT32		moduleId;	/* module identifier */
	char *		moduleName;	/* or module name */
	} module; 	

    BOOL32              listUnknownSym; /* get unknown symbols if TRUE */
    BOOL32              giveMeNext;     /* TRUE for a follow-up req */
    } WTX_MSG_SYM_MATCH_DESC;

typedef struct wtx_event_desc		/* WTX event desc. */
    {
    char *		event;		/* event descriptor */
    INT32		addlDataLen;	/* additional data length */
    char *		addlData;	/* additional data (VIO) */
    } WTX_EVENT_DESC;

typedef struct wtx_msg_event_desc  	/* event message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_EVENT_DESC	eventDesc;	/* event descriptor */
    } WTX_MSG_EVENT_DESC;

typedef struct wtx_msg_event_reg_desc	/* WTX event register desc. */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    char *		evtRegExp;	/* register event reg. expr. */
    } WTX_MSG_EVENT_REG_DESC;

typedef struct wtx_wdb_service_desc	/* WDB service descriptor */
    {
    UINT32		rpcNum;		/* RPC service number */
    char *		name;		/* service name */
    char *		svcObjFile;	/* module for new service */ 
    char *		initRtnName;	/* svc init. routine name */
    } WTX_WDB_SERVICE_DESC;

typedef struct wtx_wtx_service_desc	/* WTX service descriptor */
    {
    char *		svcObjFile;	/* xdr/service routines file */
    char *		svcProcName;	/* service procedure name */
    char *		inProcName;	/* input xdr procedure name */
    char *		outProcName;	/* output xdr procedure name */
    } WTX_WTX_SERVICE_DESC;

typedef struct wtx_msg_service_desc	/* protocol service desc. */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_WTX_SERVICE_DESC *pWtxServiceDesc; /* WTX service */
    WTX_WDB_SERVICE_DESC *pWdbServiceDesc; /* WDB service */
    } WTX_MSG_SERVICE_DESC;

typedef struct wtx_msg_service_list	/* protocol service list */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    UINT32		nServices;	/* num. of services in list */
    WTX_WDB_SERVICE_DESC *serviceDesc;	/* services list */
    } WTX_MSG_SERVICE_LIST;

typedef struct wtx_console_desc /* WTX Virtual console descriptor */
    {
    INT32		fdIn;		/* stdin for redirection */
    INT32		fdOut;		/* stdout for redirection */
    INT32		pid;		/* process identifier */
    char *		name;		/* console name */
    char *		display;	/* display name eg: host:0 */
    void *		pReserved;	/* reserved */
    } WTX_CONSOLE_DESC;

typedef struct wtx_msg_console_desc	/* WTX Virtual console desc. */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_CONSOLE_DESC	wtxConsDesc;	/* console desc */
    } WTX_MSG_CONSOLE_DESC;

typedef struct wtx_msg_mem_info	 	/* memory information */
    {
    WTX_CORE	wtxCore;		/* WTX message core */

    UINT32 	curBytesFree;		/* number of free bytes */
    UINT32 	curBytesAllocated;	/* cur. # of bytes alloc. */
    UINT32 	cumBytesAllocated;	/* cum. # of bytes alloc. */
    UINT32 	curBlocksFree;		/* cur. # of free blocks */
    UINT32 	curBlocksAlloc;		/* cur. # of blocks alloc. */
    UINT32 	cumBlocksAlloc;		/* cum. # of blocks alloc. */
    UINT32 	avgFreeBlockSize;	/* average free blocks size */
    UINT32 	avgAllocBlockSize;	/* average alloc. blocks size */
    UINT32 	cumAvgAllocBlockSize;	/* cum. avg alloc. block size */
    UINT32 	biggestBlockSize;	/* size of biggest block */
    void * 	pReserved;		/* reserved */
    } WTX_MSG_MEM_INFO;

typedef struct wtx_mem_xfer		/* memory transfer */
    {
    UINT32		numBytes;	/* num. of bytes to transfer */
    TGT_ADDR_T		destination;	/* destination address */
    char *		source;		/* source address */
    } WTX_MEM_XFER;

typedef struct wtx_msg_mem_xfer_desc	/* memory transfer message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_MEM_XFER	memXfer;	/* mem. transfer desc. */
    } WTX_MSG_MEM_XFER_DESC;

typedef struct wtx_event		/* Target event */
    {
    WTX_EVENT_TYPE 	eventType;	/* type of event */
    TGT_ARG_T	   	eventArg;	/* event type dependent argument */
    } WTX_EVENT;

typedef struct wtx_context		/* context desc. */
    {
    WTX_CONTEXT_TYPE	contextType;	/* type of context */
    WTX_CONTEXT_ID_T	contextId;	/* context ID */
    } WTX_CONTEXT;

typedef struct wtx_action		/* action desc. */
    {
    WTX_ACTION_TYPE	actionType;	/* action type to perform */
    UINT32		actionArg;	/* action dependent argument */
    TGT_ADDR_T		callRtn;	/* function to ACTION_CALL */
    TGT_ARG_T		callArg;	/* function argument */
    } WTX_ACTION;

typedef struct wtx_msg_context		/* context message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_CONTEXT_TYPE	contextType;	/* type of context */
    WTX_CONTEXT_ID_T	contextId;	/* context ID */
    } WTX_MSG_CONTEXT;

typedef struct wtx_evtpt		/* eventpoint desc. */
    {
    WTX_EVENT		event;		/* event to detect */
    WTX_CONTEXT		context;	/* context descriptor */
    WTX_ACTION		action;		/* action to perform */
    } WTX_EVTPT;

typedef struct wtx_msg_evtpt_desc	/* eventpoint message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_EVTPT		wtxEvtpt;	/* eventpoint */
    } WTX_MSG_EVTPT_DESC;

typedef struct wtx_msg_evtpt_list  	/* eventpoint list message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    UINT32		nEvtpt;		/* num. eventpoint in list */
    WTX_EVTPT *		pEvtpt;		/* eventpoint list */
    } WTX_MSG_EVTPT_LIST;

typedef struct wtx_msg_reg_write	/* register(s) to set */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_REG_SET_TYPE 	regSetType;	/* type of register set */
    WTX_CONTEXT	 	context;	/* associated context */
    WTX_MEM_XFER 	memXfer;	/* new value of register(s) */
    } WTX_MSG_REG_WRITE;
		  
typedef struct WTX_MSG_REG_READ		/* register(s) to get */
    {
    WTX_CORE	    	wtxCore;	/* WTX message core */

    WTX_REG_SET_TYPE   	regSetType;	/* type of register set */
    WTX_CONTEXT	    	context;	/* associated context */
    WTX_MEM_REGION  	memRegion;	/* register block subregion */
    } WTX_MSG_REG_READ;

typedef struct wtx_msg_mem_block_desc	/* target memory block */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    TGT_ADDR_T		startAddr;	/* blocks starts from here */
    UINT32		numBytes;	/* number of bytes in block */
    } WTX_MSG_MEM_BLOCK_DESC;

typedef struct wtx_msg_mem_read_desc	/* target memory read desc. */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    TGT_ADDR_T		source;		/* source mem. address */
    UINT32		destination;	/* destination mem. address */
    UINT32		numBytes;	/* number of bytes to read */
    } WTX_MSG_MEM_READ_DESC;

typedef struct wtx_msg_mem_copy_desc	/* target memory copy desc. */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    UINT32		source;		/* encode from here */
    TGT_ADDR_T		destination;	/* decode to here */
    UINT32		numBytes;	/* bytes to copy/bytes copied */
    } WTX_MSG_MEM_COPY_DESC;

typedef struct wtx_msg_mem_scan_desc	/* target memory scan desc. */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    BOOL32		match;		/* TRUE for matching pattern */
    TGT_ADDR_T		startAddr;	/* start addr. for scanning */
    TGT_ADDR_T		endAddr;	/* end addr. for scanning */
    UINT32		numBytes;	/* number of bytes in pattern */
    void *		pattern;	/* byte pattern to look for */
    } WTX_MSG_MEM_SCAN_DESC;

typedef struct wtx_msg_mem_move_desc	/* target memory move desc. */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    TGT_ADDR_T		source;		/* copy from here */
    TGT_ADDR_T		destination;	/* to there */
    UINT32		numBytes;	/* number of bytes to copy */
    } WTX_MSG_MEM_MOVE_DESC;

typedef struct wtx_msg_mem_set_desc	/* memory setting desc. */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    UINT32		value;		/* value to set */
    UINT8		width;		/* value width 1, 2 or 4 bytes */
    TGT_ADDR_T		startAddr;	/* set from here */
    UINT32		numItems;	/* number of items to set */
    } WTX_MSG_MEM_SET_DESC;

typedef struct wtx_msg_context_desc	/* context creation desc. */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_CONTEXT_TYPE	contextType;	/* type of context */
    WTX_RETURN_TYPE	returnType;	/* int or double */
    char *		name;		/* task name */
    UINT32		priority;	/* task priority */
    UINT32		options;	/* task options */
    TGT_ADDR_T		stackBase;	/* base of stack */
    UINT32		stackSize;	/* stack size */
    TGT_ADDR_T		entry;		/* context entry point */
    INT32		redirIn;	/* redir. in file or NULL */
    INT32		redirOut;	/* redir. out file or NULL */
    TGT_ARG_T		args[WTX_MAX_ARG_CNT];	/* arguments */
    void * 		pReserved;	/* reserved */
    } WTX_MSG_CONTEXT_DESC;

typedef struct wtx_msg_context_step_desc /* single step desc. */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_CONTEXT	 	context;	/* context to step */
    TGT_ADDR_T		startAddr;	/* lower bound of step range */
    TGT_ADDR_T		endAddr;	/* upper bound of step range */
    } WTX_MSG_CONTEXT_STEP_DESC;

typedef struct wtx_gopher_tape		/* gopher tape */
    {
    UINT16	len;			/* length of tape */
    char *	data;			/* tape data */
    } WTX_GOPHER_TAPE;

typedef struct WTX_MSG_GOPHER_TAPE 	/* gopher tape message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_GOPHER_TAPE	tape;		/* gopher tape */
    } WTX_MSG_GOPHER_TAPE;

typedef struct wtx_msg_wtxregd_pattern	/* wtxregd pattern */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    char *		name;		/* pattern to match wpwrName */
    char *		type;		/* pattern to match wpwrType */
    char *		key;		/* pattern to match wpwrKey */
    } WTX_MSG_WTXREGD_PATTERN;

typedef struct wtx_svr_desc		/* server descriptor */
    {
    char *		wpwrName;	/* name of wpwr service */
    char *		wpwrType;	/* type of service */
    char *		wpwrKey;	/* unique service key */
    } WTX_SVR_DESC;

typedef struct wtx_msg_svr_desc		/* server descriptor message */
    {
    WTX_CORE		wtxCore;	/* WTX message core */

    WTX_SVR_DESC	wtxSvrDesc;	/* Server Descriptor */
    } WTX_MSG_SVR_DESC;

typedef struct wtx_svr_desc_q		/* server descriptor queue */
    {
    WTX_SVR_DESC	    wtxSvrDesc;	/* Server Descriptor */
    struct wtx_svr_desc_q * pNext;	/* next descriptor */
    } WTX_SVR_DESC_Q;

typedef struct wtx_msg_svr_desc_q	/* server descriptor queue message */
    {
    WTX_CORE		  wtxCore;	/* WTX message core */

    WTX_SVR_DESC_Q	  wtxSvrDescQ;	/* Server Descriptor Queue */
    } WTX_MSG_SVR_DESC_Q;

#ifdef __cplusplus
}
#endif

#endif	/* __INCwtxmsgh */
