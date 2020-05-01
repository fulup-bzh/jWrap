/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         yycc_parse
#define yylex           yycc_lex
#define yyerror         yycc_error
#define yydebug         yycc_debug
#define yynerrs         yycc_nerrs

#define yylval          yycc_lval
#define yychar          yycc_char

/* Copy the first part of user declarations.  */
#line 1 "yaccFrontendCc.y" /* yacc.c:339  */

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


#line 156 "yaccFrontendCc.cxx" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yaccFrontendCc.h".  */
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
#line 96 "yaccFrontendCc.y" /* yacc.c:355  */

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

#line 290 "yaccFrontendCc.cxx" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yycc_lval;

int yycc_parse (void);

#endif /* !YY_YYCC_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 307 "yaccFrontendCc.cxx" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   391

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  280

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   152,   160,   161,   162,   163,   164,   165,
     166,   170,   174,   185,   191,   197,   207,   212,   216,   220,
     224,   228,   235,   239,   242,   251,   260,   269,   281,   285,
     289,   295,   301,   310,   314,   318,   325,   329,   336,   346,
     351,   359,   363,   371,   379,   390,   393,   396,   399,   404,
     407,   413,   419,   429,   434,   437,   440,   443,   446,   450,
     454,   458,   466,   474,   484,   487,   493,   498,   505,   509,
     514,   522,   528,   539,   543,   548,   553,   558,   566,   569,
     575,   584,   591,   594,   600,   606,   617,   629,   642,   651,
     662,   668,   676,   684,   689,   697,   705,   711,   718,   727,
     732,   739,   746,   753,   757,   768,   773,   780,   787,   794,
     798,   809,   813,   817,   823,   828,   835,   840,   846,   854,
     865,   872,   881,   885,   891,   897,   903,   909,   919,   923,
     927,   933,   941,   949,   953,   957,   962,   967,   972,   977,
     982,   990,   996,  1004,  1012,  1016,  1024,  1032,  1038,  1044,
    1050,  1054,  1059,  1064,  1072,  1078,  1085,  1094,  1104,  1114,
    1123,  1128,  1135,  1142,  1153,  1163,  1164,  1170,  1178,  1181,
    1187,  1190,  1197,  1201,  1205,  1214,  1217,  1225,  1229
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "G_WORD", "G_ERROR", "G_EOL",
  "G_SEPARATOR", "G_END", "G_EQUAL", "G_LINE", "G_NUM", "G_OPERATOR",
  "FILE_TAG", "CLASS_TAG", "VIRTUAL_TAG", "SUPER_TAG", "PUBLIK_TAG",
  "CLOSE_PRM", "OPEN_PRM", "STATIC_TAG", "EXPOR_TAG", "IMPLEMENT_TAG",
  "ENUM_TAG", "DOC_BLOCK", "SECTION_TAG", "DEFINE_TAG", "LINE_TAG",
  "END_CODE", "OPEN_BRACE", "CLOSE_BRACE", "IGNORE_TAG", "WARNING_TAG",
  "TYPEDEF_TAG", "STRUCT_TAG", "UNION_TAG", "G_PTR", "COMPLEX_TYPE",
  "CONST_TYPE", "OPEN_BRAKET", "CLOSE_BRAKET", "$accept", "Start",
  "Program", "Global", "PrefixedGlobalBlock", "Function",
  "PrefixedFunctionBlock", "Classe", "ClasseEmpty", "ClasseBlock",
  "ClsHeader", "ClsExtends", "ClsSuper", "ClsCore", "Section",
  "SectionElement", "Var", "VarBlock", "VarsCore", "VarsList",
  "VarInstance", "VarDeclaration", "Method", "MethodBlock", "MethodCore",
  "MethodProto", "MethodHeader", "MethodName", "Typedef", "TypedefBlock",
  "Struct", "StructBlock", "StructCore", "Union", "UnionBlock",
  "UnionCore", "Element", "ElementBlock", "ElementInstances",
  "ElementInstance", "Define", "DefineBlock", "Enum", "EnumBlock",
  "EnumHeader", "Values", "Value", "ValueBlock", "Doc", "Params",
  "VarType", "Param", "AssertHeader", "FileHeader", "CppFileLine",
  "Warning", "Ignore", "IgnoreBlock", "Array", "GPtrs", "ComplexType",
  "GWords", "Number", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -181

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-181)))

