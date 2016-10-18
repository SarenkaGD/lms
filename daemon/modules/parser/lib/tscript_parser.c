/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         tscript_yyparse
#define yylex           tscript_yylex
#define yyerror         tscript_yyerror
#define yylval          tscript_yylval
#define yychar          tscript_yychar
#define yydebug         tscript_yydebug
#define yynerrs         tscript_yynerrs
#define yylloc          tscript_yylloc

/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 32 "tscript_parser.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include "tscript_ast.h"

	#define YYSTYPE tscript_ast_node*

	// http://lists.gnu.org/archive/html/bug-bison/2003-04/msg00045.html
	#define YYLEX_PARAM context

	int i;


/* Line 189 of yacc.c  */
#line 94 "tscript_parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END_WHILE = 258,
     WHILE = 259,
     IN = 260,
     END_FOREACH = 261,
     FOREACH = 262,
     END_FOR = 263,
     FOR = 264,
     END_IF = 265,
     ELSE = 266,
     IF = 267,
     ERROR = 268,
     CONTINUE = 269,
     EXIT = 270,
     BREAK = 271,
     AND = 272,
     OR = 273,
     DIFFERS = 274,
     EQUALS_GREATER = 275,
     EQUALS_LESS = 276,
     EQUALS = 277,
     NEG = 278,
     MATCH = 279,
     RIGHT = 280,
     LEFT = 281,
     DEC = 282,
     INC = 283,
     CONST = 284,
     END_BLOCK = 285,
     BLOCK = 286,
     EXT = 287,
     TYPEOF = 288,
     TO_NUMBER = 289,
     TO_STRING = 290,
     NULL_CONST = 291,
     NAME = 292,
     TEXT = 293,
     NUMBER = 294,
     LITERAL = 295
   };
