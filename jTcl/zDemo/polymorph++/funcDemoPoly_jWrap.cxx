
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: funcDemoPoly_jWrap.cxx demonstrate basic jTcl/C++ multi-inheritance mecanism
 *   Date: Wed Feb 17 14:06:56 1999


 *   jWrap --cc2jTcl /home/fridu/Fulup/Vues/Fridu/Exe/linux86/etc/funcDemoPoly.h.cpp
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
#include "funcDemoPoly.h"

#ifndef DemoPoly_CUSTOM_STAMP
 #ifdef FRIDU
 #define DemoPoly_CUSTOM_STAMP &vStamp_libDemoPoly[12]
 #else
 #define DemoPoly_CUSTOM_STAMP NULL
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
   JTYPE_int                       = 0,
   JTYPE_char_Ptr                  = 1
 }; // end of usedType enumeration

 // Build used commands help array
 static char *helpCmd[] = {
   "void = probe (int number);",
   "void = probe (char * chaine);",
   "void = probe (int number, char * chaine);",
 NULL
 }; // end of helpCmd array

/* *** Classes Section *** */
class jWrap_CxxObj : public CxxObj
{
 private:
 Tcl_Obj    *jTclHandle;  // store jTcl instance object name
 Tcl_Interp *interp;      // Save Interp in order call jTcl from C++

 public: // everything else is public

 // Interface jTcl to C++ for public probe C/C++ function/method
 static int jTcl_probe_0 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_HashEntry *entryPtr;
 jWrap_CxxObj *objHandle;
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
 objHandle= (jWrap_CxxObj*)Tcl_GetHashValue (entryPtr);


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
 objHandle->CxxObj::probe (param_0);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[0]);
  return TCL_ERROR;
 } // end method jWrap_probe0

 // Interface jTcl to C++ for public probe C/C++ function/method
 static int jTcl_probe_1 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_HashEntry *entryPtr;
 jWrap_CxxObj *objHandle;
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
 objHandle= (jWrap_CxxObj*)Tcl_GetHashValue (entryPtr);


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
 objHandle->CxxObj::probe (param_0);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[1]);
  return TCL_ERROR;
 } // end method jWrap_probe1

 // Interface jTcl to C++ for public probe C/C++ function/method
 static int jTcl_probe_2 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_HashEntry *entryPtr;
 jWrap_CxxObj *objHandle;
 int param_0;
 char * param_1;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 4) goto errorNumArg;

 // get cc object handle from jTcl object name
 entryPtr = Tcl_FindHashEntry (module.hashTable
          , TCL_STRING (objv[1]));
 if (entryPtr == NULL) {
  Tcl_AppendResult (interp,"Unknown C++ Object in Hashtable index="
                   ,TCL_STRING (objv[1]),NULL);
  return (TCL_ERROR);
 }
 objHandle= (jWrap_CxxObj*)Tcl_GetHashValue (entryPtr);


 // Check param number
 if (objc != 4) goto  errorNumArg;

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
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(char **)&currentObj->internalRep;

 // effectively call C++ function/method
 objHandle->CxxObj::probe (param_0, param_1);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[2]);
  return TCL_ERROR;
 } // end method jWrap_probe2

 // Extra wrapper for polymorph function probe
 static int jTcl_probe (
  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[] )
 {

 // First check if params number is OK
 switch (objc) {
  case 3: 
  // Check internal type before calling methods
  if (
 ((objv[2]->typePtr == usedType[JTYPE_int].obj)
 ||((objv[2]->typePtr == &jWrapTypeTclObj)
 &&(((JWRAP_cgets*)(objv[2]->internalRep.otherValuePtr))->owner->typePtr
            == usedType[JTYPE_int].obj)))
   ) return ( jWrap_CxxObj::jTcl_probe_0 (cld, interp, objc, objv));
  if (
 ((objv[2]->typePtr == usedType[JTYPE_char_Ptr].obj)
 ||((objv[2]->typePtr == &jWrapTypeTclObj)
 &&(((JWRAP_cgets*)(objv[2]->internalRep.otherValuePtr))->owner->typePtr
            == usedType[JTYPE_char_Ptr].obj)))
   ) return ( jWrap_CxxObj::jTcl_probe_1 (cld, interp, objc, objv));

 // no method fit this prm count
  Tcl_AppendResult (interp,"ERROR: probe polymorph with 1 prm method should be:\n"
    ,"- ", helpCmd [0],"\n"
    ,"- ", helpCmd [1],"\n"
    ,NULL);
   return TCL_ERROR; // end case 3
  case 4: 
    return ( jWrap_CxxObj::jTcl_probe_2 (cld, interp, objc, objv));
  }; // end switch

 // Any other case is an error
 Tcl_AppendResult (interp,"ERROR: probe polymorph method available signatures:\n"
  ,"- ", helpCmd [0],"\n"
  ,"- ", helpCmd [1],"\n"
  ,"- ", helpCmd [2],"\n"
  ,NULL);
 return TCL_ERROR;
 } //end polymorph probe

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
 Tcl_SetHashValue (entryPtr, (ClientData) new jWrap_CxxObj (interp,objv[1]));
 return TCL_OK;


 errorNumArg:
  Tcl_WrongNumArgs (interp, 1, objv, "Syntax: new CxxObj");
  return TCL_ERROR;

 errorMultiInherit:
  Tcl_AppendResult (interp,"jWrap cannot multi-inherit: class CxxObj handle="
                   ,TCL_STRING(objv[1]),NULL);
  return TCL_ERROR;
 } // end default jTcl->C++ CxxObj constructor

 // Destructor clean up c++ object
 ~jWrap_CxxObj () {
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
 jWrap_CxxObj *cxxHandle;
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
 cxxHandle= (jWrap_CxxObj*)Tcl_GetHashValue (entryPtr);

  // Clean up the place and make C++ destructor not to recall jTcl
  Tcl_DecrRefCount(cxxHandle->jTclHandle);
  cxxHandle->jTclHandle = NULL;

  //effectively destroy C++ object and jTcl reference
  delete (cxxHandle);

  return TCL_OK;
 } // end jTcl destructor

 // internal constructor register C++ handle in jTcl object
 jWrap_CxxObj (Tcl_Interp *objInterp, Tcl_Obj *jTclObj)
 {
   // Store jTcl object string in C++ object
   Tcl_IncrRefCount (jTclObj);
   jTclHandle = jTclObj;
   interp     = objInterp;
 } // end internal constructor
}; // end class jWrap_CxxObj