#define YYTABLE_NINF -133

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -181,    33,   110,  -181,   282,  -181,  -181,  -181,    34,    35,
     116,   248,   167,   107,    56,  -181,    84,   103,  -181,    36,
      52,    22,   106,  -181,   108,   151,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,   140,  -181,  -181,   233,   299,  -181,  -181,
     154,  -181,   157,   272,  -181,   164,   290,  -181,  -181,  -181,
     216,   218,    57,    72,  -181,  -181,  -181,  -181,  -181,  -181,
     170,   252,  -181,  -181,   245,   300,  -181,  -181,  -181,  -181,
    -181,  -181,    60,   254,  -181,  -181,  -181,   108,  -181,    64,
    -181,   273,   251,    29,  -181,  -181,    21,   283,   169,   179,
     322,   326,   327,   331,   205,   309,  -181,   310,  -181,  -181,
    -181,   304,   195,   214,   215,  -181,  -181,  -181,   242,   121,
    -181,  -181,  -181,  -181,  -181,  -181,   167,   124,  -181,  -181,
    -181,  -181,    26,   336,  -181,  -181,  -181,   333,   334,   335,
    -181,   337,   254,  -181,   209,  -181,    90,  -181,  -181,   340,
    -181,  -181,   328,  -181,  -181,   342,   330,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,    49,  -181,    77,   310,   134,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,   345,   332,  -181,
    -181,   248,   167,   248,   231,   231,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,   255,  -181,  -181,  -181,   304,
     249,  -181,   231,  -181,   167,  -181,  -181,   314,   348,  -181,
     315,   292,  -181,   349,   346,    42,  -181,  -181,   352,  -181,
    -181,  -181,  -181,  -181,    64,  -181,  -181,  -181,     3,  -181,
     328,  -181,  -181,  -181,  -181,  -181,   155,  -181,   177,  -181,
     167,  -181,   159,  -181,  -181,  -181,   231,  -181,  -181,  -181,
    -181,  -181,   231,  -181,   178,   318,  -181,   124,  -181,   315,
     293,    26,  -181,  -181,  -181,  -181,  -181,    15,  -181,  -181,
     297,   254,   341,   320,  -181,  -181,  -181,   354,   357,  -181,
     351,  -181,  -181,   344,  -181,   101,  -181,  -181,  -181,  -181
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   144,     3,    20,    21,     0,     0,
       0,     0,     0,     0,   131,   141,     0,     0,   167,     0,
       0,     0,     0,   170,     0,     0,    16,    23,    15,    29,
      13,     7,    34,     0,    27,    31,     0,     0,    83,    17,
     150,    18,   151,     0,    19,   153,     0,     5,   120,    14,
     152,     0,    12,     0,    11,    10,     6,     9,     8,   165,
     172,     0,    84,   162,    38,   144,    26,    30,   150,   151,
     153,   152,     0,   144,    25,    32,   144,     0,    24,     0,
     161,     0,   147,     0,   163,   164,     0,   131,     0,     0,
       0,     0,     0,     0,     0,   148,   102,   149,   108,   145,
     146,     0,     0,     0,     0,    79,    78,    81,     0,   154,
     142,    87,   100,   101,   104,   112,     0,     0,   106,   107,
     110,   129,     0,     0,    22,    28,    33,   150,   151,   153,
     121,   152,    71,   173,     0,    66,    68,    82,   166,     0,
     171,   174,     0,    35,    71,     0,     0,   125,   122,   123,
     127,   124,   126,    90,    98,     0,   132,     0,     0,     0,
      95,    94,    92,    93,   103,   109,    44,     0,    41,    39,
      54,     0,     0,     0,     0,    45,    49,    52,    60,    63,
      51,    74,    75,    55,    53,     0,    57,    58,    56,     0,
       0,    37,     0,    48,     0,    80,   155,     0,   156,   111,
     116,     0,   114,     0,   138,     0,   133,   137,     0,    38,
      86,    99,   105,   128,     0,    64,    65,    69,     0,    70,
      72,    85,    72,   160,    91,    96,     0,    88,     0,    43,
       0,    76,     0,    61,    62,    77,    46,    50,    59,    73,
      40,    36,    47,   143,     0,   157,   117,     0,   113,   118,
       0,   135,   130,   136,    67,   177,   169,     0,    97,    89,
       0,     0,     0,     0,   115,   119,   175,     0,   139,   134,
       0,   168,    42,     0,   158,     0,   176,   178,   159,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,  -181,  -181,   311,  -181,   312,  -181,  -181,   313,
     -92,  -181,   180,   263,    18,  -164,  -181,   182,     5,  -181,
     156,  -181,  -181,   183,    12,  -181,  -181,   -45,   369,     1,
    -181,    10,  -181,  -181,    16,  -181,   329,   256,  -181,   126,
    -181,   324,   372,    -1,   358,  -181,   128,   172,    -2,   147,
      -6,   187,  -181,  -181,   380,   381,   382,   338,  -180,   -76,
     -51,   118,  -181
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    26,    27,    28,    29,    30,    31,    32,
      33,   103,   169,   104,   175,   176,   177,   178,   179,   134,
     135,   136,   180,   181,   182,    36,    37,    38,   183,    68,
      41,    69,    43,    44,    70,    46,   114,   115,   201,   202,
      47,    48,   184,    71,    51,   205,   206,   207,   185,   108,
      53,   110,    54,    55,   186,   187,   188,    59,   219,    60,
      61,   268,   257
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    50,   139,    40,    72,    72,    79,    34,   137,   168,
     155,   237,    42,   255,    35,    66,    74,    78,    45,    93,
     246,   139,    67,    75,   153,    95,   270,   137,   145,   204,
      91,   109,   147,     3,   148,   149,    92,   117,    64,   154,
     117,   116,   256,    63,   116,    85,    72,   150,   251,    15,
      96,   131,   224,   127,   271,    86,    23,    34,   198,    82,
       4,   151,   128,   132,    35,   152,   203,   144,   129,   265,
     123,   252,   237,    10,    87,   132,    11,    12,   237,    14,
     225,   226,    16,   228,   140,    88,    89,    83,    90,    20,
      21,    22,    23,    24,    25,    23,   133,   168,   217,    23,
     133,    50,    18,    40,   276,   164,    84,    23,   133,    97,
     117,    99,    23,     4,     5,     6,    80,     7,   279,    65,
     208,   244,     8,     9,   196,    81,    10,   200,   218,    11,
      12,    13,    14,    15,    98,    16,    17,   227,    14,   197,
      18,    19,    20,    21,    22,    23,    24,    25,    20,    21,
      22,    23,    24,    25,   100,   101,    23,   133,   258,    23,
     133,   111,   261,   145,   112,   232,    79,    72,   102,    23,
      76,   118,   157,    50,    50,    40,    40,   233,   234,    72,
     259,   262,   158,   231,   131,   235,   127,   137,   109,    14,
     140,    50,   236,    40,    23,   133,   203,    96,    73,    20,
      21,    22,   170,    77,    25,   140,   141,    98,   163,   171,
     242,   172,   140,   140,   173,   214,   215,    14,    15,   174,
     189,    17,   191,   121,   109,    18,    19,    20,    21,    22,
      23,    24,    25,   122,    73,    50,   216,    40,   170,   192,
     105,    50,   102,    40,   193,   171,   122,   172,   194,   208,
     173,    73,   143,    14,    15,   142,   241,    17,    73,   195,
     106,    18,    19,    20,    21,    22,    23,    24,    25,   171,
      14,   172,    62,   192,   173,    76,   146,    14,   193,  -132,
      20,    21,    22,    23,    24,    25,   156,    20,    21,    22,
      23,    24,    25,    76,    14,    15,   266,   -44,   247,   248,
      62,   113,    76,   194,    20,    21,    22,   166,    77,    25,
     -44,   267,    14,    15,   272,   -43,   107,   123,    62,   119,
     167,    14,    20,    21,    22,   159,    77,    25,   -43,   160,
     161,    20,    21,    22,   162,    77,    25,   164,   165,   209,
     210,   211,   212,   220,   213,   222,   221,   223,   229,    23,
     230,   245,   249,   218,   250,   204,   263,   266,   273,   274,
     276,   277,   278,   124,   125,   126,   190,   238,   239,   240,
     254,    39,   199,   264,    49,   120,   130,   260,    94,   269,
     253,   243,    56,    57,    58,   275,     0,     0,     0,     0,
       0,   138
};

