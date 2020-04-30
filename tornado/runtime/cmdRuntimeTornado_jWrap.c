
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: cmdRuntimeTornado_jWrap.c Tornado fast interface to WTX
 *   Date: Mon Mar 22 10:32:39 1999


 *   jWrap --cc2jTcl /home/fridu/Fulup/Vues/Fridu/Exe/linux86/etc/headerTornado.h.cpp
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
#include "headerTornado.h"

#ifndef Tornado_CUSTOM_STAMP
 #ifdef FRIDU
 #define Tornado_CUSTOM_STAMP &vStamp_libTornado[12]
 #else
 #define Tornado_CUSTOM_STAMP NULL
 #endif
#endif

#define JWRAP_CREATE_FUNC jWrapTypeTcl2Cc
#define JWRAP_FREE_FUNC   jWrapTypeFree
#define JWRAP_CGET_FUNC   jWrapTypeCget

 // Build module static informations
 static JWRAP_modules module;
 static int initDone=0;
 static char *errTypeFmt="param:%d type [%s] not equivalent to [%s]\n";
 static JWRAP_types usedType [31];

 // Build used type enumeration
 enum enumType {
   JTYPE_Define_Tornado            = 0,
   JTYPE_TORNADO_id_Ptr            = 1,
   JTYPE_int                       = 2,
   JTYPE_Tcl_Obj_Ptr               = 3,
   JTYPE_TORNADOid                 = 4,
   JTYPE_TORNADO_magics            = 5,
   JTYPE_HWTX                      = 6,
   JTYPE_char_Ptr                  = 7,
   JTYPE_INT32                     = 8,
   JTYPE_TORNADO_endian            = 9,
   JTYPE_void_Ptr                  = 10,
   JTYPE_TORNADOevtRet             = 11,
   JTYPE_WTX_CONTEXT_ID_T          = 12,
   JTYPE_WTX_EVENT_DESC_Ptr        = 13,
   JTYPE_TORNADOinfos              = 14,
   JTYPE_WTX_CONTEXT_DESC_Ptr      = 15,
   JTYPE_char_Ptr_Ptr              = 16,
   JTYPE_Tcl_ObjType_Ptr           = 17,
   JTYPE_tornado_endian            = 18,
   JTYPE_tornado_bindflag          = 19,
   JTYPE_tornado_memflag           = 20,
   JTYPE_tornado_magic             = 21,
   JTYPE_TORNADOevt                = 22,
   JTYPE_TORNADO_memflag           = 23,
   JTYPE_STATUS                    = 24,
   JTYPE_TGT_ADDR_T                = 25,
   JTYPE_long                      = 26,
   JTYPE_UINT32                    = 27,
   JTYPE_WTX_LD_M_FILE_DESC_Ptr    = 28,
   JTYPE_TORNADO_bindflag          = 29,
   JTYPE_JWRAP_varg_Ptr            = 30
 }; // end of usedType enumeration

 // Build used commands help array
 static char *helpCmd[] = {
   "TORNADO_endian = checkEndian ();",
   "void* = tornadoMemBlock (TORNADO_memflag flag, char * value);",
   "void = tornadoReconnect (TORNADO_id * tornadoId);",
   "STATUS = tornadoConnect (TORNADO_id * tornadoId);",
   "STATUS = tornadoEnd (TORNADO_id * tornadoId);",
   "void* = tornadoExecWaitReturn (TORNADO_id * tornadoId, WTX_CONTEXT_ID_T funcId);",
   "char* = tornadoExecFindAddr (TORNADO_id * tornadoId, char * symbol);",
   "TGT_ADDR_T = tornadoExecFindSymbol (TORNADO_id * tornadoId, char * symbol);",
   "WTX_CONTEXT_ID_T = tornadoExecFuncSpawn (TORNADO_id * tornadoId, WTX_CONTEXT_DESC * wtxCtx);",
   "void* = tornadoExecFuncCall (TORNADO_id * tornadoId, WTX_CONTEXT_DESC * wtxCtx);",
   "long = tornadoModuleLoad (TORNADO_id * tornadoId, char * objPath);",
   "UINT32 = tornadoModuleUnload (TORNADO_id * tornadoId, WTX_LD_M_FILE_DESC * objId);",
   "STATUS = tornadoModuleList (TORNADO_id * tornadoId);",
   "void = tornadoModuleBind (TORNADO_id * tornadoId, char * moduleName, TORNADO_bindflag lazy);",
   "char** = tornadoModuleUnresolved (char * moduleName);",
   "void = tornadoDirectGopher (TORNADO_id * tornadoId, JWRAP_varg * result, char * command);",
   "void = tornadoDirectVarsToValues (JWRAP_varg * vars, JWRAP_varg * values);",
   "void* = tornadoDirectFuncCall (TORNADO_id * tornadoId, char * funcName, JWRAP_varg * varg);",
 NULL
 }; // end of helpCmd array


