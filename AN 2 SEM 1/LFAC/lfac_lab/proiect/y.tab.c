/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOL = 258,
     NOT = 259,
     TRUE = 260,
     FALSE = 261,
     INT = 262,
     FLOAT = 263,
     NR = 264,
     NRF = 265,
     CHAR = 266,
     STRING = 267,
     CARACTER = 268,
     CUVANT = 269,
     MAREEGAL = 270,
     MICEGAL = 271,
     DEF = 272,
     BEG = 273,
     END = 274,
     STRUCT = 275,
     CONST = 276,
     IF = 277,
     THEN = 278,
     ELSE = 279,
     WHILE = 280,
     FOR = 281,
     AND = 282,
     OR = 283,
     XOR = 284
   };
#endif
/* Tokens.  */
#define BOOL 258
#define NOT 259
#define TRUE 260
#define FALSE 261
#define INT 262
#define FLOAT 263
#define NR 264
#define NRF 265
#define CHAR 266
#define STRING 267
#define CARACTER 268
#define CUVANT 269
#define MAREEGAL 270
#define MICEGAL 271
#define DEF 272
#define BEG 273
#define END 274
#define STRUCT 275
#define CONST 276
#define IF 277
#define THEN 278
#define ELSE 279
#define WHILE 280
#define FOR 281
#define AND 282
#define OR 283
#define XOR 284