#endif
/* Tokens.  */
#define END_WHILE 258
#define WHILE 259
#define IN 260
#define END_FOREACH 261
#define FOREACH 262
#define END_FOR 263
#define FOR 264
#define END_IF 265
#define ELSE 266
#define IF 267
#define ERROR 268
#define CONTINUE 269
#define EXIT 270
#define BREAK 271
#define AND 272
#define OR 273
#define DIFFERS 274
#define EQUALS_GREATER 275
#define EQUALS_LESS 276
#define EQUALS 277
#define NEG 278
#define MATCH 279
#define RIGHT 280
#define LEFT 281
#define DEC 282
#define INC 283
#define CONST 284
#define END_BLOCK 285
#define BLOCK 286
#define EXT 287
#define TYPEOF 288
#define TO_NUMBER 289
#define TO_STRING 290
#define NULL_CONST 291
#define NAME 292
#define TEXT 293
#define NUMBER 294
#define LITERAL 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 229 "tscript_parser.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  96
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   847

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  172

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,     2,     2,    32,    33,     2,
      54,    55,    30,    27,    57,    28,    40,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
      20,    59,    21,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    34,    58,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    22,    23,    24,    25,    29,    35,
      36,    37,    38,    39,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    16,    21,    26,
      28,    30,    32,    36,    38,    43,    47,    49,    52,    55,
      60,    64,    66,    70,    77,    82,    88,    90,    95,    99,
     103,   106,   108,   110,   112,   114,   116,   119,   122,   124,
     127,   130,   132,   136,   140,   144,   146,   150,   154,   156,
     160,   164,   166,   170,   174,   178,   182,   184,   188,   192,
     196,   198,   202,   206,   210,   214,   216,   219,   221,   225,
     227,   229,   231,   238,   249,   258,   265,   274,   276,   278,
     280,   282,   284,   287,   291,   294,   296,   299
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      87,     0,    -1,    51,    -1,    53,    -1,    52,    -1,    49,
      -1,    48,    54,    79,    55,    -1,    47,    54,    79,    55,
      -1,    46,    54,    79,    55,    -1,    62,    -1,    63,    -1,
      61,    -1,    54,    79,    55,    -1,    50,    -1,    66,    41,
      79,    56,    -1,    66,    40,    50,    -1,    66,    -1,    66,
      39,    -1,    66,    38,    -1,    71,    41,    79,    56,    -1,
      71,    40,    50,    -1,    78,    -1,    69,    57,    78,    -1,
      44,    54,    69,    55,    86,    43,    -1,    44,    58,    86,
      43,    -1,    44,    80,    58,    86,    43,    -1,    42,    -1,
      45,    54,    69,    55,    -1,    45,    54,    55,    -1,    45,
      80,    58,    -1,    45,    80,    -1,    65,    -1,    68,    -1,
      67,    -1,    70,    -1,    71,    -1,    39,    66,    -1,    38,
      66,    -1,    64,    -1,    28,    71,    -1,    26,    71,    -1,
      72,    -1,    73,    30,    72,    -1,    73,    31,    72,    -1,
      72,    32,    72,    -1,    73,    -1,    74,    27,    73,    -1,
      74,    28,    73,    -1,    74,    -1,    74,    37,    74,    -1,
      74,    36,    74,    -1,    75,    -1,    75,    20,    75,    -1,
      75,    21,    75,    -1,    75,    24,    75,    -1,    75,    23,
      75,    -1,    76,    -1,    76,    25,    76,    -1,    76,    22,
      76,    -1,    76,    35,    76,    -1,    77,    -1,    78,    19,
      77,    -1,    78,    18,    77,    -1,    78,    33,    77,    -1,
      78,    34,    77,    -1,    78,    -1,    80,    79,    -1,    79,
      -1,    66,    59,    79,    -1,    17,    -1,    16,    -1,    15,
      -1,     5,    54,    79,    55,    86,     4,    -1,    10,    54,
      85,     3,    79,     3,    85,    55,    86,     9,    -1,     8,
      54,    66,     6,    79,    55,    86,     7,    -1,    13,    54,
      79,    55,    86,    11,    -1,    13,    54,    79,    55,    86,
      12,    86,    11,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    79,    -1,    86,    85,    -1,    86,     3,    85,
      -1,    86,     3,    -1,    85,    -1,    85,     3,    -1,    86,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    71,    72,    73,    79,    85,    92,    97,
      98,   100,   101,   106,   110,   114,   119,   120,   124,   129,
     133,   139,   143,   149,   161,   172,   185,   189,   193,   197,
     201,   206,   207,   208,   209,   211,   212,   216,   220,   221,
     225,   231,   232,   236,   240,   246,   247,   251,   257,   258,
     262,   268,   269,   273,   277,   281,   287,   288,   292,   296,
     302,   303,   307,   311,   315,   320,   322,   326,   331,   336,
     340,   344,   349,   353,   357,   362,   366,   371,   372,   373,
     374,   375,   377,   381,   385,   386,   390,   392
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "';'", "END_WHILE", "WHILE", "IN",
  "END_FOREACH", "FOREACH", "END_FOR", "FOR", "END_IF", "ELSE", "IF",
  "ERROR", "CONTINUE", "EXIT", "BREAK", "AND", "OR", "'<'", "'>'",
  "DIFFERS", "EQUALS_GREATER", "EQUALS_LESS", "EQUALS", "'!'", "'+'",
  "'-'", "NEG", "'*'", "'/'", "'%'", "'&'", "'|'", "MATCH", "RIGHT",
  "LEFT", "DEC", "INC", "'.'", "'['", "CONST", "END_BLOCK", "BLOCK", "EXT",
  "TYPEOF", "TO_NUMBER", "TO_STRING", "NULL_CONST", "NAME", "TEXT",
  "NUMBER", "LITERAL", "'('", "')'", "']'", "','", "'}'", "'='", "$accept",
  "value", "type_conv", "type_of", "type_operator", "primary_expression",
  "reference", "chng_operator", "sub_variable", "argument_expression_list",
  "call_expression", "postfix_expression", "unary_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "logical_expression",
  "expression", "expressions", "assignment_statement", "jump_statement",
  "iteration_statement", "selection_statement", "statement", "statements",
  "template", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    59,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
      60,    62,   274,   275,   276,   277,    33,    43,    45,   278,
      42,    47,    37,    38,   124,   279,   280,   281,   282,   283,
      46,    91,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,    40,    41,    93,    44,   125,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    62,    62,    63,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    72,    72,    72,    72,    72,
      72,    73,    73,    73,    73,    74,    74,    74,    75,    75,
      75,    76,    76,    76,    76,    76,    77,    77,    77,    77,
      78,    78,    78,    78,    78,    79,    80,    80,    81,    82,
      82,    82,    83,    83,    83,    84,    84,    85,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     4,     4,     4,     1,
       1,     1,     3,     1,     4,     3,     1,     2,     2,     4,
       3,     1,     3,     6,     4,     5,     1,     4,     3,     3,
       2,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     2,     1,     3,     1,
       1,     1,     6,    10,     8,     6,     8,     1,     1,     1,
       1,     1,     2,     3,     2,     1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    71,    70,    69,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     5,    13,
       2,     4,     3,     0,    11,     9,    10,    38,    31,    16,
      33,    32,    34,    35,    41,    45,    48,    51,    56,    60,
      65,    81,    77,    78,    79,    80,    85,    87,     0,     0,
       0,     0,     0,    16,    40,    39,    37,    36,     0,     0,
      67,     0,     0,    30,     0,     0,     0,     0,    18,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    84,    82,     1,     0,     0,     0,
       0,     0,    21,     0,     0,    66,    28,     0,    29,     0,
       0,     0,    12,    15,     0,    68,    20,     0,    44,    42,
      43,    46,    47,    50,    49,    52,    53,    55,    54,    58,
      57,    59,    62,    61,    63,    64,    83,     0,     0,     0,
       0,     0,     0,    24,     0,    27,     8,     7,     6,    14,
      19,     0,     0,     0,     0,     0,    22,    25,    72,     0,
       0,    75,     0,    23,     0,     0,     0,    74,     0,    76,
       0,    73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    24,    25,    26,    27,    28,    53,    30,    31,   101,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      61,    42,    43,    44,    45,    46,    47,    48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -57
