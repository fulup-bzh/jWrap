/* $Header: /Master/jWrap/Include/libBackendCcProto.h,v 1.3.0.1 1999/03/11 12:49:29 Fulup Exp $
 *
 *  Copyright(c) 1997 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   libBackendCcProto.h C/C++ ansi proto backend
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/Include/libBackendCcProto.h,v $
 *
 * Modification History
 * --------------------
 * 01b,18apr98,Fulup moved to new tree
 * 01a,06feb98,Fulup,written
 */

#ifndef _libBackendCcProto_
#define _libBackendCcProto_

#include "oalWrap.h"
#include <easyc.h>


class BackendCcProto {
 public:
  McString              outName;             // Output file name
  McString              inName;              // InputFilename
  McString              baseName;            // Input name with no extention
  McString              defName;             // Output Name compatible with define 
  FILE*                 outFile;             // Output FileId
  int                   status;              // set to ERROR on order breaking ccproto

  char* getDate ();                          // return current data in ASCII
  virtual void setOutName  (Programs*);      // Compute outfilename from infilename
  virtual void output (Vars      *);         // Print out all variable
  virtual void output (Functions *);         // Print out all function and methods
  virtual void output (Classes   *);         // print out class header
  virtual void output (Enums     *);         // print out enumeration
  virtual void output (Programs  *);         // print out header and move down in object hierarchie

  virtual void output (Typedefs  *);         // Output typedef alias to struct or enum
  virtual void output (McString  *);         // print out javadoc lines
  virtual void output (Structs   *);         // output structure and unions

  void init      (Programs*,char* outDir, char*outFile);   // Application Constructor
  BackendCcProto        (void);             // Dummy C++ Constructor
  
};

#include <libBackendCcProto.i>
#endif	/* libBackendCcProto.h */











