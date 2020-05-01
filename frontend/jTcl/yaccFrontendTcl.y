%{
/*
 *
 *  Copyright(c) 1997 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   yaccFrontendTcl.y define wrapper grammar
 * Projet    :   Rubicon
 * Module    :   jDoc jTcl->java doc converter
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/frontend/jTcl/yaccFrontendTcl.y,v $
 *
 * Modification History
 * --------------------
 * 01b,16apr98,Fulup,moved to new name
 * 01a,21mar98,Fulup,written from jWrap
 */

/*
 *	includes
 */
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "libFrontendTcl.h"

// Import some data from lex
IMPORT char *yytcl_text;
IMPORT int  yytcl_lex();

#define yytext_ptr yytcl_text

LOCAL Vars* currentVar;

// Display a minimum error message when needed
void yytcl_error (char *s)
{
        fprintf (stderr, "yytcl_error: %s, line %d\n", s, currentProgram->numLine+1);
        currentProgram->status=ERROR;
} //end yyerror
LOCAL void debugMsg (int level, const char *format)
{
  if ((debugLevel>=level) || (-1*debugLevel==level)){
     printf("%d yacc %s:%3d [%3d] %-25s\n"
            ,level,(char*)currentProgram->ownerName,currentProgram->ownerLine
            ,currentProgram->numLine,format);

     asDebugYacc = TRUE;
  }
}

LOCAL void debugMsg (int level, char *format, const char *message)
{
  if ((debugLevel>=level) || (-1*debugLevel==level)){
     printf("%d yacc %s:%3d [%3d] %-25s =|%s|\n"
            ,level,(char*)currentProgram->ownerName,currentProgram->ownerLine
            ,currentProgram->numLine,format,message);

     asDebugYacc = TRUE;
  }
}
LOCAL void debugMsg (int level, const char *format, const char *mesg1, const char *msg2)
{
  if (debugLevel>=level) {
     printf("%d yacc %s:%3d [%3d] %-25s =|%s %s|\n"
            ,level ,(char*)currentProgram->ownerName,currentProgram->ownerLine
            ,currentProgram->numLine,format,mesg1,msg2);

     asDebugYacc = TRUE;
  }
}

%}

// Generic Token
%token G_WORD G_ERROR G_EOL

// Application token
%token CLASS_TAG   PROC_TAG      PRIVATE_TAG  PUBLIK_TAG
%token CLOSE_BRACE OPEN_BRACE    EXTENDS_TAG  STATIC_TAG
%token DOC_BLOCK   PACKAGE_TAG   IMPORT_TAG   END_CODE
%token VAR_TAG     IMPLEMENT_TAG

// Specify Token type for those returning a value
%union
{
  Params    *param;
  int       intVar;
  char      charVar;
  McString  *dString;
  Values    *value;
  Extends   *extend;
}

// Lex typed token
%type <dString>  DOC_BLOCK
%type <dString>  G_WORD


// Yacc typed token
%type <dString>     Doc
%type <dString>     GWords


%%

// Starting rule return a valid program or an error
Start:
    |   Program {
	currentProgram->status=OK;
    }
    |	Program G_ERROR	{ fprintf( stderr
                     	  ,"ERROR before line %d of file %s\n"
			  ,currentProgram->numLine, (char*)currentProgram->name);
	currentProgram->status=ERROR;
    }
    ;

