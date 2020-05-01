%{

/**
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
 *      Source      : $Source: /Master/jWrap/frontend/cc/lexFrontendCc.lex,v $
 *
 * Modification History
 * --------------------
 * 01a,18apr98,Fulup moved to new tree
 * 01a,06feb98,Fulup,written from jDoc & doc++ & swig and many others.
 */

/*
 *	includes
 */

#include "libFrontendCc.h"
#include "yaccFrontendCc.h"


LOCAL  int yySavedMode, yyPreCommentMode;
LOCAL  int yyBrace=0;
LOCAL  int yyCheckEOL = FALSE;

// remove leading ans trailling space from a string
LOCAL char * strip (char *token) {
 int ind;
 int start=0;

 // jump over any space or tab characters
 for (ind=0; token [ind] != 0; ind++) {
   if ((token [ind] != ' ') && (token [ind] != '\t')) break;
 }
 if (token [ind] != '\0') start = ind;

 // clean the end
 for (ind=strlen (&token [start])-1
     ; ((token [ind] == ' ') || (token [ind] == '\t'))
     ; ind--)
 ;
 token [ind] = '\0';

 return (&token [ind]);
} // end strip

LOCAL  void debugMsg (int level , const char *token)
{
  if ((debugLevel>=level) || (-1*debugLevel==level)) {
     if (asDebugYacc) {
        printf ("\n");
        asDebugYacc = FALSE;
     }

     if (yycc_text [yycc_leng-1] == '\n')  yycc_text [yycc_leng-1] = '\0';
     printf("%3d flex (%2d) [%3d] %-15s =|%s|\n"
           ,level,YYSTATE,currentProgram->numLine,token,yycc_text);
  }
} // end debugMsg

%}

/* define few usefull macro */
blank     [ \t]*
comment   ("//"|";#"|";;"){blank}
newLine   "\n"
alphaNum  [0-9A-Za-z~\._&\"]+
space     [ \t]
separator [\t \{\n\m]

/* %s STartMode %x Exclusive startmode */
%s InComment
%s InIgnore
%s InCode
%x InLineMode
%x InNumeric

%%

<INITIAL>{blank}#{blank}assert{blank}(implement|interface){blank} {
  // CPP Assert implement is use for not including class proto when compiling implementation
  debugMsg (6,"IMPLEMENT_TAG");
  return IMPLEMENT_TAG;
}

<INITIAL>^{blank}# {
  // CPP ignore any preprocessing directive
  debugMsg (9,"Ignore Preprocessing directive");
  yycc_IgnoreUntilEOL();
}

<INITIAL>"#abort" {
  // CPP use to debug and abort parsing
  fprintf (stderr,"##### Abort instruction founded ####\n");
  return G_ERROR;
}

<INITIAL>{blank}#{blank}warning {
  // CPP
  debugMsg (8,"WARNING_TAG");
  yySavedMode = YYSTATE;
  BEGIN InLineMode;
  return WARNING_TAG;
}

<INITIAL>#{blank}[0-9]+{blank} {
  // CPP Go got a CPP line number header
  debugMsg (8,"LINE_TAG");
  (void)sscanf (yycc_text,"# %d",&yycc_lval.intVar);
  return LINE_TAG;
}

<INITIAL>{blank}#{blank}include{blank} {
  // CPP We check first include line because it should be after assert
  if (currentProgram->firstInclude <0) {
     debugMsg (6,"FirstInclude");
     currentProgram->firstInclude = currentProgram->numLine;
  } else {
     debugMsg (10,"Ignoring Include");
  }
  yycc_IgnoreUntilEOL();
}

<INITIAL>{blank}#{blank}define{blank} {
  // CPP Define as a program special enum
  debugMsg (6,"DEFINE_TAG");
  yyCheckEOL = TRUE;
  return DEFINE_TAG;
}

<INITIAL>{blank}#{blank}define{blank}{alphaNum}\( {
  // CPP Define as a program special enum
  debugMsg (10,"ignoring Macro with param");
  yycc_IgnoreUntilEOL ();
}

<INITIAL>^{blank}"class"{separator} {
  // SECTION We got a class we allocate object and add it in program list
  yyless (sizeof ("class")-1);
  debugMsg (6,"CLASS_TAG");
  return CLASS_TAG;
}

<INITIAL>^{blank}"interface"{separator} {
  // SECTION We got a class we allocate object and add it in program list
  yyless (sizeof ("interface")-1);
  debugMsg (6,"CLASS_TAG");
  return CLASS_TAG;
}

