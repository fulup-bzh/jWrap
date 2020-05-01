
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: out.c Swig basic example.c adapted to jWrap
 *   Date: Fri May  1 19:15:11 2020


 *   jWrap --cc2jTcl testWrap.c
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
#include "testWrap.c"

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
 static JWRAP_types usedType [1];

 // Build used type enumeration
 enum enumType {
   JTYPE_const_char_Ptr            = 0
 }; // end of usedType enumeration

 // Build used commands help array
 static char *helpCmd[] = {
   "const char* = get_time ();",
 NULL
 }; // end of helpCmd array

/* *** Functions Section *** */

 // Interface jTcl to C++ for public get_time C/C++ function/method
 static int jTcl_get_time_0 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj *resultPtr;
 struct { union {
   const_char*   appli;
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
 // Reset TclObj and memcpy value without any check as internal value
 resultPtr->internalRep.twoPtrValue.ptr1 = 0;
 resultPtr->internalRep.twoPtrValue.ptr2 = 0;
 *(const_char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_const_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[0]);
  return TCL_ERROR;
 } // end method jWrap_get_time0


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
 module.nbCmd       = 1;
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

 jWrapTypeCheck (&usedType [0],"const_char_Ptr",sizeof(const_char*));

 /* --- Functions sub-section --- */

 // register get_time C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoSimple.get_time", jTcl_get_time_0  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 return TCL_OK;
} // end function DemoSimple_Init
#ifdef __cplusplus
}
#endif

// ------------------ end out.c ----------------------
