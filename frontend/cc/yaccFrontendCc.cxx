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
 * Auteur    :   Fulup Le Foll [Fulup@fridu.bzh]
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
    OPEN_BRAKET = 292,
    CLOSE_BRAKET = 293
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
#define OPEN_BRAKET 292
#define CLOSE_BRAKET 293

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

#line 288 "yaccFrontendCc.cxx" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yycc_lval;

int yycc_parse (void);

#endif /* !YY_YYCC_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 305 "yaccFrontendCc.cxx" /* yacc.c:358  */

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
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  278

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   151,   159,   160,   161,   162,   163,   164,
     165,   169,   173,   184,   190,   196,   206,   211,   215,   219,
     223,   227,   234,   238,   241,   250,   259,   268,   280,   284,
     288,   294,   300,   309,   313,   317,   324,   328,   335,   345,
     350,   358,   362,   370,   378,   389,   392,   395,   398,   403,
     406,   412,   418,   428,   433,   436,   439,   442,   445,   449,
     453,   457,   465,   473,   483,   486,   492,   497,   504,   508,
     513,   521,   527,   538,   542,   547,   552,   557,   565,   568,
     574,   583,   590,   593,   599,   605,   616,   628,   641,   650,
     661,   667,   675,   683,   688,   696,   704,   710,   717,   726,
     731,   738,   745,   752,   756,   767,   772,   779,   786,   793,
     797,   808,   812,   816,   822,   827,   834,   839,   845,   853,
     864,   871,   880,   884,   890,   896,   902,   908,   918,   922,
     926,   932,   940,   948,   952,   956,   961,   966,   971,   976,
     981,   989,   995,  1003,  1011,  1015,  1023,  1029,  1035,  1041,
    1045,  1050,  1055,  1063,  1069,  1076,  1085,  1095,  1105,  1114,
    1119,  1126,  1133,  1144,  1154,  1155,  1161,  1169,  1172,  1178,
    1181,  1188,  1192,  1196,  1205,  1208,  1216,  1220
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
  "OPEN_BRAKET", "CLOSE_BRAKET", "$accept", "Start", "Program", "Global",
  "PrefixedGlobalBlock", "Function", "PrefixedFunctionBlock", "Classe",
  "ClasseEmpty", "ClasseBlock", "ClsHeader", "ClsExtends", "ClsSuper",
  "ClsCore", "Section", "SectionElement", "Var", "VarBlock", "VarsCore",
  "VarsList", "VarInstance", "VarDeclaration", "Method", "MethodBlock",
  "MethodCore", "MethodProto", "MethodHeader", "MethodName", "Typedef",
  "TypedefBlock", "Struct", "StructBlock", "StructCore", "Union",
  "UnionBlock", "UnionCore", "Element", "ElementBlock", "ElementInstances",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -187

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-187)))

