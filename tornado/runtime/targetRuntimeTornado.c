/*
 *
 *  Copyright(c) 1998-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   targetRuntimeTornado.c interface some usefull routine on target
 * Projet    :   jWrap
 * Module    :   WTX VxWorks Tornado interface
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/runtime/targetRuntimeTornado.c,v $
 *
 * Modification History
 * --------------------
 * 01b,16feb99,Fulup externalized WTX module
 * 01a,05jun98,Fulup written
 */

/** -----------------------------------------------------------------
 ** make jWrap structure to be allocated with target malloc
 ** scheme. This allows a target program to free a tclsh allocated
 ** structure. Nevertheless as block is allocated in VxWorks system
 ** pool a small allocation take more space & time than a wtxMemAlloc.
 ** In order validating it wrapper should be complied with
 ** -DUSE_TARGET_MALLOC
 ** Execpt in specific case this option should be advoid.
 ** ------------------------------------------------------------------*/

#include "libRuntimeTornado.h"

#include <string.h>
#include <stdlib.h>
  
  static   WTX_CONTEXT_DESC mallocWtxCtx;
  static   WTX_CONTEXT_DESC freeWtxCtx;


/**-----------------------------------------------------------------
 ** Allocate and set to zero a new instance of Structs, note than
 ** we use ptr2 in order not breaking Tcl internal object type
 ** this is important when Tcl provide a valid list, and save
 ** time in TornadoUpdateType routine
 **-----------------------------------------------------------------*/
RESTRICTED int tornadoTargetTypeTcl2Cc (TORNADO_infos *info, Tcl_Interp *interp
       , JWRAP_structs *structure, Tcl_Obj * srcObj, Tcl_Obj *destObj) {
  int status;

  // if we are not comming from a jWrap new source==destination
  if (destObj == NULL) {
    // source and destination are equivalent
    destObj=srcObj;
    // build a dummy source objet to hold list internal rep
    srcObj = Tcl_NewObj();
    memcpy (srcObj, destObj, sizeof (Tcl_Obj));
    // invalidate previous external rep to advoid dual free
    destObj->bytes = NULL;
  }

  // type our resulting objet now
  destObj->typePtr = structure->type->obj;

  // check user does not want a null pointer
  if ((TCL_STRING(srcObj) != NULL) && (!strcmp (TCL_STRING(srcObj), jWrapStringNull))) {
    destObj->internalRep.twoPtrValue.ptr1 = NULL;
    destObj->internalRep.twoPtrValue.ptr2 = NULL;
    return TCL_OK;
  }

  // use dest ptr2 to hold a backward link on source pointer
  destObj->internalRep.twoPtrValue.ptr2 = srcObj;
  Tcl_IncrRefCount (srcObj);

  // protect our self from unbinded module
  if (info->tornadoId->wtxId == NULL) goto errNotBind;

  // prepare remote exec on target
  mallocWtxCtx.args[0] = structure->type->size;
  mallocWtxCtx.args[1] = 0;

  destObj->internalRep.longValue = (TGT_ADDR_T) tornadoExecFuncCall (info->tornadoId, &mallocWtxCtx);
  if (destObj->internalRep.longValue == 0) goto errWtxMalloc;

  // copy external rep onto target
  if (WTX_ERROR == (INT32) wtxMemSet   (info->tornadoId->wtxId
     , destObj->internalRep.longValue, structure->type->size,'\0')) goto errWtxMemWrite;

  jWrapLog (4,"tornadoTargetTypeTcl2Cc: 0x%x = malloc (%d)\n"
     ,destObj->internalRep.longValue
     ,structure->type->size);

  // Start filling our struct
  status = tornadoTypeUpdate (info,interp,structure, srcObj, destObj);

  // Invalidate external rep
  destObj->bytes = NULL;

  return status; // ------ OK ---------  

errWtxMalloc: // ---------------------- ERROR -------------------
  jWrapPanic (interp,"tornadoTargetTypeTcl2Cc can't alloc tornadoMemPool:%s WTX_ErrMsg=[%s]\n"
	     ,info->tornadoId->targetName
	     ,wtxErrMsgGet (info->tornadoId->wtxId));

errWtxMemWrite:
  jWrapPanic (interp,"tornadoTargetTypeTcl2Cc can't copy %s to wtxMemPool <0x%lx> WTX_ErrMsg=[%s]\n"
	      ,srcObj->bytes, destObj->internalRep.longValue, wtxErrMsgGet(info->tornadoId->wtxId));

errNotBind:
  jWrapPanic (interp,"tornadoTargetTypeTcl2Cc module is not bind\n");

return JWRAP_IMPOSSIBLE;

}

