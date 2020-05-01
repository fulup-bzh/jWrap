/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YYCC_Y_TAB_H_INCLUDED
# define YY_YYCC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yycc_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    G_WORD = 258,
    G_ERROR = 259,
    G_EOL = 260,
    G_SEPARATOR = 261,
    G_END = 262,
    G_EQUAL = 263,
    G_LINE = 264,
    G_NUM = 265,
    G_OPERATOR = 266,
    FILE_TAG = 267,
    CLASS_TAG = 268,
    VIRTUAL_TAG = 269,
    SUPER_TAG = 270,
    PUBLIK_TAG = 271,
    CLOSE_PRM = 272,
    OPEN_PRM = 273,
    STATIC_TAG = 274,
    EXPOR_TAG = 275,
    IMPLEMENT_TAG = 276,
    ENUM_TAG = 277,
    DOC_BLOCK = 278,
    SECTION_TAG = 279,
    DEFINE_TAG = 280,
    LINE_TAG = 281,
    END_CODE = 282,
    OPEN_BRACE = 283,
    CLOSE_BRACE = 284,
    IGNORE_TAG = 285,
    WARNING_TAG = 286,
    TYPEDEF_TAG = 287,
    STRUCT_TAG = 288,
    UNION_TAG = 289,
    G_PTR = 290,
    COMPLEX_TYPE = 291,
    CONST_TYPE = 292,
    OPEN_BRAKET = 293,
    CLOSE_BRAKET = 294
  };
#endif
/* Tokens.  */
#define G_WORD 258
#define G_ERROR 259
#define G_EOL 260
#define G_SEPARATOR 261
#define G_END 262
#define G_EQUAL 263
#define G_LINE 264
#define G_NUM 265
#define G_OPERATOR 266
#define FILE_TAG 267
#define CLASS_TAG 268
#define VIRTUAL_TAG 269
#define SUPER_TAG 270
#define PUBLIK_TAG 271
#define CLOSE_PRM 272
#define OPEN_PRM 273
#define STATIC_TAG 274
#define EXPOR_TAG 275
#define IMPLEMENT_TAG 276
#define ENUM_TAG 277
#define DOC_BLOCK 278
#define SECTION_TAG 279
#define DEFINE_TAG 280
#define LINE_TAG 281
#define END_CODE 282
#define OPEN_BRACE 283
#define CLOSE_BRACE 284
#define IGNORE_TAG 285
#define WARNING_TAG 286
#define TYPEDEF_TAG 287
#define STRUCT_TAG 288
#define UNION_TAG 289
#define G_PTR 290
#define COMPLEX_TYPE 291
#define CONST_TYPE 292
#define OPEN_BRAKET 293
#define CLOSE_BRAKET 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 96 "yaccFrontendCc.y" /* yacc.c:1909  */

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

#line 148 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yycc_lval;

int yycc_parse (void);

#endif /* !YY_YYCC_Y_TAB_H_INCLUDED  */
