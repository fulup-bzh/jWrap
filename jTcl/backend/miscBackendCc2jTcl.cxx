/*
 *  Copyright(c) 1997-98 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   micsBackendCc2jTcl.cc misceleanous method in C++ 2 jTcl backend wrapper
 * Projet    :   Rubicon/jWrap
 * Module    :   jWrap C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/jTcl/backend/miscBackendCc2jTcl.cxx,v $
 *
 * Modification History
 * --------------------
 * 01b,18apr98,Fulup,moved to new tree
 * 01a,06feb98,Fulup,written
 */

#include <stdio.h>

#include "libBackendCc2jTcl.h"


// Build output name from input one
void BackendCc2jTcl::setOutName (Programs *program) {

  // WARNING: this function is not call when output=-
  if (program->classes.size () > 0) {
    outName += "_jWrap.cxx";     // add jWrap C++ extension
  } else {
    outName += "_jWrap.c";      // add jWrap Ordinary C extension
  }
} // end setOutName


/****************************************************************************
 ** Constructor just pass parameter to super class
 *************************************************************************** */
void BackendCc2jTcl::init (Programs* program, char *outDir, char* usrName) {
  char * tmpName;
  int    ind;

  BackendCcProto::init (program, outDir, usrName);

  // check we effectively have an implement name
  if (program->implement.size() <= 1) goto noModuleName;

  // Module name is implement name without dot
  modName = program->implement;
  tmpName = modName;
  for (ind=0; ind < modName.size()-1 ; ind++) {
       if (tmpName [ind] == '.') {
          modName[ind] = '\0';
       }
  }

  return;

noModuleName:
  fprintf (stderr, "ERROR:BackendCc2jTcl no module implementation name found plus use  --implement flag\n");
  status = ERROR;

} // end application constructor

// Dummy empty constructor for stupid c++
BackendCc2jTcl::BackendCc2jTcl () {

} // end constructor