/**********************************************************************
 ** Update Internal string value
 ** Malloc equivalent area on target and copy external rep into it
 ** Save remote target string adress as tcl object internal rep
 ** @info backward link in tornado module
 ** tclObbj tcl object with a valid external rep
 ** @note if external rep is <NULL> we set internal rep to zero.
 **********************************************************************/
RESTRICTED int tornadoTargetStringTcl2Cc (TORNADO_infos *info,Tcl_Interp *interp,Tcl_Obj *tclObj)
{
  TGT_ADDR_T strAdr;

  // check user does not want a null pointer
  if (!strcmp (TCL_STRING(tclObj), jWrapStringNull)) {
    tclObj->internalRep.twoPtrValue.ptr1 = NULL;
    tclObj->internalRep.twoPtrValue.ptr2 = NULL;
    tclObj->typePtr = info->stringType;
    return TCL_OK;
  }

  // prepare remote exec on target
  mallocWtxCtx.args[0] = tclObj->length+1;
  mallocWtxCtx.args[1] = 0;

  strAdr = (TGT_ADDR_T) tornadoExecFuncCall (info->tornadoId, &mallocWtxCtx);
  if (strAdr == (TGT_ADDR_T) NULL) goto errWtxMalloc;

  jWrapLog (4,"tornadoTargetStringTcl2Cc: strAdr=0x%p\n", strAdr);

  // copy external rep onto target
  if (WTX_ERROR == (INT32) wtxMemWrite (info->tornadoId->wtxId
     , tclObj->bytes, strAdr, (unsigned)tclObj->length+1)) goto errWtxMemWrite;

  // place string addr
  tclObj->internalRep.twoPtrValue.ptr1= (void*) strAdr;
  tclObj->typePtr = info->stringType;
  return TCL_OK;

errWtxMalloc: // ---------------------- ERROR -------------------
  jWrapPanic (interp,"tornadoTargetStringTcl2Cc can't alloc tornadoMemPool:%s WTX_ErrMsg=[%s]\n"
	     ,info->tornadoId->targetName
	     ,wtxErrMsgGet (info->tornadoId->wtxId));

errWtxMemWrite:
  jWrapPanic (interp,"tornadoTargetStringTcl2Cc,can't copy %s to wtxMemPool [0x%x] WTX_ErrMsg=[%s]\n"
	      ,tclObj->bytes, strAdr, wtxErrMsgGet (info->tornadoId->wtxId));

  return JWRAP_IMPOSSIBLE;
}

/**********************************************************************
 ** Free a previousselly malloced struc or string on target
 **********************************************************************/
RESTRICTED void tornadoTargetTypeFree (TORNADO_infos *info,Tcl_Obj *tclObj) {
  // prepare emergency panic return mandatory for jWrapPanic in tornadoExecCall
  if (setjmp (jWrapCheckPoint)) {
   return;
  }
  // place string address in long value for C
  jWrapLog (5,"tornadoTargetTypeFree:0x%lx\n", tclObj->internalRep.longValue);

  // prepare remote exec on target
  freeWtxCtx.args[0] = tclObj->internalRep.longValue;
  freeWtxCtx.args[1] = 0;

  (void) tornadoExecFuncCall (info->tornadoId, &freeWtxCtx);

  // now free source internal list rep
  if (tclObj->internalRep.twoPtrValue.ptr2 != NULL) {
     Tcl_DecrRefCount((Tcl_Obj*)tclObj->internalRep.twoPtrValue.ptr2); 
  }
}

/**********************************************************************
 ** Free a previousselly malloced struc or string on target
 **********************************************************************/
RESTRICTED void tornadoTargetStringFree (TORNADO_infos *info,Tcl_Obj *tclObj) {
  // prepare emergency panic return mandatory for jWrapPanic in tornadoExecCall
  if (setjmp (jWrapCheckPoint)) {
   return;
  }
  // place string address in long value for C
  jWrapLog (5,"tornadoTargetStringFree:0x%lx\n", tclObj->internalRep.longValue);

  // prepare remote exec on target
  freeWtxCtx.args[0] = tclObj->internalRep.longValue;
  freeWtxCtx.args[1] = 0;

  (void) tornadoExecFuncCall (info->tornadoId, &freeWtxCtx);

}

/**********************************************************************
 ** Prepare malloc and free function exec context
 **********************************************************************/
RESTRICTED void tornadoTargetInit (Tcl_Interp *interp) {

  memset (&mallocWtxCtx, 0, sizeof (WTX_CONTEXT_DESC));
  memset (&freeWtxCtx, 0, sizeof (WTX_CONTEXT_DESC));
  mallocWtxCtx.name  = "malloc";
  freeWtxCtx.name    = "free";
}
