/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatica.y"

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
    string label;
    string label2;
    string traducao;
    string declaracao;
    string tipo;
    string valor;
    string strcpy;
};

void naoDeclarado(string chave);
void declarado(string chave);
void empilha();
void desempilha();
string genTemp();
string genRot();
int busca_escopo(string var);
int verificaVar(string var);
int verificaVarBloco(string var);
void conversaoImplicitaOp(atributos& $$, atributos& $1, atributos& $3, string operador, string tipo);
void operacao(atributos& $$, atributos& $1, atributos& $2, atributos& $3, string operador);

// Struct de cada tipo
typedef struct
{
    string nome;
    string tipo;
	string temp;
    string valor;
    string tamMatriz;
    bool vetor;
    bool matriz;
    int tam;
    int atribuido;
    int bloco;
} TIPO_SIMBOLO;

typedef struct
{
    string nome;
    string tipo;
	string temp;
    string retorno;
    string traducao;
} FUNCAO;

int bloco_atual = -1;
vector<unordered_map<string, TIPO_SIMBOLO>> pilha; 
vector<unordered_map<string, FUNCAO>> funcao; 
vector<tuple<string, string>> pilha_rotulo;
bool gerouRotulo = false;
bool loop = false;

vector<string> pilha_malloc;
int temp;
int tempRot;
bool bloco_switch = false;
bool defaultExecutado = false;
string auxPrint;
extern int contn;

int yylex(void);
void yyerror(string);

#line 148 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_NUM = 3,                     /* TK_NUM  */
  YYSYMBOL_TK_REAL = 4,                    /* TK_REAL  */
  YYSYMBOL_TK_TRUE = 5,                    /* TK_TRUE  */
  YYSYMBOL_TK_FALSE = 6,                   /* TK_FALSE  */
  YYSYMBOL_TK_CHAR = 7,                    /* TK_CHAR  */
  YYSYMBOL_TK_STRING = 8,                  /* TK_STRING  */
  YYSYMBOL_TK_IF = 9,                      /* TK_IF  */
  YYSYMBOL_TK_ELSE = 10,                   /* TK_ELSE  */
  YYSYMBOL_TK_FOR = 11,                    /* TK_FOR  */
  YYSYMBOL_TK_WHILE = 12,                  /* TK_WHILE  */
  YYSYMBOL_TK_DO = 13,                     /* TK_DO  */
  YYSYMBOL_TK_SWITCH = 14,                 /* TK_SWITCH  */
  YYSYMBOL_TK_CASE = 15,                   /* TK_CASE  */
  YYSYMBOL_TK_DP = 16,                     /* TK_DP  */
  YYSYMBOL_TK_DEFAULT = 17,                /* TK_DEFAULT  */
  YYSYMBOL_TK_PRINT = 18,                  /* TK_PRINT  */
  YYSYMBOL_TK_SCAN = 19,                   /* TK_SCAN  */
  YYSYMBOL_TK_BREAK = 20,                  /* TK_BREAK  */
  YYSYMBOL_TK_CONTINUE = 21,               /* TK_CONTINUE  */
  YYSYMBOL_TK_RETURN = 22,                 /* TK_RETURN  */
  YYSYMBOL_TK_TIPO_VOID = 23,              /* TK_TIPO_VOID  */
  YYSYMBOL_TK_QB = 24,                     /* TK_QB  */
  YYSYMBOL_TK_COMENT = 25,                 /* TK_COMENT  */
  YYSYMBOL_TK_MAIN = 26,                   /* TK_MAIN  */
  YYSYMBOL_TK_ID = 27,                     /* TK_ID  */
  YYSYMBOL_TK_TIPO_INT = 28,               /* TK_TIPO_INT  */
  YYSYMBOL_TK_TIPO_FLOAT = 29,             /* TK_TIPO_FLOAT  */
  YYSYMBOL_TK_TIPO_BOOL = 30,              /* TK_TIPO_BOOL  */
  YYSYMBOL_TK_CAST_FLOAT = 31,             /* TK_CAST_FLOAT  */
  YYSYMBOL_TK_CAST_INT = 32,               /* TK_CAST_INT  */
  YYSYMBOL_TK_CAST_BOOL = 33,              /* TK_CAST_BOOL  */
  YYSYMBOL_TK_TIPO_CHAR = 34,              /* TK_TIPO_CHAR  */
  YYSYMBOL_TK_TIPO_STRING = 35,            /* TK_TIPO_STRING  */
  YYSYMBOL_TK_FIM = 36,                    /* TK_FIM  */
  YYSYMBOL_TK_ERROR = 37,                  /* TK_ERROR  */
  YYSYMBOL_AND = 38,                       /* AND  */
  YYSYMBOL_OR = 39,                        /* OR  */
  YYSYMBOL_NO = 40,                        /* NO  */
  YYSYMBOL_41_ = 41,                       /* '>'  */
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_EQ = 43,                        /* EQ  */
  YYSYMBOL_NE = 44,                        /* NE  */
  YYSYMBOL_GE = 45,                        /* GE  */
  YYSYMBOL_LE = 46,                        /* LE  */
  YYSYMBOL_47_ = 47,                       /* '+'  */
  YYSYMBOL_48_ = 48,                       /* '-'  */
  YYSYMBOL_49_ = 49,                       /* '*'  */
  YYSYMBOL_50_ = 50,                       /* '/'  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_TK_CAST_CHAR = 52,              /* TK_CAST_CHAR  */
  YYSYMBOL_53_ = 53,                       /* '('  */
  YYSYMBOL_54_ = 54,                       /* ')'  */
  YYSYMBOL_55_ = 55,                       /* ','  */
  YYSYMBOL_56_ = 56,                       /* '}'  */
  YYSYMBOL_57_ = 57,                       /* ';'  */
  YYSYMBOL_58_ = 58,                       /* '='  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_S = 62,                         /* S  */
  YYSYMBOL_GLOBAL = 63,                    /* GLOBAL  */
  YYSYMBOL_TIPO = 64,                      /* TIPO  */
  YYSYMBOL_PARAMETROS = 65,                /* PARAMETROS  */
  YYSYMBOL_BLOCO = 66,                     /* BLOCO  */
  YYSYMBOL_INI = 67,                       /* INI  */
  YYSYMBOL_FIM = 68,                       /* FIM  */
  YYSYMBOL_COMANDOS = 69,                  /* COMANDOS  */
  YYSYMBOL_COMANDO = 70,                   /* COMANDO  */
  YYSYMBOL_IF = 71,                        /* IF  */
  YYSYMBOL_IF_ELSE = 72,                   /* IF_ELSE  */
  YYSYMBOL_FOR = 73,                       /* FOR  */
  YYSYMBOL_WHILE = 74,                     /* WHILE  */
  YYSYMBOL_DO_WHILE = 75,                  /* DO_WHILE  */
  YYSYMBOL_BLOCO_LOOP = 76,                /* BLOCO_LOOP  */
  YYSYMBOL_CMD = 77,                       /* CMD  */
  YYSYMBOL_BREAK_OR_CONTINUE = 78,         /* BREAK_OR_CONTINUE  */
  YYSYMBOL_SWITCH = 79,                    /* SWITCH  */
  YYSYMBOL_BLOCO_SWITCH = 80,              /* BLOCO_SWITCH  */
  YYSYMBOL_CASE_LISTA = 81,                /* CASE_LISTA  */
  YYSYMBOL_CASE_STMT = 82,                 /* CASE_STMT  */
  YYSYMBOL_CASE = 83,                      /* CASE  */
  YYSYMBOL_PRINT = 84,                     /* PRINT  */
  YYSYMBOL_EXPRESSAO = 85,                 /* EXPRESSAO  */
  YYSYMBOL_TEXTO = 86,                     /* TEXTO  */
  YYSYMBOL_E = 87                          /* E  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   726

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      53,    54,    49,    47,    55,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
      42,    58,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    56,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    43,    44,    45,    46,
      52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,   104,   114,   118,   122,   126,   130,   134,
     138,   146,   156,   168,   176,   183,   197,   203,   209,   210,
     215,   219,   223,   227,   231,   236,   241,   246,   250,   264,
     279,   293,   307,   321,   366,   407,   446,   513,   517,   521,
     616,   711,   737,   771,   815,   859,   904,   949,   959,   963,
     970,   979,   993,  1004,  1012,  1018,  1026,  1032,  1068,  1084,
    1093,  1099,  1141,  1151,  1160,  1167,  1171,  1175,  1179,  1183,
    1187,  1191,  1195,  1199,  1222,  1226,  1230,  1234,  1238,  1369,
    1379,  1387,  1395,  1404,  1414,  1424,  1441,  1458,  1475,  1481,
    1486
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_NUM", "TK_REAL",
  "TK_TRUE", "TK_FALSE", "TK_CHAR", "TK_STRING", "TK_IF", "TK_ELSE",
  "TK_FOR", "TK_WHILE", "TK_DO", "TK_SWITCH", "TK_CASE", "TK_DP",
  "TK_DEFAULT", "TK_PRINT", "TK_SCAN", "TK_BREAK", "TK_CONTINUE",
  "TK_RETURN", "TK_TIPO_VOID", "TK_QB", "TK_COMENT", "TK_MAIN", "TK_ID",
  "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_BOOL", "TK_CAST_FLOAT",
  "TK_CAST_INT", "TK_CAST_BOOL", "TK_TIPO_CHAR", "TK_TIPO_STRING",
  "TK_FIM", "TK_ERROR", "AND", "OR", "NO", "'>'", "'<'", "EQ", "NE", "GE",
  "LE", "'+'", "'-'", "'*'", "'/'", "'{'", "TK_CAST_CHAR", "'('", "')'",
  "','", "'}'", "';'", "'='", "'['", "']'", "$accept", "S", "GLOBAL",
  "TIPO", "PARAMETROS", "BLOCO", "INI", "FIM", "COMANDOS", "COMANDO", "IF",
  "IF_ELSE", "FOR", "WHILE", "DO_WHILE", "BLOCO_LOOP", "CMD",
  "BREAK_OR_CONTINUE", "SWITCH", "BLOCO_SWITCH", "CASE_LISTA", "CASE_STMT",
  "CASE", "PRINT", "EXPRESSAO", "TEXTO", "E", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-18)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,   -14,    15,   -23,  -131,   -34,   -17,  -131,   -12,   291,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,    11,  -131,  -131,
    -131,  -131,  -131,  -131,     8,    20,    28,    18,    34,    45,
      36,  -131,   -33,    56,    80,    82,    36,    36,    84,    85,
      36,    36,  -131,  -131,   183,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,   494,    68,    36,    36,    36,  -131,   112,    36,
      -3,     7,   511,   329,    36,   -51,   -38,    69,  -131,  -131,
      70,    72,   676,  -131,    74,  -131,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,  -131,   -12,
     596,   528,   610,   237,    78,   624,  -131,  -131,  -131,    79,
      87,    36,    36,  -131,    90,    19,   666,   123,  -131,    36,
    -131,    36,  -131,  -131,  -131,  -131,   676,   676,    -2,    -2,
      -2,    -2,    -2,    -2,    30,    30,  -131,  -131,   105,    83,
     -17,    36,    18,    65,  -131,    36,    94,    81,    -3,   354,
      92,    36,    31,   374,   394,    95,   -17,   137,   545,  -131,
      96,    97,   237,    93,   638,    16,  -131,  -131,  -131,  -131,
      98,   414,    36,    36,     5,    13,   -12,  -131,   -17,    36,
    -131,  -131,  -131,  -131,    99,    36,   135,   101,    16,  -131,
    -131,   102,   562,   434,  -131,    36,  -131,    36,  -131,  -131,
     652,  -131,   341,    88,  -131,  -131,  -131,  -131,   116,   454,
     474,    18,    88,  -131,    36,   118,   119,  -131,  -131,   579,
    -131,  -131,  -131
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,    14,     4,    90,
      10,     5,     6,     8,     7,     9,     2,     0,    79,    80,
      84,    83,    81,    82,     0,     0,     0,     0,     0,     0,
      90,    38,    88,     0,     0,     0,    90,    90,     0,     0,
      90,    90,    18,    15,    90,    20,    21,    24,    22,    23,
      25,    26,     0,     0,    90,    90,    90,    14,     0,    90,
       0,    88,     0,    90,    90,     0,     0,     0,    85,    86,
       0,     0,    73,    87,     0,    16,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    19,     0,
       0,     0,     0,    90,     0,     0,    63,    62,    64,     0,
      60,    90,    90,    37,     0,    88,    78,     0,    28,    90,
      29,    90,    31,    30,    32,    13,    71,    72,    65,    66,
      67,    68,    69,    70,    74,    75,    76,    77,     0,     0,
       0,    90,     0,    49,    15,    90,     0,     0,     0,     0,
       0,    90,    89,     0,     0,    11,     0,    42,     0,    45,
       0,     0,    90,     0,     0,    55,    52,    59,    61,    89,
       0,     0,    90,    90,     0,     0,     0,     3,     0,    90,
      50,    51,    48,    47,     0,    90,     0,     0,    55,    56,
      27,    89,     0,     0,    33,    90,    34,    90,    12,    43,
       0,    46,     0,    90,    53,    54,    35,    36,     0,     0,
       0,     0,    90,    58,    90,     0,     0,    44,    57,     0,
      39,    40,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,   144,    12,    -5,   122,    46,    -9,  -131,
    -131,  -131,  -131,  -131,  -131,  -130,    29,  -131,  -131,  -131,
       4,  -131,  -131,  -131,    47,  -131,   -27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    16,   128,   129,    42,     9,    74,   133,    44,
      45,    46,    47,    48,    49,    58,   134,   152,    50,   156,
     177,   178,   179,    51,    99,   100,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,     8,   149,    62,    96,    97,   108,     1,   109,    68,
      69,    10,     3,    72,    73,     4,    11,    12,    13,   110,
       6,   111,    14,    15,    98,    63,    64,    90,    91,    92,
       5,   175,    95,   176,     7,    75,   106,   107,    53,    18,
      19,    20,    21,    22,    23,    84,    85,    86,    87,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,    54,   184,    61,   185,   101,   102,    36,    37,    57,
     186,   207,   187,    55,   106,   139,    40,   101,   141,    86,
      87,    56,   143,    65,   144,   150,   151,    59,    41,   162,
     163,    18,    19,    20,    21,    22,    23,    24,    60,    25,
      26,    27,    28,   -17,   148,   -17,    29,    66,   154,    67,
      30,    70,    71,    31,   161,    32,    33,    34,    35,    36,
      37,    89,    38,    39,    94,   147,   112,   113,    40,   114,
     115,   135,   145,   137,   138,   182,   183,   146,   157,     7,
      41,   167,   190,   140,   -17,   155,   160,   168,   192,   173,
     166,   193,    17,   170,   171,   180,   191,   194,   199,   196,
     200,    76,    77,   189,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   204,   210,   211,   209,   188,    93,
     153,   172,   195,   142,   203,   158,    18,    19,    20,    21,
      22,    23,    24,   208,    25,    26,    27,    28,   -17,     0,
     -17,    29,     0,   -17,   -17,    30,     0,     0,    31,     0,
      32,    33,    34,    35,    36,    37,     0,    38,    39,     0,
       0,     0,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,    41,     0,     0,     0,   -17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
      27,    28,     0,     0,     0,    29,     0,   -17,   -17,    30,
       0,     0,    31,     0,    32,    33,    34,    35,    36,    37,
       0,    38,    39,     0,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,    41,
       0,     0,     0,   -17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,    27,    28,     0,     0,     0,    29,
       0,     0,     0,    30,     0,     0,    31,     0,    32,    33,
      34,    35,    36,    37,     0,    38,    39,     0,     0,     0,
       0,    40,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     7,    41,     0,     0,     0,   -17,   104,     0,
       0,     0,     0,     0,     0,     0,   105,   202,     0,     0,
      36,    37,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
      77,    41,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    76,    77,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,    76,    77,   159,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,    76,    77,   164,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,    76,    77,   165,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,    76,    77,   181,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,    76,    77,   198,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,    76,    77,   205,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,    76,    77,   206,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,    76,
      77,    88,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,    76,    77,   103,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,    76,    77,   131,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
      76,    77,   169,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,    76,    77,   197,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,    76,    77,   212,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,    76,    77,
     130,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,    76,    77,   132,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,    76,    77,   136,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
      76,    77,   174,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,    76,    77,   201,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
       9,     6,   132,    30,     7,     8,    57,    28,    59,    36,
      37,    23,    26,    40,    41,     0,    28,    29,    30,    57,
      54,    59,    34,    35,    27,    58,    59,    54,    55,    56,
      53,    15,    59,    17,    51,    44,    63,    64,    27,     3,
       4,     5,     6,     7,     8,    47,    48,    49,    50,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    53,    57,    27,    59,    58,    59,    31,    32,    51,
      57,   201,    59,    53,   101,   102,    40,    58,    59,    49,
      50,    53,   109,    27,   111,    20,    21,    53,    52,    58,
      59,     3,     4,     5,     6,     7,     8,     9,    53,    11,
      12,    13,    14,    15,   131,    17,    18,    27,   135,    27,
      22,    27,    27,    25,   141,    27,    28,    29,    30,    31,
      32,    53,    34,    35,    12,   130,    57,    57,    40,    57,
      56,    53,    27,    54,    47,   162,   163,    54,    57,    51,
      52,   146,   169,    53,    56,    51,    54,    10,   175,    56,
      55,    16,     8,    57,    57,    57,    57,    56,   185,    57,
     187,    38,    39,   168,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    58,    57,    57,   204,   166,    57,
     134,   152,   178,    60,   193,   138,     3,     4,     5,     6,
       7,     8,     9,   202,    11,    12,    13,    14,    15,    -1,
      17,    18,    -1,    20,    21,    22,    -1,    -1,    25,    -1,
      27,    28,    29,    30,    31,    32,    -1,    34,    35,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    56,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    -1,    -1,    -1,    18,    -1,    20,    21,    22,
      -1,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      -1,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    -1,    -1,    56,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    -1,    -1,    25,    -1,    27,    28,
      29,    30,    31,    32,    -1,    34,    35,    -1,    -1,    -1,
      -1,    40,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    56,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    16,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    52,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    38,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    60,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    60,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    60,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    60,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    60,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    60,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    60,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    38,
      39,    57,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    38,    39,    57,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    38,    39,    57,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      38,    39,    57,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    38,    39,    57,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    38,    39,    57,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    38,    39,
      54,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    38,    39,    54,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    38,    39,    54,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      38,    39,    54,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    38,    39,    54,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    62,    26,     0,    53,    54,    51,    66,    67,
      23,    28,    29,    30,    34,    35,    63,    64,     3,     4,
       5,     6,     7,     8,     9,    11,    12,    13,    14,    18,
      22,    25,    27,    28,    29,    30,    31,    32,    34,    35,
      40,    52,    66,    69,    70,    71,    72,    73,    74,    75,
      79,    84,    87,    27,    53,    53,    53,    51,    76,    53,
      53,    27,    87,    58,    59,    27,    27,    27,    87,    87,
      27,    27,    87,    87,    68,    69,    38,    39,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    57,    53,
      87,    87,    87,    67,    12,    87,     7,     8,    27,    85,
      86,    58,    59,    57,    19,    27,    87,    87,    57,    59,
      57,    59,    57,    57,    57,    56,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    64,    65,
      54,    57,    54,    69,    77,    53,    54,    54,    47,    87,
      53,    59,    60,    87,    87,    27,    54,    66,    87,    76,
      20,    21,    78,    68,    87,    51,    80,    57,    85,    60,
      54,    87,    58,    59,    60,    60,    55,    66,    10,    57,
      57,    57,    77,    56,    54,    15,    17,    81,    82,    83,
      57,    60,    87,    87,    57,    59,    57,    59,    65,    66,
      87,    57,    87,    16,    56,    81,    57,    57,    60,    87,
      87,    54,    16,    69,    58,    60,    60,    76,    69,    87,
      57,    57,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    67,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    72,    73,    74,    75,    76,    77,    77,
      78,    78,    79,    80,    81,    81,    82,    83,    83,    84,
      85,    85,    86,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     6,     0,     1,     1,     1,     1,     1,
       1,     2,     4,     5,     0,     0,     2,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     6,     3,     3,
       3,     3,     3,     6,     6,     7,     7,     3,     1,     9,
       9,    10,     5,     7,     9,     5,     7,     5,     3,     1,
       2,     2,     5,     3,     2,     0,     1,     4,     3,     5,
       1,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     4,
       0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* S: TK_TIPO_INT TK_MAIN '(' ')' BLOCO GLOBAL  */
