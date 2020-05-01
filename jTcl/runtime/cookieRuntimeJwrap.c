/*
 *  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   cookirCcWrap.c generic interface to pointers
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/runtime/cookieRuntimeJwrap.c,v $
 *
 * Modification History
 * --------------------
 * 01c,07jul98,Fulup,ispell and document
 * 01b,13may98,Fulup,simplify
 * 01a,18feb98,Fulup,written
 */


#include "libRuntimeJwrap.h"
#include <string.h>
#include <stdlib.h>

LOCAL int  cookieStringToInternal  (Tcl_Interp *interp, Tcl_Obj *objPtr);
LOCAL void cookieInternalToString  (Tcl_Obj *objPtr);
LOCAL void cookieDupInternal (Tcl_Obj *srcPtr, Tcl_Obj *copyPtr) ;


LOCAL Tcl_ObjType genericCookie = {
  "Generic_Cookie",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) cookieDupInternal,
  (Tcl_UpdateStringProc*)    cookieInternalToString,
  (Tcl_SetFromAnyProc*)      cookieStringToInternal
  };

/******************************************************************
 * Create an internal representation from external representation
 * a cookie external rep is prefixed with _KRP_ and followed by
 * hexadecimal value of cookified value.
 ******************************************************************/
LOCAL int cookieStringToInternal  (Tcl_Interp *interp, Tcl_Obj *objPtr)
{
  void     *cookie;
  int      status;

  // All jWrap Cookies are compatible we never accept any casting with no check
  if ((objPtr->typePtr != NULL)
      && (objPtr->typePtr->setFromAnyProc == cookieStringToInternal)) {
      return TCL_OK;
  } else {

    // check user does not want a null pointer
    if ((TCL_STRING(objPtr) != NULL) && (!strcmp (TCL_STRING(objPtr), jWrapStringNull))) {
      objPtr->internalRep.twoPtrValue.ptr1 = NULL;
      objPtr->internalRep.twoPtrValue.ptr2 = NULL;
      objPtr->typePtr = &genericCookie;
      return TCL_OK;
    }
  }

  // Hug cannot translate a null string
  if (TCL_STRING(objPtr) == NULL) goto errNullCookie;

  // retrieve cookie from object
  status = sscanf (TCL_STRING(objPtr), "_KRP_0x%x", (int*) &cookie);
  if (status != 1) goto  errNotAValidCookie;

  // update internal representation and update tcl object internal representation
  objPtr->internalRep.otherValuePtr = cookie;
  objPtr->typePtr = &genericCookie;

  return TCL_OK;

 errNotAValidCookie:
      Tcl_AppendResult (interp,"Not a valid jWrap Cookie [",NULL);
      if (objPtr->typePtr == NULL) {
        Tcl_AppendResult (interp,"TclString",NULL);
      } else {
        Tcl_AppendResult (interp,objPtr->typePtr->name,NULL);
      }
      Tcl_AppendResult (interp,"] = [",TCL_STRING (objPtr),"]\n",NULL);
      return TCL_ERROR;

 errNullCookie:
      Tcl_AppendResult (interp,"Cannot translate a [",objPtr->typePtr->name
                       ,"] cookie with NULL external representation\n",NULL);
      return TCL_ERROR;
}
/******************************************************************
 * Create an external representation from internal representation
 * Any internal representation can be map on a cookie, we just build
 * a string _KRP_prefixed and followed by hexadecimal value of
 * data.
 ******************************************************************/
LOCAL void cookieInternalToString  (Tcl_Obj *objPtr)
{
  void   *cookie;
  unsigned int  len;
  char key [TCL_DOUBLE_SPACE+5];

  // retrieve our cookie from internal rep
  cookie =  objPtr->internalRep.otherValuePtr;

  // build cookie string with address prefixed with _KRP_
  len = 1+ snprintf (key,sizeof(key), "_KRP_0x%x", (int)cookie);
  objPtr->bytes = Tcl_Alloc (len);
  memcpy (objPtr->bytes, key, len);
  objPtr->length= len-1; // Warning Tcl external rep should point on '\0'

} // end cookie InternalToString

/*************************************************************************
 * Duplicate a cookie, only duplicated internal longValue of object.
 *************************************************************************/
LOCAL void cookieDupInternal (Tcl_Obj *srcPtr, Tcl_Obj *copyPtr)
{
  // Get cookie from Tcl Object
  copyPtr->internalRep.otherValuePtr = srcPtr->internalRep.otherValuePtr;
}

/******************************************************************
 * register a new name as a cookie type. Any unknown type or aliased
 * type is map on a cookie, this mechanism allows jWrap/tcl to handle
 * any type of C structure even when internal structure is unknown.
 ******************************************************************/
PUBLIC void jWrapCookieRegisterType (JWRAP_types *jwType,char* typeName)
{

  jwType->obj = (Tcl_ObjType*) Tcl_Alloc (sizeof (Tcl_ObjType));
  if (jwType->obj == NULL) goto errorMalloc;

  // fill up cookie structure type
  jwType->magic                  = JWRAP_COOKIE;
  jwType->obj->name              = typeName;
  jwType->obj->freeIntRepProc    = (Tcl_FreeInternalRepProc*)NULL;
  jwType->obj->dupIntRepProc     = cookieDupInternal;
  jwType->obj->updateStringProc  = cookieInternalToString;
  jwType->obj->setFromAnyProc    = cookieStringToInternal;

  Tcl_RegisterObjType (jwType->obj);
  return;

errorMalloc:
  jWrapPanic (NULL,"jWrapRegister can't malloc Tcl_TypeObj=%s ",typeName);
} // end jWrapRegisterType
