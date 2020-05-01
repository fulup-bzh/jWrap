
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: cmdRuntimeJwrap_jWrap.c jWrap Core module
 *   Date: Fri May  1 15:43:58 2020


 *   jWrap --cc2jTcl cmdRuntimeJwrap.c
 *
 *   WARNING: Except if you really know what you are doing
 *   you should not edit this file by hand.
 *
 *   In order finding jWrap check: http://www.fridu.bzh
 + ------------------------------------------------------------ */

#ifndef EASYC_PROTO_ONLY
#define EASYC_PROTO_ONLY
#endif
#define JWRAP_CC2JTCL

#include "libRuntimeJwrap.h"
#include "cmdRuntimeJwrap.c"

#ifndef jWrap_CUSTOM_STAMP
 #ifdef FRIDU
 #define jWrap_CUSTOM_STAMP &vStamp_libjWrap[12]
 #else
 #define jWrap_CUSTOM_STAMP NULL
 #endif
#endif

#define JWRAP_CREATE_FUNC jWrapTypeTcl2Cc
#define JWRAP_FREE_FUNC   jWrapTypeFree
#define JWRAP_CGET_FUNC   jWrapTypeCget

 // Build module static informations
 static JWRAP_modules module;
 static int initDone=0;
 static char *errTypeFmt="param:%d type [%s] not equivalent to [%s]\n";
 static JWRAP_types usedType [9];

 // Build used type enumeration
 enum enumType {
   JTYPE_Define_jWrap              = 0,
   JTYPE_int                       = 1,
   JTYPE_jwrap_basic               = 2,
   JTYPE_long                      = 3,
   JTYPE_char                      = 4,
   JTYPE_void_Ptr                  = 5,
   JTYPE_char_Ptr                  = 6,
   JTYPE_double                    = 7,
   JTYPE_size_t                    = 8
 }; // end of usedType enumeration

 // Build used commands help array
 static char *helpCmd[] = {
   "void = Tcl_Free (void * NoName);",
   "void* = Tcl_Alloc (int NoName);",
   "void* = memcpy (void * dest, void * src, int size);",
   "char* = strdup (const char * string);",
   "void* = jWrapMalloc (size_t size);",
   "void* = jWrapCalloc (size_t nmemb, size_t size);",
   "void = jWrapFree (void * ptr);",
   "char* = jWrapDup (const char * source);",
   "int = jWrapPutEnv (const char * string);",
   "char* = jWrapGetEnv (const char * string);",
 NULL
 }; // end of helpCmd array


/* *** Define Section *** */


 // build define enumeration
 typedef long Define_jWrap;
 static char *Define_jWrap_slotNames [] = {
   NULL
 };
 static long Define_jWrap_slotValues [] = {
   0
 };
 static JWRAP_enums Define_jWrap_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_Define_jWrap],
  0,
  Define_jWrap_slotNames,
  (long*)Define_jWrap_slotValues
 };
LOCAL int Put_Define_jWrap (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &Define_jWrap_enum, tclObj));
}
LOCAL void Get_Define_jWrap (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&Define_jWrap_enum, tclObj);
}
// Build Define_jWrap jointure as a Tcl type
static Tcl_ObjType Define_jWrap_type = {
  "Define_jWrap",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Define_jWrap,
  (Tcl_SetFromAnyProc*)      Put_Define_jWrap
  };

 // Hold Defines & Enum reference for jWrap struct help cmd
 static JWRAP_enums *enumerations[]={
  &Define_jWrap_enum,
  NULL
 };
 
/* *** Unions Section *** */