#define YYTABLE_NINF -133

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -187,    15,   109,  -187,   281,  -187,  -187,  -187,    14,    60,
      57,   251,    73,   191,    95,  -187,   107,   114,  -187,    16,
      13,    53,    72,  -187,   121,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,   291,  -187,  -187,   153,   271,  -187,  -187,   150,
    -187,   174,   195,  -187,   190,   246,  -187,  -187,  -187,   200,
     212,   134,    67,  -187,  -187,  -187,  -187,  -187,  -187,   282,
     220,  -187,  -187,   223,   283,  -187,  -187,  -187,  -187,  -187,
    -187,    91,   224,  -187,  -187,  -187,   121,  -187,   116,  -187,
     247,   243,   143,  -187,  -187,    19,   287,   198,   216,   292,
     297,   313,   317,   253,   296,  -187,   298,  -187,  -187,   299,
     180,   264,   265,  -187,  -187,  -187,   304,   202,  -187,  -187,
    -187,  -187,  -187,  -187,    73,   222,  -187,  -187,  -187,  -187,
     185,   324,  -187,  -187,  -187,   321,   322,   323,  -187,   325,
     224,  -187,   270,  -187,    40,  -187,  -187,   328,  -187,  -187,
     315,  -187,  -187,   331,   318,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,    24,  -187,   218,   298,    48,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,   333,   319,  -187,  -187,   251,
      73,   251,   229,   229,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,    52,  -187,  -187,  -187,   299,   284,  -187,
     229,  -187,    73,  -187,  -187,   303,   336,  -187,   305,   316,
    -187,   337,   335,    35,  -187,  -187,   338,  -187,  -187,  -187,
    -187,  -187,   116,  -187,  -187,  -187,     4,  -187,   315,  -187,
    -187,  -187,  -187,  -187,   101,  -187,   120,  -187,    73,  -187,
     231,  -187,  -187,  -187,   229,  -187,  -187,  -187,  -187,  -187,
     229,  -187,   155,   307,  -187,   222,  -187,   305,    26,   185,
    -187,  -187,  -187,  -187,  -187,   100,  -187,  -187,   308,   224,
     329,   309,  -187,  -187,  -187,   342,   345,  -187,   339,  -187,
    -187,   332,  -187,    50,  -187,  -187,  -187,  -187
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   144,     3,    20,    21,     0,     0,
       0,     0,     0,     0,   131,   141,     0,     0,   166,     0,
       0,     0,     0,   169,     0,    16,    23,    15,    29,    13,
       7,    34,     0,    27,    31,     0,     0,    83,    17,   149,
      18,   150,     0,    19,   152,     0,     5,   120,    14,   151,
       0,    12,     0,    11,    10,     6,     9,     8,   164,   171,
       0,    84,   161,    38,   144,    26,    30,   149,   150,   152,
     151,     0,   144,    25,    32,   144,     0,    24,     0,   160,
       0,   146,     0,   162,   163,     0,   131,     0,     0,     0,
       0,     0,     0,     0,   147,   102,   148,   108,   145,     0,
       0,     0,     0,    79,    78,    81,     0,   153,   142,    87,
     100,   101,   104,   112,     0,     0,   106,   107,   110,   129,
       0,     0,    22,    28,    33,   149,   150,   152,   121,   151,
      71,   172,     0,    66,    68,    82,   165,     0,   170,   173,
       0,    35,    71,     0,     0,   125,   122,   123,   127,   124,
     126,    90,    98,     0,   132,     0,     0,     0,    95,    94,
      92,    93,   103,   109,    44,     0,    41,    39,    54,     0,
       0,     0,     0,    45,    49,    52,    60,    63,    51,    74,
      75,    55,    53,     0,    57,    58,    56,     0,     0,    37,
       0,    48,     0,    80,   154,     0,   155,   111,   116,     0,
     114,     0,   138,     0,   133,   137,     0,    38,    86,    99,
     105,   128,     0,    64,    65,    69,     0,    70,    72,    85,
      72,   159,    91,    96,     0,    88,     0,    43,     0,    76,
       0,    61,    62,    77,    46,    50,    59,    73,    40,    36,
      47,   143,     0,   156,   117,     0,   113,   118,     0,   135,
     130,   136,    67,   176,   168,     0,    97,    89,     0,     0,
       0,     0,   115,   119,   174,     0,   139,   134,     0,   167,
      42,     0,   157,     0,   175,   177,   158,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,  -187,  -187,   300,  -187,   301,  -187,  -187,   302,
     -91,  -187,   167,   254,   -57,  -162,  -187,   173,    22,  -187,
     145,  -187,  -187,   175,     7,  -187,  -187,   -45,   357,     1,
    -187,    11,  -187,  -187,    18,  -187,   320,   248,  -187,   115,
    -187,   310,   361,    -1,   344,  -187,   117,   161,    -2,   140,
      -6,   177,  -187,  -187,   368,   369,   370,   326,  -186,   -75,
     -50,   108,  -187
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    25,    26,    27,    28,    29,    30,    31,
      32,   101,   167,   102,   173,   174,   175,   176,   177,   132,
     133,   134,   178,   179,   180,    35,    36,    37,   181,    67,
      40,    68,    42,    43,    69,    45,   112,   113,   199,   200,
      46,    47,   182,    70,    50,   203,   204,   205,   183,   106,
      52,   108,    53,    54,   184,   185,   186,    58,   217,    59,
      60,   266,   255
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    49,   137,    39,    71,    71,    78,   135,   166,    34,
     153,   235,   244,    41,   253,     3,    85,    66,    74,    92,
      44,   137,   151,    62,    33,    84,   135,   222,   143,   264,
     107,    90,    65,    73,    77,    86,   115,   152,    91,   115,
     114,   249,   254,   114,   265,    71,    87,    88,   215,    89,
     129,   225,   125,   274,    23,    72,    94,   196,    34,   138,
      64,   263,   126,    63,   250,   201,   169,   277,   170,   127,
     130,   171,   235,    33,    14,    96,    75,   216,   235,    14,
     224,    95,   226,    23,    20,    21,    22,    23,    24,    20,
      21,    22,    23,    24,   130,    14,   166,    18,    81,    49,
      97,    39,    23,   131,   256,    20,    21,    22,   115,    76,
      82,   268,     4,     5,     6,   234,     7,    83,   206,   142,
     242,     8,     9,   257,    98,    10,    23,   131,    11,    12,
      13,    14,    15,   240,    16,    17,   138,     4,   269,    18,
      19,    20,    21,    22,    23,    24,   145,   121,   146,   147,
      10,    23,   131,    11,    12,   138,    14,   109,   260,    16,
     103,   148,   143,   230,    78,    71,    20,    21,    22,    23,
      24,    49,    49,    39,    39,   149,   229,    71,   233,   150,
     104,   110,   129,    72,   125,   135,   107,   168,   202,    49,
     138,    39,   231,   232,   169,   201,   170,   116,    75,   171,
      79,   155,    14,    15,   172,   194,    17,   119,    15,    80,
      18,    19,    20,    21,    22,    23,    24,    14,    15,   156,
     195,   223,   107,   140,   111,   198,    95,    20,    21,    22,
     141,    76,    72,    49,   259,    39,   168,    23,   131,    49,
     120,    39,    61,   169,    97,   170,   162,   206,   171,    75,
     144,    14,    15,    23,    72,    17,   161,    23,   131,    18,
      19,    20,    21,    22,    23,    24,    23,   131,    14,    15,
     187,  -132,   189,    14,    75,   117,   212,   213,    20,    21,
      22,   120,    76,    20,    21,    22,    23,    24,   105,   190,
     154,   239,   100,    14,   191,   157,   -44,   214,   -43,    61,
     158,    61,   164,    20,    21,    22,    99,    76,   190,   -44,
     192,   -43,   121,   191,   192,   165,   159,   138,   139,   100,
     160,   193,   245,   246,   162,   270,   163,   207,   208,   209,
     210,   218,   211,   219,   220,   221,   227,   228,    23,   243,
     247,   202,   216,   248,   261,   264,   271,   272,   274,   275,
     276,   122,   123,   124,   238,   188,   236,   252,   237,    38,
     262,   128,   197,    48,    93,   118,   267,   251,   258,   241,
      55,    56,    57,   273,     0,     0,     0,     0,   136
};