#line 99 "sintatica.y"
            {
                cout << "/*Compilador CAPY*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << yyvsp[-1].declaracao << yyvsp[-1].traducao << "\treturn 0;\n}" << endl;
            }
#line 1595 "y.tab.c"
    break;

  case 3: /* GLOBAL: TIPO TK_ID '(' PARAMETROS ')' BLOCO  */
#line 105 "sintatica.y"
        {
            //declarado($2.label);
            pilha.push_back(unordered_map<string, TIPO_SIMBOLO>());
            FUNCAO fun;
            fun.nome = yyvsp[-4].label;
            fun.tipo = yyvsp[-5].label;
            fun.traducao = yyvsp[0].traducao;
        }
#line 1608 "y.tab.c"
    break;

  case 4: /* GLOBAL: %empty  */
#line 114 "sintatica.y"
        {

        }
#line 1616 "y.tab.c"
    break;

  case 5: /* TIPO: TK_TIPO_INT  */
#line 119 "sintatica.y"
        {
            yyval.label = "int";
        }
#line 1624 "y.tab.c"
    break;

  case 6: /* TIPO: TK_TIPO_FLOAT  */
#line 123 "sintatica.y"
        {
            yyval.label = "float";
        }
#line 1632 "y.tab.c"
    break;

  case 7: /* TIPO: TK_TIPO_CHAR  */
#line 127 "sintatica.y"
        {
            yyval.label = "char";
        }
#line 1640 "y.tab.c"
    break;

  case 8: /* TIPO: TK_TIPO_BOOL  */
#line 131 "sintatica.y"
        {
            yyval.label = "bool";
        }
#line 1648 "y.tab.c"
    break;

  case 9: /* TIPO: TK_TIPO_STRING  */
