%{

/*
   wx2000-2.x -- Weather Data Logger Extration Program (ws2000 model)

   Copyright (C) 2005, Fulup Ar Foll
   Copyright (C) 2000,2001,2002 Friedrich Zabel
   with Modifications by Anneke Sicherer-Roetman (sicherer@sichemsoft.nl)

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   $Id: wx2000.c v 1.1 27 Oct 2002 zabel $

 * Modification History
 * --------------------
 * 01a,04-JUL-95, Fulup, Written from wx20001.1 version.
 */


/*
 *	includes
 */

#include "libFrontendTcl.h"
#include "yaccFrontendTcl.h"

LOCAL  int yySavedMode, yyPreCommentMode;
LOCAL  int yyBrace=0;
LOCAL  void debugMsg (int level , char *token) {
  if ((debugLevel>=level) || (-1*debugLevel==level)) {
     if (asDebugYacc) {
        printf ("\n");
        asDebugYacc = FALSE;
     }

     if (yytcl_text [yytcl_leng-1] == '\n')  yytcl_text [yytcl_leng-1] = '\0';
     fprintf(stderr, "%3d flex (%2d) [%3d] %-15s =|%s|\n"
           ,level,YYSTATE,currentProgram->numLine,token,yytcl_text);
  }
} // end debugMsg
%}

/* define few useful macro */
blank     [ \t]*
separator {blank}:{blank}
comment   ("//"|";#"|";;"){blank}
newLine   \n
alphaNum  [0-9A-Za-z\[\]\*~\._]+

/* %s STartMode %x Exclusive startmode */
%x InCode

%%

<INITIAL>^{blank}package{blank} {
 debugMsg (7,"PACKAGE_TAG");
 return PACKAGE_TAG;
}

<INITIAL>^{blank}jClassImport{blank} {
 debugMsg (7,"IMPORT_TAG");
 return IMPORT_TAG;
}

<INITIAL>^{blank}jClassModule{blank} {
 debugMsg (7,"IMPLEMENT_TAG");
 return IMPLEMENT_TAG;
}

<INITIAL>^{blank}(array){blank} {
  // currentelly ignore any non object syntaxe
  debugMsg (10,"Ignoring array");
}

. {
  // only processed single character is brace
  switch (yytcl_text[0]) {
    case '{':             /* } for editor matching */
      debugMsg (6,"OPEN_BRACE");
      return OPEN_BRACE;
    case '}':
      {
        debugMsg (6,"CLOSE_BRACE");
        return CLOSE_BRACE;
      }
      break;
    default: ;            /* Ignore */
  }  // Reset previous mode when end of code founded
}

{alphaNum} {
  // Generic rules for a stripped word value
  debugMsg (8,"G_WORD");
  yytcl_lval.dString = new McString (yytcl_text);
  return G_WORD;
}

"## " {
  // get javaDoc start tag save current mode and return all word until end of doc
  McString *doc =  new (McString);
  int c1=0;
  int c2=yyinput();
  if (c2 == '#') c2 = '*';

  debugMsg (8,"DOC_BLOCK start");

  for (;;) {
    // check we are not facing end of file and end of comment
    if (c2 == EOF) break;
    if (c1 == '*' && c2 == '*') break;

    // ignore any "
    if (c2 == '"') c2 = ' ';

    c1 = c2;

    // read new character from lex flow
    c2 = yyinput();
    if ((c2 == '#') && (c1 != '\\')) c2 = '*';
    // don't forget counting line for yacc error message
    if (c2 == '\n') currentProgram->numLine ++;


    // add character in current block doc
    *doc += c1;
  }
  *doc += '/';

  yytcl_lval.dString = doc;
  debugMsg (8,"DOC_BLOCK end");
  return DOC_BLOCK;
}

<INITIAL,InCode>{newLine} {
  // Update current line counter
  debugMsg (9,"Ignore eol");
  currentProgram->numLine ++;
}

