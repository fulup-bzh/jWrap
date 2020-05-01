/**
 *
 *  Copyright(c) 1997-98 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   libBackendCc2jTcl.h generate C/C++ to jTcl Wrapper
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/Include/libBackendCc2jTcl.h,v $
 *
 * Modification History
 * --------------------
 * 01b,16apr98,Fulup,moved to new tree
 * 01a,06feb98,Fulup,written
 */

#ifndef _libBackendCc2jTcl_
#define _libBackendCc2jTcl_

#include "oalWrap.h"
#include "libBackendCcProto.h"


/** -------------------------------------------------------------------
 ** This small structure is used to store typename with
 ** a magic defining is type [struct,union, ...]
 ** -------------------------------------------------------------------*/
class registeredType {
 public:
  McString* name;
  STRUCTURE magic;

 registeredType (McString*, STRUCTURE);
};


class BackendCc2jTcl : public BackendCcProto {

 public:

  int   constructorDone;                     // flag to select default or application constructor
  McDArray<Functions*> polymorphs;           // hold polymorph functions

  McDArray<registeredType*> cTypes;          // hold all used struct & union & type
  /** Keep a list of all used CMD in order generating a static array
      that is used for jWrap help/list command and for mini help diskplay when
      input parameters are wrong */
  McDArray<Functions*> usedCmd;

  /** Module name is used to prefix almost any public name, we take it either from
      --implement tag or from <Implement:> tag in program header */
  McString modName;

  /** We build an enumeration of all used type, in order allowing compiler to sold
      statically type ammping when input/ouput paramters */
  virtual char     *jWrapType (McString *);

  virtual void setOutName      (Programs*);  // Compute outfilename from infilename
  virtual void registerType    (McString*,int,STRUCTURE); // prepare to build JWRAP_TYPE information
  virtual void outputEnumProc (McString * name, int count); // Common part for define & enum
  virtual void output (McDArray<Functions*>methods, char*);   // Print polymorph extra wrapper
  virtual void output (McString*, McDArray<Defines*>);            // print define
  virtual void output (Vars      *);         // Print out all variable
  virtual void output (Unions   *);          // Print out unions mapping
  virtual void output (Structs   *);         // Print out structure mapping
  virtual void output (Functions *);         // Print out all function and methods
  virtual void output (Classes   *);         // print out class header
  virtual void output (Enums     *);         // print out enumeration
  virtual void output (Programs  *);         // print out header program

  virtual void registrate (Typedefs *alias); // Registrate typedef Alias
  virtual void registrate (Vars      *);     // Register in TCL interp variables
  virtual void unregistrate (Vars    *);     // Register in TCL interp variables
  virtual void registrate (Unions   *);
  virtual void registrate (Structs   *);
  virtual void registrate (Functions *);     // Register in TCL interp functions and methods
  virtual void registrate (Classes   *);     // Register in TCL interp classes

  virtual void init (Programs*, char*, char*); // application constructor
  BackendCc2jTcl ();                              // dummy c++ constructor
};

#include <libBackendCc2jTcl.i>

#endif	/* libBackendCc2jTcl.h */