#line 135 "sintatica.y"
        {
            yyval.label = "string";
        }
#line 1656 "y.tab.c"
    break;

  case 10: /* TIPO: TK_TIPO_VOID  */
#line 139 "sintatica.y"
        {
            yyval.label = "void";
        }
#line 1664 "y.tab.c"
    break;

  case 11: /* PARAMETROS: TIPO TK_ID  */
#line 147 "sintatica.y"
            {
                // if(pilha_funcao.empty()){
                //     pilha_funcao.push_back(unordered_map<string, TIPO_SIMBOLO>());
                // }
                // TIPO_SIMBOLO var;
                // var.tipo = $1.label;
                // var.nome = $2.label;
                // var.temp = genTemp();
            }
#line 1678 "y.tab.c"
    break;

  case 12: /* PARAMETROS: TIPO TK_ID ',' PARAMETROS  */
#line 157 "sintatica.y"
            {
                // if(pilha_funcao.empty()){
                //     pilha_funcao.push_back(unordered_map<string, TIPO_SIMBOLO>());
                // }
                // TIPO_SIMBOLO var;
                // var.tipo = $1.label;
                // var.nome = $2.label;
                // var.temp = genTemp();
            }
#line 1692 "y.tab.c"
    break;

  case 13: /* BLOCO: '{' INI COMANDOS FIM '}'  */
#line 169 "sintatica.y"
            {
                yyval.traducao = yyvsp[-2].traducao + yyvsp[-1].traducao;
				yyval.declaracao = yyvsp[-2].declaracao;
            }
#line 1701 "y.tab.c"
    break;

  case 14: /* INI: %empty  */
#line 176 "sintatica.y"
            {
                empilha();
                bloco_atual++;
            }
#line 1710 "y.tab.c"
    break;

  case 15: /* FIM: %empty  */
#line 183 "sintatica.y"
            {
                desempilha();
                bloco_atual--;
                string traducao;
                while (pilha_malloc.size() != 0) {
                    string aux = pilha_malloc.back();  // Obter o último elemento da pilha
                    pilha_malloc.pop_back();           // Remover o último elemento da pilha

                    traducao += string("\t") + string("free(") + aux + ");\n";  // Adicionar a instrução correspondente
                }
                yyval.traducao = traducao;
            }
#line 1727 "y.tab.c"
    break;

  case 16: /* COMANDOS: COMANDO COMANDOS  */
#line 198 "sintatica.y"
            {
                yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
				yyval.declaracao = yyvsp[-1].declaracao + yyvsp[0].declaracao;
            }
#line 1736 "y.tab.c"
    break;

  case 17: /* COMANDOS: %empty  */
#line 203 "sintatica.y"
            {
                yyval.traducao = "";
                yyval.declaracao = "";
            }
#line 1745 "y.tab.c"
    break;

  case 19: /* COMANDO: E ';'  */
#line 211 "sintatica.y"
            {
                yyval.traducao = yyvsp[-1].traducao;
                yyval.declaracao = yyvsp[-1].declaracao;
            }
#line 1754 "y.tab.c"
    break;

  case 20: /* COMANDO: IF  */
#line 216 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
            }
#line 1762 "y.tab.c"
    break;

  case 21: /* COMANDO: IF_ELSE  */
#line 220 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
            }
#line 1770 "y.tab.c"
    break;

  case 22: /* COMANDO: WHILE  */
#line 224 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
            }
#line 1778 "y.tab.c"
    break;

  case 23: /* COMANDO: DO_WHILE  */
#line 228 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
            }
#line 1786 "y.tab.c"
    break;

  case 24: /* COMANDO: FOR  */
#line 232 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
                yyval.declaracao = yyvsp[0].declaracao;
            }
#line 1795 "y.tab.c"
    break;

  case 25: /* COMANDO: SWITCH  */
#line 237 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
                yyval.declaracao = yyvsp[0].declaracao;
            }
#line 1804 "y.tab.c"
    break;

  case 26: /* COMANDO: PRINT  */
#line 242 "sintatica.y"
            {
                yyval.traducao = yyvsp[0].traducao;
                yyval.declaracao = yyvsp[0].declaracao;
            }
#line 1813 "y.tab.c"
    break;

  case 27: /* COMANDO: TK_ID '=' TK_SCAN '(' ')' ';'  */
#line 247 "sintatica.y"
            {   
                yyval.traducao = "\tcin >> " + pilha[busca_escopo(yyvsp[-5].label)][yyvsp[-5].label].temp + ";\n";
            }
#line 1821 "y.tab.c"
    break;

  case 28: /* COMANDO: TK_TIPO_INT TK_ID ';'  */
#line 251 "sintatica.y"
            {
                declarado(yyvsp[-1].label);
                TIPO_SIMBOLO var;
                var.nome = yyvsp[-1].label;
                var.tipo = "int";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                yyval.tipo = var.tipo;
                yyval.declaracao = "\t" + yyval.tipo + " " + var.temp + ";\n";
                yyval.traducao = "";
            }
#line 1839 "y.tab.c"
    break;

  case 29: /* COMANDO: TK_TIPO_FLOAT TK_ID ';'  */
#line 265 "sintatica.y"
            {
                declarado(yyvsp[-1].label);
                TIPO_SIMBOLO var;
                var.nome = yyvsp[-1].label;
                var.tipo = "float";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                yyval.tipo = var.tipo;
                yyval.declaracao = "\t" + yyval.tipo + " " + var.temp + ";\n";
                yyval.traducao = "";
                
            }
#line 1858 "y.tab.c"
    break;

  case 30: /* COMANDO: TK_TIPO_CHAR TK_ID ';'  */
#line 280 "sintatica.y"
            {
                declarado(yyvsp[-1].label);
                TIPO_SIMBOLO var;
                var.nome = yyvsp[-1].label;
                var.tipo = "char";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                yyval.tipo = var.tipo;
                yyval.declaracao = "\t" + yyval.tipo + " " + var.temp + ";\n";
                yyval.traducao = "";
            }
#line 1876 "y.tab.c"
    break;

  case 31: /* COMANDO: TK_TIPO_BOOL TK_ID ';'  */
#line 294 "sintatica.y"
            {
                declarado(yyvsp[-1].label);
                TIPO_SIMBOLO var;
                var.nome = yyvsp[-1].label;
                var.tipo = "bool";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                yyval.tipo = var.tipo;
                yyval.declaracao = "\t" + string("int") + " " + var.temp + ";\n";
                yyval.traducao = "";
            }
#line 1894 "y.tab.c"
    break;

  case 32: /* COMANDO: TK_TIPO_STRING TK_ID ';'  */
#line 308 "sintatica.y"
            {
                declarado(yyvsp[-1].label);
                TIPO_SIMBOLO var;
                var.nome = yyvsp[-1].label;
                var.tipo = "string";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                yyval.tipo = var.tipo;
                yyval.declaracao = "\t" + string("char") + " *" + var.temp + ";\n";
                yyval.traducao += "";
            }
#line 1912 "y.tab.c"
    break;

  case 33: /* COMANDO: TK_TIPO_INT TK_ID '[' E ']' ';'  */
#line 322 "sintatica.y"
            {
                declarado(yyvsp[-4].label);
                if(verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    yyval.label = genTemp();
                    TIPO_SIMBOLO vet;
                    vet.nome = yyvsp[-4].label;
                    vet.tipo = "int";
                    vet.atribuido = 1;
                    vet.temp = yyval.label;
                    vet.vetor = true;
                    vet.bloco = bloco_atual;
                    pilha[bloco_atual][vet.nome] = vet;
                    yyval.tipo = vet.tipo;
                    yyval.declaracao = yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-2].traducao + "\t" + yyval.tipo + " " + yyval.label + '[' + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + "];\n";
                }
                else{
                    if(yyvsp[-2].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    if(stoi(yyvsp[-2].valor) < 0){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    yyval.label = genTemp();
                    TIPO_SIMBOLO vet;
                    vet.nome = yyvsp[-4].label;
                    vet.tipo = "int";
                    vet.atribuido = 1;
                    vet.temp = yyval.label;
                    vet.tam = stoi(yyvsp[-2].valor);
                    vet.vetor = true;
                    vet.bloco = bloco_atual;
                    pilha[bloco_atual][vet.nome] = vet;
                    yyval.tipo = vet.tipo;
                    yyval.declaracao = yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-2].traducao + "\t" + yyval.tipo + " " + yyval.label + '[' + yyvsp[-2].label + "];\n";
                }
            }
#line 1961 "y.tab.c"
    break;

  case 34: /* COMANDO: TK_TIPO_FLOAT TK_ID '[' E ']' ';'  */
#line 367 "sintatica.y"
            {
                declarado(yyvsp[-4].label);
                if(verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    yyval.label = genTemp();
                    TIPO_SIMBOLO vet;
                    vet.nome = yyvsp[-4].label;
                    vet.tipo = "float";
                    vet.atribuido = 1;
                    vet.temp = yyval.label;
                    vet.vetor = true;
                    vet.bloco = bloco_atual;
                    pilha[bloco_atual][vet.nome] = vet;
                    yyval.tipo = vet.tipo;
                    yyval.declaracao = yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-2].traducao + "\t" + yyval.tipo + " " + yyval.label + '[' + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + "];\n";
                }
                else{
                    if(yyvsp[-2].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    yyval.label = genTemp();
                    TIPO_SIMBOLO vet;
                    vet.nome = yyvsp[-4].label;
                    vet.tipo = "float";
                    vet.atribuido = 1;
                    vet.temp = yyval.label;
                    vet.vetor = true;
                    vet.bloco = bloco_atual;
                    pilha[bloco_atual][vet.nome] = vet;
                    yyval.tipo = vet.tipo;
                    yyval.declaracao = yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-2].traducao + "\t" + yyval.tipo + " " + yyval.label + '[' + yyvsp[-2].label + "];\n";
                }
            }
#line 2006 "y.tab.c"
    break;

  case 35: /* COMANDO: TK_ID '=' TK_ID '[' E ']' ';'  */
#line 408 "sintatica.y"
            {
                if(verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "int"){
                        yyerror("Erro: Posição do Vetor Inválida");
                    }
                    yyval.declaracao = yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-2].traducao;
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo == "float" && pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].tipo == "int"){
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + " = (int)" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + '[' + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + "];\n";
                    }
                    else if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo == "int" && pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].tipo == "float"){
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + " = (float)" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + '[' + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + "];\n";
                    }
                    else{
                        yyval.traducao += + "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + " = " + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + "[" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + "];\n";
                    }
                }
                else{
                    if(yyvsp[-2].tipo != "int"){
                        yyerror("Erro: Posição do Vetor Inválida");
                    }
                    yyval.declaracao = yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-2].traducao;
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo == "float" && pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].tipo == "int"){
                        yyval.label = genTemp();
                        yyval.traducao += "\t" + yyval.label + " = (int)" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + '[' + yyvsp[-2].label + "];\n";
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + " = " + yyval.label + ";\n";
                    }
                    else if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo == "int" && pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].tipo == "float"){
                        yyval.label = genTemp();
                        yyval.traducao += + "\t" + yyval.label + " = (float)" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + '[' + yyvsp[-2].label + "];\n";
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + " = " + yyval.label + ";\n";
                    }
                    else{
                        yyval.traducao += + "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + " = " + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + '[' + yyvsp[-2].label + "];\n";
                    }
                }            
            }