#[ \t]+.*{newLine} {
  // Ignore jTcl comment
  debugMsg (9,"Ignoring Tcl comment");
  currentProgram->numLine ++;
  }

<InCode>. {
  // In Code we count {} in order closing InCode mode at block end
  switch (yytcl_text[0]) {
    case '{':             /* } for editor matching */
      debugMsg (9,"Ignore open brace InCode");
      yyBrace ++;
      break;
    case '}':
      yyBrace --;
      if (yyBrace == 0)
      {
        BEGIN  yySavedMode;
        debugMsg (7,"End Code END_CODE");
        return END_CODE;
      } else {
        debugMsg (9,"Ignore close brace InCode");
      }
      break;
    default: ;            /* Ignore */
  }  // Reset previous mode when end of code founded
}

^{blank}proc{blank} {
  // We got an exported variable
  debugMsg (6,"EXPOR_TAG + set InGlobal");
  return PROC_TAG;
}

^{blank}class{blank} {
  // We got a class we allocate object and add it in program list
  debugMsg (6,"CLASS_TAG");
  return CLASS_TAG;
}

{blank}extends{blank} {
  // we got a class extention tag
  debugMsg (6,"EXTENDS_TAG");
  return EXTENDS_TAG;
}

{blank}public{blank} {
  // We got public tag inside class
  debugMsg (6,"PUBLIK_TAG");
  return PUBLIK_TAG;
}

{blank}private{blank} {
  // We got public tag inside class
  debugMsg (6,"PRIVATE_TAG");
  return PRIVATE_TAG;
}

{blank}static{blank} {
  // Got a static variable or function
  debugMsg (6,"STATIC_TAG");
  return STATIC_TAG;
}

{blank}set{blank} {
  // We got an instance var
  debugMsg (6,"VAR_TAG");
  return STATIC_TAG;
}

%%

// Just ignore any piece of code we could find out
PUBLIC void yytcl_ModeInCode (int start) {
  debugMsg (7,"Start Code");
  yySavedMode = YYSTATE;
  BEGIN InCode;
  yyBrace = start;
}

// Allows yacc to replace lex in INITIAL mode
PUBLIC void yytcl_ModeInitial ()
{
   debugMsg (7,"Reset Initial mode");
   BEGIN INITIAL;
}

// Ignore until endofline
PUBLIC void yytcl_IgnoreUntilEOL ()
{
  debugMsg (12,"Ignore until end of line");
  int c1=0;
  int c2=yyinput();

  // if we already point on endofline update counters
  if (c2 == '\n') {
      currentProgram->numLine   ++;
      currentProgram->ownerLine ++;
  }

  for (;;) {
    // check we are not facing and continuation \
    if (c2 == EOF) break;
    if (c1 != '\\' && c2 == '\n') break;
    c1 = c2;
    // read new character from lex flow
    c2 = yyinput();
    // don't forget counting line for yacc error message
    if (c2 == '\n') {
       currentProgram->numLine   ++;
       currentProgram->ownerLine ++;
    }
  }
}

// Allows yacc to replace lex in INITIAL mode
PUBLIC void yytcl_IgnoreUntilEOB (int brace)
{
  debugMsg (12,"Search end of block");
  int c1=0;
  int c2=yyinput();

  for (;;) {
    // check we are not facing and continuation
    if (c2 == EOF) break;

    // compute brace in order findinf embedded code
    if (c2 == '{') brace ++;
    if (c2 == '}') brace --;

    // leave at ; and avoid protected \;
    if (c1 != '\\' && c2 == '}' && brace == 0) break;
    c1 = c2;

    // read new character from lex flow
    c2 = yyinput();

    // don't forget counting line for yacc error message
    if (c2 == '\n') {
       currentProgram->numLine   ++;
       currentProgram->ownerLine ++;
    }
  }
  debugMsg (12,"Got end of block");
} // yytcl_IgnoreUntilEOB

extern "C" {
int	yytcl_wrap()	{ return 1 ; }
};




