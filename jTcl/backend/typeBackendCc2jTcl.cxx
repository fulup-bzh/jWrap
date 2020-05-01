/*
 *
 *  Copyright(c) 1997-98 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   typeBackendCc2jTcl.cc manage type in C++ 2 jTcl backend wrapper
 * Projet    :   Rubicon/jWrap
 * Module    :   jWrap C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/backend/typeBackendCc2jTcl.cxx,v $
 *
 * Modification History
 * --------------------
 * 01c,16oct98,Fulup,add pointer on union in knowed type
 * 01b,18apr98,Fulup,extracted from global class file for new tree
 * 01a,06feb98,Fulup,written
 */

#include <stdio.h>

#include "libBackendCc2jTcl.h"

/**--------------------------------------------------------------------------
 ** Create a new typename with a magic, this small object is used
 ** later to prefix structure and union in order advoing typedef structure
 ** which an equivament typename, as it is done by default in C++
 ** -------------------------------------------------------------------------*/
registeredType::registeredType (McString* nom, STRUCTURE typeStruct) {
  name  = nom;
  magic = typeStruct;
}

/**--------------------------------------------------------------------------
 ** Remove * from type name and replace then with Ptr in oder to produce
 ** a valid enumeration constant. WARNING: This functin is not reentrant and
 ** cannot be called twice in a same fprintf !!!
 **--------------------------------------------------------------------------*/
char* BackendCc2jTcl::jWrapType (McString * oldType) {
 static char   newTypeName[255];
 char   *oldTypeName;
 int    ind,jnd;

 // get old type char pointer
 oldTypeName = *oldType;

 // va list is a very special type
 if (!strcmp (oldTypeName, "...")) return ("va_list_Ptr");

 // if string is enum or struct or const prefixed we remove it
 if (!strncmp (oldTypeName, "enum "    ,5)) oldTypeName = &oldTypeName[5];
 if (!strncmp (oldTypeName, "union "   ,6)) oldTypeName = &oldTypeName[6];
 if (!strncmp (oldTypeName, "struct "  ,7)) oldTypeName = &oldTypeName[7];
 if (!strncmp (oldTypeName, "unsigned ",9)) oldTypeName = &oldTypeName[9];

 // keep const [replace space with an _]
 if (!strncmp (oldTypeName, "const "   ,6)) {
    oldTypeName = &oldTypeName[6];
    strcpy (newTypeName, "const_");
    jnd=6;
 } else {
    jnd=0;
 }

 // remove * from type name
 for (ind=0; oldTypeName [ind] != '\0'; ind++) {
   if (oldTypeName [ind] == '*') {
     // replace with Ptr string
     strcpy (&newTypeName[jnd], "_Ptr");
     jnd = jnd + 4;
   } else {
     // remove space
     if (oldTypeName [ind] != ' ') {
         // if not an * just copy character in lower case
        newTypeName [jnd] = oldTypeName [ind];
        jnd ++;
     }
   }
 }
 newTypeName [jnd]='\0';
 return newTypeName;
} // end jWrapType


/**--------------------------------------------------------------------------
 ** Register each type used in application in order checking is we are
 ** facing ordinary or specific type, all non managed type are considered
 ** as cookies by jWrap.
 **--------------------------------------------------------------------------*/
void BackendCc2jTcl::registerType (McString * typeName,int array, STRUCTURE magic) {

  int  ind;
  char checkedType[255];

  // If type is a null array we add a pointer reference
  if (array == 0) {*typeName += "*";}

  // check this type is real new one
  strcpy (checkedType, jWrapType (typeName));

  // if void ignore
  if ((checkedType[0] == '\0') || (!(strcmp (checkedType,"void")))) return;

  for (ind=0; ind <cTypes.size(); ind++) {
     if (!strcmp (checkedType, jWrapType(cTypes[ind]->name))) {
      // Slot can have been registrated as a standard type but in in fact a struct
      if ((cTypes[ind]->magic == TYPE_NATIVE) && (magic != TYPE_NATIVE)) {
        cTypes[ind]->magic = magic;
      }
      return;
     }
  }

  // add it to list of ordinary used ctypes
  cTypes.append (new registeredType (typeName,magic));

} // end registerType

/**--------------------------------------------------------------------------
 ** Output Structures Won't Compile before order is not garanty
 **--------------------------------------------------------------------------*/