static const yytype_int16 yycheck[] =
{
       2,     2,    53,     2,    10,    11,    12,     2,    53,   101,
      86,   175,     2,    10,     2,    10,    11,    12,     2,    20,
     200,    72,    10,    11,     3,     3,    11,    72,    79,     3,
      20,    37,     3,     0,     5,     6,    20,    43,     3,    18,
      46,    43,    39,     9,    46,     9,    52,    18,     6,    23,
      28,    52,     3,    52,    39,     3,    35,    52,   109,     3,
       3,    32,    52,     3,    52,    36,   117,     3,    52,   249,
      13,    29,   236,    16,    22,     3,    19,    20,   242,    22,
       3,   157,    25,   159,    35,    33,    34,     3,    36,    32,
      33,    34,    35,    36,    37,    35,    36,   189,     8,    35,
      36,   102,    30,   102,     3,    28,     3,    35,    36,     3,
     116,     3,    35,     3,     4,     5,     9,     7,    17,     3,
     122,   197,    12,    13,     3,    18,    16,     3,    38,    19,
      20,    21,    22,    23,    28,    25,    26,     3,    22,    18,
      30,    31,    32,    33,    34,    35,    36,    37,    32,    33,
      34,    35,    36,    37,     3,    15,    35,    36,     3,    35,
      36,     7,     3,   214,     7,   171,   172,   173,    28,    35,
       3,     7,     3,   174,   175,   174,   175,   172,   173,   185,
       3,     3,     3,   171,   185,   173,   185,   232,   194,    22,
      35,   192,   174,   192,    35,    36,   247,    28,     3,    32,
      33,    34,     7,    36,    37,    35,    36,    28,     3,    14,
     192,    16,    35,    35,    19,     6,     7,    22,    23,    24,
       6,    26,     7,     7,   230,    30,    31,    32,    33,    34,
      35,    36,    37,    28,     3,   236,    27,   236,     7,    24,
       7,   242,    28,   242,    29,    14,    28,    16,     6,   251,
      19,     3,     7,    22,    23,     3,     7,    26,     3,    17,
      27,    30,    31,    32,    33,    34,    35,    36,    37,    14,
      22,    16,    18,    24,    19,     3,     3,    22,    29,    28,
      32,    33,    34,    35,    36,    37,     3,    32,    33,    34,
      35,    36,    37,     3,    22,    23,     3,    15,     6,     7,
      18,    29,     3,     6,    32,    33,    34,     3,    36,    37,
      28,    18,    22,    23,    17,    15,    17,    13,    18,    29,
      16,    22,    32,    33,    34,     3,    36,    37,    28,     3,
       3,    32,    33,    34,     3,    36,    37,    28,    28,     3,
       7,     7,     7,     3,     7,     3,    18,    17,     3,    35,
      18,     3,     3,    38,     8,     3,    38,     3,    17,    39,
       3,    10,    18,    52,    52,    52,   103,   185,   185,   189,
     214,     2,   116,   247,     2,    46,    52,   230,    20,   251,
     208,   194,     2,     2,     2,   267,    -1,    -1,    -1,    -1,
      -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,     3,     4,     5,     7,    12,    13,
      16,    19,    20,    21,    22,    23,    25,    26,    30,    31,
      32,    33,    34,    35,    36,    37,    43,    44,    45,    46,
      47,    48,    49,    50,    58,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    80,    81,    82,
      83,    84,    88,    90,    92,    93,    94,    95,    96,    97,
      99,   100,    18,     9,     3,     3,    58,    64,    69,    71,
      74,    83,    90,     3,    58,    64,     3,    36,    58,    90,
       9,    18,     3,     3,     3,     9,     3,    22,    33,    34,
      36,    71,    74,    83,    84,     3,    28,     3,    28,     3,
       3,    15,    28,    51,    53,     7,    27,    17,    89,    90,
      91,     7,     7,    29,    76,    77,    88,    90,     7,    29,
      76,     7,    28,    13,    44,    46,    49,    69,    71,    74,
      81,    83,     3,    36,    59,    60,    61,    67,    97,   100,
      35,    36,     3,     7,     3,   100,     3,     3,     5,     6,
      18,    32,    36,     3,    18,    99,     3,     3,     3,     3,
       3,     3,     3,     3,    28,    28,     3,    16,    50,    52,
       7,    14,    16,    19,    24,    54,    55,    56,    57,    58,
      62,    63,    64,    68,    82,    88,    94,    95,    96,     6,
      53,     7,    24,    29,     6,    17,     3,    18,   100,    77,
       3,    78,    79,   100,     3,    85,    86,    87,    88,     3,
       7,     7,     7,     7,     6,     7,    27,     8,    38,    98,
       3,    18,     3,    17,     3,     3,    99,     3,    99,     3,
      18,    64,    90,    58,    58,    64,    54,    55,    57,    63,
      52,     7,    54,    91,    99,     3,    98,     6,     7,     3,
       8,     6,    29,    87,    60,    10,    39,   102,     3,     3,
      89,     3,     3,    38,    79,    98,     3,    18,   101,    86,
      11,    39,    17,    17,    39,   101,     3,    10,    18,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    43,    43,    44,    44,    44,    44,    45,    45,
      46,    46,    46,    47,    47,    48,    49,    49,    50,    51,
      51,    52,    52,    50,    50,    53,    53,    53,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      56,    57,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    71,    72,    72,    72,    73,    73,    74,    75,    75,
      75,    76,    76,    77,    78,    78,    79,    79,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    82,    82,
      83,    84,    84,    85,    85,    85,    86,    86,    87,    87,
      87,    88,    89,    89,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      92,    92,    93,    94,    95,    96,    96,    97,    98,    98,
      99,    99,   100,   100,   100,   101,   101,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     1,     2,     1,
       2,     1,     2,     2,     1,     3,     4,     3,     2,     2,
       3,     1,     4,     2,     1,     2,     3,     3,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     2,     1,     3,     3,     1,     3,     1,     2,
       2,     1,     2,     2,     1,     1,     2,     2,     2,     2,
       3,     2,     2,     1,     2,     3,     3,     2,     4,     5,
       3,     4,     3,     3,     3,     3,     4,     5,     3,     3,
       2,     2,     2,     3,     2,     3,     2,     2,     2,     3,
       2,     2,     1,     3,     1,     3,     1,     2,     2,     3,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     2,
       4,     1,     2,     1,     3,     2,     2,     1,     1,     3,
       5,     1,     1,     3,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     2,     2,     3,     5,     6,
       4,     2,     2,     2,     2,     1,     2,     1,     3,     2,
       1,     2,     1,     1,     2,     1,     2,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 149 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentProgram->status=0;
   }
#line 1622 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 3:
#line 152 "yaccFrontendCc.y" /* yacc.c:1646  */
    { fprintf( stderr
                     	  ,"ERROR before line %d of file %s\n"
			  ,currentProgram->numLine, (char*)currentProgram->name);
     currentProgram->status=-1;
   }
#line 1632 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 10:
#line 166 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // We goot an help text
     debugMsg (2, "Program Accept file help", currentProgram->name, currentProgram->help);
   }
#line 1641 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 11:
#line 170 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add got an implementation assert tag
     debugMsg (2, "Program Accept implement", currentProgram->name, currentProgram->implement);
   }
#line 1650 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 12:
#line 174 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     if (currentProgram->doc ==  NULL) {
       debugMsg (2, "Program Set Doc", currentProgram->name, *(yyvsp[0].dString));
       currentProgram->doc = (yyvsp[0].dString);
     } else {
       debugMsg (2, "Program Add Doc", currentProgram->name, *(yyvsp[0].dString));
       *currentProgram->doc += "\n<br>";
       *currentProgram->doc += *(yyvsp[0].dString);
       free ((yyvsp[0].dString));
     }
   }
#line 1666 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 13:
#line 185 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       // Add current class in program
     debugMsg (2, "Program Add Class", currentProgram->name, currentClass->name);
     currentProgram->classes.append (currentClass);
     currentClass->owner = currentProgram;
   }
#line 1677 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 14:
#line 191 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add got an enumeration object
     debugMsg (2, "Program Add enumeration", currentProgram->name, currentEnum->name);
     currentProgram->enums.append (currentEnum);
     currentEnum->owner = currentProgram;
   }
#line 1688 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 15:
#line 197 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add current Function in program
     if (currentMethod->valid) {
      debugMsg (2, "Program Add Function", currentProgram->name, currentMethod->name);
      currentProgram->functions.append (currentMethod);
      currentMethod->owner = currentProgram;
     } else {
      debugMsg (2, "Program Cancel Function", currentProgram->name, currentMethod->name);
     }
   }
#line 1703 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 16:
#line 207 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add current Global in program
     debugMsg (2, "Program Add Var");
     currentVars.clear();
   }
