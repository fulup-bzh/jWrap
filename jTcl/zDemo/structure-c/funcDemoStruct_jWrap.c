
/*  ----------------------------------------------------------
 *   This file was automatically generated with
 *   jWrap (C)FRIDU a Free Software Company 97-98
 *   File: funcDemoStruct_jWrap.c Demonstrate Complex Structure handling
 *   Date: Fri May  1 15:21:43 2020


 *   jWrap --cc2jTcl funcDemoStruct.c
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
#include "funcDemoStruct.c"

#ifndef DemoStruct_CUSTOM_STAMP
 #ifdef FRIDU
 #define DemoStruct_CUSTOM_STAMP &vStamp_libDemoStruct[12]
 #else
 #define DemoStruct_CUSTOM_STAMP NULL
 #endif
#endif

#define JWRAP_CREATE_FUNC jWrapTypeTcl2Cc
#define JWRAP_FREE_FUNC   jWrapTypeFree
#define JWRAP_CGET_FUNC   jWrapTypeCget

 // Build module static informations
 static JWRAP_modules module;
 static int initDone=0;
 static char *errTypeFmt="param:%d type [%s] not equivalent to [%s]\n";
 static JWRAP_types usedType [25];

 // Build used type enumeration
 enum enumType {
   JTYPE_Define_DemoStruct         = 0,
   JTYPE_LINKED_LST_Ptr            = 1,
   JTYPE_str_sadr                  = 2,
   JTYPE_t_sadr_type               = 3,
   JTYPE_char_Ptr                  = 4,
   JTYPE_str_CC_S_BIND_REQ         = 5,
   JTYPE_int16u                    = 6,
   JTYPE_int8u                     = 7,
   JTYPE_int8u_Ptr                 = 8,
   JTYPE_boolean                   = 9,
   JTYPE_Struct_DemoStruct_0       = 10,
   JTYPE_int                       = 11,
   JTYPE_wprId                     = 12,
   JTYPE_choix                     = 13,
   JTYPE_Union_DemoStruct_0        = 14,
   JTYPE_UINT32                    = 15,
   JTYPE_FILE_Ptr                  = 16,
   JTYPE_linkedList                = 17,
   JTYPE_void_Ptr                  = 18,
   JTYPE_short                     = 19,
   JTYPE_char                      = 20,
   JTYPE_double                    = 21,
   JTYPE_Enum_DemoStruct_0         = 22,
   JTYPE_size_t                    = 23,
   JTYPE_WPR_ID_Ptr                = 24
 }; // end of usedType enumeration

 // Build used commands help array
 static char *helpCmd[] = {
   "FILE* = fopen (char * name, char * opt);",
   "int = fclose (FILE * NoName);",
   "void* = memcpy (void * dest, const void * src, size_t n);",
   "WPR_ID* = testIt (WPR_ID * wprId);",
   "void = testLst ();",
 NULL
 }; // end of helpCmd array


/* *** Define Section *** */


 // build define enumeration
 typedef long Define_DemoStruct;
 static char *Define_DemoStruct_slotNames [] = {
   "VA",
   "TOTO",
   "TATA",
   NULL
 };
 static long Define_DemoStruct_slotValues [] = {
   (long)VA,
   (long)TOTO,
   (long)TATA,
   0
 };
 static JWRAP_enums Define_DemoStruct_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_Define_DemoStruct],
  3,
  Define_DemoStruct_slotNames,
  (long*)Define_DemoStruct_slotValues
 };
LOCAL int Put_Define_DemoStruct (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &Define_DemoStruct_enum, tclObj));
}
LOCAL void Get_Define_DemoStruct (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&Define_DemoStruct_enum, tclObj);
}
// Build Define_DemoStruct jointure as a Tcl type
static Tcl_ObjType Define_DemoStruct_type = {
  "Define_DemoStruct",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Define_DemoStruct,
  (Tcl_SetFromAnyProc*)      Put_Define_DemoStruct
  };


