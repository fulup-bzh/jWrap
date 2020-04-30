/* wtx.c - WTX C library */

/* Copyright 1984-1996 Wind River Systems, Inc. */
#include "copyright_wrs.h"

/*
modification history
--------------------
03p,06dec96,dgp  doc: correct spelling
03o,21nov96,dgp  doc: change Object-Module, correct italic and bold formatting
03n,20nov96,dgp  doc: correct WTX_THROW() to WTX_THROW
03m,18nov96,dgp  doc: final changes, wtxGopherEval, wtxErrExceptionFunc, 
		      wtxSymFind
03l,12nov96,c_s  remove use of strerror on sun4-sunos4
03k,11nov96,dgp  doc: "final" formatting for API Guide
03j,30sep96,elp  put in share, adapted to be compiled on target side
		 (added wtxSymAddWithGroup() and wtxObjModuleUndefSymAdd()).
03i,19sep96,p_m  fixed syntax error in wtxMemAlign() introduced by last
		 doc modification
03h,17sep96,dgp  doc: API Guide updates, particularly wtxGopherEval,
		 wtxObjectModuleLoad
03g,05sep96,p_m  Documented wtxToolIdGet() and wtxServiceAdd()
03f,05sep96,elp	 changed val in wtxMemSet() from UINT8 to UINT32 (SPR# 6894).
03e,02sep96,jmp  added wtxToolIdGet(),
		 added WTX RPC service number argument to wtxServiceAdd().
03d,30aug96,elp	 Changed wpwrVersionGet() into wtxTsVersionGet().
03c,26jul96,pad  Changed order of include files (AIX port).
03b,26jul96,dbt  fixed a memory leak. Added serverDescFree to clean servor
		 descriptor. 
03a,15jul96,dbt  supressed call to wtxExchangeDelete() and 
		 wtxExchangeTerminate() in exchange() in case of server
		 exchange handle (SPR #6862).
02z,09jul96,dgp  doc: API Guide changes for wtxErrExceptionFunc,wtxMemMove,
		 wtxRegisterForEvent,wtxStrToXxxx,wtxToolAttach,wtxVioWrite
02y,08jul96,dgp  doc: API Guide formatting, all functions
02x,17jun96,p_m  changed wtxFileOpen() flag type (SPR# 4941).
		 added call to wtxExchangeTerminate() in registryDisconnect()
		 to avoid memory leak.
02w,13jun96,p_m  added registryDisconnect() to complete SPR# 6697 fix.
                 now call registryDisconnect() in all calls that talk to
		 the registry.
02v,13jun96,elp  last additions doc cleanup.
02t,10jun96,elp	 fix SPR# 6502 without protocol change.
02s,07jun96,p_m  now close the registry connection when leaving wtxInfo()
		 and wtxInfoQ() since it consumes fds on the registry 
		 for nothing (SPR# 6697).
02r,20may96,elp  added wtxServiceAdd(), wtxToolNameGet(), wpwrVersionGet(),
		 wtxSymTblInfoGet() (SPR# 6502) + add correct action type to
		 wtxContextExitNotifyAdd() and wtxBreakpointAdd() (SPR# 6229).
02q,01mar96,s_w  Fix SPR 5371, wtxFuncCall() doc needs improvement
02p,17nov95,pad  Fixed leak of fds: connection with target server is closed
		 in wtxToolDetach(). Initialized firstSym.
02o,15nov95,s_w  correct documentation for wtxRegister(), result must not
		 be freed by user - SPR 5463
02n,13nov95,s_w  correct memory leak bug in wtxEach() ensure server and 
		 client info is released after successful wtxTsRestart()
		 and wtxTsKill() (SPR 5442)
02m,09nov95,wmd  add WIN32 code to retrieve user name in wtxToolAttach().
02l,31oct95,s_w  make wtxObjModuleLoad() use same timeout as other calls instead
		 of a hard coded 10 minute value (SPR 5288). Doc fix to 
		 wtxMemInfoGet() (SPR 5283)
02k,30oct95,jmp  correct bug in wtxSymRemove() that returned WTX_ERROR
		 when successful.
02j,26oct95,p_m  added wtxAgentModeGet() and wtxDirectCall().
02i,23oct95,p_m  fix SPR# 5239 wtxEventAdd() now properly calls WTX_EVENT_ADD.
02h,26sep95,s_w  change wtxBreakpointDelete() to wtxEventpointDelete()
		 (SPR 4852)
02i,05sep95,s_w  update documentation for wtxObjModuleLoad() and wtxErrToMsg()
02h,05sep95,s_w	 support loader flags on wtxObjModuleLoad (SPR 4598), check
		 for NULL pMsecs param in wtxTimeoutGet (SPR 4596), implement
		 wtxErrToMsg() (SPR 4526), set value type when passing module
		 id in wtxObjModuleUnload (SPR 4832).
02g,25jul95,s_w  documentation tweaks for SPR 4537
02f,27jun95,s_w  fixed comment for wtxEventGet() and fix wtxStrToContextType()
		 to account for new hex format of CONTEXT_TYPE in event strings.
02e,23jun95,jcf  fixed mangen problems with expand and SEE ALSO.
02d,16jun95,s_w  add a more functional implementation of wtxErrMsgGet().
02c,14jun95,s_w	 handle exchange create failure in tool attach to avoid leaving
		 WTX handle in connected state. Also free exchange handle 
		 properly when disconnecting after a fatal exchange error.
02b,08jun95,c_s  added wtxTargetAttach().
02a,07jun95,s_w  correct bug in wtxSymListGet() that prevented free of result
		 and assign moduleName parameter correctly to search message.
01z,06jun95,p_m  took care of WTX_MSG_SYM_MATCH_DESC changes in wtxSymListGet().
01y,01jun95,p_m  changed wtxFuncCall() and wtxContextCreate() according to
		 new WTX protocol spec.
01x,30may95,p_m  added Solaris-2 and HP-UX  support.
01w,30may95,p_m  completed WTX_MEM_SCAN and WTX_MEM_MOVE implementation.
01v,27may95,p_m  added match field handling in wtxMemScan().
01u,26may95,s_w  add wtxSymListGet(), wtxSymRemove(), wtxEventpointList(),
		 wtxMemScan(), wtxContextExitNotifyAdd() and wtxVioFileList().
01t,23may95,p_m  made missing name changes.
01s,22may95,s_w  update wtxTsKill for new message format and add wtxTsRestart(),
		 wtxVioChanGet() and wtxVioChanRelease(). Correct exchange() to
		 avoid converting all WTX errors to WTX_ERR_API_REQUEST_FAILED,
		 Now only do so for non-fatal exchange errors.
01r,22may95,jcf  name revision.
01q,19may95,p_m  got rid of detection data in wtxBreakpointAdd().
01p,17may95,s_w  updated to use exchange mechanism, added new functions
		 for getting target info.
01o,15may95,c_s  now caches endianness; added wtxSymAdd.
01n,09may95,p_m  used WTX_MSG_... for communication with wtxregd.
01m,20apr95,s_w  rewrite for new error handling and cleanup of code. 
		 Implement many more API calls and localize dependence on
                 RPC. See comment.
01l,03may95,p_m  changed EVT_ to WTX_EVT_.
01k,19apr95,pad  fixed returned value for wtxEventGetContextType().
01j,10apr95,p_m  changed wtxToolAttachHookSet() parameter to be 
		 void (*hookFunc)().
01i,09apr95,p_m  moved WTX_EVT_TYPE to wtx.h.
01h,09apr95,p_m  added missing clnt_freeres() calls.
01g,08apr95,p_m  added Simon's C API.
01h,29mar95,p_m  added WDB errors mapping in wtxMsgErrSet().	
01g,05mar95,jcf  added breaks to case in wtxMsgErrSet().	
01f,03mar95,p_m  added wtxMsgErrSet().	
01e,14feb95,p_m  updated to new WTX structures.
01d,23jan95,jcf  removed warning.
01c,22jan95,jcf  fixed error message.
01b,20jan95,jcf  made more portable.
01a,24dec94,jcf  written.
*/

/*
DESCRIPTION
This module implements a C-language transport-neutral interface to the 
WTX messaging protocol. 

A tool must always call wtxInitialize() to initialize a handle that is
used in all further WTX calls. The tool can then attach to a target
server using a call to wtxToolAttach(). Each WTX handle can only be
connected to one server at a time.  After a successful call of
wtxToolAttach(), the handle is considered bound to the specified target
server until a call of wtxToolDetach() is made; then 
the handle can be attached to a new target server.  When the
handle is no longer required, call wtxTerminate() to release any
internal storage used by the handle. The handle must not be used after
wtxTerminate() has been called.

.CS
#include "wtx.h"

    HWTX hWtx;

    /@ initialize WTX session handle @/

    if (wtxInitialize (&hWtx) != WTX_OK)
	return (WTX_ERROR);

    /@ attach to Target Server named "soubirou" @/

    if (wtxToolAttach (hWtx, "soubirou", "wtxApp") != WTX_OK)
	return (WTX_ERROR);

    /@ register for events we want to hear about (all events here) @/

    if (wtxRegisterForEvent (hWtx, ".*") != WTX_OK)
	{
	wtxToolDetach (hWtx);
	return (WTX_ERROR);
	}

    /@ core of the WTX application @/
		   .
		   .
		   .
		   .

    /@ detach form the Target Server @/

    wtxToolDetach (hWtx);

    /@ terminate WTX session @/

    wtxTerminate (hWtx);
.CE

Most WTX calls return either a pointer value which is NULL on error or a
STATUS value which is WTX_ERROR if an error occurs.  A descriptive string
can be obtained for the last error that occurred by calling
wtxErrMsgGet().

Note that virtually all WTX calls can fail due to an error in the message
transport layer used to carry out WTX requests.  Transport errors that
are non-recoverable result in the tool being detached from the server
and an error code of WTX_ERR_API_TOOL_DISCONNECTED. If a non-fatal
error occurs, WTX_ERR_API_REQUEST_FAILED is set, except in the case of
a timeout. In that case the error is WTX_ERR_API_REQUEST_TIMED_OUT. In
the non-fatal cases, the call may be retried. In the fatal case, retrying the
call results in the error WTX_ERR_API_NOT_CONNECTED.

All API calls attempt to check the validity of the API handle provided.
The error WTX_ERR_API_INVALID_HANDLE indicates a bad handle. Other
pointer arguments are checked and WTX_ERR_API_INVALID_ARG indicates a
bad argument value such as a NULL pointer.  API calls that require the
handle to be connected to a target server generate the
WTX_ERR_API_NOT_CONNECTED error if the handle is not connected.

In addition to simple error return values, the C API allows error
handlers to be installed on a per handle basis using
wtxErrHandlerAdd().  If an error occurs, the last installed
handler is called first. If it returns a TRUE value, then any
previously installed handlers are called in reverse order, in other words,
last installed, first called.  The C API includes macros that use the
predefined error handler wtxErrExceptionFunc() to support C++ style
exception catching.  Once an API handle has been initialized using
wtxInitiliaze(), it can be used in the WTX_TRY macro to cause API
errors to be treated like exceptions. When this is done, an API call
that would normally return an error code actually causes a jump
straight to the nearest 'catch' handler as specified using a WTX_CATCH
or WTX_CATCH_ALL macro.  The previous example is shown below using this
style of error handling.

.CS
#include "wtx.h"

    HWTX hWtx;

    /@ initialize WTX session handle @/

    if (wtxInitialize (&hWtx) != WTX_OK)
	return (WTX_ERROR);

    /@ Start a block in which errors will be "caught" by a catch block @/

    WTX_TRY (hWtx)

        {

	/@ attach to Target Server named "soubirou" @/

        wtxToolAttach (hWtx, "soubirou", "wtxApp");

	/@ register for events we want to hear about (all events here) @/

	wtxRegisterForEvent (hWtx, ".*");

	/@ core of the WTX application @/
		   .
		   .
		   .
		   .

	/@ detach form the Target Server @/

	wtxToolDetach (hWtx);

	}

    /@ Catch a specific error, WTX_ERR_API_NOT_CONNECTED @/

    WTX_CATCH (hWtx, WTX_ERR_API_NOT_CONNECTED)
	    {	
	    fprintf (stderr, "Connection lost, exiting\n");
	    wtxTerminate (hWtx);
	    exit (0);
	    }

    /@ Catch any other errors in one handler and print error message @/

    WTX_CATCH_ALL (hWtx)
	fprintf (stderr, "%s\n", wtxErrMsgGet (hWtx));

    /@ Finish the try block and resume normal error handling @/

    WTX_TRY_END (hWtx);

    /@
     * Normal error handling is now restored - the WTX_TRY_END macro
     * must be executed for this to occur.
     @/
     
    /@ wtxTerminate() will also detach the tool if already attached @/

    wtxTerminate (hWtx);
.CE

In certain circumstances, it may be useful to generate a user-defined
error or to simulate an API error from within user code. This may be
done using the WTX_THROW macro, which causes execution to jump to the
nearest handler for the error thrown or to the nearest "catch all"
handler.

Many of the C API calls are very similar to the equivalent WTX
protocol calls and the user may also refer to the appropriate section
in the \f2WTX Protocol\fP reference for further information.

INCLUDE FILES: wtx.h
*/

/* includes */

#ifdef HOST
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifdef SUN4_SUNOS4
extern int              sys_nerr;
extern char *           sys_errlist;
#endif /* SUN4_SUNOS4 */
#endif

#include "private/wtxp.h"	/* Private (and public) headers */
#include "wtxexch.h"

/* These five include files are here because this implementation
 * of the WTX API is based on RPC calls.  Full implementation of the 
 * "exchange" layer would remove this transport dependency
 */
#include "wtxrpc.h"		/* For handling wtxregd RPC key routines */
#include "wtxxdr.h"		/* For WTX XDR routines */


/* defines */

#define STREQ(a,b) (*(a) == *(b) ? !strcmp ((a), (b)) : 0)

/* typedefs */

/*
 * Special dummy message type for anonymous casting and calculating field
 * alignments in wtxResultFree() 
 */
typedef struct wtx_msg_dummy	
    {
    WTX_CORE	wtxCore;
    UINT32	field;
    } WTX_MSG_DUMMY;

/* See wtx.h and wtxp.h */

/* globals */

const char WTX_EVT_TGT_RESET[] =	"TGT_RESET";
const char WTX_EVT_SYM_ADDED[] =	"SYM_ADDED";
const char WTX_EVT_SYM_REMOVED[] =	"SYM_REMOVED";
const char WTX_EVT_OBJ_LOADED[] =	"OBJ_LOADED";
const char WTX_EVT_OBJ_UNLOADED[] =	"OBJ_UNLOADED";
const char WTX_EVT_CTX_START[] =	"CTX_START";
const char WTX_EVT_CTX_EXIT[] =		"CTX_EXIT";
const char WTX_EVT_EXCEPTION[] =	"EXCEPTION";
const char WTX_EVT_VIO_WRITE[] =	"VIO_WRITE";
const char WTX_EVT_TOOL_ATTACH[] =	"TOOL_ATTACH";
const char WTX_EVT_TOOL_DETACH[] =	"TOOL_DETACH";
const char WTX_EVT_TOOL_MSG[] =		"TOOL_MSG";
const char WTX_EVT_TEXT_ACCESS[] =	"TEXT_ACCESS";
const char WTX_EVT_DATA_ACCESS[] =	"DATA_ACCESS";
const char WTX_EVT_CALL_RETURN[] =	"CALL_RETURN";
const char WTX_EVT_CALL_GOT_EXC[] =	"CALL_GOT_EXC";
const char WTX_EVT_USER[] =		"USER";
const char WTX_EVT_UNKNOWN[] =		"UNKNOWN";

/* locals */

/* forward declarations */

LOCAL WTX_ERROR_T exchange (HWTX hWtx, UINT32 svcNum, void * pIn, void * pOut);
LOCAL WTX_ERROR_T registryConnect (HWTX	hWtx);
LOCAL void 	  registryDisconnect (HWTX hWtx);

LOCAL void        toolCleanup (HWTX hWtx);
LOCAL void	  serverDescFree (HWTX	hWtx);

/*
 * NOTE: This is a list of WTX protocol calls not accessible from the 
 *       WTX C API and is based on the service numbers in wtxmsg.h
 *
 * WTX_EVENTPOINT_ADD/DELETE	- (currently breakpoints only)
 * WTX_VIO_READ			- not implemented in server (obsolete?)
 * WTX_VIO_FILE_LIST		- to do
 * WTX_SYM_TBL_CREATE/DELETE	- to do
 * WTX_SYM_TBL_LIST/INFO_GET	- to do
 * WTX_SYM_REMOVE		- to do
 * WTX_SYM_LIST_GET		- to do
 * WTX_UN_REGIS_FOR_EVENT	- not implemented in server
 * WTX_SERVICE_ADD		- to do
 * WTX_WTX_SERVICE_LIST		- not implemented in server - undefined
 * WTX_WDB_SERVICE_LIST		- not implemented in server - undefined
 * WTX_OBJ_KILL			- (currently TS kill only) Enough ?
 * WTX_OBJ_RESTART		- undefined (obsolete ?)
 */

/*******************************************************************************
*
* wtxToolAttach - connect a WTX client to the target server
*
* This routine establishes a connection to the target server
* called <serverName> and announces the client as a WTX tool called
* <toolName>. If <serverName> does not contain an `@' character, it is
* used as a regular expression; if it matches more than one (registered)
* target server name, an error is returned.  If <serverName> contains 
* an `@' character then it must be an exact match for a valid target 
* server name.
*
* RETURNS: WTX_OK or WTX_ERROR if the attach fails.
*
* ERRORS:
* .iP WTX_ERR_API_ALREADY_CONNECTED 12
* The handle is already connected to a target server.
* .iP WTX_ERR_API_SERVER_NOT_FOUND 
* <serverName> does not match a target server name using the above criteria.
* .iP WTX_ERR_API_AMBIGUOUS_SERVER_NAME 
* <serverName> matches more than one target server name.
*
* SEE ALSO: wtxToolDetach(), wtxToolConnected()
*/

STATUS wtxToolAttach 
    (
    HWTX	 hWtx,		/* WTX API handle */
    const char * serverName,	/* Target Server name */
    const char * toolName	/* tool name */
    )
    
    {
    WTX_ERROR_T		callStat;	/* status of WTX call */
    WTX_MSG_TOOL_DESC	in;		/* WTX param */
    WTX_MSG_TOOL_DESC   *pOut;		/* WTX result */
    char *		envUser;	/* result of getenv(USER) */
    char 		userName [256]; /* to format "user@host" */
    char 		hostNameBuf [32]; /* for gethostname () */
    WTX_DESC		* pSaveDesc;
#ifdef WIN32
    char                usrName [256];  /* holds name for Win32 */
#endif

    WTX_CHECK_HANDLE (hWtx, WTX_ERROR);

    if (wtxToolConnected (hWtx))
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_ALREADY_CONNECTED, WTX_ERROR);

    if (hWtx->pServerDesc) 
	{
	wtxResultFree (hWtx, hWtx->pServerDesc);
	hWtx->pServerDesc = NULL;
	}

    if (!strchr (serverName, '@'))			/* name: tgtsvr */
	{
	WTX_DESC_Q *	pTsDescQ;	/* Q Info about Target Server */

	pTsDescQ = wtxInfoQ (hWtx, (char *)serverName, NULL, NULL);

	if (pTsDescQ == NULL)
	    WTX_ERROR_RETURN (hWtx, WTX_ERR_API_SERVER_NOT_FOUND, WTX_ERROR);
	
	if (pTsDescQ->pNext != NULL)
	    {
	    wtxResultFree (hWtx, pTsDescQ);
	    WTX_ERROR_RETURN (hWtx, WTX_ERR_API_AMBIGUOUS_SERVER_NAME, 
			      WTX_ERROR);
	    }

	/*
	 * This is possible because the type of the message is stored in
	 * the WTX_CORE field so the free will still work properly.
	 */
	hWtx->pServerDesc = (WTX_DESC *) pTsDescQ;
	}
    else
	{
	WTX_DESC *		pTsDesc;	/* Info about Target Server */

	pTsDesc = wtxInfo (hWtx, (char *)serverName);	/* name: tgtsvr@host */

	if (pTsDesc == NULL)
	    WTX_ERROR_RETURN (hWtx, WTX_ERR_API_SERVER_NOT_FOUND, WTX_ERROR);

	hWtx->pServerDesc = pTsDesc;
	}

    /* allocate space to copy server information */

    if ((pSaveDesc = (WTX_DESC *) malloc (sizeof (WTX_DESC))) == NULL)
	{
	wtxResultFree (hWtx, hWtx->pServerDesc);
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, WTX_ERROR);
	}

    /* copy server information */

    memcpy ((void *) pSaveDesc, (void *) hWtx->pServerDesc, sizeof (WTX_DESC));

    if (hWtx->pServerDesc->wpwrName != NULL)
	{
	if ((pSaveDesc->wpwrName = (char *) malloc (strlen
			    (hWtx->pServerDesc->wpwrName) + 1)) == NULL)
	    {
	    free (pSaveDesc);
	    wtxResultFree (hWtx, hWtx->pServerDesc);
	    WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, WTX_ERROR);
	    }
	    
        strcpy (pSaveDesc->wpwrName, hWtx->pServerDesc->wpwrName);
	}

    if (hWtx->pServerDesc->wpwrKey != NULL)
	{
	if ((pSaveDesc->wpwrKey = (char *) malloc (strlen
			    (hWtx->pServerDesc->wpwrKey) + 1)) == NULL)
	    {
	    free (pSaveDesc);
	    free (pSaveDesc->wpwrName);
	    wtxResultFree (hWtx, hWtx->pServerDesc);
	    WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, WTX_ERROR);
	    }
	    
        strcpy (pSaveDesc->wpwrKey, hWtx->pServerDesc->wpwrKey);
	}

    if (hWtx->pServerDesc->wpwrType != NULL)
	{
	if ((pSaveDesc->wpwrType = (char *) malloc (strlen
			    (hWtx->pServerDesc->wpwrType) + 1)) == NULL)
	    {
	    free (pSaveDesc);
	    free (pSaveDesc->wpwrName);
	    free (pSaveDesc->wpwrKey);
	    wtxResultFree (hWtx, hWtx->pServerDesc);
	    WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, WTX_ERROR);
	    }
	    
        strcpy (pSaveDesc->wpwrType, hWtx->pServerDesc->wpwrType);
	}

    wtxResultFree (hWtx, hWtx->pServerDesc);
    registryDisconnect (hWtx);

    hWtx->pServerDesc = pSaveDesc;

    if (wtxExchangeInitialize (&hWtx->server) != WTX_OK ||
	wtxExchangeInstall (hWtx->server, 
			    wtxRpcExchangeCreate, 
			    wtxRpcExchangeDelete, 
			    wtxRpcExchange, 
			    wtxRpcExchangeFree, 
			    wtxRpcExchangeControl) != WTX_OK ||
	wtxExchangeCreate (hWtx->server, 
			   hWtx->pServerDesc->wpwrKey) != WTX_OK)
	{
	WTX_ERROR_T errCode;

	/* Record the error code */
	errCode = wtxExchangeErrGet (hWtx->server);

	/* free server descriptor */
	serverDescFree (hWtx);

	/* Cleanup the exchange */
	wtxExchangeTerminate (hWtx->server);
	hWtx->server = NULL;

	WTX_ERROR_RETURN (hWtx, errCode, WTX_ERROR);
	}

    memset (&in, 0, sizeof (in));

    in.wtxToolDesc.toolName = (char *) toolName;