#line 1713 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 17:
#line 212 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add current typedef in program
     debugMsg (5, "Program Accept Typedef");
   }
#line 1722 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 18:
#line 216 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add current typedef in program
     debugMsg (5, "Program Accept Struct");
   }
#line 1731 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 19:
#line 220 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add current typedef in program
     debugMsg (5, "Program Accept Union");
   }
#line 1740 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 20:
#line 224 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Ignore any unattended return line
     debugMsg (11, "Program Ignoring G_EOL");
   }
#line 1749 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 21:
#line 228 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Ignore any unattended ;
     debugMsg (11, "Program Ignoring G_END");
   }
#line 1758 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 22:
#line 235 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     debugMsg (4, "Add Doc in Global", *(yyvsp[-1].dString));
     currentVars[0]->doc = (yyvsp[-1].dString);
   }
#line 1767 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 24:
#line 242 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     int ind;
     debugMsg (4, "Prefixed Public Global");
     for (ind=0; ind < currentVars.size(); ind++) {
       currentVars[ind]->visibility = PROT_PUBLIC;
       currentVars[ind]->location   = LOC_GLOBAL;
       currentProgram->vars.append(currentVars[ind]);
     }
   }
#line 1781 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 25:
#line 251 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     int ind;
     debugMsg (4, "Prefixed Local Global");
     for (ind=0; ind < currentVars.size(); ind++) {
       currentVars[ind]->visibility = PROT_PRIVATE;
       currentVars[ind]->location   = LOC_GLOBAL;
       currentProgram->vars.append(currentVars[ind]);
     }
   }
#line 1795 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 26:
#line 260 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     int ind;
     debugMsg (4, "Explicit Public Global");
     for (ind=0; ind < currentVars.size(); ind++) {
       currentVars[ind]->visibility = PROT_PUBLIC;
       currentVars[ind]->location   = LOC_GLOBAL;
       currentProgram->vars.append(currentVars[ind]);
     }
   }
#line 1809 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 27:
#line 269 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     int ind;
     debugMsg (4, "Implicit Public Global");
     for (ind=0; ind < currentVars.size(); ind++) {
       currentVars[ind]->visibility = PROT_PUBLIC;
       currentVars[ind]->location   = LOC_GLOBAL;
       currentProgram->vars.append(currentVars[ind]);
     }
   }
#line 1823 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 28:
#line 281 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     debugMsg (4, "Add Doc in Function", *(yyvsp[-1].dString));
     currentMethod->doc = (yyvsp[-1].dString);
   }
#line 1832 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 30:
#line 289 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (3, "Get Prefixed Public Function", currentMethod->name);
      currentMethod->visibility = PROT_PUBLIC;
      currentMethod->location   = LOC_GLOBAL;
      currentMethod->defaultHelp();
   }
#line 1843 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 31:
#line 295 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (3, "Get Public Function", currentMethod->name);
      currentMethod->visibility = PROT_PUBLIC;
      currentMethod->location   = LOC_GLOBAL;
      currentMethod->defaultHelp();
   }
#line 1854 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 32:
#line 301 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (3, "Get static Function", currentMethod->name);
      currentMethod->visibility = PROT_PRIVATE;
      currentMethod->location   = LOC_GLOBAL;
      currentMethod->defaultHelp();
    }
#line 1865 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 33:
#line 310 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     debugMsg (4, "Add Doc in Class", *(yyvsp[-1].dString));
     currentClass->doc = (yyvsp[-1].dString);
    }
#line 1874 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 35:
#line 318 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     debugMsg (11, "Ignoring empty class", *(yyvsp[-1].dString));
     free ((yyvsp[-1].dString));
   }
#line 1883 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 36:
#line 325 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // update current class name
     debugMsg (1, "Got Class Extended", currentClass->name);
   }
#line 1892 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 37:
#line 329 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // update current class name
     debugMsg (1, "Got Class", currentClass->name);
   }
#line 1901 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 38:
#line 336 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       debugMsg (3, "Class Header", *(yyvsp[0].dString));
       currentClass  = new Classes ();
       currentClass->name = *(yyvsp[0].dString);
       currentVisibility = PROT_PRIVATE;
       free ((yyvsp[0].dString));
   }
#line 1913 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 39:
#line 346 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       // Add each super class in extension list
       currentClass->extends.append  ((yyvsp[0].extend));
       debugMsg (2, "Extends First Class", (yyvsp[0].extend)->name);
    }
#line 1923 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 40:
#line 351 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       // Add each super class in extension list
       currentClass->extends.append ((yyvsp[0].extend));
       debugMsg (2, "Extends Next Class", (yyvsp[0].extend)->name);
    }
#line 1933 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 41:
#line 359 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       debugMsg (5, "Super Class Basic", (yyvsp[0].extend)->name);
       (yyval.extend) = (yyvsp[0].extend);
    }
#line 1942 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 42:
#line 363 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       debugMsg (5, "Super Class Extra PRM", (yyvsp[-3].extend)->name);
       currentMethod->params.clear(); // ignore super class PRM
       (yyval.extend) = (yyvsp[-3].extend);
    }
#line 1952 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 43:
#line 371 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      Extends *extend;
      extend = new Extends();
      extend->name = *(yyvsp[0].dString);
      extend->visibility=PROT_PUBLIC;
      (yyval.extend)  = extend;
      debugMsg (4, "Super Public  Class", *(yyvsp[0].dString));
    }
#line 1965 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 44:
#line 379 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      Extends *extend;
      extend = new Extends();
      extend->name = *(yyvsp[0].dString);
      extend->visibility=PROT_PRIVATE;
      (yyval.extend)  = extend;
      debugMsg (4, "Super Private Class", *(yyvsp[0].dString));
    }
#line 1978 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 45:
#line 390 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Section Start");
    }
#line 1986 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 46:
#line 393 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Section Prefixed Start");
    }
#line 1994 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 47:
#line 396 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Section Next Visibility");
    }
#line 2002 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 48:
#line 399 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Section Core End");
    }
#line 2010 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 49:
#line 404 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Section First Element");
    }
#line 2018 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 50:
#line 407 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Section Next Element");
    }
#line 2026 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 51:
#line 413 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Section Add Method", currentMethod->name);
      currentClass->methods.append (currentMethod);
      currentMethod->owner = currentClass;
      currentMethod->visibility = currentVisibility;
    }
#line 2037 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 52:
#line 419 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      int ind;
      debugMsg (4, "Section Add Var");
      for (ind=0; ind < currentVars.size(); ind++) {
        currentVars[ind]->visibility = currentVisibility;
        currentVars[ind]->owner      = currentClass;
        currentClass->vars.append (currentVars[ind]);
      }
      currentVars.clear();
    }
#line 2052 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 53:
#line 429 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (2, "Section Add enumeration", currentProgram->name, currentEnum->name);
      currentClass->enums.append (currentEnum);
      currentEnum->owner = currentClass;
    }
#line 2062 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 54:
#line 434 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (11, "Section Ignoring ;");
    }
#line 2070 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 55:
#line 437 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (11, "Section Ignoring typedef");
    }
#line 2078 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 56:
#line 440 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (11, "Section Ignoring block");
    }
