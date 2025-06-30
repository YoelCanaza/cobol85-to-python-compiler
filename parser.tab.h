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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    UMINUS = 258,                  /* UMINUS  */
    IDENTIFICATION = 259,          /* IDENTIFICATION  */
    DIVISION = 260,                /* DIVISION  */
    PROGRAM_ID = 261,              /* PROGRAM_ID  */
    PROCEDURE = 262,               /* PROCEDURE  */
    PROGRAM = 263,                 /* PROGRAM  */
    EXIT = 264,                    /* EXIT  */
    AUTHOR = 265,                  /* AUTHOR  */
    INSTALLATION = 266,            /* INSTALLATION  */
    DATE_WRITTEN = 267,            /* DATE_WRITTEN  */
    DATE_COMPILED = 268,           /* DATE_COMPILED  */
    SECURITY = 269,                /* SECURITY  */
    REMARKS = 270,                 /* REMARKS  */
    DATA = 271,                    /* DATA  */
    FILE_TOKEN = 272,              /* FILE_TOKEN  */
    WORKING_STORAGE = 273,         /* WORKING_STORAGE  */
    LOCAL_STORAGE = 274,           /* LOCAL_STORAGE  */
    LINKAGE = 275,                 /* LINKAGE  */
    SECTION = 276,                 /* SECTION  */
    IF = 277,                      /* IF  */
    THEN = 278,                    /* THEN  */
    ELSE = 279,                    /* ELSE  */
    END_IF = 280,                  /* END_IF  */
    END_PERFORM = 281,             /* END_PERFORM  */
    END_EVALUATE = 282,            /* END_EVALUATE  */
    END = 283,                     /* END  */
    MOVE = 284,                    /* MOVE  */
    TO = 285,                      /* TO  */
    INTO_TOKEN = 286,              /* INTO_TOKEN  */
    DISPLAY = 287,                 /* DISPLAY  */
    ACCEPT = 288,                  /* ACCEPT  */
    COMPUTE = 289,                 /* COMPUTE  */
    ADD = 290,                     /* ADD  */
    SUBTRACT = 291,                /* SUBTRACT  */
    MULTIPLY = 292,                /* MULTIPLY  */
    DIVIDE = 293,                  /* DIVIDE  */
    PERFORM = 294,                 /* PERFORM  */
    VARYING = 295,                 /* VARYING  */
    FROM = 296,                    /* FROM  */
    BY = 297,                      /* BY  */
    UNTIL = 298,                   /* UNTIL  */
    GO = 299,                      /* GO  */
    PIC = 300,                     /* PIC  */
    COMP = 301,                    /* COMP  */
    COMP_3 = 302,                  /* COMP_3  */
    VALUE = 303,                   /* VALUE  */
    VALUES = 304,                  /* VALUES  */
    INDEXED = 305,                 /* INDEXED  */
    OCCURS = 306,                  /* OCCURS  */
    OCCURS_TIMES = 307,            /* OCCURS_TIMES  */
    REDEFINES = 308,               /* REDEFINES  */
    CALL = 309,                    /* CALL  */
    USING = 310,                   /* USING  */
    RETURNING = 311,               /* RETURNING  */
    EVALUATE = 312,                /* EVALUATE  */
    WHEN = 313,                    /* WHEN  */
    OTHER = 314,                   /* OTHER  */
    OR = 315,                      /* OR  */
    AND = 316,                     /* AND  */
    NOT = 317,                     /* NOT  */
    GREATER = 318,                 /* GREATER  */
    LESS = 319,                    /* LESS  */
    GEQUAL = 320,                  /* GEQUAL  */
    LEQUAL = 321,                  /* LEQUAL  */
    EQUAL = 322,                   /* EQUAL  */
    NEQUAL = 323,                  /* NEQUAL  */
    PLUS = 324,                    /* PLUS  */
    MINUS = 325,                   /* MINUS  */
    MUL_OP = 326,                  /* MUL_OP  */
    DIV_OP = 327,                  /* DIV_OP  */
    LPAREN = 328,                  /* LPAREN  */
    RPAREN = 329,                  /* RPAREN  */
    DOT = 330,                     /* DOT  */
    COMMA_TOKEN = 331,             /* COMMA_TOKEN  */
    GOBACK = 332,                  /* GOBACK  */
    ENVIRONMENT = 333,             /* ENVIRONMENT  */
    CONFIGURATION = 334,           /* CONFIGURATION  */
    SOURCE_COMPUTER = 335,         /* SOURCE_COMPUTER  */
    OBJECT_COMPUTER = 336,         /* OBJECT_COMPUTER  */
    INPUT_OUTPUT = 337,            /* INPUT_OUTPUT  */
    FILE_CONTROL = 338,            /* FILE_CONTROL  */
    STOP = 339,                    /* STOP  */
    RUN = 340,                     /* RUN  */
    NUMBER = 341,                  /* NUMBER  */
    BOOL = 342,                    /* BOOL  */
    FLOAT = 343,                   /* FLOAT  */
    IDENTIFIER = 344,              /* IDENTIFIER  */
    STRING = 345,                  /* STRING  */
    PIC_STRING = 346               /* PIC_STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 78 "parser.y"

    int    num;
    double dval;
    char*  str;

#line 161 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