#line 2049 "y.tab.c"
    break;

  case 36: /* COMANDO: TK_ID '[' E ']' '=' E ';'  */
#line 447 "sintatica.y"
            {
                if(verificaVar(yyvsp[-4].label) && verificaVar(yyvsp[-1].label)){
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo != "int"){
                        yyerror("Erro: Posição do Vetor Inválida");
                    }
                    yyval.declaracao = yyvsp[-4].declaracao + yyvsp[-1].declaracao;
                    yyval.traducao = yyvsp[-4].traducao + yyvsp[-1].traducao;
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo == "float" && pilha[busca_escopo(yyvsp[-1].label)][yyvsp[-1].label].tipo == "int"){
                        yyval.traducao = "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + "[" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + "]" + " = (int)" + pilha[busca_escopo(yyvsp[-1].label)][yyvsp[-1].label].temp + ";\n";
                    }
                    else if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo == "int" && pilha[busca_escopo(yyvsp[-1].label)][yyvsp[-1].label].tipo == "float"){
                        yyval.traducao += + "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + "[" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + "]" + " = (int)" + pilha[busca_escopo(yyvsp[-1].label)][yyvsp[-1].label].temp + ";\n";
                    }
                    else{
                        yyval.traducao += + "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + "[" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + "]" + " = " + pilha[busca_escopo(yyvsp[-1].label)][yyvsp[-1].label].temp + ";\n";
                    }
                }
                if(!verificaVar(yyvsp[-4].label) && !verificaVar(yyvsp[-1].label)){
                    if(yyvsp[-4].tipo != "int"){
                        yyerror("Erro: Posição do Vetor Inválida");
                    }
                    yyval.declaracao = yyvsp[-4].declaracao + yyvsp[-1].declaracao;
                    yyval.traducao = yyvsp[-4].traducao + yyvsp[-1].traducao;
                    if(yyvsp[-4].tipo == "float" && yyvsp[-1].tipo == "int"){
                        yyval.traducao = "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + "[" + yyvsp[-4].label + "]" + " = (float)" + yyvsp[-1].label + ";\n";
                    }
                    else if(yyvsp[-4].tipo == "int" && yyvsp[-1].tipo == "float"){
                        yyval.traducao += + "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + "[" + yyvsp[-4].label + "]" + " = (int)" + yyvsp[-1].label + ";\n";
                    }
                    else{
                        yyval.traducao += + "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + "[" + yyvsp[-4].label + "]" + " = " + yyvsp[-1].label + ";\n";
                    }
                }
                if(!verificaVar(yyvsp[-4].label) && verificaVar(yyvsp[-1].label)){
                    if(yyvsp[-4].tipo != "int"){
                        yyerror("Erro: Posição do Vetor Inválida");
                    }
                    yyval.declaracao = yyvsp[-4].declaracao + yyvsp[-1].declaracao;
                    yyval.traducao = yyvsp[-4].traducao + yyvsp[-1].traducao;
                    if(yyvsp[-4].tipo == "float" && pilha[busca_escopo(yyvsp[-1].label)][yyvsp[-1].label].tipo == "int"){
                        yyval.traducao = "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + "[" + yyvsp[-4].label + "]" + " = (float)" + pilha[busca_escopo(yyvsp[-1].label)][yyvsp[-1].label].temp + ";\n";
                    }
                    else if(yyvsp[-4].tipo == "int" && pilha[busca_escopo(yyvsp[-1].label)][yyvsp[-1].label].tipo == "float"){
                        yyval.traducao += + "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + "[" + yyvsp[-4].label + "]" + " = (int)" + pilha[busca_escopo(yyvsp[-1].label)][yyvsp[-1].label].temp + "];\n";
                    }
                    else{
                        yyval.traducao += + "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + "[" + yyvsp[-4].label + "]" + " = " + pilha[busca_escopo(yyvsp[-1].label)][yyvsp[-1].label].temp + ";\n";
                    }
                }
                if(verificaVar(yyvsp[-4].label) && !verificaVar(yyvsp[-1].label)){
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo != "int"){
                        yyerror("Erro: Posição do Vetor Inválida");
                    }
                    yyval.declaracao = yyvsp[-4].declaracao + yyvsp[-1].declaracao;
                    yyval.traducao = yyvsp[-4].traducao + yyvsp[-1].traducao;
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo == "float" && yyvsp[-1].tipo == "int"){
                        yyval.traducao = "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + "[" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + "]" + " = (float)" + yyvsp[-1].label + ";\n";
                    }
                    else if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo == "int" && yyvsp[-1].tipo == "float"){
                        yyval.traducao += + "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + "[" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + "]" + " = (int)" + yyvsp[-1].label + ";\n";
                    }
                    else{
                        yyval.traducao += + "\t" + pilha[busca_escopo(yyvsp[-6].label)][yyvsp[-6].label].temp + "[" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + "]" + " = " + yyvsp[-1].label + ";\n";
                    }
                }                
            }
#line 2120 "y.tab.c"
    break;

  case 37: /* COMANDO: TK_RETURN E ';'  */
#line 514 "sintatica.y"
            {

            }
#line 2128 "y.tab.c"
    break;

  case 38: /* COMANDO: TK_COMENT  */
#line 518 "sintatica.y"
            {
                
            }
#line 2136 "y.tab.c"
    break;

  case 39: /* COMANDO: TK_TIPO_INT TK_ID '[' E ']' '[' E ']' ';'  */
#line 522 "sintatica.y"
            {
                if(!verificaVar(yyvsp[-5].label) && !verificaVar(yyvsp[-2].label)){
                    if(yyvsp[-5].tipo != "int" || yyvsp[-2].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    yyval.declaracao = yyvsp[-5].declaracao + yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-5].traducao + yyvsp[-2].traducao;
                    yyval.label = genTemp();
                    yyval.declaracao += "\tint " + yyval.label + ";\n";
                    yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-5].label + " * " + yyvsp[-2].label + ";\n";
                    string temp = yyval.label;
                    TIPO_SIMBOLO matriz;
                    yyval.label = genTemp();
                    matriz.nome = yyvsp[-7].label;
                    matriz.tipo = "int";
                    matriz.atribuido = 1;
                    matriz.temp = yyval.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    yyval.tipo = matriz.tipo;
                    yyval.traducao += "\t" + yyval.tipo + " " + yyval.label + '[' + temp + "];\n";
                }
                if(verificaVar(yyvsp[-5].label) && verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-5].label)][yyvsp[-5].label].tipo != "int" || pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    yyval.declaracao = yyvsp[-5].declaracao + yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-5].traducao + yyvsp[-2].traducao;
                    yyval.label = genTemp();
                    yyval.declaracao += "\tint " + yyval.label + ";\n";
                    yyval.traducao += "\t" + yyval.label + " = " + pilha[busca_escopo(yyvsp[-5].label)][yyvsp[-5].label].temp + " * " + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + ";\n";
                    string temp = yyval.label;
                    TIPO_SIMBOLO matriz;
                    yyval.label = genTemp();
                    matriz.nome = yyvsp[-7].label;
                    matriz.tipo = "int";
                    matriz.atribuido = 1;
                    matriz.temp = yyval.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    yyval.tipo = matriz.tipo;
                    yyval.traducao += "\t" + yyval.tipo + " " + yyval.label + '[' + temp + "];\n";
                }
                if(!verificaVar(yyvsp[-5].label) && verificaVar(yyvsp[-2].label)){
                    if(yyvsp[-5].tipo != "int" || pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    yyval.declaracao = yyvsp[-5].declaracao + yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-5].traducao + yyvsp[-2].traducao;
                    yyval.label = genTemp();
                    yyval.declaracao += "\tint " + yyval.label + ";\n";
                    yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-5].label + " * " + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + ";\n";
                    string temp = yyval.label;
                    TIPO_SIMBOLO matriz;
                    yyval.label = genTemp();
                    matriz.nome = yyvsp[-7].label;
                    matriz.tipo = "int";
                    matriz.atribuido = 1;
                    matriz.temp = yyval.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    yyval.tipo = matriz.tipo;
                    yyval.traducao += "\t" + yyval.tipo + " " + yyval.label + '[' + temp + "];\n";
                }
                if(verificaVar(yyvsp[-5].label) && !verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-5].label)][yyvsp[-5].label].tipo != "int" || yyvsp[-2].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    yyval.declaracao = yyvsp[-5].declaracao + yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-5].traducao + yyvsp[-2].traducao;
                    yyval.label = genTemp();
                    yyval.declaracao += "\tint " + yyval.label + ";\n";
                    yyval.traducao += "\t" + yyval.label + " = " + pilha[busca_escopo(yyvsp[-5].label)][yyvsp[-5].label].temp + " * " + yyvsp[-2].label + ";\n";
                    string temp = yyval.label;
                    TIPO_SIMBOLO matriz;
                    yyval.label = genTemp();
                    matriz.nome = yyvsp[-7].label;
                    matriz.tipo = "int";
                    matriz.atribuido = 1;
                    matriz.temp = yyval.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    yyval.tipo = matriz.tipo;
                    yyval.traducao += "\t" + yyval.tipo + " " + yyval.label + '[' + temp + "];\n";
                }
            }
#line 2235 "y.tab.c"
    break;

  case 40: /* COMANDO: TK_TIPO_FLOAT TK_ID '[' E ']' '[' E ']' ';'  */
