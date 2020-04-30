/*
 *      Copyright(c) 1996-1999 Fridu a Free Software Company Fulup Le Foll
 *
 * File         : execRuntimeTornado.c  Exec a function on to VxWork thru target server
 * Projet       : jWrap
 * SubModule    : VxWorks Wtx Tornado interface
 * Auteur       : Fulup Le Foll (Fulup@fridu.bzh)
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/runtime/execRuntimeTornado.c,v $
 *
 * Modification History
 * --------------------
 * 1.5  1999/03/10 Fulup, added exception check on function return
 * 1.4  1999/02/18 Fulup, added usleep for non Dos system
 * 1.3  1999/02/16 Fulup, externalized WTX module
 * 1.2  1998/05/06 Fulup, adapted to jWrap
 * 1.1  1996/05/13 Fulup, written
 *
 */

/** --------------------------------------------------------
 ** Manages all facilities for executing function on VxWorks
 ** target. 
 ** --------------------------------------------------------*/
#include "libRuntimeTornado.h"
#include <string.h>

// Solaris <unistd.h> with Tornado does not have usleep
// On Win95 usleep is given as Sleep in document but usleep works fine [One One WinBug ???]
int usleep(unsigned int useconds);

/** define a timeout counter under Unix each hop last around
 ** 100ms + wtx RPC/Xdr call, Windows is slow enought for not
 ** adding 100ms */
EXPORT int tornadoExecHopCount = TORNADO_DEFAULT_HOP_TIMEOUT;

/**----------------------------------------------------------
 ** Split event in piece for further analysing
 ** under Wtx event are send in a Tcl string list mode and
 ** need beeing parser before beeing checked in a C switch.
 ** @param tornadoId Tornado handle
 ** @param evtId Tcl string list return by Wtx
 ** @return  TORNADO_evtRet a C structure with a parser return event
 **----------------------------------------------------------*/
RESTRICTED TORNADO_evtRet *
tornadoExecSplitEvent (TORNADO_id * tornadoId, WTX_EVENT_DESC * evtId)
{
  static TORNADO_evtRet evtRet;
  int ind;

  if (evtId->event[0] != '\0')
    jWrapLog (5, "[%s]\n", evtId->event);
  else
    jWrapLog (9, "[No Event]\n");

  /*
   * eventId in in fact a TCL list (even with C interface!!!)
   * we slipt in 4 status, funcId, return params
   * note: some event dont have 4 field
   */
  evtRet.argc = 0;
  evtRet.argv[TORNADO_EVT_TYPE] = evtId->event;
  for (ind = 0; evtId->event[ind] != '\0'; ind++) {
    if (evtId->event[ind] == ' ') {
      evtId->event[ind] = '\0';
      ind++;
      evtRet.argc++;
      evtRet.argv[evtRet.argc] = &evtId->event[ind];
    }
  }				/*
				 * end for ind 
				 */

  /*
   * tornadoCtxSpawn need evtId in order to free it 
   */
  evtRet.id = evtId;
  evtRet.tornadoId = tornadoId;

  /*
   * we have an event but not the one we have waiting for 
   */
  evtRet.evtNum = wtxStrToEventType (tornadoId->wtxId, evtRet.argv[TORNADO_EVT_TYPE]);

  if (evtRet.argc >= TORNADO_EVT_FUNC_ID) {
    evtRet.funcId = wtxStrToContextId (tornadoId->wtxId, evtRet.argv[TORNADO_EVT_FUNC_ID]);
  } else {
    evtRet.funcId = 0;
  }

  return (&evtRet);
}				/*
				 * end tornadoSplitEvent 
				 */

/**---------------------------------------------------------
 ** Pool on events until waited return is founded. Whenever
 ** a vio is received this routine print it on stdout, before
 ** repoolling for expected event. If expected event as an
 ** errno send an exeption to the shell thru jWrapPanic.
 ** @param tornadoId  TORNADO handle
 ** @param funcId function handle in WTX given with tornadoExecCall
 ** @return none
 ** @see wtxEventGet 
 **---------------------------------------------------------*/