#ifdef HOST
#ifdef WIN32
    {
        UINT32 size = sizeof (usrName);    

        if(!GetUserName (usrName, &size))
	    envUser = NULL;
	else
	    envUser = usrName;
    }
#else
    envUser = getenv ("USER");
#endif /* WIN32 */
    gethostname (hostNameBuf, sizeof (hostNameBuf));
#else
    envUser = sysBootParams.usr;
    strcpy (hostNameBuf, sysBootParams.targetName);
#endif /* HOST */
    if (envUser == NULL)
	envUser = "unknown";
    if (hostNameBuf[0] == '\0')
	strcpy (hostNameBuf, "unknown");
    sprintf (userName, "%.24s@%.24s", envUser, hostNameBuf);

    in.wtxToolDesc.userName = userName;

    pOut = calloc (1, sizeof (WTX_MSG_TOOL_DESC));
    if (pOut == NULL)
	{
	/* Close the connection to the server */
	wtxExchangeDelete (hWtx->server);

	/* free server descriptor */
	serverDescFree (hWtx);

	/* Clean up the exchange */
	wtxExchangeTerminate (hWtx->server);
	hWtx->server = NULL;

	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, WTX_ERROR);
	}

    /* Do the attach call */
    callStat = exchange (hWtx, WTX_TOOL_ATTACH, &in, pOut);
	
    if (callStat != WTX_ERR_NONE)
	{
	/* Close the connection to the server */
	wtxExchangeDelete (hWtx->server);

	/* free server descriptor */
	serverDescFree (hWtx);

	/* Clean up the exchange */
	wtxExchangeTerminate (hWtx->server);
	hWtx->server = NULL;

	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);
	}

    /* Set the msgToolId and pToolDesc filed in the HWTX for future use */
    hWtx->pToolDesc = &pOut->wtxToolDesc;
    hWtx->msgToolId.wtxCore.objId = pOut->wtxToolDesc.id;

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxToolConnected - check to see if a tool is connected to a target server
*
* This routine checks if the tool represented by <hWtx> is currently
* connected to a target server. 
*
* NOTE: If <hWtx> is an invalid handle then FALSE is returned.
*
* RETURNS: TRUE if the tool is connected, FALSE otherwise.
*
* SEE ALSO: wtxErrClear(), wtxErrGet()
*/

BOOL32 wtxToolConnected 
    (
    HWTX	hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_HANDLE (hWtx, FALSE);

    return (hWtx->server != NULL);
    }

/*******************************************************************************
*
* wtxToolDetach - detach from the target server
*
* This routine detaches from the target server. 
* The connection status for <hWtx> is cleared and any memory
* allocated by the tool attach is freed. 
*
* NOTE: Even if the detach fails internally (for example, the server
* it is attached to has died), the API still puts the handle into a
* detached state and performs all necessary internal cleanup. In this
* case the internal error is `not' reported since the tool is no longer
* attached and the handle can subsequently be attached to another server.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxToolAttach()
*/

