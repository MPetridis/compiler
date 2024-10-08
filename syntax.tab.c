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
#line 1 "syntax.y"

  #include "hashtbl.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <string.h>
  #include <math.h>

  extern FILE *yyin;
  extern int yylex();
  extern void yyerror(const char *err);
  void check(void);
  HASHTBL *hashtbl;
  int scope = 0;

#line 87 "syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "eof"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_TYPEDEF = 3,                  /* "typedef"  */
  YYSYMBOL_T_CHAR = 4,                     /* "char"  */
  YYSYMBOL_T_INT = 5,                      /* "int"  */
  YYSYMBOL_T_FLOAT = 6,                    /* "float"  */
  YYSYMBOL_T_ENUM = 7,                     /* "enum"  */
  YYSYMBOL_T_CLASS = 8,                    /* "class"  */
  YYSYMBOL_T_PRIVATE = 9,                  /* "private"  */
  YYSYMBOL_T_PROTECTED = 10,               /* "protected"  */
  YYSYMBOL_T_PUBLIC = 11,                  /* "public"  */
  YYSYMBOL_T_VOID = 12,                    /* "void"  */
  YYSYMBOL_T_STATIC = 13,                  /* "static"  */
  YYSYMBOL_T_CONTINUE = 14,                /* "continue"  */
  YYSYMBOL_T_BREAK = 15,                   /* "break"  */
  YYSYMBOL_T_THIS = 16,                    /* "this"  */
  YYSYMBOL_T_IF = 17,                      /* "if"  */
  YYSYMBOL_T_ELSE = 18,                    /* "else"  */
  YYSYMBOL_T_WHILE = 19,                   /* "while"  */
  YYSYMBOL_T_FOR = 20,                     /* "for"  */
  YYSYMBOL_T_SWITCH = 21,                  /* "switch"  */
  YYSYMBOL_T_CASE = 22,                    /* "case"  */
  YYSYMBOL_T_DEFAULT = 23,                 /* "default"  */
  YYSYMBOL_T_RETURN = 24,                  /* "return"  */
  YYSYMBOL_T_CIN = 25,                     /* "cin"  */
  YYSYMBOL_T_COUT = 26,                    /* "cout"  */
  YYSYMBOL_T_LENGTH = 27,                  /* "length"  */
  YYSYMBOL_T_MAIN = 28,                    /* "main"  */
  YYSYMBOL_T_ID = 29,                      /* "id"  */
  YYSYMBOL_T_ICONST = 30,                  /* "int const"  */
  YYSYMBOL_T_FCONST = 31,                  /* "double const"  */
  YYSYMBOL_T_CCONST = 32,                  /* "char const"  */
  YYSYMBOL_T_OROP = 33,                    /* "||"  */
  YYSYMBOL_T_ANDOP = 34,                   /* "&&"  */
  YYSYMBOL_T_EQUOP = 35,                   /* "== !="  */
  YYSYMBOL_T_RELOP = 36,                   /* "< >= < <="  */
  YYSYMBOL_T_ADDOP = 37,                   /* "+ -"  */
  YYSYMBOL_T_MULOP = 38,                   /* "* / %"  */
  YYSYMBOL_T_NOTOP = 39,                   /* "!"  */
  YYSYMBOL_T_INCDEC = 40,                  /* "++ --"  */
  YYSYMBOL_T_SIZEOP = 41,                  /* "SIZEOF"  */
  YYSYMBOL_T_STRING = 42,                  /* "string"  */
  YYSYMBOL_T_LPAREN = 43,                  /* "("  */
  YYSYMBOL_T_RPAREN = 44,                  /* ")"  */
  YYSYMBOL_T_SEMI = 45,                    /* ";"  */
  YYSYMBOL_T_DOT = 46,                     /* "."  */
  YYSYMBOL_T_COMMA = 47,                   /* ","  */
  YYSYMBOL_T_ASSIGN = 48,                  /* "="  */
  YYSYMBOL_T_COLON = 49,                   /* ":"  */
  YYSYMBOL_T_LBRACK = 50,                  /* "["  */
  YYSYMBOL_T_RBRACK = 51,                  /* "]"  */
  YYSYMBOL_T_REFER = 52,                   /* "&"  */
  YYSYMBOL_T_LBRACE = 53,                  /* "{"  */
  YYSYMBOL_T_RBRACE = 54,                  /* "}"  */
  YYSYMBOL_T_METH = 55,                    /* "::"  */
  YYSYMBOL_T_INP = 56,                     /* ">>"  */
  YYSYMBOL_T_OUT = 57,                     /* "<<"  */
  YYSYMBOL_LOWER_THAN_ELSE = 58,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_global_declarations = 61,       /* global_declarations  */
  YYSYMBOL_global_declaration = 62,        /* global_declaration  */
  YYSYMBOL_typedef_declaration = 63,       /* typedef_declaration  */
  YYSYMBOL_typename = 64,                  /* typename  */
  YYSYMBOL_standard_type = 65,             /* standard_type  */
  YYSYMBOL_dims = 66,                      /* dims  */
  YYSYMBOL_dim = 67,                       /* dim  */
  YYSYMBOL_class_declaration = 68,         /* class_declaration  */
  YYSYMBOL_class_body = 69,                /* class_body  */
  YYSYMBOL_parent = 70,                    /* parent  */
  YYSYMBOL_members_methods = 71,           /* members_methods  */
  YYSYMBOL_access = 72,                    /* access  */
  YYSYMBOL_member_or_method = 73,          /* member_or_method  */
  YYSYMBOL_member = 74,                    /* member  */
  YYSYMBOL_var_declaration = 75,           /* var_declaration  */
  YYSYMBOL_variabledefs = 76,              /* variabledefs  */
  YYSYMBOL_variabledef = 77,               /* variabledef  */
  YYSYMBOL_method = 78,                    /* method  */
  YYSYMBOL_short_func_declaration = 79,    /* short_func_declaration  */
  YYSYMBOL_short_par_func_header = 80,     /* short_par_func_header  */
  YYSYMBOL_func_header_start = 81,         /* func_header_start  */
  YYSYMBOL_parameter_type_list = 82,       /* parameter_type_list  */
  YYSYMBOL_pass_dims = 83,                 /* pass_dims  */
  YYSYMBOL_nopar_func_header = 84,         /* nopar_func_header  */
  YYSYMBOL_enum_declaration = 85,          /* enum_declaration  */
  YYSYMBOL_enum_body = 86,                 /* enum_body  */
  YYSYMBOL_id_list = 87,                   /* id_list  */
  YYSYMBOL_global_var_declaration = 88,    /* global_var_declaration  */
  YYSYMBOL_init_variabledefs = 89,         /* init_variabledefs  */
  YYSYMBOL_init_variabledef = 90,          /* init_variabledef  */
  YYSYMBOL_initializer = 91,               /* initializer  */
  YYSYMBOL_init_value = 92,                /* init_value  */
  YYSYMBOL_sign = 93,                      /* sign  */
  YYSYMBOL_constant = 94,                  /* constant  */
  YYSYMBOL_init_values = 95,               /* init_values  */
  YYSYMBOL_func_declaration = 96,          /* func_declaration  */
  YYSYMBOL_full_func_declaration = 97,     /* full_func_declaration  */
  YYSYMBOL_98_1 = 98,                      /* $@1  */
  YYSYMBOL_99_2 = 99,                      /* $@2  */
  YYSYMBOL_100_3 = 100,                    /* $@3  */
  YYSYMBOL_full_par_func_header = 101,     /* full_par_func_header  */
  YYSYMBOL_class_func_header_start = 102,  /* class_func_header_start  */
  YYSYMBOL_func_class = 103,               /* func_class  */
  YYSYMBOL_parameter_list = 104,           /* parameter_list  */
  YYSYMBOL_pass_variabledef = 105,         /* pass_variabledef  */
  YYSYMBOL_nopar_class_func_header = 106,  /* nopar_class_func_header  */
  YYSYMBOL_decl_statements = 107,          /* decl_statements  */
  YYSYMBOL_declarations = 108,             /* declarations  */
  YYSYMBOL_decltype = 109,                 /* decltype  */
  YYSYMBOL_statements = 110,               /* statements  */
  YYSYMBOL_statement = 111,                /* statement  */
  YYSYMBOL_expression_statement = 112,     /* expression_statement  */
  YYSYMBOL_general_expression = 113,       /* general_expression  */
  YYSYMBOL_assignment = 114,               /* assignment  */
  YYSYMBOL_variable = 115,                 /* variable  */
  YYSYMBOL_expression = 116,               /* expression  */
  YYSYMBOL_expression_list = 117,          /* expression_list  */
  YYSYMBOL_if_statement = 118,             /* if_statement  */
  YYSYMBOL_119_4 = 119,                    /* $@4  */
  YYSYMBOL_if_tail = 120,                  /* if_tail  */
  YYSYMBOL_while_statement = 121,          /* while_statement  */
  YYSYMBOL_122_5 = 122,                    /* $@5  */
  YYSYMBOL_for_statement = 123,            /* for_statement  */
  YYSYMBOL_optexpr = 124,                  /* optexpr  */
  YYSYMBOL_switch_statement = 125,         /* switch_statement  */
  YYSYMBOL_switch_tail = 126,              /* switch_tail  */
  YYSYMBOL_127_6 = 127,                    /* $@6  */
  YYSYMBOL_decl_cases = 128,               /* decl_cases  */
  YYSYMBOL_casestatements = 129,           /* casestatements  */
  YYSYMBOL_casestatement = 130,            /* casestatement  */
  YYSYMBOL_single_casestatement = 131,     /* single_casestatement  */
  YYSYMBOL_return_statement = 132,         /* return_statement  */
  YYSYMBOL_io_statement = 133,             /* io_statement  */
  YYSYMBOL_in_list = 134,                  /* in_list  */
  YYSYMBOL_in_item = 135,                  /* in_item  */
  YYSYMBOL_out_list = 136,                 /* out_list  */
  YYSYMBOL_out_item = 137,                 /* out_item  */
  YYSYMBOL_comp_statement = 138,           /* comp_statement  */
  YYSYMBOL_139_7 = 139,                    /* $@7  */
  YYSYMBOL_main_function = 140,            /* main_function  */
  YYSYMBOL_141_8 = 141,                    /* $@8  */
  YYSYMBOL_main_header = 142               /* main_header  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   648

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  193
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  357

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


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
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   110,   111,   114,   115,   116,   117,   118,
     121,   122,   123,   124,   127,   128,   131,   132,   133,   134,
     137,   138,   141,   142,   143,   144,   145,   146,   149,   150,
     151,   152,   156,   157,   158,   161,   162,   165,   166,   169,
     170,   171,   172,   175,   176,   179,   182,   185,   186,   189,
     192,   195,   196,   197,   198,   201,   204,   207,   208,   211,
     212,   215,   218,   221,   224,   225,   228,   231,   232,   235,
     238,   239,   242,   243,   244,   245,   246,   247,   250,   251,
     254,   255,   256,   259,   260,   263,   264,   267,   267,   268,
     268,   269,   269,   272,   273,   276,   279,   282,   283,   286,
     287,   290,   293,   294,   295,   296,   299,   300,   303,   304,
     307,   308,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   326,   327,   330,   331,   334,
     335,   336,   339,   340,   341,   342,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   364,   365,   368,   368,   371,   372,   375,
     375,   378,   381,   382,   385,   388,   388,   389,   392,   393,
     394,   395,   398,   399,   402,   403,   404,   407,   408,   411,
     414,   415,   418,   419,   421,   424,   425,   428,   429,   435,
     435,   438,   438,   441
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"eof\"", "error", "\"invalid token\"", "\"typedef\"", "\"char\"",
  "\"int\"", "\"float\"", "\"enum\"", "\"class\"", "\"private\"",
  "\"protected\"", "\"public\"", "\"void\"", "\"static\"", "\"continue\"",
  "\"break\"", "\"this\"", "\"if\"", "\"else\"", "\"while\"", "\"for\"",
  "\"switch\"", "\"case\"", "\"default\"", "\"return\"", "\"cin\"",
  "\"cout\"", "\"length\"", "\"main\"", "\"id\"", "\"int const\"",
  "\"double const\"", "\"char const\"", "\"||\"", "\"&&\"", "\"== !=\"",
  "\"< >= < <=\"", "\"+ -\"", "\"* / %\"", "\"!\"", "\"++ --\"",
  "\"SIZEOF\"", "\"string\"", "\"(\"", "\")\"", "\";\"", "\".\"", "\",\"",
  "\"=\"", "\":\"", "\"[\"", "\"]\"", "\"&\"", "\"{\"", "\"}\"", "\"::\"",
  "\">>\"", "\"<<\"", "LOWER_THAN_ELSE", "$accept", "program",
  "global_declarations", "global_declaration", "typedef_declaration",
  "typename", "standard_type", "dims", "dim", "class_declaration",
  "class_body", "parent", "members_methods", "access", "member_or_method",
  "member", "var_declaration", "variabledefs", "variabledef", "method",
  "short_func_declaration", "short_par_func_header", "func_header_start",
  "parameter_type_list", "pass_dims", "nopar_func_header",
  "enum_declaration", "enum_body", "id_list", "global_var_declaration",
  "init_variabledefs", "init_variabledef", "initializer", "init_value",
  "sign", "constant", "init_values", "func_declaration",
  "full_func_declaration", "$@1", "$@2", "$@3", "full_par_func_header",
  "class_func_header_start", "func_class", "parameter_list",
  "pass_variabledef", "nopar_class_func_header", "decl_statements",
  "declarations", "decltype", "statements", "statement",
  "expression_statement", "general_expression", "assignment", "variable",
  "expression", "expression_list", "if_statement", "$@4", "if_tail",
  "while_statement", "$@5", "for_statement", "optexpr", "switch_statement",
  "switch_tail", "$@6", "decl_cases", "casestatements", "casestatement",
  "single_casestatement", "return_statement", "io_statement", "in_list",
  "in_item", "out_list", "out_item", "comp_statement", "$@7",
  "main_function", "$@8", "main_header", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-312)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-172)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -312,    40,   247,  -312,   477,   505,  -312,    25,  -312,    64,
      35,  -312,  -312,  -312,  -312,   147,  -312,  -312,  -312,    51,
     145,    20,  -312,  -312,  -312,  -312,   140,   178,   181,  -312,
     185,  -312,     5,   215,    99,   204,   203,   212,   212,    -4,
     216,   125,  -312,   262,  -312,  -312,   162,  -312,  -312,  -312,
    -312,   175,  -312,  -312,   281,   273,    26,  -312,  -312,  -312,
     278,   294,   283,   284,    87,  -312,    54,   116,  -312,  -312,
     309,  -312,  -312,   126,    89,   150,   258,   258,  -312,   134,
     161,   258,   258,  -312,  -312,   366,   366,    61,   104,   106,
    -312,   216,   138,  -312,  -312,  -312,  -312,   131,    36,  -312,
     116,  -312,  -312,   116,  -312,   304,  -312,  -312,   322,    42,
    -312,  -312,  -312,  -312,   505,  -312,   505,  -312,    93,   114,
    -312,   317,   327,   328,   341,   200,   296,   329,   345,  -312,
    -312,  -312,   589,   589,   194,   589,   489,  -312,  -312,  -312,
     335,   300,   619,   377,  -312,  -312,    16,  -312,   593,   271,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,   346,   322,  -312,
     351,   359,   350,   370,   372,    49,   505,    66,  -312,  -312,
     131,  -312,  -312,   386,  -312,   373,  -312,  -312,    17,  -312,
    -312,   149,    27,  -312,  -312,  -312,   371,   134,  -312,  -312,
    -312,  -312,   589,   589,   200,   589,   406,   393,   396,   194,
     549,   589,   594,   410,  -312,    -5,  -312,   414,   168,   258,
    -312,   619,   377,   421,   309,  -312,  -312,  -312,   589,  -312,
     509,   425,   569,   589,   589,   589,   589,   589,   589,   589,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,   505,   427,  -312,
    -312,  -312,  -312,  -312,   416,   115,  -312,  -312,   216,  -312,
    -312,  -312,   116,  -312,  -312,  -312,  -312,  -312,  -312,   170,
     189,   424,   202,  -312,  -312,    -5,   -10,  -312,  -312,   393,
     132,  -312,   213,  -312,  -312,   422,   309,   255,  -312,  -312,
     393,   426,  -312,  -312,  -312,   124,   232,   312,   374,   191,
     410,  -312,  -312,   432,   297,   162,  -312,  -312,  -312,  -312,
     200,   112,  -312,   194,  -312,   549,  -312,  -312,   333,  -312,
     309,  -312,  -312,  -312,   371,   447,   447,   435,   415,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,   467,  -312,   529,   442,
      96,   447,  -312,   452,   412,   415,   448,   108,   505,   444,
     264,  -312,  -312,   447,  -312,  -312,   450,   447,   505,   264,
    -312,  -312,  -312,   342,   377,   377,  -312
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,    16,    17,    18,     0,
       0,    19,    15,     3,     5,     0,    14,     6,    85,     0,
       0,     0,     7,     8,     9,    86,     0,     0,     0,     2,
       0,    17,    36,     0,     0,     0,     0,    36,    36,    21,
      71,     0,    68,     0,    52,    51,     0,    54,    53,    91,
      87,     0,    89,   191,     0,     0,     0,    21,    21,    21,
       0,     0,     0,     0,     0,    96,     0,     0,    69,    66,
       0,    95,    61,    21,     0,     0,   109,   109,   101,     0,
       0,   109,   109,    35,    29,    42,    42,     0,     0,     0,
     193,    71,     0,    62,    30,    31,    28,     0,     0,    20,
       0,    78,    77,     0,    70,     0,    21,    67,    60,     0,
      99,    58,    98,    55,     0,    94,     0,   108,     0,     0,
     135,     0,     0,     0,     0,   109,     0,     0,     0,    81,
      82,    80,   109,   109,   109,   109,   109,   124,   189,   150,
       0,   109,     0,   104,   111,   112,     0,   128,   147,   131,
     113,   114,   115,   116,   117,   118,   119,     0,     0,    93,
       0,     0,     0,     0,     0,    42,     0,     0,    11,    12,
      13,    10,    65,     0,    63,     0,    26,    27,     0,    25,
      84,     0,     0,    73,    72,   100,    21,     0,   121,   120,
     123,   122,   109,   109,   109,   109,     0,   162,     0,   109,
     109,   109,   147,   143,   142,   145,   144,     0,     0,   109,
      92,     0,   102,   134,     0,   110,   126,   125,   109,   146,
     109,     0,   109,   109,   109,   109,   109,   109,   109,   109,
      88,    90,   192,    39,    40,    41,    33,     0,     0,    38,
      43,    45,    44,    50,     0,     0,    34,    32,    71,    23,
      24,    22,     0,    75,    76,    74,    60,    57,    97,     0,
       0,     0,     0,   134,   179,   184,     0,   183,   188,   187,
       0,   186,     0,   152,   151,     0,     0,     0,    48,   127,
     153,     0,   133,   130,   129,     0,   136,   137,   138,   139,
     140,   141,    37,    21,     0,     0,    64,    83,   155,   159,
     109,     0,   180,   109,   181,   109,   149,   190,     0,   107,
       0,   148,   132,    46,    21,   109,   109,     0,     0,   165,
     164,   167,   182,   185,   106,    47,   158,   160,   109,     0,
     109,   109,   156,     0,   109,     0,     0,   109,     0,     0,
     170,   173,   157,   109,   178,   177,     0,   109,     0,   168,
     166,   172,   161,   109,   176,   175,   174
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -312,  -312,  -312,  -312,  -312,    -2,   367,   -51,  -312,  -312,
     243,  -312,   418,   127,   270,  -312,  -312,  -219,   -14,  -312,
     506,  -312,   510,  -312,   332,   511,  -312,  -312,  -312,  -312,
    -312,   445,   -75,   -54,  -312,   -93,   411,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,   472,   337,  -312,   -57,   197,
     -72,  -127,  -132,  -312,  -110,   311,  -102,   -85,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -171,  -312,  -312,  -312,  -312,
     198,  -311,   209,  -312,  -312,  -312,   228,  -312,   233,  -312,
    -312,  -312,  -312,  -312
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    13,    14,   214,    16,    66,    99,    17,
      55,    56,   165,   166,   239,   240,   241,   277,   110,   242,
     243,    19,   244,    74,   111,   245,    22,    62,    92,    23,
      41,    42,    68,   180,   105,   139,   181,    24,    25,    77,
      81,    76,    26,    27,    43,    75,   112,    28,   140,   141,
     196,   143,   144,   145,   146,   147,   148,   149,   281,   150,
     315,   332,   151,   316,   152,   198,   153,   320,   330,   339,
     340,   341,   321,   154,   155,   266,   267,   270,   271,   156,
     209,    29,    82,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    40,    33,    34,   142,   142,    87,    88,    89,   142,
     142,   215,   184,   104,   212,   197,   172,   216,   250,   294,
     157,    47,   109,   261,   160,   161,   208,    85,   254,   351,
     202,   202,   205,   202,   -15,   302,    37,   177,   351,   -56,
       3,   221,   356,    97,    73,   223,   303,   203,   204,    79,
     206,    65,    44,    35,    54,    97,    40,   308,   162,   163,
     164,   217,    97,   218,    38,    48,   178,   246,   251,   211,
     -42,   -42,   -42,    49,   252,   162,   163,   164,   -42,    86,
     215,   255,   259,   260,   197,   262,   -59,   179,    95,   -59,
     269,   272,    98,    36,   188,   -42,    45,   265,   -49,   -49,
      58,   -49,   -49,   236,    98,    97,   168,   170,   279,   117,
     280,    98,   186,   285,   187,   190,    47,   100,   335,   336,
     247,   117,   202,   202,   202,   202,   202,   202,    59,   317,
     335,   336,    96,   113,   318,   109,   114,   142,   189,   286,
     287,   288,   289,   290,   291,   -79,   -79,   -79,   -79,   169,
    -171,   171,   275,   101,    98,   106,    98,   333,   102,   191,
      48,   175,  -169,   106,   238,   319,     6,    31,     8,   103,
      69,   218,    70,   296,    11,   312,    39,   304,   108,     6,
      31,     8,   176,   326,   327,   173,   158,    11,    46,   305,
     197,    12,   174,    50,   115,   269,   252,   116,   297,   342,
     278,   265,   344,   253,    12,   159,    72,   117,   116,   276,
     120,   352,   274,   117,   298,   218,   120,   218,   197,    78,
     354,    51,   215,   215,   278,   329,   355,   128,   228,   229,
     129,   130,   131,   299,    52,   238,   218,   132,    53,   133,
     134,   135,   346,   136,    57,  -163,   301,    60,     4,   218,
       5,     6,     7,     8,     9,    10,    61,   306,   338,    11,
     218,    54,   278,   109,    67,   348,   225,   226,   227,   228,
     229,   117,   118,   119,   120,   121,    12,   122,   123,   124,
      63,    64,   125,   126,   127,   128,   335,   336,   129,   130,
     131,    71,   237,   314,   237,   132,   325,   133,   134,   135,
     309,   136,   310,   137,   224,   225,   226,   227,   228,   229,
      83,   138,  -105,   117,   118,   119,   120,   121,    84,   122,
     123,   124,    90,    91,   125,   126,   127,   128,    93,    94,
     129,   130,   131,   183,   129,   130,   131,   132,   106,   133,
     134,   135,   313,   136,   310,   137,   276,   226,   227,   228,
     229,   185,   199,   138,  -103,   117,   118,   119,   120,   121,
     192,   122,   123,   124,   335,   336,   125,   126,   127,   128,
     193,   194,   129,   130,   131,   162,   163,   164,   324,   132,
     310,   133,   134,   135,   195,   136,   200,   137,   201,   210,
     117,   118,   119,   120,   121,   138,   122,   123,   124,   233,
     230,   125,   126,   127,   128,   231,  -109,   129,   130,   131,
     227,   228,   229,   232,   132,   248,   133,   134,   135,   234,
     136,   235,   137,   256,   249,   117,   118,   119,   120,   121,
     138,   122,   123,   124,   318,   263,   125,   126,   127,   128,
     218,   264,   129,   130,   131,   129,   130,   131,   229,   132,
     -15,   133,   134,   135,   282,   136,   293,   137,   273,   295,
     117,   118,   119,   120,   121,   138,   122,   123,   124,   300,
     311,   125,   126,   127,   128,   -56,   307,   129,   130,   131,
     328,     6,    31,     8,   132,   331,   133,   134,   135,    11,
     136,   334,   137,     6,    31,     8,   343,   347,   350,   353,
     138,    11,   117,   207,   167,   120,    32,   292,    18,     6,
      31,     8,    20,    21,   182,   107,   128,    11,   257,   129,
     130,   131,   117,    80,   258,   120,   132,   337,   133,   134,
     135,   322,   136,   284,    12,   349,   128,     0,   323,   129,
     130,   131,   117,   345,     0,   120,   132,     0,   133,   134,
     135,     0,   136,  -154,     0,     0,   128,     0,     0,   129,
     130,   131,   117,     0,     0,   120,   132,     0,   133,   134,
     135,     0,   136,  -163,     0,     0,   128,     0,     0,   129,
     130,   131,   117,     0,     0,   120,   132,     0,   133,   134,
     135,   268,   136,     0,     0,     0,   128,     0,     0,   129,
     130,   131,   117,     0,     0,   120,   132,     0,   133,   134,
     135,   283,   136,     0,     0,     0,   128,     0,     0,   129,
     130,   131,     0,     6,    31,     8,   132,     0,   133,   134,
     135,    11,   136,   219,   219,     0,   220,   220,     0,   221,
     221,   222,     0,   223,   223,     0,     0,     0,   213
};

static const yytype_int16 yycheck[] =
{
       2,    15,     4,     5,    76,    77,    57,    58,    59,    81,
      82,   143,   105,    67,   141,   125,    91,     1,     1,   238,
      77,     1,    73,   194,    81,    82,   136,     1,     1,   340,
     132,   133,   134,   135,    29,    45,     1,     1,   349,    43,
       0,    46,   353,     1,    46,    50,    56,   132,   133,    51,
     135,    55,     1,    28,    49,     1,    70,   276,     9,    10,
      11,    45,     1,    47,    29,    45,    30,     1,    51,   141,
       4,     5,     6,    53,    47,     9,    10,    11,    12,    53,
     212,    54,   192,   193,   194,   195,    44,    51,     1,    47,
     200,   201,    50,    29,     1,    29,    45,   199,    44,    45,
       1,    47,    48,    54,    50,     1,    45,     1,   218,    13,
     220,    50,   114,   223,   116,     1,     1,     1,    22,    23,
      54,    13,   224,   225,   226,   227,   228,   229,    29,   300,
      22,    23,    45,    44,    22,   186,    47,   209,    45,   224,
     225,   226,   227,   228,   229,    29,    30,    31,    32,    45,
      54,    45,   209,    37,    50,    29,    50,   328,    42,    45,
      45,    30,    54,    29,   166,    53,     4,     5,     6,    53,
      45,    47,    47,   248,    12,    51,    29,    45,    52,     4,
       5,     6,    51,   315,   316,    47,    52,    12,    43,    57,
     300,    29,    54,    53,    44,   305,    47,    47,   252,   331,
     214,   303,   334,    54,    29,    44,    44,    13,    47,   211,
      16,   343,    44,    13,    44,    47,    16,    47,   328,    44,
     347,    43,   354,   355,   238,   318,   353,    27,    37,    38,
      30,    31,    32,    44,    53,   237,    47,    37,    53,    39,
      40,    41,   335,    43,    29,    45,    44,    43,     1,    47,
       3,     4,     5,     6,     7,     8,    53,    44,   330,    12,
      47,    49,   276,   314,    48,   337,    34,    35,    36,    37,
      38,    13,    14,    15,    16,    17,    29,    19,    20,    21,
      37,    38,    24,    25,    26,    27,    22,    23,    30,    31,
      32,    29,   165,   295,   167,    37,   310,    39,    40,    41,
      45,    43,    47,    45,    33,    34,    35,    36,    37,    38,
      29,    53,    54,    13,    14,    15,    16,    17,    45,    19,
      20,    21,    44,    29,    24,    25,    26,    27,    45,    45,
      30,    31,    32,    29,    30,    31,    32,    37,    29,    39,
      40,    41,    45,    43,    47,    45,   348,    35,    36,    37,
      38,    29,    56,    53,    54,    13,    14,    15,    16,    17,
      43,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      43,    43,    30,    31,    32,     9,    10,    11,    45,    37,
      47,    39,    40,    41,    43,    43,    57,    45,    43,    54,
      13,    14,    15,    16,    17,    53,    19,    20,    21,    49,
      54,    24,    25,    26,    27,    54,    29,    30,    31,    32,
      36,    37,    38,    54,    37,    29,    39,    40,    41,    49,
      43,    49,    45,    52,    51,    13,    14,    15,    16,    17,
      53,    19,    20,    21,    22,    29,    24,    25,    26,    27,
      47,    45,    30,    31,    32,    30,    31,    32,    38,    37,
      29,    39,    40,    41,    29,    43,    29,    45,    44,    43,
      13,    14,    15,    16,    17,    53,    19,    20,    21,    45,
      44,    24,    25,    26,    27,    43,    54,    30,    31,    32,
      45,     4,     5,     6,    37,    18,    39,    40,    41,    12,
      43,    49,    45,     4,     5,     6,    44,    49,    54,    49,
      53,    12,    13,   136,    86,    16,    29,   237,     2,     4,
       5,     6,     2,     2,   103,    70,    27,    12,   186,    30,
      31,    32,    13,    51,   187,    16,    37,   330,    39,    40,
      41,   303,    43,   222,    29,   337,    27,    -1,   305,    30,
      31,    32,    13,   334,    -1,    16,    37,    -1,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    27,    -1,    -1,    30,
      31,    32,    13,    -1,    -1,    16,    37,    -1,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    27,    -1,    -1,    30,
      31,    32,    13,    -1,    -1,    16,    37,    -1,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    27,    -1,    -1,    30,
      31,    32,    13,    -1,    -1,    16,    37,    -1,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    27,    -1,    -1,    30,
      31,    32,    -1,     4,     5,     6,    37,    -1,    39,    40,
      41,    12,    43,    40,    40,    -1,    43,    43,    -1,    46,
      46,    48,    -1,    50,    50,    -1,    -1,    -1,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,    61,     0,     1,     3,     4,     5,     6,     7,
       8,    12,    29,    62,    63,    64,    65,    68,    79,    80,
      81,    84,    85,    88,    96,    97,   101,   102,   106,   140,
     142,     5,    29,    64,    64,    28,    29,     1,    29,    29,
      77,    89,    90,   103,     1,    45,    43,     1,    45,    53,
      53,    43,    53,    53,    49,    69,    70,    29,     1,    29,
      43,    53,    86,    69,    69,    55,    66,    48,    91,    45,
      47,    29,    44,    64,    82,   104,   100,    98,    44,    64,
     104,    99,   141,    29,    45,     1,    53,    66,    66,    66,
      44,    29,    87,    45,    45,     1,    45,     1,    50,    67,
       1,    37,    42,    53,    92,    93,    29,    90,    52,    66,
      77,    83,   105,    44,    47,    44,    47,    13,    14,    15,
      16,    17,    19,    20,    21,    24,    25,    26,    27,    30,
      31,    32,    37,    39,    40,    41,    43,    45,    53,    94,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     118,   121,   123,   125,   132,   133,   138,   107,    52,    44,
     107,   107,     9,    10,    11,    71,    72,    71,    45,    45,
       1,    45,    91,    47,    54,    30,    51,     1,    30,    51,
      92,    95,    95,    29,    94,    29,    64,    64,     1,    45,
       1,    45,    43,    43,    43,    43,   109,   113,   124,    56,
      57,    43,   115,   116,   116,   115,   116,    65,   113,   139,
      54,   109,   110,    29,    64,   111,     1,    45,    47,    40,
      43,    46,    48,    50,    33,    34,    35,    36,    37,    38,
      54,    54,    54,    49,    49,    49,    54,    72,    64,    73,
      74,    75,    78,    79,    81,    84,     1,    54,    29,    51,
       1,    51,    47,    54,     1,    54,    52,    83,   105,   113,
     113,   124,   113,    29,    45,   115,   134,   135,    42,   113,
     136,   137,   113,    44,    44,   107,    64,    76,    77,   113,
     113,   117,    29,    42,   114,   113,   116,   116,   116,   116,
     116,   116,    73,    29,    76,    43,    91,    92,    44,    44,
      45,    44,    45,    56,    45,    57,    44,    54,    76,    45,
      47,    44,    51,    45,    64,   119,   122,   124,    22,    53,
     126,   131,   135,   137,    45,    77,   111,   111,    45,    94,
     127,    18,   120,   124,    49,    22,    23,   108,   109,   128,
     129,   130,   111,    44,   111,   131,    94,    49,   109,   129,
      54,   130,   111,    49,   110,   110,   130
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    62,    62,    62,
      63,    63,    63,    63,    64,    64,    65,    65,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    68,    68,
      68,    68,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    72,    72,    73,    73,    74,    75,    76,    76,    77,
      78,    79,    79,    79,    79,    80,    81,    82,    82,    83,
      83,    84,    85,    86,    87,    87,    88,    89,    89,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    93,    93,
      94,    94,    94,    95,    95,    96,    96,    98,    97,    99,
      97,   100,    97,   101,   101,   102,   103,   104,   104,   105,
     105,   106,   107,   107,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   112,   112,   113,   113,   114,
     114,   114,   115,   115,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   119,   118,   120,   120,   122,
     121,   123,   124,   124,   125,   127,   126,   126,   128,   128,
     128,   128,   129,   129,   130,   130,   130,   131,   131,   132,
     133,   133,   134,   134,   135,   136,   136,   137,   137,   139,
     138,   141,   140,   142
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     1,     1,     1,     1,     1,     1,
       2,     0,     3,     3,     3,     2,     2,     2,     4,     4,
       4,     4,     4,     4,     4,     2,     0,     3,     2,     2,
       2,     2,     0,     1,     1,     1,     3,     3,     1,     2,
       1,     2,     2,     2,     2,     4,     2,     4,     2,     1,
       1,     3,     4,     3,     4,     2,     3,     3,     1,     2,
       2,     0,     2,     2,     3,     3,     3,     1,     1,     0,
       1,     1,     1,     3,     1,     1,     1,     0,     5,     0,
       5,     0,     5,     4,     4,     3,     2,     4,     2,     1,
       2,     3,     2,     1,     1,     0,     5,     4,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     3,     1,     3,
       3,     1,     4,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     1,     4,     4,
       1,     3,     3,     1,     0,     0,     7,     2,     0,     0,
       6,     9,     1,     0,     5,     0,     4,     1,     2,     1,
       1,     0,     2,     1,     4,     4,     3,     4,     4,     3,
       4,     4,     3,     1,     1,     3,     1,     1,     1,     0,
       4,     0,     5,     4
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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

  if (yychar <= T_EOF)
    {
      yychar = T_EOF;
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
  case 10: /* typedef_declaration: "typedef" typename "id" dims ";"  */
