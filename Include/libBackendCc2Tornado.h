/**
 *
 *  Copyright(c) 1997-99 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   libBackendCc2Tornado.h generate C/C++ to Tornado/Wtx Wrapper
 * Projet    :   jWrap
 * Module    :   Tornado/Wtx Tornado/VxWorks interface
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/Include/libBackendCc2Tornado.h,v $
 *
 * Modification History
 * --------------------
 * 01b,16feb99,Fulup,remanced modulefrom WPR to Tornado
 * 01a,30may98,Fulup,written
 */

#ifndef _libBackendCc2Tornado_
#define _libBackendCc2Tornado_

#include "libBackendCc2jTcl.h"


class BackendCc2Tornado : public BackendCc2jTcl {

 public:

  virtual void output (Functions *);            // Print out all function and methods
  virtual void output (Programs  *);            // print out header program
  virtual void setOutName (Programs *program);  // build output name from input
  virtual void tornadoTypeStdMap (void);            // map all basic type with target & tornadoId
  BackendCc2Tornado ();                             // dummy c++ constructor
};

#include <libBackendCc2Tornado.i>

#endif	/* libBackendCc2Tornado.h */