#line 617 "sintatica.y"
            {
                if(!verificaVar(yyvsp[-5].label) && !verificaVar(yyvsp[-2].label)){
                    if(yyvsp[-5].tipo != "int" || yyvsp[-2].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    yyval.declaracao = yyvsp[-5].declaracao + yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-5].traducao + yyvsp[-2].traducao;
                    yyval.label = genTemp();
                    yyval.declaracao += "\tint " + yyval.label + ";\n";
                    yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-5].label + " * " + yyvsp[-2].label + ";\n";
                    string temp = yyval.label;
                    TIPO_SIMBOLO matriz;
                    yyval.label = genTemp();
                    matriz.nome = yyvsp[-7].label;
                    matriz.tipo = "float";
                    matriz.atribuido = 1;
                    matriz.temp = yyval.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    yyval.tipo = matriz.tipo;
                    yyval.traducao += "\t" + yyval.tipo + " " + yyval.label + '[' + temp + "];\n";
                }
                if(verificaVar(yyvsp[-5].label) && verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-5].label)][yyvsp[-5].label].tipo != "int" || pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    yyval.declaracao = yyvsp[-5].declaracao + yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-5].traducao + yyvsp[-2].traducao;
                    yyval.label = genTemp();
                    yyval.declaracao += "\tint " + yyval.label + ";\n";
                    yyval.traducao += "\t" + yyval.label + " = " + pilha[busca_escopo(yyvsp[-5].label)][yyvsp[-5].label].temp + " * " + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + ";\n";
                    string temp = yyval.label;
                    TIPO_SIMBOLO matriz;
                    yyval.label = genTemp();
                    matriz.nome = yyvsp[-7].label;
                    matriz.tipo = "float";
                    matriz.atribuido = 1;
                    matriz.temp = yyval.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    yyval.tipo = matriz.tipo;
                    yyval.traducao += "\t" + yyval.tipo + " " + yyval.label + '[' + temp + "];\n";
                }
                if(!verificaVar(yyvsp[-5].label) && verificaVar(yyvsp[-2].label)){
                    if(yyvsp[-5].tipo != "int" || pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    yyval.declaracao = yyvsp[-5].declaracao + yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-5].traducao + yyvsp[-2].traducao;
                    yyval.label = genTemp();
                    yyval.declaracao += "\tint " + yyval.label + ";\n";
                    yyval.traducao += "\t" + yyval.label + " = " + yyvsp[-5].label + " * " + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + ";\n";
                    string temp = yyval.label;
                    TIPO_SIMBOLO matriz;
                    yyval.label = genTemp();
                    matriz.nome = yyvsp[-7].label;
                    matriz.tipo = "float";
                    matriz.atribuido = 1;
                    matriz.temp = yyval.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    yyval.tipo = matriz.tipo;
                    yyval.traducao += "\t" + yyval.tipo + " " + yyval.label + '[' + temp + "];\n";
                }
                if(verificaVar(yyvsp[-5].label) && !verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-5].label)][yyvsp[-5].label].tipo != "int" || yyvsp[-2].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    yyval.declaracao = yyvsp[-5].declaracao + yyvsp[-2].declaracao;
                    yyval.traducao = yyvsp[-5].traducao + yyvsp[-2].traducao;
                    yyval.label = genTemp();
                    yyval.declaracao += "\tint " + yyval.label + ";\n";
                    yyval.traducao += "\t" + yyval.label + " = " + pilha[busca_escopo(yyvsp[-5].label)][yyvsp[-5].label].temp + " * " + yyvsp[-2].label + ";\n";
                    string temp = yyval.label;
                    TIPO_SIMBOLO matriz;
                    yyval.label = genTemp();
                    matriz.nome = yyvsp[-7].label;
                    matriz.tipo = "float";
                    matriz.atribuido = 1;
                    matriz.temp = yyval.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    yyval.tipo = matriz.tipo;
                    yyval.traducao += "\t" + yyval.tipo + " " + yyval.label + '[' + temp + "];\n";
                }
            }
#line 2334 "y.tab.c"
    break;

  case 41: /* COMANDO: TK_ID '[' E ']' '[' E ']' '=' E ';'  */
#line 712 "sintatica.y"
            {
                if(!verificaVar(yyvsp[-7].label) && !verificaVar(yyvsp[-4].label)){
                    if(yyvsp[-7].tipo != "int" || yyvsp[-4].tipo != "int"){
                        yyerror("Erro: Posição da matriz Inválida");
                    }
                }
                if(verificaVar(yyvsp[-7].label) && verificaVar(yyvsp[-4].label)){
                    if(pilha[busca_escopo(yyvsp[-7].label)][yyvsp[-7].label].tipo != "int" || pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo != "int"){
                        yyerror("Erro: Posição da matriz Inválida");
                    }
                }
                if(!verificaVar(yyvsp[-7].label) && verificaVar(yyvsp[-4].label)){
                    if(yyvsp[-7].tipo != "int" || pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo != "int"){
                        yyerror("Erro: Posição da matriz Inválida");
                    }
                }
                if(verificaVar(yyvsp[-7].label) && !verificaVar(yyvsp[-4].label)){
                    if(pilha[busca_escopo(yyvsp[-7].label)][yyvsp[-7].label].tipo != "int" || yyvsp[-4].tipo != "int"){
                        yyerror("Erro: Posição da matriz Inválida");
                    }
                }
                
            }
#line 2362 "y.tab.c"
    break;

  case 42: /* IF: TK_IF '(' E ')' BLOCO  */
#line 738 "sintatica.y"
            {   
                if(verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[-2].label + " sem valor atribuido");
                    }
                    else{
                        yyval.label = genTemp();
                        string rotulo = genRot();
                        yyval.declaracao = "\tint " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + rotulo + ";\n";
                        yyval.traducao += yyvsp[0].traducao + "\t" + rotulo + ":\n";
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao + "\tint " + yyval.label + ";\n";
                    }
                }
                else{
                    if(yyvsp[-2].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    else{
                        yyval.label = genTemp();
                        string rotulo = genRot();
                        yyval.traducao += yyvsp[-2].traducao + "\t" + yyval.label + " = " + "!" + yyvsp[-2].label + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + rotulo + ";\n";
                        yyval.traducao += yyvsp[0].traducao + "\t" + rotulo + ":\n";
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao + "\tint " + yyval.label + ";\n";
                    }
                }
            }
#line 2399 "y.tab.c"
    break;

  case 43: /* IF_ELSE: TK_IF '(' E ')' BLOCO TK_ELSE BLOCO  */
#line 772 "sintatica.y"
            {   
                if(verificaVar(yyvsp[-4].label)){
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[-4].label + " sem valor atribuido");
                    }
                    else{
                        string rotulo1 = genRot();
                        string rotulo2 = genRot();
                        yyval.label = genTemp();
                        yyval.declaracao = "\tint " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-4].traducao + "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + rotulo1 + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + "\tgoto " + rotulo2 + ";\n";
                        //else
                        yyval.declaracao += yyvsp[-4].declaracao + yyvsp[-2].declaracao + "\tint " + yyval.label + ";\n";
                        yyval.declaracao += yyvsp[0].declaracao;
                        yyval.traducao += "\t" + rotulo1 + "\n" + yyvsp[0].traducao + "\t" + rotulo2 + ":\n";
                    }
                }
                else{
                    if(yyvsp[-4].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    else{
                        string rotulo1 = genRot();
                        string rotulo2 = genRot();
                        yyval.label = genTemp();
                        yyval.declaracao = "\tint " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-4].traducao + "\t" + yyval.label + " = " + "!" + yyvsp[-4].label + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + rotulo1 + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + "\tgoto " + rotulo2 + ";\n";
                        //else
                        yyval.declaracao += yyvsp[-4].declaracao + yyvsp[-2].declaracao + "\tint " + yyval.label + ";\n";
                        yyval.declaracao += yyvsp[0].declaracao;
                        yyval.traducao += "\t" + rotulo1 + "\n" + yyvsp[0].traducao + "\t" + rotulo2 + "\n";
                    }
                }
            }
#line 2445 "y.tab.c"
    break;

  case 44: /* FOR: TK_FOR '(' E ';' E ';' E ')' BLOCO_LOOP  */
#line 816 "sintatica.y"
            {
                if(verificaVar(yyvsp[-4].label)){
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].tipo != "bool"){
                        yyerror("Erro: A condição do 'for' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[-4].label + " sem valor atribuido");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        gerouRotulo = false;
                        yyval.label = genTemp(); 
                        yyval.traducao += yyvsp[-6].traducao + "\t" +iniRotulo + ":\n" + yyvsp[-4].traducao; 
                        yyval.traducao += "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[-4].label)][yyvsp[-4].label].temp + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + fimRotulo + ";\n";
                        yyval.declaracao += yyvsp[-6].declaracao + yyvsp[-4].declaracao + yyvsp[-2].declaracao + yyvsp[0].declaracao + "\tint " + yyval.label + ";\n";
                        yyval.traducao +=  yyvsp[0].traducao + yyvsp[-2].traducao ;
                        yyval.traducao += "\t" + fimRotulo +":\n";  
                    }
                }
                else{
                    if(yyvsp[-4].tipo != "bool"){
                        yyerror("Erro: A condição do 'for' deve ser uma expressão booleana válida");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        yyval.label = genTemp(); 
                        yyval.traducao += yyvsp[-6].traducao + "\t" + iniRotulo + ":\n" + yyvsp[-4].traducao;
                        yyval.traducao += "\t" + yyval.label + " = " + "!" + yyvsp[-4].label + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + fimRotulo + ";\n";
                        yyval.declaracao += yyvsp[-6].declaracao + yyvsp[-4].declaracao + yyvsp[-2].declaracao + yyvsp[0].declaracao + "\tint " + yyval.label + ";\n";
                        yyval.traducao +=  yyvsp[0].traducao + yyvsp[-2].traducao ;
                        yyval.traducao += string("\tgoto ") + iniRotulo + ";\n\t" + fimRotulo + ":\n";
                    }
                }
            }
#line 2490 "y.tab.c"
    break;

  case 45: /* WHILE: TK_WHILE '(' E ')' BLOCO_LOOP  */
#line 860 "sintatica.y"
            {
                if(verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[-2].label + " sem valor atribuido");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        gerouRotulo = false;
                        yyval.traducao += "\t" + iniRotulo + ":\n";
                        yyval.label = genTemp();
                        yyval.traducao += yyvsp[-2].traducao + "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + fimRotulo + ";\n";
                        yyval.traducao += yyvsp[0].traducao + "\tgoto " + iniRotulo +";\n";
                        yyval.traducao += "\t" + fimRotulo + ":\n";
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                    }
                }
                else{
                    if(yyvsp[-2].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        gerouRotulo = false;
                        yyval.traducao += "\t" + iniRotulo + ":\n";
                        yyval.label = genTemp();
                        yyval.traducao += yyvsp[-2].traducao + "\t" + yyval.label + " = " + "!" + yyvsp[-2].label + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + fimRotulo + ";\n";
                        yyval.traducao += yyvsp[0].traducao + "\tgoto " + iniRotulo +";\n";
                        yyval.traducao += "\t" + fimRotulo + ":\n";
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                    }
                }
                gerouRotulo = false;
            }
#line 2537 "y.tab.c"
    break;

  case 46: /* DO_WHILE: TK_DO BLOCO_LOOP TK_WHILE '(' E ')' ';'  */
#line 905 "sintatica.y"
            {
                if(verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "bool"){
                        yyerror("Erro: A condição do 'while' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[-2].label + " sem valor atribuido");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        yyval.traducao += "\t" + iniRotulo + ":\n";
                        yyval.declaracao += yyvsp[-5].declaracao + yyvsp[-2].declaracao;
                        yyval.traducao += yyvsp[-5].traducao + yyvsp[-2].traducao;
                        yyval.label = genTemp();
                        yyval.traducao += "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + fimRotulo + ";\n";
                        yyval.traducao += "\t"+ iniRotulo +":\n";
                    }
                }
                else{
                    if(yyvsp[-2].tipo != "bool"){
                        yyerror("Erro: A condição do 'while' deve ser uma expressão booleana válida");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        yyval.traducao += "\t" + iniRotulo + "\n";
                        yyval.declaracao += yyvsp[-5].declaracao + yyvsp[-2].declaracao;
                        yyval.traducao += yyvsp[-5].traducao + yyvsp[-2].traducao;
                        yyval.label = genTemp();
                        yyval.traducao += "\t" + yyval.label + " = " + "!" + yyvsp[-2].label + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + fimRotulo + ";\n";
                        yyval.traducao += "\t"+ iniRotulo +":\n";
                    }
                }
                gerouRotulo = false;
            }
#line 2582 "y.tab.c"
    break;

  case 47: /* BLOCO_LOOP: '{' INI CMD FIM '}'  */
