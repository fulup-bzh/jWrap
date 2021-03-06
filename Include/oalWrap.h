/* $Header: /Master/jWrap/Include/oalWrap.h,v 1.3.0.1 1999/03/11 12:49:29 Fulup Exp $
 *
 *  Copyright(c) 1997 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   oalWrap.h Object Abstraction layer
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/Include/oalWrap.h,v $
 *
 * Modification History
 * --------------------
 * 01b,16apr98,Fulup,moved to new tree
 * 01a,06feb98,Fulup,written
 */

#ifndef _oalWrap_
#define _oalWrap_

#include <easyc.h>

#include "../Inline/McDArray.h"
#include "../Inline/McString.h"

#define NOT_SET "NotSet"

enum STRUCTURE
{
    TYPE_NATIVE,
    TYPE_STRUCT,
    TYPE_UNION,
    TYPE_ENUM,

    TYPE_UNKNOW
} ;

enum TARGET
{
    TARGET_UKNOWN,
    TARGET_CCPROTO,
    TARGET_CCJTCL,
    TARGET_CCHAT,
    TARGET_JAVADOC,
    TARGET_CCTORNADO,

    TARGET_UNKNOW
} ;

enum LOCATION
{
    LOC_GLOBAL = 0,
    LOC_STATIC = 1,
    LOC_AUTO   = 2,
    LOC_VIRTUAL= 3,

    LOCAl_UNKNOW
} ;

enum VISIBILITY
{
    PROT_PUBLIC    = 0,
    PROT_PRIVATE   = 1,
    PROT_PROTECTED = 2,

    PROT_UNKNOW    = 3
} ;

enum LANGUAGE
{
    LANG_UNKNOWN,
    LANG_JAVA,
    LANG_JTCL,
    LANG_CC,

    LANG_UNKNOW
} ;

class BasicDatas {
 public:
  McString              name;            // symbolic name
  McString              *doc;            // java doc lines
  McString              help;            // one line help text
  BasicDatas            *owner;          // reverse link to owner object
  int                   valid;           // valid Flag
  BasicDatas ();                         // init pointer to NULL
};

class Defines {
 public:
  McString name;
  McString value;
  McString *doc;

  Defines  (McString*, McString*);      // Define with doc
};

class Elements : public BasicDatas   {
 public:
  McString             type;
  int                  array;

  Elements (char*);
};

class Structs : public BasicDatas   {
 public:
  McDArray<Elements*> elements;           // A structure is build of structure
  Structs (char*);
  Structs ();
};

// Unions is equivalent to struct in midle rep.
class Unions : public Structs {
 public:
 Unions (char*);
};

class Vars : public BasicDatas   {
 public:
  VISIBILITY            visibility;       // Protection level
  McString              type;             // used type
  int                   array;            // Array factor
  LOCATION              location;         // Where to place variable in ram

  Vars (McString*);                       // Constructor
};

class Typedefs : public BasicDatas {
 public:
  McString             source;             // Original type name [struc, basic, enum]
  Typedefs (McString*, McString*);         // Constructor
};

class Values : public BasicDatas {
 public:
  McString             value;             // constante value

  Values (char*,char*);                   // constructor
};

class Extends : public BasicDatas {
 public:
  VISIBILITY            visibility;       // constante value
  McString              extra;            // extra values ?
};

class Enums : public BasicDatas {
 public:
  McDArray<Values*>    values;            // As many as seted of params
};

class Params : public BasicDatas {
 public:
   McString   type;                       // Parameter type
   McString   name;                       // Parameter name

   Params (McString*);                    // constructor
   Params (char*);                        // constructor
};

class Functions : public BasicDatas {
 public:
  int                  number;            // command number in module
   VISIBILITY           visibility;       // Protection level
   McDArray<Params*>    params;           // Parameter list
   McString             result;           // Returned type
   LOCATION             location;         // Are we virtual ?
   Functions (McString*);                 // constructor
   void defaultHelp (void);               // build a default help message from params
};

class Classes : public BasicDatas {
 public:
   VISIBILITY           visibility;        // Class protection status
   McDArray<Extends*>   extends;           // Class extention list
   McDArray<Vars*>      vars;              // Class static variables
   McDArray<Functions*> methods;           // Class methods list
   McDArray<Enums*>     enums;             // Enumeration constante
};

class Programs : public BasicDatas {
 public:
   McString             ownerName;         // CurrentFile name change when parsing CPP
   int                  ownerLine;         // CurrentLine in owner file
   McString             implement;         // Program name given in assert directive
   LANGUAGE             lang;              // Used language
   McDArray<Typedefs*>  typedefs;          // Typedef alias
   McDArray<Enums*>     enums;             // Enumeration constante
   McDArray<Structs*>   structs;           // Complex Structure
   McDArray<Unions*>    unions;            // Union
   McDArray<Defines*>   defines;           // Define a special Enum
   McDArray<Vars*>      vars;              // Global  exported variables
   McDArray<Functions*> functions;         // Program exported function
   McDArray<Classes*>   classes;           // Program exported classes
   int                  status;            // Exit parsing status
   int                  numLine;           // Current numline number in effective parsed file
   int                  firstInclude;      // First include should be after assert for ccproto
   int                  assertLine;        // Assert line number check in ccproto

   Programs (char* name, LANGUAGE lang);   // Constructor
};

#include <oalWrap.i>
#endif	/* oalWrap */
