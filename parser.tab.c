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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int yylex();
void yyerror(const char *s);
extern int yylineno;
extern char* yytext;

int indent_level = 0;
int in_data_division = 0;
char* prog_name;
char* current_paragraph = NULL;
char* current_paragraph_params = NULL;
char* main_procedure_func = NULL;  // Variable para almacenar la función principal

typedef struct {
    char* name;
    int occurs;
} ArrayInfo;
ArrayInfo array_stack[100];
int array_stack_ptr = 0;

void emit(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    for (int i = 0; i < indent_level; i++) {
        printf("    ");
    }
    vprintf(fmt, args);
    va_end(args);
    printf("\n");
}

char* format_identifier(char* id) {
    for (char* p = id; *p; ++p) {
        if (*p == '-') *p = '_';
        else *p = tolower(*p);
    }
    return id;
}

char* build_expr(const char* op, const char* left, const char* right) {
    char* expr;
    asprintf(&expr, "%s %s %s", left, op, right);
    return expr;
}

char* build_unary_expr(const char* op, const char* operand) {
    char* expr;
    asprintf(&expr, "%s%s", op, operand);
    return expr;
}

char* make_valid_function_name(const char* id) {
    if (id[0] >= '0' && id[0] <= '9') {
        char* new_name;
        asprintf(&new_name, "para_%s", id);
        return new_name;
    } else {
        return strdup(id);
    }
}

char* get_valid_function_name(const char* id) {
    char* formatted = format_identifier(strdup(id));
    char* valid_name = make_valid_function_name(formatted);
    free(formatted);
    return valid_name;
}