static const yytype_int16 yycheck[] =
{
       2,     2,    52,     2,    10,    11,    12,    52,    99,     2,
      85,   173,   198,     2,    10,     0,     3,    10,    11,    20,
       2,    71,     3,     9,     2,     9,    71,     3,    78,     3,
      36,    20,    10,    11,    12,    22,    42,    18,    20,    45,
      42,     6,    38,    45,    18,    51,    33,    34,     8,    36,
      51,     3,    51,     3,    35,     3,     3,   107,    51,    35,
       3,   247,    51,     3,    29,   115,    14,    17,    16,    51,
       3,    19,   234,    51,    22,     3,     3,    37,   240,    22,
     155,    28,   157,    35,    32,    33,    34,    35,    36,    32,
      33,    34,    35,    36,     3,    22,   187,    30,     3,   100,
      28,   100,    35,    36,     3,    32,    33,    34,   114,    36,
       3,    11,     3,     4,     5,   172,     7,     3,   120,     3,
     195,    12,    13,     3,     3,    16,    35,    36,    19,    20,
      21,    22,    23,   190,    25,    26,    35,     3,    38,    30,
      31,    32,    33,    34,    35,    36,     3,    13,     5,     6,
      16,    35,    36,    19,    20,    35,    22,     7,     3,    25,
       7,    18,   212,   169,   170,   171,    32,    33,    34,    35,
      36,   172,   173,   172,   173,    32,   169,   183,   171,    36,
      27,     7,   183,     3,   183,   230,   192,     7,     3,   190,
      35,   190,   170,   171,    14,   245,    16,     7,     3,    19,
       9,     3,    22,    23,    24,     3,    26,     7,    23,    18,
      30,    31,    32,    33,    34,    35,    36,    22,    23,     3,
      18,     3,   228,     3,    29,     3,    28,    32,    33,    34,
       7,    36,     3,   234,     3,   234,     7,    35,    36,   240,
      28,   240,    18,    14,    28,    16,    28,   249,    19,     3,
       3,    22,    23,    35,     3,    26,     3,    35,    36,    30,
      31,    32,    33,    34,    35,    36,    35,    36,    22,    23,
       6,    28,     7,    22,     3,    29,     6,     7,    32,    33,
      34,    28,    36,    32,    33,    34,    35,    36,    17,    24,
       3,     7,    28,    22,    29,     3,    15,    27,    15,    18,
       3,    18,     3,    32,    33,    34,    15,    36,    24,    28,
       6,    28,    13,    29,     6,    16,     3,    35,    36,    28,
       3,    17,     6,     7,    28,    17,    28,     3,     7,     7,
       7,     3,     7,    18,     3,    17,     3,    18,    35,     3,
       3,     3,    37,     8,    37,     3,    17,    38,     3,    10,
      18,    51,    51,    51,   187,   101,   183,   212,   183,     2,
     245,    51,   114,     2,    20,    45,   249,   206,   228,   192,
       2,     2,     2,   265,    -1,    -1,    -1,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,     0,     3,     4,     5,     7,    12,    13,
      16,    19,    20,    21,    22,    23,    25,    26,    30,    31,
      32,    33,    34,    35,    36,    42,    43,    44,    45,    46,
      47,    48,    49,    57,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    79,    80,    81,    82,
      83,    87,    89,    91,    92,    93,    94,    95,    96,    98,
      99,    18,     9,     3,     3,    57,    63,    68,    70,    73,
      82,    89,     3,    57,    63,     3,    36,    57,    89,     9,
      18,     3,     3,     3,     9,     3,    22,    33,    34,    36,
      70,    73,    82,    83,     3,    28,     3,    28,     3,    15,
      28,    50,    52,     7,    27,    17,    88,    89,    90,     7,
       7,    29,    75,    76,    87,    89,     7,    29,    75,     7,
      28,    13,    43,    45,    48,    68,    70,    73,    80,    82,
       3,    36,    58,    59,    60,    66,    96,    99,    35,    36,
       3,     7,     3,    99,     3,     3,     5,     6,    18,    32,
      36,     3,    18,    98,     3,     3,     3,     3,     3,     3,
       3,     3,    28,    28,     3,    16,    49,    51,     7,    14,
      16,    19,    24,    53,    54,    55,    56,    57,    61,    62,
      63,    67,    81,    87,    93,    94,    95,     6,    52,     7,
      24,    29,     6,    17,     3,    18,    99,    76,     3,    77,
      78,    99,     3,    84,    85,    86,    87,     3,     7,     7,
       7,     7,     6,     7,    27,     8,    37,    97,     3,    18,
       3,    17,     3,     3,    98,     3,    98,     3,    18,    63,
      89,    57,    57,    63,    53,    54,    56,    62,    51,     7,
      53,    90,    98,     3,    97,     6,     7,     3,     8,     6,
      29,    86,    59,    10,    38,   101,     3,     3,    88,     3,
       3,    37,    78,    97,     3,    18,   100,    85,    11,    38,
      17,    17,    38,   100,     3,    10,    18,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    42,    42,    43,    43,    43,    43,    44,    44,
      45,    45,    45,    46,    46,    47,    48,    48,    49,    50,
      50,    51,    51,    49,    49,    52,    52,    52,    52,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    56,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    60,    60,    61,    61,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    70,    71,    71,    71,    72,    72,    73,    74,    74,
      74,    75,    75,    76,    77,    77,    78,    78,    78,    78,
      79,    79,    80,    80,    80,    80,    80,    80,    81,    81,
      82,    83,    83,    84,    84,    84,    85,    85,    86,    86,
      86,    87,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    90,    91,
      91,    92,    93,    94,    95,    95,    96,    97,    97,    98,
      98,    99,    99,    99,   100,   100,   101,   101
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
       5,     1,     1,     3,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     2,     2,     3,     5,     6,     4,
       2,     2,     2,     2,     1,     2,     1,     3,     2,     1,
       2,     1,     1,     2,     1,     2,     1,     3
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
#line 148 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentProgram->status=0;
   }
#line 1615 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 3:
#line 151 "yaccFrontendCc.y" /* yacc.c:1646  */
    { fprintf( stderr
                     	  ,"ERROR before line %d of file %s\n"
			  ,currentProgram->numLine, (char*)currentProgram->name);
     currentProgram->status=-1;
   }
#line 1625 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 10:
#line 165 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // We goot an help text
     debugMsg (2, "Program Accept file help", currentProgram->name, currentProgram->help);
   }
#line 1634 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 11:
#line 169 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add got an implementation assert tag
     debugMsg (2, "Program Accept implement", currentProgram->name, currentProgram->implement);
   }
#line 1643 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 12:
#line 173 "yaccFrontendCc.y" /* yacc.c:1646  */
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
#line 1659 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 13:
#line 184 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       // Add current class in program
     debugMsg (2, "Program Add Class", currentProgram->name, currentClass->name);
     currentProgram->classes.append (currentClass);
     currentClass->owner = currentProgram;
   }
#line 1670 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 14:
#line 190 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add got an enumeration object
     debugMsg (2, "Program Add enumeration", currentProgram->name, currentEnum->name);
     currentProgram->enums.append (currentEnum);
     currentEnum->owner = currentProgram;
   }
#line 1681 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 15:
#line 196 "yaccFrontendCc.y" /* yacc.c:1646  */
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
#line 1696 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 16:
#line 206 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add current Global in program
     debugMsg (2, "Program Add Var");
     currentVars.clear();
   }
#line 1706 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 17:
#line 211 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add current typedef in program
     debugMsg (5, "Program Accept Typedef");
   }
#line 1715 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 18:
#line 215 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add current typedef in program
     debugMsg (5, "Program Accept Struct");
   }
#line 1724 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 19:
#line 219 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Add current typedef in program
     debugMsg (5, "Program Accept Union");
   }
#line 1733 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 20:
#line 223 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Ignore any unattended return line
     debugMsg (11, "Program Ignoring G_EOL");
   }
#line 1742 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 21:
#line 227 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // Ignore any unattended ;
     debugMsg (11, "Program Ignoring G_END");
   }
#line 1751 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 22:
#line 234 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     debugMsg (4, "Add Doc in Global", *(yyvsp[-1].dString));
     currentVars[0]->doc = (yyvsp[-1].dString);
   }