#line 2086 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 57:
#line 443 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Section update Cpp line");
    }
#line 2094 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 59:
#line 450 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    debugMsg (4, "Add Doc in Var", *(yyvsp[-1].dString));
    currentVars[0]->doc = (yyvsp[-1].dString);
    }
#line 2103 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 61:
#line 458 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      int ind;
      debugMsg (5, "Public class Var");
      for (ind=0; ind < currentVars.size(); ind++) {
        currentVars[ind]->location   = LOC_GLOBAL;
        currentVars[ind]->visibility = PROT_PUBLIC;
      }
    }
#line 2116 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 62:
#line 466 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      int ind;
      debugMsg (5, "Static class Var");
      for (ind=0; ind < currentVars.size(); ind++) {
        currentVars[ind]->location   = LOC_STATIC;
        currentVars[ind]->visibility = PROT_PRIVATE;
      }
    }
#line 2129 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 63:
#line 474 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      int ind;
      debugMsg (5, "Instance class Var");
      for (ind=0; ind < currentVars.size(); ind++) {
        currentVars[ind]->location   = LOC_AUTO;
      }
    }
#line 2141 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 64:
#line 484 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Get Vars Core");
    }
#line 2149 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 65:
#line 487 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Get Vars Core");
    }
#line 2157 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 66:
#line 493 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentVars.clear ();
      currentVars.append((yyvsp[0].var));
      debugMsg (5, "Var First instance",(yyvsp[0].var)->type,(yyvsp[0].var)->name);
    }
#line 2167 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 67:
#line 498 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentVars.append((yyvsp[0].var));
      debugMsg (5, "Var Next instance",(yyvsp[0].var)->type,(yyvsp[0].var)->name);
    }
#line 2176 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 68:
#line 505 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Var Not initialized",(yyval.var)->type,(yyval.var)->name);
      (yyval.var) =(yyvsp[0].var);
    }
#line 2185 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 69:
#line 509 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Var Ignore Init",(yyval.var)->type,(yyval.var)->name);
      yycc_StartCode (0);
      (yyval.var) = (yyvsp[-1].var);
    }
#line 2195 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 70:
#line 514 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.var) = (yyvsp[-1].var);
      (yyval.var)->array = (yyvsp[0].intVar);
      debugMsg (5, "Var Is Array",(yyval.var)->type,(yyval.var)->name);
    }
#line 2205 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 71:
#line 522 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.var)             = new Vars((yyvsp[0].dString));
      (yyval.var)->type       = currentType;
      free ((yyvsp[0].dString));
      debugMsg (3, "Var Basic Instance ",(yyval.var)->type,(yyval.var)->name);
    }
#line 2216 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 72:
#line 528 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.var)             = new Vars((yyvsp[0].dString));
      (yyval.var)->type       =  currentType;
      (yyval.var)->type       += " ";
      (yyval.var)->type       += *(yyvsp[-1].dString);
      free ((yyvsp[-1].dString));
      free ((yyvsp[0].dString));
      debugMsg (3, "Var Instance Complex",(yyval.var)->type,(yyval.var)->name);
    }
#line 2230 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 73:
#line 539 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Add Doc in Method", *(yyvsp[-1].dString));
      currentMethod->doc = (yyvsp[-1].dString);
    }
#line 2239 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 75:
#line 548 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (3, "Get Ordinary Method", currentMethod->name);
      currentMethod->location = LOC_AUTO;
      currentMethod->defaultHelp();
    }
#line 2249 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 76:
#line 553 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (3, "Get Virtual  Method", currentMethod->name);
      currentMethod->location = LOC_VIRTUAL;
      currentMethod->defaultHelp();
    }
#line 2259 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 77:
#line 558 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (3, "Get Static   Method", currentMethod->name);
      currentMethod->location = LOC_STATIC;
      currentMethod->defaultHelp();
    }
#line 2269 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 78:
#line 566 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Method As Attached Code", currentMethod->result,currentMethod->name);
    }
#line 2277 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 79:
#line 569 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Method Is Prototype Only", currentMethod->result,currentMethod->name);
    }
#line 2285 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 80:
#line 575 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      if (currentMethod->valid)
      {
        debugMsg (4, "Method With Prm", currentMethod->result,currentMethod->name);
        yycc_StartCode (0);
      } else {
        debugMsg (4, "Method was Canceled", currentMethod->result,currentMethod->name);
      }
    }
#line 2299 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 81:
#line 584 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Method No Prm", currentMethod->result,currentMethod->name);
      yycc_StartCode (0);
    }
#line 2308 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 82:
#line 591 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Method Typed Header", currentMethod->result,currentMethod->name);
    }
#line 2316 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 83:
#line 594 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentMethod->result = "";
      debugMsg (4, "Method Untyped Header", currentMethod->result,currentMethod->name);
    }
#line 2325 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 84:
#line 600 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentMethod = new Functions ((yyvsp[-1].dString));
      currentMethod->result   = currentType;
      free ((yyvsp[-1].dString));
      debugMsg (4, "Method Name Basic ", currentMethod->result,currentMethod->name);
    }
#line 2336 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 85:
#line 606 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentMethod = new Functions ((yyvsp[-1].dString));
      currentMethod->result   = currentType;
      currentMethod->result   +=*(yyvsp[-2].dString);
      free ((yyvsp[-2].dString));
      free ((yyvsp[-1].dString));
      debugMsg (4, "Method Name Ptr",currentMethod->result,currentMethod->name);
    }
#line 2349 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 86:
#line 617 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-1].typealias) != NULL) {
        // dont alias to identical name
        if (strcmp ((yyvsp[-1].typealias)->name, (yyvsp[-1].typealias)->source)) {
        debugMsg (4, "Add Typedef + Doc Alias in program", (yyvsp[-1].typealias)->name,*(yyvsp[-2].dString));
        (yyvsp[-1].typealias)->doc = (yyvsp[-2].dString);
           currentProgram->typedefs.append ((yyvsp[-1].typealias));
        }
      } else {
        debugMsg (11, "Ignoring typdef");
      }
    }
#line 2366 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 87:
#line 629 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-1].typealias) != NULL) {
        // dont alias to identical name
        if (strcmp ((yyvsp[-1].typealias)->name, (yyvsp[-1].typealias)->source)) {
        debugMsg (4, "Add Typedef Only Alias in program", (yyvsp[-1].typealias)->name);
        currentProgram->typedefs.append ((yyvsp[-1].typealias));
       }
      } else {
        debugMsg (11, "Ignoring typdef");
      }
    }
#line 2382 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 88:
#line 642 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      *(yyvsp[-2].dString) += " ";
      *(yyvsp[-2].dString) += *(yyvsp[-1].dString);
      (yyval.typealias) = new Typedefs ((yyvsp[-2].dString),(yyvsp[0].dString));
      debugMsg (4, "Aliasing Complex Type", (yyval.typealias)->source, (yyval.typealias)->name);
      free ((yyvsp[-2].dString));
      free ((yyvsp[-1].dString));
      free ((yyvsp[0].dString));
    }