/* *** Define Section *** */


 // build define enumeration
 typedef long Define_Tornado;
 static char *Define_Tornado_slotNames [] = {
   "TORNADO_DEFAULT_HOP_TIMEOUT",
   "TORNADO_OK",
   "TORNADO_ERROR",
   NULL
 };
 static long Define_Tornado_slotValues [] = {
   (long)TORNADO_DEFAULT_HOP_TIMEOUT,
   (long)TORNADO_OK,
   (long)TORNADO_ERROR,
   0
 };
 static JWRAP_enums Define_Tornado_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_Define_Tornado],
  3,
  Define_Tornado_slotNames,
  (long*)Define_Tornado_slotValues
 };
LOCAL int Put_Define_Tornado (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &Define_Tornado_enum, tclObj));
}
LOCAL void Get_Define_Tornado (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&Define_Tornado_enum, tclObj);
}
// Build Define_Tornado jointure as a Tcl type
static Tcl_ObjType Define_Tornado_type = {
  "Define_Tornado",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Define_Tornado,
  (Tcl_SetFromAnyProc*)      Put_Define_Tornado
  };


/* *** Enumeration Section *** */


  // build enumeration tornado_endian 
 static char *tornado_endian_slotNames [] = {
   "ENDIAN_IS_BIG",
   "ENDIAN_IS_LITTLE",
   "ENDIAN_IS_UNKNOW",
   NULL
 };
 static enum tornado_endian tornado_endian_slotValues [] = {
   ENDIAN_IS_BIG,
   ENDIAN_IS_LITTLE,
   ENDIAN_IS_UNKNOW,
   0
 };
 static JWRAP_enums tornado_endian_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_tornado_endian],
  3,
  tornado_endian_slotNames,
  (long*)tornado_endian_slotValues
 };
LOCAL int Put_tornado_endian (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &tornado_endian_enum, tclObj));
}
LOCAL void Get_tornado_endian (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&tornado_endian_enum, tclObj);
}
// Build tornado_endian jointure as a Tcl type
static Tcl_ObjType tornado_endian_type = {
  "tornado_endian",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_tornado_endian,
  (Tcl_SetFromAnyProc*)      Put_tornado_endian
  };

  // build enumeration tornado_bindflag 
 static char *tornado_bindflag_slotNames [] = {
   "BIND_LAZY",
   "BIND_NOW",
   "BIND_UNKNOWN",
   NULL
 };
 static enum tornado_bindflag tornado_bindflag_slotValues [] = {
   BIND_LAZY,
   BIND_NOW,
   BIND_UNKNOWN,
   0
 };
 static JWRAP_enums tornado_bindflag_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_tornado_bindflag],
  3,
  tornado_bindflag_slotNames,
  (long*)tornado_bindflag_slotValues
 };
LOCAL int Put_tornado_bindflag (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &tornado_bindflag_enum, tclObj));
}
LOCAL void Get_tornado_bindflag (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&tornado_bindflag_enum, tclObj);
}
// Build tornado_bindflag jointure as a Tcl type
static Tcl_ObjType tornado_bindflag_type = {
  "tornado_bindflag",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_tornado_bindflag,
  (Tcl_SetFromAnyProc*)      Put_tornado_bindflag
  };

  // build enumeration tornado_memflag 
 static char *tornado_memflag_slotNames [] = {
   "TORNADO_MEM_HEXA",
   "TORNADO_MEM_STRING",
   "TORNADO_MEM_BIG_ENDIAN",
   "TORNADO_MEM_LITTLE_ENDIAN",
   "TORNADO_MEM_UNKNOWN_ENDIAN",
   NULL
 };
 static enum tornado_memflag tornado_memflag_slotValues [] = {
   TORNADO_MEM_HEXA,
   TORNADO_MEM_STRING,
   TORNADO_MEM_BIG_ENDIAN,
   TORNADO_MEM_LITTLE_ENDIAN,
   TORNADO_MEM_UNKNOWN_ENDIAN,
   0
 };
 static JWRAP_enums tornado_memflag_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_tornado_memflag],
  5,
  tornado_memflag_slotNames,
  (long*)tornado_memflag_slotValues
 };
LOCAL int Put_tornado_memflag (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &tornado_memflag_enum, tclObj));
}
LOCAL void Get_tornado_memflag (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&tornado_memflag_enum, tclObj);
}
// Build tornado_memflag jointure as a Tcl type
static Tcl_ObjType tornado_memflag_type = {
  "tornado_memflag",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_tornado_memflag,
  (Tcl_SetFromAnyProc*)      Put_tornado_memflag
  };

  // build enumeration tornado_magic 
 static char *tornado_magic_slotNames [] = {
   "TORNADO_MAGIC_ID",
   "TORNADO_MAGIC_CALL",
   "TORNADO_CTX_T_MAGIC",
   "TORNADO_CTX_ID_MAGIC",
   "TORNADO_INFO_MAGIC",
   "TORNADO_MAGIC_UNKNOW",
   NULL
 };
 static enum tornado_magic tornado_magic_slotValues [] = {
   TORNADO_MAGIC_ID,
   TORNADO_MAGIC_CALL,
   TORNADO_CTX_T_MAGIC,
   TORNADO_CTX_ID_MAGIC,
   TORNADO_INFO_MAGIC,
   TORNADO_MAGIC_UNKNOW,
   0
 };
 static JWRAP_enums tornado_magic_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_tornado_magic],
  6,
  tornado_magic_slotNames,
  (long*)tornado_magic_slotValues
 };