<INITIAL>{blank}public{blank}: {
  // SECTION We got public tag inside class
  debugMsg (6,"SECTION_TAG");
  yycc_lval.prot = PROT_PUBLIC;
  currentVisibility =  yycc_lval.prot;
  return SECTION_TAG;
}

<INITIAL>{blank}private{blank}: {
  // SECTION We got public tag inside class
  debugMsg (6,"SECTION_TAG");
  yycc_lval.prot = PROT_PRIVATE;
  currentVisibility =  yycc_lval.prot;
  return SECTION_TAG;
}

<INITIAL>{blank}protected{blank}: {
  // SECTION We got protected tag inside class
  debugMsg (6,"SECTION_TAG");
  yycc_lval.prot = PROT_PROTECTED;
  currentVisibility =  yycc_lval.prot;
  return SECTION_TAG;
}

<INITIAL>"enum"{separator} {
  // TYPE enumeration
  yyless (sizeof ("enum")-1);
  debugMsg (6,"ENUM_TAG");
  return ENUM_TAG;
}

<INITIAL>"typedef"{separator} {
  // TYPE typedef
  yyless (sizeof ("typedef")-1);
  debugMsg (3,"TYPEDEF_TAG");
  return TYPEDEF_TAG;
}

<INITIAL>"struct"{separator} {
  // TYPE struct
  yyless (sizeof ("struct")-1);
  debugMsg (3,"STRUCT_TAG");
  return STRUCT_TAG;
}

<INITIAL>"union"{separator} {
  // TYPE Union
  yyless (sizeof ("union")-1);
  debugMsg (3,"UNION_TAG");
  return UNION_TAG;
}

<INITIAL>^{blank}(static|STATIC|LOCAL|RESTRICTED){space} {
  // TYPE We got static tag
  debugMsg (6,"STATIC_TAG");
  return STATIC_TAG;
}

<INITIAL>^{blank}(PUBLIC|EXPORT|IMPORT|extern|EXTERN){space} {
  // TYPE We got public tag
  debugMsg (6,"PUBLIK_TAG");
  return PUBLIK_TAG;
}

<INITIAL>{blank}public{space} {
  // TYPE We got public tag
  debugMsg (6,"PUBLIK_TAG");
  return PUBLIK_TAG;
}

<INITIAL>{blank}virtual{blank} {
  // TYPE We got public tag inside class
  debugMsg (6,"VIRTUAL_TAG");
  return VIRTUAL_TAG;
}

<INITIAL>{alphaNum}"::"{alphaNum} {
  // TYPE Get valid method name
  debugMsg (11,"G_WORD DoubleDot");
   yycc_lval.dString = new McString (yytext);
  return G_WORD;
}

<INITIAL>long{blank}int[ \t] {
  // TYPE some people cut long and int
   debugMsg (8,"G_WORD");
   yycc_lval.dString = new McString ("long");
   return G_WORD;
}

<INITIAL>"&"{blank}{alphaNum} {
  // TYPE some people cut & and var name
   debugMsg (8,"G_WORD &");
   yycc_lval.dString = new McString (yytext);
   return G_WORD;
}

<INITIAL>"unsigned"{separator} {
   // TYPE Handle complex type
   yyless (sizeof ("unsigned")-1);
   debugMsg (8,"COMPLEX_TYPE");
   yycc_lval.dString = new McString (yycc_text);
   return COMPLEX_TYPE;
}

<INITIAL>(const|CONST){separator} {
   // TYPE Handle complex type
   yyless (sizeof ("const")-1);
   debugMsg (8,"CONST_TYPE");
   yycc_lval.dString = new McString (yycc_text);
   return CONST_TYPE;
}

<INITIAL>. {
  // GENERIC Sigle char processing
  switch (yycc_text[0]) {
    case '*': {
      debugMsg (6,"G_PTR");
      return G_PTR;
    }
    case ':': {
      debugMsg (6,"SUPER_TAG");
      return SUPER_TAG;
    }
    case  ';': {
      debugMsg (8,"G_END");
      return G_END;
    }
    case  ',': {
      debugMsg (8,"G_SEPARATOR");
      return G_SEPARATOR;
    }
    case  '=': {
      debugMsg (8,"G_EQUAL");
      return G_EQUAL;
    }
    case '(': {
      debugMsg (8,"OPEN_PRM");
      return OPEN_PRM;
    }
    case ')': {
      debugMsg (8,"CLOSE_PRM");
      return CLOSE_PRM;
    }
    case '{': {
      debugMsg (7,"OPEN_BRACE");
      return OPEN_BRACE;
    }
    case '}': {
      debugMsg (7,"CLOSE_BRACE");
      return CLOSE_BRACE;
    }
    case '[': {
      debugMsg (7,"OPEN_BRAKET");
      yySavedMode = YYSTATE;
      BEGIN InNumeric;
      return OPEN_BRAKET;
    }
    case ']': {
      debugMsg (7,"CLOSE_BRAKET");
      return CLOSE_BRAKET;
    }
    case ' ':
    case '\t':
    {
      debugMsg (15,"Ignoring Space");
      break;
    }
    case '\r':
    {
      debugMsg (15,"Ignoring CTRL-M [WinDos=>Burk!!!]");
      break;
    }
    // ignore all other characters
    default:
      debugMsg (9,"Single Char Word");
      yycc_lval.dString = new McString (yycc_text);
      return G_WORD;
  }
}

