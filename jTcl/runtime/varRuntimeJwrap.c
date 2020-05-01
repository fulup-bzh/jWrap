/*
 *  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   varWrap.c provide access to instance and static var
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/runtime/varRuntimeJwrap.c,v $
 *
 * Modification History
 * --------------------
 * 01b,04jul98,Fulup ispell code and documented
 * 01a,18feb98,Fulup,written
 */


#include "libRuntimeJwrap.h"
#include <string.h>

// Gobal variables array name
EXPORT  Tcl_Obj       *jWrapGlobalVar;

/******************************************************************
 * Generic call-back for variable trace. This routine is call each
 * time a C/Tcl mapped variable is used by interpretor. It manages to
 * update TCL variable internal rep depending on effective C value.
 * @note TCL C/Tcl variable mapping is not very efficient and
 * each time it is possible user should prefer changing C variable
 * state thru a procedure.
 * @note external representation is update only when internal rep
 * change, check is done with a memcmp call and result will be
 * incoherent when mapped variable is a pointer address and only
 * pointer contend change.
 ******************************************************************/
LOCAL char *traceCallback (JWRAP_vars *clientData, Tcl_Interp *interp
                          , char *name1, char *name2, int flag) {
  int status;
  Tcl_Obj *valueObj;

  // prepare emergency panic return
  if (setjmp (jWrapCheckPoint)) {
    return jWrapStaticMessage;
  }

  if (flag & TCL_TRACE_READS) {
       // if not already done if is time to allocate cache area
       if (clientData->previous == NULL) {
          // for small data we use a static buffer for big one we allocate one if needed
          if (clientData->jwType->size <= sizeof (double)) {
             clientData->previous=&clientData->internalRep;
           } else {
             clientData->previous = Tcl_Alloc (clientData->jwType->size);
             if (clientData->previous == NULL) goto errorMalloc;
           }
       } else {
         // cache data in order boosting script
         if (!memcmp (clientData->address,clientData->previous,clientData->jwType->size)) {
           return NULL;
         }
       }

       // get new object attached to our array
       valueObj = Tcl_ObjGetVar2 (interp, clientData->array, clientData->index, TCL_GLOBAL_ONLY);
       if (valueObj == NULL) goto invalidObj;

       // transfer C++ to TCL objc and then try invalidate external representation
       memcpy (&valueObj->internalRep,clientData->address,clientData->jwType->size);

       valueObj->bytes=NULL;
       valueObj->typePtr = clientData->jwType->obj;

       // save value for next run
       memcpy (clientData->previous,clientData->address,clientData->jwType->size);

  }

  if (flag & TCL_TRACE_WRITES) {
       // get new object attached to our array
       valueObj = Tcl_ObjGetVar2 (interp, clientData->array, clientData->index, TCL_GLOBAL_ONLY);
       if (valueObj == NULL) goto invalidObj;

       // check if we are facing a cookie or not
       if (clientData->jwType->magic == JWRAP_COOKIE) goto cannotWriteCookie;

       // convert to our wanted application type
       if ((valueObj->typePtr == 0) || (valueObj->typePtr == jWrapTypeList)) {
          status = ((Function*)clientData->jwType->obj->setFromAnyProc)
                   (interp, valueObj,NULL);
          if (status != TCL_OK) return (clientData->tclObj->bytes);
          valueObj->typePtr = clientData->jwType->obj;
       } else if (valueObj->typePtr->updateStringProc
         != clientData->jwType->obj->updateStringProc) {
         return (clientData->tclObj->bytes);
       }

       // effectively update data in C++ area
       memcpy (clientData->address, &valueObj->internalRep, clientData->jwType->size);

       // save value for next run
       if (clientData->previous == NULL) {
         // for small data we use a static buffer for big one we allocated one if needed
         if (clientData->jwType->size <= sizeof (double)) {
            clientData->previous=&clientData->internalRep;
         } else {
            clientData->previous = Tcl_Alloc (clientData->jwType->size);
            if (clientData->previous == NULL) goto errorMalloc;
         }
       }
       memcpy (clientData->previous,clientData->address,clientData->jwType->size);
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

invalidObj:
   jWrapPanic (NULL,"cannot find jwrap var %s(%s)",name1, name2);
   return (jWrapStaticMessage);

errorMalloc:
   jWrapPanic (NULL,"cannot write jwrap var %s(%s)",name1, name2);
   return (jWrapStaticMessage);

cannotWriteCookie:
   jWrapPanic (NULL,"jwrap cookie are read only %s(%s)",name1, name2);
   return (jWrapStaticMessage);

} // end trace proc

/******************************************************************
 * register a new var as a var like type, build all structure and
 * register call back in tcl for handling a C/Tcl mapped variable.
 ******************************************************************/
PUBLIC JWRAP_vars* jWrapVarRegister (Tcl_Interp *interp,Tcl_Obj *jTclObj
                             , char *varName, long* varPtr, int len
                             , JWRAP_types *jwType) {
  JWRAP_vars *variable;
  Tcl_Obj    *jTclIndex;
  int        status;


  // build on structure for each var
  variable = (JWRAP_vars*)Tcl_Alloc (sizeof (JWRAP_vars));
  if (variable == NULL) goto errorMalloc;

  // create a tempry object for index in jTcl object
  jTclIndex = Tcl_NewStringObj (varName, len);

  // Check if this is an object or an ordinary C procedure
  if (jTclObj != NULL) {
    variable->array   = jTclObj;
    // set tcl object inside jTcl array
    variable->tclObj  = Tcl_ObjSetVar2 (interp, jTclObj, jTclIndex, Tcl_NewObj(), TCL_GLOBAL_ONLY);

    // register trace method WARNING: Object version no available
    status = Tcl_TraceVar2 (interp, TCL_STRING (jTclObj), varName
                , TCL_TRACE_WRITES | TCL_TRACE_READS| TCL_GLOBAL_ONLY|TCL_TRACE_UNSETS
                ,(Tcl_VarTraceProc*)traceCallback, (ClientData)variable);

  } else {
    // get tcl object as global
    variable->array   = jWrapGlobalVar;
    variable->tclObj  = Tcl_ObjSetVar2 (interp,jWrapGlobalVar,jTclIndex
                      ,Tcl_NewObj(),TCL_GLOBAL_ONLY);

    if (variable->tclObj == NULL) goto errorRegistering;

    // register trace method WARNING: Object version no available
    status = Tcl_TraceVar2 (interp, TCL_STRING (jWrapGlobalVar), varName
                , TCL_TRACE_WRITES | TCL_TRACE_READS| TCL_GLOBAL_ONLY|TCL_TRACE_UNSETS
                , (Tcl_VarTraceProc*)traceCallback, (ClientData)variable);
  }

  if (status != TCL_OK) goto cannotSetTrace;

  // finish or traced object with common thing
  variable->index       = jTclIndex;
  variable->address      = (void*)varPtr;
  variable->jwType      = jwType;
  variable->previous    = NULL; // area will be allocated later if needed
  Tcl_IncrRefCount (variable->tclObj);
  Tcl_IncrRefCount (variable->array);
  Tcl_IncrRefCount (variable->index);

  return (variable);   // Any error is fatal and break program exec

cannotSetTrace:
 jWrapPanic (NULL,"jWrapRegisterVar cannot set trace var=%s type=%s",varName,jwType->obj->name);

errorMalloc:
 jWrapPanic (NULL,"jWrapRegisterVar: can't malloc objType var=%s type=%s",varName,jwType->obj->name);

errorRegistering:
 jWrapLog (1,"WARNING jWrapRegistervar: cannot registering twice |%s|\n", varName);
 return NULL;  // Impossible only for gcc not to complain
} // end jWrapRegistervar


/** -------------------------------------------------------------------
 **  Define JWrap array name for host global variables
 ** -------------------------------------------------------------------*/
PUBLIC void jWrapVarInit (Tcl_Interp *interp) {
  jWrapGlobalVar     = Tcl_NewStringObj("JWRAP"  ,-1) ; Tcl_IncrRefCount(jWrapGlobalVar);
}