STATUS wtxToolDetach 
    (
    HWTX	hWtx		/* WTX API handle */
    )
    {
    WTX_ERROR_T		callStat;	/* WTX call status */
    WTX_MSG_RESULT	out;		/* WTX result */

    WTX_CHECK_HANDLE (hWtx, WTX_ERROR);

    if (! wtxToolConnected(hWtx))
	return (WTX_OK);

    memset (&out, 0, sizeof (out));

    callStat = exchange (hWtx, WTX_TOOL_DETACH, &hWtx->msgToolId, &out);

    /* Free allocated memory and close neatly the connection to the server */

    wtxExchangeFree (hWtx->server, WTX_TOOL_DETACH, &out);

    /* 
     * free the server descriptor and the strings that were allocated in 
     * wtxToolAttach().
     */

    serverDescFree (hWtx);

    toolCleanup(hWtx);

    /* Actively ignore any errors that may occur */

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxInitialize - initialization routine to be called by the WTX client
*
* This routine allocates a handle structure for the tool's use and
* does any initialization required for use of the WTX interface.  All
* subsequent calls by the tool should use the handle returned in <phWtx>.
* If WTX_ERROR is returned and the handle <phWtx> is zero, then the
* initialization failed because the internal handle structure could
* not be allocated. Otherwise use wtxErrMsgGet() to find the cause
* of the error.
* 
* RETURNS: WTX_OK or WTX_ERROR if the initialization fails.
*
* ERRORS: 
* .iP WTX_ERR_API_INVALID_ARG 12
* The pointer <phWtx> is NULL.
* .iP WTX_ERR_API_MEMALLOC 
* The handle cannot be allocated.
*
* SEE ALSO: wtxTerminate(), wtxVerify()
*/

STATUS wtxInitialize 
    (
    HWTX * phWtx	/* RETURN: handle to use in subsequent API calls */
    )
    {
    if (phWtx == NULL)
	WTX_ERROR_RETURN (NULL, WTX_ERR_API_INVALID_ARG, WTX_ERROR);

    *phWtx = calloc (1, sizeof (struct _wtx));
    
    if (*phWtx == NULL)
	WTX_ERROR_RETURN (NULL, WTX_ERR_API_MEMALLOC, WTX_ERROR);
    
    /* Set the field that identifies this as a valid handle */
    (*phWtx)->self = *phWtx;

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxTerminate - terminate the use of a WTX client handle
*
* This routine destroys the specified context handle so it may no
* longer be used in WTX API calls.  If the tool is attached to a
* target server, it is first detached. (It is forcibly detached if
* errors make a normal detach impossible.)  Any memory allocated by 
* the handle is freed and the handle is invalidated; any subsequent 
* use causes an abort.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxInitialize(), wtxVerify()
*/

STATUS wtxTerminate
    (
    HWTX	hWtx		/* WTX API handle */
    )
    {
    WTX_CHECK_HANDLE (hWtx, WTX_ERROR);


    if (wtxToolConnected (hWtx))
	wtxToolDetach (hWtx);

    if (hWtx->pServerDesc) 
	wtxResultFree (hWtx, hWtx->pServerDesc);

    if (hWtx->pSelfDesc)
	wtxResultFree (hWtx, hWtx->pSelfDesc);

    if (hWtx->registry)
	wtxExchangeDelete (hWtx->registry);

    wtxExchangeTerminate (hWtx->server);
    wtxExchangeTerminate (hWtx->registry);

    /* Invalidate this handle in case it is used after terminate */
    hWtx->self = NULL;

    /* Now free up the handle memory */
    free (hWtx);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxErrSet - set the error code for the handle
*
* This routine sets the error value <errCode> in the handle specified 
* by <hWtx> so that wtxErrGet() can return <errCode> as the error.
*
* NOTE: Error handlers for the handle are not called. To set the error
* code and call the registered error handlers, use wtxErrDispatch().
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxErrGet(), wtxErrMsgGet(), wtxErrClear(), wtxErrDispatch().
*/

STATUS wtxErrSet 
    (
    HWTX 	hWtx, 		/* WTX API handle */
    UINT32	errCode		/* error value to set */
    )
    {
    WTX_CHECK_HANDLE (hWtx, WTX_ERROR);

    /* Ensure any allocated strings are freed up */
    wtxErrClear (hWtx);

    hWtx->errCode = errCode;
    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxErrGet - return the last error for a handle
*
* This routine returns the last error that occurred for the <hWtx> handle.
* The error code is only valid after an error is reported by one of the
* API calls. To check for an error after a series of API calls use 
* wtxErrClear() to clear the error status at the start and call wtxErrGet()
* at the end. 
*
* RETURNS: The last error code or WTX_ERROR if the handle is invalid.
*
* SEE ALSO: wtxErrMsgGet(), wtxErrSet(), wtxErrClear()
*/

WTX_ERROR_T wtxErrGet 
    (
    HWTX	hWtx		/* WTX API handle */
    )

    {
    WTX_CHECK_HANDLE (hWtx, WTX_ERROR);

    return (hWtx->errCode);
    }


/*******************************************************************************
*
* wtxErrHandlerAdd - add an error handler for the WTX handle
*
* This routine adds a new error handler to the list of registered handlers
* for the handle <hWtx>.  The last error handler added is the first one
* called when an error occurs. The function <pFunc> is called with three
* arguments, the handle on which the error occurred, the client data
* <pClientData>, and a call data parameter which is the error code. If the
* function returns the value TRUE then each previously registered handler
* function is called in turn until all are called or one returns the
* value FALSE.
*
* EXAMPLE
* The following is a sample error handler:
*
* .CS
*   BOOL32 errorHandler
*       (
*	HWTX   hWtx,	     /@ WTX API handle @/
*	void * pClientData,  /@ client data from wtxErrHandlerAdd() call @/
*	void * errCode       /@ error code passed from wtxErrDispatch() @/
*       )
*
*       {
*	/@ print an error message @/
*	
*	fprintf (stderr, 
*		 "Error %s (%d) from server %s\n", 
*		 wtxErrMsgGet (hWtx),
*		 (WTX_ERROR_T) errCode,		/@ or use wtxErrGet() @/
*		 wtxTsNameGet (hWtx));
*
*	/@ return TRUE allowing previously installed handlers to be called @/
*
*	return TRUE;
*	}
* .CE
*
* RETURNS: A new handler ID or NULL on failure.
*
* ERRORS:
* .iP WTX_ERR_API_MEMALLOC 12
* No memory is available to add the new handler.
*
* SEE ALSO: wtxErrHandlerRemove(), wtxErrDispatch()
*/

WTX_HANDLER_T wtxErrHandlerAdd 
    (
    HWTX		hWtx,		/* WTX API handle */
    WTX_HANDLER_FUNC	pFunc,		/* function to call on error */
    void *		pClientData	/* data to pass function */
    )

    {
    WTX_HANDLER_T descNew;

    WTX_CHECK_HANDLE (hWtx, NULL);

    descNew = calloc (1, sizeof (_WTX_HANDLER_T));

    if (descNew == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);
    
    descNew->pFunc = pFunc;
    descNew->pClientData = pClientData;
    descNew->prev = hWtx->errHandler;
    hWtx->errHandler = descNew;

    return descNew;
    }


/*******************************************************************************
*
* wtxErrHandlerRemove - remove an error handler from the WTX handle
*
* This function removes the error handler referenced by <errHandler> from 
* the handler list for <hWtx>. The error handler ID <errHandler> must be a 
* valid error handler ID returned by a call of wtxErrHandlerAdd().
*
* NOTE: It is safe for wtxErrHandlerRemove() to be called from within an
* error handler function, even if the call is to remove itself.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* ERRORS:
* .iP WTX_ERR_API_HANDLER_NOT_FOUND 12
* <errHandler> is not a valid handler ID.
*
* SEE ALSO: wtxErrHandlerAdd(), wtxErrDispatch() 
*/

STATUS wtxErrHandlerRemove 
    (
    HWTX hWtx,			/* WTX API handle */
    WTX_HANDLER_T errHandler	/* Error handler to remove */
    )

    {
    WTX_HANDLER_T desc;
    WTX_HANDLER_T last;

    WTX_CHECK_HANDLE (hWtx, WTX_ERROR);

    last = NULL;

    for (desc = hWtx->errHandler; desc; desc = desc->prev)
	{
	if (desc == errHandler)
	    {
	    /* Got the one to remove */
	    if (last)
		last->prev = desc->prev;
	    else
		hWtx->errHandler = desc->prev;
	    free (desc);
	    return (WTX_OK);
	    }
	last = desc;
	}

    WTX_ERROR_RETURN (hWtx, WTX_ERR_API_HANDLER_NOT_FOUND, WTX_ERROR);
    }

		    
/*******************************************************************************
*
* wtxErrDispatch - dispatch an error with supplied code for the given handle
*
* This function records the error <errCode> against the handle <hWtx> and 
* calls all the registered error handlers for it until one returns FALSE.
*
* RETURNS: WTX_OK or WTX_ERROR if the handle is invalid.
*
* SEE ALSO: wtxErrHandlerAdd()
*/

STATUS wtxErrDispatch
    (
    HWTX	hWtx,		/* WTX API handle */
    WTX_ERROR_T	errCode		/* error code to register */
    )

    {
    WTX_HANDLER_T desc;
    BOOL32 continueToDispatch;

    /* cannot use macro here as it will cause recursion via WTX_ERROR_RETURN */
    if (hWtx == NULL || hWtx->self != hWtx)
	{
	/* cannot do anything with the error */

	/* FIXME: should implement a global error handler */
	return WTX_ERROR;
	}

    /* Record the error code */
    hWtx->errCode = errCode;
    hWtx->errMsg = NULL;

    continueToDispatch = TRUE;
    desc = hWtx->errHandler; 

    /* Dispatch the error to all the error handlers */
    while ((desc != NULL) && continueToDispatch)
	{
	WTX_HANDLER_T prev;

	/* Just in case the handler removes itself! */
	prev = desc->prev;

	/* Be sure the function is non-null */
	if (desc->pFunc)
	    continueToDispatch = desc->pFunc (hWtx, 
					      desc->pClientData, 
					      (void *) errCode);
	desc = prev;
	}

    return (WTX_OK);
    }


/*******************************************************************************
* 
* wtxErrMsgGet - fetch the last network WTX API error string
*
* This routine gets a meaningful string for the last WTX API call
* that returned WTX_ERROR. The string is only valid after a WTX
* call has returned an error.
*
* NOTE: The return value is a pointer to internal data and must
* not be freed by the caller. Also the string is only valid until
* the next error occurs or wtxErrorClear() is called. It must
* be copied by the caller if the value must be stored.
*
* RETURNS: A pointer to a string or NULL if an error has occurred. 
*
* SEE ALSO: wtxErrorClear(), wxErrGet()
*/

const char * wtxErrMsgGet
    (
    HWTX	hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_HANDLE (hWtx, NULL);

    /* This allows for caching of previous values but is not yet implemented */
    if (hWtx->errMsg != NULL)
	return hWtx->errMsg;
    else
	{
	hWtx->errMsg = wtxErrToMsg (hWtx, hWtx->errCode);
	return hWtx->errMsg;
	}
    }


/*******************************************************************************
*
* wtxErrToMsg - convert an WTX error code to a descriptive string
*
* This routine takes an error code which has been returned by a WTX API
* call and returns a descriptive string. The value returned is a pointer
* to a string in statically allocated memory. The string must be copied 
* if the value is to be stored and it must not be freed by the caller.
*
* RETURNS: A pointer to an error string.
*/
const char * wtxErrToMsg
    (
    HWTX hWtx, 
    WTX_ERROR_T errCode
    )
    {
    static char buffer [256];

    if (errCode == WTX_ERR_NONE)
	return "No error";

    if ((errCode > WTXERR_BASE_NUM) && (errCode < WTX_ERR_LAST))
	{
	FILE * fp;

#ifdef WIN32
	sprintf (buffer, "%s\\host\\resource\\tcl\\wtxerrdb.tcl", 
		 getenv ("WIND_BASE"));
#else
	sprintf (buffer, "%s/host/resource/tcl/wtxerrdb.tcl", 
		 getenv ("WIND_BASE"));
#endif
    
	fp = fopen (buffer, "r");
	while (fp != NULL && ! ferror (fp))
	    {
	    UINT32	errNum;
	    char	errStr[256];

	    if (fgets (buffer, sizeof (buffer), fp) == NULL)
		break;

	    if (sscanf (buffer, "set wtxError(0x%x) %s", &errNum, errStr) == 2
		&& (errNum == errCode))
		{
		sprintf (buffer, "%s", errStr);
		fclose (fp);
		return buffer;
		}
	    }

	if (fp)
	    fclose (fp);

	/* A WTX error we have no error text for */
	sprintf (buffer, "WTX error %#x", errCode);
	}

#ifdef SUN4_SUNOS4
    /*
     * Avoid strerror() on SUNOS4, as this will pull libiberty.a into
     * the link, making it more difficult to bind this code into a
     * shared library.
     */
    else if (errCode > 0 && errCode < sys_nerr && sys_errlist [errCode] != NULL)
        {
        /* Probably a system error */
        sprintf (buffer, "%s (%d)", sys_errlist [errCode], errCode);
        }
#else  /* !SUN4_SUNOS4 */
    else if (strerror (errCode) != NULL)
        /* Probably a system error */
        sprintf (buffer, "%s (%d)", strerror (errCode), errCode);
#endif /* SUN4_SUNOS4 */

    else
	/* Some other error we don't know about */
	sprintf (buffer, "error %d (%#x)", errCode, errCode);

    return buffer;
    }


/*******************************************************************************
*
* wtxErrClear - explicitly clear any error status for the tool
*
* This routine clears an error message already recorded. It can be
* called before a WTX routine if you want to test for an error afterwards
* by checking whether wtxErrGet() returns a non-zero value.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxErrGet(), wtxErrMsgGet(), wtxErrSet()
*/

STATUS wtxErrClear
    (
    HWTX	hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_HANDLE (hWtx, WTX_ERROR);

    hWtx->errCode = WTX_ERR_NONE;
    hWtx->errMsg = NULL;

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxErrExceptionFunc - a function to handle an error using longjmp()
*
* This function is called as part of the error handling process shown in the
* discussion of C++ style exception catching in the wtx library description
* (\f2WTX C Library\fP).  The WTX_TRY macro, which registers the error
* handler wtxErrExceptionFunc(), is found in wtx.h.  <pClientData> contains
* the address of <jumpBuf> from WTX_TRY and <pCallData> is the error code 
* that is returned by WTX_TRY and should be cast to the type WTX_ERROR_T..
*
* RETURNS: FALSE if <pClientData> is NULL, otherwise it does not return.
* It executes a longjmp() back to <jumpBuf> in the WTX_TRY macro, which
* returns the error code passed back by <pCallData>.
*
* SEE ALSO: wtxErrHandlerAdd(), wtxErrDispatch()
*/

BOOL32 wtxErrExceptionFunc 
    (
    HWTX hWtx,			/* WTX API handle */
    void * pClientData,		/* pointer to a jump buffer */
    void * pCallData		/* error code to return via setjmp() */
    )

    {
    if (pClientData != NULL)
	longjmp (pClientData, (int) pCallData);

    return FALSE;
    }


/*******************************************************************************
*
* wtxClientDataGet - get the client data associated with the WTX handle
*
* This routine sets the pointer pointed at by <ppClientData> to the
* value set by the last call to wtxClientDataSet() for the handle <hWtx>.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* ERRORS: 
* .iP WTX_ERR_API_INVALID_ARG 12
* <ppClientData> is NULL.
*
* SEE ALSO: wtxClientDataSet()
*/

STATUS wtxClientDataGet 
    (
    HWTX hWtx,			/* WTX API handle */
    void ** ppClientData	/* RETURN: pointer to client data pointer */
    )

    {
    WTX_CHECK_HANDLE (hWtx, WTX_ERROR);

    if (ppClientData == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_INVALID_ARG, WTX_ERROR);

    *ppClientData = hWtx->pClientData;

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxClientDataSet - set the client data associated with the WTX handle
*
* This routine causes the value <pClientData> to be associated with the
* WTX API handle <hWtx>. The client data can be used by the
* caller in any way and, except when in the set and get routines,
* is not used or altered in any way by the WTX API. The initial value
* of the client data before it is set is always NULL.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxClientDataGet().
*/

STATUS wtxClientDataSet 
    (
    HWTX hWtx,			/* WTX API handle */
    void * pClientData		/* value to associate with handle */
    )

    {
    WTX_CHECK_HANDLE (hWtx, WTX_ERROR);
    hWtx->pClientData = pClientData;

    return (WTX_OK);
    }

/*******************************************************************************
*
* wtxAgentModeGet - get the mode of the target agent
*
* This routine returns the running mode of the target agent that the 
* current target server is attached to.  
*
* EXPAND ../../../include/wtxtypes.h WTX_AGENT_MODE_TYPE
*
* RETURNS: The current agent running mode or WTX_ERROR.
*
* SEE ALSO: wtxTsInfoGet(), wtxAgentModeSet()
*/

WTX_AGENT_MODE_TYPE wtxAgentModeGet 
    (
    HWTX		hWtx		/* WTX API handle */
    )
    {
    WTX_ERROR_T		callStat;	/* client status */
    WTX_AGENT_MODE_TYPE	result;		/* debug agent mode */
    WTX_MSG_RESULT	out;		/* WTX result */

    /*
     * All API calls that require a connection to the target server
     * should use the WTX_CHECK_CONNECTED macro before doing anything else.
     * This macro also calls WTX_CHECK_HANDLE to validate the handle.
     */

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    /* Always remember to initialize the out params */

    memset (&out, 0, sizeof (out));

    callStat = exchange (hWtx, WTX_AGENT_MODE_GET, &hWtx->msgToolId, &out);

    /*
     * If there is an error we don't need to free the result with 
     * wtxExchangeFree() because wtxExchange() (called by exchange()) 
     * does this for us when there is an error.
     */

    if (callStat != WTX_ERR_NONE)
	/*
	 * On error the WTX_ERROR_RETURN macro calls wtxErrDispatch() for
	 * us (which sets the error code in the API handle and calls any
	 * registered error handlers). It then returns the last param as
	 * the result. In the case where the out param was dynamically
	 * allocated (see wtxEventGet() for example) is the API call fails
	 * then we must call free() on the result before the error return.
	 */

	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    /* 
     * Here we extract any information we want from the out param, then
     * free it using wtxExchangeFree() so any exchange allocated memory is
     * released and then return the desired result value.
     */

    result = out.val.value_u.v_int32;

    wtxExchangeFree (hWtx->server, WTX_AGENT_MODE_GET, &out);

    return result;
    }


/*******************************************************************************
*
* wtxAgentModeSet - set the mode of the target agent
*
* This routine sets the mode of the target agent that the current target
* server is attached to.  A given agent may not support all the possible 
* modes.
*
* EXPAND ../../../include/wtxtypes.h WTX_AGENT_MODE_TYPE
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxTsInfoGet(), wtxAgentModeGet()
*/

STATUS wtxAgentModeSet 
    (
    HWTX		hWtx,		/* WTX API handle */
    WTX_AGENT_MODE_TYPE	agentMode	/* debug agent mode */
    )
    {
    WTX_ERROR_T		callStat;	/* client status */
    WTX_MSG_PARAM	in;		/* WTX param */
    WTX_MSG_RESULT	out;		/* WTX result */

    /*
     * All API calls that require a connection to the target server
     * should use the WTX_CHECK_CONNECTED macro before doing anything else.
     * This macro also calls WTX_CHECK_HANDLE to validate the handle.
     */
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    /* Always remember to initialize the in and out params */
    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    /* Fill in the relevant fields of the in params for the call */
    in.param.valueType = V_UINT32;
    in.param.value_u.v_uint32 = agentMode;

    /* Now make the call recording the result status */
    callStat = exchange (hWtx, WTX_AGENT_MODE_SET, &in, &out);

    /*
     * If there is an error we don't need to free the result with 
     * wtxExchangeFree() because wtxExchange() (called by exchange()) 
     * does this for us when there is an error.
     */
    if (callStat != WTX_ERR_NONE)
	/*
	 * On error the WTX_ERROR_RETURN macro calls wtxErrDispatch() for
	 * us (which sets the error code in the API handle and calls any
	 * registered error handlers). It then returns the last param as
	 * the result. In the case where the out param was dynamically
	 * allocated (see wtxEventGet() for example) is the API call fails
	 * then we must call free() on the result before the error return.
	 */
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    /* 
     * Here we extract any information we want from the out param, then
     * free it using wtxExchangeFree() so any exchange allocated memory is
     * released and then return the desired result value.
     */
    wtxExchangeFree (hWtx->server, WTX_AGENT_MODE_SET, &out);

    return (WTX_OK);
    }

/*******************************************************************************
*
* wtxBreakpointAdd - create a new WTX eventpoint of type breakpoint
*
* This routine creates a new eventpoint on the target to represent a
* breakpoint at the address <tgtAddr> for the target context <contextId>.
* The target server maintains a list of eventpoints created on the target
* and this can be queried using wtxEventpointList().  When a context is
* destroyed on the target or the target is reset, eventpoints are deleted
* automatically without intervention from the creator.
*
* RETURNS: The ID of the new breakpoint or WTX_ERROR if the add fails.
*
* SEE ALSO: wtxEventpointDelete(), wtxEventpointList()
*/

UINT32 wtxBreakpointAdd 
    (
    HWTX		hWtx,		/* WTX API handle */
    WTX_CONTEXT_TYPE	contextType,	/* type of context to put bp in */
    WTX_CONTEXT_ID_T	contextId,	/* associated context */
    TGT_ADDR_T		tgtAddr		/* breakpoint address */
    )

    {
    WTX_MSG_RESULT	out;
    WTX_MSG_EVTPT_DESC	in;
    WTX_ERROR_T		callStat;
    UINT32		bpId;
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));
    memset (&in, 0, sizeof (in));

    in.wtxEvtpt.event.eventType = WTX_EVENT_TEXT_ACCESS;
    in.wtxEvtpt.event.eventArg = (TGT_ARG_T) tgtAddr;

    in.wtxEvtpt.context.contextType = contextType;
    in.wtxEvtpt.context.contextId = contextId;

    /* ??? Not used by target agent */
    in.wtxEvtpt.action.actionType = WTX_ACTION_STOP | WTX_ACTION_NOTIFY; 

    in.wtxEvtpt.action.actionArg = 0;	/* ??? Not used by target agent */
    in.wtxEvtpt.action.callRtn = 0;	/* ??? Not used by target agent */
    in.wtxEvtpt.action.callArg = 0;	/* ??? Not used by target agent */

    callStat = exchange (hWtx, WTX_EVENTPOINT_ADD, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    bpId = out.val.value_u.v_uint32; 
    wtxExchangeFree (hWtx->server, WTX_EVENTPOINT_ADD, &out);

    return bpId;
    }


/*******************************************************************************
*
* wtxEventpointDelete - delete an eventpoint from the target
*
* This routine deletes an existing eventpoint in the context given when it
* was created.  The eventpoint is identified by <evtptId> which is the
* ID returned by wtxBreakpointAdd() or wtxContextExitNotifyAdd().  If the 
* eventpoint has already been deleted on the target (for example, because 
* the context associated with it no longer exists), then the first call of 
* wtxEventpointDelete() returns WTX_OK. (The target server ignores the 
* deletion of a valid eventpoint ID that no longer exists on the target.)  
* If the target server eventpoint list does not contain the <evtptId>, then 
* the error WTX_ERR_SVR_INVALID_EVENTPOINT occurs.
* 
* RETURNS: WTX_OK or WTX_ERROR if the delete fails.
*
* SEE ALSO: wtxBreakpointAdd(), wtxContextExitNotifyAdd(), 
* wtxEventpointList() 
*/

STATUS wtxEventpointDelete 
    (
    HWTX	hWtx,		/* WTX API handle */
    UINT32	evtptId		/* ID of eventpoint to delete */
    )
    {
    WTX_MSG_RESULT	out;
    WTX_MSG_PARAM	in;
    WTX_ERROR_T		callStat;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.param.valueType = V_UINT32;
    in.param.value_u.v_uint32 = evtptId;
   
    callStat = exchange (hWtx, WTX_EVENTPOINT_DELETE, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_EVENTPOINT_DELETE, &out);

    return (WTX_OK);
    }

/*******************************************************************************
*
* wtxConsoleCreate - create a console window (UNIX only)
*
* This routine creates a new console window. The name passed in <name>
* is used as the title for the new window. If <name> is NULL, a unique 
* name is assigned by the target server.  When the target server is
* running in an X-Window environment, the <display> parameter
* identifies the X display device to create the window on. The <fdIn>
* and <fdOut> parameters are pointers to INT32 variables in
* which are stored the target server file descriptors for the
* input and output of the new console.  wtxVioCtl() can be used
* to redirect VIO input and output to the console.
* 
* UNIX HOSTS
* On UNIX systems the returned ID is actually a process
* ID of the new console running on the same host as the target server.
*
* WINDOWS HOSTS
* This request is not implemented on Windows.  Windows allows only one virtual
* console and it must be started on the target server command line with the
* `-c' option.
*
* RETURNS: The ID number of the new console or WTX_ERROR.
*
* ERRORS:
* .iP WTX_ERR_API_INVALID_ARG 12
* Either <fdIn> or <fdOut> is NULL.
*
* SEE ALSO: wtxConsoleKill(), wtxVioCtl()
*/

INT32 wtxConsoleCreate
    (
    HWTX hWtx,			/* WTX API handle */
    const char *name,		/* Name of console window */
    const char *display,	/* Display name eg: host:0 */
    INT32 *fdIn,		/* RETURN: input file descriptor */
    INT32 *fdOut		/* RETURN: output file descriptor */
    )

    {
    WTX_MSG_CONSOLE_DESC	out;
    WTX_MSG_CONSOLE_DESC	in;
    WTX_ERROR_T			callStat;
    INT32			pid;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    if (fdIn == 0 || fdOut == 0)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_INVALID_ARG, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.wtxConsDesc.name = (char *) name;
    in.wtxConsDesc.display = (char *) display;
   
    callStat = exchange (hWtx, WTX_CONSOLE_CREATE, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    *fdIn = out.wtxConsDesc.fdIn;
    *fdOut = out.wtxConsDesc.fdOut;
    pid = out.wtxConsDesc.pid;
    wtxExchangeFree (hWtx->server, WTX_CONSOLE_CREATE, &out);

    return pid;
    }


/*******************************************************************************
*
* wtxConsoleKill - destroy a console (UNIX only)
*
* This routine destroys a console identified by <consoleId> and created by 
* a previous call to wtxConsoleCreate().
* WINDOWS HOSTS
* This request is not implemented on Windows.  If issued, it returns an
* error, but does not attempt to kill an existing console.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxConsoleCreate() 
*/

STATUS wtxConsoleKill
    (
    HWTX hWtx,		/* WTX API handle */
    INT32 consoleId	/* id of console to destroy */
    )

    {
    WTX_MSG_RESULT	out;
    WTX_MSG_PARAM	in;
    WTX_ERROR_T		callStat;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.param.valueType = V_INT32;
    in.param.value_u.v_int32 = consoleId;
   
    callStat = exchange (hWtx, WTX_CONSOLE_KILL, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_CONSOLE_KILL, &out);

    return (WTX_OK);
    }

/*******************************************************************************
*
* wtxContextCont - continue execution of a target context
*
* This routine synchronously continues execution of the context <contextId>
* on the target after it has stopped at a breakpoint.  This routine should
* be used instead of wtxContextResume() when debugging a task to prevent
* the task hitting the breakpoint a second time.
*
* RETURNS: WTX_OK or WTX_ERROR on failure.
*
* SEE ALSO: wtxContextResume(), wtxBreakpointAdd()
*/

STATUS wtxContextCont 
    (
    HWTX		hWtx,		/* WTX API handle */
    WTX_CONTEXT_TYPE	contextType,	/* type of context to continue */
    WTX_CONTEXT_ID_T	contextId	/* id of context to continue */
    )
    {
    WTX_MSG_RESULT	out;
    WTX_MSG_CONTEXT	in;
    WTX_ERROR_T	callStat;
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));
    memset (&in, 0, sizeof (in));

    in.contextType = contextType;
    in.contextId = contextId;

    callStat = exchange (hWtx, WTX_CONTEXT_CONT, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_CONTEXT_CONT, &out);
    
    return (WTX_OK);
    }


/*******************************************************************************
* 
* wtxContextCreate - create a new context on the target
*
* This routine creates a new context using the information in the
* context descriptor pointed to by <pContextDesc> which describes
* parameters for a new task context or a system context. The caller is
* responsible for freeing information supplied in the context
* descriptor after the call.
*
* EXPAND ../../../include/wtx.h WTX_CONTEXT_DESC
*
* RETURNS: The ID of the new context or WTX_ERROR. 
*
* SEE ALSO: wtxContextKill()
*/

WTX_CONTEXT_ID_T wtxContextCreate 
    (
    HWTX		   hWtx,		/* WTX API handle */
    WTX_CONTEXT_DESC *	   pContextDesc		/* context descriptor */
    )

    {
    WTX_MSG_CONTEXT_DESC	in;
    WTX_MSG_CONTEXT		out;
    WTX_ERROR_T			callStat;
    WTX_CONTEXT_ID_T		ctxId;
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    /* Fill in the context create descritor message. */

    /*
     * XXX - must have WTX_CONTEXT_DESC fields identical to those
     * WTX_MSG_CONTEXT_DESC from contextType onwards. Awaits change to
     * message definitions on wtxmsg.h so this hack will go away.
     */
    memcpy (&in.contextType, pContextDesc, sizeof (WTX_CONTEXT_DESC));
    
    callStat = exchange (hWtx, WTX_CONTEXT_CREATE, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    ctxId = out.contextId;
    wtxExchangeFree (hWtx->server, WTX_CONTEXT_CREATE, &out);
	
    return ctxId;
    }


/*******************************************************************************
*
* wtxContextResume - resume execution of a target context
*
* This routine synchronously resumes execution of the context <contextId>
* on the target after it has been suspended, perhaps by wtxContextSuspend().
* Use wtxContextCont() rather than this routine to continue a task from a 
* breakpoint; this routine causes the task to hit the breakpoint again.
*
* RETURNS: WTX_OK or WTX_ERROR on failure.
*
* SEE ALSO: wtxContextSuspend()
*/

STATUS wtxContextResume 
    (
    HWTX		hWtx,		/* WTX API handle */
    WTX_CONTEXT_TYPE	contextType,	/* type of context to resume */
    WTX_CONTEXT_ID_T	contextId	/* id of context to resume */
    )
    {
    WTX_MSG_RESULT	out;
    WTX_MSG_CONTEXT	in;
    WTX_ERROR_T		callStat;
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));
    memset (&in, 0, sizeof (in));

    in.contextType = contextType;
    in.contextId = contextId;

    callStat = exchange (hWtx, WTX_CONTEXT_RESUME, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_CONTEXT_RESUME, &out);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxContextExitNotifyAdd - add a context exit notification eventpoint
*
* This routine creates a new eventpoint that notifies the user when the
* specified context exits by sending a WTX_EVT_CTX_EXIT event.  The eventpoint 
* is removed automatically when the context exits or the routine
* wtxEventpointDelete() can be used to remove the eventpoint before the
* context exits.
*
* RETURNS: A unique identifier for the new eventpoint or WTX_ERROR.
*
* SEE ALSO: wtxEventpointList(), wtxEventpointDelete()
*/

UINT32 wtxContextExitNotifyAdd 
    (
    HWTX		hWtx,		/* WTX API handle */
    WTX_CONTEXT_TYPE	contextType,	/* type of context */
    WTX_CONTEXT_ID_T	contextId	/* associated context */
    )

    {
    WTX_MSG_RESULT	out;
    WTX_MSG_EVTPT_DESC	in;
    WTX_ERROR_T		callStat;
    UINT32		result;
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));
    memset (&in, 0, sizeof (in));

    in.wtxEvtpt.event.eventType = WTX_EVENT_CTX_EXIT;
    in.wtxEvtpt.context.contextType = contextType;
    in.wtxEvtpt.context.contextId = contextId;

    in.wtxEvtpt.action.actionType = WTX_ACTION_NOTIFY;

    callStat = exchange (hWtx, WTX_EVENTPOINT_ADD, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    result = out.val.value_u.v_uint32; 
    wtxExchangeFree (hWtx->server, WTX_EVENTPOINT_ADD, &out);

    return result;
    }

/*******************************************************************************
*
* wtxContextKill - kill a target context
*
* This routine synchronously kills the context specified by
* <contextId> on the target.  
*
* NOTE: Killing the the system context may result in a reboot of the
* target. However, the correct way to reboot the target system is by calling
* wtxTargetReset().
*
* RETURNS: WTX_OK or WTX_ERROR if the context kill fails.
*
* SEE ALSO: wtxTargetReset() 
*/

STATUS wtxContextKill 
    (
    HWTX		hWtx,		/* WTX API handle */
    WTX_CONTEXT_TYPE	contextType,	/* type of context to kill */
    WTX_CONTEXT_ID_T	contextId	/* id of context to kill   */
    )
    {
    WTX_MSG_RESULT	out;
    WTX_MSG_CONTEXT	in;
    WTX_ERROR_T		callStat;
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));
    memset (&in, 0, sizeof (in));

    in.contextType = contextType;
    in.contextId = contextId;

    callStat = exchange (hWtx, WTX_CONTEXT_KILL, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_CONTEXT_KILL, &out);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxContextStep - single step execution of a target context
*
* This routine asynchronously single steps execution of a context on
* the target. Stepping occurs while <stepStart> <= PC < <stepEnd>.  If
* stepStart == stepEnd == 0 then the context is single stepped one
* machine instruction only.  Note that <stepStart> does not set the
* initial program counter; this must be done separately.
*
* NOTE: Stepping is an asynchronous operation so the return of this
* function does not signify completion of the stepping. After stepping
* completes, a breakpoint event is generated at the address which
* terminated the stepping operation.
*
* RETURNS: WTX_OK or WTX_ERROR if the step fails.
*
* SEE ALSO: wtxContextCont(), wtxContextSuspend()
*/

STATUS wtxContextStep 
    (
    HWTX	 	hWtx,		/* WTX API handle */
    WTX_CONTEXT_TYPE	contextType,	/* type of context to resume */
    WTX_CONTEXT_ID_T	contextId,	/* id of context to step */
    TGT_ADDR_T	 	stepStart,	/* stepStart pc value */
    TGT_ADDR_T   	stepEnd		/* stepEnd PC vale */
    )
    {
    WTX_MSG_RESULT		out;
    WTX_MSG_CONTEXT_STEP_DESC	in;
    WTX_ERROR_T		callStat;
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));
    memset (&in, 0, sizeof (in));

    in.context.contextType = contextType;
    in.context.contextId = contextId;
    in.startAddr = stepStart;
    in.endAddr = stepEnd;

    callStat = exchange (hWtx, WTX_CONTEXT_STEP, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_CONTEXT_STEP, &out);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxContextSuspend - suspend a target context
*
* This routine synchronously suspends execution of a context on the
* target.
*
* RETURNS: WTX_OK or WTX_ERROR if the suspend fails.
*/

STATUS wtxContextSuspend 
    (
    HWTX		hWtx,		/* WTX API handle */
    WTX_CONTEXT_TYPE	contextType,	/* type of context to suspend */
    WTX_CONTEXT_ID_T	contextId	/* id of context being suspended */
    )
    {
    WTX_MSG_RESULT	out;
    WTX_MSG_CONTEXT	in;
    WTX_ERROR_T		callStat;
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));
    memset (&in, 0, sizeof (in));

    in.contextType = contextType;
    in.contextId =  contextId;

    callStat = exchange (hWtx, WTX_CONTEXT_SUSPEND, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_CONTEXT_SUSPEND, &out);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxEventAdd - send an event to the target server