static const yytype_int16 yypact[] =
{
     630,   -51,   -41,   -36,   -26,   -57,   -57,   -57,    27,    27,
       8,     8,   -57,   659,   747,   -17,    -6,     7,   -57,   -57,
     -57,   -57,   -57,   776,   -57,   -57,   -57,   -57,   -57,   -14,
     -57,   -57,   -57,   -33,    32,     3,    -7,    18,   -13,   -57,
      -2,   -57,   -57,   -57,   -57,   -57,    64,   580,    95,   776,
       8,   630,   776,    44,   -33,   -33,    33,    33,   776,   630,
     -57,   688,   717,   789,   776,   776,   776,    47,   -57,   -57,
      61,   776,   776,    67,   776,   776,   776,   776,   776,   776,
     776,   776,   776,   776,   776,   776,   776,   776,   776,   776,
     776,   776,   776,   -57,   630,   -57,   -57,    59,    -5,   118,
      70,   -11,    -2,   216,   630,   -57,   -57,    13,   -57,    73,
      76,    78,   -57,   -57,    66,   -57,   -57,    79,   -57,   -57,
     -57,     3,     3,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   630,   776,   776,
     630,   630,   776,   -57,   268,   -57,   -57,   -57,   -57,   -57,
     -57,   320,    84,   131,   164,   372,    -2,   -57,   -57,   630,
     630,   -57,   630,   -57,   424,    88,   476,   -57,   630,   -57,
     528,   -57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -57,   -57,   -57,   -57,     0,   -57,   -57,    85,
     -57,    83,    30,    34,    39,     5,    22,     9,   -56,    -9,
     132,   -57,   -57,   -57,   -57,   -28,   -44,   -57
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      29,   138,   102,    49,    60,    60,   102,    73,    74,    86,
      56,    57,    87,    50,    67,   103,    89,    90,    51,    95,
      78,    79,    88,    99,    68,    69,    70,    71,    52,    80,
      81,    91,    92,    76,    77,    70,    71,    64,    82,    83,
      97,    84,    85,   100,   141,    72,   142,    29,    65,    67,
      98,    29,   105,    67,   105,   109,   110,   111,    19,    29,
     144,    66,   114,   115,    75,   117,   136,    93,   145,    12,
     142,    13,    14,    70,    71,    95,    18,    19,    20,    21,
      22,    23,    68,    69,    70,    71,   156,   125,   126,   127,
     128,    54,    55,   151,    29,    96,   154,   155,   132,   133,
     134,   135,   112,    29,    29,   118,   119,   120,   129,   130,
     131,   113,   121,   122,   137,   164,    95,   116,   166,   123,
     124,   139,   149,    95,   170,   140,    95,    95,   146,   152,
     153,   147,   165,   148,   160,   150,    95,    29,    95,   159,
      29,    29,    95,   168,    29,     0,    63,   107,     0,     0,
       0,    29,     0,     0,    29,    29,     0,     0,     0,    29,
      29,     0,    29,     0,    29,     0,    29,    94,    29,     1,
      29,     0,     2,     0,     3,   161,   162,     4,     0,     5,
       6,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    94,
       0,     1,     0,     0,     2,     0,     3,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,    12,   143,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    94,     0,     1,     0,     0,     2,     0,     3,     0,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
      12,   157,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    94,   158,     1,     0,     0,     2,     0,
       3,     0,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    94,     0,     1,     0,     0,
       2,     0,     3,     0,     0,     4,     0,     5,     6,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,    12,   163,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    94,     0,     1,
       0,   167,     2,     0,     3,     0,     0,     4,     0,     5,
       6,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    94,
       0,     1,     0,     0,     2,     0,     3,   169,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    94,     0,     1,     0,     0,     2,   171,     3,     0,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    94,     0,     1,     0,     0,     2,     0,
       3,     0,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     1,     0,     0,     2,     0,
       3,     0,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     8,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    58,     8,     0,     9,    59,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     8,     0,     9,   104,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   106,     8,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    62,     8,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,     0,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,     0,     0,   108
};

