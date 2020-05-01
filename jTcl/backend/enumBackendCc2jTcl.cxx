/*
 *
 *  Copyright(c) 1997-98 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   enumBackendCc2jTcl.cc manage enumeration in CC 2 jTcl backend
 * Projet    :   Rubicon/jWrap
 * Module    :   jWrap C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/backend/enumBackendCc2jTcl.cxx,v $
 *
 * Modification History
 * --------------------
 * 01c,15feb99,Fulup,name each anonymous enum slot number unique
 * 01b,18apr98,Fulup,extracted from global class file for new tree
 * 01a,06feb98,Fulup,written
 */

#include <stdio.h>

#include "libBackendCc2jTcl.h"

/** ---------------------------------------------------------------------------
 **  Print Tcl type array and func for enumeration
 ** ---------------------------------------------------------------------------*/
void BackendCc2jTcl::outputEnumProc (McString * name, int count) {

  fprintf (outFile," static JWRAP_enums %s_enum  = {\n",(char*)*name);
  fprintf (outFile,"  JWRAP_ENUM,");
  fprintf (outFile,"  &usedType [JTYPE_%s],\n",jWrapType(name));
  fprintf (outFile,"  %d,\n",count);
  fprintf (outFile,"  %s_slotNames,\n",(char*)*name);
  fprintf (outFile,"  (long*)%s_slotValues\n",(char*)*name);
  fprintf (outFile," };\n");

  fprintf (outFile,"LOCAL int Put_%s (Tcl_Interp *interp, Tcl_Obj *tclObj) {\n", (char*)*name);
  fprintf (outFile,"  return (jWrapEnumTcl2Cc (interp, &%s_enum, tclObj));\n", (char*)*name);
  fprintf (outFile,"}\n");

  fprintf (outFile,"LOCAL void Get_%s (Tcl_Obj *tclObj) {\n", (char*)*name);
  fprintf (outFile,"  jWrapEnumCc2Tcl (&%s_enum, tclObj);\n",(char*)*name);
  fprintf (outFile,"}\n");

  fprintf (outFile,"// Build %s jointure as a Tcl type\n",(char*)*name);
  fprintf (outFile,"static Tcl_ObjType %s_type = {\n",(char*)*name);
  fprintf (outFile,"  \"%s\",\n", (char*)*name);
  fprintf (outFile,"  (Tcl_FreeInternalRepProc *)NULL,\n");
  fprintf (outFile,"  (Tcl_DupInternalRepProc *) NULL,\n");
  fprintf (outFile,"  (Tcl_UpdateStringProc*)    Get_%s,\n",(char*)*name);
  fprintf (outFile,"  (Tcl_SetFromAnyProc*)      Put_%s\n",(char*)*name);
  fprintf (outFile,"  };\n");
}

/**------------------------------------------------------------------------
 ** Enumeration are represent as static array in oder to register
 ** string/values correspondence in jWrap hashtable
 **------------------------------------------------------------------------*/
void BackendCc2jTcl::output (Enums* enumeration) {
   int ind;
   static int compteur = 1;

   // If structure is a jWrap generated structure we generate code
   if (!strncmp (enumeration->name, "Enum_", 5)) {
    fprintf (outFile," // As enum as no name we produce a dummy enumeration for size computing\n");
    fprintf (outFile," enum %s {\n", (char*) enumeration->name);
    for (ind=0; ind < enumeration->values.size(); ind ++) {
      if (ind != 0) fprintf (outFile,",\n");
      fprintf (outFile,"   slot_%d_%d" ,compteur, ind);
      if (enumeration->values[ind]->value.size() >0) {
        fprintf (outFile,"= %s", (char*)enumeration->values[ind]->name);
      };
    }
    fprintf (outFile,"\n };\n");
   }
   // save compteur for next run
   compteur++;

   fprintf (outFile,"\n  // build enumeration %s \n", (char*)enumeration->name);
   fprintf (outFile," static char *%s_slotNames [] = {\n", (char*)enumeration->name);
   for (ind=0; ind < enumeration->values.size(); ind++) {
        fprintf (outFile, "   \"%s\",\n",(char*)enumeration->values[ind]->name);
   }
   fprintf (outFile,"   NULL\n };\n");

   fprintf (outFile," static enum %s %s_slotValues [] = {\n"
           ,(char*)enumeration->name, (char*)enumeration->name);
   for (ind=0; ind < enumeration->values.size(); ind++) {
        fprintf (outFile, "   %s,\n"
          , (char*)enumeration->values[ind]->name);
   }
   fprintf (outFile,"   0\n };\n");

   outputEnumProc (&enumeration->name, enumeration->values.size());

} // end output enumeration

/**-------------------------------------------------------------------------
 ** Defines are represent a special enumeration name module_define
 ** Note we only take define that efectivelly start with a number.
 **-------------------------------------------------------------------------*/
void BackendCc2jTcl::output (McString * name, McDArray<Defines*> defines) {
   int ind;

   // remove any define with a value not starting with a number
   for (ind=0; ind < defines.size(); ind++) {
      if (((defines[ind]->value[0] != '(')&&(defines[ind]->value[0] != '-')&&(defines[ind]->value[0] != '+'))
          && ((defines[ind]->value[0] < '0') || (defines[ind]->value[0] > '9'))) {
       defines.remove (ind);
       ind --;
     }
   }

   fprintf (outFile,"\n // build define enumeration\n");
   fprintf (outFile," typedef long %s;\n",(char*)*name);
   fprintf (outFile," static char *%s_slotNames [] = {\n",(char*)*name);
   for (ind=0; ind < defines.size(); ind++) {
        fprintf (outFile, "   \"%s\",\n",(char*)defines[ind]->name);
   }
   fprintf (outFile,"   NULL\n };\n");

   fprintf (outFile," static long %s_slotValues [] = {\n",(char*)*name);
   for (ind=0; ind < defines.size(); ind++) {
        fprintf (outFile, "   (long)%s,\n",(char*)defines[ind]->name);
   }
   fprintf (outFile,"   0\n };\n");

   outputEnumProc (name, defines.size());
} // end output defines