*
* This routine sends an event to the target server. The target server adds 
* it to the event list of any attached tool that has selected that event
* by using wtxRegisterForEvent() with a suitable event pattern.  The
* event is not sent back to the tool that generated it.
*
* EXPAND ../../../include/wtxmsg.h WTX_MSG_EVENT_DESC
*
* EXPAND ../../../include/wtxmsg.h WTX_EVENT_DESC
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxEventGet(), wtxRegisterForEvent().
*/

STATUS wtxEventAdd
    (
    HWTX	 hWtx,		/* WTX API handle */
    const char * event,		/* event string to send */
    UINT32       addlDataLen,	/* length of addl data block in bytes */
    const void * pAddlData	/* pointer to additional data */
    )

    {
    WTX_MSG_EVENT_DESC	in;
    WTX_MSG_RESULT	out;
    
    WTX_ERROR_T		callStat;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    if (addlDataLen != 0 && pAddlData == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_INVALID_ARG, WTX_ERROR);

    memset (&out, 0, sizeof (out));
    memset (&in, 0, sizeof (in));

    in.eventDesc.event		= (char *) event;
    in.eventDesc.addlDataLen	= (INT32) addlDataLen;
    in.eventDesc.addlData	= (char *) pAddlData;

    callStat = exchange (hWtx, WTX_EVENT_ADD, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxEventGet - get an event from the target
*
* This routine polls the target server for any events sent to this
* client tool. It only returns one event at a time.  The event
* descriptor returned is a string containing the primary event
* data, a length count of additional binary data and a pointer to the
* additional data.  The memory allocated for the event-descriptor
* result must be freed by the user using wtxResultFree(). Note that an
* event descriptor is always returned even when no real event is ready
* for the tool. In this case the event descriptor is WTX_EVENT_OTHER, 
* `addlDataLen' is 0, and `addlData' is NULL.
*
* EXPAND ../../../include/wtxmsg.h WTX_EVENT_DESC
*
* RETURNS: A pointer to the descriptor for the event received or NULL.
*
* SEE ALSO: wtxEventAdd(), wtxResultFree(), wtxStrToEventType(), 
* wtxStrToInt(), wtxStrToTgtAddr()
*/

WTX_EVENT_DESC * wtxEventGet
    (
    HWTX		hWtx		/* WTX API handle */
    )
    {
    WTX_ERROR_T			callStat;
    WTX_MSG_EVENT_DESC *	pOut;

    WTX_CHECK_CONNECTED (hWtx, NULL);

    pOut = calloc (1, sizeof (WTX_MSG_EVENT_DESC));

    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    callStat = exchange (hWtx, WTX_EVENT_GET, &hWtx->msgToolId, pOut);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);	/* Free allocated message */
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    return (&pOut->eventDesc);
    }


/*******************************************************************************
*
* wtxEventpointList - list eventpoints on the target server
*
* This routine returns a pointer to a list of all eventpoints managed
* by the target server. These include breakpoints and context exit
* notifications. The list returned is dynamically allocated and should
* be freed by calling wtxResultFree()
*
* EXPAND ../../../include/wtx.h WTX_EVTPT_LIST
*
* RETURNS: A pointer to a list of eventpoints or NULL on error.
*
* SEE ALSO: wtxBreakpointAdd(), wtxContextExitNotifyAdd()
*/

WTX_EVTPT_LIST * wtxEventpointList 
    (
    HWTX hWtx		/* WTX API handle */
    )

    {
    WTX_MSG_EVTPT_LIST * pOut;
    WTX_ERROR_T		 callStat;

    WTX_CHECK_CONNECTED (hWtx, NULL);

    pOut = calloc (1, sizeof (WTX_MSG_EVTPT_LIST));    
    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    callStat = exchange (hWtx, WTX_EVENTPOINT_LIST, &hWtx->msgToolId, pOut);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    return (WTX_EVTPT_LIST *) &pOut->nEvtpt;
    }



/*******************************************************************************
*
* wtxFileClose - close a file on the target server
*
* This routine closes the file previously opened in a call of
* wtxFileOpen() and cancels any VIO redirection caused by that open.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxFileOpen() 
*/

STATUS wtxFileClose 
    (
    HWTX	hWtx,		/* WTX API handle */
    INT32	fileDescriptor	/* file to close descriptor */
    )
    {
    WTX_MSG_RESULT	out;
    WTX_MSG_PARAM	in;
    WTX_ERROR_T		callStat;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));
    memset (&in, 0, sizeof (in));
   
    in.param.valueType = V_INT32;
    in.param.value_u.v_int32 = fileDescriptor;

    callStat = exchange (hWtx, WTX_CLOSE, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_CLOSE, &out);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxFileOpen - open a file on the target server
*
* This routine requests that the target server open a file in the host
* environment and optionally redirects I/O from a VIO channel to it. The
* user may select which VIO channel is redirected to and from the file by
* specifying the <channel> argument. 
*
* Valid values for the <flags> parameter can be:
* 
* EXPAND  ../../../include/wtxtypes.h WTX_OPEN_FLAG
*
* or host specific flags (O_RDONLY etc...) as defined in sys/fcntl.h. The 
* latter are accepted for backward compatibility but should no longer be 
* used.
*
* NOTE: <fileName> must specify a file accessible from the host where the
* target server is running.
*
* RETURNS: A file descriptor on success or WTX_ERROR if the open fails.
*
* SEE ALSO: wtxFileClose()
*/

INT32 wtxFileOpen 
    (
    HWTX	  hWtx,		/* WTX API handle */
    const char *  fileName,	/* file name */
    WTX_OPEN_FLAG flags,	/* unix style flags */
    INT32	  mode,		/* unix style mode */
    INT32	  channel	/* channel id for redirection */
    )

    {
    WTX_ERROR_T		callStat;
    WTX_MSG_OPEN_DESC	in;
    WTX_MSG_RESULT	out;	
    INT32		fileId;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (WTX_MSG_OPEN_DESC));
    memset (&out, 0, sizeof (WTX_MSG_RESULT));

    in.filename = (char *) fileName;
    in.flags = flags;
    in.mode = mode;
    in.channel = channel;

    callStat = exchange (hWtx, WTX_OPEN, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    fileId = out.val.value_u.v_int32;

    wtxExchangeFree (hWtx->server, WTX_OPEN, &out);

    return fileId;
    }

/*******************************************************************************
* 
* wtxResultFree - free the memory used by a WTX API call result
*
* This routine frees the memory allocated for the result of a WTX API
* call.  <pResult> must point to a WTX structure that was returned by
* a WTX API call.
*
* NOTE: To ensure correct and complete freeing of memory allocated to
* API call results, use wtxResultFree() to free target server call
* results before calling wtxToolDetach() and to free registry call results 
* before calling wtxTerminate().
*
* RETURNS: WTX_OK or WTX_ERROR.
*/

STATUS wtxResultFree
    (
    HWTX	hWtx,	/* WTX API handle */
    void *	pResult	/* pointer to WTX result structure */
    )
    {
    UINT32		svcNum;
    WTX_MSG_DUMMY *	pDummy;
    WTX_ERROR_T		callStat;

    WTX_CHECK_HANDLE (hWtx, WTX_ERROR);

    if (pResult == NULL)
	return (WTX_OK);

    /*
     * All results returned by API calls are pointers to within a
     * WTX_MSG_XXX struct.  To free the result we need to reconstruct
     * the origial message to get at the wtxCore field.  So we
     * calculate where the original message started and assign this
     * pointer casted as a WTX_MSG_RESULT dummy message (any will do)
     * to <pDummy>.  In calculating the offset of the first field of
     * a message the value of <pDummy> is not important since this
     * expression is statically evaluated at compile time. 
     *
     * NOTE: this code isn't as horrendous as it looks, though I admit
     * it is a bit of a low-level hack by most peoples standards.
     */
    pDummy = (WTX_MSG_DUMMY *) ((int) pResult - OFFSET (WTX_MSG_DUMMY, field));

    /* Extract the request id used to create this result */
    svcNum = pDummy->wtxCore.objId;

    if ((WTX_MSG_DUMMY *) pDummy->wtxCore.protVersion != pDummy)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_INVALID_ARG, WTX_ERROR);

    if (svcNum == WTX_INFO_GET || svcNum == WTX_INFO_Q_GET)
	/* Result of one of the registry services, use registry handle */
	callStat = wtxExchangeFree (hWtx->registry, svcNum, pDummy);
    else
	/* Result of one of the WTX target server services */
	callStat = wtxExchangeFree (hWtx->server, svcNum, pDummy);

    /* Free the memory allocated to the actual message struct */
    free (pDummy);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxGopherEval - evaluate a Gopher string on the target 
*
* This routine evaluates the Gopher string <inputString> and populates
* the Gopher result tape WTX_GOPHER_TAPE with the result
* data. It is the caller's duty to free the result tape by calling
* wtxResultFree().
*
* EXPAND ../../../include/wtxmsg.h WTX_GOPHER_TAPE
*
* The Gopher result tape is a byte-packed (opaque) data stream.  The data is a 
* series of pairs, each consisting of a type
* code and its associated data.  The type codes are defined in
* the file .../wpwr/share/src/agents/wdb/wdb.h as follows:
*
* .CS
*       /@ gopher stream format type codes @/
*
* #define GOPHER_UINT32           0
* #define GOPHER_STRING           1
* #define GOPHER_UINT16           2
* #define GOPHER_UINT8            3
* #define GOPHER_FLOAT32          4
* #define GOPHER_FLOAT64          5
* #define GOPHER_FLOAT80          6
* .CE
*
* For an example showing how to format the Gopher result tape, see
* .I API Programmer's Guide: The WTX Protocol.
*
* RETURNS: A pointer to the Gopher result tape or NULL on error.
*
* SEE ALSO:
* .I API Reference Manual: WTX Protocol WTX_GOPHER_EVAL,
* .I API Programmer's Guide: The WTX Protocol
*/

WTX_GOPHER_TAPE * wtxGopherEval 
    (
    HWTX		  hWtx,		/* WTX API handle */
    const char *	  inputString	/* Gopher program to evaluate */
    )
    {
    WTX_MSG_PARAM		in;
    WTX_MSG_GOPHER_TAPE *	pOut;
    WTX_ERROR_T			callStat;

    WTX_CHECK_CONNECTED (hWtx, NULL);

    pOut = calloc (1, sizeof (WTX_MSG_GOPHER_TAPE));
    if (pOut == NULL)	
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    memset (&in, 0, sizeof (in));

    in.param.valueType = V_PCHAR;
    in.param.value_u.v_pchar = (char *) inputString;

    callStat = exchange (hWtx, WTX_GOPHER_EVAL, &in, pOut);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);	/* Free allocated message */
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    return (&pOut->tape);
    }


/*******************************************************************************
* 
* wtxMemInfoGet - get information about the target-server-managed memory pool
*
* This routine queries the target server to find out information about
* the target-server-managed target memory pool. The result is a pointer
* to a WTX_MEM_INFO structure that must be freed by a user call to 
* wtxResultFree().
*
* EXPAND ../../../include/wtx.h WTX_MEM_INFO
*
* RETURNS: Pointer to the module info or NULL on failure. 
*
* SEE ALSO: wtxMemAlloc().
*/

WTX_MEM_INFO * wtxMemInfoGet 
    (
    HWTX		hWtx		/* WTX API handle */
    )
    {
    WTX_ERROR_T		callStat;	/* WTX status */
    WTX_MSG_MEM_INFO *	pOut;

    WTX_CHECK_CONNECTED (hWtx, NULL);
    
    pOut = calloc (1, sizeof (WTX_MSG_MEM_INFO));

    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    callStat = exchange (hWtx, WTX_MEM_INFO_GET, &hWtx->msgToolId, pOut);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);		/* free allocated message */
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    return ((WTX_MEM_INFO *) &pOut->curBytesFree);
    }


/*******************************************************************************
* 
* wtxMemAlloc - allocate a block of memory to the target-server-managed target memory pool
*
* This routine allocates <numBytes> of memory on the target. The block
* location and alignment are unspecified.
* 
* RETURNS: The address of the target memory allocated or NULL on error.
*
* SEE ALSO: wtxMemFree()
*/

TGT_ADDR_T wtxMemAlloc 
    (
    HWTX	hWtx,		/* WTX API handle */
    UINT32	numBytes	/* size to allocate in bytes */
    ) 
    {
    WTX_ERROR_T		callStat;
    WTX_MSG_PARAM	in;
    WTX_MSG_RESULT	out;
    TGT_ADDR_T		result;

    WTX_CHECK_CONNECTED (hWtx, (TGT_ADDR_T) NULL);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.param.valueType = V_UINT32;
    in.param.value_u.v_uint32 = numBytes;

    callStat = exchange (hWtx, WTX_MEM_ALLOC, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, (TGT_ADDR_T)NULL);

    result = out.val.value_u.v_tgt_addr;

    wtxExchangeFree (hWtx->server, WTX_MEM_ALLOC, &out);

    return result;
    }


/*******************************************************************************
* 
* wtxMemChecksum - perform a checksum on target memory
*
* This routine returns a checksum for <numBytes> of memory starting at
* address <startAddr>. Errors must be detected by using the wtxErrXXX()
* routines.
*
* RETURNS: A checksum value.
*/

