/*
 *      Copyright(c) 1998-99 Fridu a Free Software Company Fulup Ar Foll
 *
 * File         : attachRuntimeTornado.c  Connect ctWtr to target server
 * Projet       : jWrap
 * SubModule    : Wtx VxWorks/Tornado interface
 * Auteur       : Fulup Ar Foll (Fulup@fridu.bzh)
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/19 08:09:27 $
 *      Revision    : $Revision: 1.4 $
 *      Source      : $Source: /Master/jWrap/tornado/runtime/attachRuntimeTornado.c,v $
 *
 * Modification History
 * ---------------------
 * 1.5  1999/03/15 Fulup, check registry is a valid hostname
 * 1.4  1999/02/18 Fulup, added WTX message on Register function
 * 1.3  1999/02/16 Fulup, extracted WTX module
 * 1.2  1998/05/06 Fulup, Adapted to jWrap
 * 1.1  1996/05/13 Fulup, Writen
 *
 */


#include "libRuntimeTornado.h"

#include <fcntl.h>
#include <loadlib.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

// TORNADO_id are linking for emergency exit
EXPORT TORNADO_id *tornadoIdHead = NULL;

/** -----------------------------------------------------------------
 ** Provides basic interaface for target attachement thru WTX
 ** protocole.
 ** ----------------------------------------------------------------*/
PUBLIC void  tornadoReconnect (TORNADO_id * tornadoId) {
  WTX_CONTEXT_DESC wtxCtx;
  char             vioDev[15];
  int              status;
  TGT_ADDR_T       vioStrAdr=0;
  UINT32           vioStrSize;

  /* check wtx as been initialized for this handle */
  if (tornadoId->vIoNum == 0) goto errHandle;

  // try detaching first
  wtxToolDetach (tornadoId->wtxId);

  /*
   * attach ctTornado to a target server
   */
  if (wtxToolAttach (tornadoId->wtxId, tornadoId->targetName
     , tornadoId->toolName) == WTX_ERROR) {
     goto errAttach;
  }

  /*
   * get registrated for event return
   */
  if (wtxRegisterForEvent (tornadoId->wtxId, ".*") == WTX_ERROR)
    goto errRegister;

  /*
   * set vio channel
   */
  tornadoId->vIoNum = wtxVioChanGet (tornadoId->wtxId);
  if (tornadoId->vIoNum == WTX_ERROR) goto errVioGet;

  /*
   * build vio file name
   */
  vioStrSize = sprintf (vioDev, "/vio/%d", (int)tornadoId->vIoNum) + 1;
  jWrapLog (3, "tornadoConnect: tornadoVio [%s] tornadoId=%#p\n", vioDev,tornadoId);

  /*
   * alloc space for vio name
   */
  vioStrAdr = wtxMemAlloc (tornadoId->wtxId, vioStrSize);
  if (vioStrAdr == (TGT_ADDR_T) NULL)
    goto errWtxMalloc;

    /*
     * copy vioName to tornadoMemPool area
     */
    if (WTX_ERROR == (INT32) wtxMemWrite (tornadoId->wtxId, vioDev
       , vioStrAdr, vioStrSize)) {
      goto errWtxMemWrite;
    }

  /*
   * fill spawn structure in order to execute open
   */
  memset (&wtxCtx, 0, sizeof (WTX_CONTEXT_DESC));
  wtxCtx.name  = "open";
  wtxCtx.entry = tornadoExecFindSymbol (tornadoId,"open");
  wtxCtx.args[0] = vioStrAdr;
  wtxCtx.args[1] = 2;
  wtxCtx.args[2] = 0;

  tornadoId->vOut = (UINT32) tornadoExecFuncCall (tornadoId, &wtxCtx);

  if (tornadoId->vOut == TORNADO_ERROR) goto errVioOpen;
  jWrapLog (2, "tornadoReconnect: tornadoVio [%s:%d]\n",vioDev, tornadoId->vOut);

  return;

errHandle:
  jWrapPanic (NULL,"ERROR: tornadoReconnect should connect before reconnect"
	      ,tornadoId->targetName
	      ,tornadoId->toolName
	      ,wtxErrMsgGet (tornadoId->wtxId));
errAttach:
  jWrapPanic (NULL,"ERROR: tornadoReconnect can't attach %s:%s\nWTX_ErrMsg=[%s]\n"
	      ,tornadoId->targetName
	      ,tornadoId->toolName
	      ,wtxErrMsgGet (tornadoId->wtxId));
errRegister:
  jWrapPanic (NULL,"ERROR: tornadoReconnect can't register for event %s:%s\nWTX_ErrMsg=[%s]\n"
	      ,tornadoId->targetName
	      ,tornadoId->toolName
	      ,wtxErrMsgGet (tornadoId->wtxId));
errVioGet:
  jWrapPanic (NULL,"ERROR: tornadoReconnect can't wtxVioChanelGet:%s [%s]\n"
	      ,tornadoId->targetName
	      ,wtxErrMsgGet (tornadoId->wtxId));

errWtxMalloc:
  jWrapPanic (NULL,"ERROR: tornadoReconnect can't alloc tornadoMemPool:%s WTX_ErrMsg=[%s]\n"
	      ,tornadoId->targetName
	      ,wtxErrMsgGet (tornadoId->wtxId));

errWtxMemWrite:
  wtxTerminate (tornadoId->wtxId);
  jWrapPanic (NULL,"ERROR: tornadoReconnect,can't copy %s to wtxMemPool [0x%x]\nWTX_ErrMsg=[%s]\n"
	      ,vioDev, vioStrAdr, wtxErrMsgGet (tornadoId->wtxId));

errVioOpen:
  wtxTerminate (tornadoId->wtxId);
  jWrapPanic (NULL,"ERROR: tornadoReconnect, can't open %s on target\nWTX_ErrMsg=[%s]\n"
	      ,vioDev, wtxErrMsgGet (tornadoId->wtxId));

}

