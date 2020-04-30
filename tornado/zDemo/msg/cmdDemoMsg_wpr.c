
/*  ----------------------------------------------------------
 *   File: cmdDemoMsg_wpr.c Tornado/VxWorks Message Queue demo
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   the Tue Feb 16 18:59:41 1999


 *   jWrap --cc2tornado /home/fridu/Fulup/Vues/Fridu/Exe/linux86/etc/cmdDemoMsg.h.cpp
 *
 *   WARNING: Except if you really know what you are doing
 *   you should not edit this file by hand.
 *
 *   In order finding jWrap check: http://www.fridu.bzh
 + ------------------------------------------------------------ */

#ifndef EASYC_PROTO_ONLY
#define EASYC_PROTO_ONLY
#endif
#define JWRAP_CC2TORNADO

#include "libRuntimeTornado.h"
#include "cmdDemoMsg.h"

#define JWRAP_CC2JTCL
#ifndef DemoMsg_CUSTOM_STAMP
 #ifdef FRIDU
 #define DemoMsg_CUSTOM_STAMP &vStamp_libDemoMsg[12]
 #else
 #define DemoMsg_CUSTOM_STAMP NULL
 #endif
#endif

// Special Tornado-Tornado defines for overloading jWrap type translation
 #define jWrapTypeTcl2Cc(P1,P2,P3,P4) tornadoTypeTcl2Cc(&tornadoInfo,P1,P2,P3,P4)
 #define jWrapTypeUpdate(P1,P2,P3,P4)  tornadoTypeUpdate(&tornadoInfo,P1,P2,P3,P4)
 #define jWrapTypeCc2Tcl(P1,P2)       tornadoTypeCc2Tcl(&tornadoInfo,P1,P2)
 #define jWrapTypeClean               tornadoTypeClean
 #define jWrapTypeFree                freeTornadoLocal
 #define JWRAP_CREATE_FUNC            createTornadoLocal
 #define JWRAP_FREE_FUNC              freeTornadoLocal
 #define JWRAP_CGET_FUNC              cGetTornadoLocal
 #define jWrapVarRegister(P1,P2,P3,P4,P5,P6) tornadoVarRegister(&tornadoInfo,P1,P2,P3,P5,P6)
 // do we use wtx or VxWorks malloc ?
 #ifdef USE_TARGET_MALLOC
 #define tornadoTypeFree     tornadoTargetTypeFree
 #define tornadoStringFree   tornadoTargetStringFree
 #define tornadoTypeTcl2Cc   tornadoTargetTypeTcl2Cc
 #define tornadoStringTcl2Cc tornadoTargetStringTcl2Cc
 #endif

 // Build module static informations
 static JWRAP_modules module;
 static int initDone=0;
 static TORNADO_infos tornadoInfo;
 static TORNADO_id    tornadoId;
 static char *errTypeFmt="param:%d type [%s] not equivalent to [%s]\n";

// Build string convertion routine
LOCAL int Put_String (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (tornadoStringTcl2Cc (&tornadoInfo, interp, tclObj));
}
LOCAL void Get_String (Tcl_Obj *tclObj) {
  tornadoStringCc2Tcl (&tornadoInfo, tclObj);
}
LOCAL void Free_String (Tcl_Obj *tclObj) {
  tornadoStringFree (&tornadoInfo, tclObj);
}
// make Manual Alloc/Free Tornado string a Tcl type
static Tcl_ObjType stringType = {
  "DemoMsg_string",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_String,
  (Tcl_SetFromAnyProc*)      Put_String
  };

// make Automatic Alloc/free Tornado string a Tcl type
static Tcl_ObjType stringPtrType = {
  "DemoMsg_string_Ptr",
  (Tcl_FreeInternalRepProc *)Free_String,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_String,
  (Tcl_SetFromAnyProc*)      Put_String
  };