// Alloc jwrap_basic slot jointure for Put/Get functions
static char *jwrap_basic_slotNames[] =  {
    "number",
    "character",
    "pointer",
    "string",
    "floating",
    NULL
};
static JWRAP_types *jwrap_basic_slotTypes[] = {
    &usedType [JTYPE_long], // number
    &usedType [JTYPE_char], // character
    &usedType [JTYPE_void_Ptr], // pointer
    &usedType [JTYPE_char_Ptr], // string
    &usedType [JTYPE_double], // floating
    NULL
};
static int jwrap_basic_slotOffsets[5];
static int jwrap_basic_slotArrays[] = {
    1, // number
    1, // character
    1, // pointer
    1, // string
    1, // floating
    0
};
static JWRAP_structs jwrap_basic_union = {
  JWRAP_UNION,
  &usedType [JTYPE_jwrap_basic],
  5,
  jwrap_basic_slotNames,
  jwrap_basic_slotTypes,
  jwrap_basic_slotOffsets,
  jwrap_basic_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_jwrap_basic (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &jwrap_basic_union, srcObj, destObj));
}
LOCAL int Put_jwrap_basic (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj *destObj) {
  return (jWrapTypeUpdate (interp, &jwrap_basic_union, srcObj, destObj));
}
LOCAL char* Get_jwrap_basic (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&jwrap_basic_union, tclObj);
}
// Build jwrap_basic jointure as a Tcl type
static Tcl_ObjType jwrap_basic_type = {
  "jwrap_basic",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_jwrap_basic,
  (Tcl_SetFromAnyProc*)      Put_jwrap_basic
  };
// Build jwrap_basic jointure as a Tcl type
static Tcl_ObjType jwrap_basic_ptr = {
  "jwrap_basic_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_jwrap_basic,
  (Tcl_SetFromAnyProc*)      Create_jwrap_basic
  };

 // Hold structure & unions reference for jWrap struct help cmd
 static JWRAP_structs *structures[]={
  &jwrap_basic_union,
  NULL
 };