/* ***  Tcl Register Section *** */
#ifdef __cplusplus
extern "C" {
#endif
RESTRICTED int Demopoly_Init (Tcl_Interp *interp) {
 // Dont init twice
 if (initDone) return TCL_OK;
 initDone = 1;

 /* --- Build module handle & register it in jWrap --- */

 module.magic       =JWRAP_MODULE;
 module.name        ="DemoPoly";
 module.help        ="demonstrate basic jTcl/C++ multi-inheritance mecanism";
 module.helpCmd     = helpCmd;
 module.nbCmd       = 3;
 module.hashTable   = NULL;
 module.version     = DemoPoly_CUSTOM_STAMP;
 module.structures  = NULL;
 module.enumerations= NULL;
 module.info        = NULL;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // init routines user or default
#ifdef DemoPoly_CUSTOM_INIT
 DemoPoly_CUSTOM_INIT;
#else
 if (Jwrap_Init (interp) != TCL_OK) return TCL_ERROR;
#endif
 jWrapModuleRegister (interp,&module);

 /* --- Used Type Section --- */

 jWrapTypeCheck (&usedType [0],"int",sizeof(int));
 jWrapTypeCheck (&usedType [1],"char_Ptr",sizeof(char *));

 /* --- Class sub-section --- */

 { // registering class CxxObj in Tcl
 Tcl_Obj *tclClassIndex;
 Tcl_Obj *tclClassValue= Tcl_NewStringObj ("CxxObj",6);Tcl_IncrRefCount(tclClassValue);
 Tcl_Obj *tclCountValue= Tcl_NewIntObj(0); Tcl_IncrRefCount(tclCountValue);
 Tcl_Obj *tclClassArray= Tcl_NewStringObj ("_C_CxxObj",9);Tcl_IncrRefCount(tclClassArray);
 Tcl_ObjSetVar2(interp,tclClassArray,jWrapMyString,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_ObjSetVar2(interp,tclClassArray,jWrapExtendsString,tclClassValue,TCL_GLOBAL_ONLY);
 // build a reference Count mandatory for jTcl
 Tcl_ObjSetVar2 (interp,tclClassArray,jWrapInsCountString,tclCountValue,TCL_GLOBAL_ONLY);

 // register probe C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("probe",5);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("CxxObj.probe",12);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_CxxObj::jTcl_probe_0, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);


 // register probe C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("probe",5);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("CxxObj.probe",12);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_CxxObj::jTcl_probe_1, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);


 // register probe C/C++ entry point as  Tcl command
 tclClassIndex= Tcl_NewStringObj ("probe",5);Tcl_IncrRefCount(tclClassIndex);
 tclClassValue= Tcl_NewStringObj ("CxxObj.probe",12);Tcl_IncrRefCount(tclClassValue);
 Tcl_ObjSetVar2 (interp,tclClassArray,tclClassIndex,tclClassValue,TCL_GLOBAL_ONLY);
 Tcl_CreateObjCommand (interp,TCL_STRING(tclClassValue),jWrap_CxxObj::jTcl_probe_2, (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // registrate extra polymorph wrapper
 Tcl_CreateObjCommand (interp,"CxxObj.probe", jWrap_CxxObj::jTcl_probe   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // registrate constructor/destructor
 Tcl_CreateObjCommand (interp,"CxxObj.new", jWrap_CxxObj::jTcl_new   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 Tcl_CreateObjCommand (interp,"CxxObj.free", jWrap_CxxObj::jTcl_free   , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 } // end class CxxObj registration
 return TCL_OK;
} // end function DemoPoly_Init
#ifdef __cplusplus
}
#endif

// ------------------ end funcDemoPoly_jWrap.cxx ----------------------