#line 1760 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 24:
#line 241 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     int ind;
     debugMsg (4, "Prefixed Public Global");
     for (ind=0; ind < currentVars.size(); ind++) {
       currentVars[ind]->visibility = PROT_PUBLIC;
       currentVars[ind]->location   = LOC_GLOBAL;
       currentProgram->vars.append(currentVars[ind]);
     }
   }
#line 1774 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 25:
#line 250 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     int ind;
     debugMsg (4, "Prefixed Local Global");
     for (ind=0; ind < currentVars.size(); ind++) {
       currentVars[ind]->visibility = PROT_PRIVATE;
       currentVars[ind]->location   = LOC_GLOBAL;
       currentProgram->vars.append(currentVars[ind]);
     }
   }
#line 1788 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 26:
#line 259 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     int ind;
     debugMsg (4, "Explicit Public Global");
     for (ind=0; ind < currentVars.size(); ind++) {
       currentVars[ind]->visibility = PROT_PUBLIC;
       currentVars[ind]->location   = LOC_GLOBAL;
       currentProgram->vars.append(currentVars[ind]);
     }
   }
#line 1802 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 27:
#line 268 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     int ind;
     debugMsg (4, "Implicit Public Global");
     for (ind=0; ind < currentVars.size(); ind++) {
       currentVars[ind]->visibility = PROT_PUBLIC;
       currentVars[ind]->location   = LOC_GLOBAL;
       currentProgram->vars.append(currentVars[ind]);
     }
   }
#line 1816 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 28:
#line 280 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     debugMsg (4, "Add Doc in Function", *(yyvsp[-1].dString));
     currentMethod->doc = (yyvsp[-1].dString);
   }
#line 1825 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 30:
#line 288 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (3, "Get Prefixed Public Function", currentMethod->name);
      currentMethod->visibility = PROT_PUBLIC;
      currentMethod->location   = LOC_GLOBAL;
      currentMethod->defaultHelp();
   }
#line 1836 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 31:
#line 294 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (3, "Get Public Function", currentMethod->name);
      currentMethod->visibility = PROT_PUBLIC;
      currentMethod->location   = LOC_GLOBAL;
      currentMethod->defaultHelp();
   }
#line 1847 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 32:
#line 300 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (3, "Get static Function", currentMethod->name);
      currentMethod->visibility = PROT_PRIVATE;
      currentMethod->location   = LOC_GLOBAL;
      currentMethod->defaultHelp();
    }
#line 1858 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 33:
#line 309 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     debugMsg (4, "Add Doc in Class", *(yyvsp[-1].dString));
     currentClass->doc = (yyvsp[-1].dString);
    }
#line 1867 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 35:
#line 317 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     debugMsg (11, "Ignoring empty class", *(yyvsp[-1].dString));
     free ((yyvsp[-1].dString));
   }
#line 1876 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 36:
#line 324 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // update current class name
     debugMsg (1, "Got Class Extended", currentClass->name);
   }
#line 1885 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 37:
#line 328 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     // update current class name
     debugMsg (1, "Got Class", currentClass->name);
   }
#line 1894 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 38:
#line 335 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       debugMsg (3, "Class Header", *(yyvsp[0].dString));
       currentClass  = new Classes ();
       currentClass->name = *(yyvsp[0].dString);
       currentVisibility = PROT_PRIVATE;
       free ((yyvsp[0].dString));
   }
#line 1906 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 39:
#line 345 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       // Add each super class in extension list
       currentClass->extends.append  ((yyvsp[0].extend));
       debugMsg (2, "Extends First Class", (yyvsp[0].extend)->name);
    }
#line 1916 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 40:
#line 350 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       // Add each super class in extension list
       currentClass->extends.append ((yyvsp[0].extend));
       debugMsg (2, "Extends Next Class", (yyvsp[0].extend)->name);
    }
#line 1926 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 41:
#line 358 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       debugMsg (5, "Super Class Basic", (yyvsp[0].extend)->name);
       (yyval.extend) = (yyvsp[0].extend);
    }
#line 1935 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 42:
#line 362 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       debugMsg (5, "Super Class Extra PRM", (yyvsp[-3].extend)->name);
       currentMethod->params.clear(); // ignore super class PRM
       (yyval.extend) = (yyvsp[-3].extend);
    }
#line 1945 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 43:
#line 370 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      Extends *extend;
      extend = new Extends();
      extend->name = *(yyvsp[0].dString);
      extend->visibility=PROT_PUBLIC;
      (yyval.extend)  = extend;
      debugMsg (4, "Super Public  Class", *(yyvsp[0].dString));
    }
#line 1958 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 44:
#line 378 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      Extends *extend;
      extend = new Extends();
      extend->name = *(yyvsp[0].dString);
      extend->visibility=PROT_PRIVATE;
      (yyval.extend)  = extend;
      debugMsg (4, "Super Private Class", *(yyvsp[0].dString));
    }
#line 1971 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 45:
#line 389 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Section Start");
    }
#line 1979 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 46:
#line 392 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Section Prefixed Start");
    }
#line 1987 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 47:
#line 395 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Section Next Visibility");
    }
#line 1995 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 48:
#line 398 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Section Core End");
    }
#line 2003 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 49:
#line 403 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Section First Element");
    }
#line 2011 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 50:
#line 406 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Section Next Element");
    }
#line 2019 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 51:
#line 412 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Section Add Method", currentMethod->name);
      currentClass->methods.append (currentMethod);
      currentMethod->owner = currentClass;
      currentMethod->visibility = currentVisibility;
    }
#line 2030 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 52:
#line 418 "yaccFrontendCc.y" /* yacc.c:1646  */
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
#line 2045 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 53:
#line 428 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (2, "Section Add enumeration", currentProgram->name, currentEnum->name);
      currentClass->enums.append (currentEnum);
      currentEnum->owner = currentClass;
    }
#line 2055 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 54:
#line 433 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (11, "Section Ignoring ;");
    }
#line 2063 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 55:
#line 436 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (11, "Section Ignoring typedef");
    }
#line 2071 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 56:
#line 439 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (11, "Section Ignoring block");
    }
#line 2079 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 57:
#line 442 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Section update Cpp line");
    }
#line 2087 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 59:
#line 449 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    debugMsg (4, "Add Doc in Var", *(yyvsp[-1].dString));
    currentVars[0]->doc = (yyvsp[-1].dString);
    }
