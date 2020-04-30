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

#ifndef YY_YYTCL_Y_TAB_H_INCLUDED
# define YY_YYTCL_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yytcl_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    G_WORD = 258,
    G_ERROR = 259,
    G_EOL = 260,
    CLASS_TAG = 261,
    PROC_TAG = 262,
    PRIVATE_TAG = 263,
    PUBLIK_TAG = 264,
    CLOSE_BRACE = 265,
    OPEN_BRACE = 266,
    EXTENDS_TAG = 267,
    STATIC_TAG = 268,
    DOC_BLOCK = 269,
    PACKAGE_TAG = 270,
    IMPORT_TAG = 271,
    END_CODE = 272,
    VAR_TAG = 273,
    IMPLEMENT_TAG = 274
  };
#endif
/* Tokens.  */
#define G_WORD 258
#define G_ERROR 259
#define G_EOL 260
#define CLASS_TAG 261
#define PROC_TAG 262
#define PRIVATE_TAG 263
#define PUBLIK_TAG 264
#define CLOSE_BRACE 265
#define OPEN_BRACE 266
#define EXTENDS_TAG 267
#define STATIC_TAG 268
#define DOC_BLOCK 269
#define PACKAGE_TAG 270
#define IMPORT_TAG 271
#define END_CODE 272
#define VAR_TAG 273
#define IMPLEMENT_TAG 274

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 93 "yaccFrontendTcl.y" /* yacc.c:1909  */

  Params    *param;
  int       intVar;
  char      charVar;
  McString  *dString;
  Values    *value;
  Extends   *extend;

#line 101 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yytcl_lval;

int yytcl_parse (void);

#endif /* !YY_YYTCL_Y_TAB_H_INCLUDED  */
