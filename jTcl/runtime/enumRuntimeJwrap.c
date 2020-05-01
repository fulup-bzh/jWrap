/*
 *  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   enumCcWrap.cc wrap C/C++ enum as cookies like
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/runtime/enumRuntimeJwrap.c,v $
 *
 * Modification History
 * --------------------
 * 01c,04jul98,Fulup,ispell code
 * 01b,15may98,Fulup,change to be struct compliant
 * 01a,18feb98,Fulup,written
 */

#include "libRuntimeJwrap.h"
#include <string.h>

/**----------------------------------------------------------------
 * Create an external representation from internal representation
 * We try first value at given value, this boost simple enum
 * with no forced values, if not find at this specific location
 * we scan all enum values.
 **----------------------------------------------------------------*/
PUBLIC void jWrapEnumCc2Tcl  (JWRAP_enums *enumeration, Tcl_Obj *tclObj) {
 int idxSlot;

  // Check if value is not valid slot
  if (tclObj->internalRep.longValue < enumeration->count) {
    if (enumeration->slotValues [tclObj->internalRep.longValue] == tclObj->internalRep.longValue) {
      jWrapStrDup (tclObj, enumeration->slotNames [tclObj->internalRep.longValue]);
      return; // ----------- RETURN OK -----
    }
  }

  // if not found scan all values
  for (idxSlot=0; idxSlot <enumeration->count; idxSlot ++) {
    if ((int) enumeration->slotValues [idxSlot] == (int) tclObj->internalRep.longValue) {
      jWrapStrDup (tclObj, enumeration->slotNames [idxSlot]);
      return; // ------------- RETURN OK ------
    }
  }

  // Value not found ERROR
  {
   char reponse[255];
    sprintf (reponse,"<%ld> not a valid %s value"
            , tclObj->internalRep.longValue
            , enumeration->type->obj->name);
    // error message as to be a malloc structure for Tcl to free it
    jWrapStrDup (tclObj,reponse);
  }
}

/**----------------------------------------------------------------
 * Create an internal representation from external representation
 * External rep should be a valid string.
 **----------------------------------------------------------------*/
PUBLIC int jWrapEnumTcl2Cc (Tcl_Interp *interp,JWRAP_enums *enumeration,Tcl_Obj *tclObj) {
  int idxSlot;

  // If type is already valid just return
  if (tclObj->typePtr == enumeration->type->obj) return TCL_OK;

  // Search element in enumeration array
  if (Tcl_GetIndexFromObj (NULL,tclObj,enumeration->slotNames,"option"
        ,0, &idxSlot) != TCL_OK)  goto errSlot;

  // If object has a previous internal rep free it
  if ((tclObj->typePtr != NULL) && (tclObj->typePtr->freeIntRepProc != NULL)) {
    tclObj->typePtr->freeIntRepProc (tclObj);
  }

  // Else update internal rep
  tclObj->internalRep.longValue = (long) enumeration->slotValues [idxSlot];
  tclObj->typePtr = enumeration->type->obj;

  return TCL_OK; // -------------------- OK -------------------

errSlot:
  Tcl_AppendResult (interp,"jWrapUpdateEnum [",enumeration->type->obj->name
                   ,"] Unknown Value [",TCL_STRING(tclObj),"]\n",NULL);
  return TCL_ERROR;
}

/**-----------------------------------------------------------------------
 * Duplicate a enum only copy long value internal rep
 **-----------------------------------------------------------------------*/
PUBLIC void jWrapEnumDup (JWRAP_enums *enumeration, Tcl_Obj *objSrc, Tcl_Obj *objDest)
{
  objDest->internalRep.longValue = objSrc->internalRep.longValue;
  objDest->typePtr = objSrc->typePtr;

  return;
}

/**-----------------------------------------------------------------
 * Print available slot of a given enumeration on stdout.
 * Do not return any result.
 **-----------------------------------------------------------------*/