/* *** Enumeration Section *** */

 // As enum as no name we produce a dummy enumeration for size computing
 enum Enum_DemoStruct_0 {
   slot_1_0= USER_SPECIFIC,
   slot_1_1= RESERVE_1,
   slot_1_2= SPECIAL_SADR,
   slot_1_3= RESERVE_2,
   slot_1_4= UNKNOWN_SADR_TYPE
 };

  // build enumeration Enum_DemoStruct_0 
 static char *Enum_DemoStruct_0_slotNames [] = {
   "USER_SPECIFIC",
   "RESERVE_1",
   "SPECIAL_SADR",
   "RESERVE_2",
   "UNKNOWN_SADR_TYPE",
   NULL
 };
 static enum Enum_DemoStruct_0 Enum_DemoStruct_0_slotValues [] = {
   USER_SPECIFIC,
   RESERVE_1,
   SPECIAL_SADR,
   RESERVE_2,
   UNKNOWN_SADR_TYPE,
   0
 };
 static JWRAP_enums Enum_DemoStruct_0_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_Enum_DemoStruct_0],
  5,
  Enum_DemoStruct_0_slotNames,
  (long*)Enum_DemoStruct_0_slotValues
 };
LOCAL int Put_Enum_DemoStruct_0 (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &Enum_DemoStruct_0_enum, tclObj));
}
LOCAL void Get_Enum_DemoStruct_0 (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&Enum_DemoStruct_0_enum, tclObj);
}
// Build Enum_DemoStruct_0 jointure as a Tcl type
static Tcl_ObjType Enum_DemoStruct_0_type = {
  "Enum_DemoStruct_0",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Enum_DemoStruct_0,
  (Tcl_SetFromAnyProc*)      Put_Enum_DemoStruct_0
  };

  // build enumeration choix 
 static char *choix_slotNames [] = {
   "A",
   "B",
   "C",
   "D",
   NULL
 };
 static enum choix choix_slotValues [] = {
   A,
   B,
   C,
   D,
   0
 };
 static JWRAP_enums choix_enum  = {
  JWRAP_ENUM,  &usedType [JTYPE_choix],
  4,
  choix_slotNames,
  (long*)choix_slotValues
 };
LOCAL int Put_choix (Tcl_Interp *interp, Tcl_Obj *tclObj) {
  return (jWrapEnumTcl2Cc (interp, &choix_enum, tclObj));
}
LOCAL void Get_choix (Tcl_Obj *tclObj) {
  jWrapEnumCc2Tcl (&choix_enum, tclObj);
}
// Build choix jointure as a Tcl type
static Tcl_ObjType choix_type = {
  "choix",
  (Tcl_FreeInternalRepProc *)NULL,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_choix,
  (Tcl_SetFromAnyProc*)      Put_choix
  };

 // Hold Defines & Enum reference for jWrap struct help cmd
 static JWRAP_enums *enumerations[]={
  &Define_DemoStruct_enum,
  &Enum_DemoStruct_0_enum,
  &choix_enum,
  NULL
 };
 
/* *** Unions Section *** */

// We need to produce internal union in order computing size
union Union_DemoStruct_0 {
  int A;
  short B;
  char C;
  double D;
};
typedef union Union_DemoStruct_0 Union_DemoStruct_0;

// Alloc Union_DemoStruct_0 slot jointure for Put/Get functions
static char *Union_DemoStruct_0_slotNames[] =  {
    "A",
    "B",
    "C",
    "D",
    NULL
};
static JWRAP_types *Union_DemoStruct_0_slotTypes[] = {
    &usedType [JTYPE_int], // A
    &usedType [JTYPE_short], // B
    &usedType [JTYPE_char], // C
    &usedType [JTYPE_double], // D
    NULL
};
static int Union_DemoStruct_0_slotOffsets[4];
static int Union_DemoStruct_0_slotArrays[] = {
    2, // A
    4, // B
    8, // C
    1, // D
    0
};
static JWRAP_structs Union_DemoStruct_0_union = {
  JWRAP_UNION,
  &usedType [JTYPE_Union_DemoStruct_0],
  4,
  Union_DemoStruct_0_slotNames,
  Union_DemoStruct_0_slotTypes,
  Union_DemoStruct_0_slotOffsets,
  Union_DemoStruct_0_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_Union_DemoStruct_0 (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &Union_DemoStruct_0_union, srcObj, destObj));
}
LOCAL int Put_Union_DemoStruct_0 (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj *destObj) {
  return (jWrapTypeUpdate (interp, &Union_DemoStruct_0_union, srcObj, destObj));
}
LOCAL char* Get_Union_DemoStruct_0 (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&Union_DemoStruct_0_union, tclObj);
}
// Build Union_DemoStruct_0 jointure as a Tcl type
static Tcl_ObjType Union_DemoStruct_0_type = {
  "Union_DemoStruct_0",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Union_DemoStruct_0,
  (Tcl_SetFromAnyProc*)      Put_Union_DemoStruct_0
  };
