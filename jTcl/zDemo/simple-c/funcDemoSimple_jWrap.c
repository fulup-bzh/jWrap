
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: funcDemoSimple_jWrap.c Swig basic example.c adapted to jWrap
 *   Date: Wed Feb 17 14:19:10 1999


 *   jWrap --cc2jTcl /home/fridu/Fulup/Vues/Fridu/Exe/linux86/etc/funcDemoSimple.c.cpp
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
#include "funcDemoSimple.c"

#ifndef DemoSimple_CUSTOM_STAMP
 #ifdef FRIDU
 #define DemoSimple_CUSTOM_STAMP &vStamp_libDemoSimple[12]
 #else
 #define DemoSimple_CUSTOM_STAMP NULL
 #endif
#endif

#define JWRAP_CREATE_FUNC jWrapTypeTcl2Cc
#define JWRAP_FREE_FUNC   jWrapTypeFree
#define JWRAP_CGET_FUNC   jWrapTypeCget

 // Build module static informations
 static JWRAP_modules module;
 static int initDone=0;
 static char *errTypeFmt="param:%d type [%s] not equivalent to [%s]\n";
 static JWRAP_types usedType [4];

 // Build used type enumeration
 enum enumType {
   JTYPE_double                    = 0,
   JTYPE_int                       = 1,
   JTYPE_long                      = 2,
   JTYPE_char_Ptr                  = 3
 }; // end of usedType enumeration

 // Build used commands help array
 static char *helpCmd[] = {
   "int = fact (int n);",
   "int = mod (int n, int m);",
   "char* = get_time ();",
 NULL
 }; // end of helpCmd array

/* *** Functions Section *** */

 // Interface jTcl to C++ for public fact C/C++ function/method
 static int jTcl_fact_0 (
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
 result.shared.appli =  fact (param_0);

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
 } // end method jWrap_fact0

 // Interface jTcl to C++ for public mod C/C++ function/method
 static int jTcl_mod_1 (
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
 int param_1;

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
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  param_0 = *(int*)&currentObj->internalRep;

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
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  param_1 = *(int*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  mod (param_0, param_1);

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
 } // end method jWrap_mod1

 // Interface jTcl to C++ for public get_time C/C++ function/method
 static int jTcl_get_time_2 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj *resultPtr;
 struct { union {
   char*   appli;
   void *ptr;
 } shared; }result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // Check param number
 if (objc != 1) goto  errorNumArg;

 // effectively call C++ function/method
 result.shared.appli =  get_time ();

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
 } // end method jWrap_get_time2


/* ***  Tcl Register Section *** */
#ifdef __cplusplus
extern "C" {
#endif
RESTRICTED int Demosimple_Init (Tcl_Interp *interp) {
 // Dont init twice
 if (initDone) return TCL_OK;
 initDone = 1;

 /* --- Build module handle & register it in jWrap --- */

 module.magic       =JWRAP_MODULE;
 module.name        ="DemoSimple";
 module.help        ="Swig basic example.c adapted to jWrap";
 module.helpCmd     = helpCmd;
 module.nbCmd       = 3;
 module.hashTable   = NULL;
 module.version     = DemoSimple_CUSTOM_STAMP;
 module.structures  = NULL;
 module.enumerations= NULL;
 module.info        = NULL;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // init routines user or default
#ifdef DemoSimple_CUSTOM_INIT
 DemoSimple_CUSTOM_INIT;
#else
 if (Jwrap_Init (interp) != TCL_OK) return TCL_ERROR;
#endif
 jWrapModuleRegister (interp,&module);

 /* --- Used Type Section --- */

 jWrapTypeCheck (&usedType [0],"double",sizeof(double));
 jWrapTypeCheck (&usedType [1],"int",sizeof(int));
 jWrapTypeCheck (&usedType [2],"long",sizeof(long));
 jWrapTypeCheck (&usedType [3],"char_Ptr",sizeof(char *));

 /* --- Static Variable registration --- */

 jWrapVarRegister (interp, NULL, "MyDouble", (long*)&MyDouble, 8 
                  , &usedType[JTYPE_double]);
 jWrapVarRegister (interp, NULL, "MyInt", (long*)&MyInt, 5 
                  , &usedType[JTYPE_int]);
 jWrapVarRegister (interp, NULL, "MyLong", (long*)&MyLong, 6 
                  , &usedType[JTYPE_long]);
 jWrapVarRegister (interp, NULL, "MyString", (long*)&MyString, 8 
                  , &usedType[JTYPE_char_Ptr]);

 /* --- Functions sub-section --- */

 // register fact C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoSimple.fact", jTcl_fact_0  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register mod C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoSimple.mod", jTcl_mod_1  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register get_time C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoSimple.get_time", jTcl_get_time_2  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 return TCL_OK;
} // end function DemoSimple_Init
#ifdef __cplusplus
}
#endif

// ------------------ end funcDemoSimple_jWrap.c ----------------------