#line 950 "sintatica.y"
            {
                yyval.declaracao += yyvsp[-2].declaracao;
                yyval.traducao += yyvsp[-2].traducao;
                if(!gerouRotulo){
                    pilha_rotulo.push_back(make_tuple(genRot(),genRot())); //ini fim
                }
            }
#line 2594 "y.tab.c"
    break;

  case 48: /* CMD: COMANDOS BREAK_OR_CONTINUE CMD  */
#line 959 "sintatica.y"
                                            {
                yyval.declaracao = yyvsp[-2].declaracao + yyvsp[-1].declaracao + yyvsp[0].declaracao;
                yyval.traducao = yyvsp[-2].traducao + yyvsp[-1].traducao + yyvsp[0].traducao;
            }
#line 2603 "y.tab.c"
    break;

  case 49: /* CMD: COMANDOS  */
#line 964 "sintatica.y"
            {
                yyval.declaracao = yyvsp[0].declaracao;
                yyval.traducao = yyvsp[0].traducao;
            }
#line 2612 "y.tab.c"
    break;

  case 50: /* BREAK_OR_CONTINUE: TK_BREAK ';'  */
#line 971 "sintatica.y"
            {     
                if(!gerouRotulo){
                    pilha_rotulo.push_back(make_tuple(genRot(),genRot())); //ini fim
                    gerouRotulo = true;
                }
                string lula = get<1>(pilha_rotulo.back());
                yyval.traducao += "\t" + string("goto ") + lula + ";\n";
            }
#line 2625 "y.tab.c"
    break;

  case 51: /* BREAK_OR_CONTINUE: TK_CONTINUE ';'  */
#line 980 "sintatica.y"
            {
                if(!gerouRotulo){
                    pilha_rotulo.push_back(make_tuple(genRot(),genRot())); //ini fim
                    gerouRotulo = true;
                }
                string iniRotulo = get<0>(pilha_rotulo.back());
                yyval.traducao += "\t" + string("goto ") + iniRotulo + ";\n"; 
            }
#line 2638 "y.tab.c"
    break;

  case 52: /* SWITCH: TK_SWITCH '(' E ')' BLOCO_SWITCH  */
#line 994 "sintatica.y"
            {
                string rotuloIni = genRot();
                string rotuloFim = genRot();
                yyval.traducao += yyvsp[-2].traducao + "\t" +rotuloIni + "\n" + yyvsp[0].traducao; 
                yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                yyval.traducao += "\t" + rotuloFim + "\n";
                defaultExecutado = false;
            }
#line 2651 "y.tab.c"
    break;

  case 53: /* BLOCO_SWITCH: '{' CASE_LISTA '}'  */
#line 1005 "sintatica.y"
            {
                // Faça o processamento necessário para o bloco switch
                yyval.traducao += yyvsp[-1].traducao;
                yyval.declaracao += yyvsp[-1].declaracao;
            }
#line 2661 "y.tab.c"
    break;

  case 54: /* CASE_LISTA: CASE_STMT CASE_LISTA  */
#line 1013 "sintatica.y"
            {
                yyval.traducao += yyvsp[0].traducao;
                yyval.declaracao += yyvsp[0].declaracao;
            }
#line 2670 "y.tab.c"
    break;

  case 55: /* CASE_LISTA: %empty  */
#line 1018 "sintatica.y"
            {
                // Caso base: não há mais casos na lista
                yyval.traducao = "";
                yyval.declaracao = "";
            }
#line 2680 "y.tab.c"
    break;

  case 56: /* CASE_STMT: CASE  */
#line 1027 "sintatica.y"
            {
                // Faça o processamento necessário para o caso
            }
#line 2688 "y.tab.c"
    break;

  case 57: /* CASE: TK_CASE E TK_DP COMANDOS  */
#line 1033 "sintatica.y"
            {
                if(verificaVar(yyvsp[-2].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[-2].label + " sem valor atribuido");
                    }
                    else{
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                        string rotuloIni = genRot();
                        string rotuloFim = genRot();
                        yyval.label = genTemp();
                        yyval.declaracao += "\t" + string("int ") + yyval.label + ";\n";
                        yyval.traducao += "\t" + rotuloIni + "\n"; 
                        yyval.traducao += yyvsp[-2].traducao;
                        yyval.traducao += "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + rotuloFim + ";\n";
                        yyval.traducao += yyvsp[0].traducao;
                        yyval.traducao += "\t"+ rotuloFim +"\n";
                    }
                }
                else{
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                        string rotuloIni = genRot();
                        string rotuloFim = genRot();
                        yyval.label = genTemp();
                        yyval.declaracao += "\t" + string("int ") + yyval.label + ";\n";
                        yyval.traducao += "\t" + rotuloIni + "\n"; 
                        yyval.traducao += yyvsp[-2].traducao;
                        yyval.traducao += "\t" + yyval.label + " = " + "!" + yyvsp[-2].label + ";\n";
                        yyval.traducao += "\tif("+ yyval.label + ")" + " goto " + rotuloFim + ";\n";
                        yyval.traducao += yyvsp[0].traducao;
                        yyval.traducao += "\t"+ rotuloFim +"\n";
                }
                

            }
#line 2728 "y.tab.c"
    break;

  case 58: /* CASE: TK_DEFAULT TK_DP COMANDOS  */
#line 1069 "sintatica.y"
            {
                if(defaultExecutado){
                   yyerror("ERRO: Mais de um case padrão (default) encontrado.");
                }else{
                    yyval.declaracao += yyvsp[0].declaracao;
                    string rotuloIni = genRot();
                    string rotuloFim = genRot();
                    yyval.traducao += "\t" + rotuloIni + "\n"; 
                    yyval.traducao += yyvsp[0].traducao;
                    yyval.traducao += "\t"+ rotuloFim +"\n";
                    defaultExecutado = true;
                }
            }
#line 2746 "y.tab.c"
    break;

  case 59: /* PRINT: TK_PRINT '(' EXPRESSAO ')' ';'  */
#line 1085 "sintatica.y"
            {   
                yyval.declaracao += yyvsp[-2].declaracao;

                yyval.traducao += yyvsp[-2].strcpy + auxPrint + "\t" + string("cout << ") + yyvsp[-2].traducao + ";\n";
                auxPrint = "";
            }
#line 2757 "y.tab.c"
    break;

  case 60: /* EXPRESSAO: TEXTO  */
#line 1094 "sintatica.y"
            {
                yyval.declaracao = yyvsp[0].declaracao;
                yyval.traducao = yyvsp[0].traducao;
                yyval.strcpy = yyvsp[0].strcpy;
            }
#line 2767 "y.tab.c"
    break;

  case 61: /* EXPRESSAO: TEXTO '+' EXPRESSAO  */
#line 1100 "sintatica.y"
            {
                if(verificaVar(yyvsp[0].label)){
                    string tipo = pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo;
                    if(tipo == "int" || tipo == "float" || tipo == "bool"){
                        yyerror("Apenas valores do tipo 'char' ou 'string' podem ser concatenados!");
                    }
                    
                } // ##############################################
                //VAR NUM
                if(verificaVar(yyval.label) && !verificaVar(yyvsp[0].label)){
                    string aux = genTemp();
                    yyval.declaracao += yyvsp[0].declaracao + "\tchar " + aux + "[" + to_string(pilha[busca_escopo(yyval.label)][yyval.label].valor.length() + yyvsp[0].label.length() - 2) + "];\n";
                    yyval.strcpy += yyvsp[0].strcpy;
                    auxPrint += "\tstrcpy(" + aux + ", strcat(" + yyval.traducao + ", " + yyvsp[0].label2 + "));\n";
                    yyval.traducao = aux;
                //VAR VAR
                }else if(verificaVar(yyval.label) && verificaVar(yyval.label)){
                    string aux = genTemp();
                    yyval.declaracao += yyvsp[0].declaracao + "\tchar " + aux + "[" + to_string(pilha[busca_escopo(yyval.label)][yyval.label].valor.length() + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].valor.length() - 2) + "];\n";
                    yyval.strcpy += yyvsp[0].strcpy;
                    auxPrint += "\tstrcpy(" + aux + ", strcat(" + yyval.traducao + ", " + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + "));\n";
                    yyval.traducao = aux;
                //NUM VAR
                }else if(!verificaVar(yyval.label) && verificaVar(yyvsp[0].label)){
                    string aux = genTemp();
                    yyval.declaracao += yyvsp[0].declaracao + "\tchar " + aux + "["  + to_string(yyval.traducao.length() + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].valor.length() - 2) + "];\n";
                    yyval.strcpy += yyvsp[0].strcpy;
                    auxPrint += "\tstrcpy(" + aux + ", strcat(" + yyval.traducao + ", " + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + "));\n";
                    yyval.traducao = aux;
                }
                //NUM NUM
                else{
                    yyval.label = genTemp();
                    yyval.declaracao += yyvsp[0].declaracao + "\tchar " + yyval.label + "[" + to_string(yyval.traducao.length() + yyvsp[0].traducao.length() - 2) + "];\n";
                    yyval.strcpy += yyvsp[0].strcpy;
                    auxPrint += "\tstrcpy(" + yyval.label + ", strcat(" + yyval.label2 + ", " + yyvsp[0].label2 + "));\n";
                    yyval.traducao = yyval.label;
                } 
            }
#line 2811 "y.tab.c"
    break;

  case 62: /* TEXTO: TK_STRING  */
#line 1142 "sintatica.y"
            {   
                yyval.tipo = "string";
                yyval.label = genTemp();
                yyval.valor = yyvsp[0].label;
                yyval.declaracao += "\t" + string("char") + " " + yyval.label + string("[") + to_string(yyvsp[0].label.length()-1) +string("]")+ ";\n";
                yyval.strcpy += "\t" + string("strcpy(") + yyval.label + ", "+ yyvsp[0].label + ")"+";\n"; 
                yyval.traducao += yyval.valor;
                yyval.label2 += yyval.label;
            }
#line 2825 "y.tab.c"
    break;

  case 63: /* TEXTO: TK_CHAR  */
#line 1152 "sintatica.y"
            {
                yyval.tipo = "char";
                yyval.label = genTemp();
                yyval.valor = yyvsp[0].label;
                yyval.declaracao += "\t" + string("char") + " " + yyval.label + string("[") + to_string(yyvsp[0].label.length()-1) +string("]")+ ";\n";
                yyval.strcpy += "\t" + string("strcpy(") + yyval.label + ", "+ yyvsp[0].label + ")"+";\n";
                yyval.traducao += yyvsp[0].label;
            }
#line 2838 "y.tab.c"
    break;

  case 64: /* TEXTO: TK_ID  */
#line 1161 "sintatica.y"
            {
                yyval.traducao += pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp;
            }
#line 2846 "y.tab.c"
    break;

  case 65: /* E: E '>' E  */
#line 1168 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], ">");
            }
#line 2854 "y.tab.c"
    break;

  case 66: /* E: E '<' E  */
#line 1172 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "<");
            }
#line 2862 "y.tab.c"
    break;

  case 67: /* E: E EQ E  */
#line 1176 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "==");
            }
#line 2870 "y.tab.c"
    break;

  case 68: /* E: E NE E  */
#line 1180 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "!=");
            }
#line 2878 "y.tab.c"
    break;

  case 69: /* E: E GE E  */
#line 1184 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], ">=");
            }