/* Copy the first part of user declarations.  */
#line 1 "proj.y"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
extern FILE* yyin;
extern FILE* yyout;
extern char* yytext;
extern int yylineno;
int yyerror(char* s){
printf("eroare %s linia %d\n",s,yylineno);
}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "proj.y"
{
int intval;
char* strval;
}
/* Line 193 of yacc.c.  */
#line 172 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 185 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   535

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNRULES -- Number of states.  */
#define YYNSTATES  359

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    47,     2,    32,     2,     2,
      39,    40,    30,    33,    43,    34,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      45,    46,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,    36,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    11,    15,    18,    22,    24,    26,
      28,    30,    35,    40,    45,    50,    55,    63,    68,    70,
      72,    74,    76,    78,    80,    82,    84,    93,    96,    99,
     103,   107,   109,   113,   115,   117,   119,   121,   123,   125,
     127,   129,   131,   133,   135,   137,   142,   147,   152,   157,
     162,   167,   170,   173,   178,   188,   193,   203,   208,   216,
     221,   231,   236,   241,   251,   253,   257,   259,   263,   265,
     269,   271,   275,   281,   283,   285,   290,   297,   301,   302,
     306,   310,   319,   323,   332,   336,   343,   347,   356,   360,
     369,   373,   377,   381,   385,   389,   391,   395,   399,   403,
     407,   412,   414,   416,   418,   422,   426,   430,   434,   438,
     442,   444,   448,   452,   456,   460,   464,   468,   473,   475,
     477,   479,   481,   486,   488,   492,   494,   496,   498,   500,
     502,   504,   506,   508,   510,   514,   518,   520,   522,   529,
     540,   546
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    18,    51,    19,    -1,    52,    35,
      -1,    52,    35,    50,    -1,    54,    35,    -1,    54,    35,
      51,    -1,    55,    -1,    62,    -1,    53,    -1,    67,    -1,
      21,     7,    36,     9,    -1,    21,     8,    36,    10,    -1,
      21,     3,    36,     5,    -1,    21,     3,    36,     6,    -1,
      21,    11,    36,    13,    -1,    21,    11,    37,     9,    38,
      36,    14,    -1,    21,    12,    36,    14,    -1,    69,    -1,
      70,    -1,    72,    -1,    77,    -1,    74,    -1,    78,    -1,
      79,    -1,    80,    -1,    17,    58,    39,    57,    40,    41,
      56,    42,    -1,    54,    35,    -1,    62,    35,    -1,    54,
      35,    56,    -1,    62,    35,    56,    -1,    60,    -1,    60,
      43,    57,    -1,    59,    -1,     7,    -1,     8,    -1,    11,
      -1,    12,    -1,     3,    -1,     7,    -1,     8,    -1,    11,
      -1,    12,    -1,     3,    -1,    61,    -1,     7,    37,     9,
      38,    -1,     8,    37,     9,    38,    -1,    11,    37,     9,
      38,    -1,    12,    37,     9,    38,    -1,     3,    37,     9,
      38,    -1,    61,    37,     9,    38,    -1,    17,    59,    -1,
      17,    61,    -1,    17,     7,    36,     9,    -1,    17,     7,
      37,     9,    38,    36,    41,    65,    42,    -1,    17,     8,
      36,    10,    -1,    17,     8,    37,     9,    38,    36,    41,
      63,    42,    -1,    17,    11,    36,    13,    -1,    17,    11,
      37,     9,    38,    36,    14,    -1,    17,    12,    36,    14,
      -1,    17,    12,    37,     9,    38,    36,    41,    66,    42,
      -1,    17,     3,    36,     5,    -1,    17,     3,    36,     6,
      -1,    17,     3,    37,     9,    38,    36,    41,    64,    42,
      -1,    72,    -1,    72,    43,    63,    -1,    70,    -1,    70,
      43,    64,    -1,    72,    -1,    72,    43,    65,    -1,    14,
      -1,    14,    43,    66,    -1,    17,    20,    39,    68,    40,
      -1,    60,    -1,    69,    -1,    58,    39,    57,    40,    -1,
      68,    43,    58,    39,    57,    40,    -1,    68,    43,    60,
      -1,    -1,    68,    43,    69,    -1,     7,    36,    72,    -1,
       7,    37,     9,    38,    36,    41,    65,    42,    -1,     8,
      36,    72,    -1,     8,    37,     9,    38,    36,    41,    63,
      42,    -1,    11,    36,    13,    -1,    11,    37,     9,    38,
      36,    14,    -1,    12,    36,    14,    -1,    12,    37,     9,
      38,    36,    41,    66,    42,    -1,     3,    36,    70,    -1,
       3,    37,     9,    38,    36,    41,    64,    42,    -1,     7,
      36,    74,    -1,     8,    36,    74,    -1,     3,    36,    74,
      -1,    12,    36,    74,    -1,    11,    36,    74,    -1,    71,
      -1,    70,    27,    70,    -1,    70,    28,    70,    -1,    70,
      29,    70,    -1,    39,    70,    40,    -1,     4,    39,    70,
      40,    -1,     3,    -1,     5,    -1,     6,    -1,    72,    44,
      72,    -1,    72,    45,    72,    -1,    72,    46,    72,    -1,
      72,    47,    72,    -1,    72,    15,    72,    -1,    72,    16,
      72,    -1,    73,    -1,    72,    30,    72,    -1,    72,    31,
      72,    -1,    72,    32,    72,    -1,    72,    33,    72,    -1,
      72,    34,    72,    -1,    39,    72,    40,    -1,    34,    39,
      72,    40,    -1,     9,    -1,    10,    -1,     7,    -1,     8,
      -1,    58,    39,    75,    40,    -1,    76,    -1,    76,    43,
      75,    -1,    61,    -1,    12,    -1,    11,    -1,    13,    -1,
      14,    -1,    72,    -1,    70,    -1,    74,    -1,    53,    -1,
      77,    33,    77,    -1,    77,    30,     9,    -1,    12,    -1,
      14,    -1,    22,    70,    23,    41,    51,    42,    -1,    22,
      70,    23,    41,    51,    42,    24,    41,    51,    42,    -1,
      25,    70,    41,    51,    42,    -1,    26,    69,    35,    70,
      35,    72,    41,    51,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    34,    34,    37,    38,    41,    42,    45,    46,    47,
      48,    51,    52,    53,    54,    55,    56,    57,    60,    61,
      62,    63,    64,    65,    66,    67,    70,    73,    74,    75,
      76,    79,    80,    83,    86,    87,    88,    89,    90,    93,
      94,    95,    96,    97,    98,   101,   102,   103,   104,   105,
     106,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   141,   142,   146,   147,   150,   151,
     154,   155,   158,   161,   162,   163,   164,   165,   166,   166,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   186,   187,   188,   189,   190,
     191,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     205,   206,   207,   208,   209,   210,   211,   212,   215,   216,
     217,   218,   221,   224,   225,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   239,   240,   241,   242,   245,   246,
     249,   252
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "NOT", "TRUE", "FALSE", "INT",
  "FLOAT", "NR", "NRF", "CHAR", "STRING", "CARACTER", "CUVANT", "MAREEGAL",
  "MICEGAL", "DEF", "BEG", "END", "STRUCT", "CONST", "IF", "THEN", "ELSE",
  "WHILE", "FOR", "AND", "OR", "XOR", "'*'", "'/'", "'%'", "'+'", "'-'",
  "';'", "'~'", "'['", "']'", "'('", "')'", "'{'", "'}'", "','", "'>'",
  "'<'", "'='", "'#'", "$accept", "progr", "instructiuni_globale",
  "instructiuni", "instr_globala", "constanta", "instr",
  "declaratie_functie", "instructiuni_functii", "lista_parametri", "fnc",
  "tip", "parametru", "tablou", "initializare", "lista_valori_reale",
  "lista_valori_booleene", "lista_valori_intregi", "lista_cuvinte",
  "declaratie_struct", "lista_parametri_struct", "asignare",
  "expresie_booleena", "exp_bool", "expresie_aritmetica", "exp_aritm",
  "apel_functie", "lista_parametri_extinsa", "parametri_extinsi",
  "expresie_str", "daca", "cat_timp", "pentru", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      42,    47,    37,    43,    45,    59,   126,    91,    93,    40,
      41,   123,   125,    44,    62,    60,    61,    35
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    52,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    56,    56,    56,
      56,    57,    57,    58,    59,    59,    59,    59,    59,    60,
      60,    60,    60,    60,    60,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    74,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    77,    77,    78,    78,
      79,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     3,     2,     3,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     7,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     8,     2,     2,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     2,     2,     4,     9,     4,     9,     4,     7,     4,
       9,     4,     4,     9,     1,     3,     1,     3,     1,     3,
       1,     3,     5,     1,     1,     4,     6,     3,     0,     3,
       3,     8,     3,     8,     3,     6,     3,     8,     3,     8,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       4,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     4,     1,     1,
       1,     1,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     6,    10,
       5,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     9,     7,     8,    10,
      38,    34,    35,    36,    37,     0,     0,    33,    52,     0,
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,   101,     0,   102,   103,
     120,   121,   118,   119,    36,   136,   137,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    18,    19,    95,    20,
     110,    22,    21,    23,    24,    25,     4,    61,    62,     0,
      53,     0,    55,     0,    57,     0,    59,     0,    43,    39,
      40,    41,    42,     0,    73,    44,     0,    74,    43,    39,
      40,    41,    42,     0,    31,     0,    13,    14,    11,    12,
      15,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    45,
      46,    47,    48,     0,     0,     0,     0,     0,     0,    72,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
     101,   120,   121,    36,    37,    88,    92,     0,     0,    38,
       0,    80,    90,     0,    82,    91,     0,    34,    35,    84,
      94,     0,    86,    93,     0,     0,     0,     0,     0,    99,
     116,     6,   101,   120,   121,   127,   126,   128,   129,   133,
     125,   131,   130,   132,     0,   123,    96,    97,    98,   108,
     109,   111,   112,   113,   114,   115,   104,   105,   106,   107,
     135,   136,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    79,     0,     0,     0,
       0,     0,     0,    32,     0,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   122,     0,     0,     0,
       0,    58,     0,    49,    45,    46,    47,    48,    75,     0,
      49,    45,    46,    47,    48,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,     0,   140,     0,   124,     0,
      66,     0,    68,     0,    64,    70,     0,     0,    51,    27,
      26,    28,     0,     0,     0,    85,     0,   138,     0,    63,
       0,    54,     0,    56,     0,     0,    60,    76,    29,    30,
       0,     0,     0,     0,     0,     0,    67,    69,    65,    71,
      89,    81,    83,    87,     0,     0,     0,   141,   139
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    62,     5,     6,    63,     7,   297,   103,
      64,    65,   104,    95,   298,   313,   309,   311,   316,     9,
      96,    66,    67,    68,   128,    70,    71,   224,   225,    72,
      73,    74,    75
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -309
static const yytype_int16 yypact[] =
{
       3,   155,    68,    18,     5,     4,  -309,  -309,  -309,  -309,
      77,    82,   136,   171,   203,    35,    39,    34,    61,    74,
      99,   103,   254,   123,  -309,    78,     3,   211,   173,   192,
     204,   154,   234,   233,   278,   298,   309,   281,   356,   334,
     320,   364,   373,   378,   386,   385,   141,   348,  -309,  -309,
     269,   274,  -309,  -309,   285,   345,  -309,   190,   190,   358,
     377,   190,   398,   383,   380,  -309,  -309,   240,  -309,   270,
    -309,  -309,    21,  -309,  -309,  -309,  -309,  -309,  -309,   382,
    -309,   387,  -309,   388,  -309,   389,  -309,   390,   349,   353,
     357,   361,   365,   391,  -309,    61,    59,  -309,   392,   394,
     395,   396,   397,   399,   379,   400,  -309,  -309,  -309,  -309,
    -309,   402,  -309,   180,   412,   190,    22,   414,    22,   415,
     333,   426,   316,   427,  -309,  -309,  -309,   221,   270,   128,
     341,   370,   372,   285,   374,   406,    98,   183,   226,  -309,
      78,   140,   190,   190,   190,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,   428,   119,   407,   408,
     409,   410,   411,   433,   439,   440,   441,   442,   356,  -309,
     281,   443,   444,   445,   446,   447,   416,   356,  -309,   422,
     420,   421,   423,  -309,  -309,   240,  -309,   425,   198,  -309,
      98,   231,  -309,   429,   231,  -309,   430,  -309,  -309,  -309,
    -309,   431,  -309,  -309,   432,   424,    78,   190,   317,  -309,
    -309,  -309,   131,   214,   237,   321,   335,  -309,  -309,  -309,
      61,   240,   270,  -309,   434,   418,   384,   435,  -309,   231,
     231,   247,   305,   381,   437,  -309,   231,   231,   231,   231,
    -309,  -309,  -309,   436,   438,   448,   452,   449,   450,   453,
     454,   455,   456,   457,   459,  -309,  -309,   458,   461,   462,
     463,   464,    38,  -309,   466,   451,  -309,   322,   467,   468,
     469,   470,    78,   465,   193,  -309,  -309,   140,   190,    98,
      98,  -309,   471,   451,   467,   468,   469,   470,  -309,   356,
    -309,  -309,  -309,  -309,  -309,   368,   460,   472,   473,  -309,
     474,   475,   476,   495,   477,   478,  -309,    98,  -309,   479,
      30,   480,   172,   481,   202,   482,   484,   487,  -309,    38,
    -309,    38,   190,    98,    98,  -309,   471,   486,   301,  -309,
     190,  -309,    98,  -309,    98,   471,  -309,  -309,  -309,  -309,
     488,   489,   490,   491,   483,    78,  -309,  -309,  -309,  -309,
    -309,  -309,  -309,  -309,    78,   492,   493,  -309,  -309
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -309,  -309,   485,  -136,  -309,  -135,  -254,  -309,    84,  -155,
       1,     2,   -30,     0,     9,  -308,  -221,  -295,  -273,  -309,
    -309,   -32,   -47,  -309,   -25,  -309,  -101,   195,  -309,   318,
    -309,  -309,  -309
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -52
static const yytype_int16 yytable[] =
{
      69,    18,    16,    17,   211,    97,   219,    94,   296,     8,
     127,   129,   186,   253,   137,   192,   342,   195,    24,   200,
       1,   203,   263,    25,     2,   189,   348,   135,   341,   181,
     182,    52,    53,   183,   184,     8,   138,   347,    93,    26,
     223,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,   156,    56,   343,   157,   295,    60,   142,   143,   144,
      57,   190,   349,    58,    59,   296,   185,   296,   188,   -51,
     273,    19,    60,   330,    37,    20,    21,    61,    38,    22,
      23,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,   191,    56,   194,   221,   226,   227,   228,    39,   169,
      57,   340,   170,    58,    59,   125,   126,    52,    53,   346,
      40,   208,    60,    27,    28,    69,   222,    61,    29,    30,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   241,    60,    56,   317,    41,   305,   190,   256,    42,
     255,   220,   219,   212,    47,    48,    49,   213,   214,    52,
      53,   215,   216,   217,   218,   142,   143,   144,    10,    45,
     274,     2,    11,    12,    82,   267,    13,    14,   171,   206,
     -38,   254,    31,    32,    60,    15,   223,   113,   114,    61,
     -38,    69,    79,   180,    47,    48,    49,   181,   182,    52,
      53,   183,   184,   124,    47,    48,    49,   125,   126,    52,
      53,    80,   147,   148,   149,   150,   151,    33,    34,   355,
     142,   143,   144,    81,    60,   332,    77,    78,   356,    61,
     142,   143,   144,   209,    60,   142,   143,   144,   307,    61,
     221,   310,   147,   148,   149,   150,   151,    69,   266,    35,
      36,   145,   146,    83,   205,   334,    84,    69,   142,   143,
     144,   172,   222,   -34,   312,   314,   147,   148,   149,   150,
     151,   147,   148,   149,   150,   151,   210,   142,   143,   144,
     152,   153,   154,   155,   173,   310,   -35,   220,   148,   149,
     150,   151,   328,   310,    88,   145,   146,    85,    89,    90,
      43,    44,    91,    92,    69,    18,    69,   318,   312,   314,
     147,   148,   149,   150,   151,   116,   117,   312,   -34,   314,
     118,   119,    86,   -35,   152,   153,   154,   155,    87,   189,
      69,   120,   121,   197,   198,   106,   107,   183,   184,    69,
     202,   147,   148,   149,   150,   151,   189,   149,   150,   151,
     197,   198,   345,   105,   183,   184,   199,   147,   148,   149,
     150,   151,   147,   148,   149,   150,   151,   275,   174,    98,
     -36,   130,   210,    99,   100,   131,   132,   101,   102,   133,
     134,    10,   175,   108,   -37,    11,    12,   113,   114,    13,
      14,   122,   123,   109,   -37,   113,   163,   115,   -38,   116,
     164,   110,   -34,   118,   165,   111,   -35,   120,   166,   112,
     -36,   122,   167,   338,   -37,   339,   116,   117,   118,   119,
     122,   123,   143,   144,   150,   151,   136,   139,   140,   141,
     158,   187,   177,   193,   196,   159,   160,   161,   162,   171,
     168,   172,   173,   174,   175,   201,   204,   240,   178,   176,
     179,   207,   248,   243,   244,   245,   246,   247,   249,   250,
     251,   252,   257,   258,   259,   260,   261,   262,   264,   -38,
     -34,   277,   -35,   265,   144,   272,   281,   268,   269,   270,
     271,   151,   308,     0,   276,   242,     0,   278,     0,   279,
     299,     0,     0,     0,     0,   315,     0,   300,   283,   280,
     282,   284,   285,   286,   287,   319,   290,   288,   289,   291,
     292,   293,   294,   301,   302,   303,   304,   306,   321,   325,
     344,    76,     0,     0,   320,   322,   323,   324,   326,     0,
     327,   329,   331,   333,   354,   335,   336,   337,     0,     0,
     350,   351,   352,   353,   357,   358
};

static const yytype_int16 yycheck[] =
{
      25,     1,     1,     1,   140,    37,   141,    37,   262,     0,
      57,    58,   113,   168,    61,   116,   324,   118,     0,   120,
      17,   122,   177,    18,    21,     3,   334,    59,   323,     7,
       8,     9,    10,    11,    12,    26,    61,   332,    37,    35,
     141,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    30,    14,   326,    33,    17,    34,    27,    28,    29,
      22,    39,   335,    25,    26,   319,   113,   321,   115,    35,
     206,     3,    34,    43,    39,     7,     8,    39,    39,    11,
      12,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   116,    14,   118,   141,   142,   143,   144,    37,    40,
      22,   322,    43,    25,    26,     7,     8,     9,    10,   330,
      36,   136,    34,    36,    37,   140,   141,    39,    36,    37,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    12,    34,    14,   289,    36,   272,    39,   170,    36,
     170,   141,   277,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    27,    28,    29,     3,    36,
     207,    21,     7,     8,    10,   190,    11,    12,    37,    41,
      39,   170,    36,    37,    34,    20,   277,    36,    37,    39,
      39,   206,     9,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     3,     4,     5,     6,     7,     8,     9,
      10,     9,    30,    31,    32,    33,    34,    36,    37,   345,
      27,    28,    29,     9,    34,    43,     5,     6,   354,    39,
      27,    28,    29,    40,    34,    27,    28,    29,    35,    39,
     277,   278,    30,    31,    32,    33,    34,   262,    40,    36,
      37,    15,    16,     9,    23,    43,    13,   272,    27,    28,
      29,    37,   277,    39,   279,   280,    30,    31,    32,    33,
      34,    30,    31,    32,    33,    34,    40,    27,    28,    29,
      44,    45,    46,    47,    37,   322,    39,   277,    31,    32,
      33,    34,   307,   330,     3,    15,    16,     9,     7,     8,
      36,    37,    11,    12,   319,   295,   321,   295,   323,   324,
      30,    31,    32,    33,    34,    36,    37,   332,    39,   334,
      36,    37,    14,    39,    44,    45,    46,    47,     9,     3,
     345,    36,    37,     7,     8,     5,     6,    11,    12,   354,
      14,    30,    31,    32,    33,    34,     3,    32,    33,    34,
       7,     8,    41,     9,    11,    12,    13,    30,    31,    32,
      33,    34,    30,    31,    32,    33,    34,    40,    37,     3,
      39,     3,    40,     7,     8,     7,     8,    11,    12,    11,
      12,     3,    37,     9,    39,     7,     8,    36,    37,    11,
      12,    36,    37,    10,    39,    36,    37,    39,    39,    36,
      37,    13,    39,    36,    37,     9,    39,    36,    37,    14,
      39,    36,    37,   319,    39,   321,    36,    37,    36,    37,
      36,    37,    28,    29,    33,    34,    39,    19,    35,    39,
      38,     9,    43,     9,     9,    38,    38,    38,    38,    37,
      39,    37,    37,    37,    37,     9,     9,     9,    38,    40,
      38,    35,     9,    36,    36,    36,    36,    36,     9,     9,
       9,     9,     9,     9,     9,     9,     9,    41,    36,    39,
      39,    43,    39,    38,    29,    41,    14,    38,    38,    38,
      38,    34,   277,    -1,    40,   157,    -1,    41,    -1,    41,
      14,    -1,    -1,    -1,    -1,    14,    -1,    36,    38,    41,
      41,    38,    38,    38,    38,    35,    38,    40,    39,    38,
      38,    38,    38,    36,    36,    36,    36,    42,    35,    14,
      24,    26,    -1,    -1,    42,    41,    41,    41,    41,    -1,
      42,    42,    42,    42,    41,    43,    42,    40,    -1,    -1,
      42,    42,    42,    42,    42,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    21,    49,    50,    52,    53,    55,    62,    67,
       3,     7,     8,    11,    12,    20,    58,    59,    61,     3,
       7,     8,    11,    12,     0,    18,    35,    36,    37,    36,
      37,    36,    37,    36,    37,    36,    37,    39,    39,    37,
      36,    36,    36,    36,    37,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    14,    22,    25,    26,
      34,    39,    51,    54,    58,    59,    69,    70,    71,    72,
      73,    74,    77,    78,    79,    80,    50,     5,     6,     9,
       9,     9,    10,     9,    13,     9,    14,     9,     3,     7,
       8,    11,    12,    58,    60,    61,    68,    69,     3,     7,
       8,    11,    12,    57,    60,     9,     5,     6,     9,    10,
      13,     9,    14,    36,    37,    39,    36,    37,    36,    37,
      36,    37,    36,    37,     3,     7,     8,    70,    72,    70,
       3,     7,     8,    11,    12,    69,    39,    70,    72,    19,
      35,    39,    27,    28,    29,    15,    16,    30,    31,    32,
      33,    34,    44,    45,    46,    47,    30,    33,    38,    38,
      38,    38,    38,    37,    37,    37,    37,    37,    39,    40,
      43,    37,    37,    37,    37,    37,    40,    43,    38,    38,
       3,     7,     8,    11,    12,    70,    74,     9,    70,     3,
      39,    72,    74,     9,    72,    74,     9,     7,     8,    13,
      74,     9,    14,    74,     9,    23,    41,    35,    72,    40,
      40,    51,     3,     7,     8,    11,    12,    13,    14,    53,
      61,    70,    72,    74,    75,    76,    70,    70,    70,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
       9,    12,    77,    36,    36,    36,    36,    36,     9,     9,
       9,     9,     9,    57,    58,    60,    69,     9,     9,     9,
       9,     9,    41,    57,    36,    38,    40,    72,    38,    38,
      38,    38,    41,    51,    70,    40,    40,    43,    41,    41,
      41,    14,    41,    38,    38,    38,    38,    38,    40,    39,
      38,    38,    38,    38,    38,    17,    54,    56,    62,    14,
      36,    36,    36,    36,    36,    51,    42,    35,    75,    64,
      70,    65,    72,    63,    72,    14,    66,    57,    59,    35,
      42,    35,    41,    41,    41,    14,    41,    42,    72,    42,
      43,    42,    43,    42,    43,    43,    42,    40,    56,    56,
      64,    65,    63,    66,    24,    41,    64,    65,    63,    66,
      42,    42,    42,    42,    41,    51,    51,    42,    42
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 34 "proj.y"
    {printf ("input acceptat!\n");}
    break;

  case 34:
#line 86 "proj.y"
    { fprintf(yyout, "| %s | variabila ",(yyval.strval)); fprintf(yyout, "| tip : INT |"); }
    break;

  case 51:
#line 110 "proj.y"
    { fprintf(yyout, "\n"); }
    break;


/* Line 1267 of yacc.c.  */
#line 1726 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 256 "proj.y"

int main(int argc,char** argv)
{
    yyout=fopen(argv[2],"w");
    yyin=fopen(argv[1],"r");
    fprintf(yyout, "start...\n");
    yyparse();
    fclose(yyout);
}
