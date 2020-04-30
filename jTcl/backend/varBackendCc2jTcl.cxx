/*
 *
 *  Copyright(c) 1997 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   varBackendCc2jTcl.cc manage variable in C++ 2 jTcl backend wrapper 
 * Projet    :   Rubicon/jWrap
 * Module    :   jWrap C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/backend/varBackendCc2jTcl.cxx,v $
 *
 * Modification History
 * --------------------
 * 01b,18apr98,Fulup,extracted from global class file for new tree
 * 01a,06feb98,Fulup,written
 */

#include <stdio.h>

#include "libBackendCc2jTcl.h"

/*******************************************************************
 ** Output variable place C++ var in current C/C++ namespace
 *******************************************************************/ 
void BackendCc2jTcl::output (Vars* var) {

      switch (var->location) {
      case LOC_GLOBAL:
          fprintf (outFile," extern");
          break;
      case LOC_STATIC:
          fprintf (outFile,"    static");
          break;
      case LOC_AUTO:
          fprintf (outFile,"   ");
          break;
      case LOC_VIRTUAL:
          fprintf (outFile,"    virtual");
          break;
       }
      fprintf (outFile," %s %s;\n", (char*)var->type, (char*)var->name);
} // end output var

/*******************************************************************
 ** Register variable in order trace proc to main c++/Tcl coherency
 *******************************************************************/ 
void BackendCc2jTcl::registrate (Vars* var) {
  char *jTclObj;
  char *prefix    = "";  // use to class store class name for static data
  char *separator = "";  // use to place ::
  char *tclPrefix = "";  // use to make local variable unique in JWRAP array 
  char *tclSeparator = "";
  int  len = var->name.size()-1; // Tcl what string len without \0

      switch (var->location) {
      case LOC_GLOBAL:
          jTclObj = "NULL";
          if (var->visibility == PROT_PRIVATE) {
             tclPrefix    = modName;
             tclSeparator = ".";
             len = len + modName.size();
          }
          break;
      case LOC_STATIC:
          jTclObj   = "tclClassArray";
          prefix    = var->owner->name;
          separator = "::";
          break;
      case LOC_AUTO:
      case LOC_VIRTUAL:
    	  fprintf (outFile,"  "); // source target indentation
          jTclObj = "jTclHandle";
          break;
       }
      fprintf (outFile," jWrapVarRegister (interp, %s, \"%s%s%s\", (long*)&%s%s%s, %d \n"
              , jTclObj, tclPrefix,tclSeparator,(char*)var->name , prefix, separator
              , (char*)var->name, len);
      fprintf (outFile,"                  , &usedType[JTYPE_%s]);\n"
              ,jWrapType(&var->type));
} // end registrate var

/*******************************************************************
 ** unregister variable in order trace proc to main c++/Tcl coherency
 *******************************************************************/ 
void BackendCc2jTcl::unregistrate (Vars* var) {

      switch (var->location) {
      case LOC_GLOBAL:
      case LOC_STATIC:
	return;       // static variables are never unregistrate
      }

      fprintf (outFile,"    jWrapVarUnRegister (interp, jTclHandle, \"%s\");\n"
              , (char*)var->name);
} // end unregistrate var













