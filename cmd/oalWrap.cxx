/**
 *
 *  Copyright(c) 199 a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   oalWrap.cc Object Abstraction layer
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/cmd/oalWrap.cxx,v $
 *
 * Modification History
 * --------------------
 * 01b,18apr98,Fulup,adapted to new tree
 * 01a,06feb98,Fulup,written
 */


#include "oalWrap.h"

// Global exported datas
 EXPORT   FILE*      yyin;
 EXPORT   char       *yyFileName;
 EXPORT   VISIBILITY visibility;
 EXPORT   Programs   *currentProgram =(Programs*)NULL;
 EXPORT   Classes    *currentClass   =(Classes*)NULL;
 EXPORT   Functions  *currentFunction=(Functions*)NULL;
 EXPORT   Enums      *currentEnum    =(Enums*)NULL;
 EXPORT   Functions  *currentMethod  =(Functions*)NULL;

 EXPORT   McString   currentType; // hold type when one type define more than one var
 EXPORT   McDArray<Elements*> currentElements;
 EXPORT   McDArray<Vars*>     currentVars;

 EXPORT   VISIBILITY currentVisibility;

 // some static starting option save
 EXPORT   BOOL     asDebugYacc =FALSE;
 EXPORT   BOOL     verbose     =FALSE;
 EXPORT   SINT32   debugLevel  =0;


Defines::Defines (McString*nom,McString*valeur ) {
 name  = *nom;
 value = *valeur;
}

BasicDatas::BasicDatas () {
  doc   = (McString*)NULL;
  owner = (BasicDatas*)NULL;
  valid = TRUE;
}

// Enumeration values constructor
Values::Values (char* nam, char* val) {
  name         = nam;
  value        = val;
};

// build a new parameter and free usr given type
Params::Params (McString *usrType) {
 type = *usrType;
 name = "noName";
};

// build a new function
Functions::Functions (McString *nom) {
 name = *nom;
};

// build a new parameter and free usr given type
Params::Params (char *usrType) {
 type = usrType;
 name = "noName";
};

// Build a structure
Structs::Structs (char *nom) {
  name    = nom;
}
Structs::Structs () {};


// Build a Unions
Unions::Unions (char *nom) {
  name    = nom;
}

// Element is basic componant of a structure
Elements::Elements (char* nom) {
 name = nom;
 type = currentType;
 array = -1;
}

// build a default help message from paramters
void Functions::defaultHelp (void) {

 int ind;

 // if function is not valid return
 if (!valid) return;

 if (result.size() > 1) {
  help =  result;
  help += " = ";
 }
 help += name;
 help += " (";

 for (ind = 0; ind < params.size (); ind ++) {
   if (ind != 0) help += ", ";
   help += params [ind]->type;
   help += " ";
   help += params [ind]->name;
 }
 help += ");";

}; // end defaultHelp

// Vars have a name
Vars::Vars (McString* nom) {
 name = *nom;
 array = -1;
}

// typedef alias constructor
Typedefs::Typedefs (McString* alias, McString *destination) {
 name   = *destination;
 source = *alias;
};

// Final Class Program constructor
Programs::Programs (char* fileName, LANGUAGE language) {
   name         = fileName;
   doc          = (McString*)NULL;
   ownerName    = fileName;
   lang         = language;
   numLine      = 0;
   ownerLine    = 0;
   firstInclude = -1;
   assertLine   = -1;
   help         = "No Help";
};
