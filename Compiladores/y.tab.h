/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_NUM = 258,                  /* TK_NUM  */
    TK_REAL = 259,                 /* TK_REAL  */
    TK_TRUE = 260,                 /* TK_TRUE  */
    TK_FALSE = 261,                /* TK_FALSE  */
    TK_CHAR = 262,                 /* TK_CHAR  */
    TK_STRING = 263,               /* TK_STRING  */
    TK_IF = 264,                   /* TK_IF  */
    TK_ELSE = 265,                 /* TK_ELSE  */
    TK_FOR = 266,                  /* TK_FOR  */
    TK_WHILE = 267,                /* TK_WHILE  */
    TK_DO = 268,                   /* TK_DO  */
    TK_SWITCH = 269,               /* TK_SWITCH  */
    TK_CASE = 270,                 /* TK_CASE  */
    TK_DP = 271,                   /* TK_DP  */
    TK_DEFAULT = 272,              /* TK_DEFAULT  */
    TK_PRINT = 273,                /* TK_PRINT  */
    TK_SCAN = 274,                 /* TK_SCAN  */
    TK_BREAK = 275,                /* TK_BREAK  */
    TK_CONTINUE = 276,             /* TK_CONTINUE  */
    TK_RETURN = 277,               /* TK_RETURN  */
    TK_TIPO_VOID = 278,            /* TK_TIPO_VOID  */
    TK_QB = 279,                   /* TK_QB  */
    TK_COMENT = 280,               /* TK_COMENT  */
    TK_MAIN = 281,                 /* TK_MAIN  */
    TK_ID = 282,                   /* TK_ID  */
    TK_TIPO_INT = 283,             /* TK_TIPO_INT  */
    TK_TIPO_FLOAT = 284,           /* TK_TIPO_FLOAT  */
    TK_TIPO_BOOL = 285,            /* TK_TIPO_BOOL  */
    TK_CAST_FLOAT = 286,           /* TK_CAST_FLOAT  */
    TK_CAST_INT = 287,             /* TK_CAST_INT  */
    TK_CAST_BOOL = 288,            /* TK_CAST_BOOL  */
    TK_TIPO_CHAR = 289,            /* TK_TIPO_CHAR  */
    TK_TIPO_STRING = 290,          /* TK_TIPO_STRING  */
    TK_FIM = 291,                  /* TK_FIM  */
    TK_ERROR = 292,                /* TK_ERROR  */
    AND = 293,                     /* AND  */
    OR = 294,                      /* OR  */
    NO = 295,                      /* NO  */
    EQ = 296,                      /* EQ  */
    NE = 297,                      /* NE  */
    GE = 298,                      /* GE  */
    LE = 299,                      /* LE  */
    TK_CAST_CHAR = 300             /* TK_CAST_CHAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_NUM 258
#define TK_REAL 259
#define TK_TRUE 260
#define TK_FALSE 261
#define TK_CHAR 262
#define TK_STRING 263
#define TK_IF 264
#define TK_ELSE 265
#define TK_FOR 266
#define TK_WHILE 267
#define TK_DO 268
#define TK_SWITCH 269
#define TK_CASE 270
#define TK_DP 271
#define TK_DEFAULT 272
#define TK_PRINT 273
#define TK_SCAN 274
#define TK_BREAK 275
#define TK_CONTINUE 276
#define TK_RETURN 277
#define TK_TIPO_VOID 278
#define TK_QB 279
#define TK_COMENT 280
#define TK_MAIN 281
#define TK_ID 282
#define TK_TIPO_INT 283
#define TK_TIPO_FLOAT 284
#define TK_TIPO_BOOL 285
#define TK_CAST_FLOAT 286
#define TK_CAST_INT 287
#define TK_CAST_BOOL 288
#define TK_TIPO_CHAR 289
#define TK_TIPO_STRING 290
#define TK_FIM 291
#define TK_ERROR 292
#define AND 293
#define OR 294
#define NO 295
#define EQ 296
#define NE 297
#define GE 298
#define LE 299
#define TK_CAST_CHAR 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