#line 2096 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 61:
#line 457 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      int ind;
      debugMsg (5, "Public class Var");
      for (ind=0; ind < currentVars.size(); ind++) {
        currentVars[ind]->location   = LOC_GLOBAL;
        currentVars[ind]->visibility = PROT_PUBLIC;
      }
    }
#line 2109 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 62:
#line 465 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      int ind;
      debugMsg (5, "Static class Var");
      for (ind=0; ind < currentVars.size(); ind++) {
        currentVars[ind]->location   = LOC_STATIC;
        currentVars[ind]->visibility = PROT_PRIVATE;
      }
    }
#line 2122 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 63:
#line 473 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      int ind;
      debugMsg (5, "Instance class Var");
      for (ind=0; ind < currentVars.size(); ind++) {
        currentVars[ind]->location   = LOC_AUTO;
      }
    }
#line 2134 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 64:
#line 483 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Get Vars Core");
    }
#line 2142 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 65:
#line 486 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Get Vars Core");
    }
#line 2150 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 66:
#line 492 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentVars.clear ();
      currentVars.append((yyvsp[0].var));
      debugMsg (5, "Var First instance",(yyvsp[0].var)->type,(yyvsp[0].var)->name);
    }
#line 2160 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 67:
#line 497 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentVars.append((yyvsp[0].var));
      debugMsg (5, "Var Next instance",(yyvsp[0].var)->type,(yyvsp[0].var)->name);
    }
#line 2169 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 68:
#line 504 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Var Not initialized",(yyval.var)->type,(yyval.var)->name);
      (yyval.var) =(yyvsp[0].var);
    }
#line 2178 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 69:
#line 508 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Var Ignore Init",(yyval.var)->type,(yyval.var)->name);
      yycc_StartCode (0);
      (yyval.var) = (yyvsp[-1].var);
    }
#line 2188 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 70:
#line 513 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.var) = (yyvsp[-1].var);
      (yyval.var)->array = (yyvsp[0].intVar);
      debugMsg (5, "Var Is Array",(yyval.var)->type,(yyval.var)->name);
    }
#line 2198 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 71:
#line 521 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.var)             = new Vars((yyvsp[0].dString));
      (yyval.var)->type       = currentType;
      free ((yyvsp[0].dString));
      debugMsg (3, "Var Basic Instance ",(yyval.var)->type,(yyval.var)->name);
    }
#line 2209 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 72:
#line 527 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.var)             = new Vars((yyvsp[0].dString));
      (yyval.var)->type       =  currentType;
      (yyval.var)->type       += " ";
      (yyval.var)->type       += *(yyvsp[-1].dString);
      free ((yyvsp[-1].dString));
      free ((yyvsp[0].dString));
      debugMsg (3, "Var Instance Complex",(yyval.var)->type,(yyval.var)->name);
    }
#line 2223 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 73:
#line 538 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Add Doc in Method", *(yyvsp[-1].dString));
      currentMethod->doc = (yyvsp[-1].dString);
    }
#line 2232 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 75:
#line 547 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (3, "Get Ordinary Method", currentMethod->name);
      currentMethod->location = LOC_AUTO;
      currentMethod->defaultHelp();
    }
#line 2242 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 76:
#line 552 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (3, "Get Virtual  Method", currentMethod->name);
      currentMethod->location = LOC_VIRTUAL;
      currentMethod->defaultHelp();
    }
#line 2252 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 77:
#line 557 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (3, "Get Static   Method", currentMethod->name);
      currentMethod->location = LOC_STATIC;
      currentMethod->defaultHelp();
    }
#line 2262 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 78:
#line 565 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Method As Attached Code", currentMethod->result,currentMethod->name);
    }
#line 2270 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 79:
#line 568 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Method Is Prototype Only", currentMethod->result,currentMethod->name);
    }
#line 2278 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 80:
#line 574 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      if (currentMethod->valid)
      {
        debugMsg (4, "Method With Prm", currentMethod->result,currentMethod->name);
        yycc_StartCode (0);
      } else {
        debugMsg (4, "Method was Canceled", currentMethod->result,currentMethod->name);
      }
    }
#line 2292 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 81:
#line 583 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Method No Prm", currentMethod->result,currentMethod->name);
      yycc_StartCode (0);
    }
#line 2301 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 82:
#line 590 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Method Typed Header", currentMethod->result,currentMethod->name);
    }
#line 2309 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 83:
#line 593 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentMethod->result = "";
      debugMsg (4, "Method Untyped Header", currentMethod->result,currentMethod->name);
    }
#line 2318 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 84:
#line 599 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentMethod = new Functions ((yyvsp[-1].dString));
      currentMethod->result   = currentType;
      free ((yyvsp[-1].dString));
      debugMsg (4, "Method Name Basic ", currentMethod->result,currentMethod->name);
    }
#line 2329 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 85:
#line 605 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentMethod = new Functions ((yyvsp[-1].dString));
      currentMethod->result   = currentType;
      currentMethod->result   +=*(yyvsp[-2].dString);
      free ((yyvsp[-2].dString));
      free ((yyvsp[-1].dString));
      debugMsg (4, "Method Name Ptr",currentMethod->result,currentMethod->name);
    }
#line 2342 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 86:
#line 616 "yaccFrontendCc.y" /* yacc.c:1646  */
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
#line 2359 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 87:
#line 628 "yaccFrontendCc.y" /* yacc.c:1646  */
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
#line 2375 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 88:
#line 641 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      *(yyvsp[-2].dString) += " ";
      *(yyvsp[-2].dString) += *(yyvsp[-1].dString);
      (yyval.typealias) = new Typedefs ((yyvsp[-2].dString),(yyvsp[0].dString));
      debugMsg (4, "Aliasing Complex Type", (yyval.typealias)->source, (yyval.typealias)->name);
      free ((yyvsp[-2].dString));
      free ((yyvsp[-1].dString));
      free ((yyvsp[0].dString));
    }
#line 2389 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 89:
#line 650 "yaccFrontendCc.y" /* yacc.c:1646  */
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
#line 2405 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 90:
#line 661 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.typealias) = new Typedefs ((yyvsp[-1].dString),(yyvsp[0].dString));
      debugMsg (4, "Aliasing Basic Type", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[-1].dString));
      free ((yyvsp[0].dString));
    }
#line 2416 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 91:
#line 667 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      *(yyvsp[-2].dString) += *(yyvsp[-1].dString);
      (yyval.typealias) = new Typedefs ((yyvsp[-2].dString),(yyvsp[0].dString));
      debugMsg (4, "Aliasing Basic Ptr Type", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[-2].dString));
      free ((yyvsp[-1].dString));
      free ((yyvsp[0].dString));
    }