// Build Union_DemoStruct_0 jointure as a Tcl type
static Tcl_ObjType Union_DemoStruct_0_ptr = {
  "Union_DemoStruct_0_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Union_DemoStruct_0,
  (Tcl_SetFromAnyProc*)      Create_Union_DemoStruct_0
  };
 
/* *** Structure Section *** */

// Alloc str_sadr slot structure for Put/Get functions
static char *str_sadr_slotNames[] =  {
    "type",
    "digits",
    NULL
};
static JWRAP_types *str_sadr_slotTypes[] = {
    &usedType [JTYPE_t_sadr_type], // type 
    &usedType [JTYPE_char_Ptr], // digits 
    NULL
};
static int str_sadr_slotArrays[] = {
    1, // type
    1, // digits
    0
};
static int str_sadr_slotOffsets[2];
static JWRAP_structs str_sadr_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_str_sadr],
  2,
  str_sadr_slotNames,
  str_sadr_slotTypes,
  str_sadr_slotOffsets,
  str_sadr_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_str_sadr (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &str_sadr_struct, srcObj, destObj));
}
LOCAL int Put_str_sadr (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &str_sadr_struct, srcObj, destObj));
}
LOCAL char* Get_str_sadr (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&str_sadr_struct, tclObj);
}
// Build str_sadr structure as a Tcl type
static Tcl_ObjType str_sadr_type = {
  "str_sadr",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_str_sadr,
  (Tcl_SetFromAnyProc*)      Put_str_sadr
  };
// Build str_sadr structure as a Tcl type
static Tcl_ObjType str_sadr_ptr = {
  "str_sadr_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_str_sadr,
  (Tcl_SetFromAnyProc*)      Create_str_sadr
  };

// Alloc str_CC_S_BIND_REQ slot structure for Put/Get functions
static char *str_CC_S_BIND_REQ_slotNames[] =  {
    "app_q_id",
    "ref",
    "ctx_max",
    "con_type",
    "mode",
    "user_to_user",
    "data_service",
    NULL
};
static JWRAP_types *str_CC_S_BIND_REQ_slotTypes[] = {
    &usedType [JTYPE_int16u], // app_q_id 
    &usedType [JTYPE_int8u], // ref 
    &usedType [JTYPE_int8u], // ctx_max 
    &usedType [JTYPE_int8u], // con_type 
    &usedType [JTYPE_int8u], // mode 
    &usedType [JTYPE_int8u_Ptr], // user_to_user 
    &usedType [JTYPE_boolean], // data_service 
    NULL
};
static int str_CC_S_BIND_REQ_slotArrays[] = {
    1, // app_q_id
    1, // ref
    1, // ctx_max
    1, // con_type
    1, // mode
    1, // user_to_user
    1, // data_service
    0
};
static int str_CC_S_BIND_REQ_slotOffsets[7];
static JWRAP_structs str_CC_S_BIND_REQ_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_str_CC_S_BIND_REQ],
  7,
  str_CC_S_BIND_REQ_slotNames,
  str_CC_S_BIND_REQ_slotTypes,
  str_CC_S_BIND_REQ_slotOffsets,
  str_CC_S_BIND_REQ_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_str_CC_S_BIND_REQ (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &str_CC_S_BIND_REQ_struct, srcObj, destObj));
}
LOCAL int Put_str_CC_S_BIND_REQ (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &str_CC_S_BIND_REQ_struct, srcObj, destObj));
}
LOCAL char* Get_str_CC_S_BIND_REQ (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&str_CC_S_BIND_REQ_struct, tclObj);
}
// Build str_CC_S_BIND_REQ structure as a Tcl type
static Tcl_ObjType str_CC_S_BIND_REQ_type = {
  "str_CC_S_BIND_REQ",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_str_CC_S_BIND_REQ,
  (Tcl_SetFromAnyProc*)      Put_str_CC_S_BIND_REQ
  };
