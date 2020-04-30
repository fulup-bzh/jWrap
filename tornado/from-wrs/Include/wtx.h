/* wtx.h - wtx protocol header file */

/* Copyright 1984-1996 Wind River Systems, Inc. */

/*
modification history
--------------------
02s,30sep96,elp  put in share/, added wtxObjModuleUndefSymAdd(),
		 wtxSymAddWithGroup() (SPR# 6775).
02r,27sep96,sjw  correct prototype for wtxTsVersionGet, was wtsTsVersionGet
02q,18sep96,dgp  doc: change spelling of alignement to alignment for API Guide
		 in wtxMemAlign
02p,05sep96,elp	 changed val in wtxMemSet() from UINT8 to UINT32 (SPR# 6984).
02o,02sep96,jmp  added wtxToolIdGet() prototypes,
		 added WTX RPC service number argument to wtxServiceAdd().
02n,30aug96,elp	 changed wpwrVersionGet() into wtxTsVersionGet().
02m,17jun96,p_m	 changed type of flags parameter in wtxFileOpen() (SPR# 4941).
02l,30may96,elp	 added wtxToolNameGet(), wpwrVersionGet(), wtxServiceAdd() and
		 wtxSymTblInfoGet() prototypes (SPR# 6502).
02k,09nov95,p_m  removed un-necessary version defines.
02h,03nov95,jmp  added wtxErrSet() prototype.
02g,25oct95,p_m  added wtxAgentModeGet() (SPR# 5231) and wtxDirectCall().
02f,26sep95,s_w  rename wtxBreakpointDelete() to wtxEventpointDelete() 
                 (SPR 4852)
02e,05sep95,s_w	 add WTX_LD_M_FILE_DESC type and change wtxObjModuleLoad()
		 prototype (for SPR 4598)
02d,08jun95,c_s  added wtxTargetAttach().
02c,02jun95,p_m  added WTX_PROTOCOL_VERSION.
02b,01jun95,p_m  replaced isText by contextType and added returnType in 
		 WTX_CONTEXT_DESC. Changed wtxFuncCall() parameters to 
		 WTX_CONTEXT_DESC.
02a,26may95,s_w  add wtxSymListGet(), wtxSymRemove(), wtxEventpointList(),
		 wtxMemScan(), wtxVioFileList(), wtxContextExitNotifyAdd()
		 and correct the K&R prototype for wtxStrToEventType().
01z,22may95,s_w  add wtxTsRestart(), wtxVioChanGet() and wtxVioChanRelease().
01y,22may95,jcf  name revision.
01x,14may95,s_w  Removed use of WTX messages in API calls and added extra
		 target info routines. Use exchange API to make calls.
01w,15may95,c_s  added wtxEndian().
01v,04may95,s_w  major re-write for cleanup of WTX C library and addition
		 of error handling routines. Also restruction of headers.
01u,03may95,p_m  changed EVT_ to WTX_EVT_ and removed EVT_CALL_GOT_EXC
		 and EVT_BREAKPOINT.
01t,20apr95,p_m  integrated more WIN32 changes. added wtxShutdown().
01s,10apr95,p_m  moved event strings from "tsevt.h" and added EVT_TOOL_MSG.
		 added wtxMsgErrSet() that was removed by mistake.
01r,09apr95,s_w  correct prototype for wtxErrClear and wtxToolAttachHookSet
01q,09apr95,p_m  added missing prototypes and WTXC_EVT_TYPE.
01p,08apr95,p_m  completed C API.
01o,03mar95,p_m  added wtxMsgErrSet().
01n,28feb95,p_m  added WTX_MAX_SYM_CNT.
01m,23feb95,pad  changed WTX_MAX_SERVICE_CNT to 500.
01l,17feb95,p_m  changed delete to dlete in wtxExchangeInstall to please g++.
01k,08feb95,p_m  added MAX_OBJ_SEG_CNT and MAX_LD_M_SECTION_CNT taken from
		 xdrwtx.c. removed unnecessary constants.
		 made all limits prefix be WTX_MAX_.
01j,02feb95,p_m  merged all status in WTX_ERROR_T. 
01i,22jan95,jcf  added new status returns.
01h,20jan95,jcf  changed include to wtxtypes.h.
01g,20dec94,p_m  now use wtxrpc.h generated by rpcgen from wtx.x.
		 added S_wtx_AGENT_SERVICE_NOT_AVAIL.
		 added S_wtx_TARGET_NOT_ATTACHED.
01f,16nov94,p_m  added WTX_EVENT_ADD and wtxSvcInit().
		 removed S_wtx_NOT_ENOUGH_MEMORY. Changed errno numbers.
		 added S_wtx_NO_SCALABLE_AGENT and S_wtx_WIND_BASE_NOT_SET. 
01e,14nov94,p_m  changed WTX_VIO_OPEN to WTX_OPEN and WTX_VIO_CLOSE 
		 to WTX_CLOSE.  added S_wtx_INVALID_FLAGS.
01e,11nov94,p_m  changed WTX_EVAL_GOPHER to WTX_GOPHER_EVAL.
01d,27oct94,p_m  added WTX_CONTEXT_RESUME.
01c,24oct94,p_m  added WTX_FUNC_CALL_PRI.
01b,20oct94,p_m  added error codes.
01a,06oct94,p_m  written.
*/

