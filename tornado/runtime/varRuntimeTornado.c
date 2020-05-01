/*
 *  Copyright(c) 1998-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   varTornado.c provide access to instance and static var
 * Projet    :   jWrap
 * Module    :   WTX VxWorks Tornado Interface
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/runtime/varRuntimeTornado.c,v $
 *
 * Modification History
 * --------------------
 * 01c,02feb99,Fulup,externalized WTX module
 * 01b,04jul98,Fulup,ispell code
 * 01a,18feb98,Fulup,written
 */

/* ----------------------------------------------------------------
 *  Mapping of static and public variables from VxWOrks target
 *  to tclsh is not operationnal in current version.
 *  ---------------------------------------------------------------*/

#include "libRuntimeTornado.h"
#include <string.h>

// define or global array name
EXPORT Tcl_Obj       *tornadoGlobalVar;

/******************************************************************
 ** Generic call-back for variable trace
 ******************************************************************/
LOCAL char *traceCallback (JWRAP_vars *clientData, Tcl_Interp *interp
                          , char *name1, char *name2, int flag) {
  int status;
  Tcl_Obj *valueObj;
  TORNADO_infos *info;
  long checksum;

  // prepare emergency panic return
  if (setjmp (jWrapCheckPoint)) {
    return jWrapStaticMessage;
  }

  // get info TORNADO struct from client data
  info = (TORNADO_infos*) clientData->info;

  // Check we got variable address at first exec
  if (clientData->address == NULL) {
    clientData->address = (void*) tornadoExecFindSymbol (info->tornadoId, name2);
    jWrapLog (5,"tornadoTraceCallBack: @%s=%#x\n", name2, clientData->address);
    if (clientData->address == NULL) goto errUnknownVar;
  }

  if (flag & TCL_TRACE_READS) {
       // If this is not first call we check for previous checksum
       if (clientData->previous != NULL) {
         checksum = wtxMemChecksum (info->tornadoId->wtxId
         ,(TGT_ADDR_T) clientData->address
         , (unsigned long)clientData->jwType->size);

	 // If checksum did not change return current external rep
         if (checksum == (long)clientData->previous) return NULL;
	 clientData->previous = (void*) checksum;
       }

       // get new object attached to our array
       valueObj = Tcl_ObjGetVar2 (interp, clientData->array
       , clientData->index, TCL_GLOBAL_ONLY);
       if (valueObj == NULL) goto invalidObj;

       // effectively update data in C++ area
       valueObj->internalRep.longValue = 0;
       if (WTX_ERROR == (INT32) wtxMemRead (info->tornadoId->wtxId
            , (TGT_ADDR_T) clientData->address
            , &valueObj->internalRep
            , clientData->jwType->size)) goto errWtxMemRead;

       valueObj->bytes=NULL;
       valueObj->typePtr = clientData->jwType->obj;
  }

  if (flag & TCL_TRACE_WRITES) {
       // get new object attached to our array
       valueObj = Tcl_ObjGetVar2 (interp, clientData->array
       , clientData->index, TCL_GLOBAL_ONLY);
       if (valueObj == NULL) goto invalidObj;

       // check if we are facing a cookie or not
       if (clientData->jwType->magic == JWRAP_COOKIE) goto cannotWriteCookie;

       // variable as been written in Tcl update C++ image
       status = Tcl_ConvertToType (interp, valueObj, clientData->jwType->obj);
       if (status != TCL_OK) return (clientData->tclObj->bytes);

       // effectively update data in C++ area
       if (WTX_ERROR == (INT32) wtxMemWrite (info->tornadoId->wtxId
            , &valueObj->internalRep
            , (TGT_ADDR_T) clientData->address
            , clientData->jwType->size)) goto errWtxMemWrite;
  }

  // Trace ended Variable as been unregistrated
  if  (flag & TCL_TRACE_UNSETS) {
      if (clientData->jwType->size > sizeof (double)) Tcl_Free(clientData->previous);
      Tcl_DecrRefCount (clientData->tclObj);
      Tcl_DecrRefCount (clientData->array);
      Tcl_DecrRefCount (clientData->index);
      Tcl_Free ((char*)clientData);
  }

  return NULL;    // we got C++ value

errUnknownVar:
   jWrapPanic (NULL,"Unknown public var %s on target\n", name2);

invalidObj:
   jWrapPanic (NULL,"cannot find jwrap var %s(%s)",name1, name2);

cannotWriteCookie:
   jWrapPanic (NULL,"jwrap cookie are read only %s(%s)",name1, name2);

errWtxMemRead:
  jWrapPanic (NULL,"tornadoVarTrace can't read target <0x%lx> ram area\nWTX_ErrMsg=[%s]\n"
            , (TGT_ADDR_T) clientData->address
            , wtxErrMsgGet (info->tornadoId->wtxId));

errWtxMemWrite:
  jWrapPanic (NULL,"tornadoVarTrace can't write target <0x%lx> ram area\nWTX_ErrMsg=[%s]\n"
            , (TGT_ADDR_T) clientData->address
            , wtxErrMsgGet (info->tornadoId->wtxId));

return NULL; // for gcc warnings
} // end trace proc