<INITIAL>{alphaNum} {
  // GENERIC rules for a stripped word value
  debugMsg (8,"G_WORD");
  yycc_lval.dString = new McString (yycc_text);
  return G_WORD;
}

<InNumeric>[0-9]+ {
  // NUMBER process basic values
  debugMsg (7,"G_NUM");
  sscanf  (yycc_text,"%d", &yycc_lval.intVar);
  return G_NUM;
}

<InNumeric>[\+\-\*\/] {
  // NUMBER process basic values
  debugMsg (7,"G_OPERATOR");
  yycc_lval.intVar = yycc_text [0];
  return G_OPERATOR;
}

<InNumeric>\] {
  // NUMBER End of Number
  debugMsg (6,"CLOSE_BRAKET");
  BEGIN yySavedMode;
  return CLOSE_BRAKET;
}


{newLine} {
  // GENERIC Update current line counter
  if (yyCheckEOL) {
    yyCheckEOL = FALSE;
    debugMsg (8,"G_EOL");
    currentProgram->numLine   ++;
    currentProgram->ownerLine ++;
    return G_EOL;
  }
  debugMsg (19,"Ignore eol");
  currentProgram->numLine   ++;
  currentProgram->ownerLine ++;
}

<InLineMode>.*{newLine} {
  // LINE return all the end of line to Yacc
  currentProgram->numLine   ++;
  currentProgram->ownerLine ++;
  // remove any new line or ctrl-M [dos!!!]
  if (yycc_text [yycc_leng-2] == '\r') yycc_text [yycc_leng-2] = '\0';
  if (yycc_text [yycc_leng-1] == '\n') yycc_text [yycc_leng-1] = '\0';
  debugMsg (7,"G_LINE");
  yycc_lval.dString = new McString (yycc_text);
  BEGIN yySavedMode;
  return G_LINE;
}

"/**"([^*]) {
  // COMMENT get javaDoc start tag save current mode and return all word until end of doc
  McString *doc =  new (McString);
  int c1=0;
  int c2=yytext[3];

  // if already in comment ignore
  if  (YYSTATE == InComment) goto ignoreDoc;

  debugMsg (8,"DOC_BLOCK start");

  if (c2 == '\n') {
     currentProgram->numLine   ++;
     currentProgram->ownerLine ++;
  }

  for (;;) {
    // check we are not facing end of file and end of comment
    if (c2 == EOF) break;
    if (c1 == '*' && c2 == '/') break;
    c1 = c2;
    // read new character from lex flow
    c2 = yyinput();

    // ignore \m (hugly dos)
    if (c2 == '\r') continue;

    // don't forget counting line for yacc error message
    if (c2 == '\n') {
       currentProgram->numLine   ++;
       currentProgram->ownerLine ++;
    }

    // ignore any not basic char double character
    if ((c1 == c2 ) && (c1 < '0')) continue;

    // add character in current block doc
    *doc += c1;
  }

  debugMsg (8,"DOC_BLOCK end");
  yycc_lval.dString = doc;
  return DOC_BLOCK;

 ignoreDoc:
   debugMsg (10,"DOC_BLOCK ignored");
}

\/\/.*{newLine} {
  // COMMENT Ignore C++ comment
  currentProgram->numLine ++;
  currentProgram->ownerLine ++;
  debugMsg (12,"Ignoring c++ comment");
}

"/*" {
  // COMMENT remove C comment but check for file: help line
  debugMsg (11,"Start comment");
  yyPreCommentMode = YYSTATE;
  BEGIN InComment;
  }

<InComment>{blank}(Object|Help){blank}:{blank} {
  // COMMENT Search Program name
  debugMsg (6,"FILE_TAG");
  yySavedMode = YYSTATE;
  BEGIN  InLineMode;
  return FILE_TAG;
}