/**------------------------------------------------------------------
 ** tornadoConnect connect to a target server depending of TORNADO_id contend
 ** @param  tornadoId super handle to WTX connection
 ** @return a fully filled TORNADO handle, a status or error message
 ** thru jWrapPanic.
 ** @see tornadoEnd
 **------------------------------------------------------------------*/
PUBLIC STATUS tornadoConnect (TORNADO_id * tornadoId) {
  static int       count = 0;
  TGT_ADDR_T       vioStrAdr=0;
  UINT32           vioStrSize;
  WTX_CONTEXT_DESC wtxCtx;
  char             vioDev[15];
  char             *registry;
  struct hostent   *hostenv;

  /*
   * check user did no forget
   */
  registry = getenv ("WIND_REGISTRY");
  if (registry == NULL) goto errRegistery;

  /* check registry is a vlaid host name */
  hostenv =  gethostbyname (registry);
  if (hostenv == NULL) goto errHostname;

  /*
   * check hostname name
   */
  if (tornadoId->targetName == NULL)
    goto noHostname;

  /* check wtx as been initialized for this handle */
  if (tornadoId->vIoNum == 0) {
     if (wtxInitialize (&tornadoId->wtxId) != WTX_OK) goto errWtxInit;
  }

  /*
   * provide a default tool name
   */
  if (tornadoId->toolName == NULL) {
    tornadoId->toolName = Tcl_Alloc (10);

    sprintf (tornadoId->toolName, "jWrap_%d", count++);
    jWrapLog (2, "tornadoConnect: default name for toolName=[%s]\n", tornadoId->toolName);
  }
  /*
   * attach ctTornado to a target server
   */
  if (wtxToolAttach (tornadoId->wtxId, tornadoId->targetName
     , tornadoId->toolName) == WTX_ERROR) {
     goto errAttach;
  }
  /*
   * get registrated for event return
   */
  if (wtxRegisterForEvent (tornadoId->wtxId, ".*") == WTX_ERROR)
    goto errRegister;

  /*
   * set vio channel
   */
  tornadoId->vIoNum = wtxVioChanGet (tornadoId->wtxId);
  if (tornadoId->vIoNum == WTX_ERROR)
    goto errVioGet;

  /*
   * build vio file name
   */
  vioStrSize = sprintf (vioDev, "/vio/%d", (int)tornadoId->vIoNum) + 1;
  jWrapLog (3, "tornadoConnect: tornadoVio [%s] tornadoId=%#p\n", vioDev,tornadoId);

  /*
   * alloc space for vio name
   */
  vioStrAdr = wtxMemAlloc (tornadoId->wtxId, vioStrSize);
  if (vioStrAdr == (TGT_ADDR_T) NULL)
    goto errWtxMalloc;

    /*
     * copy vioName to tornadoMemPool area
     */
    if (WTX_ERROR == (INT32) wtxMemWrite (tornadoId->wtxId, vioDev
       , vioStrAdr, vioStrSize)) {
      goto errWtxMemWrite;
    }

  /*
   * fill spawn structure in order to execute open
   */
  memset (&wtxCtx, 0, sizeof (WTX_CONTEXT_DESC));
  wtxCtx.name  = "open";
  wtxCtx.entry = tornadoExecFindSymbol (tornadoId,"open");
  wtxCtx.args[0] = vioStrAdr;
  wtxCtx.args[1] = 2;
  wtxCtx.args[2] = 0;

  tornadoId->vOut = (UINT32) tornadoExecFuncCall (tornadoId, &wtxCtx);

  if (tornadoId->vOut == TORNADO_ERROR) goto errVioOpen;
  jWrapLog (2, "tornadoConnect: tornadoVio [%s:%d]\n",vioDev, tornadoId->vOut);

  // setup endian type for gopher
  tornadoId->hostEndian = checkEndian ();

  switch (wtxTargetEndianGet (tornadoId->wtxId)) {
  case WTX_ENDIAN_BIG:
    tornadoId->targetEndian  =  ENDIAN_IS_BIG;
    break;
  case WTX_ENDIAN_LITTLE:
    tornadoId->targetEndian  =  ENDIAN_IS_LITTLE;
    break;
  default:
     tornadoId->targetEndian =  ENDIAN_IS_UNKNOW;
  }

  // register tornadoId in linked list
  if (tornadoIdHead == NULL) {
    tornadoId->next = NULL;
  } else {
    tornadoId->next = tornadoIdHead;
  }
  tornadoIdHead = (void*)tornadoId;

  jWrapLog (2,"tornadoConnect: [%s:%s]\n", tornadoId->targetName, tornadoId->toolName);

  return TORNADO_OK;

  /*
   * ------------ ERROR ------------------
   */
errRegistery:
  jWrapPanic (NULL,"ERROR: tornadoConnect WIND_REGISTRY should point our registry server[%s]\n"
	      ,registry);

noHostname:
  jWrapPanic (NULL,"ERROR: tornadoConnect target host name is mandatory\n");

errHostname:
  jWrapPanic (NULL,"ERROR: tornadoConnect registry hostname [%s] unknow/invalid\n", registry);

errWtxInit:
  jWrapPanic (NULL, "ERROR: tornadoConnect INIT WTX FAILED\n");

errAttach:
  jWrapPanic (NULL,"ERROR: tornadoConnect can't attach %s:%s\nWTX_ErrMsg=[%s]\n"
	      ,tornadoId->targetName
	      ,tornadoId->toolName
	      ,wtxErrMsgGet (tornadoId->wtxId));
errRegister:
  jWrapPanic (NULL,"ERROR: tornadoConnect can't register event %s\nWTX_ErrMsg=[%s]\n"
	      ,tornadoId->targetName
	      ,wtxErrMsgGet (tornadoId->wtxId));

errVioGet:
  jWrapPanic (NULL,"ERROR: tornadoConnect can't wtxVioChanelGet:%s [%s]\n"
	      ,tornadoId->targetName
	      ,wtxErrMsgGet (tornadoId->wtxId));

errWtxMalloc:
  jWrapPanic (NULL,"ERROR: tornadoConnect can't alloc tornadoMemPool:%s WTX_ErrMsg=[%s]\n"
	      ,tornadoId->targetName
	      ,wtxErrMsgGet (tornadoId->wtxId));

errWtxMemWrite:
  wtxTerminate (tornadoId->wtxId);
  jWrapPanic (NULL,"ERROR: tornadoConnect,can't copy %s to wtxMemPool [0x%x]\nWTX_ErrMsg=[%s]\n"
	      ,vioDev, vioStrAdr, wtxErrMsgGet (tornadoId->wtxId));

errVioOpen:
  wtxTerminate (tornadoId->wtxId);
  jWrapPanic (NULL,"ERROR: tornadoConnect, can't open %s on target\nWTX_ErrMsg=[%s]\n"
	      ,vioDev, wtxErrMsgGet (tornadoId->wtxId));

  return JWRAP_IMPOSSIBLE;	// for Gcc not to complain

}				/*
				 * end tornadoConnect
				 */

