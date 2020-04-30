
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: funcDemoTypemap_jWrap.c jTcl C wrapping DemoTypemap
 *   Date: Sat Mar  6 14:01:35 1999


 *   jWrap --cc2jTcl /home/fridu/Fulup/Vues/Fridu/Exe/linux86/etc/funcDemoTypemap.h.cpp
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
#include "funcDemoTypemap.h"

#ifndef DemoTypemap_CUSTOM_STAMP
 #ifdef FRIDU
 #define DemoTypemap_CUSTOM_STAMP &vStamp_libDemoTypemap[12]
 #else
 #define DemoTypemap_CUSTOM_STAMP NULL
 #endif
#endif

#define JWRAP_CREATE_FUNC jWrapTypeTcl2Cc
#define JWRAP_FREE_FUNC   jWrapTypeFree
#define JWRAP_CGET_FUNC   jWrapTypeCget

 // Build module static informations
 static JWRAP_modules module;
 static int initDone=0;
 static char *errTypeFmt="param:%d type [%s] not equivalent to [%s]\n";
 static JWRAP_types usedType [11];

 // Build used type enumeration
 enum enumType {
   JTYPE_Define_DemoTypemap        = 0,
   JTYPE_char_Ptr                  = 1,
   JTYPE_typeMapAdrs_Ptr           = 2,
   JTYPE_MapAdrs                   = 3,
   JTYPE_int                       = 4,
   JTYPE_Some_Options              = 5,
   JTYPE_SomeOptions               = 6,
   JTYPE_char_Ptr_Ptr              = 7,
   JTYPE_Tcl_Interp_Ptr            = 8,
   JTYPE_Tcl_Obj_Ptr               = 9,
   JTYPE_JWRAP_varg_Ptr            = 10
 }; // end of usedType enumeration

 // Build used commands help array
 static char *helpCmd[] = {
   "int = checkOpt (SomeOptions NoName);",
   "int = addOneToInt (int NoName);",
   "char* = stringToUpper (char * NoName);",
   "char** = listToUpper (char ** NoName);",
   "int = evalTclInC (Tcl_Interp * NoName, Tcl_Obj * NoName);",
   "void = printAdr (typeMapAdrs * NoName);",
   "void = checkVarg (JWRAP_varg * varg);",
 NULL
 }; // end of helpCmd array


/* *** Define Section *** */


 // build define enumeration
 typedef long Define_DemoTypemap;
 static char *Define_DemoTypemap_slotNames [] = {
   NULL
 };
 static long Define_DemoTypemap_slotValues [] = {
   0
 };
 static JWRAP_enums Define_DemoTypemap_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_Define_DemoTypemap],
  0,
  Define_DemoTypemap_slotNames,
  (long*)Define_DemoTypemap_slotValues
 };
LOCAL int Put_Define_DemoTypemap (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &Define_DemoTypemap_enum, tclObj));
}
LOCAL void Get_Define_DemoTypemap (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&Define_DemoTypemap_enum, tclObj);
}
// Build Define_DemoTypemap jointure as a Tcl type
static Tcl_ObjType Define_DemoTypemap_type = {
  "Define_DemoTypemap",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Define_DemoTypemap,
  (Tcl_SetFromAnyProc*)      Put_Define_DemoTypemap
  };


/* *** Enumeration Section *** */


  // build enumeration Some_Options 
 static char *Some_Options_slotNames [] = {
   "OPT_1",
   "OPT_2",
   "OPT_3",
   NULL
 };
 static enum Some_Options Some_Options_slotValues [] = {
   OPT_1,
   OPT_2,
   OPT_3,
   0
 };
 static JWRAP_enums Some_Options_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_Some_Options],
  3,
  Some_Options_slotNames,
  (long*)Some_Options_slotValues
 };
LOCAL int Put_Some_Options (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &Some_Options_enum, tclObj));
}
LOCAL void Get_Some_Options (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&Some_Options_enum, tclObj);
}
// Build Some_Options jointure as a Tcl type
static Tcl_ObjType Some_Options_type = {
  "Some_Options",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Some_Options,
  (Tcl_SetFromAnyProc*)      Put_Some_Options
  };

 // Hold Defines & Enum reference for jWrap struct help cmd
 static JWRAP_enums *enumerations[]={
  &Define_DemoTypemap_enum,
  &Some_Options_enum,
  NULL
 };
 
/* *** Structure Section *** */