#line 121 "syntax.y"
                                                                          {hashtbl_insert(hashtbl,(yyvsp[-2].strval),NULL,scope);}
#line 1813 "syntax.tab.c"
    break;

  case 11: /* typedef_declaration: error typename "id" dims ";"  */
#line 122 "syntax.y"
                                                                        {hashtbl_insert(hashtbl,(yyvsp[-2].strval),NULL,scope); yyerror("Wrong declaration of typedef"); yyerrok;}
#line 1819 "syntax.tab.c"
    break;

  case 12: /* typedef_declaration: "typedef" typename error dims ";"  */
#line 123 "syntax.y"
                                                                            {yyerror("Wrong declaration of typedef"); yyerrok;}
#line 1825 "syntax.tab.c"
    break;

  case 13: /* typedef_declaration: "typedef" typename "id" dims error  */
#line 124 "syntax.y"
                                                                          {hashtbl_insert(hashtbl,(yyvsp[-2].strval),NULL,scope); yyerror("Forgot semicolon"); yyerrok;}
#line 1831 "syntax.tab.c"
    break;

  case 15: /* typename: "id"  */
#line 128 "syntax.y"
                                           {hashtbl_insert(hashtbl,(yyvsp[0].strval),NULL,scope);}
#line 1837 "syntax.tab.c"
    break;

  case 23: /* dim: error "int const" "]"  */