// Build a free wrapper in order Tcl to find Tornado->wtx handle
LOCAL void freeTornadoLocal (Tcl_Obj *objPtr) {
  tornadoTypeFree (&tornadoInfo, objPtr);
}

// Build a create wrapper in order Tcl to find Tornado->wtx handle
LOCAL void createTornadoLocal (Tcl_Interp *interp
           ,JWRAP_structs *structure,Tcl_Obj *srcObj, Tcl_Obj *destObj) {
  tornadoTypeTcl2Cc (&tornadoInfo, interp,structure,srcObj,destObj);
}

// Build a cget wrapper in order Tcl to find Tornado->wtx handle
LOCAL void cGetTornadoLocal (Tcl_Interp *interp
  ,JWRAP_structs *structure,Tcl_Obj *tclObj,Tcl_Obj *slot) {
  tornadoTypeCget (&tornadoInfo, interp,structure,tclObj,slot);
}
 static JWRAP_types usedType [16];

 // Build used type enumeration
 enum enumType {
   JTYPE_Define_DemoMsg            = 0
  ,JTYPE_char_Ptr                  = 1
  ,JTYPE_MsgLists                  = 2
  ,JTYPE_int                       = 3
  ,JTYPE_void_Ptr                  = 4
  ,JTYPE_BB                        = 5
  ,JTYPE_type32                    = 6
  ,JTYPE_short                     = 7
  ,JTYPE_MsgOptions                = 8
  ,JTYPE_MsgPriorities             = 9
  ,JTYPE_MsgStatus                 = 10
  ,JTYPE_MSG_Q_ID                  = 11
  ,JTYPE_MSG_options               = 12
  ,JTYPE_MSG_status                = 13
  ,JTYPE_MSG_priorities            = 14
  ,JTYPE_PART_ID                   = 15
 }; // end of usedType enumeration

 // Build used commands arrays
 static WTX_CONTEXT_DESC wtxCtx [10];
 static char *helpCmd[] = {
   "void* = malloc (int size);",
   "void = free (void * NoName);",
   "MSG_Q_ID = msgQCreate (int maxMsg, int maxMsgLenght, MSG_options option);",
   "MSG_status = msgQDelete (MSG_Q_ID msgQId);",
   "int = msgQNumMsgs (MSG_Q_ID msgId);",
   "int = msgQReceive (MSG_Q_ID msgId, void * buffer, int maxNBytes, int timeout);",
   "MSG_status = msgQSend (MSG_Q_ID msgId, char * buffer, int maxNBytes, int timeout, MSG_priorities priority);",
   "PART_ID = memPartCreate (void * poolBlock, int poolSize);",
   "void* = memPartAlloc (PART_ID partId, int size);",
   "void = memPartFree (PART_ID partId, void * pBlock);",
 NULL
 }; // end of helpCmd array
 static char *nameCmd[] = {
   "malloc",
   "free",
   "msgQCreate",
   "msgQDelete",
   "msgQNumMsgs",
   "msgQReceive",
   "msgQSend",
   "memPartCreate",
   "memPartAlloc",
   "memPartFree",
 NULL
 }; // end of nameCmd array


/* *** Define Section *** */


 // build define enumeration
 typedef long Define_DemoMsg;
 static char *Define_DemoMsg_slotNames [] = {
   "MSG_DEFAULT_LENGHT",
   "forever",
   NULL
 };
 static long Define_DemoMsg_slotValues [] = {
   (long)MSG_DEFAULT_LENGHT,
   (long)forever,
   0
 };
 static JWRAP_enums Define_DemoMsg_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_Define_DemoMsg],
  2,
  Define_DemoMsg_slotNames,
  (long*)Define_DemoMsg_slotValues
 };
LOCAL int Put_Define_DemoMsg (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &Define_DemoMsg_enum, tclObj));
}
LOCAL void Get_Define_DemoMsg (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&Define_DemoMsg_enum, tclObj);
}
// Build Define_DemoMsg jointure as a Tcl type
static Tcl_ObjType Define_DemoMsg_type = {
  "Define_DemoMsg",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Define_DemoMsg,
  (Tcl_SetFromAnyProc*)      Put_Define_DemoMsg
  };