#ifndef __INCwtxh
#define __INCwtxh	1

#ifdef __cplusplus
extern "C" {
#endif

#ifdef HOST
#include <setjmp.h>
#else
#include "vxWorks.h"
#include "setjmp.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "bootLib.h"
#endif /* HOST */

#include "wtxtypes.h"
#include "wtxmsg.h"
#include "wtxerr.h"

/* defines */

#if !defined(__STDC__) && !defined(__cplusplus) && !defined(WIN32_COMPILER)
#define const
#endif

#define WTX_TRY(hWtx) \
{\
	WTX_HANDLER_T errHandler;\
	jmp_buf jumpBuf;\
\
	wtxErrClear (hWtx);\
	errHandler = wtxErrHandlerAdd (hWtx, &wtxErrExceptionFunc, &jumpBuf);\
	if (setjmp (jumpBuf) == 0)

#define WTX_CATCH(hWtx, errCode) else if (wtxErrGet (hWtx) == errCode)
#define WTX_CATCH_ALL(hWtx) else

#define WTX_TRY_END(hWtx) \
	wtxErrHandlerRemove (hWtx, errHandler);\
}

#define WTX_THROW(hWtx, errCode) wtxErrDispatch (hWtx, errCode)

/* event type strings */

extern const char WTX_EVT_TGT_RESET[];
extern const char WTX_EVT_SYM_ADDED[];
extern const char WTX_EVT_SYM_REMOVED[];
extern const char WTX_EVT_OBJ_LOADED[];
extern const char WTX_EVT_OBJ_UNLOADED[];
extern const char WTX_EVT_CTX_START[];
extern const char WTX_EVT_CTX_EXIT[];
extern const char WTX_EVT_EXCEPTION[];
extern const char WTX_EVT_VIO_WRITE[];
extern const char WTX_EVT_TOOL_ATTACH[];
extern const char WTX_EVT_TOOL_DETACH[];
extern const char WTX_EVT_TOOL_MSG[];
extern const char WTX_EVT_TEXT_ACCESS[];
extern const char WTX_EVT_DATA_ACCESS[];
extern const char WTX_EVT_CALL_RETURN[];
extern const char WTX_EVT_UNKNOWN[];
extern const char WTX_EVT_USER[];

/* typedefs */

typedef enum wtx_endian_t
    {
    WTX_ENDIAN_BIG	= 0,
    WTX_ENDIAN_LITTLE	= 1,
    WTX_ENDIAN_UNKNOWN	= WTX_ERROR
    } WTX_ENDIAN_T;

typedef struct _wtx * HWTX;		/* WTX Handle */


#if defined(__STDC__) || defined(__cplusplus) || defined(WIN32_COMPILER)
typedef BOOL32 (*WTX_HANDLER_FUNC) (HWTX hWtx, 
				    void * pClientData, 
				    void * pCallData);
#else
typedef BOOL32 (*WTX_HANDLER_FUNC) (); 
#endif /* __STDC__ */


typedef struct _wtx_handler_t * WTX_HANDLER_T;


/* XXX - expect typedefs below to move into wtxtypes.h or wtxmsg.h */

typedef struct wtx_context_desc		/* context creation desc. */
    {
    WTX_CONTEXT_TYPE	contextType;	/* context type */
    WTX_RETURN_TYPE	returnType;	/* int or double */
    char *		name;		/* name	*/
    UINT32		priority;	/* priority */
    UINT32		options;	/* options */
    TGT_ADDR_T		stackBase;	/* base of stack */
    UINT32		stackSize;	/* stack size */
    TGT_ADDR_T		entry;		/* context entry point */
    INT32		redirIn;	/* redir. in file or NULL */
    INT32		redirOut;	/* redir. out file or NULL */
    TGT_ARG_T		args[WTX_MAX_ARG_CNT];	/* arguments */
    } WTX_CONTEXT_DESC;

typedef struct wtx_evtpt_list  	/* eventpoint list message */
    {
    UINT32		nEvtpt;		/* num. eventpoint in list */
    WTX_EVTPT *		pEvtpt;		/* eventpoint list */
    } WTX_EVTPT_LIST;

typedef struct wtx_ld_m_file_desc	/* object module file desc. */ 
    {
    char *	   	filename;	/* object file name */
    INT32	   	loadFlag;	/* behavior control flags */
    UINT32	  	moduleId;	/* module identifier */
    UINT32	   	nSections;	/* number of sections */
    LD_M_SECTION * 	section;	/* section description */
    WTX_SYM_LIST   	undefSymList;	/* list of undefined symbols */
    } WTX_LD_M_FILE_DESC;

typedef struct wtx_mem_info	 	/* memory information */
    {
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
    } WTX_MEM_INFO;

typedef struct wtx_module_info	/* object module information */
    {
    UINT32	  	moduleId;	/* module Id */
    char *	  	moduleName;	/* module name */
    char *	  	format;		/* object file format */
    UINT32	  	group;		/* group number */
    int		  	loadFlag;	/* flags used to load mod. */
    UINT32	  	nSegments;	/* number of segments */
    OBJ_SEGMENT *	segment;	/* segment description */
    void *	  	pReserved;	/* reserved */
    } WTX_MODULE_INFO;

typedef struct wtx_module_list	/* object module list */
    {
    UINT32		numObjMod; 	/* number of module in list */
    UINT32 *	 	modIdList; 	/* list of object module id */
    } WTX_MODULE_LIST;

typedef struct wtx_ts_info		/* TS information message */
    {
    WTX_TGT_LINK_DESC	tgtLinkDesc;	/* Target link descriptor */
    WTX_TGT_INFO	tgtInfo;	/* info obtained from Target */
    WTX_TOOL_DESC *	pWtxToolDesc;	/* info about attached Tools */
    char *		version;	/* Target Server version */
    char *		userName;	/* target server user name */
    char *		startTime;	/* target server start time */
    char *		accessTime;	/* target server access time */
    char *		lockMsg;	/* lock/authorization message */
    void *		pReserved;	/* reserved */
    } WTX_TS_INFO;


/* globals */

#ifndef HOST
/* externals */

extern BOOT_PARAMS	sysBootParams;
#endif /* HOST */


/* function declarations */

#if defined(__STDC__) || defined(__cplusplus) || defined(WIN32_COMPILER)

extern STATUS wtxEach (HWTX hWtx, const char * namePat, const char * typePat, 
		       const char * keyPat, FUNCPTR routine, void * arg);
extern WTX_DESC * wtxInfo (HWTX hWtx, const char * name);
extern WTX_DESC_Q * wtxInfoQ (HWTX hWtx, 
			      const char * namePat, 
			      const char * typePat, 
			      const char * keyPat);
extern STATUS	wtxInitialize (HWTX *phWtx);
extern STATUS	wtxProbe (HWTX hWtx);
extern WTX_DESC * wtxRegister (HWTX hWtx, const char * name, 
			       const char * type, const char * key);
extern STATUS	wtxTerminate (HWTX hWtx);
extern STATUS	wtxTimeoutSet (HWTX hWtx, UINT32 msec);
extern STATUS	wtxTimeoutGet (HWTX hWtx, UINT32 * pMsec);
extern STATUS 	wtxUnregister (HWTX hWtx, const char * name);

extern STATUS	wtxAgentModeSet (HWTX hWtx, WTX_AGENT_MODE_TYPE agentMode);
extern WTX_AGENT_MODE_TYPE wtxAgentModeGet (HWTX hWtx);
extern UINT32	wtxBreakpointAdd (HWTX hWtx, WTX_CONTEXT_TYPE contextType,
			          WTX_CONTEXT_ID_T contextId,
				  TGT_ADDR_T tgtAddr);
extern STATUS	wtxClientDataGet (HWTX hWtx, void ** ppClientData);
extern STATUS	wtxClientDataSet (HWTX hWtx, void * pClientData);
extern INT32	wtxConsoleCreate (HWTX hWtx, const char * name, 
				  const char * display, 
				  INT32 * fdIn, INT32 * fdOut);
extern STATUS	wtxConsoleKill (HWTX hWtx, INT32 consoleId);
extern STATUS	wtxContextCont (HWTX hWtx, WTX_CONTEXT_TYPE contextType,
				WTX_CONTEXT_ID_T contextId);
extern WTX_CONTEXT_ID_T	wtxContextCreate (HWTX hWtx, 
					  WTX_CONTEXT_DESC * pContextDesc);
extern UINT32	wtxContextExitNotifyAdd (HWTX hWTx, 
					 WTX_CONTEXT_TYPE contextType,
					 WTX_CONTEXT_ID_T);
extern STATUS	wtxContextKill (HWTX hWtx, WTX_CONTEXT_TYPE contextType,
				WTX_CONTEXT_ID_T contextId);
extern STATUS	wtxContextResume (HWTX hWtx, WTX_CONTEXT_TYPE contextType,
				  WTX_CONTEXT_ID_T contextId);
extern STATUS	wtxContextStep (HWTX hWtx, WTX_CONTEXT_TYPE contextType,
				WTX_CONTEXT_ID_T contextId, 
				TGT_ADDR_T stepStart, TGT_ADDR_T stepEnd);
extern STATUS	wtxContextSuspend (HWTX hWtx, WTX_CONTEXT_TYPE contextType,
				   WTX_CONTEXT_ID_T contextId);
extern STATUS	wtxErrClear (HWTX hWtx);
extern WTX_ERROR_T	wtxErrGet (HWTX hWtx);
extern STATUS	wtxErrSet (HWTX hWtx, UINT32 errCode);
extern const char *	wtxErrMsgGet (HWTX hWtx);
extern const char *	wtxErrToMsg (HWTX hWtx, WTX_ERROR_T errCode);
extern STATUS	wtxErrDispatch (HWTX hWtx, WTX_ERROR_T errCode);
extern BOOL32	wtxErrExceptionFunc (HWTX hWtx, void *pClientData, 
				     void *pCallData);
extern WTX_HANDLER_T	wtxErrHandlerAdd (HWTX hWtx, WTX_HANDLER_FUNC pFunc,
					  void * pClientData);
extern STATUS	wtxErrHandlerRemove (HWTX hWtx, WTX_HANDLER_T pHandler);
extern STATUS	wtxEventAdd (HWTX hWtx, const char * event, 
			     UINT32 addlDataLen, const void * pAddlData);
extern WTX_EVENT_DESC * wtxEventGet (HWTX hWtx);
extern STATUS	wtxEventpointDelete (HWTX hWtx, UINT32 evtptId);
extern WTX_EVTPT_LIST * wtxEventpointList (HWTX hWTx);
extern STATUS	wtxFileClose (HWTX hWtx, INT32 fileDescriptor);
extern INT32	wtxFileOpen (HWTX hWtx, const char * fileName, 
			     WTX_OPEN_FLAG flags, INT32 mode, INT32 channel);
extern WTX_CONTEXT_ID_T	wtxFuncCall (HWTX hWtx, 
				     WTX_CONTEXT_DESC * pContextDesc); 
extern STATUS	wtxDirectCall (HWTX hWtx, TGT_ADDR_T entry, void * pRetVal,
			       TGT_ARG_T arg0, TGT_ARG_T arg1, TGT_ARG_T arg2,
			       TGT_ARG_T arg3, TGT_ARG_T arg4, TGT_ARG_T arg5,
			       TGT_ARG_T arg6, TGT_ARG_T arg7, TGT_ARG_T arg8,
			       TGT_ARG_T arg9); 
extern WTX_GOPHER_TAPE * wtxGopherEval (HWTX hWtx, const char * inputString);
extern WTX_MEM_INFO * wtxMemInfoGet (HWTX hWtx);
extern STATUS	wtxMemAddToPool (HWTX hWtx, TGT_ADDR_T address, UINT32 size);
extern TGT_ADDR_T	wtxMemAlign (HWTX hWtx, TGT_ADDR_T alignment, 
				    UINT32 numBytes);
extern TGT_ADDR_T	wtxMemAlloc (HWTX hWtx, UINT32 numBytes);
extern UINT32	wtxMemChecksum (HWTX hWtx, TGT_ADDR_T startAddr, 
				UINT32 numBytes);
extern STATUS	wtxMemFree (HWTX hWtx, TGT_ADDR_T address);
extern STATUS	wtxMemMove (HWTX hWtx, TGT_ADDR_T srcAddr, TGT_ADDR_T destAddr,
			    UINT32 numBytes);
extern UINT32	wtxMemRead (HWTX hWtx, TGT_ADDR_T fromAddr, void * toAddr, 
			    UINT32 numBytes);
extern TGT_ADDR_T	wtxMemRealloc (HWTX hWtx, TGT_ADDR_T address, 
				       UINT32 numBytes);
extern UINT32	wtxMemSet (HWTX hWtx, TGT_ADDR_T addr, UINT32 numBytes, 
			    UINT32 val);
extern STATUS	wtxMemScan (HWTX hWTx, BOOL32 match, TGT_ADDR_T startAddr, 
			    TGT_ADDR_T endAddr, UINT32 numBytes, 
			    void * pattern, TGT_ADDR_T * pResult);
extern UINT32	wtxMemWrite (HWTX hWtx, void * fromAddr, TGT_ADDR_T toAddr, 
			     UINT32 numBytes);
extern char *	wtxObjModuleFindName (HWTX hWtx, UINT32 modId);
extern UINT32	wtxObjModuleFindId (HWTX hWtx, const char *name);
extern WTX_MODULE_INFO * wtxObjModuleInfoGet (HWTX hWtx, UINT32 modId);
extern WTX_MODULE_LIST * wtxObjModuleList (HWTX hWtx);
extern WTX_LD_M_FILE_DESC * wtxObjModuleLoad (HWTX hWtx, 
					      WTX_LD_M_FILE_DESC *pFileDesc);
extern STATUS	wtxObjModuleUnload (HWTX hWtx, UINT32 modId);
extern STATUS	wtxObjModuleUndefSymAdd (HWTX hWtx, char * symName,
					 UINT32 symGroup);
extern STATUS	wtxRegisterForEvent (HWTX hWtx, const char * regExp);
extern STATUS	wtxRegsGet (HWTX hWtx, 
			    WTX_CONTEXT_TYPE contextType,
			    WTX_CONTEXT_ID_T contextId, 
			    WTX_REG_SET_TYPE regSet, 
			    UINT32 firstByte, UINT32 numBytes,
			    void * regMemory);
extern STATUS	wtxRegsSet (HWTX hWtx, WTX_CONTEXT_TYPE contextType,
			    WTX_CONTEXT_ID_T contextId, 
			    WTX_REG_SET_TYPE regSet, UINT32 firstByte, 
			    UINT32 numBytes, void * regMemory);
extern STATUS	wtxResultFree (HWTX hWtx, void * pResult);
extern STATUS	wtxServiceAdd (HWTX hWtx, UINT32 * wtxSvcNum,
			       UINT32 wdbSvcNum, char * wdbName,
			       char * wdbObjFile, char * wdbInitRtn, 
			       char * wtxObjFile, char * wtxName,
			       char * wtxInProcName, char * wtxOutProcName);
extern TGT_ADDR_T       wtxStrToTgtAddr (HWTX hWtx, const char *);
extern INT32            wtxStrToInt32 (HWTX hWtx, const char *);
extern WTX_CONTEXT_ID_T wtxStrToContextId (HWTX hWtx, const char *);
extern WTX_CONTEXT_TYPE wtxStrToContextType (HWTX hWtx, const char *);
extern WTX_EVENT_TYPE	wtxStrToEventType (HWTX hWtx, const char *);
extern STATUS		wtxSymAdd (HWTX hWtx, const char * symName, 
				   TGT_ADDR_T symValue, UINT8 symType); 
extern STATUS		wtxSymAddWithGroup (HWTX hWtx, const char * symName, 
				   	    TGT_ADDR_T symValue,
					    UINT8 symType, UINT16 group); 
extern WTX_SYMBOL *	wtxSymFind (HWTX hWtx, const char *symName, 
				    TGT_ADDR_T symValue, BOOL32 exactName, 
				    UINT8 symType, UINT8 typeMask);
extern WTX_SYM_LIST *	wtxSymListGet (HWTX hWtx, const char *string,
				       const char *moduleNameOrId,
				       TGT_ADDR_T value,  BOOL32 listUnknown);
extern STATUS		wtxSymRemove (HWTX hWtx, const char *symName, 
				      UINT8 symType);
extern WTX_SYM_TBL_INFO * wtxSymTblInfoGet (HWTX hWtx);
extern UINT32		wtxTargetRtTypeGet (HWTX hWtx);
extern const char *	wtxTargetRtVersionGet (HWTX hWtx);
extern UINT32		wtxTargetCpuTypeGet (HWTX hWtx);
extern BOOL32		wtxTargetHasFppGet (HWTX hWtx);
extern WTX_ENDIAN_T	wtxTargetEndianGet (HWTX hWtx);
extern const char *	wtxTargetBootlineGet (HWTX hWtx);
extern const char *	wtxTargetBspNameGet (HWTX hWtx);
extern STATUS	wtxTargetReset (HWTX hWtx);
extern STATUS	wtxTargetAttach (HWTX hWtx);
extern STATUS	wtxToolAttach (HWTX hWtx, const char * targetName, 
				const char * toolName);
extern STATUS	wtxToolAttachHookSet (HWTX hWtx, FUNCPTR hookFunc);
extern char *	wtxToolNameGet (HWTX hWtx);
extern BOOL32	wtxToolConnected (HWTX hWtx);
extern STATUS	wtxToolDetach (HWTX hWtx);
extern UINT32	wtxToolIdGet (HWTX hWtx);
extern WTX_TS_INFO * wtxTsInfoGet (HWTX hWtx);
extern STATUS	wtxTsKill (HWTX hWtx);
extern STATUS	wtxTsLock (HWTX hWtx);
extern const char *	wtxTsNameGet (HWTX hWtx);
extern STATUS	wtxTsRestart (HWTX hWtx);
extern STATUS	wtxTsUnlock (HWTX hWtx);
extern BOOL32	wtxVerify (HWTX hWtx);
extern INT32	wtxVioChanGet (HWTX hWtx);
extern STATUS	wtxVioChanRelease (HWTX hWtx, INT32 channel);
extern STATUS	wtxVioCtl (HWTX hWtx, INT32 channel, 
			   UINT32 request, UINT32 arg);
extern WTX_VIO_FILE_DESC ** wtxVioFileList (HWTX hWtx);
extern UINT32	wtxVioWrite (HWTX hWtx, INT32 channel, void * pData, 
			     UINT32 numBytes);
extern char *	wtxTsVersionGet (HWTX hWtx);

#else	/* __STDC__ */

extern STATUS wtxEach ();
extern WTX_DESC * wtxInfo ();
extern WTX_DESC_Q * wtxInfoQ ();
extern STATUS	wtxInitialize ();
extern STATUS	wtxProbe ();
extern WTX_DESC * wtxRegister ();
extern STATUS	wtxTerminate ();
extern STATUS	wtxTimeoutSet ();
extern STATUS	wtxTimeoutGet ();
extern STATUS 	wtxUnregister ();

extern STATUS	wtxAgentModeSet ();
extern WTX_AGENT_MODE_TYPE wtxAgentModeGet ();
extern UINT32	wtxBreakpointAdd ();
extern STATUS	wtxClientDataGet ();
extern STATUS	wtxClientDataSet ();
extern INT32	wtxConsoleCreate ();
extern STATUS	wtxConsoleKill ();
extern WTX_CONTEXT_ID_T	wtxContextCreate ();
extern UINT32	wtxContextExitNotifyAdd ();
extern STATUS	wtxContextKill ();
extern STATUS	wtxContextCont ();
extern STATUS	wtxContextResume ();
extern STATUS	wtxContextStep ();
extern STATUS	wtxContextSuspend ();
extern STATUS	wtxErrClear ();
extern WTX_ERROR_T	wtxErrGet ();
extern STATUS	wtxErrSet ();
extern const char *	wtxErrMsgGet ();
extern const char *	wtxErrToMsg ();
extern STATUS	wtxErrDispatch ();
extern BOOL32	wtxErrExceptionFunc ();
extern WTX_HANDLER_T	wtxErrHandlerAdd ();
extern STATUS	wtxErrHandlerRemove ();
extern STATUS	wtxEventAdd ();
extern WTX_EVENT_DESC * wtxEventGet ();
extern STATUS	wtxEventpointDelete ();
extern WTX_EVTPT_LIST * wtxEventpointList ();
extern STATUS	wtxFileClose ();
extern INT32	wtxFileOpen ();
extern WTX_CONTEXT_ID_T	wtxFuncCall ();
extern UINT32	wtxDirectCall ();
extern WTX_GOPHER_TAPE * wtxGopherEval ();
extern WTX_MEM_INFO * wtxMemInfoGet ();
extern STATUS	wtxMemAddToPool ();
extern TGT_ADDR_T	wtxMemAlign ();
extern TGT_ADDR_T	wtxMemAlloc ();
extern UINT32	wtxMemChecksum ();
extern STATUS	wtxMemFree ();
extern STATUS	wtxMemMove ();
extern UINT32	wtxMemRead ();
extern TGT_ADDR_T	wtxMemRealloc ();
extern UINT32	wtxMemSet ();
extern STATUS	wtxMemScan ();
extern UINT32	wtxMemWrite ();
extern char *	wtxObjModuleFindName ();
extern UINT32	wtxObjModuleFindId ();
extern WTX_MODULE_INFO * wtxObjModuleInfoGet ();
extern WTX_MODULE_LIST * wtxObjModuleList ();
extern WTX_LD_M_FILE_DESC * wtxObjModuleLoad ();
extern STATUS	wtxObjModuleUndefSymAdd ();
extern STATUS	wtxObjModuleUnload ();
extern STATUS	wtxRegisterForEvent ();
extern STATUS	wtxRegsGet ();
extern STATUS	wtxRegsSet ();
extern STATUS	wtxResultFree ();
extern STATUS	wtxServiceAdd ();
extern TGT_ADDR_T       wtxStrToTgtAddr ();
extern INT32            wtxStrToInt32 ();
extern WTX_CONTEXT_ID_T wtxStrToContextId ();
extern WTX_CONTEXT_TYPE wtxStrToContextType ();
extern WTX_EVENT_TYPE	wtxStrToEventType ();
extern STATUS			wtxSymAdd (); 
extern STATUS			wtxSymAddWithGroup (); 
extern WTX_SYMBOL *		wtxSymFind ();
extern WTX_SYM_LIST *		wtxSymListGet ();
extern STATUS			wtxSymRemove ();
extern WTX_SYM_TBL_INFO *	wtxSymTblInfoGet ();
extern UINT32		wtxTargetRtTypeGet ();
extern const char *	wtxTargetRtVersionGet ();
extern UINT32		wtxTargetCpuTypeGet ();
extern BOOL32		wtxTargetHasFppGet ();
extern WTX_ENDIAN_T	wtxTargetEndianGet ();
extern const char *	wtxTargetBootlineGet ();
extern const char *	wtxTargetBspNameGet ();
extern STATUS	wtxTargetReset ();
extern STATUS	wtxTargetAttach ();
extern STATUS	wtxToolAttach ();
extern STATUS	wtxToolAttachHookSet ();
extern char *	wtxToolNameGet ();
extern BOOL32	wtxToolConnected ();
extern STATUS	wtxToolDetach ();
extern UINT32	wtxToolIdGet ();
extern WTX_TS_INFO * wtxTsInfoGet ();
extern STATUS	wtxTsKill ();
extern STATUS	wtxTsLock ();
extern const char *	wtxTsNameGet ();
extern STATUS	wtxTsRestart ();
extern STATUS	wtxTsUnlock ();
extern BOOL32	wtxVerify ();
extern INT32	wtxVioChanGet ();
extern STATUS	wtxVioChanRelease ();
extern STATUS	wtxVioCtl ();
extern WTX_VIO_FILE_DESC ** wtxVioFileList ();
extern UINT32	wtxVioWrite ();
extern char *	wtxTsVersionGet ();

#endif	/* __STDC__ */

#ifdef __cplusplus
}
#endif

#endif /* __INCwtxh */