#line 2429 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 92:
#line 675 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Program Add Internal Enum", currentEnum->name);
      currentProgram->enums.append (currentEnum);

      (yyval.typealias) = new Typedefs (&currentEnum->name,(yyvsp[0].dString));
      debugMsg (4, "Aliasing Enum to Type", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[0].dString));
    }
#line 2442 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 93:
#line 683 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.typealias) = new Typedefs (&currentEnum->name,(yyvsp[0].dString));
      debugMsg (4, "Aliasing Enum to Type", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[0].dString));
    }
#line 2452 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 94:
#line 688 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Program Add Internal Union", (yyvsp[-1].jointure)->name);
      currentProgram->unions.append ((yyvsp[-1].jointure));

      (yyval.typealias) = new Typedefs (&(yyvsp[-1].jointure)->name,(yyvsp[0].dString));
      debugMsg (4, "Aliasing Enum to Union", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[0].dString));
    }
#line 2465 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 95:
#line 696 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Program Add Internal Struct", (yyvsp[-1].structure)->name);
      currentProgram->structs.append ((yyvsp[-1].structure));

      (yyval.typealias) = new Typedefs (&(yyvsp[-1].structure)->name,(yyvsp[0].dString));
      debugMsg (4, "Aliasing Stuct", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[0].dString));
    }
#line 2478 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 96:
#line 704 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.typealias) = new Typedefs ((yyvsp[0].dString), (yyvsp[-1].dString));
      debugMsg (4, "Aliasing Stuct", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[-1].dString));
      free ((yyvsp[0].dString));
    }
#line 2489 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 97:
#line 710 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.typealias) = new Typedefs ((yyvsp[0].dString), (yyvsp[-2].dString));
      (yyval.typealias)->source += *(yyvsp[-1].dString);
      debugMsg (4, "Aliasing G_PTR Stuct", (yyval.typealias)->source,(yyval.typealias)->name);
      free ((yyvsp[-2].dString));
      free ((yyvsp[0].dString));
    }
#line 2501 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 98:
#line 717 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (10, "Ignoring Function typedef", *(yyvsp[-1].dString));
      free ((yyvsp[-1].dString));
      yycc_StartCode (0);
      (yyval.typealias) = NULL;
    }
#line 2512 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 99:
#line 726 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Add Struct + Doc in program", *(yyvsp[-2].dString));
      (yyvsp[-1].structure)->doc = (yyvsp[-2].dString);
      currentProgram->structs.append ((yyvsp[-1].structure));
    }
#line 2522 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 100:
#line 731 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Add Struct Only in program");
      currentProgram->structs.append ((yyvsp[-1].structure));
    }
#line 2531 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 101:
#line 738 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Got Structure", (yyvsp[-1].structure)->name);
      (yyval.structure) = (yyvsp[-1].structure);
    }
#line 2540 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 102:
#line 745 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      static int ind =0;
      char   nom[50];
      sprintf (nom,"Struct_%s_%d", (char*)currentProgram->implement, ind++);
      debugMsg (2, "Start noName Struct",nom);
      (yyval.structure) = new Structs (nom);
    }
#line 2552 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 103:
#line 752 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (2, "Start Named Struct",*(yyvsp[-1].dString));
      (yyval.structure) = new Structs (*(yyvsp[-1].dString));
    }
#line 2561 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 104:
#line 756 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      int ind;
      debugMsg (4, "Add Elements in Struct", (yyvsp[-1].structure)->name);
      for (ind=0; ind < currentElements.size(); ind++) {
        (yyvsp[-1].structure)->elements.append (currentElements [ind]);
      }
      (yyval.structure) = (yyvsp[-1].structure);
    }
#line 2574 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 105:
#line 767 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Add Union + Doc in program", (yyvsp[-1].jointure)->name, *(yyvsp[-2].dString));
      (yyvsp[-1].jointure)->doc = (yyvsp[-2].dString);
      currentProgram->unions.append ((yyvsp[-1].jointure));
    }
#line 2584 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 106:
#line 772 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Add Union Only in program", (yyvsp[-1].jointure)->name);
      currentProgram->unions.append ((yyvsp[-1].jointure));
    }
#line 2593 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 107:
#line 779 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Got Union", (yyvsp[-1].jointure)->name);
      (yyval.jointure) = (yyvsp[-1].jointure);
    }
#line 2602 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 108:
#line 786 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      static int ind =0;
      char   nom[50];
      sprintf (nom,"Union_%s_%d", (char*)currentProgram->implement, ind++);
      debugMsg (2, "Start noName Union",nom);
      (yyval.jointure) = new Unions (nom);
    }
#line 2614 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 109:
#line 793 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (2, "Start Named Union",*(yyvsp[-1].dString));
      (yyval.jointure) = new Unions (*(yyvsp[-1].dString));
    }
#line 2623 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 110:
#line 797 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      int ind;
      debugMsg (4, "Add Elements in Union", (yyvsp[-1].jointure)->name);
      for (ind=0; ind < currentElements.size(); ind++) {
        (yyvsp[-1].jointure)->elements.append (currentElements [ind]);
      }
      (yyval.jointure) = (yyvsp[-1].jointure);
    }
#line 2636 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 111:
#line 808 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Element Doc Added");
      currentElements[0]->doc = (yyvsp[-1].dString);
    }
#line 2645 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 113:
#line 816 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
       debugMsg (5, "Got Struct Element line");
    }
#line 2653 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 114:
#line 822 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Get Element First intance");
      currentElements.clear  ();
      currentElements.append ((yyvsp[0].element));
    }
#line 2663 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 115:
#line 827 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Get Element Next intance");
      currentElements.append ((yyvsp[0].element));
    }
#line 2672 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 116:
#line 834 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.element) = new Elements(*(yyvsp[0].dString));
      free ((yyvsp[0].dString));
      debugMsg (3, "Element Instance",(yyval.element)->type,(yyval.element)->name);
    }
#line 2682 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 117:
#line 839 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.element) = new Elements(*(yyvsp[-1].dString));
      (yyval.element)->array = (yyvsp[0].intVar);
      free ((yyvsp[-1].dString));
      debugMsg (3, "Element Array Instance",(yyval.element)->type,(yyval.element)->name);
    }