#line 2396 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 89:
#line 651 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      *(yyvsp[-3].dString) += " ";
      *(yyvsp[-3].dString) += *(yyvsp[-2].dString);
      *(yyvsp[-3].dString) += *(yyvsp[-1].dString);
      (yyval.typealias) = new Typedefs ((yyvsp[-3].dString),(yyvsp[0].dString));
      debugMsg (4, "Aliasing Complex Ptr Type", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[-3].dString));
      free ((yyvsp[-2].dString));
      free ((yyvsp[-1].dString));
      free ((yyvsp[0].dString));
    }
#line 2412 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 90:
#line 662 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.typealias) = new Typedefs ((yyvsp[-1].dString),(yyvsp[0].dString));
      debugMsg (4, "Aliasing Basic Type", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[-1].dString));
      free ((yyvsp[0].dString));
    }
#line 2423 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 91:
#line 668 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      *(yyvsp[-2].dString) += *(yyvsp[-1].dString);
      (yyval.typealias) = new Typedefs ((yyvsp[-2].dString),(yyvsp[0].dString));
      debugMsg (4, "Aliasing Basic Ptr Type", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[-2].dString));
      free ((yyvsp[-1].dString));
      free ((yyvsp[0].dString));
    }
#line 2436 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 92:
#line 676 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Program Add Internal Enum", currentEnum->name);
      currentProgram->enums.append (currentEnum);

      (yyval.typealias) = new Typedefs (&currentEnum->name,(yyvsp[0].dString));
      debugMsg (4, "Aliasing Enum to Type", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[0].dString));
    }
#line 2449 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 93:
#line 684 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.typealias) = new Typedefs (&currentEnum->name,(yyvsp[0].dString));
      debugMsg (4, "Aliasing Enum to Type", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[0].dString));
    }
#line 2459 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 94:
#line 689 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Program Add Internal Union", (yyvsp[-1].jointure)->name);
      currentProgram->unions.append ((yyvsp[-1].jointure));

      (yyval.typealias) = new Typedefs (&(yyvsp[-1].jointure)->name,(yyvsp[0].dString));
      debugMsg (4, "Aliasing Enum to Union", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[0].dString));
    }
#line 2472 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 95:
#line 697 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Program Add Internal Struct", (yyvsp[-1].structure)->name);
      currentProgram->structs.append ((yyvsp[-1].structure));

      (yyval.typealias) = new Typedefs (&(yyvsp[-1].structure)->name,(yyvsp[0].dString));
      debugMsg (4, "Aliasing Stuct", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[0].dString));
    }
#line 2485 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 96:
#line 705 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.typealias) = new Typedefs ((yyvsp[0].dString), (yyvsp[-1].dString));
      debugMsg (4, "Aliasing Stuct", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[-1].dString));
      free ((yyvsp[0].dString));
    }
#line 2496 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 97:
#line 711 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.typealias) = new Typedefs ((yyvsp[0].dString), (yyvsp[-2].dString));
      (yyval.typealias)->source += *(yyvsp[-1].dString);
      debugMsg (4, "Aliasing G_PTR Stuct", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[-2].dString));
      free ((yyvsp[0].dString));
    }
#line 2508 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 98:
#line 718 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (10, "Ignoring Function typedef", *(yyvsp[-1].dString));
      free ((yyvsp[-1].dString));
      yycc_StartCode (0);
      (yyval.typealias) = NULL;
    }
#line 2519 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 99:
#line 727 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Add Struct + Doc in program", *(yyvsp[-2].dString));
      (yyvsp[-1].structure)->doc = (yyvsp[-2].dString);
      currentProgram->structs.append ((yyvsp[-1].structure));
    }
#line 2529 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 100:
#line 732 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Add Struct Only in program");
      currentProgram->structs.append ((yyvsp[-1].structure));
    }
#line 2538 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 101:
#line 739 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Got Structure", (yyvsp[-1].structure)->name);
      (yyval.structure) = (yyvsp[-1].structure);
    }
#line 2547 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 102:
#line 746 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      static int ind =0;
      char   nom[50];
      sprintf (nom,"Struct_%s_%d", (char*)currentProgram->implement, ind++);
      debugMsg (2, "Start noName Struct",nom);
      (yyval.structure) = new Structs (nom);
    }
#line 2559 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 103:
#line 753 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (2, "Start Named Struct",*(yyvsp[-1].dString));
      (yyval.structure) = new Structs (*(yyvsp[-1].dString));
    }
#line 2568 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 104:
#line 757 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      int ind;
      debugMsg (4, "Add Elements in Struct", (yyvsp[-1].structure)->name);
      for (ind=0; ind < currentElements.size(); ind++) {
        (yyvsp[-1].structure)->elements.append (currentElements [ind]);
      }
      (yyval.structure) = (yyvsp[-1].structure);
    }
#line 2581 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 105:
#line 768 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Add Union + Doc in program", (yyvsp[-1].jointure)->name, *(yyvsp[-2].dString));
      (yyvsp[-1].jointure)->doc = (yyvsp[-2].dString);
      currentProgram->unions.append ((yyvsp[-1].jointure));
    }
#line 2591 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 106:
#line 773 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Add Union Only in program", (yyvsp[-1].jointure)->name);
      currentProgram->unions.append ((yyvsp[-1].jointure));
    }
#line 2600 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 107:
#line 780 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Got Union", (yyvsp[-1].jointure)->name);
      (yyval.jointure) = (yyvsp[-1].jointure);
    }
#line 2609 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 108:
#line 787 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      static int ind =0;
      char   nom[50];
      sprintf (nom,"Union_%s_%d", (char*)currentProgram->implement, ind++);
      debugMsg (2, "Start noName Union",nom);
      (yyval.jointure) = new Unions (nom);
    }
#line 2621 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 109:
#line 794 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (2, "Start Named Union",*(yyvsp[-1].dString));
      (yyval.jointure) = new Unions (*(yyvsp[-1].dString));
    }
#line 2630 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 110:
#line 798 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      int ind;
      debugMsg (4, "Add Elements in Union", (yyvsp[-1].jointure)->name);
      for (ind=0; ind < currentElements.size(); ind++) {
        (yyvsp[-1].jointure)->elements.append (currentElements [ind]);
      }
      (yyval.jointure) = (yyvsp[-1].jointure);
    }
#line 2643 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 111:
#line 809 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Element Doc Added");
      currentElements[0]->doc = (yyvsp[-1].dString);
    }
#line 2652 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 113:
#line 817 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       debugMsg (5, "Got Struct Element line");
    }
#line 2660 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 114:
#line 823 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Get Element First intance");
      currentElements.clear  ();
      currentElements.append ((yyvsp[0].element));
    }
#line 2670 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 115:
#line 828 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Get Element Next intance");
      currentElements.append ((yyvsp[0].element));
    }
#line 2679 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 116:
#line 835 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.element) = new Elements(*(yyvsp[0].dString));
      free ((yyvsp[0].dString));
      debugMsg (3, "Element Instance",(yyval.element)->type,(yyval.element)->name);
    }
#line 2689 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 117:
#line 840 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.element) = new Elements(*(yyvsp[-1].dString));
      (yyval.element)->array = (yyvsp[0].intVar);
      free ((yyvsp[-1].dString));
      debugMsg (3, "Element Array Instance",(yyval.element)->type,(yyval.element)->name);
    }