UINT32 wtxMemChecksum
    (
    HWTX	hWtx,		/* WTX API handle */
    TGT_ADDR_T	startAddr,	/* remote addr to start checksum at */
    UINT32	numBytes	/* number of bytes to checksum */
    )
    {
    WTX_ERROR_T			callStat;
    WTX_MSG_MEM_SET_DESC	in;
    WTX_MSG_RESULT		out;
    UINT32			result;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.startAddr = startAddr;
    in.numItems = numBytes;

    callStat = exchange (hWtx, WTX_MEM_CHECKSUM, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    result = out.val.value_u.v_uint32;
    wtxExchangeFree (hWtx->server, WTX_MEM_CHECKSUM, &out);

    return result;
    }


/*******************************************************************************
* 
* wtxMemMove - move a block of target memory
*
* This routine moves <numBytes> from <srcAddr> to <destAddr>.  Note that
* the source and destination buffers may overlap.
*
* RETURNS: WTX_OK or WTX_ERROR.
*/

STATUS wtxMemMove
    (
    HWTX	hWtx,		/* WTX API handle */
    TGT_ADDR_T	srcAddr,	/* remote addr to move from */
    TGT_ADDR_T	destAddr,	/* remote addr to move to */
    UINT32	numBytes	/* number of bytes to move */
    )
    {
    WTX_ERROR_T			callStat;
    WTX_MSG_MEM_MOVE_DESC	in;
    WTX_MSG_RESULT		out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.source = srcAddr;
    in.destination = destAddr;
    in.numBytes = numBytes;

    callStat = exchange (hWtx, WTX_MEM_MOVE, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_MEM_MOVE, &out);

    return (WTX_OK);
    }


/*******************************************************************************
* 
* wtxMemFree - free a block of target memory
*
* This routine frees a target memory block previously allocated with
* wtxMemAlloc().
* 
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxMemAlloc()
*/

STATUS wtxMemFree 
    (
    HWTX	hWtx,		/* WTX API handle */
    TGT_ADDR_T	address		/* target memory block address to free */
    )
    {
    WTX_ERROR_T	callStat;
    WTX_MSG_PARAM	in;
    WTX_MSG_RESULT	out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.param.valueType = V_TGT_ADDR;
    in.param.value_u.v_tgt_addr = address;

    callStat = exchange (hWtx, WTX_MEM_FREE, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_MEM_FREE, &out);

    return (WTX_OK);
    }


/*******************************************************************************
* 
* wtxMemRead - read memory from the target
*
* This routine reads <numBytes> of memory from the target starting at 
* <fromAddr> and writes the contents to <toAddr>. 
*
* NOTE: Because the target agent tests that all memory is readable,
* this routine can never do a partial read. The return value is
* always <numBytes> or WTX_ERROR.
* 
* RETURNS: The number of bytes read (see note) or WTX_ERROR.
* 
* SEE ALSO: wtxMemWrite()
*/

UINT32 wtxMemRead 
    (
    HWTX	hWtx,		/* WTX API handle */
    TGT_ADDR_T	fromAddr,	/* Target addr to read from */
    void *	toAddr,		/* Local addr to read to */
    UINT32	numBytes	/* Bytes to read */
    )
    {
    WTX_ERROR_T			callStat;
    WTX_MSG_MEM_READ_DESC	in;
    WTX_MSG_MEM_COPY_DESC	out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.source = fromAddr;
    in.destination = (UINT32) toAddr;
    in.numBytes = numBytes;

    callStat = exchange (hWtx, WTX_MEM_READ, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_MEM_READ, &out);

    /* NOTE : WTX_MEM_READ can only read 0 or all of the bytes, hence the
     * return value is actually 0 (a status code == WTX_OK) when all is
     * well.
     */

    return numBytes;
    }


/*******************************************************************************
* 
* wtxMemWrite - write memory on the target
*
* This routine writes <numBytes> of memory to <toAddr> on the target from
* the local address <fromAddr>. 
*
* NOTE: Because the target agent tests that all memory is writable,
* this routine can never do a partial write. The return value is
* always <numBytes> or WTX_ERROR.
* 
* RETURNS: The number of bytes written (see note) or WTX_ERROR. 
*
* SEE ALSO: wtxMemRead()
*/

UINT32 wtxMemWrite 
    (
    HWTX	hWtx,		/* WTX API handle */
    void *	fromAddr,	/* Local addr to write from */
    TGT_ADDR_T	toAddr,		/* Remote addr to write to */
    UINT32	numBytes	/* Bytes to read */
    )
    {
    WTX_ERROR_T			callStat;
    WTX_MSG_MEM_COPY_DESC	in;
    WTX_MSG_RESULT		out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.source = (UINT32) fromAddr;
    in.destination = toAddr;
    in.numBytes = numBytes;

    callStat = exchange (hWtx, WTX_MEM_WRITE, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_MEM_WRITE, &out);

    /* NOTE : WTX_MEM_WRITE can only write 0 or all of the bytes, hence the
     * return value is actually 0 (a status code == WTX_OK) when all is
     * well.
     */
    return numBytes;
    }


/*******************************************************************************
* 
* wtxMemSet - set target memory to a given value
*
* This routine sets <numBytes> at address <addr> to the value <val>.
*
* RETURNS: WTX_OK or WTX_ERROR.
*/

UINT32 wtxMemSet 
    (
    HWTX	hWtx,		/* WTX API handle */
    TGT_ADDR_T	addr,		/* remote addr to write to */
    UINT32	numBytes,	/* number of bytes to set */
    UINT32	val		/* value to set */
    )
    {
    WTX_ERROR_T			callStat;
    WTX_MSG_MEM_SET_DESC	in;
    WTX_MSG_RESULT		out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.startAddr = addr;
    in.width 	= 1;
    in.numItems = numBytes;
    in.value 	= (UINT32) val;

    callStat = exchange (hWtx, WTX_MEM_SET, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_MEM_SET, &out);

    return (WTX_OK);
    }


/******************************************************************************
*
* wtxMemAddToPool - add memory to the agent pool
*
* This function adds the block of memory starting at <address> and spanning
* <size> bytes to the agent pool, enlarging it.  It is possible to enlarge
* the agent pool with memory obtained from the runtime memory manager
* or with any currently unclaimed memory.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxMemInfoGet(), wtxMemAlloc(), wtxMemRealloc(), wtxMemFree()
*/

STATUS wtxMemAddToPool
    (
    HWTX		hWtx,		/* WTX API handle */
    TGT_ADDR_T		address,	/* base of memory block to add */
    UINT32		size		/* size of memory block to add */
    )

    {
    WTX_ERROR_T		    	callStat;
    WTX_MSG_MEM_BLOCK_DESC	in;
    WTX_MSG_RESULT		out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.startAddr = address;
    in.numBytes  = size;

    callStat = exchange (hWtx, WTX_MEM_ADD_TO_POOL, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_MEM_ADD_TO_POOL, &out);

    return (WTX_OK);
    }


/******************************************************************************
*
* wtxMemRealloc - reallocate a block of target memory
*
* This function changes the size of the block starting at <address> to 
* <numBytes> bytes and returns the address of the block (which may have moved).
*
* RETURNS: The address of the target memory reallocated or NULL on error.
*
* SEE ALSO: wtxMemAlloc()
*/

TGT_ADDR_T wtxMemRealloc
    (
    HWTX		hWtx,		/* WTX API handle */
    TGT_ADDR_T		address,	/* memory block to reallocate */
    UINT32		numBytes	/* new size */
    )

    {
    WTX_ERROR_T			callStat;
    WTX_MSG_MEM_BLOCK_DESC	in;
    WTX_MSG_RESULT		out;
    TGT_ADDR_T			result;

    WTX_CHECK_CONNECTED (hWtx, (TGT_ADDR_T)NULL);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.startAddr = address;
    in.numBytes  = numBytes;

    callStat = exchange (hWtx, WTX_MEM_REALLOC, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, (TGT_ADDR_T)NULL);

    result = out.val.value_u.v_tgt_addr;
    wtxExchangeFree (hWtx->server, WTX_MEM_REALLOC, &out);

    return result;
    }

/******************************************************************************
*
* wtxMemAlign - allocate aligned target memory
*
* This function allocates a block of memory of <numBytes> bytes aligned on 
* a <alignment>-byte boundary.  <alignment> must be a power of 2.
*
* RETURNS: The address of the target memory allocated or NULL on error.
*
* SEE ALSO: wtxMemAlloc()
*/

TGT_ADDR_T wtxMemAlign
    (
    HWTX		hWtx,		/* WTX API handle */
    TGT_ADDR_T		alignment,	/* alignment boundary */
    UINT32		numBytes	/* size of block to allocate */
    )

    {
    WTX_ERROR_T			callStat;
    WTX_MSG_MEM_BLOCK_DESC	in;
    WTX_MSG_RESULT		out;
    TGT_ADDR_T			result;

    WTX_CHECK_CONNECTED (hWtx, (TGT_ADDR_T)NULL);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.startAddr = alignment;
    in.numBytes  = numBytes;

    callStat = exchange (hWtx, WTX_MEM_ALIGN, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, (TGT_ADDR_T)NULL);

    result = out.val.value_u.v_tgt_addr;
    wtxExchangeFree (hWtx->server, WTX_MEM_ALIGN, &out);

    return result;
    }

/******************************************************************************
*
* wtxMemScan - scan target memory for the presence or absence of a pattern
*
* This routine scans the target memory from <startAddr> to <endAddr>.
* When <match> is set to TRUE, the first address containing the pattern
* pointed to by <pattern> is returned.  When <match> is
* FALSE, the first address not matching <pattern> is returned.
* <pattern> is a pointer to a host array of byte values of length
* <numBytes>. If the pattern cannot be found then an error is returned.
*
* RETURNS: WTX_OK or WTX_ERROR.
*/
STATUS wtxMemScan 
    (
    HWTX		hWtx,		/* WTX API handle */
    BOOL32		match,		/* Match/Not-match pattern boolean */
    TGT_ADDR_T		startAddr,	/* Target address to start scan */
    TGT_ADDR_T		endAddr,	/* Target address to finish scan */
    UINT32		numBytes,	/* Number of bytes in pattern */
    void *		pattern,	/* Pointer to pattern to search for */
    TGT_ADDR_T *	pResult		/* Pointer to result address */
    )

    {
    WTX_ERROR_T			callStat;
    WTX_MSG_MEM_SCAN_DESC	in;
    WTX_MSG_RESULT		out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    if (pResult == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_INVALID_ARG, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.startAddr = startAddr;
    in.endAddr = endAddr;
    in.numBytes = numBytes;
    in.pattern = pattern;
    in.match = match ; 

    callStat = exchange (hWtx, WTX_MEM_SCAN, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    *pResult = out.val.value_u.v_tgt_addr;
    wtxExchangeFree (hWtx->server, WTX_MEM_SCAN, &out);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxObjModuleFindId - find the ID of an object module given its name
*
* This routine returns the ID of the object module that was loaded
* from the file with the name <moduleName>.  The object name must not
* include any directory components as this is not stored in the
* object module.
*
* RETURNS: The object module ID or WTX_ERROR.
*
* SEE ALSO: wtxObjModuleFindName(), wtxObjModuleInfoGet()
*/

UINT32	wtxObjModuleFindId 
    (
    HWTX		hWtx,		/* WTX API handle */
    const char *	moduleName	/* object module file name */
    )

    {
    WTX_MSG_MOD_NAME_OR_ID in;
    WTX_MSG_MOD_NAME_OR_ID out;
    WTX_ERROR_T		   callStat;
    UINT32		   moduleId;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.filename = (char *) moduleName;

    callStat = exchange (hWtx, WTX_OBJ_MODULE_FIND, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    moduleId = out.moduleId;

    wtxExchangeFree (hWtx->server, WTX_OBJ_MODULE_FIND, &out);

    return out.moduleId;
    }


/*******************************************************************************
*
* wtxObjModuleFindName - find object module name given its ID
*
* This routine returns the name of the object for the module that has
* the ID <moduleId>.  The name returned is the name of the object file
* from which it was loaded and does not include the directory where
* the object file was loaded. The returned string must be freed by
* the user calling wtxResultFree().
*
* RETURNS: The object module filename or NULL.
*
* SEE ALSO: wtxObjModuleFindId(), wtxObjModuleInfoGet() 
*/

char * wtxObjModuleFindName 
    (
    HWTX hWtx,			/* WTX API handle */
    UINT32 moduleId		/* id of module to find object name of */
    )

    {
    WTX_MSG_MOD_NAME_OR_ID in;
    WTX_MSG_MOD_NAME_OR_ID out;
    WTX_ERROR_T		   callStat;

    WTX_CHECK_CONNECTED (hWtx, NULL);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.moduleId = moduleId;

    callStat = exchange (hWtx, WTX_OBJ_MODULE_FIND, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, NULL);

    return out.filename;
    }




/*******************************************************************************
*
* wtxObjModuleInfoGet - return information on a module given its module ID
*
* This routine returns a pointer to a module information structure for
* the module with the supplied ID <modId>. The module information must be
* freed by the user calling wtxResultFree().
*
* EXPAND ../../../include/wtx.h WTX_MODULE_INFO
*
* where OBJ_SEGMENT is:
*
* EXPAND ../../../include/wtxmsg.h OBJ_SEGMENT
*
* RETURNS: A pointer to the module information structure or NULL on error.
*
* SEE ALSO: wtxObjModuleList() 
*/

WTX_MODULE_INFO * wtxObjModuleInfoGet 
    (
    HWTX		  hWtx,		/* WTX API handle */
    UINT32		  modId		/* id of module to look for */
    )

    {
    WTX_ERROR_T			callStat;
    WTX_MSG_MOD_NAME_OR_ID	in;
    WTX_MSG_MODULE_INFO *	pOut;

    WTX_CHECK_CONNECTED (hWtx, NULL);

    in.moduleId = modId;
    in.filename = NULL;		

    pOut = calloc (1, sizeof (WTX_MSG_MODULE_INFO));
    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    callStat = exchange (hWtx, WTX_OBJ_MODULE_INFO_GET, &in, pOut);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);		/* Free allocated message */
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    return ((WTX_MODULE_INFO *) &pOut->moduleId);
    }


/*******************************************************************************
*
* wtxObjModuleList - fetch a list of loaded object modules from the target
*
* This routine queries the target server symbol table for a list of
* loaded modules. A pointer to the module list is returned and must
* be freed by the caller using wtxResultFree().
*
* EXPAND ../../../include/wtx.h WTX_MODULE_LIST
*
* RETURNS: A pointer to the module list or NULL on error.
*
* SEE ALSO: wtxObjModuleInfoGet()
*/

WTX_MODULE_LIST * wtxObjModuleList 
    (
    HWTX		  hWtx		/* WTX API handle */
    )

    {
    WTX_ERROR_T			callStat;
    WTX_MSG_MODULE_LIST *	pOut;

    WTX_CHECK_CONNECTED (hWtx, NULL);

    pOut = calloc (1, sizeof (WTX_MSG_MODULE_LIST));
    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    callStat = exchange (hWtx, WTX_OBJ_MODULE_LIST, &hWtx->msgToolId, pOut);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);		/* Free allocated message */
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    return ((WTX_MODULE_LIST *) &pOut->numObjMod);
    }


/*******************************************************************************
*
* wtxObjModuleLoad - incrementally load a new object module
*
* This routine loads a new module onto the target and into the 
* target server module table. The caller should pass in a pointer to a
* WTX_LD_M_FILE_DESC structure:
*
* EXPAND ../../../include/wtx.h WTX_LD_M_FILE_DESC
*
* The user must set the `filename' field to the name of the file containing
* the object module and the `loadFlag' to the loader flags required (see
* loadlib.h).  When no section description is given and `nSections' is set
* to zero, the host-based loader allocates memory for the text, data,
* and bss sections of the module using memory from the target memory pool.
* If the `nSections' field is non-zero, the user can specify the location to
* load the sections and the `section' field points to an array of section
* descriptors:
*
* EXPAND ../../../include/wtxmsg.h LD_M_SECTION
*
* If the load is successful, the return value is a pointer to a
* file descriptor for the new object module containing the actual
* information about the file loaded.  If there are undefined symbols
* in the module, `undefSymList' points to a list of those symbols
* that were not resolved:
*
* EXPAND ../../../include/wtxmsg.h WTX_SYM_LIST
*
* EXPAND ../../../include/wtxmsg.h WTX_SYMBOL
*
* Use free() to free the input WTX_LD_M_FILE_DESC parameter and 
* wtxResultFree() to free the output WTX_LD_M_FILE_DESC parameter.
*
* NOTE: COFF object modules with more than 3 sections are not
* supported.
*
* RETURNS: A pointer to a WTX_LD_M_FILE_DESC for the new module or NULL on
* error.
*
* SEE ALSO: wtxObjModuleUnload(), wtxObjModuleList(), wtxObjModuleInfoGet(),
* .I API Reference Manual: Target Server Internal Routines,
* .I API Programmer's Guide: Object Module Loader
*/

WTX_LD_M_FILE_DESC * wtxObjModuleLoad 
    (
    HWTX		hWtx,		/* WTX API handle */
    WTX_LD_M_FILE_DESC *pFileDesc	/* module descriptor */
    )
    {
    WTX_ERROR_T 		callStat;
    WTX_MSG_LD_M_FILE_DESC	in;
    WTX_MSG_LD_M_FILE_DESC *	pOut;

    WTX_CHECK_CONNECTED (hWtx, NULL);

    pOut = calloc (1, sizeof (WTX_MSG_LD_M_FILE_DESC));
    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

     /*
      * XXX - must have WTX_LD_M_FILE_DESC fields identical to those of
      * WTX_MSG_LD_M_FILE_DESC from the filename field onwards. Awaits
      * change to message definitions on wtxmsg.h so this hack will go away.
      */
    memcpy (&in.filename, pFileDesc, sizeof (WTX_LD_M_FILE_DESC));

    callStat = exchange (hWtx, WTX_OBJ_MODULE_LOAD, &in, pOut);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    return ((WTX_LD_M_FILE_DESC *) &pOut->filename);
    }


/******************************************************************************
*
* wtxObjModuleUndefSymAdd - add a undefined symbol to the undefined symbol list 
*
* This routine adds the symbol specified by <symId> to the corresponding
* module's undefined symbol list.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* NOMANUAL
*/

STATUS wtxObjModuleUndefSymAdd
    (
    HWTX		hWtx,		/* WTX API handle */
    char *		symName,	/* undefined symbol name */
    UINT32		symGroup	/* undefined symbol group */
    )
    {
    WTX_ERROR_T         callStat;
    WTX_MSG_SYMBOL_DESC in;
    WTX_MSG_RESULT      out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.symbol.name = symName;
    in.symbol.group = symGroup;

    callStat = exchange (hWtx, WTX_OBJ_MODULE_UNDEF_SYM_ADD, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);
    
    return (WTX_OK);
    }

/*******************************************************************************
*
* wtxObjModuleUnload - unload an object module from the target
*
* This routine unloads the module specified by <moduleId> from the target.
* The module ID is returned when the module is loaded or by one of the
* information routines.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxObjModuleLoad(), wtxObjModuleList(), wtxObjModuleInfoGet()
*/

STATUS wtxObjModuleUnload
    (
    HWTX	hWtx,		/* WTX API handle */
    UINT32	moduleId	/* id of module to unload */
    )

    {
    WTX_ERROR_T		callStat;
    WTX_MSG_PARAM	in;
    WTX_MSG_RESULT	out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.param.value_u.v_uint32 = moduleId;
    in.param.valueType = V_UINT32;

    callStat = exchange (hWtx, WTX_OBJ_MODULE_UNLOAD, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    return (WTX_OK);
    }



/*******************************************************************************
*
* wtxRegisterForEvent - ask the WTX server to send events matching a regular expression
*
* This routine takes a string <regExp>, which is a regular expression,
* and uses it to specify which events this user is interested in. By
* default a WTX client receives no event notifications.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxEventGet()
*/

STATUS wtxRegisterForEvent 
    (
    HWTX	 hWtx,		/* WTX API handle */
    const char * regExp		/* Regular expression to select events */
    )
    {
    WTX_ERROR_T		callStat;
    WTX_MSG_EVENT_REG_DESC	in;
    WTX_MSG_RESULT		out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));
    memset (&in, 0, sizeof (in));

    in.evtRegExp = (char *) regExp;

    callStat = exchange (hWtx, WTX_REGISTER_FOR_EVENT, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_REGISTER_FOR_EVENT, &out);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxRegsGet - read register data from the target
*
* This routine reads <numBytes> of raw (target format) register data
* from the register set <regSet> starting from the byte at offset
* <firstByte>. The data read are stored in local memory at <regMemory>.
*
* EXPAND ../../../include/wtxtypes.h WTX_REG_SET_TYPE
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxRegsSet()
*/

STATUS wtxRegsGet 
    (
    HWTX		hWtx,		/* WTX API handle */
    WTX_CONTEXT_TYPE	contextType,	/* context type to get regs of */
    WTX_CONTEXT_ID_T	contextId,	/* context id to get regs of */
    WTX_REG_SET_TYPE	regSet,		/* type of register set */
    UINT32		firstByte,	/* first byte of register set */
    UINT32		numBytes,	/* number of bytes of register set */
    void *		regMemory	/* place holder for reg. values */
    )
    {
    WTX_MSG_MEM_XFER_DESC	out;
    WTX_MSG_REG_READ		in;
    WTX_ERROR_T			callStat;
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));
    memset (&in, 0, sizeof (in));

    in.context.contextType = contextType;
    in.context.contextId = contextId;
    in.regSetType = regSet;
    in.memRegion.baseAddr = (TGT_ADDR_T) firstByte;
    in.memRegion.size = numBytes;

    /* NOTE: This relies on XDR to allocate memory to write register info to */

    callStat = exchange (hWtx, WTX_REGS_GET, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    /* WTX_REGS_GET is a pain because it may not set the error flag */
    if (out.memXfer.numBytes != numBytes)
	{
	wtxExchangeFree (hWtx->server, WTX_REGS_GET, &out);
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_REGS_GET_PARTIAL_READ, WTX_ERROR);
	}
	
    memcpy(regMemory, out.memXfer.source, out.memXfer.numBytes);
    wtxExchangeFree (hWtx->server, WTX_REGS_GET, &out);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxRegsSet - write to registers on the target
*
* This routine writes <numBytes> of raw (target format) register data
* to register set <regSet> starting at offset <firstByte>. Data is
* written from local memory at <regMemory>.
*
* EXPAND ../../../include/wtxtypes.h WTX_REG_SET_TYPE
*
* RETURNS: WTX_OK or WTX_ERROR if the register set fails.
*/

STATUS wtxRegsSet 
    (
    HWTX		hWtx,		/* WTX API handle */
    WTX_CONTEXT_TYPE	contextType,	/* context type to set regs of */
    WTX_CONTEXT_ID_T	contextId,	/* context id to set regs of */
    WTX_REG_SET_TYPE	regSet,		/* type of register set */
    UINT32		firstByte,	/* first byte of reg. set */
    UINT32		numBytes,	/* number of bytes in reg. set. */
    void *		regMemory	/* register contents */
    )

    {
    WTX_MSG_RESULT	out;
    WTX_MSG_REG_WRITE	in;
    WTX_ERROR_T		callStat;
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));
    memset (&in, 0, sizeof (in));

    in.context.contextId = contextId;
    in.context.contextType = contextType;
    in.regSetType = regSet;
    in.memXfer.destination = (TGT_ADDR_T) firstByte;
    in.memXfer.numBytes = numBytes;
    in.memXfer.source = (char *) regMemory;
  
    callStat = exchange (hWtx, WTX_REGS_SET, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_REGS_SET, &out);

    return (WTX_OK);
    }



/*******************************************************************************
*
* wtxStrToTgtAddr - convert a string argument to a TGT_ADDR_T value
*
* This routine takes a string and converts it to a TGT_ADDR_T.  The string
* is part of an event string.  See wtxEventGet() and the WTX library 
* discussion of WTX events in the \f2API Reference Manual: WTX Protocol\fP.
* 
* RETURNS: The address as a TGT_ADDR_T value.
*/

TGT_ADDR_T wtxStrToTgtAddr 
    (
    HWTX	hWtx,		/* WTX API handle */
    const char *str		/* string */
    )
    {
    WTX_CHECK_HANDLE (hWtx, (TGT_ADDR_T)NULL);
    return (TGT_ADDR_T) strtoul (str, NULL, 16); /* Base 16 read */
    }

/*******************************************************************************
*
* wtxStrToContextId - convert a string argument to a WTX_CONTEXT_ID_T
*
* This routine takes a string and converts it to a context ID.  The string
* is part of an event string.  See wtxEventGet() and the WTX library 
* discussion of WTX events in the \f2API Reference Manual: WTX Protocol\fP.
* 
* RETURNS: The context ID.
*/

WTX_CONTEXT_ID_T wtxStrToContextId 
    (
    HWTX	hWtx,		/* WTX API handle */
    const char *str		/* string */
    )
    {
    WTX_CHECK_HANDLE (hWtx, (TGT_ADDR_T)NULL);
    return (WTX_CONTEXT_ID_T) strtoul (str, NULL, 16); /* Hex read */
    }

/*******************************************************************************
*
* wtxStrToContextType - convert a string argument to a WTX_CONTEXT_TYPE value
*
* This routine takes a string and converts it to a WTX_CONTEXT_TYPE
* enumeration value.  The string is part of an event string.  See
* wtxEventGet() and the WTX library discussion of WTX events in the \f2API
* Reference Manual: WTX Protocol\fP.
* 
* RETURNS: The context type or WTX_ERROR on error.
*/

WTX_CONTEXT_TYPE wtxStrToContextType 
    (
    HWTX	 hWtx,		/* WTX API handle */
    const char * str		/* string */
    )
    {
    INT32 value;

    WTX_CHECK_HANDLE (hWtx, WTX_ERROR);

    value = (INT32) strtol (str, NULL, 16); /* Hex read */
    
    if (value < WTX_CONTEXT_SYSTEM || value > WTX_CONTEXT_ISR_ANY)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_INVALID_ARG, WTX_ERROR);
    else
	return (WTX_CONTEXT_TYPE) value;
    }


/*******************************************************************************
*
* wtxStrToInt32 - convert a string argument to an INT32 value
*
* This routine takes a string and converts it to a signed host integer.  The
* string is part of an event string.  See wtxEventGet() and the WTX library
* discussion of WTX events in the \f2API Reference Manual: WTX Protocol\fP.
* 
* RETURNS: The string as an INT32 value.
*/

INT32 wtxStrToInt32 
    (
    HWTX	hWtx,		/* WTX API handle */
    const char *str		/* string */
    )
    {
    return (INT32) strtol (str, NULL, 16); /* Base 16 read */
    }


/*******************************************************************************
*
* wtxStrToEventType - convert a string to a WTX event enumeration type
*
* This routine is a type converter for the event strings passed
* to a WTX client by the target server. It converts back to the
* event enumeration type so event types can be switched on.
*
* If the string is NULL, WTX_EVT_T_NONE is returned.  If
* the string does not match any of the pre-defined events,
* WTX_EVT_T_OTHER is returned.
*
* RETURNS: The event type or WTX_EVT_T_INVALID on error.  
*/

WTX_EVENT_TYPE wtxStrToEventType 
    (
    HWTX	hWtx,		/* WTX API handle */
    const char *str		/* string */
    )
    {
    WTX_CHECK_HANDLE (hWtx, WTX_EVENT_INVALID);

    if (str == NULL)
	return WTX_EVENT_NONE;
    else if (STREQ (str, WTX_EVT_TGT_RESET))
	return WTX_EVENT_TGT_RESET;
    else if (STREQ (str, WTX_EVT_SYM_ADDED))
	return WTX_EVENT_SYM_ADDED;
    else if (STREQ (str,WTX_EVT_SYM_REMOVED))
	return WTX_EVENT_SYM_REMOVED;
    else if (STREQ (str,WTX_EVT_OBJ_LOADED))
	return WTX_EVENT_OBJ_LOADED;
    else if (STREQ (str,WTX_EVT_OBJ_UNLOADED))
	return WTX_EVENT_OBJ_UNLOADED;
    else if (STREQ (str,WTX_EVT_CTX_START))
	return WTX_EVENT_CTX_START;
    else if (STREQ (str,WTX_EVT_CTX_EXIT))
	return WTX_EVENT_CTX_EXIT;
    else if (STREQ (str,WTX_EVT_EXCEPTION))
	return WTX_EVENT_EXCEPTION;
    else if (STREQ (str,WTX_EVT_VIO_WRITE))
	return WTX_EVENT_VIO_WRITE;
    else if (STREQ (str,WTX_EVT_TOOL_ATTACH))
	return WTX_EVENT_TOOL_ATTACH;
    else if (STREQ (str,WTX_EVT_TOOL_DETACH))
	return WTX_EVENT_TOOL_DETACH;
    else if (STREQ (str,WTX_EVT_TOOL_MSG))
	return WTX_EVENT_TOOL_MSG;
    else if (STREQ (str,WTX_EVT_TEXT_ACCESS))
	return WTX_EVENT_TEXT_ACCESS;
    else if (STREQ (str,WTX_EVT_DATA_ACCESS))
	return WTX_EVENT_DATA_ACCESS;
    else if (STREQ (str,WTX_EVT_CALL_RETURN))
	return WTX_EVENT_CALL_RETURN;
    else if (STREQ (str,WTX_EVT_USER))
	return WTX_EVENT_USER;
    else if (STREQ (str,WTX_EVT_UNKNOWN))
	return WTX_EVENT_UNKNOWN;
    else
	return WTX_EVENT_OTHER;
    }