/**------------------------------------------------------
 ** close/free Tornado/Wtx connection, close vio create
 ** in tornadoConnect, and detach from target server
 ** this function is usually called automatically with
 ** Ctrl-C handler [Unix Only] or Tcl exit command
 ** @param  tornadoId connecttion handle
 ** @return status or error message thru jWrapPanic
 ** @see tornadoCtrlC
 ** @see tornadoExit
 **------------------------------------------------------*/
PUBLIC STATUS
tornadoEnd (TORNADO_id * tornadoId)
{
  int status;
  char vioDev[20];
  WTX_CONTEXT_DESC wtxCtx;
  TORNADO_id *tornadoId2;
  TORNADO_id *tornadoId1=NULL;

  // Check in list for our ID
  for (tornadoId2 = tornadoIdHead;  tornadoId2 != NULL; tornadoId2 = (TORNADO_id*)tornadoId->next) {
    if (tornadoId2 == tornadoId) break;
    tornadoId1 = tornadoId2;
  }
  if (tornadoId2 == NULL) goto errTornadoId;

  // Remove current tornadoId fromp linked list
  if (tornadoId1 == NULL) {
    tornadoIdHead = tornadoIdHead->next;
  } else {
    tornadoId1->next = tornadoId2->next;
  }

  jWrapLog (2,"tornadoEnd [%s->%s tornadoId=0x%p]\n",tornadoId->targetName, tornadoId->toolName, tornadoId);


  /*
   * build vioDevName for error message
   */
  sprintf (vioDev, "/vio/%d", tornadoId->vIoNum);

  /*
   * fill spawn structure in order to execute close
   */
  memset (&wtxCtx, 0, sizeof (WTX_CONTEXT_DESC));
  wtxCtx.entry = tornadoExecFindSymbol (tornadoId,"close");
  wtxCtx.name = "close";
  wtxCtx.args[0] = tornadoId->vOut;
  wtxCtx.args[2] = 0;

  status = (UINT32) tornadoExecFuncCall (tornadoId, &wtxCtx);

  if (status == WTX_ERROR) goto errVioClose;

  jWrapLog (5,"tornadoEnd close vIO %s:%d=%d\n",vioDev, tornadoId->vOut, status);

  /*
   * now vIO as been close free VIO channel
   */
  if (WTX_ERROR == wtxVioChanRelease (tornadoId->wtxId, tornadoId->vIoNum)) goto errVioFree;

  /* finally detact from Tornado target server */
  if (WTX_ERROR == wtxToolDetach (tornadoId->wtxId)) goto errDetach;
  jWrapLog (5, "tornadoEnd: wtxToolDetach\n");

  /* terminate connectin and free all remainning ressources */
  if (WTX_ERROR == wtxTerminate (tornadoId->wtxId)) goto errTerminate;
  jWrapLog (5, "tornadoEnd: wtxTerminate\n");

  // force next connect to rebuild connection
  tornadoId->vIoNum = 0;

  return TORNADO_OK;

  /* --------------------------- ERROR ----------------------------- */
 errTornadoId:
  jWrapPanic (NULL,"tornadoEnd <0x%x> is not a valid connected tornadoId\n",tornadoId);

 errVioClose:
  jWrapPanic (NULL,"tornadoEnd vIO target target failed %s:%d WTX_ErrMsg=[%s]\n"
	     ,vioDev, tornadoId->vOut, wtxErrMsgGet (tornadoId->wtxId));

 errVioFree:
  jWrapPanic (NULL,"tornadoEnd can't wtxVioChanelRelease:%s WTX_ErrMsg=[%s]\n"
	     ,tornadoId->targetName
	     ,wtxErrMsgGet (tornadoId->wtxId));

 errDetach:
  jWrapPanic (NULL,"tornadoEnd can't wtxToolDetach:%s WTX_ErrMsg=[%s]\n"
	     ,tornadoId->targetName
	     ,wtxErrMsgGet (tornadoId->wtxId));

 errTerminate:
  jWrapPanic (NULL,"tornadoEnd can't wtxTerminate:%s WTX_ErrMsg=[%s]\n"
	     ,tornadoId->targetName
	     ,wtxErrMsgGet (tornadoId->wtxId));

  return JWRAP_IMPOSSIBLE; // for gcc not to complain
}				/*
				 * end tornadoEnd
				 */