#line 142 "syntax.y"
                                                             {yyerror("Missing left bracket"); yyerrok;}
#line 1843 "syntax.tab.c"
    break;

  case 24: /* dim: "[" "int const" error  */
#line 143 "syntax.y"
                                                             {yyerror("Missing right bracket"); yyerrok;}
#line 1849 "syntax.tab.c"
    break;

  case 26: /* dim: error "]"  */
#line 145 "syntax.y"
                                                     {yyerror("Missing left bracket"); yyerrok;}
#line 1855 "syntax.tab.c"
    break;

  case 27: /* dim: "[" error  */
#line 146 "syntax.y"
                                                     {yyerror("Missing right bracket"); yyerrok;}
#line 1861 "syntax.tab.c"
    break;

  case 28: /* class_declaration: "class" "id" class_body ";"  */
#line 149 "syntax.y"
                                                                      {hashtbl_insert(hashtbl,(yyvsp[-2].strval),NULL,scope); }
#line 1867 "syntax.tab.c"
    break;

  case 29: /* class_declaration: error "id" class_body ";"  */
#line 150 "syntax.y"
                                                                    {hashtbl_insert(hashtbl,(yyvsp[-2].strval),NULL,scope); yyerror("Wrong declaration of class"); yyerrok;}
#line 1873 "syntax.tab.c"
    break;

  case 30: /* class_declaration: "class" error class_body ";"  */