#line 2886 "y.tab.c"
    break;

  case 70: /* E: E LE E  */
#line 1188 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "<=");
            }
#line 2894 "y.tab.c"
    break;

  case 71: /* E: E AND E  */
#line 1192 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "&&");
            }
#line 2902 "y.tab.c"
    break;

  case 72: /* E: E OR E  */
#line 1196 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "||");
            }
#line 2910 "y.tab.c"
    break;

  case 73: /* E: NO E  */
#line 1200 "sintatica.y"
            {	
                
                //VAR
                if(verificaVar(yyvsp[0].label)){
                    if(pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo != "bool"){
                        yyerror("ERRO: Operadores Lógicos só aceitam tipo Booleano!");
                    }
                    yyval.label = genTemp();
                    yyval.tipo = "bool";
                    yyval.declaracao += yyvsp[-1].declaracao + yyvsp[0].declaracao + "\t" + "int" + " " + yyval.label + ";\n";
                    yyval.traducao += yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + "!" + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + ";\n";
                }else{
                    //NAO VAR
                    if(yyvsp[0].tipo != "bool"){
                        yyerror("ERRO: Operadores Lógicos só aceitam tipos Booleano!");
                    }
                    yyval.label = genTemp();
                    yyval.tipo = "bool";
                    yyval.declaracao += yyvsp[-1].declaracao + yyvsp[0].declaracao + "\t" + "int" + " " + yyval.label + ";\n";
                    yyval.traducao += yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + "!" + yyvsp[0].label + ";\n";
                }
            }
#line 2937 "y.tab.c"
    break;

  case 74: /* E: E '+' E  */
#line 1223 "sintatica.y"
            {	
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "+");
            }
#line 2945 "y.tab.c"
    break;

  case 75: /* E: E '-' E  */
#line 1227 "sintatica.y"
            {
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "-");
            }
#line 2953 "y.tab.c"
    break;

  case 76: /* E: E '*' E  */
#line 1231 "sintatica.y"
            {
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "*");
            }
#line 2961 "y.tab.c"
    break;

  case 77: /* E: E '/' E  */
#line 1235 "sintatica.y"
            {
				operacao(yyval,yyvsp[-2],yyvsp[-1],yyvsp[0], "/");
            }
#line 2969 "y.tab.c"
    break;

  case 78: /* E: TK_ID '=' E  */
#line 1239 "sintatica.y"
            {   
                //E -> VAR  
                if(verificaVar(yyvsp[0].label)){
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "bool" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo != "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "bool" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo == "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "char" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo != "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "char" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo == "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "string" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo != "string"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "string" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo == "string"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].atribuido == 0){
                       yyerror("ERRO: Variável " + yyvsp[0].label + " sem valor atribuido");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "int" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo == "string"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "int" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo != "int"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo == "string" && pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "string"){
                    yyerror("ERRO: Tipos difentes!");
                    }
                    
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "float" && pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].tipo == "int"){
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        yyval.label = genTemp();
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao + "\t" + "float" + " " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + "(" + "float" + ")" + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + ";\n";
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + yyval.label + ";\n";
				    }
                    else if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "int" && yyvsp[0].tipo == "float"){
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        yyval.label = genTemp();
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao + "\t" + "int" + " " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + "(" + "int" + ")" + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + ";\n";
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + yyval.label + ";\n";
                    }
				    //IGUAIS
                    else{
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                            if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "string"){
                                pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].valor = yyvsp[0].valor;
                                yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + string("(char*) malloc(") + to_string(pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].valor.length()-1) + string(")") + ";\n";
                                yyval.traducao += "\t" + string("strcpy(") + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + string(", ") + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + ");\n";
                                pilha_malloc.push_back(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp);
                            }
                            else{
                                yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + pilha[busca_escopo(yyvsp[0].label)][yyvsp[0].label].temp + ";\n";
                            }
                        
                    }
                }
                else{
                    //E -> NUM
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "bool" && yyvsp[0].tipo != "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    } 
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "bool" && yyvsp[0].tipo == "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    } 
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "char" && yyvsp[0].tipo != "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "char" && yyvsp[0].tipo == "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if((pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "string") && (yyvsp[0].tipo != "string")){
                        yyerror("ERRO: Tipos difentes!");
                    }    
                    if(yyvsp[0].tipo == "string" && pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo != "string"){
                    yyerror("ERRO: Tipos difentes!");
                }   
                    
                    
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "float" && yyvsp[0].tipo == "int"){
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        yyvsp[0].tipo = "float";
                        yyval.label = genTemp();
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao + "\t" + yyvsp[0].tipo + " " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + "(" + yyvsp[0].tipo + ")" + yyvsp[0].label + ";\n";
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + yyval.label + ";\n";
                    }
                    else if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "int" && yyvsp[0].tipo == "float"){
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        yyvsp[0].tipo = "int";
                        yyval.label = genTemp();
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao + "\t" + yyvsp[0].tipo + " " + yyval.label + ";\n";
                        yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = " + "(" + yyvsp[0].tipo + ")" + yyvsp[0].label + ";\n";
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + yyval.label + ";\n";
                    }
                    //IGUAIS -string
                    if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].tipo == "string"){
                        if(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido == 1){
                            int i;
                            for (i = 0; i < pilha_malloc.size(); i++) {
                                if (pilha_malloc[i] == pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp) {
                                    break; 
                                }
                            }
                            string aux = pilha_malloc[i];  // Obter o último elemento da pilha
                            pilha_malloc.erase(pilha_malloc.begin() + i);  // Remover o último elemento da pilha
                            yyval.traducao += string("\t") + string("free(") + aux + ");\n";  // Adicionar a instrução 
                        }
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].valor = yyvsp[0].valor;
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                        yyval.traducao += "\t" + string("strcpy(") + yyvsp[0].label + string(", ") + yyvsp[0].valor + ");\n";
                        yyval.traducao += "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + string("(char*) malloc(") + to_string(yyvsp[0].valor.length()-1) + string(")") + ";\n";
                        yyval.traducao += "\t" + string("strcpy(") + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + string(", ") + yyvsp[0].label + ");\n";
                        pilha_malloc.push_back(pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp);
                    }
                    else{
                        pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].atribuido = 1;
                        yyval.declaracao += yyvsp[-2].declaracao + yyvsp[0].declaracao;
                        yyval.traducao += yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + pilha[busca_escopo(yyvsp[-2].label)][yyvsp[-2].label].temp + " = " + yyvsp[0].label + ";\n";
                    }
                }
            }
#line 3104 "y.tab.c"
    break;

  case 79: /* E: TK_NUM  */
#line 1370 "sintatica.y"
            {
				yyval.tipo = "int";
                yyval.valor = yyvsp[0].label;
				yyval.label = genTemp();
				yyval.declaracao += "\t" + yyval.tipo + " " + yyval.label + ";\n";
				yyval.traducao += "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";

                yyval.valor = yyvsp[0].label;
            }
#line 3118 "y.tab.c"
    break;

  case 80: /* E: TK_REAL  */
#line 1380 "sintatica.y"
            {
                yyval.tipo = "float";
                yyval.label = genTemp();
                yyval.declaracao += "\t" + yyval.tipo + " " + yyval.label + ";\n";
                yyval.traducao += "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
                //$$.label = $1.label;
            }
#line 3130 "y.tab.c"
    break;

  case 81: /* E: TK_CHAR  */
#line 1388 "sintatica.y"
            {
                yyval.tipo = "char";
                yyval.label = genTemp();
                yyval.declaracao += "\t" + yyval.tipo + " " + yyval.label + ";\n";
                yyval.traducao += "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
                //$$.label = $1.label;
            }
#line 3142 "y.tab.c"
    break;

  case 82: /* E: TK_STRING  */
#line 1396 "sintatica.y"
            {
                yyval.label = genTemp();
                yyval.tipo = "string";
                yyval.valor = yyvsp[0].label;
                yyval.declaracao += "\t" + string("char") + " " + yyval.label + string("[") +to_string(yyvsp[0].label.length()-1) +string("]")+ ";\n";
                yyval.traducao += "\t" + string("strcpy(") + yyval.label + ", " + yyvsp[0].label + ");\n";
                //$$.label = $1.label;
            }
#line 3155 "y.tab.c"
    break;

  case 83: /* E: TK_FALSE  */
#line 1405 "sintatica.y"
            {
                string valor = "0";
                string tipo = "int";
                yyval.tipo = "bool";
                yyval.label = genTemp();
                yyval.declaracao += "\t" + tipo + " " + yyval.label + ";\n";
                yyval.traducao += "\t" + yyval.label + " = " + valor + ";\n";
                //$$.label = valor;
            }
#line 3169 "y.tab.c"
    break;

  case 84: /* E: TK_TRUE  */
#line 1415 "sintatica.y"
            {
                string valor = "1";
                string tipo = "int";
                yyval.tipo = "bool";
                yyval.label = genTemp();
                yyval.declaracao += "\t" + tipo + " " + yyval.label + ";\n";
                yyval.traducao += "\t" + yyval.label + " = " + valor + ";\n";
                //$$.label = valor;
            }
#line 3183 "y.tab.c"
    break;

  case 85: /* E: TK_CAST_FLOAT E  */
#line 1425 "sintatica.y"
            {   
                yyval.tipo = "float";
                yyval.label = genTemp();

                yyval.declaracao += "\t" + yyval.tipo + " " + yyval.label + ";\n";

                //CAST VAR
                if(verificaVar(yyvsp[0].label)){
                    yyval.traducao += "\t" + yyval.label + " = "  + "(float)"  + pilha[bloco_atual][yyvsp[0].label].temp + ";\n";
                }
                //CAST NUM
                else if(!verificaVar(yyvsp[0].label)){
                    yyval.declaracao += yyvsp[-1].declaracao + yyvsp[0].declaracao;
                    yyval.traducao += yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = "  + "(float)"  + yyvsp[0].label + ";\n";
                }
            }
#line 3204 "y.tab.c"
    break;

  case 86: /* E: TK_CAST_INT E  */
#line 1442 "sintatica.y"
            {   
                yyval.tipo = "int";
                yyval.label = genTemp();

                yyval.declaracao += "\t" + yyval.tipo + " " + yyval.label + ";\n";

                //CAST VAR
                if(verificaVar(yyvsp[0].label)){
                    yyval.traducao += "\t" + yyval.label + " = "  + "(int)"  + pilha[bloco_atual][yyvsp[0].label].temp + ";\n";
                }
                //CAST NUM
                else if(!verificaVar(yyvsp[0].label)){
                    yyval.declaracao += yyvsp[-1].declaracao + yyvsp[0].declaracao;
                    yyval.traducao += yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = "  + "(int)"  + yyvsp[0].label + ";\n";
                }
            }
#line 3225 "y.tab.c"
    break;

  case 87: /* E: TK_CAST_CHAR E  */