/* *** Enumeration Section *** */


  // build enumeration MsgOptions 
 static char *MsgOptions_slotNames [] = {
   "MSG_Q_FIFO",
   "MSG_Q_PRIORITY",
   NULL
 };
 static enum MsgOptions MsgOptions_slotValues [] = {
   MSG_Q_FIFO,
   MSG_Q_PRIORITY,
   0
 };
 static JWRAP_enums MsgOptions_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_MsgOptions],
  2,
  MsgOptions_slotNames,
  (long*)MsgOptions_slotValues
 };
LOCAL int Put_MsgOptions (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &MsgOptions_enum, tclObj));
}
LOCAL void Get_MsgOptions (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&MsgOptions_enum, tclObj);
}
// Build MsgOptions jointure as a Tcl type
static Tcl_ObjType MsgOptions_type = {
  "MsgOptions",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_MsgOptions,
  (Tcl_SetFromAnyProc*)      Put_MsgOptions
  };

  // build enumeration MsgPriorities 
 static char *MsgPriorities_slotNames [] = {
   "MSG_PRI_NORMAL",
   "MSG_PRI_URGENT",
   NULL
 };
 static enum MsgPriorities MsgPriorities_slotValues [] = {
   MSG_PRI_NORMAL,
   MSG_PRI_URGENT,
   0
 };
 static JWRAP_enums MsgPriorities_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_MsgPriorities],
  2,
  MsgPriorities_slotNames,
  (long*)MsgPriorities_slotValues
 };
LOCAL int Put_MsgPriorities (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &MsgPriorities_enum, tclObj));
}
LOCAL void Get_MsgPriorities (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&MsgPriorities_enum, tclObj);
}
// Build MsgPriorities jointure as a Tcl type
static Tcl_ObjType MsgPriorities_type = {
  "MsgPriorities",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_MsgPriorities,
  (Tcl_SetFromAnyProc*)      Put_MsgPriorities
  };

  // build enumeration MsgStatus 
 static char *MsgStatus_slotNames [] = {
   "MSG_STS_OK",
   "MSG_STS_ERROR",
   "MSG_STS_UNKNOW",
   NULL
 };
 static enum MsgStatus MsgStatus_slotValues [] = {
   MSG_STS_OK,
   MSG_STS_ERROR,
   MSG_STS_UNKNOW,
   0
 };
 static JWRAP_enums MsgStatus_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_MsgStatus],
  3,
  MsgStatus_slotNames,
  (long*)MsgStatus_slotValues
 };
LOCAL int Put_MsgStatus (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &MsgStatus_enum, tclObj));
}
LOCAL void Get_MsgStatus (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&MsgStatus_enum, tclObj);
}
// Build MsgStatus jointure as a Tcl type
static Tcl_ObjType MsgStatus_type = {
  "MsgStatus",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_MsgStatus,
  (Tcl_SetFromAnyProc*)      Put_MsgStatus
  };

 // Hold Defines & Enum reference for jWrap struct help cmd
 static JWRAP_enums *enumerations[]={
  &Define_DemoMsg_enum,
  &MsgOptions_enum,
  &MsgPriorities_enum,
  &MsgStatus_enum,
  NULL
 };
 
/* *** Unions Section *** */