#line 151 "syntax.y"
                                                                       { yyerror("Wrong declaration of class"); yyerrok;}
#line 1879 "syntax.tab.c"
    break;

  case 31: /* class_declaration: "class" "id" class_body error  */
#line 152 "syntax.y"
                                                                     {hashtbl_insert(hashtbl,(yyvsp[-2].strval),NULL,scope); yyerror("Forgot semicolon"); yyerrok;}
#line 1885 "syntax.tab.c"
    break;

  case 33: /* class_body: parent error members_methods "}"  */
#line 157 "syntax.y"
                                                                              {yyerror("Missing left brace"); yyerrok;}
#line 1891 "syntax.tab.c"
    break;

  case 34: /* class_body: parent "{" members_methods error  */
#line 158 "syntax.y"
                                                                              {yyerror("Missing right brace"); yyerrok;}
#line 1897 "syntax.tab.c"
    break;

  case 35: /* parent: ":" "id"  */
#line 161 "syntax.y"
                                                   {hashtbl_insert(hashtbl,(yyvsp[0].strval),NULL,scope);scope++;}
#line 1903 "syntax.tab.c"
    break;

  case 36: /* parent: %empty  */
#line 162 "syntax.y"
                                             {}
#line 1909 "syntax.tab.c"
    break;

  case 39: /* access: "private" ":"  */