<InComment>{blank}(Interface|Implement){blank}:{blank} {
  // COMMENT Search Program name
  debugMsg (6,"IMPLEMENT_TAG");
  yySavedMode = YYSTATE;
  BEGIN  InLineMode;
  return IMPLEMENT_TAG;
}

<InComment>. {
  // In comment we just ignore any signle char
}

<InComment>"*/" {
  // COMMENT got end comment tag
  debugMsg (11,"End comment (all ignored)");
  BEGIN yyPreCommentMode;
}

<InCode>. {
  // IGNORE In Code we count {} in order closing InCode mode at block end
  switch (yycc_text[0]) {
    case ';':
     if (yyBrace == 0) {
      BEGIN  yySavedMode;
      debugMsg (7,"End Mono instruction Code G_END");
      return G_END;
     }
     break;
    case '{':             /* } for editor matching */
      debugMsg (12,"Ignore open brace InCode");
      yyBrace ++;
      break;
    case '\\':              /* ignore next character what ever it is */
      debugMsg (12,"Ignore \\ and next character");
      yyinput();
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
    default:             /* Ignore */
      debugMsg (15,"Ignoring");

  }  // Reset previous mode when end of code founded
}

<INITIAL>{blank}#{blank}assert{blank}jWrap{blank} {
  // IGNORE  User can stop/restart parsing with no influence on Yacc
  debugMsg (2,"JWrap Ignore Start");
  yySavedMode= YYSTATE;
  BEGIN InIgnore;
}

<InIgnore>jWrap{blank}"("{blank}process{blank}")" {
  // IGNORE
  debugMsg (2,"jWrap Ignore End");
  BEGIN yySavedMode;
}

<INITIAL>"<".+">" {
  // IGNORE any C++ template
  debugMsg (6,"IGNORE_TAG");
  return IGNORE_TAG;
}

<INITIAL>[&\*=/+\-! \t]+(operator|friend) {
  // IGNORE we got an inline proc and ingore ir
  debugMsg (8,"IGNORE_TAG");
  return IGNORE_TAG;
}

<INITIAL>{blank}(inline|friend){blank} {
  // IGNORE we got an inline proc and ingore ir
  debugMsg (10,"Ignoring Inline");
  yycc_IgnoreUntilEOB (0);
}

%%

// Allows yacc to replace lex in INITIAL mode
PUBLIC void yycc_ModeInitial ()
{
   debugMsg (7,"Reset Initial mode");
   BEGIN INITIAL;
}

PUBLIC void yycc_ModeRestore ()
{
   debugMsg (7,"Reset Saved mode");
   BEGIN yySavedMode;
}


PUBLIC void yycc_ModeSet (int mode)
{
   debugMsg (7,"Reset mode");
   BEGIN mode;
}

PUBLIC int yycc_ModeGet ()
{
   debugMsg (7,"Get mode");
   return yySavedMode;
}

PUBLIC void yycc_StartCode (int brace) {
  // Just ignore any piece of code we could find out
  debugMsg (7,"Start Code");
  yySavedMode = YYSTATE;
  BEGIN InCode;
  yyBrace = brace;
}

// Ignore until endofline
PUBLIC void yycc_IgnoreUntilEOL ()
{
  debugMsg (12,"Ignore until end of line");
  int c1=0;
  int c2=yyinput();

  // reset line eol check if any
  yyCheckEOL = FALSE;

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
PUBLIC void yycc_IgnoreUntilEOB (int brace)
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
    if (c1 != '\\' && c2 == ';' && brace == 0) break;
    c1 = c2;

    // read new character from lex flow
    c2 = yyinput();

    // don't forget counting line for yacc error message
    if (c2 == '\n') {
       currentProgram->numLine   ++;
       currentProgram->ownerLine ++;
    }
  }
} // yycc_IgnoreUntilEOB

// Allows yacc to replace lex in INITIAL mode
PUBLIC void yycc_IgnoreUntilBalancedBrace (int brace)
{
  debugMsg (12,"Search separator");
  int c1=0;
  int c2=yyinput();

  for (;;) {
    // check we are not facing and continuation
    if (c2 == EOF) break;

    // compute brace in order findinf embedded code
    if (c2 == '(') brace ++;
    if (c2 == ')') brace --;

    // leave at ; and avoid protected \;
    if (brace == 0) {
      break;
    }
    c1 = c2;

    // read new character from lex flow
    c2 = yyinput();

    // don't forget counting line for yacc error message
    if (c2 == '\n') {
       currentProgram->numLine   ++;
       currentProgram->ownerLine ++;
    }
  }
} // yycc_IgnoreUntilSEP

extern "C" {
int	yycc_wrap()	{ return 1 ; }
};