LOCAL int Put_tornado_magic (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &tornado_magic_enum, tclObj));
}
LOCAL void Get_tornado_magic (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&tornado_magic_enum, tclObj);
}
// Build tornado_magic jointure as a Tcl type
static Tcl_ObjType tornado_magic_type = {
  "tornado_magic",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_tornado_magic,
  (Tcl_SetFromAnyProc*)      Put_tornado_magic
  };

  // build enumeration TORNADOevt 
 static char *TORNADOevt_slotNames [] = {
   "TORNADO_EVT_TYPE",
   "TORNADO_EVT_FUNC_ID",
   "TORNADO_EVT_FUNC_RET",
   "TORNADO_EVT_FUNC_STATUS",
   "TORNADO_EVT_UNKNOW",
   NULL
 };
 static enum TORNADOevt TORNADOevt_slotValues [] = {
   TORNADO_EVT_TYPE,
   TORNADO_EVT_FUNC_ID,
   TORNADO_EVT_FUNC_RET,
   TORNADO_EVT_FUNC_STATUS,
   TORNADO_EVT_UNKNOW,
   0
 };
 static JWRAP_enums TORNADOevt_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_TORNADOevt],
  5,
  TORNADOevt_slotNames,
  (long*)TORNADOevt_slotValues
 };
LOCAL int Put_TORNADOevt (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &TORNADOevt_enum, tclObj));
}
LOCAL void Get_TORNADOevt (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&TORNADOevt_enum, tclObj);
}
// Build TORNADOevt jointure as a Tcl type
static Tcl_ObjType TORNADOevt_type = {
  "TORNADOevt",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_TORNADOevt,
  (Tcl_SetFromAnyProc*)      Put_TORNADOevt
  };

 // Hold Defines & Enum reference for jWrap struct help cmd
 static JWRAP_enums *enumerations[]={
  &Define_Tornado_enum,
  &tornado_endian_enum,
  &tornado_bindflag_enum,
  &tornado_memflag_enum,
  &tornado_magic_enum,
  &TORNADOevt_enum,
  NULL
 };
 
/* *** Structure Section *** */

// Alloc TORNADOid slot structure for Put/Get functions
static char *TORNADOid_slotNames[] =  {
    "magic",
    "wtxId",
    "targetName",
    "toolName",
    "vIoNum",
    "vOut",
    "vIn",
    "hostEndian",
    "targetEndian",
    "next",
    NULL
};
static JWRAP_types *TORNADOid_slotTypes[] = {
    &usedType [JTYPE_TORNADO_magics], // magic 
    &usedType [JTYPE_HWTX], // wtxId 
    &usedType [JTYPE_char_Ptr], // targetName 
    &usedType [JTYPE_char_Ptr], // toolName 
    &usedType [JTYPE_INT32], // vIoNum 
    &usedType [JTYPE_INT32], // vOut 
    &usedType [JTYPE_INT32], // vIn 
    &usedType [JTYPE_TORNADO_endian], // hostEndian 
    &usedType [JTYPE_TORNADO_endian], // targetEndian 
    &usedType [JTYPE_void_Ptr], // next 
    NULL
};
static int TORNADOid_slotArrays[] = {
    1, // magic
    1, // wtxId
    1, // targetName
    1, // toolName
    1, // vIoNum
    1, // vOut
    1, // vIn
    1, // hostEndian
    1, // targetEndian
    1, // next
    0
};
static int TORNADOid_slotOffsets[10];
static JWRAP_structs TORNADOid_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_TORNADOid],
  10,
  TORNADOid_slotNames,
  TORNADOid_slotTypes,
  TORNADOid_slotOffsets,
  TORNADOid_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_TORNADOid (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &TORNADOid_struct, srcObj, destObj));
}
LOCAL int Put_TORNADOid (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &TORNADOid_struct, srcObj, destObj));
}
LOCAL char* Get_TORNADOid (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&TORNADOid_struct, tclObj);
}
// Build TORNADOid structure as a Tcl type
static Tcl_ObjType TORNADOid_type = {
  "TORNADOid",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_TORNADOid,
  (Tcl_SetFromAnyProc*)      Put_TORNADOid
  };
// Build TORNADOid structure as a Tcl type
static Tcl_ObjType TORNADOid_ptr = {
  "TORNADOid_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_TORNADOid,
  (Tcl_SetFromAnyProc*)      Create_TORNADOid
  };