// Alloc MapAdrs slot structure for Put/Get functions
static char *MapAdrs_slotNames[] =  {
    "firstName",
    "lastName",
    "adress",
    "zip",
    "town",
    NULL
};
static JWRAP_types *MapAdrs_slotTypes[] = {
    &usedType [JTYPE_char_Ptr], // firstName 
    &usedType [JTYPE_char_Ptr], // lastName 
    &usedType [JTYPE_char_Ptr], // adress 
    &usedType [JTYPE_int], // zip 
    &usedType [JTYPE_char_Ptr], // town 
    NULL
};
static int MapAdrs_slotArrays[] = {
    1, // firstName
    1, // lastName
    1, // adress
    1, // zip
    1, // town
    0
};
static int MapAdrs_slotOffsets[5];
static JWRAP_structs MapAdrs_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_MapAdrs],
  5,
  MapAdrs_slotNames,
  MapAdrs_slotTypes,
  MapAdrs_slotOffsets,
  MapAdrs_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_MapAdrs (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &MapAdrs_struct, srcObj, destObj));
}
LOCAL int Put_MapAdrs (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &MapAdrs_struct, srcObj, destObj));
}
LOCAL char* Get_MapAdrs (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&MapAdrs_struct, tclObj);
}
// Build MapAdrs structure as a Tcl type
static Tcl_ObjType MapAdrs_type = {
  "MapAdrs",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_MapAdrs,
  (Tcl_SetFromAnyProc*)      Put_MapAdrs
  };
// Build MapAdrs structure as a Tcl type
static Tcl_ObjType MapAdrs_ptr = {
  "MapAdrs_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_MapAdrs,
  (Tcl_SetFromAnyProc*)      Create_MapAdrs
  };

 // Hold structure & unions reference for jWrap struct help cmd
 static JWRAP_structs *structures[]={
  &MapAdrs_struct,
  NULL
 };

/* *** Functions Section *** */

 // Interface jTcl to C++ for public checkOpt C/C++ function/method
 static int jTcl_checkOpt_0 (
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
 SomeOptions param_0;

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
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_SomeOptions].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_SomeOptions].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_SomeOptions].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_SomeOptions].obj->name);
 }
  param_0 = *(SomeOptions*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  checkOpt (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(int*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_int].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[0]);
  return TCL_ERROR;
 } // end method jWrap_checkOpt0

 // Interface jTcl to C++ for public addOneToInt C/C++ function/method
 static int jTcl_addOneToInt_1 (
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
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
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
 result.shared.appli =  addOneToInt (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(int*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_int].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[1]);
  return TCL_ERROR;
 } // end method jWrap_addOneToInt1

 // Interface jTcl to C++ for public stringToUpper C/C++ function/method
 static int jTcl_stringToUpper_2 (
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
 char * param_0;

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
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_0 = *(char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  stringToUpper (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[2]);
  return TCL_ERROR;
 } // end method jWrap_stringToUpper2

 // Interface jTcl to C++ for public listToUpper C/C++ function/method
 static int jTcl_listToUpper_3 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   char**   appli;
   void *ptr;
 } shared; }result;
 char ** param_0;

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
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_char_Ptr_Ptr].obj->name);
 }
  param_0 = *(char ***)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  listToUpper (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(char***)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[3]);
  return TCL_ERROR;
 } // end method jWrap_listToUpper3

 // Interface jTcl to C++ for public evalTclInC C/C++ function/method
 static int jTcl_evalTclInC_4 (
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
 Tcl_Interp * param_0;
 Tcl_Obj * param_1;

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
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_Tcl_Interp_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_Tcl_Interp_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_Tcl_Interp_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_Tcl_Interp_Ptr].obj->name);
 }
  param_0 = *(Tcl_Interp **)&currentObj->internalRep;

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
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_Tcl_Obj_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_Tcl_Obj_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_Tcl_Obj_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_Tcl_Obj_Ptr].obj->name);
 }
  param_1 = *(Tcl_Obj **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  evalTclInC (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(int*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_int].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[4]);
  return TCL_ERROR;
 } // end method jWrap_evalTclInC4

 // Interface jTcl to C++ for public printAdr C/C++ function/method
 static int jTcl_printAdr_5 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 typeMapAdrs * param_0;

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
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_typeMapAdrs_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_typeMapAdrs_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_typeMapAdrs_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_typeMapAdrs_Ptr].obj->name);
 }
  param_0 = *(typeMapAdrs **)&currentObj->internalRep;

 // effectively call C++ function/method
 printAdr (param_0);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[5]);
  return TCL_ERROR;
 } // end method jWrap_printAdr5

 // Interface jTcl to C++ for public checkVarg C/C++ function/method
 static int jTcl_checkVarg_6 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 JWRAP_varg * param_0;

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
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_JWRAP_varg_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_JWRAP_varg_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_JWRAP_varg_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_JWRAP_varg_Ptr].obj->name);
 }
  param_0 = *(JWRAP_varg **)&currentObj->internalRep;

 // effectively call C++ function/method
 checkVarg (param_0);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[6]);
  return TCL_ERROR;
 } // end method jWrap_checkVarg6