#line 148 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_UMINUS = 3,                     /* UMINUS  */
  YYSYMBOL_IDENTIFICATION = 4,             /* IDENTIFICATION  */
  YYSYMBOL_DIVISION = 5,                   /* DIVISION  */
  YYSYMBOL_PROGRAM_ID = 6,                 /* PROGRAM_ID  */
  YYSYMBOL_PROCEDURE = 7,                  /* PROCEDURE  */
  YYSYMBOL_PROGRAM = 8,                    /* PROGRAM  */
  YYSYMBOL_EXIT = 9,                       /* EXIT  */
  YYSYMBOL_AUTHOR = 10,                    /* AUTHOR  */
  YYSYMBOL_INSTALLATION = 11,              /* INSTALLATION  */
  YYSYMBOL_DATE_WRITTEN = 12,              /* DATE_WRITTEN  */
  YYSYMBOL_DATE_COMPILED = 13,             /* DATE_COMPILED  */
  YYSYMBOL_SECURITY = 14,                  /* SECURITY  */
  YYSYMBOL_REMARKS = 15,                   /* REMARKS  */
  YYSYMBOL_DATA = 16,                      /* DATA  */
  YYSYMBOL_FILE_TOKEN = 17,                /* FILE_TOKEN  */
  YYSYMBOL_WORKING_STORAGE = 18,           /* WORKING_STORAGE  */
  YYSYMBOL_LOCAL_STORAGE = 19,             /* LOCAL_STORAGE  */
  YYSYMBOL_LINKAGE = 20,                   /* LINKAGE  */
  YYSYMBOL_SECTION = 21,                   /* SECTION  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_THEN = 23,                      /* THEN  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_END_IF = 25,                    /* END_IF  */
  YYSYMBOL_END_PERFORM = 26,               /* END_PERFORM  */
  YYSYMBOL_END_EVALUATE = 27,              /* END_EVALUATE  */
  YYSYMBOL_END = 28,                       /* END  */
  YYSYMBOL_MOVE = 29,                      /* MOVE  */
  YYSYMBOL_TO = 30,                        /* TO  */
  YYSYMBOL_INTO_TOKEN = 31,                /* INTO_TOKEN  */
  YYSYMBOL_DISPLAY = 32,                   /* DISPLAY  */
  YYSYMBOL_ACCEPT = 33,                    /* ACCEPT  */
  YYSYMBOL_COMPUTE = 34,                   /* COMPUTE  */
  YYSYMBOL_ADD = 35,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 36,                  /* SUBTRACT  */
  YYSYMBOL_MULTIPLY = 37,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 38,                    /* DIVIDE  */
  YYSYMBOL_PERFORM = 39,                   /* PERFORM  */
  YYSYMBOL_VARYING = 40,                   /* VARYING  */
  YYSYMBOL_FROM = 41,                      /* FROM  */
  YYSYMBOL_BY = 42,                        /* BY  */
  YYSYMBOL_UNTIL = 43,                     /* UNTIL  */
  YYSYMBOL_GO = 44,                        /* GO  */
  YYSYMBOL_PIC = 45,                       /* PIC  */
  YYSYMBOL_COMP = 46,                      /* COMP  */
  YYSYMBOL_COMP_3 = 47,                    /* COMP_3  */
  YYSYMBOL_VALUE = 48,                     /* VALUE  */
  YYSYMBOL_VALUES = 49,                    /* VALUES  */
  YYSYMBOL_INDEXED = 50,                   /* INDEXED  */
  YYSYMBOL_OCCURS = 51,                    /* OCCURS  */
  YYSYMBOL_OCCURS_TIMES = 52,              /* OCCURS_TIMES  */
  YYSYMBOL_REDEFINES = 53,                 /* REDEFINES  */
  YYSYMBOL_CALL = 54,                      /* CALL  */
  YYSYMBOL_USING = 55,                     /* USING  */
  YYSYMBOL_RETURNING = 56,                 /* RETURNING  */
  YYSYMBOL_EVALUATE = 57,                  /* EVALUATE  */
  YYSYMBOL_WHEN = 58,                      /* WHEN  */
  YYSYMBOL_OTHER = 59,                     /* OTHER  */
  YYSYMBOL_OR = 60,                        /* OR  */
  YYSYMBOL_AND = 61,                       /* AND  */
  YYSYMBOL_NOT = 62,                       /* NOT  */
  YYSYMBOL_GREATER = 63,                   /* GREATER  */
  YYSYMBOL_LESS = 64,                      /* LESS  */
  YYSYMBOL_GEQUAL = 65,                    /* GEQUAL  */
  YYSYMBOL_LEQUAL = 66,                    /* LEQUAL  */
  YYSYMBOL_EQUAL = 67,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 68,                    /* NEQUAL  */
  YYSYMBOL_PLUS = 69,                      /* PLUS  */
  YYSYMBOL_MINUS = 70,                     /* MINUS  */
  YYSYMBOL_MUL_OP = 71,                    /* MUL_OP  */
  YYSYMBOL_DIV_OP = 72,                    /* DIV_OP  */
  YYSYMBOL_LPAREN = 73,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 74,                    /* RPAREN  */
  YYSYMBOL_DOT = 75,                       /* DOT  */
  YYSYMBOL_COMMA_TOKEN = 76,               /* COMMA_TOKEN  */
  YYSYMBOL_GOBACK = 77,                    /* GOBACK  */
  YYSYMBOL_ENVIRONMENT = 78,               /* ENVIRONMENT  */
  YYSYMBOL_CONFIGURATION = 79,             /* CONFIGURATION  */
  YYSYMBOL_SOURCE_COMPUTER = 80,           /* SOURCE_COMPUTER  */
  YYSYMBOL_OBJECT_COMPUTER = 81,           /* OBJECT_COMPUTER  */
  YYSYMBOL_INPUT_OUTPUT = 82,              /* INPUT_OUTPUT  */
  YYSYMBOL_FILE_CONTROL = 83,              /* FILE_CONTROL  */
  YYSYMBOL_STOP = 84,                      /* STOP  */
  YYSYMBOL_RUN = 85,                       /* RUN  */
  YYSYMBOL_NUMBER = 86,                    /* NUMBER  */
  YYSYMBOL_BOOL = 87,                      /* BOOL  */
  YYSYMBOL_FLOAT = 88,                     /* FLOAT  */
  YYSYMBOL_IDENTIFIER = 89,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 90,                    /* STRING  */
  YYSYMBOL_PIC_STRING = 91,                /* PIC_STRING  */
  YYSYMBOL_YYACCEPT = 92,                  /* $accept  */
  YYSYMBOL_program = 93,                   /* program  */
  YYSYMBOL_optional_environment_division = 94, /* optional_environment_division  */
  YYSYMBOL_environment_division = 95,      /* environment_division  */
  YYSYMBOL_end_program = 96,               /* end_program  */
  YYSYMBOL_identification_division = 97,   /* identification_division  */
  YYSYMBOL_optional_dot = 98,              /* optional_dot  */
  YYSYMBOL_identification_entries = 99,    /* identification_entries  */
  YYSYMBOL_identification_entry = 100,     /* identification_entry  */
  YYSYMBOL_environment_sections = 101,     /* environment_sections  */
  YYSYMBOL_environment_section = 102,      /* environment_section  */
  YYSYMBOL_configuration_section = 103,    /* configuration_section  */
  YYSYMBOL_configuration_paragraphs = 104, /* configuration_paragraphs  */
  YYSYMBOL_configuration_paragraph = 105,  /* configuration_paragraph  */
  YYSYMBOL_input_output_section = 106,     /* input_output_section  */
  YYSYMBOL_input_output_paragraphs = 107,  /* input_output_paragraphs  */
  YYSYMBOL_input_output_paragraph = 108,   /* input_output_paragraph  */
  YYSYMBOL_data_division = 109,            /* data_division  */
  YYSYMBOL_110_1 = 110,                    /* $@1  */
  YYSYMBOL_data_sections = 111,            /* data_sections  */
  YYSYMBOL_data_section = 112,             /* data_section  */
  YYSYMBOL_data_items = 113,               /* data_items  */
  YYSYMBOL_param_items = 114,              /* param_items  */
  YYSYMBOL_data_item = 115,                /* data_item  */
  YYSYMBOL_param_item = 116,               /* param_item  */
  YYSYMBOL_level_number = 117,             /* level_number  */
  YYSYMBOL_pic_clause = 118,               /* pic_clause  */
  YYSYMBOL_comp_clause = 119,              /* comp_clause  */
  YYSYMBOL_value_clause = 120,             /* value_clause  */
  YYSYMBOL_occurs_clause = 121,            /* occurs_clause  */
  YYSYMBOL_redefines_clause = 122,         /* redefines_clause  */
  YYSYMBOL_literal = 123,                  /* literal  */
  YYSYMBOL_procedure_division = 124,       /* procedure_division  */
  YYSYMBOL_125_2 = 125,                    /* $@2  */
  YYSYMBOL_optional_using = 126,           /* optional_using  */
  YYSYMBOL_param_list = 127,               /* param_list  */
  YYSYMBOL_paragraphs = 128,               /* paragraphs  */
  YYSYMBOL_paragraph = 129,                /* paragraph  */
  YYSYMBOL_paragraph_header = 130,         /* paragraph_header  */
  YYSYMBOL_statements = 131,               /* statements  */
  YYSYMBOL_statement = 132,                /* statement  */
  YYSYMBOL_133_3 = 133,                    /* $@3  */
  YYSYMBOL_134_4 = 134,                    /* $@4  */
  YYSYMBOL_135_5 = 135,                    /* $@5  */
  YYSYMBOL_136_6 = 136,                    /* $@6  */
  YYSYMBOL_optional_then = 137,            /* optional_then  */
  YYSYMBOL_opt_else = 138,                 /* opt_else  */
  YYSYMBOL_139_7 = 139,                    /* $@7  */
  YYSYMBOL_evaluate_cases = 140,           /* evaluate_cases  */
  YYSYMBOL_evaluate_case = 141,            /* evaluate_case  */
  YYSYMBOL_142_8 = 142,                    /* $@8  */
  YYSYMBOL_opt_other = 143,                /* opt_other  */
  YYSYMBOL_144_9 = 144,                    /* $@9  */
  YYSYMBOL_literal_list = 145,             /* literal_list  */
  YYSYMBOL_call_params = 146,              /* call_params  */
  YYSYMBOL_condition = 147,                /* condition  */
  YYSYMBOL_logical_expr = 148,             /* logical_expr  */
  YYSYMBOL_comparison = 149,               /* comparison  */
  YYSYMBOL_expr = 150                      /* expr  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   420

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  311

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   346


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   123,   123,   134,   136,   140,   145,   153,   164,   175,
     177,   181,   182,   186,   190,   193,   196,   199,   202,   205,
     208,   211,   214,   217,   220,   223,   228,   230,   234,   235,
     239,   243,   245,   249,   252,   258,   262,   264,   268,   273,
     272,   278,   280,   284,   285,   286,   287,   290,   292,   295,
     297,   301,   316,   326,   330,   331,   335,   336,   337,   341,
     342,   346,   347,   355,   356,   360,   365,   370,   371,   378,
     377,   395,   396,   400,   403,   411,   412,   416,   429,   456,
     458,   462,   465,   464,   474,   473,   482,   484,   486,   488,
     490,   492,   494,   497,   496,   509,   508,   518,   524,   530,
     537,   541,   545,   551,   553,   556,   559,   558,   568,   569,
     574,   573,   582,   585,   584,   594,   595,   599,   600,   603,
     606,   607,   608,   609,   610,   614,   615,   616,   617,   618,
     619,   623,   628,   633,   634,   635,   636,   637,   638,   639,
     640
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
  "\"end of file\"", "error", "\"invalid token\"", "UMINUS",
  "IDENTIFICATION", "DIVISION", "PROGRAM_ID", "PROCEDURE", "PROGRAM",
  "EXIT", "AUTHOR", "INSTALLATION", "DATE_WRITTEN", "DATE_COMPILED",
  "SECURITY", "REMARKS", "DATA", "FILE_TOKEN", "WORKING_STORAGE",
  "LOCAL_STORAGE", "LINKAGE", "SECTION", "IF", "THEN", "ELSE", "END_IF",
  "END_PERFORM", "END_EVALUATE", "END", "MOVE", "TO", "INTO_TOKEN",
  "DISPLAY", "ACCEPT", "COMPUTE", "ADD", "SUBTRACT", "MULTIPLY", "DIVIDE",
  "PERFORM", "VARYING", "FROM", "BY", "UNTIL", "GO", "PIC", "COMP",
  "COMP_3", "VALUE", "VALUES", "INDEXED", "OCCURS", "OCCURS_TIMES",
  "REDEFINES", "CALL", "USING", "RETURNING", "EVALUATE", "WHEN", "OTHER",
  "OR", "AND", "NOT", "GREATER", "LESS", "GEQUAL", "LEQUAL", "EQUAL",
  "NEQUAL", "PLUS", "MINUS", "MUL_OP", "DIV_OP", "LPAREN", "RPAREN", "DOT",
  "COMMA_TOKEN", "GOBACK", "ENVIRONMENT", "CONFIGURATION",
  "SOURCE_COMPUTER", "OBJECT_COMPUTER", "INPUT_OUTPUT", "FILE_CONTROL",
  "STOP", "RUN", "NUMBER", "BOOL", "FLOAT", "IDENTIFIER", "STRING",
  "PIC_STRING", "$accept", "program", "optional_environment_division",
  "environment_division", "end_program", "identification_division",
  "optional_dot", "identification_entries", "identification_entry",
  "environment_sections", "environment_section", "configuration_section",
  "configuration_paragraphs", "configuration_paragraph",
  "input_output_section", "input_output_paragraphs",
  "input_output_paragraph", "data_division", "$@1", "data_sections",
  "data_section", "data_items", "param_items", "data_item", "param_item",
  "level_number", "pic_clause", "comp_clause", "value_clause",
  "occurs_clause", "redefines_clause", "literal", "procedure_division",
  "$@2", "optional_using", "param_list", "paragraphs", "paragraph",
  "paragraph_header", "statements", "statement", "$@3", "$@4", "$@5",
  "$@6", "optional_then", "opt_else", "$@7", "evaluate_cases",
  "evaluate_case", "$@8", "opt_other", "$@9", "literal_list",
  "call_params", "condition", "logical_expr", "comparison", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-213)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      23,    48,    56,   -18,    -8,  -213,    71,    66,  -213,  -213,
     184,    -8,    92,    84,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,   184,  -213,  -213,    -8,    99,    87,    40,   -47,   -38,
     -20,    -9,     0,    13,  -213,   -54,  -213,    78,   128,  -213,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,   121,   123,  -213,  -213,  -213,  -213,    70,
      -8,   -65,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,    -8,    -8,   131,  -213,    85,
    -213,  -213,    89,  -213,  -213,   145,   156,   161,   167,  -213,
     112,   114,  -213,    33,   124,    -8,    -8,    -8,    -8,  -213,
    -213,   114,  -213,    -8,    -8,    -8,  -213,    -8,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,   117,   120,  -213,   118,   118,
     118,   336,    -8,    -8,  -213,  -213,   134,  -213,   135,   217,
      90,    95,    95,   143,   144,    95,    95,   154,   168,   -26,
     207,   169,    95,    -8,   174,  -213,  -213,  -213,   215,   215,
      -8,    90,    95,    90,  -213,  -213,  -213,  -213,   238,    49,
    -213,   331,    95,    29,   -49,    -8,   195,    36,     3,   221,
     233,   176,    90,    -8,   178,   213,   183,  -213,    -8,   179,
      91,    91,  -213,  -213,   183,   -59,   148,  -213,  -213,    90,
      90,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,   101,   182,  -213,  -213,    95,   186,   187,    95,    95,
     231,    -8,  -213,    -8,    95,   220,  -213,  -213,  -213,  -213,
     225,    -8,  -213,  -213,  -213,   222,  -213,   183,   183,   183,
     183,   183,   183,   115,   115,  -213,  -213,    -8,   -49,    -8,
      -8,   -49,   -49,    95,  -213,  -213,   116,   183,    95,   224,
    -213,   152,   234,  -213,   212,  -213,  -213,  -213,  -213,  -213,
    -213,    86,  -213,    95,  -213,   226,   183,    57,  -213,   257,
    -213,  -213,  -213,  -213,  -213,   201,   235,  -213,   265,    95,
     271,   183,    95,  -213,  -213,    -8,   239,   203,    -8,  -213,
      -8,   -24,    -8,   183,   336,  -213,  -213,  -213,  -213,  -213,
     336,  -213,    90,  -213,   336,    -8,  -213,  -213,   305,    -8,
    -213
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     9,     1,     0,     0,     4,    10,
       0,     9,     0,     0,     9,     9,     9,     9,     9,     9,
       9,     8,    11,    26,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     5,    39,    71,     0,     2,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     0,     0,    27,    28,    29,    41,     0,
       9,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     9,     9,    40,    73,    72,
      69,     7,     0,    31,    36,     0,     0,     0,     0,    42,
       0,     0,     6,    30,    35,     9,     9,     9,     9,    74,
      78,    70,    75,     9,     9,     9,    32,     9,    37,    43,
      47,    47,    49,    76,    79,     0,     0,    38,    44,    45,
      46,    77,     9,     9,    53,    48,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    80,    33,    34,    54,    54,
       9,     0,     0,     0,   131,   132,   133,   134,   103,   119,
     123,     0,     0,     0,     9,     9,     0,     0,     0,     0,
       0,     0,     0,     9,     0,     0,    84,   100,     9,     0,
      56,    56,   101,   122,   139,     0,     0,   104,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,     0,     0,     0,     0,     0,
       0,     9,    97,     9,     0,     0,   102,    55,    57,    58,
      59,     9,   124,   140,    79,   120,   121,   125,   126,   127,
     128,   129,   130,   135,   136,   137,   138,     9,     9,     9,
       9,     9,     9,     0,    95,    99,     9,   117,     0,   112,
     108,     0,    61,    52,   105,    81,    88,    89,    90,    91,
      92,     0,    79,     0,    98,   110,   115,     0,   109,     0,
      65,    68,    66,    67,    60,     0,    63,   106,     0,     0,
       0,   118,     0,    79,   113,     9,     0,     0,     9,    79,
       9,     0,     9,   116,   111,    79,    85,    62,    64,    51,
     107,    83,     0,    96,   114,     9,    93,    79,     0,     9,
      94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -213,  -213,  -213,  -213,  -213,  -213,   -11,  -213,   274,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,   188,  -213,  -213,  -213,   181,   153,   130,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,   211,  -213,  -212,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,    64,
    -213,  -213,  -213,  -213,  -213,  -161,  -135,  -213,   -74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     7,     8,    39,     3,    10,    21,    22,    35,
      55,    56,    93,   106,    57,    94,   108,    13,    58,    77,
      89,   118,   120,   125,   127,   126,   180,   220,   252,   276,
     288,   274,    26,    91,    60,    79,   101,   102,   103,   121,
     145,   224,   215,   307,   262,   188,   278,   289,   249,   250,
     283,   269,   295,   265,   246,   158,   159,   160,   161
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,   189,   190,    27,    28,    29,    30,    31,    32,    33,
      81,   211,   254,    36,   171,   222,   183,   172,   185,   302,
     197,   198,   199,   200,    82,    53,     9,     1,    54,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    41,    42,   207,   197,   198,   199,   200,    80,
     280,    43,    44,     4,   225,   226,     5,   163,   164,   202,
       6,   167,   168,   173,    83,    84,   206,     9,   176,    45,
      46,   294,   197,   198,   199,   200,    11,   300,   184,   186,
      47,    48,    12,   304,   109,   110,   111,   112,   201,    49,
      50,    25,   114,   115,   116,   308,   117,    24,   197,   198,
     199,   200,    51,    52,    37,   197,   198,   199,   200,   189,
     190,   146,   147,   104,   105,    38,   284,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   152,   279,    40,
     162,   238,   177,    59,   241,   242,    61,   218,   219,   182,
     247,   305,    75,   154,    76,   155,   156,   157,    85,    86,
      87,    88,   151,   203,   204,   197,   198,   199,   200,    78,
     152,    90,   212,   153,    92,   152,    95,   216,   162,   261,
     197,   198,   199,   200,   266,   223,   154,    96,   155,   156,
     157,   154,    97,   155,   156,   157,   199,   200,    98,   281,
      14,     9,   263,   266,    15,    16,    17,    18,    19,    20,
     244,    99,   245,   100,   124,   291,   122,   107,   293,   123,
     253,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   129,   223,   148,   149,   150,   255,   256,   257,   258,
     259,   260,   165,   166,   130,   264,   277,   174,   270,   271,
     272,   131,   273,   169,   132,   133,   134,   135,   136,   137,
     138,   139,   197,   198,   199,   200,   140,   170,   175,   178,
     179,   187,   205,   208,   209,   210,   141,   213,   214,   142,
     217,   237,   243,   251,   296,   239,   240,   299,   248,   301,
     129,   303,   267,   190,   285,   275,   282,   286,   287,   143,
     290,   297,   298,   130,   306,    34,   144,   292,   310,   119,
     131,   128,   181,   132,   133,   134,   135,   136,   137,   138,
     139,   221,   113,   268,   129,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,   130,   142,     0,
       0,   309,     0,     0,   131,     0,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   129,     0,     0,   143,   140,
       0,     0,     0,     0,     0,   144,     0,     0,   130,   141,
       0,     0,   142,     0,     0,   131,     0,     0,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,     0,     0,
     140,     0,   143,     0,     0,     0,     0,     0,     0,   144,
     141,     0,     0,   142,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
     144
};

static const yytype_int16 yycheck[] =
{
      11,    60,    61,    14,    15,    16,    17,    18,    19,    20,
      75,   172,   224,    24,    40,    74,   151,    43,   153,    43,
      69,    70,    71,    72,    89,    79,    75,     4,    82,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    89,    90,    41,    69,    70,    71,    72,    60,
     262,    89,    90,     5,   189,   190,     0,   131,   132,    30,
      78,   135,   136,    89,    75,    76,    30,    75,   142,    89,
      90,   283,    69,    70,    71,    72,     5,   289,   152,   153,
      89,    90,    16,   295,    95,    96,    97,    98,   162,    89,
      90,     7,   103,   104,   105,   307,   107,     5,    69,    70,
      71,    72,    89,    90,     5,    69,    70,    71,    72,    60,
      61,   122,   123,    80,    81,    28,    59,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    70,    42,    89,
      73,   205,   143,    55,   208,   209,     8,    46,    47,   150,
     214,   302,    21,    86,    21,    88,    89,    90,    17,    18,
      19,    20,    62,   164,   165,    69,    70,    71,    72,    89,
      70,    76,   173,    73,    75,    70,    21,   178,    73,   243,
      69,    70,    71,    72,   248,    74,    86,    21,    88,    89,
      90,    86,    21,    88,    89,    90,    71,    72,    21,   263,
       6,    75,    76,   267,    10,    11,    12,    13,    14,    15,
     211,    89,   213,    89,    86,   279,    89,    83,   282,    89,
     221,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     9,    74,    89,    89,     8,   237,   238,   239,   240,
     241,   242,    89,    89,    22,   246,    24,    30,    86,    87,
      88,    29,    90,    89,    32,    33,    34,    35,    36,    37,
      38,    39,    69,    70,    71,    72,    44,    89,    89,    85,
      45,    23,    67,    42,    31,    89,    54,    89,    55,    57,
      91,    89,    41,    48,   285,    89,    89,   288,    58,   290,
       9,   292,    58,    61,    27,    51,    60,    86,    53,    77,
      25,    52,    89,    22,   305,    21,    84,    26,   309,   111,
      29,   120,   149,    32,    33,    34,    35,    36,    37,    38,
      39,   181,   101,   249,     9,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    22,    57,    -1,
      -1,    26,    -1,    -1,    29,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,     9,    -1,    -1,    77,    44,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    22,    54,
      -1,    -1,    57,    -1,    -1,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      54,    -1,    -1,    57,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      84
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    93,    97,     5,     0,    78,    94,    95,    75,
      98,     5,    16,   109,     6,    10,    11,    12,    13,    14,
      15,    99,   100,    98,     5,     7,   124,    98,    98,    98,
      98,    98,    98,    98,   100,   101,    98,     5,    28,    96,
      89,    89,    90,    89,    90,    89,    90,    89,    90,    89,
      90,    89,    90,    79,    82,   102,   103,   106,   110,    55,
     126,     8,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    21,    21,   111,    89,   127,
      98,    75,    89,    98,    98,    17,    18,    19,    20,   112,
      76,   125,    75,   104,   107,    21,    21,    21,    21,    89,
      89,   128,   129,   130,    80,    81,   105,    83,   108,    98,
      98,    98,    98,   129,    98,    98,    98,    98,   113,   113,
     114,   131,    89,    89,    86,   115,   117,   116,   117,     9,
      22,    29,    32,    33,    34,    35,    36,    37,    38,    39,
      44,    54,    57,    77,    84,   132,    98,    98,    89,    89,
       8,    62,    70,    73,    86,    88,    89,    90,   147,   148,
     149,   150,    73,   150,   150,    89,    89,   150,   150,    89,
      89,    40,    43,    89,    30,    89,   150,    98,    85,    45,
     118,   118,    98,   148,   150,   148,   150,    23,   137,    60,
      61,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   150,    30,    98,    98,    67,    30,    41,    42,    31,
      89,   147,    98,    89,    55,   134,    98,    91,    46,    47,
     119,   119,    74,    74,   133,   148,   148,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,    89,   150,    89,
      89,   150,   150,    41,    98,    98,   146,   150,    58,   140,
     141,    48,   120,    98,   131,    98,    98,    98,    98,    98,
      98,   150,   136,    76,    98,   145,   150,    58,   141,   143,
      86,    87,    88,    90,   123,    51,   121,    24,   138,    42,
     131,   150,    60,   142,    59,    27,    86,    53,   122,   139,
      25,   150,    26,   150,   131,   144,    98,    52,    89,    98,
     131,    98,    43,    98,   131,   147,    98,   135,   131,    26,
      98
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    94,    94,    95,    96,    96,    97,    98,
      98,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   101,   101,   102,   102,
     103,   104,   104,   105,   105,   106,   107,   107,   108,   110,
     109,   111,   111,   112,   112,   112,   112,   113,   113,   114,
     114,   115,   116,   117,   118,   118,   119,   119,   119,   120,
     120,   121,   121,   122,   122,   123,   123,   123,   123,   125,
     124,   126,   126,   127,   127,   128,   128,   129,   130,   131,
     131,   132,   133,   132,   134,   132,   132,   132,   132,   132,
     132,   132,   132,   135,   132,   136,   132,   132,   132,   132,
     132,   132,   132,   137,   137,   138,   139,   138,   140,   140,
     142,   141,   143,   144,   143,   145,   145,   146,   146,   147,
     148,   148,   148,   148,   148,   149,   149,   149,   149,   149,
     149,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     1,     4,     4,     3,     4,     0,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     2,     1,     1,
       4,     0,     2,     4,     4,     4,     0,     2,     2,     0,
       5,     0,     2,     3,     4,     4,     4,     0,     2,     0,
       2,     8,     5,     1,     0,     2,     0,     1,     1,     0,
       2,     0,     3,     0,     2,     1,     1,     1,     1,     0,
       6,     0,     2,     1,     3,     1,     2,     3,     1,     0,
       2,     5,     0,     8,     0,     7,     3,     3,     5,     5,
       5,     5,     5,     0,    14,     0,     8,     3,     5,     4,
       2,     3,     3,     0,     1,     0,     0,     3,     1,     2,
       0,     4,     0,     0,     4,     1,     3,     1,     3,     1,
       3,     3,     2,     1,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     3,     3,     3,     3,     2,
       3
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
  case 2: /* program: identification_division optional_environment_division data_division procedure_division end_program  */