#line 2700 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 118:
#line 846 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.element)             = new Elements (*(yyvsp[0].dString));
      (yyval.element)->type       = currentType;
      (yyval.element)->type      += *(yyvsp[-1].dString);
      free ((yyvsp[0].dString));
      free ((yyvsp[-1].dString));
      debugMsg (3, "Element Array CompleType Instance",(yyval.element)->type,(yyval.element)->name);
    }
#line 2713 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 119:
#line 854 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.element)             = new Elements (*(yyvsp[-1].dString));
      (yyval.element)->type       = currentType;
      (yyval.element)->type      += *(yyvsp[-2].dString);
      (yyval.element)->array      = (yyvsp[0].intVar);
      free ((yyvsp[-1].dString));
      free ((yyvsp[-2].dString));
      debugMsg (3, "Element CompleType Instance",(yyval.element)->type,(yyval.element)->name);
    }
#line 2727 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 120:
#line 865 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].define) != NULL) {
        debugMsg (5, "Define no doc",(yyvsp[0].define)->name);
	(yyvsp[0].define)->doc = NULL;
        currentProgram->defines.append ((yyvsp[0].define));
      }
    }
#line 2739 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 121:
#line 872 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     if ((yyvsp[0].define) != NULL) {
       debugMsg (4, "Define Add Doc",(yyvsp[0].define)->name,*(yyvsp[-1].dString));
       (yyvsp[0].define)->doc = (yyvsp[-1].dString);
       currentProgram->defines.append ((yyvsp[0].define));
     }
    }
#line 2751 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 122:
#line 881 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5,"Ignore define with no value", *(yyvsp[-1].dString));
      (yyval.define) = NULL;
    }
#line 2760 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 123:
#line 885 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5,"Ignore define with a comma", *(yyvsp[-1].dString));
      yyclearin;
      yycc_IgnoreUntilEOL ();
      (yyval.define) = NULL;
    }
#line 2771 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 124:
#line 891 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5,"Ignore define with embedded TYPEDEF", *(yyvsp[-1].dString));
      yyclearin;
      yycc_IgnoreUntilEOL ();
      (yyval.define)= NULL;
    }
#line 2782 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 125:
#line 897 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      yyclearin;
      yycc_IgnoreUntilEOL ();
      (yyval.define) = new Defines ((yyvsp[-1].dString),(yyvsp[0].dString));
      debugMsg (4, "Add New define value",(yyval.define)->name,(yyval.define)->value);
    }
#line 2793 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 126:
#line 903 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Ignore New define complex value",*(yyvsp[-1].dString),*(yyvsp[0].dString));
      yyclearin;
      yycc_IgnoreUntilEOL ();
      (yyval.define) = NULL;
    }
#line 2804 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 127:
#line 909 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Ignore define complex value",*(yyvsp[-1].dString));
      yyclearin;
      yycc_IgnoreUntilEOL ();
      yycc_ModeInitial();
      (yyval.define) = NULL;
    }
#line 2816 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 128:
#line 919 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Add Doc in Enum", *(yyvsp[-2].dString));
      currentEnum->doc = (yyvsp[-2].dString);
    }
#line 2825 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 130:
#line 927 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Got Enum", currentEnum->name);
    }
#line 2833 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 131:
#line 933 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      static int ind=0;
      char   name[50];
      currentEnum = new Enums();
      sprintf (name,"Enum_%s_%d",(char*)currentProgram->implement,ind++);
      currentEnum->name = name;
      debugMsg (3, "Enum Header NoNamed", name);
    }
#line 2846 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 132:
#line 941 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentEnum = new Enums();
      currentEnum->name = *(yyvsp[0].dString);
      debugMsg (3, "Enum Header Named", *(yyvsp[0].dString));
    }
#line 2856 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 133:
#line 949 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Got First enum value",(yyvsp[0].value)->name,(yyvsp[0].value)->value);
      currentEnum->values.append ((yyvsp[0].value));
    }
#line 2865 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 134:
#line 953 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Add New  enum value",(yyvsp[0].value)->name,(yyvsp[0].value)->value);
      currentEnum->values.append ((yyvsp[0].value));
    }
#line 2874 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 135:
#line 957 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Last comma ignored");
    }
#line 2882 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 136:
#line 962 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Enum value Add Doc");
      (yyvsp[0].value)->doc = (yyvsp[-1].dString);
      (yyval.value) = (yyvsp[0].value);
    }
#line 2892 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 137:
#line 967 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.value)  = (yyvsp[0].value);
    }
#line 2900 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 138:
#line 972 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      // Enum as no value we provide a default value
      debugMsg (5, "Get Last Enum slot", *(yyvsp[0].dString), NOT_SET);
      (yyval.value) = new Values (*(yyvsp[0].dString), "");
    }
#line 2910 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 139:
#line 977 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      // Build a new constance/value relation
      debugMsg (5, "Got Enum value", *(yyvsp[-2].dString), *(yyvsp[0].dString));
      (yyval.value) = new Values (*(yyvsp[-2].dString), *(yyvsp[0].dString));
    }
#line 2920 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 140:
#line 982 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      // Build a new constance/value relation
      debugMsg (5, "Got Enum value", *(yyvsp[-4].dString), *(yyvsp[-1].dString));
      (yyval.value) = new Values (*(yyvsp[-4].dString), *(yyvsp[-1].dString));
    }
#line 2930 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 141:
#line 990 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.dString) = (yyvsp[0].dString);
    }
#line 2938 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 142:
#line 996 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      if (strcmp ("void", (char*)(yyvsp[0].param)->type)) {
        debugMsg (4, "Add First Param,", (yyvsp[0].param)->type);
        currentMethod->params.append ((yyvsp[0].param));
      } else {
        debugMsg (5, "Ignore void param,", (yyvsp[0].param)->type);
      }
    }
#line 2951 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 143:
#line 1004 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      // ignore params if void
      debugMsg (4, "Add Next Param,", (yyvsp[0].param)->type);
      currentMethod->params.append ((yyvsp[0].param));
    }
#line 2961 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 144:
#line 1012 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType = *(yyvsp[0].dString);
     debugMsg (3, "Get Vars Basic Type",currentType);
   }
#line 2970 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 145:
#line 1016 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType =  *(yyvsp[-1].dString);
     currentType += " ";
     currentType += *(yyvsp[0].dString);
     free ((yyvsp[-1].dString));
     free ((yyvsp[0].dString));
     debugMsg (3, "Get Vars Complex Type",currentType);
   }
#line 2983 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 146:
#line 1024 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType =  *(yyvsp[-1].dString);
     currentType += " ";
     currentType += *(yyvsp[0].dString);
     free ((yyvsp[-1].dString));
     free ((yyvsp[0].dString));
     debugMsg (3, "Get Vars Const Type",currentType);
   }
#line 2996 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 147:
#line 1032 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType =  "enum ";
     currentType += *(yyvsp[0].dString);
     free ((yyvsp[0].dString));
     debugMsg (3, "Get Vars Enum Type",currentType);
   }
#line 3007 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 148:
#line 1038 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType =  "struct ";
     currentType += *(yyvsp[0].dString);
     free ((yyvsp[0].dString));
     debugMsg (3, "Get Vars Struct Type",currentType);
   }