// Alloc type32 slot jointure for Put/Get functions
static char *type32_slotNames[] =  {
    "intValue",
    "pointer",
    NULL
};
static JWRAP_types *type32_slotTypes[] = {
    &usedType [JTYPE_int], // intValue
    &usedType [JTYPE_void_Ptr], // pointer
    NULL
};
static int type32_slotOffsets[2];
static int type32_slotArrays[] = {
    1, // intValue
    1, // pointer
    0
};
static JWRAP_structs type32_union = {
  JWRAP_UNION,
  &usedType [JTYPE_type32],
  2,
  type32_slotNames,
  type32_slotTypes,
  type32_slotOffsets,
  type32_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_type32 (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &type32_union, srcObj, destObj));
}
LOCAL int Put_type32 (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj *destObj) {
  return (jWrapTypeUpdate (interp, &type32_union, srcObj, destObj));
}
LOCAL char* Get_type32 (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&type32_union, tclObj);
}
// Build type32 jointure as a Tcl type
static Tcl_ObjType type32_type = {
  "type32",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_type32,
  (Tcl_SetFromAnyProc*)      Put_type32
  };
// Build type32 jointure as a Tcl type
static Tcl_ObjType type32_ptr = {
  "type32_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_type32,
  (Tcl_SetFromAnyProc*)      Create_type32
  };

// Alloc BB slot jointure for Put/Get functions
static char *BB_slotNames[] =  {
    "shortValue",
    "buffer",
    NULL
};
static JWRAP_types *BB_slotTypes[] = {
    &usedType [JTYPE_short], // shortValue
    &usedType [JTYPE_void_Ptr], // buffer
    NULL
};
static int BB_slotOffsets[2];
static int BB_slotArrays[] = {
    2, // shortValue
    1, // buffer
    0
};
static JWRAP_structs BB_union = {
  JWRAP_UNION,
  &usedType [JTYPE_BB],
  2,
  BB_slotNames,
  BB_slotTypes,
  BB_slotOffsets,
  BB_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_BB (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &BB_union, srcObj, destObj));
}
LOCAL int Put_BB (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj *destObj) {
  return (jWrapTypeUpdate (interp, &BB_union, srcObj, destObj));
}
LOCAL char* Get_BB (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&BB_union, tclObj);
}
// Build BB jointure as a Tcl type
static Tcl_ObjType BB_type = {
  "BB",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_BB,
  (Tcl_SetFromAnyProc*)      Put_BB
  };
// Build BB jointure as a Tcl type
static Tcl_ObjType BB_ptr = {
  "BB_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_BB,
  (Tcl_SetFromAnyProc*)      Create_BB
  };
 
/* *** Structure Section *** */

// Alloc MsgLists slot structure for Put/Get functions
static char *MsgLists_slotNames[] =  {
    "A",
    "name",
    "next",
    "jointure",
    NULL
};
static JWRAP_types *MsgLists_slotTypes[] = {
    &usedType [JTYPE_int], // A 
    &usedType [JTYPE_char_Ptr], // name 
    &usedType [JTYPE_void_Ptr], // next 
    &usedType [JTYPE_BB], // jointure 
    NULL
};
static int MsgLists_slotArrays[] = {
    4, // A
    1, // name
    1, // next
    1, // jointure
    0
};
static int MsgLists_slotOffsets[4];
static JWRAP_structs MsgLists_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_MsgLists],
  4,
  MsgLists_slotNames,
  MsgLists_slotTypes,
  MsgLists_slotOffsets,
  MsgLists_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_MsgLists (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &MsgLists_struct, srcObj, destObj));
}
LOCAL int Put_MsgLists (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &MsgLists_struct, srcObj, destObj));
}
LOCAL char* Get_MsgLists (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&MsgLists_struct, tclObj);
}
// Build MsgLists structure as a Tcl type
static Tcl_ObjType MsgLists_type = {
  "MsgLists",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_MsgLists,
  (Tcl_SetFromAnyProc*)      Put_MsgLists
  };
// Build MsgLists structure as a Tcl type
static Tcl_ObjType MsgLists_ptr = {
  "MsgLists_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_MsgLists,
  (Tcl_SetFromAnyProc*)      Create_MsgLists
  };

 // Hold structure & unions reference for jWrap struct help cmd
 static JWRAP_structs *structures[]={
  &MsgLists_struct,
  &type32_union,
  &BB_union,
  NULL
 };

