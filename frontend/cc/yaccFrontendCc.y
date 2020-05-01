%{
/*
 *
 *  Copyright(c) 1997 FRIDU a Free Software Company [fridu@fridu.bzh]
 *
 * File      :   yaccCcWrap.y define wrapper grammar
 * Projet    :   Rubicon/jTcl
 * Module    :   jTcl C++ wrapper
 * Auteur    :   Fulup Ar Foll [Fulup@fridu.bzh]
 *
 * Last
 *      Author      : $Author: Fulup $
 *      Date        : $Date: 1999/03/11 12:49:29 $
 *      Revision    : $Revision: 1.3.0.1 $
 *      Source      : $Source: /Master/jWrap/frontend/cc/yaccFrontendCc.y,v $
 *
 * Modification History
 * --------------------
 * 01c,14jul98,Fulup,made C++ parsing work again
 * 01b,18apr98,Fulup,moved to new tree improved parsing to support QT includes
 * 01a,06feb98,Fulup,written from jDoc & doc++ & swig and many others.
 */

/*
 *	includes
 */
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


#include "libFrontendCc.h"

// Import some data from lex
IMPORT char *yycc_text;
IMPORT int  yycc_lex();

// Display a minimum error message when needed
void yycc_error (const char *s)
{
        fprintf (stderr, "yycc_error: %s:%d %s, line %d, token=|%s|\n"
                       ,(char*)currentProgram->ownerName,currentProgram->ownerLine
                       ,s,currentProgram->numLine+1,yycc_text);
        currentProgram->status=-1;
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

LOCAL void debugMsg (int level, const char *format, const char *message)
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
%token G_WORD G_ERROR G_EOL G_SEPARATOR G_END G_EQUAL G_LINE G_NUM G_OPERATOR

// Application token
%token FILE_TAG     CLASS_TAG     VIRTUAL_TAG   SUPER_TAG    PUBLIK_TAG
%token CLOSE_PRM    OPEN_PRM      STATIC_TAG    EXPOR_TAG   IMPLEMENT_TAG
%token ENUM_TAG     DOC_BLOCK     SECTION_TAG   DEFINE_TAG   G_EQUAL
%token LINE_TAG     END_CODE      OPEN_BRACE    CLOSE_BRACE  IGNORE_TAG
%token WARNING_TAG  TYPEDEF_TAG   STRUCT_TAG    UNION_TAG    G_PTR
%token COMPLEX_TYPE CONST_TYPE    OPEN_BRAKET   CLOSE_BRAKET

// Specify Token type for those returning a value
%union
{
  Params*     param;
  int         intVar;
  char        charVar;
  McString*   dString;
  Values*     value;
  Extends*    extend;
  Vars*       var;
  VISIBILITY  prot;
  Structs*    structure;
  Unions*     jointure;
  Typedefs*   typealias;
  Elements*   element;
  Defines*    define;
}

// Lex typed token
%type <dString>     DOC_BLOCK
%type <dString>     G_WORD
%type <intVar>      LINE_TAG
%type <intVar>      G_NUM
%type <intVar>      G_OPERATOR
%type <prot>        SECTION_TAG
%type <dString>     COMPLEX_TYPE
%type <dString>     CONST_TYPE
%type <dString>     G_LINE

// Yacc typed token
%type <intVar>      Number
%type <intVar>      Array
%type <dString>     Doc
%type <dString>     GWords
%type <define>      DefineBlock
%type <extend>      ClsHeader
%type <extend>      ClsSuper
%type <param>       Param
%type <dString>     ComplexType
%type <value>       Value
%type <value>       ValueBlock
%type <prot>        Section
%type <var>         VarInstance
%type <var>         VarDeclaration
%type <dString>     GPtrs
%type <jointure>    UnionBlock
%type <jointure>    UnionCore
%type <structure>   StructBlock
%type <structure>   StructCore
%type <typealias>   TypedefBlock
%type <element>     ElementInstance

%%

// Starting rule return a valid program or an error
Start: Program {
     currentProgram->status=0;
   }
   | Program G_ERROR	{ fprintf( stderr
                     	  ,"ERROR before line %d of file %s\n"
			  ,currentProgram->numLine, (char*)currentProgram->name);
     currentProgram->status=-1;
   }
   ;

// A program is builded with a header Classes Function and global vars
Program:
   | Program Define
   | Program CppFileLine
   | Program ClasseEmpty
   | Program Ignore
   | Program Warning
   | Program FileHeader {
     // We goot an help text
     debugMsg (2, "Program Accept file help", currentProgram->name, currentProgram->help);
   }
   | Program AssertHeader {
     // Add got an implementation assert tag
     debugMsg (2, "Program Accept implement", currentProgram->name, currentProgram->implement);
   }
   | Program Doc {
     if (currentProgram->doc ==  NULL) {
       debugMsg (2, "Program Set Doc", currentProgram->name, *$2);
       currentProgram->doc = $2;
     } else {
       debugMsg (2, "Program Add Doc", currentProgram->name, *$2);
       *currentProgram->doc += "\n<br>";
       *currentProgram->doc += *$2;
       free ($2);
     }
   }
   | Program Classe {
       // Add current class in program
     debugMsg (2, "Program Add Class", currentProgram->name, currentClass->name);
     currentProgram->classes.append (currentClass);
     currentClass->owner = currentProgram;
   }
   | Program Enum {
     // Add got an enumeration object
     debugMsg (2, "Program Add enumeration", currentProgram->name, currentEnum->name);
     currentProgram->enums.append (currentEnum);
     currentEnum->owner = currentProgram;
   }
   | Program Function {
     // Add current Function in program
     if (currentMethod->valid) {
      debugMsg (2, "Program Add Function", currentProgram->name, currentMethod->name);
      currentProgram->functions.append (currentMethod);
      currentMethod->owner = currentProgram;
     } else {
      debugMsg (2, "Program Cancel Function", currentProgram->name, currentMethod->name);
     }
   }
   | Program Global {
     // Add current Global in program
     debugMsg (2, "Program Add Var");
     currentVars.clear();
   }
   | Program Typedef {
     // Add current typedef in program
     debugMsg (5, "Program Accept Typedef");
   }
   | Program Struct {
     // Add current typedef in program
     debugMsg (5, "Program Accept Struct");
   }
   | Program Union {
     // Add current typedef in program
     debugMsg (5, "Program Accept Union");
   }
   | Program G_EOL {
     // Ignore any unattended return line
     debugMsg (11, "Program Ignoring G_EOL");
   }
   | Program G_END {
     // Ignore any unattended ;
     debugMsg (11, "Program Ignoring G_END");
   }
   ;

// Exported Global Doc processing
Global: Doc PrefixedGlobalBlock {
     debugMsg (4, "Add Doc in Global", *$1);
     currentVars[0]->doc = $1;
   }
   | PrefixedGlobalBlock
   ;

PrefixedGlobalBlock: EXPOR_TAG VarsCore {
     int ind;
     debugMsg (4, "Prefixed Public Global");
     for (ind=0; ind < currentVars.size(); ind++) {
       currentVars[ind]->visibility = PROT_PUBLIC;
       currentVars[ind]->location   = LOC_GLOBAL;
       currentProgram->vars.append(currentVars[ind]);
     }
   }
   | STATIC_TAG VarsCore {
     int ind;
     debugMsg (4, "Prefixed Local Global");
     for (ind=0; ind < currentVars.size(); ind++) {
       currentVars[ind]->visibility = PROT_PRIVATE;
       currentVars[ind]->location   = LOC_GLOBAL;
       currentProgram->vars.append(currentVars[ind]);
     }
   }
   | PUBLIK_TAG VarsCore {
     int ind;
     debugMsg (4, "Explicit Public Global");
     for (ind=0; ind < currentVars.size(); ind++) {
       currentVars[ind]->visibility = PROT_PUBLIC;
       currentVars[ind]->location   = LOC_GLOBAL;
       currentProgram->vars.append(currentVars[ind]);
     }
   }
   | VarsCore {
     int ind;
     debugMsg (4, "Implicit Public Global");
     for (ind=0; ind < currentVars.size(); ind++) {
       currentVars[ind]->visibility = PROT_PUBLIC;
       currentVars[ind]->location   = LOC_GLOBAL;
       currentProgram->vars.append(currentVars[ind]);
     }
   }
   ;

// If any add doc to current function
Function:  Doc PrefixedFunctionBlock {
     debugMsg (4, "Add Doc in Function", *$1);
     currentMethod->doc = $1;
   }
   | PrefixedFunctionBlock
   ;

// A function can be PUBLIC prefixed
PrefixedFunctionBlock:  PUBLIK_TAG MethodCore {
      debugMsg (3, "Get Prefixed Public Function", currentMethod->name);
      currentMethod->visibility = PROT_PUBLIC;
      currentMethod->location   = LOC_GLOBAL;
      currentMethod->defaultHelp();
   }
   | MethodCore {
      debugMsg (3, "Get Public Function", currentMethod->name);
      currentMethod->visibility = PROT_PUBLIC;
      currentMethod->location   = LOC_GLOBAL;
      currentMethod->defaultHelp();
   }
   | STATIC_TAG MethodCore {
      debugMsg (3, "Get static Function", currentMethod->name);
      currentMethod->visibility = PROT_PRIVATE;
      currentMethod->location   = LOC_GLOBAL;
      currentMethod->defaultHelp();
    }
    ;

// if any add doc to classe
Classe: Doc ClasseBlock {
     debugMsg (4, "Add Doc in Class", *$1);
     currentClass->doc = $1;
    }
    | ClasseBlock
    ;

// We ignore any empty class
ClasseEmpty: CLASS_TAG G_WORD G_END {
     debugMsg (11, "Ignoring empty class", *$2);
     free ($2);
   }
   ;

// Classe have a prefix with CASS_TAG and follow with a name methods and vars
ClasseBlock: ClsHeader ClsExtends ClsCore G_END {
     // update current class name
     debugMsg (1, "Got Class Extended", currentClass->name);
   }
   | ClsHeader ClsCore G_END {
     // update current class name
     debugMsg (1, "Got Class", currentClass->name);
   }
   ;

// Class header set class name
ClsHeader: CLASS_TAG G_WORD {
       debugMsg (3, "Class Header", *$2);
       currentClass  = new Classes ();
       currentClass->name = *$2;
       currentVisibility = PROT_PRIVATE;
       free ($2);
   }
   ;

// Extension is a list of classes
ClsExtends: SUPER_TAG ClsSuper {
       // Add each super class in extension list
       currentClass->extends.append  ($2);
       debugMsg (2, "Extends First Class", $2->name);
    }
    | ClsExtends G_SEPARATOR ClsSuper {
       // Add each super class in extension list
       currentClass->extends.append ($3);
       debugMsg (2, "Extends Next Class", $3->name);
    }
    ;

// super class can have parameters
ClsSuper: ClsHeader {
       debugMsg (5, "Super Class Basic", $1->name);
       $$ = $1;
    }
    | ClsHeader OPEN_PRM Params CLOSE_PRM {
       debugMsg (5, "Super Class Extra PRM", $1->name);
       currentMethod->params.clear(); // ignore super class PRM
       $$ = $1;
    }
    ;

// Get super class name and attached tag if any
ClsHeader: PUBLIK_TAG G_WORD {
      Extends *extend;
      extend = new Extends();
      extend->name = *$2;
      extend->visibility=PROT_PUBLIC;
      $$  = extend;
      debugMsg (4, "Super Public  Class", *$2);
    }
    | G_WORD {
      Extends *extend;
      extend = new Extends();
      extend->name = *$1;
      extend->visibility=PROT_PRIVATE;
      $$  = extend;
      debugMsg (4, "Super Private Class", *$1);
    }
    ;

// Visibility is done of public / private section
ClsCore: OPEN_BRACE Section {
      debugMsg (4, "Section Start");
    }
    |OPEN_BRACE SECTION_TAG Section {
      debugMsg (4, "Section Prefixed Start");
    }
    | ClsCore SECTION_TAG Section {
      debugMsg (4, "Section Next Visibility");
    }
    | ClsCore CLOSE_BRACE {
      debugMsg (4, "Section Core End");
    }
    ;

Section: SectionElement  {
      debugMsg (5, "Section First Element");
    }
    | Section SectionElement {
      debugMsg (5, "Section Next Element");
    }
    ;

// A MethodCore section start with a private field
SectionElement: Method {
      debugMsg (4, "Section Add Method", currentMethod->name);
      currentClass->methods.append (currentMethod);
      currentMethod->owner = currentClass;
      currentMethod->visibility = currentVisibility;
    }
    | Var {
      int ind;
      debugMsg (4, "Section Add Var");
      for (ind=0; ind < currentVars.size(); ind++) {
        currentVars[ind]->visibility = currentVisibility;
        currentVars[ind]->owner      = currentClass;
        currentClass->vars.append (currentVars[ind]);
      }
      currentVars.clear();
    }
    | Enum {
      debugMsg (2, "Section Add enumeration", currentProgram->name, currentEnum->name);
      currentClass->enums.append (currentEnum);
      currentEnum->owner = currentClass;
    }
    | G_END {
      debugMsg (11, "Section Ignoring ;");
    }
    | Typedef {
      debugMsg (11, "Section Ignoring typedef");
    }
    | Ignore {
      debugMsg (11, "Section Ignoring block");
    }
    | CppFileLine {
      debugMsg (5, "Section update Cpp line");
    }
    | Warning
    ;

// If doc is present we attach it to first variable
Var: Doc VarBlock {
    debugMsg (4, "Add Doc in Var", *$1);
    currentVars[0]->doc = $1;
    }
    | VarBlock
    ;

VarBlock:
    PUBLIK_TAG VarsCore {
      int ind;
      debugMsg (5, "Public class Var");
      for (ind=0; ind < currentVars.size(); ind++) {
        currentVars[ind]->location   = LOC_GLOBAL;
        currentVars[ind]->visibility = PROT_PUBLIC;
      }
    }
    | STATIC_TAG VarsCore {
      int ind;
      debugMsg (5, "Static class Var");
      for (ind=0; ind < currentVars.size(); ind++) {
        currentVars[ind]->location   = LOC_STATIC;
        currentVars[ind]->visibility = PROT_PRIVATE;
      }
    }
    | VarsCore {
      int ind;
      debugMsg (5, "Instance class Var");
      for (ind=0; ind < currentVars.size(); ind++) {
        currentVars[ind]->location   = LOC_AUTO;
      }
    }
    ;

// A variable can be multi-instanciated ot standalone
VarsCore: VarType VarsList G_END {
      debugMsg (4, "Get Vars Core");
    }
    | VarType VarsList END_CODE {
      debugMsg (4, "Get Vars Core");
    }
    ;

// Define multi-instance variables
VarsList: VarInstance {
      currentVars.clear ();
      currentVars.append($1);
      debugMsg (5, "Var First instance",$1->type,$1->name);
    }
    | VarsList G_SEPARATOR VarInstance {
      currentVars.append($3);
      debugMsg (5, "Var Next instance",$3->type,$3->name);
    }
    ;

// A variable can be inited or be an array
VarInstance: VarDeclaration {
      debugMsg (5, "Var Not initialized",$$->type,$$->name);
      $$ =$1;
    }
    | VarDeclaration G_EQUAL {
      debugMsg (5, "Var Ignore Init",$$->type,$$->name);
      yycc_StartCode (0);
      $$ = $1;
    }
    | VarDeclaration Array {
      $$ = $1;
      $$->array = $2;
      debugMsg (5, "Var Is Array",$$->type,$$->name);
    }
    ;

// Define basic type + variable declaration
VarDeclaration: G_WORD {
      $$             = new Vars($1);
      $$->type       = currentType;
      free ($1);
      debugMsg (3, "Var Basic Instance ",$$->type,$$->name);
    }
    | ComplexType G_WORD {
      $$             = new Vars($2);
      $$->type       =  currentType;
      $$->type       += " ";
      $$->type       += *$1;
      free ($1);
      free ($2);
      debugMsg (3, "Var Instance Complex",$$->type,$$->name);
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
    MethodCore {
      debugMsg (3, "Get Ordinary Method", currentMethod->name);
      currentMethod->location = LOC_AUTO;
      currentMethod->defaultHelp();
    }
    | VIRTUAL_TAG  MethodCore {
      debugMsg (3, "Get Virtual  Method", currentMethod->name);
      currentMethod->location = LOC_VIRTUAL;
      currentMethod->defaultHelp();
    }
    | STATIC_TAG  MethodCore {
      debugMsg (3, "Get Static   Method", currentMethod->name);
      currentMethod->location = LOC_STATIC;
      currentMethod->defaultHelp();
    }
    ;

// A Method can have attached code or be a simple proto
MethodCore: MethodProto END_CODE {
      debugMsg (4, "Method As Attached Code", currentMethod->result,currentMethod->name);
    }
    | MethodProto G_END {
      debugMsg (4, "Method Is Prototype Only", currentMethod->result,currentMethod->name);
    }
    ;

// A Method as or as not input parameters
MethodProto: MethodHeader Params CLOSE_PRM {
      if (currentMethod->valid)
      {
        debugMsg (4, "Method With Prm", currentMethod->result,currentMethod->name);
        yycc_StartCode (0);
      } else {
        debugMsg (4, "Method was Canceled", currentMethod->result,currentMethod->name);
      }
    }
    |  MethodHeader  CLOSE_PRM {
      debugMsg (4, "Method No Prm", currentMethod->result,currentMethod->name);
      yycc_StartCode (0);
    }
    ;

// A methods can be virtual with or without return type as alway have parameters
MethodHeader: VarType MethodName {
      debugMsg (4, "Method Typed Header", currentMethod->result,currentMethod->name);
    }
    | MethodName   {
      currentMethod->result = "";
      debugMsg (4, "Method Untyped Header", currentMethod->result,currentMethod->name);
    }
    ;

MethodName: G_WORD OPEN_PRM {
      currentMethod = new Functions ($1);
      currentMethod->result   = currentType;
      free ($1);
      debugMsg (4, "Method Name Basic ", currentMethod->result,currentMethod->name);
    }
    | ComplexType G_WORD OPEN_PRM {
      currentMethod = new Functions ($2);
      currentMethod->result   = currentType;
      currentMethod->result   +=*$1;
      free ($1);
      free ($2);
      debugMsg (4, "Method Name Ptr",currentMethod->result,currentMethod->name);
    }
    ;

// typedef is an alias on a struct or on am enum
Typedef: Doc TypedefBlock G_END {
      if ($2 != NULL) {
        // dont alias to identical name
        if (strcmp ($2->name, $2->source)) {
        debugMsg (4, "Add Typedef + Doc Alias in program", $2->name,*$1);
        $2->doc = $1;
           currentProgram->typedefs.append ($2);
        }
      } else {
        debugMsg (11, "Ignoring typdef");
      }
    }
    | TypedefBlock G_END {
      if ($1 != NULL) {
        // dont alias to identical name
        if (strcmp ($1->name, $1->source)) {
        debugMsg (4, "Add Typedef Only Alias in program", $1->name);
        currentProgram->typedefs.append ($1);
       }
      } else {
        debugMsg (11, "Ignoring typdef");
      }
    }
    ;

TypedefBlock:  TYPEDEF_TAG COMPLEX_TYPE G_WORD G_WORD {
      *$2 += " ";
      *$2 += *$3;
      $$ = new Typedefs ($2,$4);
      debugMsg (4, "Aliasing Complex Type", $$->source, $$->name);
      free ($2);
      free ($3);
      free ($4);
    }
    | TYPEDEF_TAG COMPLEX_TYPE G_WORD GPtrs G_WORD {
      *$2 += " ";
      *$2 += *$3;
      *$2 += *$4;
      $$ = new Typedefs ($2,$5);
      debugMsg (4, "Aliasing Complex Ptr Type", $$->source,$$->name);
      free ($2);
      free ($3);
      free ($4);
      free ($5);
    }
    | TYPEDEF_TAG G_WORD G_WORD {
      $$ = new Typedefs ($2,$3);
      debugMsg (4, "Aliasing Basic Type", $$->source,$$->name);
      free ($2);
      free ($3);
    }
    | TYPEDEF_TAG G_WORD GPtrs G_WORD {
      *$2 += *$3;
      $$ = new Typedefs ($2,$4);
      debugMsg (4, "Aliasing Basic Ptr Type", $$->source,$$->name);
      free ($2);
      free ($3);
      free ($4);
    }
    | TYPEDEF_TAG EnumBlock G_WORD {
      debugMsg (4, "Program Add Internal Enum", currentEnum->name);
      currentProgram->enums.append (currentEnum);

      $$ = new Typedefs (&currentEnum->name,$3);
      debugMsg (4, "Aliasing Enum to Type", $$->source,$$->name);
      free ($3);
    }
    | TYPEDEF_TAG EnumHeader G_WORD {
      $$ = new Typedefs (&currentEnum->name,$3);
      debugMsg (4, "Aliasing Enum to Type", $$->source,$$->name);
      free ($3);
    }
    | TYPEDEF_TAG UnionBlock G_WORD {
      debugMsg (4, "Program Add Internal Union", $2->name);
      currentProgram->unions.append ($2);

      $$ = new Typedefs (&$2->name,$3);
      debugMsg (4, "Aliasing Enum to Union", $$->source,$$->name);
      free ($3);
    }
    | TYPEDEF_TAG StructBlock G_WORD {
      debugMsg (4, "Program Add Internal Struct", $2->name);
      currentProgram->structs.append ($2);

      $$ = new Typedefs (&$2->name,$3);
      debugMsg (4, "Aliasing Stuct", $$->source,$$->name);
      free ($3);
    }
    | TYPEDEF_TAG STRUCT_TAG G_WORD G_WORD {
      $$ = new Typedefs ($4, $3);
      debugMsg (4, "Aliasing Stuct", $$->source,$$->name);
      free ($3);
      free ($4);
    }
    | TYPEDEF_TAG STRUCT_TAG G_WORD GPtrs G_WORD {
      $$ = new Typedefs ($5, $3);
      $$->source += *$4;
      debugMsg (4, "Aliasing G_PTR Stuct", $$->source,$$->name);
      free ($3);
      free ($5);
    }
    | TYPEDEF_TAG G_WORD OPEN_PRM  {
      debugMsg (10, "Ignoring Function typedef", *$2);
      free ($2);
      yycc_StartCode (0);
      $$ = NULL;
    }
    ;

// Struct parse a complex type
Struct: Doc StructBlock G_END {
      debugMsg (4, "Add Struct + Doc in program", *$1);
      $2->doc = $1;
      currentProgram->structs.append ($2);
    }
    | StructBlock G_END {
      debugMsg (4, "Add Struct Only in program");
      currentProgram->structs.append ($1);
    }
    ;

// effectively parse structure bloc
StructBlock: StructCore CLOSE_BRACE {
      debugMsg (4, "Got Structure", $1->name);
      $$ = $1;
    }
    ;

// Create a new structure objet for each struct tag
StructCore: STRUCT_TAG OPEN_BRACE {
      static int ind =0;
      char   nom[50];
      sprintf (nom,"Struct_%s_%d", (char*)currentProgram->implement, ind++);
      debugMsg (2, "Start noName Struct",nom);
      $$ = new Structs (nom);
    }
    | STRUCT_TAG G_WORD OPEN_BRACE {
      debugMsg (2, "Start Named Struct",*$2);
      $$ = new Structs (*$2);
    }
    | StructCore Element  {
      int ind;
      debugMsg (4, "Add Elements in Struct", $1->name);
      for (ind=0; ind < currentElements.size(); ind++) {
        $1->elements.append (currentElements [ind]);
      }
      $$ = $1;
    }
    ;

// Union is a special struct
Union: Doc UnionBlock G_END {
      debugMsg (4, "Add Union + Doc in program", $2->name, *$1);
      $2->doc = $1;
      currentProgram->unions.append ($2);
    }
    | UnionBlock G_END {
      debugMsg (4, "Add Union Only in program", $1->name);
      currentProgram->unions.append ($1);
    }
    ;

// effectively parse union bloc
UnionBlock: UnionCore CLOSE_BRACE {
      debugMsg (4, "Got Union", $1->name);
      $$ = $1;
    }
    ;

// Create a new structure objet for each struct tag
UnionCore: UNION_TAG OPEN_BRACE {
      static int ind =0;
      char   nom[50];
      sprintf (nom,"Union_%s_%d", (char*)currentProgram->implement, ind++);
      debugMsg (2, "Start noName Union",nom);
      $$ = new Unions (nom);
    }
    | UNION_TAG G_WORD OPEN_BRACE {
      debugMsg (2, "Start Named Union",*$2);
      $$ = new Unions (*$2);
    }
    | UnionCore Element  {
      int ind;
      debugMsg (4, "Add Elements in Union", $1->name);
      for (ind=0; ind < currentElements.size(); ind++) {
        $1->elements.append (currentElements [ind]);
      }
      $$ = $1;
    }
    ;

// Each element can have doc
Element: Doc ElementBlock {
      debugMsg (4, "Element Doc Added");
      currentElements[0]->doc = $1;
    }
    | ElementBlock
    ;

// SubType are elmentary type of struct
ElementBlock:  VarType ElementInstances G_END {
       debugMsg (5, "Got Struct Element line");
    }
    ;

// A variable can be multi-instanciated ot standalone
ElementInstances: ElementInstance {
      debugMsg (4, "Get Element First intance");
      currentElements.clear  ();
      currentElements.append ($1);
    }
    | ElementInstances G_SEPARATOR ElementInstance {
      debugMsg (4, "Get Element Next intance");
      currentElements.append ($3);
    }
    ;

// Define basic type + variable declaration
ElementInstance: G_WORD {
      $$ = new Elements(*$1);
      free ($1);
      debugMsg (3, "Element Instance",$$->type,$$->name);
    }
    | G_WORD Array {
      $$ = new Elements(*$1);
      $$->array = $2;
      free ($1);
      debugMsg (3, "Element Array Instance",$$->type,$$->name);
    }
    | ComplexType G_WORD  {
      $$             = new Elements (*$2);
      $$->type       = currentType;
      $$->type      += *$1;
      free ($2);
      free ($1);
      debugMsg (3, "Element Array CompleType Instance",$$->type,$$->name);
    }
    | ComplexType G_WORD Array {
      $$             = new Elements (*$2);
      $$->type       = currentType;
      $$->type      += *$1;
      $$->array      = $3;
      free ($2);
      free ($1);
      debugMsg (3, "Element CompleType Instance",$$->type,$$->name);
    }
    ;

Define: DefineBlock {
      if ($1 != NULL) {
        debugMsg (5, "Define no doc",$1->name);
	$1->doc = NULL;
        currentProgram->defines.append ($1);
      }
    }
    | Doc DefineBlock {
     if ($2 != NULL) {
       debugMsg (4, "Define Add Doc",$2->name,*$1);
       $2->doc = $1;
       currentProgram->defines.append ($2);
     }
    }
    ;

DefineBlock: DEFINE_TAG G_WORD G_EOL {
      debugMsg (5,"Ignore define with no value", *$2);
      $$ = NULL;
    }
    | DEFINE_TAG G_WORD G_SEPARATOR {
      debugMsg (5,"Ignore define with a comma", *$2);
      yyclearin;
      yycc_IgnoreUntilEOL ();
      $$ = NULL;
    }
    | DEFINE_TAG G_WORD TYPEDEF_TAG {
      debugMsg (5,"Ignore define with embedded TYPEDEF", *$2);
      yyclearin;
      yycc_IgnoreUntilEOL ();
      $$= NULL;
    }
    | DEFINE_TAG G_WORD G_WORD {
      yyclearin;
      yycc_IgnoreUntilEOL ();
      $$ = new Defines ($2,$3);
      debugMsg (4, "Add New define value",$$->name,$$->value);
    }
    | DEFINE_TAG G_WORD COMPLEX_TYPE {
      debugMsg (4, "Ignore New define complex value",*$2,*$3);
      yyclearin;
      yycc_IgnoreUntilEOL ();
      $$ = NULL;
    }
    | DEFINE_TAG G_WORD OPEN_PRM {
      debugMsg (4, "Ignore define complex value",*$2);
      yyclearin;
      yycc_IgnoreUntilEOL ();
      yycc_ModeInitial();
      $$ = NULL;
    }
    ;

// add doc to enum if any
Enum: Doc EnumBlock G_END {
      debugMsg (4, "Add Doc in Enum", *$1);
      currentEnum->doc = $1;
    }
    | EnumBlock G_END
    ;

// Enumeratin can have a name or not
EnumBlock: EnumHeader OPEN_BRACE Values CLOSE_BRACE {
      debugMsg (4, "Got Enum", currentEnum->name);
    }
    ;

// Enum Tag Build Enum Struct
EnumHeader: ENUM_TAG {
      static int ind=0;
      char   name[50];
      currentEnum = new Enums();
      sprintf (name,"Enum_%s_%d",(char*)currentProgram->implement,ind++);
      currentEnum->name = name;
      debugMsg (3, "Enum Header NoNamed", name);
    }
    |  ENUM_TAG G_WORD {
      currentEnum = new Enums();
      currentEnum->name = *$2;
      debugMsg (3, "Enum Header Named", *$2);
    }
    ;

// We can have one or more value in each enum
Values: Value {
      debugMsg (5, "Got First enum value",$1->name,$1->value);
      currentEnum->values.append ($1);
    }
    | Values G_SEPARATOR Value {
      debugMsg (5, "Add New  enum value",$3->name,$3->value);
      currentEnum->values.append ($3);
    }
    | Values G_SEPARATOR {
      debugMsg (5, "Last comma ignored");
    }
    ;

Value: Doc ValueBlock {
      debugMsg (4, "Enum value Add Doc");
      $2->doc = $1;
      $$ = $2;
    }
    | ValueBlock {
      $$  = $1;
    }
    ;

ValueBlock:  G_WORD {
      // Enum as no value we provide a default value
      debugMsg (5, "Get Last Enum slot", *$1, NOT_SET);
      $$ = new Values (*$1, "");
    }
    | G_WORD G_EQUAL GWords {
      // Build a new constance/value relation
      debugMsg (5, "Got Enum value", *$1, *$3);
      $$ = new Values (*$1, *$3);
    }
    | G_WORD G_EQUAL OPEN_PRM GWords CLOSE_PRM {
      // Build a new constance/value relation
      debugMsg (5, "Got Enum value", *$1, *$4);
      $$ = new Values (*$1, *$4);
    }
    ;

// Doc is a block doc + some empty lines
Doc: DOC_BLOCK {
      $$ = $1;
    }
    ;

// Params is a list of word and can be empty
Params: Param {
      if (strcmp ("void", (char*)$1->type)) {
        debugMsg (4, "Add First Param,", $1->type);
        currentMethod->params.append ($1);
      } else {
        debugMsg (5, "Ignore void param,", $1->type);
      }
    }
    | Params G_SEPARATOR Param {
      // ignore params if void
      debugMsg (4, "Add Next Param,", $3->type);
      currentMethod->params.append ($3);
    }
    ;

// Var header define variable list type
VarType: G_WORD {
     currentType = *$1;
     debugMsg (3, "Get Vars Basic Type",currentType);
   }
   | COMPLEX_TYPE G_WORD {
     currentType =  *$1;
     currentType += " ";
     currentType += *$2;
     free ($1);
     free ($2);
     debugMsg (3, "Get Vars Complex Type",currentType);
   }
   | CONST_TYPE G_WORD {
     currentType =  "const ";
     currentType += *$2;
     free ($1);
     free ($2);
     debugMsg (3, "Get Vars Const Type",currentType);
   }
   | ENUM_TAG G_WORD {
     currentType =  "enum ";
     currentType += *$2;
     free ($2);
     debugMsg (3, "Get Vars Enum Type",currentType);
   }
   | STRUCT_TAG G_WORD {
     currentType =  "struct ";
     currentType += *$2;
     free ($2);
     debugMsg (3, "Get Vars Struct Type",currentType);
   }
   | UNION_TAG G_WORD {
     currentType =  "union ";
     currentType += *$2;
     free ($2);
     debugMsg (3, "Get Vars Union Type",currentType);
   }
   | TypedefBlock {
     debugMsg (3, "Get Vars Typedef Type Add to Prog",currentType);
     currentProgram->typedefs.append ($1);
   }
   | StructBlock {
     currentType = $1->name;
     currentProgram->structs.append ($1);
     debugMsg (3, "Get Vars Struct Type Add to Prog",currentType);
   }
   | EnumBlock {
     currentType = currentEnum->name;
     currentProgram->enums.append (currentEnum);
     debugMsg (3, "Get Vars Enum Type Add to Prog",currentType);
   }
   | UnionBlock {
     currentType = $1->name;
     currentProgram->unions.append ($1);
     debugMsg (3, "Get Vars Union Type Add to prog",currentType);
   }
   ;

// A paramter can have a name
Param: VarType {
      $$ = new Params (&currentType);
      $$->type = currentType;
      $$->name = "NoName";
      debugMsg (5, "Get NoName Param",$$->type,$$->name);
   }
   |  VarType G_WORD {
      $$ = new Params (&currentType);
      $$->type = currentType;
      $$->name = *$2;
      free ($2);
      debugMsg (5, "Get Named Param",$$->type,$$->name);
   }
   |  VarType ComplexType {
      $$ = new Params (&currentType);
      $$->type = currentType;
      $$->type += " ";
      $$->type += *$2;
      $$->name = "NoName";
      free ($2);
      debugMsg (5, "Get Complex NoName Param",$$->type,$$->name);
   }
   |  VarType ComplexType G_WORD {
      $$ = new Params (&currentType);
      $$->type = currentType;
      $$->type += " ";
      $$->type += *$2;
      $$->name = *$3;
      free ($2);
      free ($3);
      debugMsg (5, "Get Complex Named Param",$$->type,$$->name);
   }
   |  VarType ComplexType G_WORD OPEN_BRAKET CLOSE_BRAKET {
      $$ = new Params (&currentType);
      $$->type = currentType;
      $$->type += "* ";
      $$->type += *$2;
      $$->name = *$3;
      free ($2);
      free ($3);
      debugMsg (5, "Get Complex Named Param",$$->type,$$->name);
   }
   |  VarType OPEN_PRM GPtrs G_WORD CLOSE_PRM OPEN_PRM  {
      currentMethod->valid=FALSE;
      yycc_IgnoreUntilBalancedBrace (1);
      debugMsg (11, "Ignoring function with FUNC as param");
   }
   ;


// Get assert implementation name
AssertHeader: IMPLEMENT_TAG OPEN_PRM G_WORD CLOSE_PRM  {
      currentProgram->implement= *$3;
      currentProgram->assertLine= currentProgram->numLine;
      debugMsg (5, "assert implementation", currentProgram->implement);
      yycc_IgnoreUntilEOL();  // restart Lex searching
    } | IMPLEMENT_TAG G_LINE {
      currentProgram->implement= *$2;
      currentProgram->assertLine= currentProgram->numLine;
      debugMsg (5, "assert implementation", currentProgram->implement);
    }
    ;
// Get program name and small help text
FileHeader:  FILE_TAG G_LINE {
      currentProgram->help =  *$2;
      debugMsg (5, "PrgName Help", currentProgram->help);
    }
    ;

// CPP linetag reset linenumber and filename for error message only
CppFileLine: LINE_TAG G_WORD {
      if (strcmp (*$2, currentProgram->ownerName)) {
        debugMsg (2, "CppFileLine", *$2);
        currentProgram->ownerName = *$2;
      }
      currentProgram->ownerLine = $1;
      yycc_IgnoreUntilEOL();
    }
    ;

// Warning are pressed as frist level debug command
Warning: WARNING_TAG G_LINE {
  if (verbose) {
    fprintf (stderr, "********************************************************\n");
    fprintf (stderr, "| %s\n", (char*)*$2);
    fprintf (stderr, "********************************************************\n");
  };
  free ($2);
}

// Ignore template
Ignore: IgnoreBlock
  | VarType IgnoreBlock {
    currentType = "";
  }
  ;

// Template can be prefixed but many stuf
IgnoreBlock: IGNORE_TAG {
    debugMsg (11, "Ignoring Block");
    yyclearin;
    yycc_IgnoreUntilEOB(0);
  }
  ;

// Take only number from array
Array: OPEN_BRAKET Number CLOSE_BRAKET {
    $$ = $2;
  }
  | OPEN_BRAKET CLOSE_BRAKET {
    $$ = 0;
  }
  ;

// GPtrs is at least one pointer
GPtrs: G_PTR {
    $$ =new McString("*");
  }
  | GPtrs G_PTR {
    $$  =   $1;
    *$$  += "*";
  }
  ;

// A type can be simple or complex
ComplexType: GPtrs {
      $$ = $1;
      debugMsg (5, "Ptr Type",*$$);
    }
    | COMPLEX_TYPE {
      $$ = $1;
      debugMsg (5, "Complex Type",*$$);
    }
    | GPtrs COMPLEX_TYPE {
      $$ = $1;
      *$$ += *$2;
      free ($2);
      debugMsg (5, "Complex Ptr Type",*$$);
    }
    ;

// GWords is at least one pointer
GWords: G_WORD {
    $$ = $1;
  }
  | GWords G_WORD {
    $$   =   $1;
    *$$  += *$2;
    free ($2);
  }
  ;

// Compute number if any
Number: G_NUM {
    debugMsg (4, "Get Basic Number");
    $$ = $1;
  }
  | Number G_OPERATOR G_NUM {
    switch ($2) {
      case '+':
        $$ = $$ + $2;
        break;
      case '-':
        $$ = $$ - $2;
        break;
      case '*':
        $$ = $$ * $2;
        break;
      case '/':
        $$ = $$ / $2;
        break;
    }
    $$ = $1;
  }
  ;