/******************************************************************************
*
* wtxServiceAdd - add a new service to the agent
*
* This command adds a new service to the target server. The service is 
* provided in WDB- and WTX-level object modules. The WDB object module is 
* downloaded to the target, and the WTX object module is dynamically linked
* to the target server. 
* 
* The <wtxInProcName> and <wtxOutProcName> arguments are the names of 
* known structure filter procedures used to exchange data with the new
* service.
*
* <wtxObjFile> is the name of a dynamically loadable library file that
* contain the WTX service routine, the service initialization routine, and
* XDR filters code for the service input and output parameters.
* 
* Upon success the service number to be used for future requests to the newly
* added service is returned in <mySvcNumber>.
*
* Example:
* .CS
*
*   /@ 
*    * Add a WTX service called mySvc and get the service number in 
*    * mySvcNumber.
*    @/
*
*   if (wtxServiceAdd 
*           (
*           wtxh, 		       /@ our tool handle @/
*           &mySvcNumber, 	       /@ where to return service num. @/
*           NULL, NULL, NULL, NULL,    /@ no WDB items @/
*           "mySvc.so", 	       /@ new service DLL @/
*           "mySvcName", 	       /@ service routine name @/
*           "xdr_WTX_MY_SVC_IN_PARAM", /@ input param XDR filter @/
*           "xdr_WTX_MY_SVC_OUT_PARAM" /@ output param XDR filter @/
*           ) != OK)
*       {
*       printf("Error: cannot add mySvc service:%s\n",wtxErrMsgGet(wtxh));
*       wtxTerminate (wtxh);		/@ terminate tool connection @/
*       exit(0);
*       }
*
*     ...
*
*   /@ get our client handle in order to call the newly added service @/
*
*   pClient = (CLIENT *) wtxh->server->transport;
*
*   /@ set client call timeout @/
*
*   timeout.tv_sec = 10;
*   timeout.tv_usec = 0;
*
*   /@ Call the newly added service @/
*
*   rpcStat = clnt_call (           
*       pClient,                                /@ client handle @/
*       mySvcNumber,                            /@ service number @/
*       xdr_WTX_MY_SVC_IN_PARAM,                /@ request XDR filter @/
*       (char *) pIn,                           /@ ptr to input data @/
*       xdr_WTX_MY_SVC_OUT_PARAM,               /@ reply XDR filter @/
*       (char *) pOut,                          /@ ptr to result @/
*       timeout                                 /@ request timeout value @/
*       );
*
* .CE
*
* WARNING: In the Tornado 1.0 release, wtxServiceAdd() can only add WTX 
* services that do not require an additional WDB service.  The <wdbSvcNum>,
* <wdbName>, <wdbObjFile> and <wdbSvcInitRtn> parameters must be set to NULL.
* 
* RETURNS: WTX_OK or WTX_ERROR.
*/

STATUS wtxServiceAdd
    (
    HWTX        hWtx,           /* WTX API handle */
    UINT32 *	wtxSvcNum,	/* where to return WTX RPC service number */
    UINT32	wdbSvcNum,	/* WDB RPC service number */
    char *      wdbName,        /* WDB service name */
    char *      wdbObjFile,     /* WDB service object module */
    char *      wdbSvcInitRtn,  /* WDB svc initialization routine name */
    char *      wtxObjFile,     /* WTX xdr/service DLL file */
    char *      wtxName,        /* WTX service routine name */
    char *      wtxInProcName,  /* WTX service input xdr procedure name */
    char *      wtxOutProcName  /* WTX service output xdr procedure name */
    )
    {
    WTX_MSG_SERVICE_DESC        in;
    WTX_MSG_RESULT              out;
    WTX_ERROR_T                 callStat;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.pWtxServiceDesc = (WTX_WTX_SERVICE_DESC *)
                         malloc (sizeof (WTX_WTX_SERVICE_DESC));
    in.pWdbServiceDesc = (WTX_WDB_SERVICE_DESC *)
                         malloc (sizeof (WTX_WDB_SERVICE_DESC));

    if ((in.pWtxServiceDesc == NULL) || (in.pWdbServiceDesc == NULL))
        WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, WTX_ERROR);

    in.pWtxServiceDesc->svcObjFile = wtxObjFile;
    in.pWtxServiceDesc->svcProcName = wtxName;
    in.pWtxServiceDesc->inProcName = wtxInProcName;
    in.pWtxServiceDesc->outProcName = wtxOutProcName;

    in.pWdbServiceDesc->rpcNum = wdbSvcNum;
    in.pWdbServiceDesc->name = wdbName;
    in.pWdbServiceDesc->svcObjFile = wdbObjFile;
    in.pWdbServiceDesc->initRtnName = wdbSvcInitRtn;

    callStat = exchange (hWtx, WTX_SERVICE_ADD, &in, &out);

    if (callStat != WTX_ERR_NONE)
        WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    *wtxSvcNum = out.val.value_u.v_uint32;

    wtxExchangeFree (hWtx->server, WTX_SERVICE_ADD, &out);

    return WTX_OK;
    }

/******************************************************************************
*
* wtxSymAdd - add a symbol with the given name, value, and type
*
* This routine adds a new symbol with the specified name, value, and type to 
* the target server symbol table.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxSymFind(), wtxSymListGet(), wtxSymRemove()
*/

STATUS wtxSymAdd
    (
    HWTX		hWtx,	/* WTX API handle */
    const char *	name,	/* name of symbol to add */
    TGT_ADDR_T		value,	/* value of symbol to add */
    UINT8 		type	/* type of symbol to add */
    )

    {
    WTX_MSG_SYMBOL_DESC	in;		/* input to WTX call */
    WTX_MSG_RESULT 	out;
    UINT32 		result;
    WTX_ERROR_T		callStat;	/* client status */
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.symbol.name = (char *) name;
    in.symbol.value = value;
    in.symbol.type = type;

    callStat = exchange (hWtx, WTX_SYM_ADD, &in, &out);	

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    result = out.val.value_u.v_uint32;
    wtxExchangeFree (hWtx->server, WTX_SYM_ADD, &out);

    return (result);
    }

/******************************************************************************
*
* wtxSymAddWithGroup - add a symbol with the given name, value, type and group
*
* This routine adds a new symbol with the specified name, value, type and 
* group to the target server symbol table.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxSymFind(), wtxSymListGet(), wtxSymRemove()
*/

STATUS wtxSymAddWithGroup
    (
    HWTX		hWtx,	/* WTX API handle */
    const char *	name,	/* name of symbol to add */
    TGT_ADDR_T		value,	/* value of symbol to add */
    UINT8 		type,	/* type of symbol to add */
    UINT16		group	/* group of symbol to add */
    )

    {
    WTX_MSG_SYMBOL_DESC	in;		/* input to WTX call */
    WTX_MSG_RESULT 	out;
    UINT32 		result;
    WTX_ERROR_T		callStat;	/* client status */
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.symbol.name = (char *) name;
    in.symbol.value = value;
    in.symbol.type = type;
    in.symbol.group = group;

    callStat = exchange (hWtx, WTX_SYM_ADD, &in, &out);	

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    result = out.val.value_u.v_uint32;
    wtxExchangeFree (hWtx->server, WTX_SYM_ADD, &out);

    return (result);
    }

/*******************************************************************************
* 
* wtxSymFind - find information on a symbol given its name or value
*
* This routine searches for a symbol which matches the supplied
* search criteria.  If <symName> is non-NULL, the search is for a symbol
* whose name matches <symName>.  If <symName> is NULL, the 
* search is for one with value <symValue>.  When searching by name,
* the <exactName> flag is used to control whether the name must exactly
* match <symName> or only partially.  In both value and name searches,
* a symbol type <symType> can be supplied to further refine the search.
* Valid symbol types are defined in a_out.h.  To prevent the type being
* considered in the search set <typeMask> to 0.
*
* The result of the search is a pointer to a symbol which 
* must be freed by the user calling wtxResultFree().
*
* EXPAND ../../../include/wtxmsg.h WTX_SYMBOL
*
* RETURNS: A pointer to the symbol or NULL on error.
*
* SEE ALSO: wtxResultFree().
*/

WTX_SYMBOL * wtxSymFind
    (
    HWTX			hWtx,		/* WTX API handle */
    const char *		symName,	/* name of symbol */
    TGT_ADDR_T			symValue,	/* value of symbol */
    BOOL32			exactName,	/* must match name exactly */
    UINT8			symType,	/* type of symbol */
    UINT8			typeMask	/* mask to select type bits */
    )
    {
    WTX_MSG_SYMBOL_DESC		in;		/* input to WTX call */
    WTX_MSG_SYMBOL_DESC *	pOut;		/* result pointer */
    WTX_ERROR_T			callStat;	/* client status */
    
    WTX_CHECK_CONNECTED (hWtx, NULL);

    pOut = calloc (1, sizeof (WTX_MSG_SYMBOL_DESC));
    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    memset (&in, 0, sizeof (in));

    in.symbol.name = (char *) symName;
    in.symbol.exactName = exactName;
    in.symbol.value = symValue;
    in.symbol.type = symType;
    in.symbol.typeMask = typeMask;

    callStat = exchange (hWtx, WTX_SYM_FIND, &in, pOut);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);		/* Free allocated message */
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    return (&pOut->symbol);
    }    

/*******************************************************************************
*
* wtxSymListGet - get a list of symbols matching the given search criteria
*
* This routine gets a list of symbols matching given search criteria.
* <substring> is a symbol substring to match and <value> is a target symbol
* address value to search around.  Either <string> or <value> should be set
* to a non-NULL value, but not both. In addition, if <listUnknown> is set to
* TRUE then only unknown symbols are listed and <substring> and <value> are
* ignored.  If <moduleName> is non-NULL, it specifies the module to search.
* Even if no symbols match the search parameters, the pointer returned is
* not NULL. It points to a WTX_SYM_LIST with a NULL `pSymbol' field.
*
* The return value must be freed by the caller using wtxResultFree().
*
* EXPAND ../../../include/wtxmsg.h WTX_SYM_LIST
*
* EXPAND ../../../include/wtxmsg.h WTX_SYMBOL
*
* RETURNS: A pointer to a list of symbols or NULL on error.
* 
* SEE ALSO: wtxResultFree()
*/

WTX_SYM_LIST * wtxSymListGet 
    (
    HWTX	hWtx,			/* WTX API handle */
    const char *substring,		/* Symbol name substring to match */
    const char *moduleName,		/* Module name to search in */
    TGT_ADDR_T	value,			/* Symbol value to match */
    BOOL32	listUnknown		/* List unknown symbols only flag */
    )

    {
    WTX_MSG_SYM_MATCH_DESC	in;
    WTX_MSG_SYM_LIST *		pOut;
    WTX_MSG_SYM_LIST		out;
    WTX_SYMBOL *		firstSym = NULL;
    WTX_SYMBOL *		lastSym;
    WTX_ERROR_T			callStat;
    
    WTX_CHECK_CONNECTED (hWtx, NULL);

    if (substring != NULL && (void*)value != NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_INVALID_ARG, NULL);

    memset (&in, 0, sizeof (in));
    pOut = calloc (1, sizeof (WTX_MSG_SYM_LIST));
    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    in.symTblId = 0;	/* Use default target symbol table */
    in.matchString = (substring != NULL);
    in.adrs = value;
    in.stringToMatch = (char *) substring;
    in.byModuleName = TRUE;
    in.module.moduleName = (char *) moduleName;
    in.listUnknownSym = listUnknown;
    in.giveMeNext = FALSE;

    lastSym = NULL;
    do
	{
	memset (&out, 0, sizeof (out));	/* Zero output */

	callStat = exchange (hWtx, WTX_SYM_LIST_GET, &in, &out);

	if (callStat != WTX_ERR_NONE)
	    {
	    wtxExchangeFree (hWtx->server, WTX_SYM_LIST_GET, pOut);
	    free (pOut);
	    WTX_ERROR_RETURN (hWtx, callStat, NULL);
	    }
	
	if (lastSym == NULL)
	    {
	    /* this is the first query */
	    firstSym = out.symList.pSymbol;
	    lastSym = firstSym;
	    }
	else
	    {
            /* skip to end of the previous query list */
	    while (lastSym->next != NULL) 
		lastSym = lastSym->next;
	    /* join this one onto the end of it */
	    lastSym->next = out.symList.pSymbol;
	    }

	/* Ensure next time around, if any gets the remainng symbols */
	in.giveMeNext = TRUE;

	} while (out.moreToCome == TRUE);

    /* Set up pOut so that it can be freed by wtxResultFree() */
    pOut->wtxCore.protVersion = (UINT32) pOut;
    pOut->wtxCore.objId = WTX_SYM_LIST_GET;

    /* Then set the symbol pointer to the first symbol in the list */
    pOut->symList.pSymbol = firstSym;

    return &pOut->symList;
    }

/*******************************************************************************
*
* wtxSymRemove - remove a symbol from the default target server symbol table
*
* This routine removes a symbol from the default target server symbol table.
* <symName> and <symType> identify the symbol to remove.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxSymAdd(), wtxSymFind(), wtxSymListGet()
*/

STATUS wtxSymRemove 
    (
    HWTX	hWtx,		/* WTX API handle */
    const char *symName,	/* Name of symbol to remove */
    UINT8	symType		/* Type of symbol to remove */
    )

    {
    WTX_MSG_SYMBOL_DESC	in;		/* input to WTX call */
    WTX_MSG_RESULT	out;		/* result pointer */
    WTX_ERROR_T		callStat;	/* client status */
    
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.symbol.name = (char *) symName;
    in.symbol.type = symType;

    callStat = exchange (hWtx, WTX_SYM_REMOVE, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_SYM_REMOVE, &out);

    return WTX_OK;
    }

/*******************************************************************************
*
* wtxSymTblInfoGet - return information about the target server symbol table
*
* This routine queries the target server to find out information about its
* symbol table. The return value must be freed by the caller using
* wtxResultFree().
*
* EXPAND ../../../include/wtxmsg.h WTX_SYM_TBL_INFO
*
* RETURNS: A pointer to the target server symbol-table information structure
* or NULL on error.
*/

WTX_SYM_TBL_INFO * wtxSymTblInfoGet
    (
    HWTX        hWtx    /* WTX API handle */
    )
    {
    WTX_MSG_SYM_TBL_INFO *      pOut;
    WTX_ERROR_T                 callStat;

    WTX_CHECK_CONNECTED (hWtx, NULL);

    pOut = calloc (1, sizeof (WTX_MSG_SYM_TBL_INFO));
    if (pOut == NULL)
        WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    callStat = exchange (hWtx, WTX_SYM_TBL_INFO_GET, &hWtx->msgToolId, pOut);

    if (callStat != WTX_ERR_NONE)
        {
        free (pOut);
        WTX_ERROR_RETURN (hWtx, callStat, NULL);
        }

    return ((WTX_SYM_TBL_INFO *) &(pOut->symTblId));
    }


/*******************************************************************************
*
* wtxTargetReset - reset the target 
*
* This routine resets the target as if it was manually rebooted.
* The target server restarts itself and if the reboot is successful,
* it reconnects to the target. If the call is successful a target
* reset event, TGT_RESET, is generated and sent to all clients
* registered to receive them. 
*
* NOTE: The client making the request must reconnect to the target
* server as restarting the server causes the server connection to
* be broken.
*
* RETURNS: WTX_OK or WTX_ERROR on failure.
*/

STATUS wtxTargetReset 
    (
    HWTX	hWtx	/* WTX API handle */
    )
    {
    WTX_ERROR_T	callStat;
    WTX_MSG_RESULT	out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));

    callStat = exchange (hWtx, WTX_TARGET_RESET, &hWtx->msgToolId, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_TARGET_RESET, &out);

    return (WTX_OK);
    }


/******************************************************************************
*
* wtxTsNameGet - get the full name of the currently attached target server
*
* This routine returns the full name of the target server to which the
* handle <hWtx> is attached (if any).  The string is an internal one and
* must not be freed by the caller.
*
* RETURNS: The target server name string or NULL if not connected.
*/

const char * wtxTsNameGet
    (
    HWTX	hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_HANDLE (hWtx, NULL);

    if (wtxToolConnected (hWtx))
	return hWtx->pServerDesc->wpwrName;
    else
	return NULL;
    }

/*******************************************************************************
*
* wtxTargetRtTypeGet - get the target-runtime-type information
*
* This routine returns a numeric value indicating the runtime type
* as returned by the target agent.  
*
* RETURNS: The runtime type code as a UINT32 or WTX_ERROR on error.
*/
UINT32 wtxTargetRtTypeGet 
    (
    HWTX hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    if (hWtx->pTsInfo == NULL && wtxTsInfoGet (hWtx) == NULL)
	/* Error has already been dispatched, just return WTX_ERROR */
	return WTX_ERROR;
    
    return hWtx->pTsInfo->tgtInfo.rtInfo.rtType;
    }

/*******************************************************************************
*
* wtxTargetRtVersionGet - get the target-runtime-version information
*
* This routine returns a string containing the version information for
* the runtime of the current target.  The return value is a pointer to the
* string in temporary memory; the string must be copied if its value is to be 
* stored.
*
* RETURNS: The version string or NULL on error.
*/
const char * wtxTargetRtVersionGet 
    (
    HWTX hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_CONNECTED (hWtx, NULL);

    if (hWtx->pTsInfo == NULL && wtxTsInfoGet (hWtx) == NULL)
	/* Error has already been dispatched, just return NULL */
	return NULL;
    
    return hWtx->pTsInfo->tgtInfo.rtInfo.rtVersion;
    }

/*******************************************************************************
*
* wtxTargetCpuTypeGet - get the target CPU type code
*
* This routine returns a numeric value indicating the type of the CPU
* as returned by the target agent.  
*
* RETURNS: The CPU type code as a UINT32 or WTX_ERROR on error.
*/
UINT32 wtxTargetCpuTypeGet 
    (
    HWTX hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    if (hWtx->pTsInfo == NULL && wtxTsInfoGet (hWtx) == NULL)
	/* Error has already been dispatched, just return WTX_ERROR */
	return WTX_ERROR;
    
    return hWtx->pTsInfo->tgtInfo.rtInfo.cpuType;
    }

/*******************************************************************************
*
* wtxTargetHasFppGet - check if the target has a floating point processor
*
* This routine returns a boolean indicating whether the current target has a
* floating point processor available. Errors must be detected using
* wtxErrClear() and wtxErrGet().
*
* RETURNS: TRUE if it has a floating point processor or FALSE if not or if 
* there was an error.
*/
BOOL32 wtxTargetHasFppGet 
    (
    HWTX hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_CONNECTED (hWtx, FALSE);

    if (hWtx->pTsInfo == NULL && wtxTsInfoGet (hWtx) == NULL)
	/* Error has already been dispatched, just return WTX_ERROR */
	return FALSE;
    
    return hWtx->pTsInfo->tgtInfo.rtInfo.hasFpp;
    }

/*******************************************************************************
*
* wtxTargetEndianGet - get the endianness of the target CPU
*
* This routine returns WTX_ENDIAN_BIG if the target has a CPU that uses
* big-endian byte storage ordering (the most significant byte first) or 
* WTX_ENDIAN_LITTLE if it uses little-endian ordering (the least significant
* byte first).  If an error occurs, the routine returns WTX_ENDIAN_UNKNOWN.
*
* EXPAND ../../../include/wtx.h WTX_ENDIAN_T
*
* RETURNS: The CPU endian value or WTX_ENDIAN_UNKNOWN.
*/
WTX_ENDIAN_T wtxTargetEndianGet 
    (
    HWTX hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_CONNECTED (hWtx, WTX_ENDIAN_UNKNOWN);

    if (hWtx->pTsInfo == NULL && wtxTsInfoGet (hWtx) == NULL)
	/* Error has already been dispatched, just return error value */
	return WTX_ENDIAN_UNKNOWN;
    
    switch (hWtx->pTsInfo->tgtInfo.rtInfo.endian)
	{
	case 1234:
	    return WTX_ENDIAN_BIG;
	case 4321:
	    return WTX_ENDIAN_LITTLE;
	default:
	    return WTX_ENDIAN_UNKNOWN;
	}
    }

