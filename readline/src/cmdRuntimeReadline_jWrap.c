
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: cmdRuntimeReadline_jWrap.c GNU Readline interface to tclsh
 *   Date: Mon Mar 22 10:32:37 1999


 *   jWrap --cc2jTcl /home/fridu/Fulup/Vues/Fridu/Exe/linux86/etc/headerReadline.h.cpp
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
#include "headerReadline.h"

#ifndef Readline_CUSTOM_STAMP
 #ifdef FRIDU
 #define Readline_CUSTOM_STAMP &vStamp_libReadline[12]
 #else
 #define Readline_CUSTOM_STAMP NULL
 #endif
#endif

#define JWRAP_CREATE_FUNC jWrapTypeTcl2Cc
#define JWRAP_FREE_FUNC   jWrapTypeFree
#define JWRAP_CGET_FUNC   jWrapTypeCget

 // Build module static informations
 static JWRAP_modules module;
 static int initDone=0;
 static char *errTypeFmt="param:%d type [%s] not equivalent to [%s]\n";
 static JWRAP_types usedType [2];

 // Build used type enumeration
 enum enumType {
   JTYPE_Define_Readline           = 0,
   JTYPE_char_Ptr                  = 1
 }; // end of usedType enumeration

 // Build used commands help array
 static char *helpCmd[] = {
   "void = ReadlineHistory ();",
   "void = ReadlineStart ();",
 NULL
 }; // end of helpCmd array


/* *** Define Section *** */


 // build define enumeration
 typedef long Define_Readline;
 static char *Define_Readline_slotNames [] = {
   NULL
 };
 static long Define_Readline_slotValues [] = {
   0
 };
 static JWRAP_enums Define_Readline_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_Define_Readline],
  0,
  Define_Readline_slotNames,
  (long*)Define_Readline_slotValues
 };
LOCAL int Put_Define_Readline (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &Define_Readline_enum, tclObj));
}
LOCAL void Get_Define_Readline (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&Define_Readline_enum, tclObj);
}
// Build Define_Readline jointure as a Tcl type
static Tcl_ObjType Define_Readline_type = {
  "Define_Readline",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Define_Readline,
  (Tcl_SetFromAnyProc*)      Put_Define_Readline
  };

 // Hold Defines & Enum reference for jWrap struct help cmd
 static JWRAP_enums *enumerations[]={
  &Define_Readline_enum,
  NULL
 };

/* *** Functions Section *** */

 // Interface jTcl to C++ for public ReadlineHistory C/C++ function/method
 static int jTcl_ReadlineHistory_0 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {

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
 ReadlineHistory ();

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[0]);
  return TCL_ERROR;
 } // end method jWrap_ReadlineHistory0

 // Interface jTcl to C++ for public ReadlineStart C/C++ function/method
 static int jTcl_ReadlineStart_1 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {

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
 ReadlineStart ();

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[1]);
  return TCL_ERROR;
 } // end method jWrap_ReadlineStart1


/* ***  Tcl Register Section *** */
#ifdef __cplusplus
extern "C" {
#endif
RESTRICTED int Readline_Init (Tcl_Interp *interp) {
 // Dont init twice
 if (initDone) return TCL_OK;
 initDone = 1;

 /* --- Build module handle & register it in jWrap --- */

 module.magic       =JWRAP_MODULE;
 module.name        ="Readline";
 module.help        ="GNU Readline interface to tclsh";
 module.helpCmd     = helpCmd;
 module.nbCmd       = 2;
 module.hashTable   = NULL;
 module.version     = Readline_CUSTOM_STAMP;
 module.structures  = NULL;
 module.enumerations= enumerations;
 module.info        = NULL;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // init routines user or default
#ifdef Readline_CUSTOM_INIT
 Readline_CUSTOM_INIT;
#else
 if (Jwrap_Init (interp) != TCL_OK) return TCL_ERROR;
#endif
 jWrapModuleRegister (interp,&module);
 jWrapEnumRegister (&module,&Define_Readline_enum,&Define_Readline_type);

 /* --- Used Type Section --- */

 jWrapTypeCheck (&usedType [0],"Define_Readline",sizeof(Define_Readline));
 jWrapTypeCheck (&usedType [1],"char_Ptr",sizeof(char *));

 /* --- Static Variable registration --- */

 jWrapVarRegister (interp, NULL, "ReadlinePrompt1", (long*)&ReadlinePrompt1, 15 
                  , &usedType[JTYPE_char_Ptr]);
 jWrapVarRegister (interp, NULL, "ReadlinePrompt2", (long*)&ReadlinePrompt2, 15 
                  , &usedType[JTYPE_char_Ptr]);
 jWrapVarRegister (interp, NULL, "ReadlineName", (long*)&ReadlineName, 12 
                  , &usedType[JTYPE_char_Ptr]);

 /* --- Functions sub-section --- */

 // register ReadlineHistory C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Readline.History", jTcl_ReadlineHistory_0  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register ReadlineStart C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Readline.Start", jTcl_ReadlineStart_1  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 return TCL_OK;
} // end function Readline_Init
#ifdef __cplusplus
}
#endif

// ------------------ end cmdRuntimeReadline_jWrap.c ----------------------