PUBLIC void *
tornadoExecWaitReturn (TORNADO_id * tornadoId, WTX_CONTEXT_ID_T funcId)
{
  int hop;
  TGT_ADDR_T returnValue;
  INT32      returnStatus;
  BOOL done = FALSE;
  TORNADO_evtRet *evtSplit;
  WTX_EVENT_DESC *evtId;

  /*
   * pool event for result 
   */
  for (hop = 0; done == FALSE; hop++) {
    /*
     * event works in pool mode wait for not killing host 
     */
#   ifndef WinDos
        usleep (100000);
#   endif
    Tcl_DoOneEvent (TCL_DONT_WAIT);
    evtId = wtxEventGet (tornadoId->wtxId);
    /*
     * if wtxEventGet was sucesfull but no event raised
     * retry (huggly pool method) 
     */
    if (evtId == NULL) {
      // Tcl_DoOneEvent (TCL_ALL_EVENTS);
      // usleep (100000);
      continue;
    }

    /*
     * parse event 
     */
    evtSplit = tornadoExecSplitEvent (tornadoId, evtId);

    switch (evtSplit->evtNum) {

      case WTX_EVENT_CALL_RETURN:

	/*
	 * check eventId->event look nice 
	 */
	if (evtSplit->argc != 3)
	  goto errEvtFmt;

	/*
	 * is this the one we are looking for ? 
	 */
	jWrapLog (8,"[%#x==%#x ?] \n" ,(void*)funcId, (void*)evtSplit->funcId);

	/*
	 * hum hum, is this what we are waiting for 
	 */
	if (funcId == evtSplit->funcId)
	  done = TRUE;
	break;

      case WTX_EVENT_VIO_WRITE:

	/*
	 * print all VIO message on stdout 
	 */
	fwrite (evtId->addlData, sizeof (char), (size_t)evtId->addlDataLen, stdout);
        fflush (stdout);

	hop--;			/*
				 * each VIO_WRITE increase hop timeout 
				 */

	/*
	 * free unsued event before asking a new one 
	 */
	wtxResultFree (tornadoId->wtxId, evtId);

	break;
  
      case WTX_EVENT_EXCEPTION:

        jWrapLog (1, "[%s]\n", evtId->event);
	wtxResultFree (tornadoId->wtxId, evtId);
        goto errException;

        break;

      default:
	/*
	 * free unsued event before asking a new one 
	 */
	wtxResultFree (tornadoId->wtxId, evtId);

    }				/*
				 * end switch 
				 */

    /*
     * did we hopTimeout ? 
     */
    if (hop >= tornadoExecHopCount)
      goto errTimeout;
  }				// end for

  /*
   * process return status 
   */
  returnStatus = wtxStrToInt32 (tornadoId->wtxId, evtSplit->argv[TORNADO_EVT_FUNC_STATUS]);
  if (returnStatus != WTX_OK)
    goto errRetStatus;

  /*
   * we finaly have a good result process it as an adress 
   */
  returnValue = wtxStrToTgtAddr (tornadoId->wtxId, evtSplit->argv[TORNADO_EVT_FUNC_RET]);

#ifdef NOT_DONE
  /*
   * now we can free event ID 
   */
  wtxResultFree (tornadoId->wtxId, evtId);
#endif

  jWrapLog (2, " ==== [%#x=(%ld)] ====\n", (void*)returnValue, (long)returnValue);
  return (void *) returnValue;

  /*
   * ---------------------- ERROR --------------------- 
   */

errEvtFmt:
  jWrapPanic (NULL,"event did not returned 4 slots but [%d]\n", evtSplit->argc);

errTimeout:
  jWrapPanic (NULL,"tornadoExecWaitReturn (hopTimeout [%d])\n", hop);

errException:
  jWrapPanic (NULL,"tornadoExecWaitReturn (Exception on target WTX_ErrMsg=[%s])\n"
             ,wtxErrMsgGet (tornadoId->wtxId));

errRetStatus:
  jWrapPanic (NULL,"tornadoExecWaitReturn (return status FX [%d] WTX_ErrMsg=[%s])\n"
	      ,returnStatus, wtxErrMsgGet (tornadoId->wtxId));

  return NULL;			// for gcc not to complain

}				/*
				 * end tornadoExecWaitReturn 
				 */

/** ---------------------------------------------------------------------
 **   Search a symbol in target server. Giving it adress
 **   @param tornadoId  Tornado handle
 **   @param symbol a valid symbol in target symbol table.
 **   @note does not use strict symbol search
 **   @see wtxSymFind
 ** ---------------------------------------------------------------------*/
PUBLIC char* tornadoExecFindAddr (TORNADO_id * tornadoId, char *symbol) { 
 WTX_SYMBOL *wtxSymId; 
 TGT_ADDR_T address;
 int        len;
 char       *result;

   len=sscanf (symbol,"0x%lx",(long*) &address);
   if (len != 1) goto errScanAddr;
   wtxSymId = wtxSymFind (tornadoId->wtxId, NULL, address, FALSE, 0, 0);
   if (wtxSymId == NULL) goto errSymFind;

   result = strdup (wtxSymId->name);
   wtxResultFree (tornadoId->wtxId, wtxSymId);
   return result;

errSymFind:
   jWrapPanic (NULL,"tornadoExecFindAddr (wtxSymFind [%s])\nWTX_ErrMsg=[%s]\n"
	      ,symbol
              ,wtxErrMsgGet (tornadoId->wtxId));
errScanAddr:
   jWrapPanic (NULL,"tornadoExecFindAddr (wtxSymFind [%s]) invalid hexa adresse\n"
	      ,symbol);

   return NULL;
} 