static const yytype_int16 yycheck[] =
{
       0,     6,    58,    54,    13,    14,    62,    40,    41,    22,
      10,    11,    25,    54,    23,    59,    18,    19,    54,    47,
      27,    28,    35,    51,    38,    39,    40,    41,    54,    36,
      37,    33,    34,    30,    31,    40,    41,    54,    20,    21,
      49,    23,    24,    52,    55,    59,    57,    47,    54,    58,
      50,    51,    61,    62,    63,    64,    65,    66,    50,    59,
     104,    54,    71,    72,    32,    74,    94,     3,    55,    42,
      57,    44,    45,    40,    41,   103,    49,    50,    51,    52,
      53,    54,    38,    39,    40,    41,   142,    82,    83,    84,
      85,     8,     9,   137,    94,     0,   140,   141,    89,    90,
      91,    92,    55,   103,   104,    75,    76,    77,    86,    87,
      88,    50,    78,    79,    55,   159,   144,    50,   162,    80,
      81,     3,    56,   151,   168,    55,   154,   155,    55,   138,
     139,    55,   160,    55,     3,    56,   164,   137,   166,    55,
     140,   141,   170,    55,   144,    -1,    14,    62,    -1,    -1,
      -1,   151,    -1,    -1,   154,   155,    -1,    -1,    -1,   159,
     160,    -1,   162,    -1,   164,    -1,   166,     3,   168,     5,
     170,    -1,     8,    -1,    10,    11,    12,    13,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,     3,
      -1,     5,    -1,    -1,     8,    -1,    10,    -1,    -1,    13,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     3,    -1,     5,    -1,    -1,     8,    -1,    10,    -1,
      -1,    13,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,     3,     4,     5,    -1,    -1,     8,    -1,
      10,    -1,    -1,    13,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     3,    -1,     5,    -1,    -1,
       8,    -1,    10,    -1,    -1,    13,    -1,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,     3,    -1,     5,
      -1,     7,     8,    -1,    10,    -1,    -1,    13,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,     3,
      -1,     5,    -1,    -1,     8,    -1,    10,    11,    -1,    13,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    42,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     3,    -1,     5,    -1,    -1,     8,     9,    10,    -1,
      -1,    13,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,     3,    -1,     5,    -1,    -1,     8,    -1,
      10,    -1,    -1,    13,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     5,    -1,    -1,     8,    -1,
      10,    -1,    -1,    13,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    26,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    42,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    26,    -1,    28,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    26,    -1,    28,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    26,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    26,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    42,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    42,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     8,    10,    13,    15,    16,    17,    26,    28,
      38,    39,    42,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    61,    62,    63,    64,    65,    66,
      67,    68,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    81,    82,    83,    84,    85,    86,    87,    54,
      54,    54,    54,    66,    71,    71,    66,    66,    54,    58,
      79,    80,    54,    80,    54,    54,    54,    79,    38,    39,
      40,    41,    59,    40,    41,    32,    30,    31,    27,    28,
      36,    37,    20,    21,    23,    24,    22,    25,    35,    18,
      19,    33,    34,     3,     3,    85,     0,    79,    66,    85,
      79,    69,    78,    86,    58,    79,    55,    69,    58,    79,
      79,    79,    55,    50,    79,    79,    50,    79,    72,    72,
      72,    73,    73,    74,    74,    75,    75,    75,    75,    76,
      76,    76,    77,    77,    77,    77,    85,    55,     6,     3,
      55,    55,    57,    43,    86,    55,    55,    55,    55,    56,
      56,    86,    79,    79,    86,    86,    78,    43,     4,    55,
       3,    11,    12,    43,    86,    85,    86,     7,    55,    11,
      86,     9
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      yyerror (context, YY_("syntax error: cannot back up")); \
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
# define YYLEX yylex (context)
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
		  Type, Value, Location, context); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, tscript_context* context)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, context)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    tscript_context* context;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (context);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, tscript_context* context)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, context)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    tscript_context* context;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, context);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, tscript_context* context)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, context)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    tscript_context* context;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , context);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, context); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, tscript_context* context)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, context)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    tscript_context* context;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (context);

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
int yyparse (tscript_context* context);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
yyparse (tscript_context* context)
#else
int
yyparse (context)
    tscript_context* context;