/* ***  Tcl Register Section *** */
#ifdef __cplusplus
extern "C" {
#endif
RESTRICTED int Demotypemap_Init (Tcl_Interp *interp) {
 // Dont init twice
 if (initDone) return TCL_OK;
 initDone = 1;

 /* --- Build module handle & register it in jWrap --- */

 module.magic       =JWRAP_MODULE;
 module.name        ="DemoTypemap";
 module.help        ="jTcl C wrapping DemoTypemap";
 module.helpCmd     = helpCmd;
 module.nbCmd       = 7;
 module.hashTable   = NULL;
 module.version     = DemoTypemap_CUSTOM_STAMP;
 module.structures  = structures;
 module.enumerations= enumerations;
 module.info        = NULL;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // init routines user or default
#ifdef DemoTypemap_CUSTOM_INIT
 DemoTypemap_CUSTOM_INIT;
#else
 if (Jwrap_Init (interp) != TCL_OK) return TCL_ERROR;
#endif
 jWrapModuleRegister (interp,&module);
 jWrapEnumRegister (&module,&Define_DemoTypemap_enum,&Define_DemoTypemap_type);

 /* --- Enumeration Section --- */

 jWrapEnumRegister (&module, &Some_Options_enum,&Some_Options_type);
 
 /* *** Type Structs/Unions Section *** */
 {  // Compute MapAdrs structure offset
  struct MapAdrs dummy4offset;
  MapAdrs_slotOffsets [0] = (char*)&dummy4offset.firstName - (char*)&dummy4offset;
  MapAdrs_slotOffsets [1] = (char*)&dummy4offset.lastName - (char*)&dummy4offset;
  MapAdrs_slotOffsets [2] = (char*)&dummy4offset.adress - (char*)&dummy4offset;
  MapAdrs_slotOffsets [3] = (char*)&dummy4offset.zip - (char*)&dummy4offset;
  MapAdrs_slotOffsets [4] = (char*)&dummy4offset.town - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&MapAdrs_struct,&MapAdrs_type,&MapAdrs_ptr );
 };
 
 /* *** Type Alias Section *** */
 jWrapTypeAlias (&module,"Some_Options" ,"SomeOptions");
 jWrapTypeAlias (&module,"MapAdrs" ,"typeMapAdrs");

 /* --- Used Type Section --- */

 jWrapTypeCheck (&usedType [0],"Define_DemoTypemap",sizeof(Define_DemoTypemap));
 jWrapTypeCheck (&usedType [1],"char_Ptr",sizeof(char *));
 jWrapTypeCheck (&usedType [2],"typeMapAdrs_Ptr",sizeof(typeMapAdrs *));
 jWrapTypeCheck (&usedType [3],"MapAdrs",sizeof(struct MapAdrs));
 jWrapTypeCheck (&usedType [4],"int",sizeof(int));
 jWrapTypeCheck (&usedType [5],"Some_Options",sizeof(enum Some_Options));
 jWrapTypeCheck (&usedType [6],"SomeOptions",sizeof(SomeOptions));
 jWrapTypeCheck (&usedType [7],"char_Ptr_Ptr",sizeof(char**));
 jWrapTypeCheck (&usedType [8],"Tcl_Interp_Ptr",sizeof(Tcl_Interp *));
 jWrapTypeCheck (&usedType [9],"Tcl_Obj_Ptr",sizeof(Tcl_Obj *));
 jWrapTypeCheck (&usedType [10],"JWRAP_varg_Ptr",sizeof(JWRAP_varg *));

 /* --- Static Variable registration --- */

 jWrapVarRegister (interp, NULL, "TypeMap_help", (long*)&TypeMap_help, 12 
                  , &usedType[JTYPE_char_Ptr]);
 jWrapVarRegister (interp, NULL, "lastAdr", (long*)&lastAdr, 7 
                  , &usedType[JTYPE_typeMapAdrs_Ptr]);

 /* --- Functions sub-section --- */

 // register checkOpt C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoTypemap.checkOpt", jTcl_checkOpt_0  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register addOneToInt C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoTypemap.addOneToInt", jTcl_addOneToInt_1  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register stringToUpper C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoTypemap.stringToUpper", jTcl_stringToUpper_2  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register listToUpper C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoTypemap.listToUpper", jTcl_listToUpper_3  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register evalTclInC C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoTypemap.evalTclInC", jTcl_evalTclInC_4  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register printAdr C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoTypemap.printAdr", jTcl_printAdr_5  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register checkVarg C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoTypemap.checkVarg", jTcl_checkVarg_6  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 return TCL_OK;
} // end function DemoTypemap_Init
#ifdef __cplusplus
}
#endif

// ------------------ end funcDemoTypemap_jWrap.c ----------------------