// Build str_CC_S_BIND_REQ structure as a Tcl type
static Tcl_ObjType str_CC_S_BIND_REQ_ptr = {
  "str_CC_S_BIND_REQ_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_str_CC_S_BIND_REQ,
  (Tcl_SetFromAnyProc*)      Create_str_CC_S_BIND_REQ
  };
// As enum as no name we  produce a dummy  structure for size computing
struct Struct_DemoStruct_0 {
  int A;
  int B;
  int C;
};

// Alloc Struct_DemoStruct_0 slot structure for Put/Get functions
static char *Struct_DemoStruct_0_slotNames[] =  {
    "A",
    "B",
    "C",
    NULL
};
static JWRAP_types *Struct_DemoStruct_0_slotTypes[] = {
    &usedType [JTYPE_int], // A 
    &usedType [JTYPE_int], // B 
    &usedType [JTYPE_int], // C 
    NULL
};
static int Struct_DemoStruct_0_slotArrays[] = {
    1, // A
    1, // B
    1, // C
    0
};
static int Struct_DemoStruct_0_slotOffsets[3];
static JWRAP_structs Struct_DemoStruct_0_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_Struct_DemoStruct_0],
  3,
  Struct_DemoStruct_0_slotNames,
  Struct_DemoStruct_0_slotTypes,
  Struct_DemoStruct_0_slotOffsets,
  Struct_DemoStruct_0_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_Struct_DemoStruct_0 (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &Struct_DemoStruct_0_struct, srcObj, destObj));
}
LOCAL int Put_Struct_DemoStruct_0 (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &Struct_DemoStruct_0_struct, srcObj, destObj));
}
LOCAL char* Get_Struct_DemoStruct_0 (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&Struct_DemoStruct_0_struct, tclObj);
}
// Build Struct_DemoStruct_0 structure as a Tcl type
static Tcl_ObjType Struct_DemoStruct_0_type = {
  "Struct_DemoStruct_0",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Struct_DemoStruct_0,
  (Tcl_SetFromAnyProc*)      Put_Struct_DemoStruct_0
  };
// Build Struct_DemoStruct_0 structure as a Tcl type
static Tcl_ObjType Struct_DemoStruct_0_ptr = {
  "Struct_DemoStruct_0_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_Struct_DemoStruct_0,
  (Tcl_SetFromAnyProc*)      Create_Struct_DemoStruct_0
  };

// Alloc wprId slot structure for Put/Get functions
static char *wprId_slotNames[] =  {
    "targetName",
    "toolName",
    "within",
    "option",
    "jointure",
    "vIoNum",
    "fichier",
    "array",
    NULL
};
static JWRAP_types *wprId_slotTypes[] = {
    &usedType [JTYPE_char_Ptr], // targetName 
    &usedType [JTYPE_char_Ptr], // toolName 
    &usedType [JTYPE_Struct_DemoStruct_0], // within 
    &usedType [JTYPE_choix], // option 
    &usedType [JTYPE_Union_DemoStruct_0], // jointure 
    &usedType [JTYPE_UINT32], // vIoNum 
    &usedType [JTYPE_FILE_Ptr], // fichier 
    &usedType [JTYPE_UINT32], // array 
    NULL
};
static int wprId_slotArrays[] = {
    1, // targetName
    1, // toolName
    1, // within
    1, // option
    1, // jointure
    1, // vIoNum
    1, // fichier
    10, // array
    0
};
static int wprId_slotOffsets[8];
static JWRAP_structs wprId_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_wprId],
  8,
  wprId_slotNames,
  wprId_slotTypes,
  wprId_slotOffsets,
  wprId_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_wprId (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &wprId_struct, srcObj, destObj));
}
LOCAL int Put_wprId (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &wprId_struct, srcObj, destObj));
}
LOCAL char* Get_wprId (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&wprId_struct, tclObj);
}
// Build wprId structure as a Tcl type
static Tcl_ObjType wprId_type = {
  "wprId",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wprId,
  (Tcl_SetFromAnyProc*)      Put_wprId
  };