#line 128 "parser.y"
    {
        emit("\nif __name__ == '__main__':");
        emit("    %s()", prog_name);
    }
#line 1540 "parser.tab.c"
    break;

  case 6: /* end_program: END PROGRAM IDENTIFIER DOT  */
#line 146 "parser.y"
    {
        if (main_procedure_func) {
            free(main_procedure_func);
            main_procedure_func = NULL;
        }
        emit("# END PROGRAM %s", (yyvsp[-1].str));
    }
#line 1552 "parser.tab.c"
    break;

  case 7: /* end_program: END PROGRAM DOT  */
#line 154 "parser.y"
    {
        if (main_procedure_func) {
            free(main_procedure_func);
            main_procedure_func = NULL;
        }
        emit("# END PROGRAM");
    }
#line 1564 "parser.tab.c"
    break;

  case 8: /* identification_division: IDENTIFICATION DIVISION optional_dot identification_entries  */
#line 166 "parser.y"
    {
        emit("#!/usr/bin/env python3");
        emit("# Generated by COBOL-85 to Python compiler");
        emit("import sys");
        emit("def %s():", prog_name);
        indent_level++;
    }
#line 1576 "parser.tab.c"
    break;

  case 13: /* identification_entry: PROGRAM_ID optional_dot IDENTIFIER optional_dot  */