/* *** Functions Section *** */

 // Interface jTcl to C++ for public malloc C/C++ function/method
 static int jTcl_malloc_0 (
  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 int status;
 Tcl_Obj *currentObj;
 Tcl_Obj tmpCgetObj;
 Tcl_Obj *resultPtr;
 void  *result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  wtxCtx[0].args[0] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // effectivelly call routine on target
 result = tornadoExecFuncCall (&tornadoId, &wtxCtx[0]);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.twoPtrValue.ptr1 = result;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_void_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[0]);
  return TCL_ERROR;
 } // end jWrap_malloc0

 // Interface jTcl to C++ for public free C/C++ function/method
 static int jTcl_free_1 (
  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 int status;
 Tcl_Obj *currentObj;
 Tcl_Obj tmpCgetObj;
 void  *result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  wtxCtx[1].args[0] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // effectivelly call routine on target
 result = tornadoExecFuncCall (&tornadoId, &wtxCtx[1]);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[1]);
  return TCL_ERROR;
 } // end jWrap_free1

 // Interface jTcl to C++ for public msgQCreate C/C++ function/method
 static int jTcl_msgQCreate_2 (
  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 int status;
 Tcl_Obj *currentObj;
 Tcl_Obj tmpCgetObj;
 Tcl_Obj *resultPtr;
 void  *result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 4) goto errorNumArg;

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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  wtxCtx[2].args[0] = (TGT_ARG_T)currentObj->internalRep.longValue;
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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  wtxCtx[2].args[1] = (TGT_ARG_T)currentObj->internalRep.longValue;
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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_MSG_options].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_MSG_options].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_MSG_options].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_MSG_options].obj->name);
 }
  wtxCtx[2].args[2] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // effectivelly call routine on target
 result = tornadoExecFuncCall (&tornadoId, &wtxCtx[2]);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.twoPtrValue.ptr1 = result;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_MSG_Q_ID].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[2]);
  return TCL_ERROR;
 } // end jWrap_msgQCreate2

 // Interface jTcl to C++ for public msgQDelete C/C++ function/method
 static int jTcl_msgQDelete_3 (
  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 int status;
 Tcl_Obj *currentObj;
 Tcl_Obj tmpCgetObj;
 Tcl_Obj *resultPtr;
 void  *result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_MSG_Q_ID].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_MSG_Q_ID].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_MSG_Q_ID].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_MSG_Q_ID].obj->name);
 }
  wtxCtx[3].args[0] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // effectivelly call routine on target
 result = tornadoExecFuncCall (&tornadoId, &wtxCtx[3]);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.twoPtrValue.ptr1 = result;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_MSG_status].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[3]);
  return TCL_ERROR;
 } // end jWrap_msgQDelete3

 // Interface jTcl to C++ for public msgQNumMsgs C/C++ function/method
 static int jTcl_msgQNumMsgs_4 (
  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 int status;
 Tcl_Obj *currentObj;
 Tcl_Obj tmpCgetObj;
 Tcl_Obj *resultPtr;
 void  *result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 2) goto errorNumArg;

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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_MSG_Q_ID].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_MSG_Q_ID].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_MSG_Q_ID].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_MSG_Q_ID].obj->name);
 }
  wtxCtx[4].args[0] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // effectivelly call routine on target
 result = tornadoExecFuncCall (&tornadoId, &wtxCtx[4]);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.twoPtrValue.ptr1 = result;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_int].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[4]);
  return TCL_ERROR;
 } // end jWrap_msgQNumMsgs4

 // Interface jTcl to C++ for public msgQReceive C/C++ function/method
 static int jTcl_msgQReceive_5 (
  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 int status;
 Tcl_Obj *currentObj;
 Tcl_Obj tmpCgetObj;
 Tcl_Obj *resultPtr;
 void  *result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 5) goto errorNumArg;

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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_MSG_Q_ID].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_MSG_Q_ID].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_MSG_Q_ID].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_MSG_Q_ID].obj->name);
 }
  wtxCtx[5].args[0] = (TGT_ARG_T)currentObj->internalRep.longValue;
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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  wtxCtx[5].args[1] = (TGT_ARG_T)currentObj->internalRep.longValue;
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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  wtxCtx[5].args[2] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  wtxCtx[5].args[3] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // effectivelly call routine on target
 result = tornadoExecFuncCall (&tornadoId, &wtxCtx[5]);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.twoPtrValue.ptr1 = result;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_int].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[5]);
  return TCL_ERROR;
 } // end jWrap_msgQReceive5

 // Interface jTcl to C++ for public msgQSend C/C++ function/method
 static int jTcl_msgQSend_6 (
  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 int status;
 Tcl_Obj *currentObj;
 Tcl_Obj tmpCgetObj;
 Tcl_Obj *resultPtr;
 void  *result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 6) goto errorNumArg;

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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_MSG_Q_ID].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_MSG_Q_ID].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_MSG_Q_ID].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_MSG_Q_ID].obj->name);
 }
  wtxCtx[6].args[0] = (TGT_ARG_T)currentObj->internalRep.longValue;
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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  wtxCtx[6].args[1] = (TGT_ARG_T)currentObj->internalRep.longValue;
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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  wtxCtx[6].args[2] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // Check for user application object
 if (objv[4]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[4]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[4]->bytes;
   tmpCgetObj.length  = objv[4]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[4];
 }
 // convert to our wanted application type
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,3,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  wtxCtx[6].args[3] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // Check for user application object
 if (objv[5]->typePtr == &jWrapTypeTclObj) {
   JWRAP_cgets* cget;
   cget = (JWRAP_cgets*)objv[5]->internalRep.twoPtrValue.ptr1;
   // create a tempry object with cget slot
   tmpCgetObj.bytes   = objv[5]->bytes;
   tmpCgetObj.length  = objv[5]->length;
   tmpCgetObj.typePtr = cget->type;
   tmpCgetObj.internalRep.otherValuePtr = cget->valueAdr;
   currentObj    = &tmpCgetObj;
 } else {
   currentObj  = objv[5];
 }
 // convert to our wanted application type
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_MSG_priorities].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_MSG_priorities].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_MSG_priorities].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,4,currentObj->typePtr->name,usedType[JTYPE_MSG_priorities].obj->name);
 }
  wtxCtx[6].args[4] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // effectivelly call routine on target
 result = tornadoExecFuncCall (&tornadoId, &wtxCtx[6]);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.twoPtrValue.ptr1 = result;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_MSG_status].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[6]);
  return TCL_ERROR;
 } // end jWrap_msgQSend6

 // Interface jTcl to C++ for public memPartCreate C/C++ function/method
 static int jTcl_memPartCreate_7 (
  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 int status;
 Tcl_Obj *currentObj;
 Tcl_Obj tmpCgetObj;
 Tcl_Obj *resultPtr;
 void  *result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 3) goto errorNumArg;

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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  wtxCtx[7].args[0] = (TGT_ARG_T)currentObj->internalRep.longValue;
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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  wtxCtx[7].args[1] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // effectivelly call routine on target
 result = tornadoExecFuncCall (&tornadoId, &wtxCtx[7]);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.twoPtrValue.ptr1 = result;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_PART_ID].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[7]);
  return TCL_ERROR;
 } // end jWrap_memPartCreate7

 // Interface jTcl to C++ for public memPartAlloc C/C++ function/method
 static int jTcl_memPartAlloc_8 (
  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 int status;
 Tcl_Obj *currentObj;
 Tcl_Obj tmpCgetObj;
 Tcl_Obj *resultPtr;
 void  *result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 3) goto errorNumArg;

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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_PART_ID].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_PART_ID].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_PART_ID].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_PART_ID].obj->name);
 }
  wtxCtx[8].args[0] = (TGT_ARG_T)currentObj->internalRep.longValue;
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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_int].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_int].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_int].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_int].obj->name);
 }
  wtxCtx[8].args[1] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // effectivelly call routine on target
 result = tornadoExecFuncCall (&tornadoId, &wtxCtx[8]);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.twoPtrValue.ptr1 = result;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_void_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[8]);
  return TCL_ERROR;
 } // end jWrap_memPartAlloc8

 // Interface jTcl to C++ for public memPartFree C/C++ function/method
 static int jTcl_memPartFree_9 (
  ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 int status;
 Tcl_Obj *currentObj;
 Tcl_Obj tmpCgetObj;
 void  *result;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   if (jWrapStaticMessage[0] != '\0') {
     Tcl_SetResult (interp,jWrapStaticMessage,TCL_STATIC);
   }
   return TCL_ERROR;
 }

 // First check if params number is OK
 if (objc != 3) goto errorNumArg;

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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_PART_ID].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_PART_ID].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_PART_ID].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_PART_ID].obj->name);
 }
  wtxCtx[9].args[0] = (TGT_ARG_T)currentObj->internalRep.longValue;
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
 if (currentObj->typePtr == NULL) {
   status = ((Function*)usedType[JTYPE_void_Ptr].obj->setFromAnyProc)
            (interp, currentObj, NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_void_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
     != usedType[JTYPE_void_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_void_Ptr].obj->name);
 }
  wtxCtx[9].args[1] = (TGT_ARG_T)currentObj->internalRep.longValue;
   // effectivelly call routine on target
 result = tornadoExecFuncCall (&tornadoId, &wtxCtx[9]);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[9]);
  return TCL_ERROR;
 } // end jWrap_memPartFree9