#line 2693 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 118:
#line 845 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.element)             = new Elements (*(yyvsp[0].dString));
      (yyval.element)->type       = currentType;
      (yyval.element)->type      += *(yyvsp[-1].dString);
      free ((yyvsp[0].dString));
      free ((yyvsp[-1].dString));
      debugMsg (3, "Element Array CompleType Instance",(yyval.element)->type,(yyval.element)->name);
    }
#line 2706 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 119:
#line 853 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.element)             = new Elements (*(yyvsp[-1].dString));
      (yyval.element)->type       = currentType;
      (yyval.element)->type      += *(yyvsp[-2].dString);
      (yyval.element)->array      = (yyvsp[0].intVar);
      free ((yyvsp[-1].dString));
      free ((yyvsp[-2].dString));
      debugMsg (3, "Element CompleType Instance",(yyval.element)->type,(yyval.element)->name);
    }
#line 2720 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 120:
#line 864 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].define) != NULL) {
        debugMsg (5, "Define no doc",(yyvsp[0].define)->name);
	(yyvsp[0].define)->doc = NULL;
        currentProgram->defines.append ((yyvsp[0].define));
      }
    }
#line 2732 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 121:
#line 871 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     if ((yyvsp[0].define) != NULL) {
       debugMsg (4, "Define Add Doc",(yyvsp[0].define)->name,*(yyvsp[-1].dString));
       (yyvsp[0].define)->doc = (yyvsp[-1].dString);
       currentProgram->defines.append ((yyvsp[0].define));
     }
    }
#line 2744 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 122:
#line 880 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5,"Ignore define with no value", *(yyvsp[-1].dString));
      (yyval.define) = NULL;
    }
#line 2753 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 123:
#line 884 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5,"Ignore define with a comma", *(yyvsp[-1].dString));
      yyclearin;
      yycc_IgnoreUntilEOL ();
      (yyval.define) = NULL;
    }
#line 2764 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 124:
#line 890 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5,"Ignore define with embedded TYPEDEF", *(yyvsp[-1].dString));
      yyclearin;
      yycc_IgnoreUntilEOL ();
      (yyval.define)= NULL;
    }
#line 2775 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 125:
#line 896 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      yyclearin;
      yycc_IgnoreUntilEOL ();
      (yyval.define) = new Defines ((yyvsp[-1].dString),(yyvsp[0].dString));
      debugMsg (4, "Add New define value",(yyval.define)->name,(yyval.define)->value);
    }
#line 2786 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 126:
#line 902 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Ignore New define complex value",*(yyvsp[-1].dString),*(yyvsp[0].dString));
      yyclearin;
      yycc_IgnoreUntilEOL ();
      (yyval.define) = NULL;
    }
#line 2797 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 127:
#line 908 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Ignore define complex value",*(yyvsp[-1].dString));
      yyclearin;
      yycc_IgnoreUntilEOL ();
      yycc_ModeInitial();
      (yyval.define) = NULL;
    }
#line 2809 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 128:
#line 918 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Add Doc in Enum", *(yyvsp[-2].dString));
      currentEnum->doc = (yyvsp[-2].dString);
    }
#line 2818 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 130:
#line 926 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Got Enum", currentEnum->name);
    }
#line 2826 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 131:
#line 932 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      static int ind=0;
      char   name[50];
      currentEnum = new Enums();
      sprintf (name,"Enum_%s_%d",(char*)currentProgram->implement,ind++);
      currentEnum->name = name;
      debugMsg (3, "Enum Header NoNamed", name);
    }
#line 2839 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 132:
#line 940 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentEnum = new Enums();
      currentEnum->name = *(yyvsp[0].dString);
      debugMsg (3, "Enum Header Named", *(yyvsp[0].dString));
    }
#line 2849 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 133:
#line 948 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Got First enum value",(yyvsp[0].value)->name,(yyvsp[0].value)->value);
      currentEnum->values.append ((yyvsp[0].value));
    }
#line 2858 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 134:
#line 952 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Add New  enum value",(yyvsp[0].value)->name,(yyvsp[0].value)->value);
      currentEnum->values.append ((yyvsp[0].value));
    }
#line 2867 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 135:
#line 956 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (5, "Last comma ignored");
    }
#line 2875 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 136:
#line 961 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      debugMsg (4, "Enum value Add Doc");
      (yyvsp[0].value)->doc = (yyvsp[-1].dString);
      (yyval.value) = (yyvsp[0].value);
    }
#line 2885 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 137:
#line 966 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.value)  = (yyvsp[0].value);
    }
#line 2893 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 138:
#line 971 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      // Enum as no value we provide a default value
      debugMsg (5, "Get Last Enum slot", *(yyvsp[0].dString), NOT_SET);
      (yyval.value) = new Values (*(yyvsp[0].dString), "");
    }
#line 2903 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 139:
#line 976 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      // Build a new constance/value relation
      debugMsg (5, "Got Enum value", *(yyvsp[-2].dString), *(yyvsp[0].dString));
      (yyval.value) = new Values (*(yyvsp[-2].dString), *(yyvsp[0].dString));
    }
#line 2913 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 140:
#line 981 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      // Build a new constance/value relation
      debugMsg (5, "Got Enum value", *(yyvsp[-4].dString), *(yyvsp[-1].dString));
      (yyval.value) = new Values (*(yyvsp[-4].dString), *(yyvsp[-1].dString));
    }
#line 2923 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 141:
#line 989 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.dString) = (yyvsp[0].dString);
    }
#line 2931 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 142:
#line 995 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      if (strcmp ("void", (char*)(yyvsp[0].param)->type)) {
        debugMsg (4, "Add First Param,", (yyvsp[0].param)->type);
        currentMethod->params.append ((yyvsp[0].param));
      } else {
        debugMsg (5, "Ignore void param,", (yyvsp[0].param)->type);
      }
    }
#line 2944 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 143:
#line 1003 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      // ignore params if void
      debugMsg (4, "Add Next Param,", (yyvsp[0].param)->type);
      currentMethod->params.append ((yyvsp[0].param));
    }
#line 2954 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 144:
#line 1011 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType = *(yyvsp[0].dString);
     debugMsg (3, "Get Vars Basic Type",currentType);
   }
#line 2963 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 145:
#line 1015 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType =  *(yyvsp[-1].dString);
     currentType += " ";
     currentType += *(yyvsp[0].dString);
     free ((yyvsp[-1].dString));
     free ((yyvsp[0].dString));
     debugMsg (3, "Get Vars Complex Type",currentType);
   }
#line 2976 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 146:
#line 1023 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType =  "enum ";
     currentType += *(yyvsp[0].dString);
     free ((yyvsp[0].dString));
     debugMsg (3, "Get Vars Enum Type",currentType);
   }