void BackendCc2jTcl::output (Structs *structure) {
  int ind;

  // If structure is a jWrap generated structure we generate code
  if (!strncmp (structure->name, "Struct_", 7)) {
    fprintf (outFile,"// As enum as no name we  produce a dummy  structure for size computing\n");
    fprintf (outFile,"struct %s {\n", (char*) structure->name);
    for (ind=0; ind < structure->elements.size(); ind ++) {
      fprintf (outFile,"  %s %s;\n"
              ,(char*)structure->elements[ind]->type
              ,(char*)structure->elements[ind]->name
      );
    }
    fprintf (outFile,"};\n");
  }

  fprintf (outFile,"\n// Alloc %s slot structure for Put/Get functions\n",(char*)structure->name);
  fprintf (outFile,"static char *%s_slotNames[] =  {\n",(char*)structure->name);
  for (ind = 0; ind < structure->elements.size(); ind ++) {
    fprintf (outFile,"    \"%s\",\n",(char*)structure->elements[ind]->name);
  }
  fprintf (outFile,"    NULL\n};\n");

  fprintf (outFile,"static JWRAP_types *%s_slotTypes[] = {\n",(char*)structure->name);
  for (ind = 0; ind < structure->elements.size(); ind ++) {
    fprintf (outFile,"    &usedType [JTYPE_%s], // %s \n"
       , jWrapType(&structure->elements[ind]->type),(char*)structure->elements[ind]->name);
  }
  fprintf (outFile,"    NULL\n};\n");

  fprintf (outFile,"static int %s_slotArrays[] = {\n",(char*)structure->name);
  for (ind = 0; ind < structure->elements.size(); ind ++) {
    fprintf (outFile,"    %d, // %s\n"
       , abs (structure->elements[ind]->array),(char*)structure->elements[ind]->name);
  }
  fprintf (outFile,"    0\n};\n");

  fprintf (outFile,"static int %s_slotOffsets[%d];\n"
                  ,(char*)structure->name,structure->elements.size());

  fprintf (outFile,"static JWRAP_structs %s_struct = {\n",(char*)structure->name);
  fprintf (outFile,"  JWRAP_STRUCT,\n");
  fprintf (outFile,"  &usedType [JTYPE_%s],\n",(char*)structure->name);
  fprintf (outFile,"  %d,\n",structure->elements.size());
  fprintf (outFile,"  %s_slotNames,\n",(char*)structure->name);
  fprintf (outFile,"  %s_slotTypes,\n",(char*)structure->name);
  fprintf (outFile,"  %s_slotOffsets,\n",(char*)structure->name);
  fprintf (outFile,"  %s_slotArrays,\n",(char*)structure->name);
  fprintf (outFile,"  (Function*)JWRAP_CREATE_FUNC,\n");
  fprintf (outFile,"  (Function*)JWRAP_FREE_FUNC,\n");
  fprintf (outFile,"  (Function*)JWRAP_CGET_FUNC\n");
  fprintf (outFile,"};\n");

  fprintf (outFile,"LOCAL int Create_%s (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {\n"
                  , (char*)structure->name);
  fprintf (outFile,"  return (jWrapTypeTcl2Cc (interp, &%s_struct, srcObj, destObj));\n"
                  ,(char*)structure->name);
  fprintf (outFile,"}\n");

  fprintf (outFile,"LOCAL int Put_%s (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {\n"
                  , (char*)structure->name);
  fprintf (outFile,"  return (jWrapTypeUpdate (interp, &%s_struct, srcObj, destObj));\n"
                  ,(char*)structure->name);
  fprintf (outFile,"}\n");

  fprintf (outFile,"LOCAL char* Get_%s (Tcl_Obj *tclObj) {\n", (char*)structure->name);
  fprintf (outFile,"  return jWrapTypeCc2Tcl (&%s_struct, tclObj);\n",(char*)structure->name);
  fprintf (outFile,"}\n");

  fprintf (outFile,"// Build %s structure as a Tcl type\n",(char*)structure->name);
  fprintf (outFile,"static Tcl_ObjType %s_type = {\n",(char*)structure->name);
  fprintf (outFile,"  \"%s\",\n", jWrapType (&structure->name));
  fprintf (outFile,"  (Tcl_FreeInternalRepProc *)jWrapTypeClean,\n");
  fprintf (outFile,"  (Tcl_DupInternalRepProc *) NULL,\n");
  fprintf (outFile,"  (Tcl_UpdateStringProc*)    Get_%s,\n",(char*)structure->name);
  fprintf (outFile,"  (Tcl_SetFromAnyProc*)      Put_%s\n",(char*)structure->name);
  fprintf (outFile,"  };\n");

  fprintf (outFile,"// Build %s structure as a Tcl type\n",(char*)structure->name);
  fprintf (outFile,"static Tcl_ObjType %s_ptr = {\n",(char*)structure->name);
  fprintf (outFile,"  \"%s_Ptr\",\n",jWrapType (&structure->name));
  fprintf (outFile,"  (Tcl_FreeInternalRepProc *)jWrapTypeFree,\n");
  fprintf (outFile,"  (Tcl_DupInternalRepProc *) NULL,\n");
  fprintf (outFile,"  (Tcl_UpdateStringProc*)    Get_%s,\n",(char*)structure->name);
  fprintf (outFile,"  (Tcl_SetFromAnyProc*)      Create_%s\n",(char*)structure->name);
  fprintf (outFile,"  };\n");

} // end outputStruct