#line 186 "parser.y"
                                                    { 
        prog_name = strdup((yyvsp[-1].str)); 
        emit("# PROGRAM-ID: %s", (yyvsp[-1].str));
    }
#line 1585 "parser.tab.c"
    break;

  case 14: /* identification_entry: AUTHOR optional_dot IDENTIFIER optional_dot  */
#line 190 "parser.y"
                                                  { 
        emit("# AUTHOR: %s", (yyvsp[-1].str)); 
    }
#line 1593 "parser.tab.c"
    break;

  case 15: /* identification_entry: AUTHOR optional_dot STRING optional_dot  */
#line 193 "parser.y"
                                              { 
        emit("# AUTHOR: %s", (yyvsp[-1].str)); 
    }
#line 1601 "parser.tab.c"
    break;

  case 16: /* identification_entry: INSTALLATION optional_dot IDENTIFIER optional_dot  */
#line 196 "parser.y"
                                                        { 
        emit("# INSTALLATION: %s", (yyvsp[-1].str)); 
    }
#line 1609 "parser.tab.c"
    break;

  case 17: /* identification_entry: INSTALLATION optional_dot STRING optional_dot  */
#line 199 "parser.y"
                                                    { 
        emit("# INSTALLATION: %s", (yyvsp[-1].str)); 
    }