#line 169 "syntax.y"
                                                        {scope++;}
#line 1915 "syntax.tab.c"
    break;

  case 40: /* access: "protected" ":"  */
#line 170 "syntax.y"
                                                          {scope++;}
#line 1921 "syntax.tab.c"
    break;

  case 41: /* access: "public" ":"  */
#line 171 "syntax.y"
                                                       {check();}
#line 1927 "syntax.tab.c"
    break;

  case 49: /* variabledef: "id" dims  */
#line 189 "syntax.y"
                                                {hashtbl_insert(hashtbl,(yyvsp[-1].strval),NULL,scope);}
#line 1933 "syntax.tab.c"
    break;

  case 52: /* short_func_declaration: short_par_func_header error  */
#line 196 "syntax.y"
                                                                   {yyerror("Forgot semicolon"); yyerrok;}
#line 1939 "syntax.tab.c"
    break;

  case 54: /* short_func_declaration: nopar_func_header error  */
#line 198 "syntax.y"
                                                                {yyerror("Forgot semicolon"); yyerrok;}
#line 1945 "syntax.tab.c"
    break;

  case 56: /* func_header_start: typename "id"  */
#line 204 "syntax.y"
                                                    {hashtbl_insert(hashtbl,(yyvsp[0].strval),NULL,scope);}