/**--------------------------------------------------------------------------
 ** Union is almost a Structure with a null offset
 **--------------------------------------------------------------------------*/
void BackendCc2jTcl::output (Unions *jointure) {
  int ind;

  // If jointure is a jWrap generated jointure we generate code
  if (!strncmp (jointure->name, "Union_", 6)) {
    fprintf (outFile,"// We need to produce internal union in order computing size\n");
    fprintf (outFile,"union %s {\n", (char*) jointure->name);
    for (ind=0; ind < jointure->elements.size(); ind ++) {
      fprintf (outFile,"  %s %s;\n"
              ,(char*)jointure->elements[ind]->type
              ,(char*)jointure->elements[ind]->name
      );
    }
    fprintf (outFile,"};\n");
    fprintf (outFile,"typedef union %s %s;\n",(char*) jointure->name,(char*) jointure->name);
  }

  fprintf (outFile,"\n// Alloc %s slot jointure for Put/Get functions\n",(char*)jointure->name);
  fprintf (outFile,"static char *%s_slotNames[] =  {\n",(char*)jointure->name);
  for (ind = 0; ind < jointure->elements.size(); ind ++) {
    fprintf (outFile,"    \"%s\",\n",(char*)jointure->elements[ind]->name);
  }
  fprintf (outFile,"    NULL\n};\n");

  fprintf (outFile,"static JWRAP_types *%s_slotTypes[] = {\n",(char*)jointure->name);
  for (ind = 0; ind < jointure->elements.size(); ind ++) {
    fprintf (outFile,"    &usedType [JTYPE_%s], // %s\n"
       , jWrapType(&jointure->elements[ind]->type),(char*)jointure->elements[ind]->name);
  }
  fprintf (outFile,"    NULL\n};\n");

  fprintf (outFile,"static int %s_slotOffsets[%d];\n"
                  ,(char*)jointure->name,jointure->elements.size());

  fprintf (outFile,"static int %s_slotArrays[] = {\n",(char*)jointure->name);
  for (ind = 0; ind < jointure->elements.size(); ind ++) {
    fprintf (outFile,"    %d, // %s\n"
       , abs (jointure->elements[ind]->array),(char*)jointure->elements[ind]->name);
  }
  fprintf (outFile,"    0\n};\n");

  fprintf (outFile,"static JWRAP_structs %s_union = {\n",(char*)jointure->name);
  fprintf (outFile,"  JWRAP_UNION,\n");
  fprintf (outFile,"  &usedType [JTYPE_%s],\n"
                  ,(char*)jointure->name);
  fprintf (outFile,"  %d,\n",jointure->elements.size());
  fprintf (outFile,"  %s_slotNames,\n",(char*)jointure->name);
  fprintf (outFile,"  %s_slotTypes,\n",(char*)jointure->name);
  fprintf (outFile,"  %s_slotOffsets,\n",(char*)jointure->name);
  fprintf (outFile,"  %s_slotArrays,\n",(char*)jointure->name);
  fprintf (outFile,"  (Function*)JWRAP_CREATE_FUNC,\n");
  fprintf (outFile,"  (Function*)JWRAP_FREE_FUNC,\n");
  fprintf (outFile,"  (Function*)JWRAP_CGET_FUNC\n");
  fprintf (outFile,"};\n");

  fprintf (outFile,"LOCAL int Create_%s (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj * destObj) {\n"
                  , (char*)jointure->name);
  fprintf (outFile,"  return (jWrapTypeTcl2Cc (interp, &%s_union, srcObj, destObj));\n"
                  ,(char*)jointure->name);
  fprintf (outFile,"}\n");

  fprintf (outFile,"LOCAL int Put_%s (Tcl_Interp *interp, Tcl_Obj *srcObj, Tcl_Obj *destObj) {\n"
                  , (char*)jointure->name);
  fprintf (outFile,"  return (jWrapTypeUpdate (interp, &%s_union, srcObj, destObj));\n"
                  ,(char*)jointure->name);
  fprintf (outFile,"}\n");

  fprintf (outFile,"LOCAL char* Get_%s (Tcl_Obj *tclObj) {\n", (char*)jointure->name);
  fprintf (outFile,"  return jWrapTypeCc2Tcl (&%s_union, tclObj);\n",(char*)jointure->name);
  fprintf (outFile,"}\n");

  fprintf (outFile,"// Build %s jointure as a Tcl type\n",(char*)jointure->name);
  fprintf (outFile,"static Tcl_ObjType %s_type = {\n",(char*)jointure->name);
  fprintf (outFile,"  \"%s\",\n", jWrapType (&jointure->name));
  fprintf (outFile,"  (Tcl_FreeInternalRepProc *)jWrapTypeClean,\n");
  fprintf (outFile,"  (Tcl_DupInternalRepProc *) NULL,\n");
  fprintf (outFile,"  (Tcl_UpdateStringProc*)    Get_%s,\n",(char*)jointure->name);
  fprintf (outFile,"  (Tcl_SetFromAnyProc*)      Put_%s\n",(char*)jointure->name);
  fprintf (outFile,"  };\n");

  fprintf (outFile,"// Build %s jointure as a Tcl type\n",(char*)jointure->name);
  fprintf (outFile,"static Tcl_ObjType %s_ptr = {\n",(char*)jointure->name);
  fprintf (outFile,"  \"%s_Ptr\",\n", jWrapType (&jointure->name));
  fprintf (outFile,"  (Tcl_FreeInternalRepProc *)jWrapTypeFree,\n");
  fprintf (outFile,"  (Tcl_DupInternalRepProc *) NULL,\n");
  fprintf (outFile,"  (Tcl_UpdateStringProc*)    Get_%s,\n",(char*)jointure->name);
  fprintf (outFile,"  (Tcl_SetFromAnyProc*)      Create_%s\n",(char*)jointure->name);
  fprintf (outFile,"  };\n");
} // end output Unions

