/* $Header: /Master/jWrap/Include/libBackendCcHat.h,v 1.3.0.1 1999/03/11 12:49:29 Fulup Exp $
 *
 *  Copyright(c) 1997 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   libBackendCcHat.h C/C++ hat backend
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/Include/libBackendCcHat.h,v $
 *
 * Modification History
 * --------------------
 * 01b,18apr98,Fulup moved to new tree
 * 01a,06feb98,Fulup,written
 */

#ifndef _libBackendCcHat_
#define _libBackendCcHat_

#include "oalWrap.h"
#include <easyc.h>

#include "libBackendCcProto.h"

class BackendCcHat : public BackendCcProto {
 public:

  virtual void setOutName  (Programs*);      // Compute outfilename from infilename
  virtual void output (Vars      *);         // Print out all variable
  virtual void output (Functions *);         // Print out all function and methods
  virtual void output (Classes   *);         // print out class header
  virtual void output (Programs  *);         // print out header and move down in object hierarchie

  BackendCcHat        (void);             // Dummy C++ Constructor
  
};

#include <libBackendCcHat.i>
#endif	/* libBackendCcHat.h */