// A program is builded with a header Classes Function and global vars
Program:
     | Program Package;    // ignored
     | Program Import;     // ignored
     | Program Implement {
       debugMsg (5, "Program Accept Implement Module");
     }
     | Program Doc {
            if (currentProgram->doc ==  NULL) {
       debugMsg (2, "Program Set Doc", currentProgram->name, *$2);
       currentProgram->doc = $2;
     } else {
       debugMsg (2, "Program Add Doc", currentProgram->name, *$2);
       *currentProgram->doc += *$2;
       free ($2);
     }
     }
     | Program Classe {
       // Add current class in program
       debugMsg (2, "Add Class in Program", currentProgram->name, currentClass->name);
       currentProgram->classes.append (currentClass);
       currentClass->owner = currentProgram;
     }
     | Program Var {
       // Add current Global in program
       debugMsg (2, "Program Add Var");
       currentProgram->vars.append (currentVar);
       currentVar->owner = currentProgram;
     }
     | Program Function {
       // Add current Function in program
       debugMsg (2, "Add Function in Program", currentProgram->name, currentMethod->name);
       currentProgram->functions.append (currentMethod);
       currentMethod->owner = currentProgram;
     }
     | Program GWords {
       // Ignore any unattended word
       debugMsg (5, "Program Ignoring word", *$2);
       free ($2);
     }
     | Program GEols {
       // Ignore any unattended return line
       debugMsg (5, "Program Ignoring GEols");
     }
     ;

// Modulename is taken from jClassModule function
Implement: IMPLEMENT_TAG G_WORD {
     debugMsg (4, "Add Implement Module in Program", *$2);
      currentProgram->implement = *$2;
      free ($2);
    }
    ;

// If any add doc to current function
Function:  Doc FunctionBlock {
     debugMsg (4, "Add Doc in Function", *$1);
     currentMethod->doc = $1;
     }
     | FunctionBlock
     ;

// An exported function should be prefixed with PUBLIC keyword
FunctionBlock: PROC_TAG MethodCore {
        debugMsg (3, "Get Public Function", currentMethod->name);
        currentMethod->visibility = PROT_PUBLIC;
        currentMethod->location   = LOC_GLOBAL;
        currentMethod->defaultHelp();
     }
     ;

// if any add doc to class
Classe: Doc ClasseBlock {
     debugMsg (4, "Add Doc in Class", *$1);
     currentClass->doc = $1;
     }
     | ClasseBlock
     ;

// Classe have are prefix with CASS_TAG and follow with a name methods and vars
ClasseBlock:
     ClassHeader ClsExtends ClsCore {
       // update current class name
       debugMsg (5, "Got Class",currentClass->name);
     }
     ;

// Class header is prefixe with class and have a name
ClassHeader: CLASS_TAG G_WORD {
       // update current class name
       debugMsg (1, "Class Header", *$2);
       currentClass=new Classes();
       currentClass->name = *$2;
       free ($2);
     }
     ;

// Extension is a list of classes
ClsExtends:  OPEN_BRACE Extends CLOSE_BRACE {
        // Add each super class in extension list
        debugMsg (5, "Extends Class done","NoText");
     }
     ;

// Get super class name and attached tag if any
Extends:
     EXTENDS_TAG G_WORD {
        Extends *extends;
        extends = new Extends();
        extends->name = *$2;
        extends->visibility=PROT_PUBLIC;
        currentClass->extends.append (extends);
        debugMsg (4, "First Super Class", *$2);
     }
     | Extends EXTENDS_TAG G_WORD {
        Extends *extends;
        extends = new Extends();
        extends->name = *$3;
        extends->visibility=PROT_PUBLIC;
        currentClass->extends.append  (extends);
        debugMsg (4, "Supplementary Super Class", *$3);
     }
     ;

// if class is limited with to brace
ClsCore: OPEN_BRACE SectionPublic CLOSE_BRACE;

// Public section is equivalent to private
SectionPublic:
     | SectionPublic Method {
       debugMsg (2, "Section Add Method Public", currentMethod->name);
       currentClass->methods.append (currentMethod);
       currentMethod->owner = currentClass;
       currentMethod->visibility = PROT_PUBLIC;
     }
     | SectionPublic Var {
       debugMsg (2, "Section Add public Var", currentVar->type, currentVar->name);
       currentClass->vars.append (currentVar);
       currentVar->owner = currentClass;
       currentVar->visibility    = PROT_PUBLIC;
     }
     ;

