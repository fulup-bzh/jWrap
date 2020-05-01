/* $Header: /Master/jWrap/Include/libBackendJavadoc.h,v 1.3.0.1 1999/03/11 12:49:29 Fulup Exp $
 *
 *  Copyright(c) 1998 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   libBackendJavadoc.h Generated javadoc
 * Projet    :   Rubicon/jTcl
 * Module    :   Javadoc backend
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/Include/libBackendJavadoc.h,v $
 *
 * Modification History
 * --------------------
 * 01b,18apr98,Fulup moved to new tree
 * 01a,03mar98,Fulup,written
 */

#ifndef _libBackendJavadoc_
#define _libBackendJavadoc_

#include "libBackendCc2jTcl.h"

class BackendJavadoc : public BackendCc2jTcl {
 public:

  virtual int  openOutFile (char*,char*,McString*);  // Open destination file in outdir
  virtual void setOutName  (Programs*);      // Compute outfilename from infilename
  virtual void output (Typedefs  *);         // Output typedef alias to struct or enum
  virtual void output (Vars      *);         // Print out all variable
  virtual void output (Functions *);         // Print out all function and methods
  virtual void output (Classes   *);         // print out class header
  virtual void output (Enums     *);         // print out enumeration
  virtual void output (McString  *);         // print out javadoc lines
  virtual void output (Structs   *);         // output structure and unions
  virtual void output (Programs  *);         // print out program header
  virtual void init   (Programs* program, char *outDir, char* usrName);
  BackendJavadoc  (void);                       // Dummy C++ Constructor

};

#include <libBackendJavadoc.i>
#endif	/* libBackendJavadoc.h */