#line 1617 "parser.tab.c"
    break;

  case 18: /* identification_entry: DATE_WRITTEN optional_dot IDENTIFIER optional_dot  */
#line 202 "parser.y"
                                                        { 
        emit("# DATE-WRITTEN: %s", (yyvsp[-1].str)); 
    }
#line 1625 "parser.tab.c"
    break;

  case 19: /* identification_entry: DATE_WRITTEN optional_dot STRING optional_dot  */
#line 205 "parser.y"
                                                    { 
        emit("# DATE-WRITTEN: %s", (yyvsp[-1].str)); 
    }
#line 1633 "parser.tab.c"
    break;

  case 20: /* identification_entry: DATE_COMPILED optional_dot IDENTIFIER optional_dot  */
#line 208 "parser.y"
                                                         { 
        emit("# DATE-COMPILED: %s", (yyvsp[-1].str)); 
    }
#line 1641 "parser.tab.c"
    break;

  case 21: /* identification_entry: DATE_COMPILED optional_dot STRING optional_dot  */
#line 211 "parser.y"
                                                     { 
        emit("# DATE-COMPILED: %s", (yyvsp[-1].str)); 
    }
#line 1649 "parser.tab.c"
    break;

  case 22: /* identification_entry: SECURITY optional_dot IDENTIFIER optional_dot  */