// Build wprId structure as a Tcl type
static Tcl_ObjType wprId_ptr = {
  "wprId_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_wprId,
  (Tcl_SetFromAnyProc*)      Create_wprId
  };

// Alloc linkedList slot structure for Put/Get functions
static char *linkedList_slotNames[] =  {
    "name",
    "ind",
    "next",
    NULL
};
static JWRAP_types *linkedList_slotTypes[] = {
    &usedType [JTYPE_char_Ptr], // name 
    &usedType [JTYPE_int], // ind 
    &usedType [JTYPE_void_Ptr], // next 
    NULL
};
static int linkedList_slotArrays[] = {
    1, // name
    1, // ind
    1, // next
    0
};
static int linkedList_slotOffsets[3];
static JWRAP_structs linkedList_struct = {
  JWRAP_STRUCT,
  &usedType [JTYPE_linkedList],
  3,
  linkedList_slotNames,
  linkedList_slotTypes,
  linkedList_slotOffsets,
  linkedList_slotArrays,
  (Function*)JWRAP_CREATE_FUNC,
  (Function*)JWRAP_FREE_FUNC,
  (Function*)JWRAP_CGET_FUNC
};
LOCAL int Create_linkedList (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeTcl2Cc (interp, &linkedList_struct, srcObj, destObj));
}
LOCAL int Put_linkedList (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {
  return (jWrapTypeUpdate (interp, &linkedList_struct, srcObj, destObj));
}
LOCAL char* Get_linkedList (Tcl_Obj *tclObj) {
  return jWrapTypeCc2Tcl (&linkedList_struct, tclObj);
}
// Build linkedList structure as a Tcl type
static Tcl_ObjType linkedList_type = {
  "linkedList",
  (Tcl_FreeInternalRepProc *)jWrapTypeClean,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_linkedList,
  (Tcl_SetFromAnyProc*)      Put_linkedList
  };
// Build linkedList structure as a Tcl type
static Tcl_ObjType linkedList_ptr = {
  "linkedList_Ptr",
  (Tcl_FreeInternalRepProc *)jWrapTypeFree,
  (Tcl_DupInternalRepProc *) NULL,
  (Tcl_UpdateStringProc*)    Get_linkedList,
  (Tcl_SetFromAnyProc*)      Create_linkedList
  };

 // Hold structure & unions reference for jWrap struct help cmd
 static JWRAP_structs *structures[]={
  &str_sadr_struct,
  &str_CC_S_BIND_REQ_struct,
  &Struct_DemoStruct_0_struct,
  &wprId_struct,
  &linkedList_struct,
  &Union_DemoStruct_0_union,
  NULL
 };

/* *** Functions Section *** */

 // Interface jTcl to C++ for public fopen C/C++ function/method
 static int jTcl_fopen_0 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   FILE*   appli;
   void *ptr;
 } shared; }result;
 char * param_0;
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
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_char_Ptr].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_char_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_char_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_char_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_char_Ptr].obj->name);
 }
  param_0 = *(char **)&currentObj->internalRep;

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
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_char_Ptr].obj->setFromAnyProc)){
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
 result.shared.appli =  fopen (param_0, param_1);

 resultPtr = Tcl_GetObjResult (interp);
 // Reset TclObj and memcpy value without any check as internal value
 resultPtr->internalRep.twoPtrValue.ptr1 = 0;
 resultPtr->internalRep.twoPtrValue.ptr2 = 0;
 *(FILE**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_FILE_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[0]);
  return TCL_ERROR;
 } // end method jWrap_fopen0

 // Interface jTcl to C++ for public fclose C/C++ function/method
 static int jTcl_fclose_1 (
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
 FILE * param_0;

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
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_FILE_Ptr].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_FILE_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_FILE_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_FILE_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_FILE_Ptr].obj->name);
 }
  param_0 = *(FILE **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  fclose (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // Reset TclObj and memcpy value without any check as internal value
 resultPtr->internalRep.twoPtrValue.ptr1 = 0;
 resultPtr->internalRep.twoPtrValue.ptr2 = 0;
 *(int*)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_int].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[1]);
  return TCL_ERROR;
 } // end method jWrap_fclose1

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
 const void * param_1;
 size_t param_2;

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
  param_1 = *(const void **)&currentObj->internalRep;

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
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_size_t].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_size_t].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_size_t].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_size_t].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,2,currentObj->typePtr->name,usedType[JTYPE_size_t].obj->name);
 }
  param_2 = *(size_t*)&currentObj->internalRep;

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

 // Interface jTcl to C++ for public testIt C/C++ function/method
 static int jTcl_testIt_3 (
     ClientData cld, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
 {
 Tcl_Obj     tmpCgetObj;
 Tcl_Obj     *currentObj;
 int status;
 Tcl_Obj *resultPtr;
 struct { union {
   WPR_ID*   appli;
   void *ptr;
 } shared; }result;
 WPR_ID * param_0;

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
 if (!currentObj->typePtr || (currentObj->typePtr->setFromAnyProc!= usedType[JTYPE_WPR_ID_Ptr].obj->setFromAnyProc)){
   status = ((Function*)usedType[JTYPE_WPR_ID_Ptr].obj->setFromAnyProc)
            (interp, currentObj,NULL);
   if (status != TCL_OK) return status;
   currentObj->typePtr = usedType[JTYPE_WPR_ID_Ptr].obj;
 } else if (currentObj->typePtr->updateStringProc
  != usedType[JTYPE_WPR_ID_Ptr].obj->updateStringProc) {
  jWrapPanic (interp,errTypeFmt  ,0,currentObj->typePtr->name,usedType[JTYPE_WPR_ID_Ptr].obj->name);
 }
  param_0 = *(WPR_ID **)&currentObj->internalRep;

 // effectively call C++ function/method
 result.shared.appli =  testIt (param_0);

 resultPtr = Tcl_GetObjResult (interp);
 // Reset TclObj and memcpy value without any check as internal value
 resultPtr->internalRep.twoPtrValue.ptr1 = 0;
 resultPtr->internalRep.twoPtrValue.ptr2 = 0;
 *(WPR_ID**)&resultPtr->internalRep = result.shared.appli;
 resultPtr->bytes = NULL;
 resultPtr->typePtr = usedType[JTYPE_WPR_ID_Ptr].obj;
 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[3]);
  return TCL_ERROR;
 } // end method jWrap_testIt3

 // Interface jTcl to C++ for public testLst C/C++ function/method
 static int jTcl_testLst_4 (
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
 testLst ();

 return TCL_OK;

 errorNumArg:
  Tcl_WrongNumArgs (interp,1,objv, helpCmd[4]);
  return TCL_ERROR;
 } // end method jWrap_testLst4


