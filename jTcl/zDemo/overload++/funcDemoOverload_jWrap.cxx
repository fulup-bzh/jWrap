
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: funcDemoOverload_jWrap.cxx Demonstrate how overloading a C++ function from jTcl
 *   Date: Wed Feb 17 14:05:28 1999


 *   jWrap --cc2jTcl /home/fridu/Fulup/Vues/Fridu/Exe/linux86/etc/funcDemoOverload.h.cpp
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
#include "funcDemoOverload.h"

#ifndef DemoOverload_CUSTOM_STAMP
 #ifdef FRIDU
 #define DemoOverload_CUSTOM_STAMP &vStamp_libDemoOverload[12]
 #else
 #define DemoOverload_CUSTOM_STAMP NULL
 #endif
#endif

#define JWRAP_CREATE_FUNC jWrapTypeTcl2Cc
#define JWRAP_FREE_FUNC   jWrapTypeFree
#define JWRAP_CGET_FUNC   jWrapTypeCget

 // Build module static informations
 static JWRAP_modules module;
 static int initDone=0;
 static char *errTypeFmt="param:%d type [%s] not equivalent to [%s]\n";
 static JWRAP_types usedType [3];

 // Build used type enumeration
 enum enumType {
   JTYPE_char_Ptr                  = 0,
   JTYPE_int                       = 1,
   JTYPE_CxxConvert_Ptr            = 2
 }; // end of usedType enumeration

 // Build used commands help array
 static char *helpCmd[] = {
   "CxxConvert* = handle ();",
   "void = signal (char * message);",
   "char* = int2hexa (int number);",
   "int = hexa2int (char * chaine);",
 NULL
 }; // end of helpCmd array

/* *** Classes Section *** */
static Tcl_Obj *tclStr_CxxConvert_signal = jWrapStringNew ("signal",6);
class jWrap_CxxConvert : public CxxConvert
{
 private:
 Tcl_Obj    *jTclHandle;  // store jTcl instance object name
 Tcl_Interp *interp;      // Save Interp in order call jTcl from C++

 public: // everything else is public

 // Interface jTcl to C++ for public handle C/C++ function/method
 static int jTcl_handle_0 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_HashEntry *entryPtr;
 jWrap_CxxConvert *objHandle;
 Tcl_Obj *resultPtr;
 struct { union {
   CxxConvert*   appli;
   void *ptr;
 } shared; }result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (module.hashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable index="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 objHandle= (jWrap_CxxConvert*)Tcl_GetHashValue (entryPtr);


 // Check param number
 if (objc != 2) goto  errorNumArg;

 // effectively call C++ function/method
 result.shared.appli =  objHandle->CxxConvert::handle ();

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(CxxConvert**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_CxxConvert_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[0]);
  return TCL_ERROR;
 } // end method jWrap_handle0