Var: Doc VarBlock {
     debugMsg (4, "Add Doc in Var", *$1);
     currentVar->doc = $1;
     }
     | VarBlock
     ;

VarBlock:
     STATIC_TAG VarCore {
       currentVar->location   = LOC_STATIC;
     }
     | VAR_TAG VarCore {
       currentVar->location   = LOC_AUTO;
     }
     ;

VarCore: G_WORD {
       debugMsg (3, "Instance Var Basic", *$1);
       currentVar = new Vars($1);
       currentVar->type = "String";
     }
     | G_WORD OPEN_BRACE {
       debugMsg (3, "Instance Var With Code", *$1);
       currentVar = new Vars($1);
       currentVar->type = "String";
       yytcl_IgnoreUntilEOB(1);
     }
     | G_WORD G_WORD {
       debugMsg (3, "Instance Var Initialized", *$1);
       currentVar = new Vars($1);
       currentVar->type = "String";
     }
     ;


// package require name
Package: PACKAGE_TAG G_WORD G_WORD;

// jClassImport
Import: IMPORT_TAG OPEN_BRACE GWords CLOSE_BRACE;

// GWords return first word of a list ignore any other one
GWords:
     G_WORD {
       $$=$1;
     }
     | GWords G_WORD {
       free    ($2);
       $$   =   $1;
     }
     ;

// add doc to method if any
Method: Doc MethodBlock {
     debugMsg (4, "Add Doc in Method", *$1);
     currentMethod->doc = $1;
     }
     | MethodBlock
     ;

// A method is static virtual or ordinary
MethodBlock:
     MethodCore END_CODE {
        debugMsg (3, "Get Constructor/Destructor Method", currentMethod->name);
        currentMethod->location  = LOC_AUTO;
        currentMethod->visibility= PROT_PUBLIC;
        currentMethod->defaultHelp();
        currentMethod->result = "String";
     }
     | PUBLIK_TAG  MethodCore END_CODE {
        debugMsg (3, "Get Public Method", currentMethod->name);
        currentMethod->location  = LOC_AUTO;
        currentMethod->visibility= PROT_PUBLIC;
        currentMethod->defaultHelp();
        currentMethod->result = "String";
     }
     | PRIVATE_TAG  MethodCore END_CODE {
        debugMsg (3, "Get Private Method", currentMethod->name);
        currentMethod->location  = LOC_AUTO;
        currentMethod->visibility= PROT_PRIVATE;
        currentMethod->defaultHelp();
        currentMethod->result = "String";
     }
     ;

// A methods can be virtual with or without return type as alway have parameters
MethodCore: G_WORD Params OPEN_BRACE {
        debugMsg (4, "Get Method", *$1);
        currentMethod->name     = *$1;
        yytcl_ModeInCode(1);
     }
     ;

// Doc is a block doc + some empty lines
Doc: DOC_BLOCK {
    $$ = $1;
  }

// GEols one or more end of line
GEols:
  G_EOL
  | GEols G_EOL
  ;


// Params is a list of word and can be empty
Params: OPEN_BRACE {
       // we got a new method allocated it and add it in class
       debugMsg (5, "Create New Method", "NoText");
       currentMethod = new Functions (new McString (""));
     }
     | Params  CLOSE_BRACE {
       debugMsg (5, "Params End", "No Text");
       // currentMethod->params = NULL;
     }
     | Params G_WORD {
       Params *param;
       // Save parameter in method mist
       debugMsg (4, "Params Basic", *$2);
       param = new Params ("String");
       param->name = *$2;
       currentMethod->params.append (param);
     }
     | Params G_WORD OPEN_BRACE {
       Params *param;
       debugMsg (4, "Params Initialized", *$2);
       param = new Params ("String");
       param->name = *$2;
       currentMethod->params.append (param);
       yytcl_IgnoreUntilEOB(1);
     }
     ;