#line 214 "parser.y"
                                                    { 
        emit("# SECURITY: %s", (yyvsp[-1].str)); 
    }
#line 1657 "parser.tab.c"
    break;

  case 23: /* identification_entry: SECURITY optional_dot STRING optional_dot  */
#line 217 "parser.y"
                                                { 
        emit("# SECURITY: %s", (yyvsp[-1].str)); 
    }
#line 1665 "parser.tab.c"
    break;

  case 24: /* identification_entry: REMARKS optional_dot IDENTIFIER optional_dot  */
#line 220 "parser.y"
                                                   { 
        emit("# REMARKS: %s", (yyvsp[-1].str)); 
    }
#line 1673 "parser.tab.c"
    break;

  case 25: /* identification_entry: REMARKS optional_dot STRING optional_dot  */
#line 223 "parser.y"
                                               { 
        emit("# REMARKS: %s", (yyvsp[-1].str)); 
    }
#line 1681 "parser.tab.c"
    break;

  case 33: /* configuration_paragraph: SOURCE_COMPUTER optional_dot IDENTIFIER optional_dot  */
#line 249 "parser.y"
                                                         { 
        emit("# SOURCE-COMPUTER: %s", (yyvsp[-1].str)); 
    }
#line 1689 "parser.tab.c"
    break;

  case 34: /* configuration_paragraph: OBJECT_COMPUTER optional_dot IDENTIFIER optional_dot  */
#line 252 "parser.y"
                                                           { 
        emit("# OBJECT-COMPUTER: %s", (yyvsp[-1].str)); 
    }
#line 1697 "parser.tab.c"
    break;

  case 38: /* input_output_paragraph: FILE_CONTROL optional_dot  */
#line 268 "parser.y"
                              { emit("# FILE-CONTROL"); }
#line 1703 "parser.tab.c"
    break;

  case 39: /* $@1: %empty  */
#line 273 "parser.y"
    { in_data_division = 1; }
#line 1709 "parser.tab.c"
    break;

  case 40: /* data_division: DATA DIVISION optional_dot $@1 data_sections  */
#line 275 "parser.y"
    { in_data_division = 0; }
#line 1715 "parser.tab.c"
    break;

  case 51: /* data_item: level_number IDENTIFIER pic_clause comp_clause value_clause occurs_clause redefines_clause optional_dot  */
#line 308 "parser.y"
    {
        if ((yyvsp[-3].str)) emit("%s = %s", (yyvsp[-6].str), (yyvsp[-3].str));
        else if ((yyvsp[-2].str)) emit("%s = [None] * %s", (yyvsp[-6].str), (yyvsp[-2].str));
        else emit("%s = None", (yyvsp[-6].str));
    }
#line 1725 "parser.tab.c"
    break;

  case 52: /* param_item: level_number IDENTIFIER pic_clause comp_clause optional_dot  */
#line 320 "parser.y"
    {
        emit("# Parameter: %s", (yyvsp[-3].str));
    }
#line 1733 "parser.tab.c"
    break;

  case 54: /* pic_clause: %empty  */
#line 330 "parser.y"
                { (yyval.str) = NULL; }
#line 1739 "parser.tab.c"
    break;

  case 55: /* pic_clause: PIC PIC_STRING  */
#line 331 "parser.y"
                     { (yyval.str) = (yyvsp[0].str); }
#line 1745 "parser.tab.c"
    break;

  case 56: /* comp_clause: %empty  */
#line 335 "parser.y"
                { (yyval.str) = NULL; }
#line 1751 "parser.tab.c"
    break;

  case 57: /* comp_clause: COMP  */
#line 336 "parser.y"
           { (yyval.str) = NULL; }
#line 1757 "parser.tab.c"
    break;

  case 58: /* comp_clause: COMP_3  */
#line 337 "parser.y"
             { (yyval.str) = NULL; }
#line 1763 "parser.tab.c"
    break;

  case 59: /* value_clause: %empty  */
#line 341 "parser.y"
                { (yyval.str) = NULL; }
#line 1769 "parser.tab.c"
    break;

  case 60: /* value_clause: VALUE literal  */
#line 342 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1775 "parser.tab.c"
    break;

  case 61: /* occurs_clause: %empty  */
#line 346 "parser.y"
                { (yyval.str) = NULL; }
#line 1781 "parser.tab.c"
    break;

  case 62: /* occurs_clause: OCCURS NUMBER OCCURS_TIMES  */
#line 347 "parser.y"
                                 { 
        char* occurs = malloc(20);
        sprintf(occurs, "%d", (yyvsp[-1].num));
        (yyval.str) = occurs;
    }
#line 1791 "parser.tab.c"
    break;

  case 63: /* redefines_clause: %empty  */
#line 355 "parser.y"
                { (yyval.str) = NULL; }
#line 1797 "parser.tab.c"
    break;

  case 64: /* redefines_clause: REDEFINES IDENTIFIER  */
#line 356 "parser.y"
                           { (yyval.str) = (yyvsp[0].str); }
#line 1803 "parser.tab.c"
    break;

  case 65: /* literal: NUMBER  */
#line 360 "parser.y"
           { 
        char* buf;
        asprintf(&buf, "%d", (yyvsp[0].num));
        (yyval.str) = buf;
    }
#line 1813 "parser.tab.c"
    break;

  case 66: /* literal: FLOAT  */
#line 365 "parser.y"
          { 
        char* buf;
        asprintf(&buf, "%f", (yyvsp[0].dval));
        (yyval.str) = buf;
    }
#line 1823 "parser.tab.c"
    break;

  case 67: /* literal: STRING  */
#line 370 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 1829 "parser.tab.c"
    break;

  case 68: /* literal: BOOL  */
#line 371 "parser.y"
         { 
        (yyval.str) = (yyvsp[0].num) ? strdup("True") : strdup("False"); 
    }
#line 1837 "parser.tab.c"
    break;

  case 69: /* $@2: %empty  */
#line 378 "parser.y"
    {
        if ((yyvsp[-1].str)) {
            current_paragraph_params = strdup((yyvsp[-1].str));
        }
    }
#line 1847 "parser.tab.c"
    break;

  case 70: /* procedure_division: PROCEDURE DIVISION optional_using optional_dot $@2 paragraphs  */