#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:

/* Line 1464 of yacc.c  */
#line 74 "tscript_parser.y"
    {
			(yyval) = tscript_ast_node_val(TSCRIPT_AST_VALUE,
				tscript_value_create_null());
		}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 80 "tscript_parser.y"
    {
			(yyval) = tscript_ast_node_1(TSCRIPT_AST_CONV, (yyvsp[(3) - (4)]));
			(yyval)->value = tscript_value_create_null();
			(yyval)->value->type = TSCRIPT_TYPE_STRING;
		}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 86 "tscript_parser.y"
    {
			(yyval) = tscript_ast_node_1(TSCRIPT_AST_CONV, (yyvsp[(3) - (4)]));
			(yyval)->value = tscript_value_create_null();
			(yyval)->value->type = TSCRIPT_TYPE_NUMBER;
		}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 93 "tscript_parser.y"
    {
			(yyval) = tscript_ast_node_1(TSCRIPT_AST_TYPEOF, (yyvsp[(3) - (4)]));
		}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 102 "tscript_parser.y"
    {
				(yyval) = (yyvsp[(2) - (3)]);
			}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 107 "tscript_parser.y"
    {
			(yyval) = tscript_ast_node_1(TSCRIPT_AST_VAR_GET, (yyvsp[(1) - (1)]));
		}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 111 "tscript_parser.y"
    {
			(yyval) = tscript_ast_node_2(TSCRIPT_AST_INDEX, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
		}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 115 "tscript_parser.y"
    {
			(yyval) = tscript_ast_node_2(TSCRIPT_AST_SUBVAR, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
		}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 121 "tscript_parser.y"
    {
			(yyval) = tscript_ast_node_1(TSCRIPT_AST_INC, (yyvsp[(1) - (2)]));
		}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 125 "tscript_parser.y"
    {
			(yyval) = tscript_ast_node_1(TSCRIPT_AST_DEC, (yyvsp[(1) - (2)]));
		}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 130 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_INDEX, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
			}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 134 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_SUBVAR, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 140 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_1(TSCRIPT_AST_ARGS, (yyvsp[(1) - (1)]));
			}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 144 "tscript_parser.y"
    {
				tscript_ast_node_add_child((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
				(yyval) = (yyvsp[(1) - (3)]);
			}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 150 "tscript_parser.y"
    {
				if (strcmp(tscript_value_as_string((yyvsp[(1) - (6)])->value),
					tscript_value_as_string((yyvsp[(6) - (6)])->value)) != 0)
				{
					yyerror(context,
						"block extension begin and end mismatch");
					YYERROR;
				}
				tscript_ast_node_add_child((yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]));
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_EXT, (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]));
			}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 162 "tscript_parser.y"
    {
				if (strcmp(tscript_value_as_string((yyvsp[(1) - (4)])->value),
					tscript_value_as_string((yyvsp[(4) - (4)])->value)) != 0)
				{
					yyerror(context,
						"block extension begin and end mismatch");
					YYERROR;
				}
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_EXT, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
			}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 173 "tscript_parser.y"
    {
				if (strcmp(tscript_value_as_string((yyvsp[(1) - (5)])->value),
					tscript_value_as_string((yyvsp[(5) - (5)])->value)) != 0)
				{
					yyerror(context,
						"block extension begin and end mismatch");
					YYERROR;
				}
				(yyval) = tscript_ast_node_1(TSCRIPT_AST_ARGS, (yyvsp[(2) - (5)]));
				tscript_ast_node_add_child((yyval), (yyvsp[(4) - (5)]));
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_EXT, (yyvsp[(1) - (5)]), (yyval));
			}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 186 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_1(TSCRIPT_AST_CONST, (yyvsp[(1) - (1)]));
			}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 190 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_EXT, (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
			}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 194 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_1(TSCRIPT_AST_EXT, (yyvsp[(1) - (3)]));
			}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 198 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_EXT, (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));
			}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 202 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_EXT, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
			}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 213 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_1(TSCRIPT_AST_UN_INC, (yyvsp[(2) - (2)]));
			}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 217 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_1(TSCRIPT_AST_UN_DEC, (yyvsp[(2) - (2)]));
			}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 222 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_1(TSCRIPT_AST_NEG, (yyvsp[(2) - (2)]));
			}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 226 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_1(TSCRIPT_AST_NOT, (yyvsp[(2) - (2)]));
			}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 233 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_MUL, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 237 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_DIV, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 241 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_MOD, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 248 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_PLUS, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 252 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_MINUS, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 259 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_LEFT, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 263 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_RIGHT, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 270 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_LESS, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 274 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_GREATER, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 278 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_EQUALS_LESS, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 282 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_EQUALS_GREATER, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 289 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_EQUALS, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 293 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_DIFFERS, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 297 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_MATCH, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 304 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_OR, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 308 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_AND, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 312 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_BAND, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 316 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_BOR, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 323 "tscript_parser.y"
    {
			(yyval) = tscript_ast_node_2(TSCRIPT_AST_SEQ, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
		}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 327 "tscript_parser.y"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 332 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_VAR_SET, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
			}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 337 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_0(TSCRIPT_AST_BREAK);
			}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 341 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_0(TSCRIPT_AST_EXIT);
			}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 345 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_0(TSCRIPT_AST_CONTINUE);
			}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 350 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_WHILE, (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]));
			}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 354 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_4(TSCRIPT_AST_FOR, (yyvsp[(3) - (10)]), (yyvsp[(5) - (10)]), (yyvsp[(7) - (10)]), (yyvsp[(9) - (10)]));
			}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 358 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_3(TSCRIPT_AST_FOREACH, (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
			}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 363 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_2(TSCRIPT_AST_IF, (yyvsp[(3) - (6)]), (yyvsp[(5) - (6)]));
			}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 367 "tscript_parser.y"
    {
				(yyval) = tscript_ast_node_3(TSCRIPT_AST_IF, (yyvsp[(3) - (8)]), (yyvsp[(5) - (8)]), (yyvsp[(7) - (8)]));
			}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 378 "tscript_parser.y"
    {
			(yyval) = tscript_ast_node_2(TSCRIPT_AST_SEQ, (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
		}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 382 "tscript_parser.y"
    {
			(yyval) = tscript_ast_node_2(TSCRIPT_AST_SEQ, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
		}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 387 "tscript_parser.y"
    {
			(yyval) = (yyvsp[(1) - (1)]);
		}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 393 "tscript_parser.y"
    {
			context->ast = (yyvsp[(1) - (1)]);
		}
    break;



/* Line 1464 of yacc.c  */
#line 2327 "tscript_parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
      yyerror (context, YY_("syntax error"));
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
	    yyerror (context, yymsg);
	  }
	else
	  {
	    yyerror (context, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc, context);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, context);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (context, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, context);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, context);
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



/* Line 1684 of yacc.c  */
#line 397 "tscript_parser.y"