PUBLIC void jWrapEnumInfo (JWRAP_enums *enumeration,int listAsked,char**result) {
  int  ind;
  char name [JWRAP_MAX_NAME];
  char *tuple [2];
  char **elements;

  if (!listAsked) {
    // print out enumeration type and slot name
    fprintf (stdout,"#\n# Enumeration %s  {\n", enumeration->type->obj->name);

    // for each slot print type and var name
    for (ind=0; ind < enumeration->count; ind ++) {

      fprintf (stdout, "#   %s %ld;\n"
                   , enumeration->slotNames[ind]
                   , enumeration->slotValues[ind]);
    }
    // print a conventional struc trailer
    fprintf (stdout,"# }\n");
  } else {
    // return all enumeration as a list in slot
    elements = (char**) Tcl_Alloc (sizeof (char*) * (enumeration->count+1));
    elements [0] = enumeration->type->obj->name;
    for (ind=0; ind < enumeration->count; ind ++) {
      tuple [0] = enumeration->slotNames[ind];
      sprintf (name, "%ld", enumeration->slotValues[ind]);
      tuple [1] = name;
      elements [ind+1] = Tcl_Merge (2, tuple);
    }
    // group all element in result and free tempry element lists
    *result = Tcl_Merge (ind, elements);
    for (ind=1;ind < enumeration->count+1; ind ++) {
      Tcl_Free (elements[ind]);
    }
    // free tmp RAM
    Tcl_Free ((char*)elements);
  }
}

/**-----------------------------------------------------------------
 *  Print or make a list with enumeration information
 **-----------------------------------------------------------------*/
PUBLIC void jWrapEnumHelp (JWRAP_modules *module, int listAsked, char** line) {
 int  nbEnum;
 char **slot=NULL;
 int ind;

 //Check we have enumerations
 if (module->enumerations == NULL) {
  *line = strdup ("");
  return;
 }

 if (!listAsked) {
   fprintf (stdout,"#\n## --- Enumeration For Module=%s\n", module->name);
 }
 // First we count enumeration number
 for (nbEnum=0;module->enumerations[nbEnum] != NULL; nbEnum++);
 { // open block
   slot = (char**)Tcl_Realloc ((void*)slot, sizeof (char*) * (nbEnum+1));
   slot [0] = module->name;
   for (ind=0; module->enumerations[ind] != NULL; ind ++) {
     jWrapEnumInfo (module->enumerations[ind], listAsked, &slot[ind+1]);
   }

   if (listAsked) {
     // build a list with all modules lines
     *line = Tcl_Merge (nbEnum, slot);
     // free an intermediate lines
     for (ind= 1; ind < nbEnum+1; ind ++) Tcl_Free (slot [ind]);
   }
 } // end block

 // free tempry structure
 Tcl_Free ((void*)slot);

}

/**----------------------------------------------------------------
 * register a new enum as a jWrap enum type. We register one new
 * enumeration in tcl interpretor for each new enumeration.
 **----------------------------------------------------------------*/
PUBLIC void jWrapEnumRegister (JWRAP_modules *module, JWRAP_enums* enumeration
                              ,Tcl_ObjType *tclType)
{
 char name [JWRAP_MAX_NAME];
  Tcl_HashEntry *entryPtr;
  int new;

  // Build label name from enumeration name
  sprintf (name,"OBJ_%s", tclType->name);

  // Store in hashtable
  entryPtr = Tcl_CreateHashEntry (module->hashTable, name, &new);
  if (!new) goto alreadyRegister;
  Tcl_SetHashValue (entryPtr, (ClientData) enumeration);

  // Reference Tcl Type no possible conflict all enumeration are modname prefixed
  Tcl_RegisterObjType (tclType);


  return; // --------------- OK -----------------

alreadyRegister:
  jWrapPanic (NULL, "jWrapRegisterEnum Enumeration [%s] is already register in module [%s]\n"
                  , name, module->name);


} // end jWrapRegisterEnum