#line 1951 "syntax.tab.c"
    break;

  case 62: /* enum_declaration: "enum" "id" enum_body ";"  */
#line 218 "syntax.y"
                                                                   {hashtbl_insert(hashtbl,(yyvsp[-2].strval),NULL,scope);}
#line 1957 "syntax.tab.c"
    break;

  case 64: /* id_list: id_list "," "id" initializer  */
#line 224 "syntax.y"
                                                                       {hashtbl_insert(hashtbl,(yyvsp[-1].strval),NULL,scope);}
#line 1963 "syntax.tab.c"
    break;

  case 65: /* id_list: "id" initializer  */
#line 225 "syntax.y"
                                                       {hashtbl_insert(hashtbl,(yyvsp[-1].strval),NULL,scope);}
#line 1969 "syntax.tab.c"
    break;

  case 73: /* init_value: sign "id"  */
#line 243 "syntax.y"
                                                {hashtbl_insert(hashtbl,(yyvsp[0].strval),NULL,scope);}
#line 1975 "syntax.tab.c"
    break;

  case 75: /* init_value: error init_values "}"  */
#line 245 "syntax.y"
                                                                 {yyerror("Missing left drace"); yyerrok;}
#line 1981 "syntax.tab.c"
    break;

  case 76: /* init_value: "{" init_values error  */