/*******************************************************************************
*
* wtxTargetBootlineGet - get the target bootline information string
*
* This routine returns a string containing the target bootline.  The
* return value is a pointer to the string in temporary memory; the string
* must be copied if it is to be stored.
*
* RETURNS: The bootline string or NULL on error.  
*/
const char * wtxTargetBootlineGet 
    (
    HWTX hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_CONNECTED (hWtx, NULL);

    if (hWtx->pTsInfo == NULL && wtxTsInfoGet (hWtx) == NULL)
	/* Error has already been dispatched, just return NULL */
	return NULL;
    
    return hWtx->pTsInfo->tgtInfo.rtInfo.bootline;
    }

/*******************************************************************************
*
* wtxTargetBspNameGet - get the target board-support-package name string
*
* This routine returns a string containing the board-support-package name for
* the runtime of the current target.  The return value is a pointer to 
* the string in temporary memory; the string must be copied if it is to be 
* stored.
*
* RETURNS: The BSP name string or NULL on error.
*/
const char * wtxTargetBspNameGet 
    (
    HWTX hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_CONNECTED (hWtx, NULL);

    if (hWtx->pTsInfo == NULL && wtxTsInfoGet (hWtx) == NULL)
	/* Error has already been dispatched, just return NULL */
	return NULL;
    
    return hWtx->pTsInfo->tgtInfo.rtInfo.bspName;
    }

/*******************************************************************************
*
* wtxToolNameGet - return the name of the current tool
*
* This function gets a string representing the name of the current tool.
* The return value is a pointer to the string in temporary memory; the string
* must be copied if it is to be stored.
*
* RETURNS: The tool name string or NULL on error.
*/

char * wtxToolNameGet
    (
    HWTX        hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_CONNECTED (hWtx, NULL);

    if (hWtx->pToolDesc != NULL)
        return hWtx->pToolDesc->toolName;
    else
        return NULL;
    }

/******************************************************************************
*
* wtxTsVersionGet - return the Tornado version
*
* This function gets a string representing the Tornado version.
* The return value is a pointer to temporary memory and must be copied if it is
* to be stored.
*
* RETURNS: A pointer to the Tornado version string or NULL on error.
*/

char * wtxTsVersionGet
    (
    HWTX        hWtx	/* WTX API handle */
    )
    {
    WTX_CHECK_CONNECTED (hWtx, NULL);

    if (hWtx->pTsInfo == NULL && wtxTsInfoGet (hWtx) == NULL)
        /* Error has already been dispatched, just return NULL */
        return NULL;

    return hWtx->pTsInfo->version;
    }

/******************************************************************************
*
* wtxTsKill - kill the target server
*
* This routine kills the target server.  The client detaches from the
* target server at this time.  Another attachment can subsequently be
* made.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxToolAttach()
*/

STATUS wtxTsKill
    (
    HWTX	hWtx	/* WTX API handle */
    )

    {
    WTX_ERROR_T		callStat;	/* WTX RPC status */
    WTX_MSG_KILL_DESC	in;		/* WTX kill message */
    WTX_MSG_RESULT	out;		/* WTX result message */
    
    WTX_CHECK_CONNECTED (hWtx, (TGT_ADDR_T)NULL);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.request = WTX_OBJ_KILL_DESTROY;
    callStat = exchange (hWtx, WTX_OBJ_KILL, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_OBJ_KILL, &out);

    toolCleanup(hWtx);

    return (WTX_OK);
    }

/******************************************************************************
*
* wtxTsRestart - restart the target server
*
* This routine restarts the target server.  The client detaches from the
* target server at this time.  Another attachment can subsequently be
* made.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxToolAttach()
*/

STATUS wtxTsRestart
    (
    HWTX	hWtx	/* WTX API handle */
    )

    {
    WTX_ERROR_T		callStat;	/* WTX RPC status */
    WTX_MSG_KILL_DESC	in;		/* WTX kill message */
    WTX_MSG_RESULT	out;		/* WTX result message */
    
    WTX_CHECK_CONNECTED (hWtx, (TGT_ADDR_T)NULL);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.request = WTX_OBJ_KILL_RESTART;
    callStat = exchange (hWtx, WTX_OBJ_KILL, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_OBJ_KILL, &out);

    toolCleanup(hWtx);

    return (WTX_OK);
    }

/******************************************************************************
*
* wtxFuncCall - call a function on the target
*
* This routine calls the function identified by WTX_CONTEXT_DESC.
* 
* EXPAND ../../../include/wtx.h WTX_CONTEXT_DESC
*
* Execution starts at `entry', with up to 10 integer arguments specified in
* the array `args[]'.  The return type is specified by setting `returnType'
* to WTX_RETURN_TYPE_INT or WTX_RETURN_TYPE_DOUBLE.
*
* NOTE: Because calling a function creates a task context on the target
* system, it cannot be used when the target agent is in external mode.
* 
* RETURNS: The ID of the function call or WTX_ERROR.  When the called
* function terminates, a CALL_RETURN event is generated which
* references this ID and contains the return value.
*
* SEE ALSO: wtxEventGet(), wtxDirectCall(),
* .I API Reference Manual: WTX Protocol WTX_FUNC_CALL
*/

WTX_CONTEXT_ID_T wtxFuncCall
    (
    HWTX		hWtx,		/* WTX API handle */
    WTX_CONTEXT_DESC *  pContextDesc	/* pointer to call descriptor */
    )

    {
    WTX_ERROR_T			callStat;	/* status of RPC */
    WTX_MSG_CONTEXT_DESC	in;		/* params to WTX call */
    WTX_MSG_RESULT		out;		/* result of WTX call */
    WTX_CONTEXT_ID_T		callId;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    /* Fill in the context create descriptor message. */

    /*
     * XXX - must have WTX_CONTEXT_DESC fields identical to those
     * WTX_MSG_CONTEXT_DESC from contextType onwards. Awaits change to
     * message definitions on wtxmsg.h so this hack will go away.
     */
    memcpy (&in.contextType, pContextDesc, sizeof (WTX_CONTEXT_DESC));
    
    callStat = exchange (hWtx, WTX_FUNC_CALL, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    callId = out.val.value_u.v_uint32; 

    wtxExchangeFree (hWtx->server, WTX_FUNC_CALL, &out);

    return callId;
    }

/******************************************************************************
*
* wtxDirectCall - call a function on the target within the agent
*
* This routine calls the function at <entry>, with up to 10 integer 
* arguments <arg0>... <arg9>, in the context of the target agent.  
*
* The return value of the function called on the target is returned at
* the address pointed to by <pRetVal>.
*
* NOTE: The called function is executed within the target agent allowing
* tools to call functions when the agent is running in both task and external
* mode.  This service should only be used to call simple functions that 
* return immediately in order to avoid locking access to the target for other
* tools.  It is preferable to use wtxFuncCall() to call functions that may take
* longer to return.  If the function called from wtxDirectCall() gets an 
* exception, the agent stops and communication with the target board is
* lost.
*
* CAVEAT: This service cannot be used to call functions that return a double.
* 
* RETURNS: WTX_OK or WTX_ERROR if cannot call the function or if <pRetVal>
* is NULL.  
*
* SEE ALSO: wtxFuncCall()
*/

STATUS wtxDirectCall
    (
    HWTX	hWtx,		/* WTX API handle */
    TGT_ADDR_T	entry,		/* function address */
    void *	pRetVal,	/* pointer to return value */
    TGT_ARG_T	arg0,		/* function arguments */
    TGT_ARG_T	arg1,	
    TGT_ARG_T	arg2,	
    TGT_ARG_T	arg3,	
    TGT_ARG_T	arg4,	
    TGT_ARG_T	arg5,	
    TGT_ARG_T	arg6,	
    TGT_ARG_T	arg7,	
    TGT_ARG_T	arg8,	
    TGT_ARG_T	arg9	
    )

    {
    WTX_ERROR_T			callStat;	/* status of RPC */
    WTX_MSG_CONTEXT_DESC	in;		/* params to WTX call */
    WTX_MSG_RESULT		out;		/* result of WTX call */

    /* check for invalid parameter */

    if (pRetVal == NULL)
	return (WTX_ERROR);

    /* check tool connection */

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    /* Fill in the context create descriptor message */

    in.entry	= entry;
    in.args[0]	= arg0;
    in.args[1]	= arg1;
    in.args[2]	= arg2;
    in.args[3]	= arg3;
    in.args[4]	= arg4;
    in.args[5]	= arg5;
    in.args[6]	= arg6;
    in.args[7]	= arg7;
    in.args[8]	= arg8;
    in.args[9]	= arg9;
    
    /* perform the call */

    callStat = exchange (hWtx, WTX_DIRECT_CALL, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    /* set target function return value */

    *(UINT32 *)pRetVal = out.val.value_u.v_uint32; 

    wtxExchangeFree (hWtx->server, WTX_DIRECT_CALL, &out);

    return WTX_OK;
    }

/*******************************************************************************
* 
* wtxTsInfoGet - get information about the target server, the target, and the link to the target
*
* This routine queries the target server to find out information about
* the currently connected target and target server.  The result is a pointer
* to internal memory that must not be freed by the user.  The value in
* memory may change after any subsequent WTX API calls so it must be copied 
* if the values are to be saved.
*
* EXPAND ../../../include/wtx.h WTX_TS_INFO
*
* where WTX_TGT_LINK_DESC is:
*
* EXPAND ../../../include/wtxmsg.h WTX_TGT_LINK_DESC
*
* and WTX_TGT_INFO is:
*
* EXPAND ../../../include/wtxmsg.h WTX_TGT_INFO
*
* WTX_TOOL_DESC is:
*
* EXPAND ../../../include/wtxmsg.h WTX_TOOL_DESC
*
* with WTX_AGENT_INFO:
*
* EXPAND ../../../include/wtxmsg.h WTX_AGENT_INFO
*
* and WTX_RT_INFO:
*
* EXPAND ../../../include/wtxmsg.h WTX_RT_INFO
*
* NOTE: This call actively queries the target server for information.
* Each successful call returns the latest information. 
*
* RETURNS: A pointer to the target server information structure or NULL on 
* error.
*/

WTX_TS_INFO * wtxTsInfoGet 
    (
    HWTX		hWtx		/* WTX API handle */
    )

    {
    WTX_ERROR_T		callStat;	/* WTX status */
    WTX_MSG_TS_INFO *	pOut;

    WTX_CHECK_CONNECTED (hWtx, NULL);

    pOut = calloc (1, sizeof (WTX_MSG_TS_INFO));
    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    callStat = exchange (hWtx, WTX_TS_INFO_GET, &hWtx->msgToolId, pOut);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);		/* Free allocated message */
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    /* Free the old target server info stored in the handle */
    if (hWtx->pTsInfo != NULL)
	wtxResultFree (hWtx, hWtx->pTsInfo);

    hWtx->pTsInfo = (WTX_TS_INFO *) &pOut->tgtLinkDesc;

    return (hWtx->pTsInfo);
    }



/*******************************************************************************
* 
* wtxTsLock - lock the connected target server for exclusive access
*
* This routine locks the target server that the client is connected to
* so it can only be used by this user and no others.  Other clients
* already connected can continue to use the target server 
* until they disconnect.  When a target server is locked the only
* operations another user may perform are connecting, getting the
* target server information, and disconnecting.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxTsUnlock()
*/

STATUS wtxTsLock 
    (
    HWTX		hWtx		/* WTX API handle */
    )

    {
    WTX_ERROR_T		callStat;	/* WTX status */
    WTX_MSG_TS_LOCK	in;
    WTX_MSG_RESULT	out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.lockType = 0;	/* ??? Is the lock type documented anywhere ??? */

    callStat = exchange (hWtx, WTX_TS_LOCK, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_TS_LOCK, &out);

    return (WTX_OK);
    }


/*******************************************************************************
* 
* wtxTsUnlock - unlock the connected target server
*
* This routine unlocks the target server that the client is connected to
* so it can be accessed by any user on its access list.  The unlock will
* only succeed if it is being unlocked by the same user that locked it.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxTsLock()
*/

STATUS wtxTsUnlock 
    (
    HWTX		hWtx		/* WTX API handle */
    )

    {
    WTX_ERROR_T		callStat;	/* WTX status */
    WTX_MSG_TS_UNLOCK	in;
    WTX_MSG_RESULT	out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.force = FALSE;	/* ??? Is this documented anywhere ??? */

    callStat = exchange (hWtx, WTX_TS_UNLOCK, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_TS_UNLOCK, &out);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxVerify - verify that a WTX handle is valid for use
*
* This routine returns WTX_OK if the WTX handle <hWtx> is valid. If an
* invalid handle is passed to a WTX routine, the error
* WTX_ERR_API_INVALID_HANDLE occurs. A handle that has been released using
* wtxTerminate() is invalid.
*
* RETURNS: TRUE if the handle is valid or FALSE if not.
*
* SEE ALSO: wtxInitialize(), wtxTerminate()
*/

BOOL32 wtxVerify
    (
    HWTX	hWtx		/* WTX API handle */
    )
    {
    return (hWtx != NULL && hWtx->self == hWtx);
    }

/*******************************************************************************
* 
* wtxVioChanGet - get a virtual I/O channel number
*
* This routine returns a free virtual I/O channel number to be
* used for redirection of target I/O to the host.  The returned
* channel number is an INT32 between 1 and 255.  (Channel 0 is
* reserved for the default console.) When no longer required, the
* channel number is released using wtxVioChanRelease().
*
* RETURNS: The new channel number or WTX_ERROR on failure.
*
* SEE ALSO: wtxVioChanRelease()
*/
INT32 wtxVioChanGet
    (
    HWTX hWtx	/* WTX API handle */
    )
    {
    WTX_ERROR_T		callStat;
    WTX_MSG_RESULT	out;
    INT32		result;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);
    memset (&out, 0, sizeof (out));

    callStat = exchange (hWtx, WTX_VIO_CHAN_GET, &hWtx->msgToolId, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    result = out.val.value_u.v_int32;
    wtxExchangeFree (hWtx->server, WTX_VIO_CHAN_GET, &out);

    return result;
    }

/*******************************************************************************
*
* wtxVioChanRelease - release a virtual I/O channel
*
* This request releases a virtual I/O channel number previously obtained
* using wtxVioChanGet() and returns it to the free-channel-number pool of
* the target server.  Valid channel numbers are in the range 1 to 255.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxVioChanGet()
*/

STATUS wtxVioChanRelease 
    (
    HWTX hWtx,		/* WTX API handle */
    INT32 channel	/* the channel number to release */
    )
    {
    WTX_ERROR_T		callStat;
    WTX_MSG_PARAM	in;
    WTX_MSG_RESULT	out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.param.valueType = V_INT32;
    in.param.value_u.v_int32 = channel;

    callStat = exchange (hWtx, WTX_VIO_CHAN_RELEASE, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_VIO_CHAN_RELEASE, &out);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxVioCtl - perform a control operation on a virtual I/O channel
*
* This routine performs the special I/O operation specified by <request>
* on the virtual I/O channel <channel>. An operation-specific
* parameter is supplied to the operation by <arg>.
* 
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxVioChanGet()
*/

STATUS wtxVioCtl
    (
    HWTX	hWtx,		/* WTX API handle */
    INT32	channel,	/* channel to do control operation on */
    UINT32	request,	/* control operation to perform */
    UINT32	arg		/* arg for call */
    )

    {
    WTX_ERROR_T			callStat;	/* WTX status */
    WTX_MSG_VIO_CTL_DESC	in;
    WTX_MSG_RESULT		out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.channel = channel;
    in.request = request;
    in.arg = arg;

    callStat = exchange (hWtx, WTX_VIO_CTL, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_VIO_CTL, &out);

    return (WTX_OK);
    }

/*******************************************************************************
*
* wtxVioFileList - list the files managed by the target server
*
* This routine returns a list of all the target-server-managed files along
* with information about each file including its name, state, and associated
* virtual I/O channel redirection.  The result is a pointer to a pointer to
* the first item in a linked list of file descriptors. It must be freed by
* the caller using wtxResultFree(). If the list is empty (no files are
* managed by the target server), the result points to a NULL value.
*
* EXPAND ../../../include/wtxmsg.h WTX_VIO_FILE_DESC
*
* RETURNS: A pointer to a pointer to the file list or NULL on error.
* 
* SEE ALSO: wtxFileOpen(), wtxFileClose()
*/

WTX_VIO_FILE_DESC ** wtxVioFileList 
    (
    HWTX hWtx		/* WTX API handle */
    )

    {
    WTX_ERROR_T			callStat;
    WTX_MSG_VIO_FILE_LIST *	pOut;

    WTX_CHECK_CONNECTED (hWtx, NULL);

    pOut = calloc (1, sizeof (WTX_MSG_VIO_FILE_LIST));
    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    callStat = exchange (hWtx, WTX_VIO_FILE_LIST, &hWtx->msgToolId, pOut);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);		/* Free allocated message */
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    return &pOut->pVioFileList;
    }


/*******************************************************************************
*
* wtxVioWrite - write data to a VIO channel
*
* This routine writes at most <numBytes> of data starting at <pData>
* to the virtual I/O channel number <channel>.  The buffer size is 512 bytes;
* if <numBytes> is greater than 512, the extra bytes are discarded.
*
* RETURNS: The number of bytes actually written or WTX_ERROR.
*
* SEE ALSO: wtxEventGet(), wtxVioChanGet()
*/

UINT32 wtxVioWrite
    (
    HWTX	hWtx,		/* WTX API handle */
    INT32	channel,	/* channel to write to */
    void *	pData,		/* pointer to data to write */
    UINT32	numBytes	/* number of bytes of data to write */
    )

    {
    WTX_ERROR_T			callStat;	/* WTX status */
    WTX_MSG_VIO_COPY_DESC	in;
    WTX_MSG_RESULT		out;
    UINT32			bytesWritten;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    memset (&out, 0, sizeof (out));

    in.channel = channel;
    in.maxBytes = numBytes;
    in.baseAddr = pData;

    callStat = exchange (hWtx, WTX_VIO_WRITE, &in, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    bytesWritten = out.val.value_u.v_uint32;
    wtxExchangeFree (hWtx->server, WTX_VIO_WRITE, &out);

    return bytesWritten;
    }


/*******************************************************************************
*
* wtxTargetAttach - reattach to the target
*
* This routine reattaches the client to a target that has been disconnected
* or for which the target server is waiting to connect. 
* 
* RETURNS: WTX_OK if the target is successfully attached or WTX_ERROR 
* if the target is still unavailable.
*/

STATUS wtxTargetAttach
    (
    HWTX	hWtx	/* WTX API handle */
    )
    {
    WTX_ERROR_T	callStat;
    WTX_MSG_RESULT	out;

    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    memset (&out, 0, sizeof (out));

    callStat = exchange (hWtx, WTX_TARGET_ATTACH, &hWtx->msgToolId, &out);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    wtxExchangeFree (hWtx->server, WTX_TARGET_ATTACH, &out);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxProbe - probe to see if the registry service is running
*
* This routine returns WTX_OK if the registry service is running. Otherwise
* it returns WTX_ERROR.
*
* RETURNS: WTX_OK or WTX_ERROR.
*/

STATUS wtxProbe 
    (
    HWTX hWtx	/* WTX API handle */
    )

    {
    WTX_ERROR_T callStat;

    WTX_CHECK_HANDLE (hWtx, WTX_ERROR);

    if (registryConnect (hWtx) != WTX_OK)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_REGISTRY_UNREACHABLE, WTX_ERROR);

    callStat = wtxExchange (hWtx->registry, NULLPROC, NULL, NULL);

    /* close registry connection now since we don't need it anymore */
    registryDisconnect (hWtx);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    return (WTX_OK);
    }

/*******************************************************************************
*
* wtxRegister - register the target server with the Tornado registry service
*
* This routine registers the named target server with the WTX registry daemon.
* If the specified name does not conflict with any other registered server,
* the registry allocates, initializes, and adds a WTX descriptor structure
* containing a unique RPC program number to its internal tables.  If
* specified, <name> must be unique for the whole system, and by convention
* it is a legal C identifier.  If <name> is NULL, a unique name is allocated
* by the registry and returned to the caller. Only one server can be
* registered per WTX handle.
*
* The return value is a pointer to internal data and must not be freed
* by the user.
*
* EXPAND ../../../include/wtxtypes.h WTX_DESC
*
* RETURNS: A pointer to a WTX_DESC or NULL if the registration failed.
*
* ERRORS:
* .iP WTX_ERR_API_SERVICE_ALREADY_REGISTERED 12
* The server has already registered itself.
* .iP WTX_ERR_API_REGISTRY_UNREACHABLE 
* The registry service is not reachable (in other words, the registry 
* daemon is not running).
* .iP WTX_ERR_API_MEMALLOC 
* There are insufficient resources to allocate a new WTX descriptor for 
* the server.
*
* SEE ALSO: wtxUnregister(), wtxInfo()
*/

WTX_DESC * wtxRegister
    (
    HWTX	hWtx,		/* WTX API handle */
    const char *name,		/* service name, NULL to be named */
    const char *type,		/* service type, NULL for unspecified */
    const char *key		/* unique service key */
    )
    {
    WTX_ERROR_T	callStat;
    WTX_MSG_SVR_DESC	in;
    WTX_MSG_SVR_DESC *	pOut;

    if (hWtx->pSelfDesc != NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_SERVICE_ALREADY_REGISTERED, NULL);

    if (registryConnect (hWtx) != WTX_OK)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_REGISTRY_UNREACHABLE, NULL);

    /* allocate a new descriptor */
    pOut = calloc (1, sizeof (WTX_MSG_SVR_DESC));
    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    /* fill in our particulars */
    memset (&in, 0, sizeof (in));
    in.wtxSvrDesc.wpwrName = (char *) name;		/* send our name */
    in.wtxSvrDesc.wpwrType = (char *) type;		/* send our type */
    in.wtxSvrDesc.wpwrKey  = (char *) key;		/* send our key */

    callStat = exchange (hWtx, WTX_REGISTER, &in, pOut);

    /* close registry connection now since we don't need it anymore */
    registryDisconnect (hWtx);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);		/* free allocated message */
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    /* XXX - This is a hack! Relies on WTX_SVR_DESC and WTX_DESC being
     * identical which they are at the moment. The WTX_SVR_DESC type should
     * be renamed WTX_DESC and the original typedef should be removed but
     * until then this works and jives with the wtxResultFree() mechanism.
     */
    hWtx->pSelfDesc = (WTX_DESC *) &pOut->wtxSvrDesc;

    return (hWtx->pSelfDesc);				/* return descriptor */
    }

/*******************************************************************************
*
* wtxUnregister - unregister the server with the Tornado registry
*
* This routine removes the specified descriptor from the Tornado-registry
* internal table. The name of the server is no longer reserved. Passing
* NULL for <name> means unregister the server already registered against
* the handle <hWtx> using wtxRegister().
*
* RETURNS: WTX_OK or WTX_ERROR if the server could not be unregistered.
*
* ERRORS:
* .iP WTX_ERR_API_SERVICE_NOT_REGISTERED 12
* The server is trying to unregister itself when it has not registered or
* has already unregistered.
* .iP WTX_ERR_API_REGISTRY_UNREACHABLE
* The registry service is not reachable (in other words, the registry 
* daemon is not running).
*
* SEE ALSO: wtxRegister()
*/

STATUS wtxUnregister 
    (
    HWTX	hWtx,		/* WTX API handle */
    const char *name		/* service to unregister, NULL for self */
    )
    {
    WTX_MSG_PARAM	in;
    WTX_MSG_RESULT	out;
    WTX_ERROR_T		callStat;
    
    if ((name == NULL) &&				/* self? */
        (hWtx->pSelfDesc == NULL || 
	 (name = hWtx->pSelfDesc->wpwrName) == NULL))
	/*  Unregistering self when not registered */
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_SERVICE_NOT_REGISTERED, WTX_ERROR);

    if (registryConnect (hWtx) != WTX_OK)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_REGISTRY_UNREACHABLE, WTX_ERROR);

    memset (&in, 0, sizeof (in));
    in.param.valueType = V_PCHAR;
    in.param.value_u.v_pchar = (char *) name;
    memset (&out, 0, sizeof (out));

    callStat = exchange (hWtx, WTX_UNREGISTER, &in, &out);

    /* close registry connection now since we don't need it anymore */
    registryDisconnect (hWtx);

    if (callStat != WTX_ERR_NONE)
	WTX_ERROR_RETURN (hWtx, callStat, WTX_ERROR);

    /* if unregistering ourself, destroy our descriptor */
    if (hWtx->pSelfDesc && 
	  hWtx->pSelfDesc->wpwrName && 
	  STREQ (hWtx->pSelfDesc->wpwrName, name))
	{
	wtxResultFree (hWtx, hWtx->pSelfDesc);
	hWtx->pSelfDesc = NULL;
	}

    wtxExchangeFree (hWtx->registry, WTX_UNREGISTER, &out);

    return (WTX_OK);
    }

