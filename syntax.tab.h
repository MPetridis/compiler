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

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    T_EOF = 0,                     /* "eof"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_TYPEDEF = 258,               /* "typedef"  */
    T_CHAR = 259,                  /* "char"  */
    T_INT = 260,                   /* "int"  */
    T_FLOAT = 261,                 /* "float"  */
    T_ENUM = 262,                  /* "enum"  */
    T_CLASS = 263,                 /* "class"  */
    T_PRIVATE = 264,               /* "private"  */
    T_PROTECTED = 265,             /* "protected"  */
    T_PUBLIC = 266,                /* "public"  */
    T_VOID = 267,                  /* "void"  */
    T_STATIC = 268,                /* "static"  */
    T_CONTINUE = 269,              /* "continue"  */
    T_BREAK = 270,                 /* "break"  */
    T_THIS = 271,                  /* "this"  */
    T_IF = 272,                    /* "if"  */
    T_ELSE = 273,                  /* "else"  */
    T_WHILE = 274,                 /* "while"  */
    T_FOR = 275,                   /* "for"  */
    T_SWITCH = 276,                /* "switch"  */
    T_CASE = 277,                  /* "case"  */
    T_DEFAULT = 278,               /* "default"  */
    T_RETURN = 279,                /* "return"  */
    T_CIN = 280,                   /* "cin"  */
    T_COUT = 281,                  /* "cout"  */
    T_LENGTH = 282,                /* "length"  */
    T_MAIN = 283,                  /* "main"  */
    T_ID = 284,                    /* "id"  */
    T_ICONST = 285,                /* "int const"  */
    T_FCONST = 286,                /* "double const"  */
    T_CCONST = 287,                /* "char const"  */
    T_OROP = 288,                  /* "||"  */
    T_ANDOP = 289,                 /* "&&"  */
    T_EQUOP = 290,                 /* "== !="  */
    T_RELOP = 291,                 /* "< >= < <="  */
    T_ADDOP = 292,                 /* "+ -"  */
    T_MULOP = 293,                 /* "* / %"  */
    T_NOTOP = 294,                 /* "!"  */
    T_INCDEC = 295,                /* "++ --"  */
    T_SIZEOP = 296,                /* "SIZEOF"  */
    T_STRING = 297,                /* "string"  */
    T_LPAREN = 298,                /* "("  */
    T_RPAREN = 299,                /* ")"  */
    T_SEMI = 300,                  /* ";"  */
    T_DOT = 301,                   /* "."  */
    T_COMMA = 302,                 /* ","  */
    T_ASSIGN = 303,                /* "="  */
    T_COLON = 304,                 /* ":"  */
    T_LBRACK = 305,                /* "["  */
    T_RBRACK = 306,                /* "]"  */
    T_REFER = 307,                 /* "&"  */
    T_LBRACE = 308,                /* "{"  */
    T_RBRACE = 309,                /* "}"  */
    T_METH = 310,                  /* "::"  */
    T_INP = 311,                   /* ">>"  */
    T_OUT = 312,                   /* "<<"  */
    LOWER_THAN_ELSE = 313          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "syntax.y"

  int intval;
  double doubleval;
  char charval;
  char* strval;

#line 129 "syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