#line 246 "syntax.y"
                                                                    {yyerror("Missing right drace"); yyerrok;}
#line 1987 "syntax.tab.c"
    break;

  case 87: /* $@1: %empty  */
#line 267 "syntax.y"
                                                                    {scope++;}
#line 1993 "syntax.tab.c"
    break;

  case 88: /* full_func_declaration: full_par_func_header "{" $@1 decl_statements "}"  */
#line 267 "syntax.y"
                                                                                                        {hashtbl_get(hashtbl,scope);check();}
#line 1999 "syntax.tab.c"
    break;

  case 89: /* $@2: %empty  */
#line 268 "syntax.y"
                                                                       {scope++;}
#line 2005 "syntax.tab.c"
    break;

  case 90: /* full_func_declaration: nopar_class_func_header "{" $@2 decl_statements "}"  */
#line 268 "syntax.y"
                                                                                                           {hashtbl_get(hashtbl,scope);check();}
#line 2011 "syntax.tab.c"
    break;

  case 91: /* $@3: %empty  */
#line 269 "syntax.y"
                                                                 {scope++;}
#line 2017 "syntax.tab.c"
    break;

  case 92: /* full_func_declaration: nopar_func_header "{" $@3 decl_statements "}"  */
#line 269 "syntax.y"
                                                                                                     {hashtbl_get(hashtbl,scope);check();}