/*******************************************************************************
*
* wtxInfo - allocate and return a descriptor for the named service
*
* This routine allocates and fills in a descriptor corresponding to the
* named service.  This routine always queries the WTX registry daemon for
* the named service and allocates and fills a WTX descriptor structure with
* the results.  The descriptor must be deallocated with wtxResultFree()
* when it is no longer needed. Passing NULL for <name> means to get
* information on the server already registered against the handle <hWtx>
* using wtxRegister().
*
* EXPAND ../../../include/wtxtypes.h WTX_DESC
*
* RETURNS: A pointer to a WTX_DESC or NULL if the service could not be found.
*
* ERRORS:
* .iP WTX_ERR_API_SERVICE_NOT_REGISTERED 12
* <name> is NULL and no service is registered against the handle.
* .iP WTX_ERR_API_REGISTRY_UNREACHABLE 
* The registry service is not reachable (in other words, the registry daemon
* is not running).
*
* SEE ALSO: wtxInfoQ()
*/

WTX_DESC * wtxInfo 
    (
    HWTX	 hWtx,		/* WTX API handle */
    const char * name		/* service name to lookup */
    )
    {
    WTX_MSG_PARAM	in;
    WTX_MSG_SVR_DESC *	pOut;
    WTX_ERROR_T		callStat;

    if ((name == NULL) &&				/* self? */
        (hWtx->pSelfDesc == NULL || 
	 (name = hWtx->pSelfDesc->wpwrName) == NULL))
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_SERVICE_NOT_REGISTERED, NULL);

    if (registryConnect (hWtx) != WTX_OK)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_REGISTRY_UNREACHABLE, NULL);

    /* allocate and initialize registry response */
    pOut = (WTX_MSG_SVR_DESC *) calloc (1, sizeof (WTX_MSG_SVR_DESC));
    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    memset (&in, 0, sizeof (in));
    in.param.valueType = V_PCHAR;
    in.param.value_u.v_pchar = (char *) name;

    /* ask daemon for information */
    callStat = exchange (hWtx, WTX_INFO_GET, &in, pOut);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);				/* Free allocated message */
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    /* XXX - See wtxRegister() for justification of this hack */
    return (WTX_DESC *) &pOut->wtxSvrDesc;
    }

/*******************************************************************************
*
* wtxInfoQ - return a list of all services registered with the Tornado registry
*
* This routine provides the caller with a table of descriptors corresponding 
* to all services registered with the Tornado registry.  An unsorted table
* of descriptors is allocated and returned.  There is no guarantee that 
* the table is valid by the time it is inspected.  Services may come and go
* at any time.
*
* EXPAND ../../../include/wtxtypes.h WTX_DESC_Q
*
* The table of descriptors should be deallocated with wtxResultFree().
*
* RETURNS: A pointer to a table of descriptors or NULL if error.
*
* ERRORS:
* .iP WTX_ERR_API_REGISTRY_UNREACHABLE 12
* The registry service is not reachable (in other words, the registry
* daemon is not running).
* .iP WTX_ERR_API_MEMALLOC 
* There are insufficient resources to allocate the WTX_DESC_Q structure for
* the result value.
*
* SEE ALSO: wtxInfo()
*/

WTX_DESC_Q * wtxInfoQ
    (
    HWTX hWtx,			/* WTX API handle */
    const char *namePattern,	/* regular expression to match svc name */
    const char *typePattern,	/* regular expression to match svc type */
    const char *keyPattern	/* regular expression to match svc key */
    )
    {
    WTX_MSG_WTXREGD_PATTERN	in;
    WTX_MSG_SVR_DESC_Q *	pOut;
    WTX_ERROR_T			callStat;


    if (registryConnect (hWtx) != WTX_OK)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_REGISTRY_UNREACHABLE, NULL);

    /* allocate and initialize registry response */
    pOut = calloc (1, sizeof (WTX_MSG_SVR_DESC_Q));
    if (pOut == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_MEMALLOC, NULL);

    /* fill in patterns for query */

    in.name = (char *) namePattern;
    in.type = (char *) typePattern;
    in.key  = (char *) keyPattern;

    /* get list of registered services */

    callStat = exchange (hWtx, WTX_INFO_Q_GET, &in, pOut);

    if (callStat != WTX_ERR_NONE)
	{
	free (pOut);
	WTX_ERROR_RETURN (hWtx, callStat, NULL);
	}

    /* XXX - See wtxRegister() for justification of this hack */
    return (WTX_DESC_Q *) &pOut->wtxSvrDescQ;
    }

/*******************************************************************************
*
* wtxEach - call a routine to examine each WTX-registered service
*
* This routine calls a user-supplied routine to examine each WTX-registered
* service; it calls the specified routine once for each service.  The
* routine should be declared as follows:
* 
* .CS
*   BOOL32 routine
*	(
*	WTX_DESC_Q *	pDesc,	/@ entry name @/
*	int          	arg	/@ arbitrary user-supplied arg @/
*	)
* .CE
* 
* The user-supplied routine should return TRUE if wtxEach() is
* to  continue  calling  it  for each entry, or FALSE if it is
* done and wtxEach() can exit.  
*
* Note that all descriptors are deallocated upon exit.
*
* RETURNS: WTX_OK or WTX_ERROR if the table of descriptors could not be 
* obtained.
* 
* ERRORS:
* .iP WTX_ERR_API_REGISTRY_UNREACHABLE 12 
* The registry service is not reachable (in other words, the registry daemon
* is not running).
* .iP WTX_ERR_API_MEMALLOC
* There are insufficient resources to allocate the WTX_DESC_Q structure for
* the result value.
*
* SEE ALSO: wtxInfoQ()
*/

STATUS wtxEach
    (
    HWTX	hWtx,		/* WTX API handle */
    const char *namePattern,	/* regular expression to match svc name */
    const char *typePattern,	/* regular expression to match svc type */
    const char *keyPattern,	/* regular expression to match svc key */
    FUNCPTR	routine,	/* func to call for each svc entry */
    void *	routineArg	/* arbitrary user-supplied arg */
    )
    {
    WTX_DESC_Q *	pWtxDescQ;
    WTX_DESC_Q *	pDescQ;

    pWtxDescQ = wtxInfoQ (hWtx, namePattern, typePattern, keyPattern);

    if (pWtxDescQ == NULL)
	/* Note: error has already been dispatched so just return */
	return  WTX_ERROR;

    pDescQ = pWtxDescQ;

    /* traverse descriptor queue and call the routine */
    while (pDescQ != NULL)
	{
	if (!((* routine) (pDescQ, routineArg)))
	    break;
	pDescQ = (WTX_DESC_Q *) pWtxDescQ->pNext;
	}

    wtxResultFree (hWtx, pWtxDescQ);

    return (WTX_OK);
    }


/*******************************************************************************
*
* wtxTimeoutSet - set the timeout for completion of WTX calls
*
* This routine changes the timeout value for making WTX API calls.
* When a call takes longer than the value specified by <msec> (in
* milliseconds), the call aborts with an error status and the
* error code is set to WTX_ERR_API_REQUEST_TIMED_OUT.
*
* NOTE: The timeout for WTX registry calls is unaffected.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxTimeoutGet()
*/
STATUS	wtxTimeoutSet 
    (
    HWTX	hWtx,	/* WTX API handle */
    UINT32	msec	/* New timeout value in milliseconds */
    )
    {
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    if (wtxExchangeControl (hWtx->server, 
			    WTX_EXCHANGE_CTL_TIMEOUT_SET, &msec) == WTX_OK)
	return WTX_OK;
    else
	WTX_ERROR_RETURN (hWtx, wtxExchangeErrGet (hWtx->server), WTX_ERROR);
    }


/*******************************************************************************
*
* wtxTimeoutGet - get the current timeout for completion of WTX calls
*
* This routine gets the current timeout value for making WTX API calls.
* The value is returned in the UINT32 pointed to by <pMsec>.
*
* RETURNS: WTX_OK or WTX_ERROR.
*
* SEE ALSO: wtxTimeoutSet()
*/
STATUS	wtxTimeoutGet 
    (
    HWTX	hWtx,	/* WTX API handle */
    UINT32 *	pMsec	/* Pointer to timeout value in milliseconds */
    )
    {
    WTX_CHECK_CONNECTED (hWtx, WTX_ERROR);

    if (pMsec == NULL)
	WTX_ERROR_RETURN (hWtx, WTX_ERR_API_INVALID_ARG, WTX_ERROR);

    if (wtxExchangeControl (hWtx->server, 
			    WTX_EXCHANGE_CTL_TIMEOUT_GET, pMsec) == WTX_OK)
	return WTX_OK;
    else
	WTX_ERROR_RETURN (hWtx, wtxExchangeErrGet (hWtx->server), WTX_ERROR);
    }


/*******************************************************************************
*
* exchange - wrapper for calling exchange mechanism
*
* This routine performs a WTX call selecting the correct exchange handle
* and doing some additional error checking.
*
* RETURNS: WTX_ERR_NONE or error code
*
* NOMANUAL
*/

LOCAL WTX_ERROR_T exchange
    (
    HWTX	hWtx,		/* handle to use for exchange */
    UINT32	svcNum,		/* service number to call */
    void *	pIn,		/* pointer to in (argument) data */
    void *	pOut		/* pointer to out (result) data */
    )

    {
    WTX_ERROR_T	retVal;		/* value to return */
    STATUS	status;		/* status of exchange call */
    WTX_XID 	xid;		/* exchange handle to use for call */

    /* Figure out which exchange handle to use based on the API service num */
    switch (svcNum)
	{
	case WTX_REGISTER:
	case WTX_UNREGISTER:
	case WTX_INFO_GET:
	case WTX_INFO_Q_GET:
	    xid = hWtx->registry;
	    break;

	default:
	    xid = hWtx->server;
	    break;
	}

    /* Fill in the objId field required by some API requests */
    ((WTX_MSG_DUMMY *) pIn)->wtxCore.objId = hWtx->msgToolId.wtxCore.objId;

    /* Do the call */
    status = wtxExchange (xid, svcNum, pIn, pOut);

    /*
     * Stamp the result with the service number so that it can be freed
     * by the free function without knowing its object type. The protVersion
     * field is used to store the address of the result to help identify
     * (not foolproof but fairly good) bogus pointers passed to free.
     */
    if (status == WTX_OK)
	{
	((WTX_MSG_DUMMY *) pOut)->wtxCore.objId = svcNum;
	((WTX_MSG_DUMMY *) pOut)->wtxCore.protVersion = (UINT32) pOut;
	return WTX_ERR_NONE;
	}

    /* Analyze the result and see if it requires any special action */
    switch (wtxExchangeErrGet (xid))
	{
	case WTX_ERR_EXCHANGE_TRANSPORT_DISCONNECT:
	    /*
	     * This exchange transport mechanism has broken down and
	     * disconnected us. The error is reported to the caller as
	     * WTX_ERR_API_TOOL_DISCONECTED or
	     * WTX_ERR_API_REGISTRY_UNREACHABLE (depending on the
	     * connection) so the user can tell there is no point in
	     * making further calls (which would return 
	     * WTX_ERR_API_NOT_CONNECTED 
	     */
	    if (xid == hWtx->registry)
		{
	        wtxExchangeDelete (xid);
	        wtxExchangeTerminate (xid);
		hWtx->registry = NULL;
		retVal = WTX_ERR_API_REGISTRY_UNREACHABLE;
		}
	    else
		{
    		toolCleanup (hWtx);
		retVal = WTX_ERR_API_TOOL_DISCONNECTED;
		}
	    break;

	case WTX_ERR_EXCHANGE_TIMEOUT:
	    retVal = WTX_ERR_API_REQUEST_TIMED_OUT;
	    break;

	case WTX_ERR_EXCHANGE:
	case WTX_ERR_EXCHANGE_INVALID_HANDLE:
	case WTX_ERR_EXCHANGE_DATA:
	case WTX_ERR_EXCHANGE_MEMALLOC:
	case WTX_ERR_EXCHANGE_NO_SERVER:
	case WTX_ERR_EXCHANGE_INVALID_ARG:
	case WTX_ERR_EXCHANGE_MARSHALPTR:
	case WTX_ERR_EXCHANGE_BAD_KEY:
	case WTX_ERR_EXCHANGE_REQUEST_UNSUPPORTED:
	case WTX_ERR_EXCHANGE_TRANSPORT_UNSUPPORTED:
	case WTX_ERR_EXCHANGE_TRANSPORT_ERROR:
	case WTX_ERR_EXCHANGE_NO_TRANSPORT:
	    retVal = WTX_ERR_API_REQUEST_FAILED;
	    break;

	default:
	    /* some other API error - return error unchanged */
	    retVal = wtxExchangeErrGet (xid);
	    break;
	}

    return retVal;
    }

/*******************************************************************************
*
* registryConnect - wrapper for setting up registry exchange
*
* This routine tries to set up the exchange handle for the registry
* and connect to the registry service.
*
* RETURNS: WTX_ERR_NONE or error code
*
* NOMANUAL
*/

LOCAL WTX_ERROR_T registryConnect
    (
    HWTX	hWtx	/* handle to connect to registry */
    )
    {
    if (hWtx->registry != NULL)
	return WTX_OK;

    if (wtxExchangeInitialize (&hWtx->registry) != WTX_OK ||
	wtxExchangeInstall (hWtx->registry, 
			    wtxRpcExchangeCreate, 
			    wtxRpcExchangeDelete, 
			    wtxRpcExchange, 
			    wtxRpcExchangeFree, 
			    wtxRpcExchangeControl) != WTX_OK ||
	wtxExchangeCreate (hWtx->registry, NULL) != WTX_OK)
	{
	wtxExchangeTerminate (hWtx->registry);
	hWtx->registry = NULL;
	return WTX_ERROR;
	}

    return WTX_OK;
    }


/*******************************************************************************
*
* registryDisconnect - wrapper for closing registry exchange
*
* This routine terminates the exchange handle for the registry
* and clears the registry field in the WTX handle.
*
* RETURNS: WTX_ERR_NONE or error code
*
* NOMANUAL
*/

LOCAL void registryDisconnect
    (
    HWTX	hWtx	/* handle to disconnect registry */
    )
    {
    if (hWtx->registry == NULL)		/* check if not already disconnected */
	return; 

    wtxExchangeDelete (hWtx->registry);	/* close registry connection */

    wtxExchangeTerminate (hWtx->registry);	/* cleanup */

    hWtx->registry = NULL;		/* clear handle */

    return;
    }

/*******************************************************************************
*
* toolCleanup - do the cleanups necessary when a tool detaches
*
* RETURNS: N/A
*
* NOMANUAL
*/

LOCAL void toolCleanup
    (
    HWTX	hWtx  /* handle to connect to server */
    )
    {
    if (hWtx == NULL)
	return;

    /* Free up the target server info before deleting the exchange handle */
    if (hWtx->pTsInfo)
	{
	wtxResultFree (hWtx, hWtx->pTsInfo);
	hWtx->pTsInfo = NULL;
	}

    /* Free up the tool descriptor */
    if (hWtx->pToolDesc)
	{
	wtxResultFree (hWtx, hWtx->pToolDesc);
	hWtx->pToolDesc = NULL;
	}

    if (hWtx->server != NULL)
	{
	wtxExchangeDelete (hWtx->server);
	wtxExchangeTerminate (hWtx->server); 
	}

    hWtx->server = NULL;
    }

/*******************************************************************************
*
* serverDescFree - de-allocate server descriptor
*
* RETURNS: N/A
*
* NOMANUAL
*/

LOCAL void serverDescFree
    (
    HWTX	hWtx  /* handle to connect to server */
    )

    {
    free (hWtx->pServerDesc->wpwrName);
    free (hWtx->pServerDesc->wpwrKey);
    free (hWtx->pServerDesc->wpwrType);

    free (hWtx->pServerDesc);
    hWtx->pServerDesc = NULL;
    }

/******************************************************************************
*
* wtxToolIdGet - return the tool identifier of the current tool
*
* This function returns the tool identifier associated with the given
* handle <hWtx>.
*
* RETURNS: The tool identifier or WTX_ERROR on error.
*/

UINT32 wtxToolIdGet
    (
    HWTX	hWtx		/* WTX API handle */
    )
    {

    WTX_CHECK_CONNECTED (hWtx, (UINT32)NULL);

    if (hWtx->pToolDesc != NULL)
	return (hWtx->pToolDesc->id);
    else
	return (WTX_ERROR);
    }
