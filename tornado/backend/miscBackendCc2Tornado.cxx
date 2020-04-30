/*
 *  Copyright(c) 1997-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   micsBackendCc2Tornado.cc misceleanous method in C++ 2 jTcl backend wrapper
 * Projet    :   /jWrap
 * Module    :   WTX VxWorks Troando C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:30 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/tornado/backend/miscBackendCc2Tornado.cxx,v $
 *
 * Modification History
 * --------------------
 * 01b,16feb99,Fulup,remanced modulefrom TORNADO to Tornado
 * 01a,03jun98,Fulup,written
 */

#include <stdio.h>

#include "libBackendCc2Tornado.h"


// Build output name from input one
void BackendCc2Tornado::setOutName (Programs *program) {

  // WARNING: this function is not call when output=-
  if (program->classes.size () > 0) {
    outName += "_tornado.cxx";     // add jWrap C++ extension
  } else {
    outName += "_tornado.c";      // add jWrap Ordinary C extension
  }
} // end setOutName



// Dummy empty constructor for stupid c++
BackendCc2Tornado::BackendCc2Tornado () {
  
} // end constructor    