/******************************************************************
 ** register a new var as a var like type
 ******************************************************************/
RESTRICTED JWRAP_vars* tornadoVarRegister (TORNADO_infos *info, Tcl_Interp *interp
                             ,Tcl_Obj *jTclObj
                             , char *varName, int len
                             , JWRAP_types *jwType) {
  JWRAP_vars *variable;
  Tcl_Obj    *jTclIndex;
  int        status;

  // We dont support complex structure mapping
  if (jwType->magic ==  JWRAP_STRUCT) goto cannotSetTrace;

  // build on structure for each var
  variable = (JWRAP_vars*)Tcl_Alloc (sizeof (JWRAP_vars));
  if (variable == NULL) goto errorMalloc;

  // store TORNADO info struct in order variable to know about WTX link
  variable->info = (ClientData) info;

  // create a tempry object for index in jTcl object
  jTclIndex = Tcl_NewStringObj (varName, len);

  // Check if this is an object or an ordinary C procedure
  if (jTclObj != NULL) {
    variable->array   = jTclObj;
    // set tcl object inside jTcl array
    variable->tclObj  = Tcl_ObjSetVar2 (interp, jTclObj
    , jTclIndex, Tcl_NewObj(), TCL_GLOBAL_ONLY);

    // register trace method WARNING: Object version no available
    status = Tcl_TraceVar2 (interp, TCL_STRING (jTclObj), varName
         , TCL_TRACE_WRITES | TCL_TRACE_READS| TCL_GLOBAL_ONLY|TCL_TRACE_UNSETS
         ,(Tcl_VarTraceProc*)traceCallback, (ClientData)variable);

  } else {
    // get tcl object as global
    variable->array   = tornadoGlobalVar;
    variable->tclObj  = Tcl_ObjSetVar2 (interp,tornadoGlobalVar,jTclIndex
                      ,Tcl_NewObj(),TCL_GLOBAL_ONLY);

    if (variable->tclObj == NULL) goto errorRegistering;

    // register trace method WARNING: Object version no available
    status = Tcl_TraceVar2 (interp, TCL_STRING (tornadoGlobalVar), varName
        , TCL_TRACE_WRITES | TCL_TRACE_READS| TCL_GLOBAL_ONLY|TCL_TRACE_UNSETS
        , (Tcl_VarTraceProc*)traceCallback, (ClientData)variable);
  }

  if (status != TCL_OK) goto cannotSetTrace;

  // finish or traced object with common thing
  variable->index       = jTclIndex;
  variable->address      = NULL;
  variable->jwType      = jwType;
  variable->previous    = NULL; // area will be allocated later if needed
  Tcl_IncrRefCount (variable->tclObj);
  Tcl_IncrRefCount (variable->array);
  Tcl_IncrRefCount (variable->index);

  return (variable);   // Any error is fatal and break program exec

cannotSetTrace:
 jWrapPanic (NULL,"tornadoRegisterVar cannot set trace var=%s type=%s"
            ,varName,jwType->obj->name);

errorMalloc:
 jWrapPanic (NULL,"tornadoRegisterVar: can't malloc objType var=%s type=%s"
           ,varName,jwType->obj->name);

errorRegistering:
 jWrapLog   (1,"WARNING tornadoRegistervar: cannot regitering twice |%s|\n"
           , varName);
 return NULL;
} // end jWrapRegistervar


/** -------------------------------------------------------------------------
 ** Create Tronado array for VxWorks global variables on target
 ** -------------------------------------------------------------------------*/
RESTRICTED void tornadoVarInit (Tcl_Interp *interp) {

   tornadoGlobalVar     = Tcl_NewStringObj("TORNADO" ,-1) ; Tcl_IncrRefCount(jWrapGlobalVar);
}