/* *** Functions Section *** */

 // Interface jTcl to C++ for public Tcl_Free C/C++ function/method
 static int jTcl_Tcl_Free_0 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 void * param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_void_Ptr].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_0 = *(void **)&currentObj->internalRep;

 // effectively call C++ function/method
 Tcl_Free (param_0);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[0]);
  return TCL_ERROR;
 } // end method jWrap_Tcl_Free0

 // Interface jTcl to C++ for public Tcl_Alloc C/C++ function/method
 static int jTcl_Tcl_Alloc_1 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   void*   appli;
   void *ptr;
 } shared; }result;
 int param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_int].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  param_0 = *(int*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  Tcl_Alloc (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // Reset TclObj and memcpy value without any check as internal value
 resultPtr->internalRep.twoPtrValue.ptr1 = 0;
 resultPtr->internalRep.twoPtrValue.ptr2 = 0;
 *(void**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_void_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[1]);
  return TCL_ERROR;
 } // end method jWrap_Tcl_Alloc1

 // Interface jTcl to C++ for public memcpy C/C++ function/method
 static int jTcl_memcpy_2 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   void*   appli;
   void *ptr;
 } shared; }result;
 void * param_0;
 void * param_1;
 int param_2;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 4) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_void_Ptr].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_0 = *(void **)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_void_Ptr].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_1 = *(void **)&currentObj->internalRep;

 // Check for user application object
 if (objv[3]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[3]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[3]->bytes;
   tmpCgetObj.length  = objv[3]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[3];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_int].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  param_2 = *(int*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  memcpy (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // Reset TclObj and memcpy value without any check as internal value
 resultPtr->internalRep.twoPtrValue.ptr1 = 0;
 resultPtr->internalRep.twoPtrValue.ptr2 = 0;
 *(void**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_void_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[2]);
  return TCL_ERROR;
 } // end method jWrap_memcpy2

 // Interface jTcl to C++ for public strdup C/C++ function/method
 static int jTcl_strdup_3 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   char*   appli;
   void *ptr;
 } shared; }result;
 const char * param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_char_Ptr].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_0 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  strdup (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // Reset TclObj and memcpy value without any check as internal value
 resultPtr->internalRep.twoPtrValue.ptr1 = 0;
 resultPtr->internalRep.twoPtrValue.ptr2 = 0;
 *(char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[3]);
  return TCL_ERROR;
 } // end method jWrap_strdup3

 // Interface jTcl to C++ for public jWrapMalloc C/C++ function/method
 static int jTcl_jWrapMalloc_4 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   void*   appli;
   void *ptr;
 } shared; }result;
 size_t param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_size_t].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_size_t].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_size_t].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_size_t].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_size_t].obj->name);
 }
  param_0 = *(size_t*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  jWrapMalloc (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // Reset TclObj and memcpy value without any check as internal value
 resultPtr->internalRep.twoPtrValue.ptr1 = 0;
 resultPtr->internalRep.twoPtrValue.ptr2 = 0;
 *(void**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_void_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[4]);
  return TCL_ERROR;
 } // end method jWrap_jWrapMalloc4

 // Interface jTcl to C++ for public jWrapCalloc C/C++ function/method
 static int jTcl_jWrapCalloc_5 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   void*   appli;
   void *ptr;
 } shared; }result;
 size_t param_0;
 size_t param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 3) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_size_t].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_size_t].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_size_t].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_size_t].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_size_t].obj->name);
 }
  param_0 = *(size_t*)&currentObj->internalRep;

 // Check for user application object
 if (objv[2]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[2]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[2]->bytes;
   tmpCgetObj.length  = objv[2]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[2];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_size_t].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_size_t].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_size_t].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_size_t].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_size_t].obj->name);
 }
  param_1 = *(size_t*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  jWrapCalloc (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // Reset TclObj and memcpy value without any check as internal value
 resultPtr->internalRep.twoPtrValue.ptr1 = 0;
 resultPtr->internalRep.twoPtrValue.ptr2 = 0;
 *(void**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_void_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[5]);
  return TCL_ERROR;
 } // end method jWrap_jWrapCalloc5

 // Interface jTcl to C++ for public jWrapFree C/C++ function/method
 static int jTcl_jWrapFree_6 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 void * param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_void_Ptr].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  param_0 = *(void **)&currentObj->internalRep;

 // effectively call C++ function/method
 jWrapFree (param_0);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[6]);
  return TCL_ERROR;
 } // end method jWrap_jWrapFree6

 // Interface jTcl to C++ for public jWrapDup C/C++ function/method
 static int jTcl_jWrapDup_7 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   char*   appli;
   void *ptr;
 } shared; }result;
 const char * param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_char_Ptr].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_0 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  jWrapDup (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // Reset TclObj and memcpy value without any check as internal value
 resultPtr->internalRep.twoPtrValue.ptr1 = 0;
 resultPtr->internalRep.twoPtrValue.ptr2 = 0;
 *(char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[7]);
  return TCL_ERROR;
 } // end method jWrap_jWrapDup7

 // Interface jTcl to C++ for public jWrapPutEnv C/C++ function/method
 static int jTcl_jWrapPutEnv_8 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   int   appli;
   void *ptr;
 } shared; }result;
 const char * param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_char_Ptr].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_0 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  jWrapPutEnv (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // Reset TclObj and memcpy value without any check as internal value
 resultPtr->internalRep.twoPtrValue.ptr1 = 0;
 resultPtr->internalRep.twoPtrValue.ptr2 = 0;
 *(int*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_int].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[8]);
  return TCL_ERROR;
 } // end method jWrap_jWrapPutEnv8

 // Interface jTcl to C++ for public jWrapGetEnv C/C++ function/method
 static int jTcl_jWrapGetEnv_9 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   char*   appli;
   void *ptr;
 } shared; }result;
 const char * param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 2) goto  errorNumArg;

 // Check for user application object
 if (objv[1]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[1]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[1]->bytes;
   tmpCgetObj.length  = objv[1]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[1];
 }
 // convert to our wanted application type
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_char_Ptr].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_0 = *(const char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  jWrapGetEnv (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // Reset TclObj and memcpy value without any check as internal value
 resultPtr->internalRep.twoPtrValue.ptr1 = 0;
 resultPtr->internalRep.twoPtrValue.ptr2 = 0;
 *(char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[9]);
  return TCL_ERROR;
 } // end method jWrap_jWrapGetEnv9


/* ***  Tcl Register Section *** */
#ifdef __cplusplus
extern "C" {
#endif
RESTRICTED int Jwrap_Init (Tcl_Interp *interp) {
 // Dont init twice
 if (initDone) return TCL_OK;
 initDone = 1;

 /* --- Build module handle & register it in jWrap --- */

 module.magic       =JWRAP_MODULE;
 module.name        ="jWrap";
 module.help        ="jWrap Core module";
 module.helpCmd     = helpCmd;
 module.nbCmd       = 10;
 module.hashTable   = NULL;
 module.version     = jWrap_CUSTOM_STAMP;
 module.structures  = structures;
 module.enumerations= enumerations;
 module.info        = NULL;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // init routines user or default
#ifdef jWrap_CUSTOM_INIT
 jWrap_CUSTOM_INIT;
#else
 if (Jwrap_Init (interp) != TCL_OK) return TCL_ERROR;
#endif
 jWrapModuleRegister (interp,&module);
 jWrapEnumRegister (&module,&Define_jWrap_enum,&Define_jWrap_type);

 {  // Compute jwrap_basic Unions offset
  union jwrap_basic dummy4offset;
  jwrap_basic_slotOffsets [0] = (char*)&dummy4offset.number - (char*)&dummy4offset;
  jwrap_basic_slotOffsets [1] = (char*)&dummy4offset.character - (char*)&dummy4offset;
  jwrap_basic_slotOffsets [2] = (char*)&dummy4offset.pointer - (char*)&dummy4offset;
  jwrap_basic_slotOffsets [3] = (char*)&dummy4offset.string - (char*)&dummy4offset;
  jwrap_basic_slotOffsets [4] = (char*)&dummy4offset.floating - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&jwrap_basic_union,&jwrap_basic_type,&jwrap_basic_ptr );
 };
 
 /* *** Type Alias Section *** */
 jWrapTypeAlias (&module,"jwrap_basic" ,"JWRAP_basic");

 /* --- Used Type Section --- */

 jWrapTypeCheck (&usedType [0],"Define_jWrap",sizeof(Define_jWrap));
 jWrapTypeCheck (&usedType [1],"int",sizeof(int));
 jWrapTypeCheck (&usedType [2],"jwrap_basic",sizeof(union jwrap_basic));
 jWrapTypeCheck (&usedType [3],"long",sizeof(long));
 jWrapTypeCheck (&usedType [4],"char",sizeof(char));
 jWrapTypeCheck (&usedType [5],"void_Ptr",sizeof(void*));
 jWrapTypeCheck (&usedType [6],"char_Ptr",sizeof(char*));
 jWrapTypeCheck (&usedType [7],"double",sizeof(double));
 jWrapTypeCheck (&usedType [8],"size_t",sizeof(size_t));

 /* --- Static Variable registration --- */

 jWrapVarRegister (interp, NULL, "jWrapDbgValue", (long*)&jWrapDbgValue, 13 
                  , &usedType[JTYPE_int]);

 /* --- Functions sub-section --- */

 // register Tcl_Free C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"jWrap.Tcl_Free", jTcl_Tcl_Free_0  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register Tcl_Alloc C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"jWrap.Tcl_Alloc", jTcl_Tcl_Alloc_1  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register memcpy C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"jWrap.memcpy", jTcl_memcpy_2  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register strdup C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"jWrap.strdup", jTcl_strdup_3  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register jWrapMalloc C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"jWrap.Malloc", jTcl_jWrapMalloc_4  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register jWrapCalloc C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"jWrap.Calloc", jTcl_jWrapCalloc_5  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register jWrapFree C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"jWrap.Free", jTcl_jWrapFree_6  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register jWrapDup C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"jWrap.Dup", jTcl_jWrapDup_7  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register jWrapPutEnv C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"jWrap.PutEnv", jTcl_jWrapPutEnv_8  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register jWrapGetEnv C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"jWrap.GetEnv", jTcl_jWrapGetEnv_9  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 return TCL_OK;
} // end function jWrap_Init
#ifdef __cplusplus
}
#endif

// ------------------ end cmdRuntimeJwrap_jWrap.c ----------------------