#line 384 "parser.y"
    {
        // Llamar a la función principal después de definir todas las funciones
        if (main_procedure_func) {
            emit("%s()  # Llamada a la función principal", main_procedure_func);
        }
        indent_level--;
        emit("");
    }
#line 1860 "parser.tab.c"
    break;

  case 71: /* optional_using: %empty  */
#line 395 "parser.y"
                { (yyval.str) = NULL; }
#line 1866 "parser.tab.c"
    break;

  case 72: /* optional_using: USING param_list  */
#line 396 "parser.y"
                       { (yyval.str) = (yyvsp[0].str); }
#line 1872 "parser.tab.c"
    break;

  case 73: /* param_list: IDENTIFIER  */
#line 400 "parser.y"
               { 
        (yyval.str) = format_identifier((yyvsp[0].str));
    }
#line 1880 "parser.tab.c"
    break;

  case 74: /* param_list: param_list COMMA_TOKEN IDENTIFIER  */
#line 403 "parser.y"
                                        { 
        char* new_param;
        asprintf(&new_param, "%s, %s", (yyvsp[-2].str), format_identifier((yyvsp[0].str)));
        (yyval.str) = new_param;
    }
#line 1890 "parser.tab.c"
    break;

  case 77: /* paragraph: paragraph_header optional_dot statements  */
#line 418 "parser.y"
    {
        indent_level--;
        emit("");
        if (current_paragraph_params) {
            free(current_paragraph_params);
            current_paragraph_params = NULL;
        }
    }
#line 1903 "parser.tab.c"
    break;

  case 78: /* paragraph_header: IDENTIFIER  */
#line 430 "parser.y"
    {
        current_paragraph = strdup((yyvsp[0].str));
        char* func_name = make_valid_function_name((yyvsp[0].str));
        emit("");
        
        // Guardar la primera función como principal
        if (main_procedure_func == NULL) {
            main_procedure_func = strdup(func_name);
        }
        
        if (strcmp((yyvsp[0].str), prog_name) == 0) {
            if (current_paragraph_params) {
                emit("def %s(%s):", func_name, current_paragraph_params);
            } else {
                emit("def %s():", func_name);
            }
        } else {
            emit("def %s():", func_name);
            // Agregar declaración nonlocal para todas las variables
            emit("    nonlocal n_input, n, total, x, y, z, exp_x, exp_y, exp_z, suma, ws_base, ws_exp, ws_result, ws_j");
        }
        free(func_name);
        indent_level++;
    }
#line 1932 "parser.tab.c"
    break;

  case 81: /* statement: MOVE expr TO IDENTIFIER optional_dot  */
#line 463 "parser.y"
    { emit("%s = %s", (yyvsp[-1].str), (yyvsp[-3].str)); }
#line 1938 "parser.tab.c"
    break;

  case 82: /* $@3: %empty  */
#line 465 "parser.y"
    {
        emit("if %s:", (yyvsp[-1].str));
        indent_level++;
    }
#line 1947 "parser.tab.c"
    break;

  case 83: /* statement: IF condition optional_then $@3 statements opt_else END_IF optional_dot  */
#line 472 "parser.y"
    { indent_level--; }
#line 1953 "parser.tab.c"
    break;

  case 84: /* $@4: %empty  */
#line 474 "parser.y"
    {
        emit("match %s:", (yyvsp[0].str));
        indent_level++;
    }
#line 1962 "parser.tab.c"
    break;

  case 85: /* statement: EVALUATE expr $@4 evaluate_cases opt_other END_EVALUATE optional_dot  */
#line 481 "parser.y"
    { indent_level--; }
#line 1968 "parser.tab.c"
    break;

  case 86: /* statement: DISPLAY expr optional_dot  */
#line 483 "parser.y"
    { emit("print(%s)", (yyvsp[-1].str)); }
#line 1974 "parser.tab.c"
    break;

  case 87: /* statement: ACCEPT IDENTIFIER optional_dot  */
#line 485 "parser.y"
    { emit("%s = int(input())", (yyvsp[-1].str)); }
#line 1980 "parser.tab.c"
    break;

  case 88: /* statement: COMPUTE IDENTIFIER EQUAL expr optional_dot  */