 // Interface jTcl to C++ for public signal C/C++ function/method
 static int jTcl_signal_1 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_HashEntry *entryPtr;
 jWrap_CxxConvert *objHandle;
 char * param_0;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 3) goto errorNumArg;

 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (module.hashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable index="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 objHandle= (jWrap_CxxConvert*)Tcl_GetHashValue (entryPtr);


 // Check param number
 if (objc != 3) goto  errorNumArg;

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
 objHandle->CxxConvert::signal (param_0);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[1]);
  return TCL_ERROR;
 } // end method jWrap_signal1

 // Interface C++ -> jTcl for signal C++ method
 virtual void signal (char * param_0)
 {
 Tcl_CmdInfo infoCmd;
 Tcl_Obj *objv[3],*resultObj;
 int     status;
 // Build jTcl cmd start with proc_name + jtcl_obj + method_name
 objv[0] = jTclHandle;
 objv[1] = tclStr_CxxConvert_signal;

 // Translate params from C++ native to Tcl object
 objv[2] = Tcl_NewObj();
 objv[2]->bytes = NULL;
 objv[2]->typePtr = usedType [JTYPE_char_Ptr].obj;
 objv[2]->internalRep.otherValuePtr = (void*) param_0;
 Tcl_IncrRefCount(objv[2]);
  // call jTcl free method
  if (!Tcl_GetCommandInfo (interp, TCL_STRING (jTclHandle), &infoCmd)) {
     jWrapPanic (NULL,"Unknown jTcl  object",TCL_STRING (jTclHandle));
  }
  status = (*infoCmd.objProc) (infoCmd.objClientData, interp,3,objv);

  if (status != TCL_OK) jWrapPanic (NULL,"jTcl Method signal failed");

 // make sure Tcl GCwon't delete internal rep
 objv[2]->typePtr = NULL;
 Tcl_DecrRefCount (objv[2]);
 return;
 } // end method signal

 // Interface jTcl to C++ for public int2hexa C/C++ function/method
 static int jTcl_int2hexa_2 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_HashEntry *entryPtr;
 jWrap_CxxConvert *objHandle;
 Tcl_Obj *resultPtr;
 struct { union {
   char*   appli;
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

 // First check if params number is OK
 if (objc != 3) goto errorNumArg;

 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (module.hashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable index="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 objHandle= (jWrap_CxxConvert*)Tcl_GetHashValue (entryPtr);


 // Check param number
 if (objc != 3) goto  errorNumArg;

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
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  param_0 = *(int*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  objHandle->CxxConvert::int2hexa (param_0);

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
 } // end method jWrap_int2hexa2

 // Interface jTcl to C++ for public hexa2int C/C++ function/method
 static int jTcl_hexa2int_3 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_HashEntry *entryPtr;
 jWrap_CxxConvert *objHandle;
 Tcl_Obj *resultPtr;
 struct { union {
   int   appli;
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

 // First check if params number is OK
 if (objc != 3) goto errorNumArg;

 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (module.hashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable index="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 objHandle= (jWrap_CxxConvert*)Tcl_GetHashValue (entryPtr);


 // Check param number
 if (objc != 3) goto  errorNumArg;

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
 result.shared.appli =  objHandle->CxxConvert::hexa2int (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(int*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_int].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[3]);
  return TCL_ERROR;
 } // end method jWrap_hexa2int3

 // jWrap need a constructor to register jTcl obj reference
 static jTcl_new (ClientData clData, Tcl_Interp *interp
           ,int objc,Tcl_Obj *CONST objv[]) {
 // tempry data for registration of CC obj handle in hashtable
 int isnew; Tcl_HashEntry *entryPtr;


 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

 // Store cc handle in hashtable with jTcl handle as key
 entryPtr = Tcl_CreateHashEntry (&jWrapHashTable ,TCL_STRING (objv[1]), &isnew);
 if (!isnew) goto errorMultiInherit; // Effectively build C++ object and store it in hashtable
 Tcl_SetHashValue (entryPtr, (ClientData) new jWrap_CxxConvert (interp,objv[1]));
 return TCL_OK;


 errorNumArg:
  Tcl_WrongNumArgs (interp, 1, objv, "Syntax: new CxxConvert");
  return TCL_ERROR;

 errorMultiInherit:
  Tcl_AppendResult (interp,"jWrap cannot multi-inherit: class CxxConvert handle="
                   ,TCL_STRING(objv[1]),NULL);
  return TCL_ERROR;
 } // end default jTcl->C++ CxxConvert constructor

 // Destructor clean up c++ object
 ~jWrap_CxxConvert () {
   int status;
   Tcl_CmdInfo infoCmd;
   Tcl_Obj *resultPtr;
   Tcl_Obj *objv[2];

   // if called from jTcl just return
   if (jTclHandle == NULL) return;

   // Build jTcl free cmd
   objv[0] = jWrapFreeMethod;
   objv[1] = jTclHandle;

  // call jTcl free method
  if (!Tcl_GetCommandInfo (interp, TCL_STRING (jTclHandle), &infoCmd)) {
     jWrapPanic (NULL,"Unknown jTcl  object",TCL_STRING (jTclHandle));
  }
   status    = (*infoCmd.objProc) (infoCmd.objClientData, interp,2,objv);

   if (status != TCL_OK) {
     resultPtr = Tcl_GetObjResult(interp);
     jWrapPanic (NULL,TCL_STRING(resultPtr));   }

 } // end C++ destructor

 // jTcl destructor call C++ cleanup
 static int jTcl_free
 (ClientData clData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_HashEntry *entryPtr;
 jWrap_CxxConvert *cxxHandle;
  // prepare emergency panic return
  if (setjmp (jWrapCheckPoint)) {
     return TCL_ERROR;
  }
 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (&jWrapHashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable handle="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 cxxHandle= (jWrap_CxxConvert*)Tcl_GetHashValue (entryPtr);

  // Clean up the place and make C++ destructor not to recall jTcl
  Tcl_DecrRefCount(cxxHandle->jTclHandle);
  cxxHandle->jTclHandle = NULL;

  //effectively destroy C++ object and jTcl reference
  delete (cxxHandle);

  return TCL_OK;
 } // end jTcl destructor

 // internal constructor register C++ handle in jTcl object
 jWrap_CxxConvert (Tcl_Interp *objInterp, Tcl_Obj *jTclObj)
 {
   // Store jTcl object string in C++ object
   Tcl_IncrRefCount (jTclObj);
   jTclHandle = jTclObj;
   interp     = objInterp;
 } // end internal constructor
}; // end class jWrap_CxxConvert


/* ***  Tcl Register Section *** */
#ifdef __cplusplus
extern "C" {
#endif
RESTRICTED int Demooverload_Init (Tcl_Interp *interp) {
 // Dont init twice
 if (initDone) return TCL_OK;
 initDone = 1;

 /* --- Build module handle & register it in jWrap --- */

 module.magic       =JWRAP_MODULE;
 module.name        ="DemoOverload";
 module.help        ="Demonstrate how overloading a C++ function from jTcl";
 module.helpCmd     = helpCmd;
 module.nbCmd       = 4;
 module.hashTable   = NULL;
 module.version     = DemoOverload_CUSTOM_STAMP;
 module.structures  = NULL;
 module.enumerations= NULL;
 module.info        = NULL;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // init routines user or default
#ifdef DemoOverload_CUSTOM_INIT
 DemoOverload_CUSTOM_INIT;
#else
 if (Jwrap_Init (interp) != TCL_OK) return TCL_ERROR;
#endif
 jWrapModuleRegister (interp,&module);

 /* --- Used Type Section --- */

 jWrapTypeCheck (&usedType [0],"char_Ptr",sizeof(char *));
 jWrapTypeCheck (&usedType [1],"int",sizeof(int));
 jWrapTypeCheck (&usedType [2],"CxxConvert_Ptr",sizeof(CxxConvert*));

 /* --- Static Variable registration --- */

 jWrapVarRegister (interp, NULL, "Overload_help", (long*)&Overload_help, 13 
                  , &usedType[JTYPE_char_Ptr]);

 /* --- Class sub-section --- */

 { // registering class CxxConvert in Tcl
 Tcl_Obj *tclClassIndex;
 Tcl_Obj *tclClassValue= Tcl_NewStringObj ("CxxConvert",10);Tcl_IncrRefCount(tclClassValue);
 Tcl_Obj *tclCountValue= Tcl_NewIntObj(0); Tcl_IncrRefCount(tclCountValue);
 Tcl_Obj *tclClassArray= Tcl_NewStringObj ("_C_CxxConvert",13);Tcl_IncrRefCount(tclClassArray);
 Tcl_ObjSetVar2(interp,tclClassArray,jWrapMyString,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_ObjSetVar2(interp,tclClassArray,jWrapExtendsString,tclClassValue,TCL_GLOBAL_ONLY);
 // build a reference Count mandatory for jTcl
 Tcl_ObjSetVar2 (interp,tclClassArray,jWrapInsCountString,tclCountValue,TCL_GLOBAL_ONLY);

 /* --- Static Variable registration --- */
 jWrapVarRegister (interp, tclClassArray, "iscxx", (long*)&CxxConvert::iscxx, 5 
                  , &usedType[JTYPE_int]);

 // register handle C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("handle",6);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("CxxConvert.handle",17);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_CxxConvert::jTcl_handle_0, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);


 // register signal C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("signal",6);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("CxxConvert.signal",17);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_CxxConvert::jTcl_signal_1, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);


 // register int2hexa C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("int2hexa",8);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("CxxConvert.int2hexa",19);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_CxxConvert::jTcl_int2hexa_2, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);


 // register hexa2int C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("hexa2int",8);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("CxxConvert.hexa2int",19);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_CxxConvert::jTcl_hexa2int_3, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);


 // registrate constructor/destructor
 Tcl_CreateObjCommand (interp,"CxxConvert.new", jWrap_CxxConvert::jTcl_new   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 Tcl_CreateObjCommand (interp,"CxxConvert.free", jWrap_CxxConvert::jTcl_free   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 } // end class CxxConvert registration
 return TCL_OK;
} // end function DemoOverload_Init
#ifdef __cplusplus
}
#endif

// ------------------ end funcDemoOverload_jWrap.cxx ----------------------