// Alloc TORNADOevtRet slot structure for Put/Get functions
static char *TORNADOevtRet_slotNames[] =  {
    "argc",
    "argv",
    "funcId",
    "id",
    "evtNum",
    "tornadoId",
    NULL
};
static JWRAP_types *TORNADOevtRet_slotTypes[] = {
    &usedType [JTYPE_int], // argc 
    &usedType [JTYPE_char_Ptr], // argv 
    &usedType [JTYPE_WTX_CONTEXT_ID_T], // funcId 
    &usedType [JTYPE_WTX_EVENT_DESC_Ptr], // id 
    &usedType [JTYPE_int], // evtNum 
    &usedType [JTYPE_TORNADO_id_Ptr], // tornadoId 
    NULL
};
static int TORNADOevtRet_slotArrays[] = {
    1, // argc
    4, // argv
    1, // funcId
    1, // id
    1, // evtNum
    1, // tornadoId
    0
};
static int TORNADOevtRet_slotOffsets[6];
static JWRAP_structs TORNADOevtRet_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_TORNADOevtRet],
  6,
  TORNADOevtRet_slotNames,
  TORNADOevtRet_slotTypes,
  TORNADOevtRet_slotOffsets,
  TORNADOevtRet_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_TORNADOevtRet (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &TORNADOevtRet_struct, srcObj, destObj));
}
LOCAL int Put_TORNADOevtRet (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &TORNADOevtRet_struct, srcObj, destObj));
}
LOCAL char* Get_TORNADOevtRet (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&TORNADOevtRet_struct, tclObj);
}
// Build TORNADOevtRet structure as a Tcl type
static Tcl_ObjType TORNADOevtRet_type = {
  "TORNADOevtRet",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_TORNADOevtRet,
  (Tcl_SetFromAnyProc*)      Put_TORNADOevtRet
  };
// Build TORNADOevtRet structure as a Tcl type
static Tcl_ObjType TORNADOevtRet_ptr = {
  "TORNADOevtRet_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_TORNADOevtRet,
  (Tcl_SetFromAnyProc*)      Create_TORNADOevtRet
  };

// Alloc TORNADOinfos slot structure for Put/Get functions
static char *TORNADOinfos_slotNames[] =  {
    "magic",
    "tornadoId",
    "wtxCtx",
    "nameCmd",
    "stringType",
    "tornadoFree",
    NULL
};
static JWRAP_types *TORNADOinfos_slotTypes[] = {
    &usedType [JTYPE_TORNADO_magics], // magic 
    &usedType [JTYPE_TORNADO_id_Ptr], // tornadoId 
    &usedType [JTYPE_WTX_CONTEXT_DESC_Ptr], // wtxCtx 
    &usedType [JTYPE_char_Ptr_Ptr], // nameCmd 
    &usedType [JTYPE_Tcl_ObjType_Ptr], // stringType 
    &usedType [JTYPE_void_Ptr], // tornadoFree 
    NULL
};
static int TORNADOinfos_slotArrays[] = {
    1, // magic
    1, // tornadoId
    1, // wtxCtx
    1, // nameCmd
    1, // stringType
    1, // tornadoFree
    0
};
static int TORNADOinfos_slotOffsets[6];
static JWRAP_structs TORNADOinfos_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_TORNADOinfos],
  6,
  TORNADOinfos_slotNames,
  TORNADOinfos_slotTypes,
  TORNADOinfos_slotOffsets,
  TORNADOinfos_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_TORNADOinfos (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &TORNADOinfos_struct, srcObj, destObj));
}
LOCAL int Put_TORNADOinfos (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &TORNADOinfos_struct, srcObj, destObj));
}
LOCAL char* Get_TORNADOinfos (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&TORNADOinfos_struct, tclObj);
}
// Build TORNADOinfos structure as a Tcl type
static Tcl_ObjType TORNADOinfos_type = {
  "TORNADOinfos",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_TORNADOinfos,
  (Tcl_SetFromAnyProc*)      Put_TORNADOinfos
  };
// Build TORNADOinfos structure as a Tcl type
static Tcl_ObjType TORNADOinfos_ptr = {
  "TORNADOinfos_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_TORNADOinfos,
  (Tcl_SetFromAnyProc*)      Create_TORNADOinfos
  };

 // Hold structure & unions reference for jWrap struct help cmd
 static JWRAP_structs *structures[]={
  &TORNADOid_struct,
  &TORNADOevtRet_struct,
  &TORNADOinfos_struct,
  NULL
 };