/* ***  Tcl Register Section *** */
#ifdef __cplusplus
extern "C" {
#endif
RESTRICTED int Demostruct_Init (Tcl_Interp *interp) {
 // Dont init twice
 if (initDone) return TCL_OK;
 initDone = 1;

 /* --- Build module handle & register it in jWrap --- */

 module.magic       =JWRAP_MODULE;
 module.name        ="DemoStruct";
 module.help        ="Demonstrate Complex Structure handling";
 module.helpCmd     = helpCmd;
 module.nbCmd       = 5;
 module.hashTable   = NULL;
 module.version     = DemoStruct_CUSTOM_STAMP;
 module.structures  = structures;
 module.enumerations= enumerations;
 module.info        = NULL;

 // prepare emergency panic return
 if (setjmp (jWrapCheckPoint)) {
   return TCL_ERROR;
 }

 // init routines user or default
#ifdef DemoStruct_CUSTOM_INIT
 DemoStruct_CUSTOM_INIT;
#else
 if (Jwrap_Init (interp) != TCL_OK) return TCL_ERROR;
#endif
 jWrapModuleRegister (interp,&module);
 jWrapEnumRegister (&module,&Define_DemoStruct_enum,&Define_DemoStruct_type);

 /* --- Enumeration Section --- */

 jWrapEnumRegister (&module, &Enum_DemoStruct_0_enum,&Enum_DemoStruct_0_type);
 jWrapEnumRegister (&module, &choix_enum,&choix_type);
 
 /* *** Type Structs/Unions Section *** */
 {  // Compute str_sadr structure offset
  struct str_sadr dummy4offset;
  str_sadr_slotOffsets [0] = (char*)&dummy4offset.type - (char*)&dummy4offset;
  str_sadr_slotOffsets [1] = (char*)&dummy4offset.digits - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&str_sadr_struct,&str_sadr_type,&str_sadr_ptr );
 };
 {  // Compute str_CC_S_BIND_REQ structure offset
  struct str_CC_S_BIND_REQ dummy4offset;
  str_CC_S_BIND_REQ_slotOffsets [0] = (char*)&dummy4offset.app_q_id - (char*)&dummy4offset;
  str_CC_S_BIND_REQ_slotOffsets [1] = (char*)&dummy4offset.ref - (char*)&dummy4offset;
  str_CC_S_BIND_REQ_slotOffsets [2] = (char*)&dummy4offset.ctx_max - (char*)&dummy4offset;
  str_CC_S_BIND_REQ_slotOffsets [3] = (char*)&dummy4offset.con_type - (char*)&dummy4offset;
  str_CC_S_BIND_REQ_slotOffsets [4] = (char*)&dummy4offset.mode - (char*)&dummy4offset;
  str_CC_S_BIND_REQ_slotOffsets [5] = (char*)&dummy4offset.user_to_user - (char*)&dummy4offset;
  str_CC_S_BIND_REQ_slotOffsets [6] = (char*)&dummy4offset.data_service - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&str_CC_S_BIND_REQ_struct,&str_CC_S_BIND_REQ_type,&str_CC_S_BIND_REQ_ptr );
 };
 {  // Compute Struct_DemoStruct_0 structure offset
  struct Struct_DemoStruct_0 dummy4offset;
  Struct_DemoStruct_0_slotOffsets [0] = (char*)&dummy4offset.A - (char*)&dummy4offset;
  Struct_DemoStruct_0_slotOffsets [1] = (char*)&dummy4offset.B - (char*)&dummy4offset;
  Struct_DemoStruct_0_slotOffsets [2] = (char*)&dummy4offset.C - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&Struct_DemoStruct_0_struct,&Struct_DemoStruct_0_type,&Struct_DemoStruct_0_ptr );
 };
 {  // Compute wprId structure offset
  struct wprId dummy4offset;
  wprId_slotOffsets [0] = (char*)&dummy4offset.targetName - (char*)&dummy4offset;
  wprId_slotOffsets [1] = (char*)&dummy4offset.toolName - (char*)&dummy4offset;
  wprId_slotOffsets [2] = (char*)&dummy4offset.within - (char*)&dummy4offset;
  wprId_slotOffsets [3] = (char*)&dummy4offset.option - (char*)&dummy4offset;
  wprId_slotOffsets [4] = (char*)&dummy4offset.jointure - (char*)&dummy4offset;
  wprId_slotOffsets [5] = (char*)&dummy4offset.vIoNum - (char*)&dummy4offset;
  wprId_slotOffsets [6] = (char*)&dummy4offset.fichier - (char*)&dummy4offset;
  wprId_slotOffsets [7] = (char*)&dummy4offset.array - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&wprId_struct,&wprId_type,&wprId_ptr );
 };
 {  // Compute linkedList structure offset
  struct linkedList dummy4offset;
  linkedList_slotOffsets [0] = (char*)&dummy4offset.name - (char*)&dummy4offset;
  linkedList_slotOffsets [1] = (char*)&dummy4offset.ind - (char*)&dummy4offset;
  linkedList_slotOffsets [2] = (char*)&dummy4offset.next - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&linkedList_struct,&linkedList_type,&linkedList_ptr );
 };

 {  // Compute Union_DemoStruct_0 Unions offset
  union Union_DemoStruct_0 dummy4offset;
  Union_DemoStruct_0_slotOffsets [0] = (char*)&dummy4offset.A - (char*)&dummy4offset;
  Union_DemoStruct_0_slotOffsets [1] = (char*)&dummy4offset.B - (char*)&dummy4offset;
  Union_DemoStruct_0_slotOffsets [2] = (char*)&dummy4offset.C - (char*)&dummy4offset;
  Union_DemoStruct_0_slotOffsets [3] = (char*)&dummy4offset.D - (char*)&dummy4offset;
  jWrapTypeRegister (&module,&Union_DemoStruct_0_union,&Union_DemoStruct_0_type,&Union_DemoStruct_0_ptr );
 };
 
 /* *** Type Alias Section *** */
 jWrapTypeAlias (&module,"long" ,"UINT32");
 jWrapTypeAlias (&module,"short" ,"int16u");
 jWrapTypeAlias (&module,"char" ,"int8u");
 jWrapTypeAlias (&module,"char" ,"boolean");
 jWrapTypeAlias (&module,"Enum_DemoStruct_0" ,"t_sadr_type");
 jWrapTypeAlias (&module,"str_sadr" ,"t_sadr");
 jWrapTypeAlias (&module,"str_CC_S_BIND_REQ" ,"CC_S_BIND_REQ");
 jWrapTypeAlias (&module,"wprId" ,"WPR_ID");
 jWrapTypeAlias (&module,"linkedList" ,"LINKED_LST");

 /* --- Used Type Section --- */

 jWrapTypeCheck (&usedType [0],"Define_DemoStruct",sizeof(Define_DemoStruct));
 jWrapTypeCheck (&usedType [1],"LINKED_LST_Ptr",sizeof(LINKED_LST *));
 jWrapTypeCheck (&usedType [2],"str_sadr",sizeof(struct str_sadr));
 jWrapTypeCheck (&usedType [3],"t_sadr_type",sizeof(t_sadr_type));
 jWrapTypeCheck (&usedType [4],"char_Ptr",sizeof(char*));
 jWrapTypeCheck (&usedType [5],"str_CC_S_BIND_REQ",sizeof(struct str_CC_S_BIND_REQ));
 jWrapTypeCheck (&usedType [6],"int16u",sizeof(int16u));
 jWrapTypeCheck (&usedType [7],"int8u",sizeof(int8u));
 jWrapTypeCheck (&usedType [8],"int8u_Ptr",sizeof(int8u*));
 jWrapTypeCheck (&usedType [9],"boolean",sizeof(boolean));
 jWrapTypeCheck (&usedType [10],"Struct_DemoStruct_0",sizeof(struct Struct_DemoStruct_0));
 jWrapTypeCheck (&usedType [11],"int",sizeof(int));
 jWrapTypeCheck (&usedType [12],"wprId",sizeof(struct wprId));
 jWrapTypeCheck (&usedType [13],"choix",sizeof(enum choix));
 jWrapTypeCheck (&usedType [14],"Union_DemoStruct_0",sizeof(union Union_DemoStruct_0));
 jWrapTypeCheck (&usedType [15],"UINT32",sizeof(UINT32));
 jWrapTypeCheck (&usedType [16],"FILE_Ptr",sizeof(FILE*));
 jWrapTypeCheck (&usedType [17],"linkedList",sizeof(struct linkedList));
 jWrapTypeCheck (&usedType [18],"void_Ptr",sizeof(void*));
 jWrapTypeCheck (&usedType [19],"short",sizeof(short));
 jWrapTypeCheck (&usedType [20],"char",sizeof(char));
 jWrapTypeCheck (&usedType [21],"double",sizeof(double));
 jWrapTypeCheck (&usedType [22],"Enum_DemoStruct_0",sizeof(enum Enum_DemoStruct_0));
 jWrapTypeCheck (&usedType [23],"size_t",sizeof(size_t));
 jWrapTypeCheck (&usedType [24],"WPR_ID_Ptr",sizeof(WPR_ID*));

 /* --- Static Variable registration --- */

 jWrapVarRegister (interp, NULL, "DemoStruct.listHead", (long*)&listHead, 19 
                  , &usedType[JTYPE_LINKED_LST_Ptr]);

 /* --- Functions sub-section --- */

 // register fopen C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoStruct.fopen", jTcl_fopen_0  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register fclose C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoStruct.fclose", jTcl_fclose_1  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register memcpy C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoStruct.memcpy", jTcl_memcpy_2  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register testIt C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoStruct.testIt", jTcl_testIt_3  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);

 // register testLst C/C++ entry point as  Tcl command
 Tcl_CreateObjCommand (interp,"DemoStruct.testLst", jTcl_testLst_4  , (ClientData)NULL, (Tcl_CmdDeleteProc*) NULL);
 return TCL_OK;
} // end function DemoStruct_Init
#ifdef __cplusplus
}
#endif

// ------------------ end funcDemoStruct_jWrap.c ----------------------