/**--------------------------------------------------------------------------
 ** Structure as to registrated in module hashtable at runtime
 **--------------------------------------------------------------------------*/
void BackendCc2jTcl::registrate (Structs *structure) {
 int ind;

  fprintf (outFile," {  // Compute %s structure offset\n",(char*) structure->name);
  fprintf (outFile,"  struct %s dummy4offset;\n",(char*)structure->name);
  for (ind=0; ind <structure->elements.size(); ind++) {
   fprintf (outFile,"  %s_slotOffsets [%d] = (char*)&dummy4offset.%s - (char*)&dummy4offset;\n"
     ,(char*)structure->name, ind, (char*)structure->elements[ind]->name);
  }
  fprintf (outFile,"  jWrapTypeRegister (&module,&%s_struct,&%s_type,&%s_ptr );\n"
    , (char*) structure->name,(char*) structure->name,(char*) structure->name);
  fprintf (outFile," };\n");
}

/**--------------------------------------------------------------------------
 ** Structure as to registrated in module hashtable at runtime
 **--------------------------------------------------------------------------*/
void BackendCc2jTcl::registrate (Unions *jointure) {

 int ind;

  fprintf (outFile,"\n {  // Compute %s Unions offset\n",(char*) jointure->name);
  fprintf (outFile,"  union %s dummy4offset;\n",(char*)jointure->name);
  for (ind=0; ind <jointure->elements.size(); ind++) {
   fprintf (outFile,"  %s_slotOffsets [%d] = (char*)&dummy4offset.%s - (char*)&dummy4offset;\n"
     ,(char*)jointure->name, ind, (char*)jointure->elements[ind]->name);
  }
  fprintf (outFile,"  jWrapTypeRegister (&module,&%s_union,&%s_type,&%s_ptr );\n"
    , (char*) jointure->name,(char*) jointure->name, (char*) jointure->name);
  fprintf (outFile," };\n");

}

/**--------------------------------------------------------------------------
 ** Output typedef mapping, note that we use two printf because typeMap is
 ** returning a unique static value.
 **--------------------------------------------------------------------------*/
void BackendCc2jTcl::registrate (Typedefs *alias) {

    fprintf (outFile
    ," jWrapTypeAlias (&module,\"%s\"", jWrapType (&alias->source));

    fprintf (outFile
    ," ,\"%s\");\n", jWrapType (&alias->name));

} // end register Typedefs alias