#line 3018 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 149:
#line 1044 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType =  "union ";
     currentType += *(yyvsp[0].dString);
     free ((yyvsp[0].dString));
     debugMsg (3, "Get Vars Union Type",currentType);
   }
#line 3029 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 150:
#line 1050 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     debugMsg (3, "Get Vars Typedef Type Add to Prog",currentType);
     currentProgram->typedefs.append ((yyvsp[0].typealias));
   }
#line 3038 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 151:
#line 1054 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType = (yyvsp[0].structure)->name;
     currentProgram->structs.append ((yyvsp[0].structure));
     debugMsg (3, "Get Vars Struct Type Add to Prog",currentType);
   }
#line 3048 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 152:
#line 1059 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType = currentEnum->name;
     currentProgram->enums.append (currentEnum);
     debugMsg (3, "Get Vars Enum Type Add to Prog",currentType);
   }
#line 3058 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 153:
#line 1064 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType = (yyvsp[0].jointure)->name;
     currentProgram->unions.append ((yyvsp[0].jointure));
     debugMsg (3, "Get Vars Union Type Add to prog",currentType);
   }
#line 3068 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 154:
#line 1072 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.param) = new Params (&currentType);
      (yyval.param)->type = currentType;
      (yyval.param)->name = "NoName";
      debugMsg (5, "Get NoName Param",(yyval.param)->type,(yyval.param)->name);
   }
#line 3079 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 155:
#line 1078 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.param) = new Params (&currentType);
      (yyval.param)->type = currentType;
      (yyval.param)->name = *(yyvsp[0].dString);
      free ((yyvsp[0].dString));
      debugMsg (5, "Get Named Param",(yyval.param)->type,(yyval.param)->name);
   }
#line 3091 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 156:
#line 1085 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.param) = new Params (&currentType);
      (yyval.param)->type = currentType;
      (yyval.param)->type += " ";
      (yyval.param)->type += *(yyvsp[0].dString);
      (yyval.param)->name = "NoName";
      free ((yyvsp[0].dString));
      debugMsg (5, "Get Complex NoName Param",(yyval.param)->type,(yyval.param)->name);
   }
#line 3105 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 157:
#line 1094 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.param) = new Params (&currentType);
      (yyval.param)->type = currentType;
      (yyval.param)->type += " ";
      (yyval.param)->type += *(yyvsp[-1].dString);
      (yyval.param)->name = *(yyvsp[0].dString);
      free ((yyvsp[-1].dString));
      free ((yyvsp[0].dString));
      debugMsg (5, "Get Complex Named Param",(yyval.param)->type,(yyval.param)->name);
   }
#line 3120 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 158:
#line 1104 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.param) = new Params (&currentType);
      (yyval.param)->type = currentType;
      (yyval.param)->type += "* ";
      (yyval.param)->type += *(yyvsp[-3].dString);
      (yyval.param)->name = *(yyvsp[-2].dString);
      free ((yyvsp[-3].dString));
      free ((yyvsp[-2].dString));
      debugMsg (5, "Get Complex Named Param",(yyval.param)->type,(yyval.param)->name);
   }
#line 3135 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 159:
#line 1114 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentMethod->valid=FALSE;
      yycc_IgnoreUntilBalancedBrace (1);
      debugMsg (11, "Ignoring function with FUNC as param");
   }
#line 3145 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 160:
#line 1123 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentProgram->implement= *(yyvsp[-1].dString);
      currentProgram->assertLine= currentProgram->numLine;
      debugMsg (5, "assert implementation", currentProgram->implement);
      yycc_IgnoreUntilEOL();  // restart Lex searching
    }
#line 3156 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 161:
#line 1128 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentProgram->implement= *(yyvsp[0].dString);
      currentProgram->assertLine= currentProgram->numLine;
      debugMsg (5, "assert implementation", currentProgram->implement);
    }
#line 3166 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 162:
#line 1135 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentProgram->help =  *(yyvsp[0].dString);
      debugMsg (5, "PrgName Help", currentProgram->help);
    }
#line 3175 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 163:
#line 1142 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      if (strcmp (*(yyvsp[0].dString), currentProgram->ownerName)) {
        debugMsg (2, "CppFileLine", *(yyvsp[0].dString));
        currentProgram->ownerName = *(yyvsp[0].dString);
      }
      currentProgram->ownerLine = (yyvsp[-1].intVar);
      yycc_IgnoreUntilEOL();
    }
#line 3188 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 164:
#line 1153 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
  if (verbose) {
    fprintf (stderr, "********************************************************\n");
    fprintf (stderr, "| %s\n", (char*)*(yyvsp[0].dString));
    fprintf (stderr, "********************************************************\n");
  };
  free ((yyvsp[0].dString));
}
#line 3201 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 166:
#line 1164 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    currentType = "";
  }
#line 3209 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 167:
#line 1170 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    debugMsg (11, "Ignoring Block");
    yyclearin;
    yycc_IgnoreUntilEOB(0);
  }
#line 3219 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 168:
#line 1178 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    (yyval.intVar) = (yyvsp[-1].intVar);
  }
#line 3227 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 169:
#line 1181 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    (yyval.intVar) = 0;
  }
#line 3235 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 170:
#line 1187 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    (yyval.dString) =new McString("*");
  }
#line 3243 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 171:
#line 1190 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    (yyval.dString)  =   (yyvsp[-1].dString);
    *(yyval.dString)  += "*";
  }
#line 3252 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 172:
#line 1197 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.dString) = (yyvsp[0].dString);
      debugMsg (5, "Ptr Type",*(yyval.dString));
    }
#line 3261 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 173:
#line 1201 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.dString) = (yyvsp[0].dString);
      debugMsg (5, "Complex Type",*(yyval.dString));
    }
#line 3270 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 174:
#line 1205 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.dString) = (yyvsp[-1].dString);
      *(yyval.dString) += *(yyvsp[0].dString);
      free ((yyvsp[0].dString));
      debugMsg (5, "Complex Ptr Type",*(yyval.dString));
    }
#line 3281 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 175:
#line 1214 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    (yyval.dString) = (yyvsp[0].dString);
  }
#line 3289 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 176:
#line 1217 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    (yyval.dString)   =   (yyvsp[-1].dString);
    *(yyval.dString)  += *(yyvsp[0].dString);
    free ((yyvsp[0].dString));
  }
#line 3299 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 177:
#line 1225 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    debugMsg (4, "Get Basic Number");
    (yyval.intVar) = (yyvsp[0].intVar);
  }
#line 3308 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 178:
#line 1229 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[-1].intVar)) {
      case '+':
        (yyval.intVar) = (yyval.intVar) + (yyvsp[-1].intVar);
        break;
      case '-':
        (yyval.intVar) = (yyval.intVar) - (yyvsp[-1].intVar);
        break;
      case '*':
        (yyval.intVar) = (yyval.intVar) * (yyvsp[-1].intVar);
        break;
      case '/':
        (yyval.intVar) = (yyval.intVar) / (yyvsp[-1].intVar);
        break;
    }
    (yyval.intVar) = (yyvsp[-2].intVar);
  }
#line 3330 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;


#line 3334 "yaccFrontendCc.cxx" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