#line 2023 "syntax.tab.c"
    break;

  case 95: /* class_func_header_start: typename func_class "id"  */
#line 276 "syntax.y"
                                                               {hashtbl_insert(hashtbl,(yyvsp[0].strval),NULL,scope);}
#line 2029 "syntax.tab.c"
    break;

  case 96: /* func_class: "id" "::"  */
#line 279 "syntax.y"
                                                  {hashtbl_insert(hashtbl,(yyvsp[-1].strval),NULL,scope);}
#line 2035 "syntax.tab.c"
    break;

  case 100: /* pass_variabledef: "&" "id"  */
#line 287 "syntax.y"
                                                   {hashtbl_insert(hashtbl,(yyvsp[0].strval),NULL,scope);}
#line 2041 "syntax.tab.c"
    break;

  case 121: /* statement: "continue" error  */
#line 320 "syntax.y"
                                                       {yyerror("Forgot semicolon"); yyerrok;}
#line 2047 "syntax.tab.c"
    break;

  case 123: /* statement: "break" error  */
#line 322 "syntax.y"
                                                    {yyerror("Forgot semicolon"); yyerrok;}
#line 2053 "syntax.tab.c"
    break;

  case 126: /* expression_statement: general_expression error  */
#line 327 "syntax.y"
                                                                {yyerror("Forgot semicolon"); yyerrok;}
#line 2059 "syntax.tab.c"
    break;

  case 133: /* variable: variable "." "id"  */
#line 340 "syntax.y"
                                                          {hashtbl_insert(hashtbl,(yyvsp[0].strval),NULL,scope);}
#line 2065 "syntax.tab.c"
    break;

  case 134: /* variable: decltype "id"  */
#line 341 "syntax.y"
                                                    {hashtbl_insert(hashtbl,(yyvsp[0].strval),NULL,scope);}
#line 2071 "syntax.tab.c"
    break;

  case 155: /* $@4: %empty  */
#line 368 "syntax.y"
                                                                                {scope++;}
#line 2077 "syntax.tab.c"
    break;

  case 157: /* if_tail: "else" statement  */
#line 371 "syntax.y"
                                                       {hashtbl_get(hashtbl,scope);check();}
#line 2083 "syntax.tab.c"
    break;

  case 159: /* $@5: %empty  */
#line 375 "syntax.y"
                                                                                   {scope++;}
#line 2089 "syntax.tab.c"
    break;

  case 165: /* $@6: %empty  */
#line 388 "syntax.y"
                                               {scope++;}
#line 2095 "syntax.tab.c"
    break;

  case 166: /* switch_tail: "{" $@6 decl_cases "}"  */
#line 388 "syntax.y"
                                                                              {hashtbl_get(hashtbl,scope);check();}
#line 2101 "syntax.tab.c"
    break;

  case 189: /* $@7: %empty  */
#line 435 "syntax.y"
                                              {scope++;}
#line 2107 "syntax.tab.c"
    break;

  case 190: /* comp_statement: "{" $@7 decl_statements "}"  */
#line 435 "syntax.y"
                                                                                  {hashtbl_get(hashtbl,scope);check();}
#line 2113 "syntax.tab.c"
    break;

  case 191: /* $@8: %empty  */
#line 438 "syntax.y"
                                                           {scope++;}
#line 2119 "syntax.tab.c"
    break;

  case 192: /* main_function: main_header "{" $@8 decl_statements "}"  */
#line 438 "syntax.y"
                                                                                               {hashtbl_get(hashtbl,scope);check();}
#line 2125 "syntax.tab.c"
    break;


#line 2129 "syntax.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= T_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == T_EOF)
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 443 "syntax.y"


int main(int argc, char *argv[]) {
  int token;

  if(!(hashtbl = hashtbl_create(50,NULL))){
        printf("eEror failed to intialize hashtabl");
        exit(EXIT_FAILURE);
    }

  if(argc > 1){
    yyin = fopen(argv[1],"r");
    if(yyin == NULL){
      perror ("Error opening file");
      return EXIT_FAILURE;
    }
  }
  
  yyparse();

  fclose(yyin);
  hashtbl_destroy(hashtbl);


  return 0;
}

void check(void){
  if (scope>0){
    scope--;
  }else{
    scope=0;
  }
}
 