#line 487 "parser.y"
    { emit("%s = %s", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1986 "parser.tab.c"
    break;

  case 89: /* statement: ADD expr TO IDENTIFIER optional_dot  */
#line 489 "parser.y"
    { emit("%s += %s", (yyvsp[-1].str), (yyvsp[-3].str)); }
#line 1992 "parser.tab.c"
    break;

  case 90: /* statement: SUBTRACT expr FROM IDENTIFIER optional_dot  */
#line 491 "parser.y"
    { emit("%s -= %s", (yyvsp[-1].str), (yyvsp[-3].str)); }
#line 1998 "parser.tab.c"
    break;

  case 91: /* statement: MULTIPLY IDENTIFIER BY expr optional_dot  */
#line 493 "parser.y"
    { emit("%s *= %s", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2004 "parser.tab.c"
    break;

  case 92: /* statement: DIVIDE IDENTIFIER INTO_TOKEN expr optional_dot  */
#line 495 "parser.y"
    { emit("%s = %s / %s", (yyvsp[-1].str), (yyvsp[-1].str), (yyvsp[-3].str)); }
#line 2010 "parser.tab.c"
    break;

  case 93: /* $@5: %empty  */
#line 497 "parser.y"
    {
        emit("%s = %s", (yyvsp[-7].str), (yyvsp[-5].str));
        emit("while not (%s):", (yyvsp[-1].str));  // Condición corregida
        indent_level++;
    }
#line 2020 "parser.tab.c"
    break;

  case 94: /* statement: PERFORM VARYING IDENTIFIER FROM expr BY expr UNTIL condition optional_dot $@5 statements END_PERFORM optional_dot  */
#line 504 "parser.y"
    {
        emit("%s += %s", (yyvsp[-11].str), (yyvsp[-7].str));
        indent_level--;
    }
#line 2029 "parser.tab.c"
    break;

  case 95: /* $@6: %empty  */
#line 509 "parser.y"
    {
        emit("while not (%s):", (yyvsp[-1].str));  // Condición corregida
        indent_level++;
    }
#line 2038 "parser.tab.c"
    break;

  case 96: /* statement: PERFORM UNTIL condition optional_dot $@6 statements END_PERFORM optional_dot  */
#line 515 "parser.y"
    {
        indent_level--;
    }
#line 2046 "parser.tab.c"
    break;

  case 97: /* statement: PERFORM IDENTIFIER optional_dot  */
#line 519 "parser.y"
    { 
        char* func_name = get_valid_function_name((yyvsp[-1].str));
        emit("%s()", func_name);
        free(func_name);
    }
#line 2056 "parser.tab.c"
    break;

  case 98: /* statement: CALL IDENTIFIER USING call_params optional_dot  */
#line 525 "parser.y"
    { 
        char* func_name = get_valid_function_name((yyvsp[-3].str));
        emit("%s(%s)", func_name, (yyvsp[-1].str));
        free(func_name);
    }
#line 2066 "parser.tab.c"
    break;

  case 99: /* statement: GO TO IDENTIFIER optional_dot  */
#line 531 "parser.y"
    {
        char* func_name = get_valid_function_name((yyvsp[-1].str));
        emit("%s()", func_name);
        emit("return");
        free(func_name);
    }
#line 2077 "parser.tab.c"
    break;

  case 100: /* statement: GOBACK optional_dot  */
#line 538 "parser.y"
    {
        emit("return");
    }
#line 2085 "parser.tab.c"
    break;

  case 101: /* statement: EXIT PROGRAM optional_dot  */
#line 542 "parser.y"
    {
        emit("sys.exit(0)");
    }
#line 2093 "parser.tab.c"
    break;

  case 102: /* statement: STOP RUN optional_dot  */
#line 546 "parser.y"
    {
        emit("sys.exit(0)");
    }
#line 2101 "parser.tab.c"
    break;

  case 106: /* $@7: %empty  */
#line 559 "parser.y"
      {
          indent_level--;
          emit("else:");
          indent_level++;
      }
#line 2111 "parser.tab.c"
    break;

  case 110: /* $@8: %empty  */
#line 574 "parser.y"
    {
        emit("case %s:", (yyvsp[0].str));
        indent_level++;
    }
#line 2120 "parser.tab.c"
    break;

  case 111: /* evaluate_case: WHEN literal_list $@8 statements  */
#line 579 "parser.y"
    { indent_level--; }
#line 2126 "parser.tab.c"
    break;

  case 113: /* $@9: %empty  */
#line 585 "parser.y"
    {
        emit("case _:");
        indent_level++;
    }
#line 2135 "parser.tab.c"
    break;

  case 114: /* opt_other: WHEN OTHER $@9 statements  */
#line 590 "parser.y"
    { indent_level--; }
#line 2141 "parser.tab.c"
    break;

  case 120: /* logical_expr: logical_expr OR logical_expr  */
#line 606 "parser.y"
                                   { (yyval.str) = build_expr("or", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2147 "parser.tab.c"
    break;

  case 121: /* logical_expr: logical_expr AND logical_expr  */
#line 607 "parser.y"
                                   { (yyval.str) = build_expr("and", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2153 "parser.tab.c"
    break;

  case 122: /* logical_expr: NOT logical_expr  */
#line 608 "parser.y"
                                   { (yyval.str) = build_unary_expr("not ", (yyvsp[0].str)); }
#line 2159 "parser.tab.c"
    break;

  case 123: /* logical_expr: comparison  */
#line 609 "parser.y"
                                   { (yyval.str) = (yyvsp[0].str); }
#line 2165 "parser.tab.c"
    break;

  case 124: /* logical_expr: LPAREN logical_expr RPAREN  */
#line 610 "parser.y"
                                   { (yyval.str) = (yyvsp[-1].str); }
#line 2171 "parser.tab.c"
    break;

  case 125: /* comparison: expr GREATER expr  */
#line 614 "parser.y"
                       { (yyval.str) = build_expr(">", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2177 "parser.tab.c"
    break;

  case 126: /* comparison: expr LESS expr  */
#line 615 "parser.y"
                       { (yyval.str) = build_expr("<", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2183 "parser.tab.c"
    break;

  case 127: /* comparison: expr GEQUAL expr  */
#line 616 "parser.y"
                       { (yyval.str) = build_expr(">=", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2189 "parser.tab.c"
    break;

  case 128: /* comparison: expr LEQUAL expr  */
#line 617 "parser.y"
                       { (yyval.str) = build_expr("<=", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2195 "parser.tab.c"
    break;

  case 129: /* comparison: expr EQUAL expr  */
#line 618 "parser.y"
                       { (yyval.str) = build_expr("==", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2201 "parser.tab.c"
    break;

  case 130: /* comparison: expr NEQUAL expr  */
#line 619 "parser.y"
                       { (yyval.str) = build_expr("!=", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2207 "parser.tab.c"
    break;

  case 131: /* expr: NUMBER  */
#line 623 "parser.y"
           { 
        char* buf;
        asprintf(&buf, "%d", (yyvsp[0].num));
        (yyval.str) = buf;
    }
#line 2217 "parser.tab.c"
    break;

  case 132: /* expr: FLOAT  */
#line 628 "parser.y"
          { 
        char* buf;
        asprintf(&buf, "%f", (yyvsp[0].dval));
        (yyval.str) = buf;
    }
#line 2227 "parser.tab.c"
    break;

  case 133: /* expr: IDENTIFIER  */
#line 633 "parser.y"
               { (yyval.str) = format_identifier((yyvsp[0].str)); }
#line 2233 "parser.tab.c"
    break;

  case 134: /* expr: STRING  */
#line 634 "parser.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 2239 "parser.tab.c"
    break;

  case 135: /* expr: expr PLUS expr  */
#line 635 "parser.y"
                    { (yyval.str) = build_expr("+", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2245 "parser.tab.c"
    break;

  case 136: /* expr: expr MINUS expr  */
#line 636 "parser.y"
                    { (yyval.str) = build_expr("-", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2251 "parser.tab.c"
    break;

  case 137: /* expr: expr MUL_OP expr  */
#line 637 "parser.y"
                     { (yyval.str) = build_expr("*", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2257 "parser.tab.c"
    break;

  case 138: /* expr: expr DIV_OP expr  */
#line 638 "parser.y"
                     { (yyval.str) = build_expr("/", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2263 "parser.tab.c"
    break;

  case 139: /* expr: MINUS expr  */
#line 639 "parser.y"
                                { (yyval.str) = build_unary_expr("-", (yyvsp[0].str)); }
#line 2269 "parser.tab.c"
    break;

  case 140: /* expr: LPAREN expr RPAREN  */
#line 640 "parser.y"
                       { (yyval.str) = (yyvsp[-1].str); }
#line 2275 "parser.tab.c"
    break;


#line 2279 "parser.tab.c"

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

#line 643 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s. Token: '%s' (Length: %d)\n", 
            yylineno, s, yytext, (int)strlen(yytext));
    for (int i = 0; yytext[i]; i++) {
        fprintf(stderr, "Char %d: %d\n", i, (unsigned char)yytext[i]);
    }
    exit(1);
}

int main() {
    yyparse();
    return 0;
}