/* *** Functions Section *** */

 // Interface jTcl to C++ for public checkEndian C/C++ function/method
 static int jTcl_checkEndian_0 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj *resultPtr;
 struct { union {
   TORNADO_endian   appli;
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
 result.shared.appli =  checkEndian ();

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(TORNADO_endian*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_TORNADO_endian].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[0]);
  return TCL_ERROR;
 } // end method jWrap_checkEndian0

 // Interface jTcl to C++ for public tornadoMemBlock C/C++ function/method
 static int jTcl_tornadoMemBlock_1 (
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
 TORNADO_memflag param_0;
 char * param_1;

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
   status = ((Function*)usedType[JTYPE_TORNADO_memflag].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_memflag].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_memflag].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_memflag].obj->name);
 }
  param_0 = *(TORNADO_memflag*)&currentObj->internalRep;

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
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  tornadoMemBlock (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(void**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_void_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[1]);
  return TCL_ERROR;
 } // end method jWrap_tornadoMemBlock1

 // Interface jTcl to C++ for public tornadoReconnect C/C++ function/method
 static int jTcl_tornadoReconnect_2 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 TORNADO_id * param_0;

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
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

 // effectively call C++ function/method
 tornadoReconnect (param_0);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[2]);
  return TCL_ERROR;
 } // end method jWrap_tornadoReconnect2

 // Interface jTcl to C++ for public tornadoConnect C/C++ function/method
 static int jTcl_tornadoConnect_3 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 TORNADO_id * param_0;

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
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  tornadoConnect (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[3]);
  return TCL_ERROR;
 } // end method jWrap_tornadoConnect3

 // Interface jTcl to C++ for public tornadoEnd C/C++ function/method
 static int jTcl_tornadoEnd_4 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 TORNADO_id * param_0;

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
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  tornadoEnd (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[4]);
  return TCL_ERROR;
 } // end method jWrap_tornadoEnd4

 // Interface jTcl to C++ for public tornadoExecWaitReturn C/C++ function/method
 static int jTcl_tornadoExecWaitReturn_5 (
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
 TORNADO_id * param_0;
 WTX_CONTEXT_ID_T param_1;

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
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

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
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_ID_T].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_ID_T].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_ID_T].obj->name);
 }
  param_1 = *(WTX_CONTEXT_ID_T*)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  tornadoExecWaitReturn (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(void**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_void_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[5]);
  return TCL_ERROR;
 } // end method jWrap_tornadoExecWaitReturn5

 // Interface jTcl to C++ for public tornadoExecFindAddr C/C++ function/method
 static int jTcl_tornadoExecFindAddr_6 (
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
 TORNADO_id * param_0;
 char * param_1;

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
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

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
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  tornadoExecFindAddr (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(char**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[6]);
  return TCL_ERROR;
 } // end method jWrap_tornadoExecFindAddr6

 // Interface jTcl to C++ for public tornadoExecFindSymbol C/C++ function/method
 static int jTcl_tornadoExecFindSymbol_7 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   TGT_ADDR_T   appli;
   void *ptr;
 } shared; }result;
 TORNADO_id * param_0;
 char * param_1;

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
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

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
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  tornadoExecFindSymbol (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(TGT_ADDR_T*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_TGT_ADDR_T].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[7]);
  return TCL_ERROR;
 } // end method jWrap_tornadoExecFindSymbol7

 // Interface jTcl to C++ for public tornadoExecFuncSpawn C/C++ function/method
 static int jTcl_tornadoExecFuncSpawn_8 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WTX_CONTEXT_ID_T   appli;
   void *ptr;
 } shared; }result;
 TORNADO_id * param_0;
 WTX_CONTEXT_DESC * param_1;

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
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

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
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj->name);
 }
  param_1 = *(WTX_CONTEXT_DESC **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  tornadoExecFuncSpawn (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(WTX_CONTEXT_ID_T*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WTX_CONTEXT_ID_T].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[8]);
  return TCL_ERROR;
 } // end method jWrap_tornadoExecFuncSpawn8

 // Interface jTcl to C++ for public tornadoExecFuncCall C/C++ function/method
 static int jTcl_tornadoExecFuncCall_9 (
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
 TORNADO_id * param_0;
 WTX_CONTEXT_DESC * param_1;

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
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

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
   status = ((Function*)usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_CONTEXT_DESC_Ptr].obj->name);
 }
  param_1 = *(WTX_CONTEXT_DESC **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  tornadoExecFuncCall (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(void**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_void_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[9]);
  return TCL_ERROR;
 } // end method jWrap_tornadoExecFuncCall9

 // Interface jTcl to C++ for public tornadoModuleLoad C/C++ function/method
 static int jTcl_tornadoModuleLoad_10 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   long   appli;
   void *ptr;
 } shared; }result;
 TORNADO_id * param_0;
 char * param_1;

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
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

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
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(char **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  tornadoModuleLoad (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(long*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_long].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[10]);
  return TCL_ERROR;
 } // end method jWrap_tornadoModuleLoad10

 // Interface jTcl to C++ for public tornadoModuleUnload C/C++ function/method
 static int jTcl_tornadoModuleUnload_11 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   UINT32   appli;
   void *ptr;
 } shared; }result;
 TORNADO_id * param_0;
 WTX_LD_M_FILE_DESC * param_1;

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
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

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
   status = ((Function*)usedType[JTYPE_WTX_LD_M_FILE_DESC_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WTX_LD_M_FILE_DESC_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WTX_LD_M_FILE_DESC_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_WTX_LD_M_FILE_DESC_Ptr].obj->name);
 }
  param_1 = *(WTX_LD_M_FILE_DESC **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  tornadoModuleUnload (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(UINT32*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_UINT32].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[11]);
  return TCL_ERROR;
 } // end method jWrap_tornadoModuleUnload11

 // Interface jTcl to C++ for public tornadoModuleList C/C++ function/method
 static int jTcl_tornadoModuleList_12 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   STATUS   appli;
   void *ptr;
 } shared; }result;
 TORNADO_id * param_0;

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
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  tornadoModuleList (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(STATUS*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_STATUS].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[12]);
  return TCL_ERROR;
 } // end method jWrap_tornadoModuleList12

 // Interface jTcl to C++ for public tornadoModuleBind C/C++ function/method
 static int jTcl_tornadoModuleBind_13 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 TORNADO_id * param_0;
 char * param_1;
 TORNADO_bindflag param_2;

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
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

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
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(char **)&currentObj->internalRep;

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
   status = ((Function*)usedType[JTYPE_TORNADO_bindflag].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_bindflag].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_bindflag].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_TORNADO_bindflag].obj->name);
 }
  param_2 = *(TORNADO_bindflag*)&currentObj->internalRep;

 // effectively call C++ function/method
 tornadoModuleBind (param_0, param_1, param_2);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[13]);
  return TCL_ERROR;
 } // end method jWrap_tornadoModuleBind13

 // Interface jTcl to C++ for public tornadoModuleUnresolved C/C++ function/method
 static int jTcl_tornadoModuleUnresolved_14 (
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
 result.shared.appli =  tornadoModuleUnresolved (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(char***)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_char_Ptr_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[14]);
  return TCL_ERROR;
 } // end method jWrap_tornadoModuleUnresolved14

 // Interface jTcl to C++ for public tornadoDirectGopher C/C++ function/method
 static int jTcl_tornadoDirectGopher_15 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 TORNADO_id * param_0;
 JWRAP_varg * param_1;
 char * param_2;

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
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

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
   status = ((Function*)usedType[JTYPE_JWRAP_varg_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_JWRAP_varg_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_JWRAP_varg_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_JWRAP_varg_Ptr].obj->name);
 }
  param_1 = *(JWRAP_varg **)&currentObj->internalRep;

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
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_2 = *(char **)&currentObj->internalRep;

 // effectively call C++ function/method
 tornadoDirectGopher (param_0, param_1, param_2);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[15]);
  return TCL_ERROR;
 } // end method jWrap_tornadoDirectGopher15

 // Interface jTcl to C++ for public tornadoDirectVarsToValues C/C++ function/method
 static int jTcl_tornadoDirectVarsToValues_16 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 JWRAP_varg * param_0;
 JWRAP_varg * param_1;

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
   status = ((Function*)usedType[JTYPE_JWRAP_varg_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_JWRAP_varg_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_JWRAP_varg_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_JWRAP_varg_Ptr].obj->name);
 }
  param_0 = *(JWRAP_varg **)&currentObj->internalRep;

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
   status = ((Function*)usedType[JTYPE_JWRAP_varg_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_JWRAP_varg_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_JWRAP_varg_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_JWRAP_varg_Ptr].obj->name);
 }
  param_1 = *(JWRAP_varg **)&currentObj->internalRep;

 // effectively call C++ function/method
 tornadoDirectVarsToValues (param_0, param_1);

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[16]);
  return TCL_ERROR;
 } // end method jWrap_tornadoDirectVarsToValues16

 // Interface jTcl to C++ for public tornadoDirectFuncCall C/C++ function/method
 static int jTcl_tornadoDirectFuncCall_17 (
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
 TORNADO_id * param_0;
 char * param_1;
 JWRAP_varg * param_2;

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
 if ((currentObj->typePtr==0)||(currentObj->typePtr==jWrapTypeList)){
   status = ((Function*)usedType[JTYPE_TORNADO_id_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_TORNADO_id_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_TORNADO_id_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_TORNADO_id_Ptr].obj->name);
 }
  param_0 = *(TORNADO_id **)&currentObj->internalRep;

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
  jWrapPanic (interp,errTypeFmt  ,1,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_1 = *(char **)&currentObj->internalRep;

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
   status = ((Function*)usedType[JTYPE_JWRAP_varg_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_JWRAP_varg_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_JWRAP_varg_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_JWRAP_varg_Ptr].obj->name);
 }
  param_2 = *(JWRAP_varg **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  tornadoDirectFuncCall (param_0, param_1, param_2);

 resultPtr = Tcl_GetObjResult (interp);
 // copy result in Tcl internal value without checking it
 resultPtr->internalRep.longValue = 0;
 *(void**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_void_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[17]);
  return TCL_ERROR;
 } // end method jWrap_tornadoDirectFuncCall17


/* ***  Tcl Register Section *** */
#ifdef __cplusplus
extern "C" {
#endif
RESTRICTED int Tornado_Init (Tcl_Interp *interp) {
 // Dont init twice
 if (initDone) return TCL_OK;
 initDone = 1;

 /* --- Build module handle & register it in jWrap --- */

 module.magic       =JWRAP_MODULE;
 module.name        ="Tornado";
 module.help        ="Tornado fast interface to WTX";
 module.helpCmd     = helpCmd;
 module.nbCmd       = 18;
 module.hashTable   = NULL;
 module.version     = Tornado_CUSTOM_STAMP;
 module.structures  = structures;
 module.enumerations= enumerations;
 module.info        = NULL;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // init routines user or default
#ifdef Tornado_CUSTOM_INIT
 Tornado_CUSTOM_INIT;
#else
 if (Jwrap_Init (interp) != TCL_OK) return TCL_ERROR;
#endif
 jWrapModuleRegister (interp,&module);
 jWrapEnumRegister (&module,&Define_Tornado_enum,&Define_Tornado_type);

 /* --- Enumeration Section --- */

 jWrapEnumRegister (&module, &tornado_endian_enum,&tornado_endian_type);
 jWrapEnumRegister (&module, &tornado_bindflag_enum,&tornado_bindflag_type);
 jWrapEnumRegister (&module, &tornado_memflag_enum,&tornado_memflag_type);
 jWrapEnumRegister (&module, &tornado_magic_enum,&tornado_magic_type);
 jWrapEnumRegister (&module, &TORNADOevt_enum,&TORNADOevt_type);
 
 /* *** Type Structs/Unions Section *** */
 {  // Compute TORNADOid structure offset
  struct TORNADOid dummy4offset;
  TORNADOid_slotOffsets [0] = (char*)&dummy4offset.magic - (char*)&dummy4offset;
  TORNADOid_slotOffsets [1] = (char*)&dummy4offset.wtxId - (char*)&dummy4offset;
  TORNADOid_slotOffsets [2] = (char*)&dummy4offset.targetName - (char*)&dummy4offset;
  TORNADOid_slotOffsets [3] = (char*)&dummy4offset.toolName - (char*)&dummy4offset;
  TORNADOid_slotOffsets [4] = (char*)&dummy4offset.vIoNum - (char*)&dummy4offset;
  TORNADOid_slotOffsets [5] = (char*)&dummy4offset.vOut - (char*)&dummy4offset;
  TORNADOid_slotOffsets [6] = (char*)&dummy4offset.vIn - (char*)&dummy4offset;
  TORNADOid_slotOffsets [7] = (char*)&dummy4offset.hostEndian - (char*)&dummy4offset;
  TORNADOid_slotOffsets [8] = (char*)&dummy4offset.targetEndian - (char*)&dummy4offset;
  TORNADOid_slotOffsets [9] = (char*)&dummy4offset.next - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&TORNADOid_struct,&TORNADOid_type,&TORNADOid_ptr );
 };
 {  // Compute TORNADOevtRet structure offset
  struct TORNADOevtRet dummy4offset;
  TORNADOevtRet_slotOffsets [0] = (char*)&dummy4offset.argc - (char*)&dummy4offset;
  TORNADOevtRet_slotOffsets [1] = (char*)&dummy4offset.argv - (char*)&dummy4offset;
  TORNADOevtRet_slotOffsets [2] = (char*)&dummy4offset.funcId - (char*)&dummy4offset;
  TORNADOevtRet_slotOffsets [3] = (char*)&dummy4offset.id - (char*)&dummy4offset;
  TORNADOevtRet_slotOffsets [4] = (char*)&dummy4offset.evtNum - (char*)&dummy4offset;
  TORNADOevtRet_slotOffsets [5] = (char*)&dummy4offset.tornadoId - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&TORNADOevtRet_struct,&TORNADOevtRet_type,&TORNADOevtRet_ptr );
 };
 {  // Compute TORNADOinfos structure offset
  struct TORNADOinfos dummy4offset;
  TORNADOinfos_slotOffsets [0] = (char*)&dummy4offset.magic - (char*)&dummy4offset;
  TORNADOinfos_slotOffsets [1] = (char*)&dummy4offset.tornadoId - (char*)&dummy4offset;
  TORNADOinfos_slotOffsets [2] = (char*)&dummy4offset.wtxCtx - (char*)&dummy4offset;
  TORNADOinfos_slotOffsets [3] = (char*)&dummy4offset.nameCmd - (char*)&dummy4offset;
  TORNADOinfos_slotOffsets [4] = (char*)&dummy4offset.stringType - (char*)&dummy4offset;
  TORNADOinfos_slotOffsets [5] = (char*)&dummy4offset.tornadoFree - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&TORNADOinfos_struct,&TORNADOinfos_type,&TORNADOinfos_ptr );
 };
 
 /* *** Type Alias Section *** */
 jWrapTypeAlias (&module,"tornado_endian" ,"TORNADO_endian");
 jWrapTypeAlias (&module,"tornado_bindflag" ,"TORNADO_bindflag");
 jWrapTypeAlias (&module,"tornado_memflag" ,"TORNADO_memflag");
 jWrapTypeAlias (&module,"tornado_magic" ,"TORNADO_magics");
 jWrapTypeAlias (&module,"TORNADOevt" ,"TORNADO_evt");
 jWrapTypeAlias (&module,"TORNADOid" ,"TORNADO_id");
 jWrapTypeAlias (&module,"TORNADOevtRet" ,"TORNADO_evtRet");
 jWrapTypeAlias (&module,"TORNADOinfos" ,"TORNADO_infos");

 /* --- Used Type Section --- */

 jWrapTypeCheck (&usedType [0],"Define_Tornado",sizeof(Define_Tornado));
 jWrapTypeCheck (&usedType [1],"TORNADO_id_Ptr",sizeof(TORNADO_id *));
 jWrapTypeCheck (&usedType [2],"int",sizeof(int));
 jWrapTypeCheck (&usedType [3],"Tcl_Obj_Ptr",sizeof(Tcl_Obj *));
 jWrapTypeCheck (&usedType [4],"TORNADOid",sizeof(struct TORNADOid));
 jWrapTypeCheck (&usedType [5],"TORNADO_magics",sizeof(TORNADO_magics));
 jWrapTypeCheck (&usedType [6],"HWTX",sizeof(HWTX));
 jWrapTypeCheck (&usedType [7],"char_Ptr",sizeof(char*));
 jWrapTypeCheck (&usedType [8],"INT32",sizeof(INT32));
 jWrapTypeCheck (&usedType [9],"TORNADO_endian",sizeof(TORNADO_endian));
 jWrapTypeCheck (&usedType [10],"void_Ptr",sizeof(void*));
 jWrapTypeCheck (&usedType [11],"TORNADOevtRet",sizeof(struct TORNADOevtRet));
 jWrapTypeCheck (&usedType [12],"WTX_CONTEXT_ID_T",sizeof(WTX_CONTEXT_ID_T));
 jWrapTypeCheck (&usedType [13],"WTX_EVENT_DESC_Ptr",sizeof(WTX_EVENT_DESC*));
 jWrapTypeCheck (&usedType [14],"TORNADOinfos",sizeof(struct TORNADOinfos));
 jWrapTypeCheck (&usedType [15],"WTX_CONTEXT_DESC_Ptr",sizeof(WTX_CONTEXT_DESC*));
 jWrapTypeCheck (&usedType [16],"char_Ptr_Ptr",sizeof(char**));
 jWrapTypeCheck (&usedType [17],"Tcl_ObjType_Ptr",sizeof(Tcl_ObjType*));
 jWrapTypeCheck (&usedType [18],"tornado_endian",sizeof(enum tornado_endian));
 jWrapTypeCheck (&usedType [19],"tornado_bindflag",sizeof(enum tornado_bindflag));
 jWrapTypeCheck (&usedType [20],"tornado_memflag",sizeof(enum tornado_memflag));
 jWrapTypeCheck (&usedType [21],"tornado_magic",sizeof(enum tornado_magic));
 jWrapTypeCheck (&usedType [22],"TORNADOevt",sizeof(enum TORNADOevt));
 jWrapTypeCheck (&usedType [23],"TORNADO_memflag",sizeof(TORNADO_memflag));
 jWrapTypeCheck (&usedType [24],"STATUS",sizeof(STATUS));
 jWrapTypeCheck (&usedType [25],"TGT_ADDR_T",sizeof(TGT_ADDR_T));
 jWrapTypeCheck (&usedType [26],"long",sizeof(long));
 jWrapTypeCheck (&usedType [27],"UINT32",sizeof(UINT32));
 jWrapTypeCheck (&usedType [28],"WTX_LD_M_FILE_DESC_Ptr",sizeof(WTX_LD_M_FILE_DESC *));
 jWrapTypeCheck (&usedType [29],"TORNADO_bindflag",sizeof(TORNADO_bindflag));
 jWrapTypeCheck (&usedType [30],"JWRAP_varg_Ptr",sizeof(JWRAP_varg *));

 /* --- Static Variable registration --- */

 jWrapVarRegister (interp, NULL, "tornadoIdHead", (long*)&tornadoIdHead, 13 
                  , &usedType[JTYPE_TORNADO_id_Ptr]);
 jWrapVarRegister (interp, NULL, "tornadoExecHopCount", (long*)&tornadoExecHopCount, 19 
                  , &usedType[JTYPE_int]);
 jWrapVarRegister (interp, NULL, "tornadoGlobalVar", (long*)&tornadoGlobalVar, 16 
                  , &usedType[JTYPE_Tcl_Obj_Ptr]);

 /* --- Functions sub-section --- */

 // register checkEndian C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.checkEndian", jTcl_checkEndian_0  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoMemBlock C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.MemBlock", jTcl_tornadoMemBlock_1  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoReconnect C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.Reconnect", jTcl_tornadoReconnect_2  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoConnect C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.Connect", jTcl_tornadoConnect_3  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoEnd C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.End", jTcl_tornadoEnd_4  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoExecWaitReturn C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.ExecWaitReturn", jTcl_tornadoExecWaitReturn_5  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoExecFindAddr C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.ExecFindAddr", jTcl_tornadoExecFindAddr_6  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoExecFindSymbol C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.ExecFindSymbol", jTcl_tornadoExecFindSymbol_7  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoExecFuncSpawn C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.ExecFuncSpawn", jTcl_tornadoExecFuncSpawn_8  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoExecFuncCall C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.ExecFuncCall", jTcl_tornadoExecFuncCall_9  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoModuleLoad C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.ModuleLoad", jTcl_tornadoModuleLoad_10  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoModuleUnload C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.ModuleUnload", jTcl_tornadoModuleUnload_11  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoModuleList C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.ModuleList", jTcl_tornadoModuleList_12  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoModuleBind C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.ModuleBind", jTcl_tornadoModuleBind_13  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoModuleUnresolved C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.ModuleUnresolved", jTcl_tornadoModuleUnresolved_14  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoDirectGopher C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.DirectGopher", jTcl_tornadoDirectGopher_15  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoDirectVarsToValues C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.DirectVarsToValues", jTcl_tornadoDirectVarsToValues_16  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register tornadoDirectFuncCall C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"Tornado.DirectFuncCall", jTcl_tornadoDirectFuncCall_17  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 return TCL_OK;
} // end function Tornado_Init
#ifdef __cplusplus
}
#endif

// ------------------ end cmdRuntimeTornado_jWrap.c ----------------------