/* ***  Tcl Register Section *** */
#ifdef __cplusplus
extern "C" {
#endif

/* ***  Tcl Register Section *** */
#ifdef __cplusplus
extern "C" {
#endif
PUBLIC int Demomsg_Init (Tcl_Interp *interp) {

 /* --- Build module handle & register it in jWrap --- */

 tornadoInfo.magic         = TORNADO_INFO_MAGIC;
 tornadoInfo.wtxCtx        = wtxCtx;
 tornadoInfo.nameCmd       = nameCmd;
 tornadoInfo.tornadoId         = &tornadoId;
 tornadoInfo.stringType    = &stringPtrType;
 tornadoInfo.tornadoFree       = (void*)freeTornadoLocal;

 module.magic        = JWRAP_MODULE;
 module.name           = "DemoMsg";
 module.help           = "Tornado/VxWorks Message Queue demo";
 module.helpCmd        = helpCmd;
 module.nbCmd          = 10;
 module.hashTable      = NULL;
 module.version        = DemoMsg_CUSTOM_STAMP;
 module.structures   = structures;
 module.enumerations = enumerations;
 module.info           = (ClientData) &tornadoInfo;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }
 // Register Target string type
 Tcl_RegisterObjType (&stringType);
 Tcl_RegisterObjType (&stringPtrType);


 // init routines user or default
#ifdef DemoMsg_CUSTOM_INIT
 DemoMsg_CUSTOM_INIT;
#else
 if (Tornado_Init (interp) != TCL_OK) return TCL_ERROR;
#endif
 jWrapModuleRegister (interp,&module);

 jWrapEnumRegister (&module,&Define_DemoMsg_enum,&Define_DemoMsg_type);

 /* --- Enumeration Section --- */

 jWrapEnumRegister (&module, &MsgOptions_enum,&MsgOptions_type);
 jWrapEnumRegister (&module, &MsgPriorities_enum,&MsgPriorities_type);
 jWrapEnumRegister (&module, &MsgStatus_enum,&MsgStatus_type);
 
 /* *** Type Structs/Unions Section *** */
 {  // Compute MsgLists structure offset
  struct MsgLists dummy4offset;
  MsgLists_slotOffsets [0] = (char*)&dummy4offset.A - (char*)&dummy4offset;
  MsgLists_slotOffsets [1] = (char*)&dummy4offset.name - (char*)&dummy4offset;
  MsgLists_slotOffsets [2] = (char*)&dummy4offset.next - (char*)&dummy4offset;
  MsgLists_slotOffsets [3] = (char*)&dummy4offset.jointure - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&MsgLists_struct,&MsgLists_type,&MsgLists_ptr );
 };

 {  // Compute type32 Unions offset
  union type32 dummy4offset;
  type32_slotOffsets [0] = (char*)&dummy4offset.intValue - (char*)&dummy4offset;
  type32_slotOffsets [1] = (char*)&dummy4offset.pointer - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&type32_union,&type32_type,&type32_ptr );
 };

 {  // Compute BB Unions offset
  union BB dummy4offset;
  BB_slotOffsets [0] = (char*)&dummy4offset.shortValue - (char*)&dummy4offset;
  BB_slotOffsets [1] = (char*)&dummy4offset.buffer - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&BB_union,&BB_type,&BB_ptr );
 };
 
 /* *** Type Alias Section *** */
 jWrapTypeAlias (&module,"void_Ptr" ,"MSG_Q_ID");
 jWrapTypeAlias (&module,"void_Ptr" ,"PART_ID");
 jWrapTypeAlias (&module,"type32" ,"TYPE32");
 jWrapTypeAlias (&module,"MsgLists" ,"MSG_lists");
 jWrapTypeAlias (&module,"char" ,"target_char");
 jWrapTypeAlias (&module,"MsgOptions" ,"MSG_options");
 jWrapTypeAlias (&module,"MsgPriorities" ,"MSG_priorities");
 jWrapTypeAlias (&module,"MsgStatus" ,"MSG_status");

 /* --- Used Type Section --- */

 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [0],"Define_DemoMsg",sizeof(Define_DemoMsg));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [1],"char_Ptr",sizeof(char *));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [2],"MsgLists",sizeof(struct MsgLists));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [3],"int",sizeof(int));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [4],"void_Ptr",sizeof(void*));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [5],"BB",sizeof(union BB));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [6],"type32",sizeof(union type32));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [7],"short",sizeof(short));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [8],"MsgOptions",sizeof(enum MsgOptions));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [9],"MsgPriorities",sizeof(enum MsgPriorities));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [10],"MsgStatus",sizeof(enum MsgStatus));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [11],"MSG_Q_ID",sizeof(MSG_Q_ID));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [12],"MSG_options",sizeof(MSG_options));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [13],"MSG_status",sizeof(MSG_status));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [14],"MSG_priorities",sizeof(MSG_priorities));
 tornadoTypeCheck ((TORNADO_infos*)module.info, &usedType [15],"PART_ID",sizeof(PART_ID));

 /* --- Static Variable registration --- */

 // WARNING: [sysBootLine] var not mapped on this version

 /* --- Functions sub-section --- */

 // register malloc C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoMsg.malloc", jTcl_malloc_0  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register free C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoMsg.free", jTcl_free_1  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register msgQCreate C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoMsg.msgQCreate", jTcl_msgQCreate_2  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register msgQDelete C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoMsg.msgQDelete", jTcl_msgQDelete_3  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register msgQNumMsgs C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoMsg.msgQNumMsgs", jTcl_msgQNumMsgs_4  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register msgQReceive C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoMsg.msgQReceive", jTcl_msgQReceive_5  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register msgQSend C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoMsg.msgQSend", jTcl_msgQSend_6  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register memPartCreate C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoMsg.memPartCreate", jTcl_memPartCreate_7  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register memPartAlloc C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoMsg.memPartAlloc", jTcl_memPartAlloc_8  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register memPartFree C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoMsg.memPartFree", jTcl_memPartFree_9  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 return TCL_OK;
} // end function DemoMsg_Init
#ifdef __cplusplus
}
#endif

// ------------------ end cmdDemoMsg_wpr.c ----------------------
