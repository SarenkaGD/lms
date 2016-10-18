/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE tscript_yylval;

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

extern YYLTYPE tscript_yylloc;