/** ---------------------------------------------------------------------
 **   Search a symbol in target server. Is symbol exist in target server
 **   return the adress in VxWorks adress space, else raise an exeption
 **   thru jWrapPanic.
 **   @param tornadoId  Tornado handle
 **   @param symbol a valid symbol in target symbol table.
 **   @note does not use strict symbol search
 **   @see wtxSymFind
 ** ---------------------------------------------------------------------*/
PUBLIC TGT_ADDR_T tornadoExecFindSymbol (TORNADO_id * tornadoId, char *symbol) { 
 WTX_SYMBOL *wtxSymId; 
 TGT_ADDR_T result;
 int        len;
 
    wtxSymId = wtxSymFind (tornadoId->wtxId, symbol, 0, FALSE, 0, 0);
    if (wtxSymId == NULL) goto errSymFind;

    result = wtxSymId->value;
    wtxResultFree (tornadoId->wtxId, wtxSymId);
    return result;

errSymFind:
   jWrapPanic (NULL,"tornadoExecFindSymbol (wtxSymFind [%s])\nWTX_ErrMsg=[%s]\n"
	      ,symbol
              ,wtxErrMsgGet (tornadoId->wtxId));

   return (unsigned)JWRAP_IMPOSSIBLE;
} 

/**----------------------------------------------------
 ** Start a function as a task on VxWorks target
 ** @param tornadoId TORNADO handle
 ** @param wtxCtx a valid wtx function context
 ** @return a function execution context, and an execption
 ** if symbol given in wtxCtx cannot be found
 ** @see wtxFuncCall
 **----------------------------------------------------*/
PUBLIC WTX_CONTEXT_ID_T tornadoExecFuncSpawn (TORNADO_id * tornadoId, WTX_CONTEXT_DESC *wtxCtx) {
  WTX_CONTEXT_ID_T funcId;

  jWrapLog (2,"tornadoExecFuncSpawn: ???? [%s(%#x,%#x,...)] ????\n"
              ,wtxCtx->name,(void*)wtxCtx->args[0],(void*)wtxCtx->args[1]);

  // If function as not been binded try to do it now
  if (wtxCtx->entry == 0) {
     wtxCtx->entry = tornadoExecFindSymbol (tornadoId, wtxCtx->name);
     if (wtxCtx->entry == 0) goto errSymbol;
     wtxCtx->redirOut  = tornadoId->vOut;
  }
  /*
   * call function 
   */
  funcId = wtxFuncCall (tornadoId->wtxId, wtxCtx);
  if (funcId == (WTX_CONTEXT_ID_T) WTX_ERROR)
    goto errFuncCall;

    /*
     * return funcId for tornadoExecWaitReturn 
     */
  return (funcId);

  /*
   * ---------------------------- ERROR -------------------- 
   */
errSymbol:
  jWrapPanic (NULL,"ERROR: tornadoExecFuncCall [%s] Unknow Symbol\nWTX_ErrMsg=[%s]\n"
	      ,wtxCtx->name, wtxErrMsgGet (tornadoId->wtxId));

errFuncCall:
  jWrapPanic (NULL,"ERROR: tornadoExecFuncCall [%s]\nWTX_ErrMsg=[%s]\n"
	      ,wtxCtx->name, wtxErrMsgGet (tornadoId->wtxId));

  return 0;			// for Gcc warning

}				/*
				 * end tornadoExecFuncCall 
				 */

/**----------------------------------------------------------- 
 ** Short interface for tornadoExecFuncCall & tornadoExecWaitReturn
 ** this routine is the one used by jWrap.
 ** @param  tornadoId TORNADO handle
 ** @wtxCtx a valid wtx function handle
 ** @note: in simulation mode alway return string "simu"
 **----------------------------------------------------------*/
PUBLIC void *tornadoExecFuncCall (TORNADO_id *tornadoId, WTX_CONTEXT_DESC *wtxCtx) {
  WTX_CONTEXT_ID_T funcId;
  void *result;

  if (tornadoId== NULL) goto errTornadoId;
  if (tornadoId->wtxId == NULL) goto errWtxId;
  /*
   * spwan task and take exec function wtxCtx id 
   */
  funcId = tornadoExecFuncSpawn (tornadoId, wtxCtx);

  /*
   * wait for result and return it 
   */
#ifndef WTX_SIMULATION
  result = tornadoExecWaitReturn (tornadoId, funcId);
#else
  result = "Simu";
#endif

  return (result); // ------------------ OK ----------------


 errTornadoId:
   jWrapPanic (NULL,"ERROR: tornadoExecFuncCall TornadoId==NULL [Check calling syntaxe]!!!\n");
   return NULL;

 errWtxId:
   jWrapPanic (NULL,"ERROR: tornadoExecFuncCall TornadoId->wtxId==NULL [not bind|connected]\n");
   return NULL;
}				/*
				 * end tornadoFuncCall 
				 */