#line 1459 "sintatica.y"
            {   
                yyval.tipo = "char";
                yyval.label = genTemp();

                yyval.declaracao += "\t" + yyval.tipo + " " + yyval.label + ";\n";

                //CAST VAR
                if(verificaVar(yyvsp[0].label)){
                    yyval.traducao += "\t" + yyval.label + " = "  + "(char)"  + pilha[bloco_atual][yyvsp[0].label].temp + ";\n";
                }
                //CAST NUM
                else if(!verificaVar(yyvsp[0].label)){
                    yyval.declaracao += yyvsp[-1].declaracao + yyvsp[0].declaracao;
                    yyval.traducao += yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + yyval.label + " = "  + "(char)"  + yyvsp[0].label + ";\n";
                }
            }
#line 3246 "y.tab.c"
    break;

  case 88: /* E: TK_ID  */
#line 1476 "sintatica.y"
            {
                naoDeclarado(yyvsp[0].label);
                //TIPO_SIMBOLO var = pilha[bloco_atual][$1.label];
                //$$.tipo = var.tipo;
            }
#line 3256 "y.tab.c"
    break;

  case 89: /* E: TK_ID '[' E ']'  */
#line 1482 "sintatica.y"
            {
                yyval.label = yyvsp[-3].label + '[' + yyvsp[-1].label + ']';
            }
#line 3264 "y.tab.c"
    break;

  case 90: /* E: %empty  */
#line 1486 "sintatica.y"
            {
                
            }
#line 3272 "y.tab.c"
    break;


#line 3276 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1491 "sintatica.y"


#include "lex.yy.c"

int yyparse();

string genTemp()
{
	temp++;
	return  "t" + std::to_string(temp);
}
string genRot()
{
	tempRot++;
	return  "label_" + std::to_string(tempRot);
}

void declarado(string chave){
	if (verificaVarBloco(chave))
    	yyerror("ERRO: Variável " + chave + " já foi declarada!");
}

void naoDeclarado(string chave){
	if (!verificaVar(chave))
		yyerror("ERRO: Variável " + chave + " não foi declarada!");
}

int verificaVar(string var){
    for(int i=bloco_atual;i>=0;i--){
        if(!(pilha[i].find(var) == pilha[i].end())){
            return 1;
        }
    }  
    return 0;
}

int verificaVarBloco(string var){
    if(!(pilha[bloco_atual].find(var) == pilha[bloco_atual].end())){
        return 1;
    }
    return 0;
}

int busca_escopo(string var){
    for(int i= bloco_atual; i>=0; i--){
        if(!(pilha[i].find(var) == pilha[i].end())){
            return pilha[i][var].bloco;
        }
    } 
    yyerror("ERRO: Variável " + var + " não foi declarada!");  
    return 0;
} 

void conversaoImplicitaOp(atributos& $$, atributos& $1, atributos& $3, string operador, string tipo){
    //NUMERO NUMERO
    if(!verificaVar($1.label) && !verificaVar($3.label)){
        if(($1.tipo == "int" && $3.tipo == "float") || ($1.tipo == "float" && $3.tipo == "int") ){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao += $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao += $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + $1.label + ";\n";

            string aux = $$.label;
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = "float";
            }
            else{
                $$.tipo = "bool";
            }
            
            $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
        }
        else{
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = $1.tipo;
            }
            else{
                $$.tipo = "bool";
            }
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + operador + " " + $3.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
        }
    }
    //VAR NUMERO
    else if(verificaVar($1.label) && !verificaVar($3.label)){
        if((pilha[busca_escopo($1.label)][$1.label].tipo == "int" && $3.tipo == "float") || (pilha[busca_escopo($1.label)][$1.label].tipo == "float" && $3.tipo == "int") ){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + pilha[busca_escopo($1.label)][$1.label].temp + ";\n";

            string aux = $$.label;
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = "float";
            }
            else{
                $$.tipo = "bool";
            }
            
            $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
        }
        else{
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = pilha[busca_escopo($1.label)][$1.label].tipo;
            }
            else{
                $$.tipo = "bool";
            }
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + pilha[busca_escopo($1.label)][$1.label].temp + " " + operador + " " + $3.label + ";\n";
        }
    }
    //NUMERO VAR
    else if(!verificaVar($1.label) && verificaVar($3.label)){
        if(($1.tipo == "int" && pilha[busca_escopo($3.label)][$3.label].tipo == "float") || ($1.tipo == "float" && pilha[busca_escopo($3.label)][$3.label].tipo == "int") ){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + $1.label + ";\n";

            string aux = $$.label;
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = "float";
            }
            else{
                $$.tipo = "bool";
            }
            
            $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
        }
        else{
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = $1.tipo;
            }
            else{
                $$.tipo = "bool";
            }
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + operador + " " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
        }
    }
    //VAR VAR
    else if(verificaVar($1.label) && verificaVar($3.label)){
        if((pilha[busca_escopo($1.label)][$1.label].tipo == "int" && pilha[busca_escopo($3.label)][$3.label].tipo == "float") || (pilha[busca_escopo($1.label)][$1.label].tipo == "float" && pilha[busca_escopo($3.label)][$3.label].tipo == "int") ){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + pilha[busca_escopo($1.label)][$1.label].temp + ";\n";

            string aux = $$.label;
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = "float";
            }
            else{
                $$.tipo = "bool";
            }
            
            $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
        }
        else{
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = pilha[busca_escopo($1.label)][$1.label].tipo;
            }
            else{
                $$.tipo = "bool";
            }
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + pilha[busca_escopo($1.label)][$1.label].temp + " " + operador + " " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
        }
    }
}

void operacao(atributos& $$, atributos& $1, atributos& $2, atributos& $3, string operador){
    if(verificaVar($1.label) || verificaVar($3.label)){
        // $1 var
        if(verificaVar($1.label)){
            if (pilha[busca_escopo($1.label)][$1.label].atribuido == 0){
                yyerror("ERRO: variável " + $1.label + " sem valor atribuido!");
            }
            if(operador == "||" || operador == "&&"){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" || pilha[busca_escopo($1.label)][$1.label].tipo  == "float" || pilha[busca_escopo($1.label)][$1.label].tipo == "char" || pilha[busca_escopo($1.label)][$1.label].tipo == "string" || $3.tipo == "int" || $3.tipo == "float" || $3.tipo == "char" || $3.tipo == "string"){
                    yyerror("ERRO: Operadores lógicos só aceitam tipo Booleano!");
                }
            }
            if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" ||  $3.tipo == "bool"){
                    yyerror("ERRO: Operadores relacionais não aceitam tipo Booleano!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" ||  $3.tipo == "string"){
                    yyerror("ERRO: Operadores relacionais não aceitam tipo string!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" ||  $3.tipo == "char"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo char!");
                }
            }
            if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" || $3.tipo == "bool"){
                    yyerror("Erro: operações aritiméticas não aceitam booleanos!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" ||  $3.tipo == "string"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo string!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" ||  $3.tipo == "char"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo char!");
                }
            }
        }
        // $3 var
        if(verificaVar($3.label)){ 
            if (pilha[busca_escopo($3.label)][$3.label].atribuido == 0){
                yyerror("ERRO: Variável " + $3.label + " sem valor atribuido!");
            }
            if(operador == "||" || operador == "&&"){
                if($1.tipo == "int" || $1.tipo == "float" || $1.tipo == "char" || $1.tipo == "string" || pilha[busca_escopo($3.label)][$3.label].tipo == "int" || pilha[busca_escopo($3.label)][$3.label].tipo == "float" || pilha[busca_escopo($3.label)][$3.label].tipo == "char" || pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores Lógicos só aceitam tipo Booleano!");
                }
            }
            if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
                if($1.tipo == "bool" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                    yyerror("ERRO: Operadores Relacionais não aceitam tipo Booleano!");
                }
                if($1.tipo == "string" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores Relacionais não aceitam tipo string!");
                }
                if($1.tipo == "char" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo char!");
                }
            }
            if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                if($1.tipo == "bool" || pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                    yyerror("Erro: operações aritiméticas não aceitam booleanos!");
                }
                if($1.tipo == "string" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo string!");
                }
                if($1.tipo == "char" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo char!");
                }
            }
        }
        // $1 e $3 var
        if(verificaVar($1.label) && verificaVar($3.label)){
            if (pilha[busca_escopo($1.label)][$1.label].atribuido == 0){
                yyerror("ERRO: Variável " + $1.label + " sem valor atribuido!");
            }
            if (pilha[busca_escopo($3.label)][$3.label].atribuido == 0){
                yyerror("ERRO: Variável " + $3.label + " sem valor atribuido!");
            }
            if(operador == "||" || operador == "&&"){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" || pilha[busca_escopo($1.label)][$1.label].tipo == "float" || pilha[busca_escopo($1.label)][$1.label].tipo == "char" || pilha[busca_escopo($1.label)][$1.label].tipo == "string" || pilha[busca_escopo($3.label)][$3.label].tipo == "int" || pilha[busca_escopo($3.label)][$3.label].tipo == "float" || pilha[busca_escopo($3.label)][$3.label].tipo == "char" || pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores Lógicos só aceitam tipo Booleano!");
                }
            }
            if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                    yyerror("ERRO: Operadores Relacionais não aceitam tipo Booleano!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores Relacionais não aceitam tipo string!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo char!");
            }
            }
            if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" || pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                    yyerror("Erro: operações aritiméticas não aceitam booleanos!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo string!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo char!");
                }
            }
        }
    }
    // $1 e $3 não var
    else{
        if(operador == "||" || operador == "&&"){
            if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" || pilha[busca_escopo($1.label)][$1.label].tipo == "float" || pilha[busca_escopo($1.label)][$1.label].tipo == "char" || pilha[busca_escopo($1.label)][$1.label].tipo == "string" || $3.tipo == "int" || $3.tipo == "float" || $3.tipo == "char" || $3.tipo == "string"){
                yyerror("ERRO: Operadores Lógicos só aceitam tipo Booleano!");
            }
        }
        if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
            if($1.tipo == "bool" ||  $3.tipo == "bool"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo Booleano!");
            }
            if($1.tipo == "string" ||  $3.tipo == "string"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo string!");
            }
            if($1.tipo == "char" ||  $3.tipo == "char"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo char!");
            }
        }
        if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
            if($1.tipo == "bool" || $3.tipo == "bool"){
                yyerror("Erro: operações aritiméticas não aceitam booleanos!");
            }
            if($1.tipo == "string" ||  $3.tipo == "string"){
                yyerror("ERRO: Operadores aritiméticos não aceitam tipo string!");
            }
            if($1.tipo == "char" ||  $3.tipo == "char"){
                yyerror("ERRO: Operadores aritiméticos não aceitam tipo char!");
            }
        }
    }

    //relacionanis e lógicos
    if(operador == ">" || operador == "<" || operador == ">=" || operador == "<=" || operador == "==" || operador == "!=" || operador == "&&" || operador == "||"){
        conversaoImplicitaOp($$, $1, $3, operador, "int");
    }
    
    //aritimeticos
    if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
        conversaoImplicitaOp($$,$1,$3,operador,"int");
    }
}

void empilha(){
    pilha.push_back(unordered_map<string, TIPO_SIMBOLO>());
}

void desempilha(){
    pilha.pop_back();
}

int main( int argc, char* argv[] )
{
	temp = 0;
    tempRot = 0;
	yyparse();
	

	return 0;
}

void yyerror( string MSG )
{
	cout << "Linha " + to_string(contn) + " -> " + MSG << endl;
    //cout << MSG << endl;
	exit (0);
}