#line 2987 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 147:
#line 1029 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType =  "struct ";
     currentType += *(yyvsp[0].dString);
     free ((yyvsp[0].dString));
     debugMsg (3, "Get Vars Struct Type",currentType);
   }
#line 2998 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 148:
#line 1035 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType =  "union ";
     currentType += *(yyvsp[0].dString);
     free ((yyvsp[0].dString));
     debugMsg (3, "Get Vars Union Type",currentType);
   }
#line 3009 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 149:
#line 1041 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     debugMsg (3, "Get Vars Typedef Type Add to Prog",currentType);
     currentProgram->typedefs.append ((yyvsp[0].typealias));
   }
#line 3018 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 150:
#line 1045 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType = (yyvsp[0].structure)->name;
     currentProgram->structs.append ((yyvsp[0].structure));
     debugMsg (3, "Get Vars Struct Type Add to Prog",currentType);
   }
#line 3028 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 151:
#line 1050 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType = currentEnum->name;
     currentProgram->enums.append (currentEnum);
     debugMsg (3, "Get Vars Enum Type Add to Prog",currentType);
   }
#line 3038 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 152:
#line 1055 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
     currentType = (yyvsp[0].jointure)->name;
     currentProgram->unions.append ((yyvsp[0].jointure));
     debugMsg (3, "Get Vars Union Type Add to prog",currentType);
   }
#line 3048 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 153:
#line 1063 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.param) = new Params (&currentType);
      (yyval.param)->type = currentType;
      (yyval.param)->name = "NoName";
      debugMsg (5, "Get NoName Param",(yyval.param)->type,(yyval.param)->name);
   }
#line 3059 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 154:
#line 1069 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.param) = new Params (&currentType);
      (yyval.param)->type = currentType;
      (yyval.param)->name = *(yyvsp[0].dString);
      free ((yyvsp[0].dString));
      debugMsg (5, "Get Named Param",(yyval.param)->type,(yyval.param)->name);
   }
#line 3071 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 155:
#line 1076 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.param) = new Params (&currentType);
      (yyval.param)->type = currentType;
      (yyval.param)->type += " ";
      (yyval.param)->type += *(yyvsp[0].dString);
      (yyval.param)->name = "NoName";
      free ((yyvsp[0].dString));
      debugMsg (5, "Get Complex NoName Param",(yyval.param)->type,(yyval.param)->name);
   }
#line 3085 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 156:
#line 1085 "yaccFrontendCc.y" /* yacc.c:1646  */
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
#line 3100 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 157:
#line 1095 "yaccFrontendCc.y" /* yacc.c:1646  */
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
#line 3115 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 158:
#line 1105 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentMethod->valid=FALSE;
      yycc_IgnoreUntilBalancedBrace (1);
      debugMsg (11, "Ignoring function with FUNC as param");
   }
#line 3125 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 159:
#line 1114 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentProgram->implement= *(yyvsp[-1].dString);
      currentProgram->assertLine= currentProgram->numLine;
      debugMsg (5, "assert implementation", currentProgram->implement);
      yycc_IgnoreUntilEOL();  // restart Lex searching
    }
#line 3136 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 160:
#line 1119 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentProgram->implement= *(yyvsp[0].dString);
      currentProgram->assertLine= currentProgram->numLine;
      debugMsg (5, "assert implementation", currentProgram->implement);
    }
#line 3146 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 161:
#line 1126 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      currentProgram->help =  *(yyvsp[0].dString);
      debugMsg (5, "PrgName Help", currentProgram->help);
    }
#line 3155 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 162:
#line 1133 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      if (strcmp (*(yyvsp[0].dString), currentProgram->ownerName)) {
        debugMsg (2, "CppFileLine", *(yyvsp[0].dString));
        currentProgram->ownerName = *(yyvsp[0].dString);
      }
      currentProgram->ownerLine = (yyvsp[-1].intVar);
      yycc_IgnoreUntilEOL();
    }
#line 3168 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 163:
#line 1144 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
  if (verbose) {
    fprintf (stderr, "********************************************************\n");
    fprintf (stderr, "| %s\n", (char*)*(yyvsp[0].dString));
    fprintf (stderr, "********************************************************\n");
  };
  free ((yyvsp[0].dString));
}
#line 3181 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 165:
#line 1155 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    currentType = "";
  }
#line 3189 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 166:
#line 1161 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    debugMsg (11, "Ignoring Block");
    yyclearin;
    yycc_IgnoreUntilEOB(0);
  }
#line 3199 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 167:
#line 1169 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    (yyval.intVar) = (yyvsp[-1].intVar);
  }
#line 3207 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 168:
#line 1172 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    (yyval.intVar) = 0;
  }
#line 3215 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 169:
#line 1178 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    (yyval.dString) =new McString("*");
  }
#line 3223 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 170:
#line 1181 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    (yyval.dString)  =   (yyvsp[-1].dString);
    *(yyval.dString)  += "*";
  }
#line 3232 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 171:
#line 1188 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.dString) = (yyvsp[0].dString);
      debugMsg (5, "Ptr Type",*(yyval.dString));
    }
#line 3241 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 172:
#line 1192 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.dString) = (yyvsp[0].dString);
      debugMsg (5, "Complex Type",*(yyval.dString));
    }
#line 3250 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 173:
#line 1196 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
      (yyval.dString) = (yyvsp[-1].dString);
      *(yyval.dString) += *(yyvsp[0].dString);
      free ((yyvsp[0].dString));
      debugMsg (5, "Complex Ptr Type",*(yyval.dString));
    }
#line 3261 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 174:
#line 1205 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    (yyval.dString) = (yyvsp[0].dString);
  }
#line 3269 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 175:
#line 1208 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    (yyval.dString)   =   (yyvsp[-1].dString);
    *(yyval.dString)  += *(yyvsp[0].dString);
    free ((yyvsp[0].dString));
  }
#line 3279 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 176:
#line 1216 "yaccFrontendCc.y" /* yacc.c:1646  */
    {
    debugMsg (4, "Get Basic Number");
    (yyval.intVar) = (yyvsp[0].intVar);
  }
#line 3288 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;

  case 177:
#line 1220 "yaccFrontendCc.y" /* yacc.c:1646  */
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
#line 3310 "yaccFrontendCc.cxx" /* yacc.c:1646  */
    break;


#line 3314 "yaccFrontendCc.cxx" /* yacc.c:1646  */
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
