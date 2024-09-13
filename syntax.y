%{
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
%}

%define parse.error verbose

%union {
  int intval;
  double doubleval;
  char charval;
  char* strval;
}
%token T_EOF      0     "eof"
%token T_TYPEDEF        "typedef"
%token T_CHAR           "char"
%token T_INT            "int"
%token T_FLOAT          "float"
%token T_ENUM           "enum"
%token T_CLASS          "class"
%token T_PRIVATE        "private"
%token T_PROTECTED      "protected"
%token T_PUBLIC         "public"

%token T_VOID           "void"
%token T_STATIC         "static"
%token T_CONTINUE       "continue"
%token T_BREAK          "break"
%token T_THIS           "this"
%token T_IF             "if"
%token T_ELSE           "else"
%token T_WHILE          "while"
%token T_FOR            "for"
%token T_SWITCH         "switch"
%token T_CASE           "case"
%token T_DEFAULT        "default"
%token T_RETURN         "return"
%token T_CIN            "cin"
%token T_COUT           "cout"
%token T_LENGTH         "length"
%token T_MAIN           "main"

%token <strval>       T_ID             "id"
%token <intval>       T_ICONST         "int const"
%token <doubleval>    T_FCONST         "double const"
%token <charval>      T_CCONST         "char const"

%token T_OROP           "||"
%token T_ANDOP          "&&"
%token T_EQUOP          "== !="
%token T_RELOP          "< >= < <="
%token T_ADDOP          "+ -"
%token T_MULOP          "* / %"
%token T_NOTOP          "!"
%token T_INCDEC         "++ --"
%token T_SIZEOP         "SIZEOF"

%token T_STRING         "string"

%token T_LPAREN         "("
%token T_RPAREN         ")"
%token T_SEMI           ";"
%token T_DOT            "."
%token T_COMMA          ","
%token T_ASSIGN         "="
%token T_COLON          ":"
%token T_LBRACK         "["
%token T_RBRACK         "]"
%token T_REFER          "&"
%token T_LBRACE         "{"
%token T_RBRACE         "}"
%token T_METH           "::"
%token T_INP            ">>"
%token T_OUT            "<<"

%left T_COMMA
%right T_ASSIGN
%left T_OROP 
%left T_ANDOP 
%left T_EQUOP 
%left T_RELOP 
%left T_ADDOP 
%left T_MULOP
%right T_NOTOP 
%left  T_DOT T_LBRACE T_RBRACE T_LBRACK T_RBRACK T_INCDEC 

%nonassoc T_SIZEOP
%nonassoc LOWER_THAN_ELSE
%nonassoc T_ELSE



%start program
%%

program :                             global_declarations main_function
                                      ;

global_declarations :                 global_declarations global_declaration 
                                    | %empty
                                    ;

global_declaration :                  typedef_declaration
                                    | class_declaration
                                    | enum_declaration
                                    | global_var_declaration
                                    | func_declaration
                                    ;

typedef_declaration :                 T_TYPEDEF typename T_ID dims T_SEMI {hashtbl_insert(hashtbl,$3,NULL,scope);}
                                      |error typename T_ID dims T_SEMI  {hashtbl_insert(hashtbl,$3,NULL,scope); yyerror("Wrong declaration of typedef"); yyerrok;}
                                      |T_TYPEDEF typename error dims T_SEMI {yyerror("Wrong declaration of typedef"); yyerrok;}
                                      |T_TYPEDEF typename T_ID dims error {hashtbl_insert(hashtbl,$3,NULL,scope); yyerror("Forgot semicolon"); yyerrok;}
                                      ;

typename :                            standard_type
                                    | T_ID {hashtbl_insert(hashtbl,$1,NULL,scope);}
                                    ;

standard_type :                       T_CHAR 
                                    | T_INT 
                                    | T_FLOAT 
                                    | T_VOID
                                      ;

dims :                                dims dim
                                    | %empty
                                    ;

dim :                                 T_LBRACK T_ICONST T_RBRACK
                                    |error T_ICONST T_RBRACK {yyerror("Missing left bracket"); yyerrok;}
                                    |T_LBRACK T_ICONST error {yyerror("Missing right bracket"); yyerrok;}
                                    | T_LBRACK T_RBRACK
                                    | error T_RBRACK {yyerror("Missing left bracket"); yyerrok;}
                                    | T_LBRACK error {yyerror("Missing right bracket"); yyerrok;}
                                    ;

class_declaration :                   T_CLASS T_ID class_body T_SEMI  {hashtbl_insert(hashtbl,$2,NULL,scope); }
                                      |error T_ID class_body T_SEMI {hashtbl_insert(hashtbl,$2,NULL,scope); yyerror("Wrong declaration of class"); yyerrok;} 
                                      |T_CLASS error class_body T_SEMI { yyerror("Wrong declaration of class"); yyerrok;}
                                      |T_CLASS T_ID class_body error {hashtbl_insert(hashtbl,$2,NULL,scope); yyerror("Forgot semicolon"); yyerrok;}
                                      ;


class_body :                          parent T_LBRACE members_methods T_RBRACE 
                                      | parent error members_methods T_RBRACE {yyerror("Missing left brace"); yyerrok;}
                                      | parent T_LBRACE members_methods error {yyerror("Missing right brace"); yyerrok;}
                                      ;

parent :                              T_COLON T_ID {hashtbl_insert(hashtbl,$2,NULL,scope);scope++;}
                                    | %empty {}
                                    ;

members_methods :                     members_methods access member_or_method
                                    | access member_or_method
                                    ;

access :                              T_PRIVATE T_COLON {scope++;}
                                    | T_PROTECTED T_COLON {scope++;}
                                    | T_PUBLIC T_COLON {check();}
                                    | %empty
                                    ;

member_or_method :                    member
                                      | method
                                      ;

member :                              var_declaration
                                      ;

var_declaration :                     typename variabledefs T_SEMI
                                      ;
                                      
variabledefs :                        variabledefs T_COMMA variabledef
                                      | variabledef
                                      ;

variabledef :                         T_ID dims {hashtbl_insert(hashtbl,$1,NULL,scope);}
                                      ;

method :                              short_func_declaration
                                      ;

short_func_declaration :              short_par_func_header T_SEMI
                                      |short_par_func_header error {yyerror("Forgot semicolon"); yyerrok;}
                                      | nopar_func_header T_SEMI
                                      | nopar_func_header error {yyerror("Forgot semicolon"); yyerrok;}
                                      ;
                                      
short_par_func_header :               func_header_start T_LPAREN parameter_type_list T_RPAREN
                                      ;

func_header_start :                   typename T_ID {hashtbl_insert(hashtbl,$2,NULL,scope);}
                                      ;

parameter_type_list :                 parameter_type_list T_COMMA typename pass_dims
                                      | typename pass_dims
                                      ;

pass_dims :                           dims
                                    | T_REFER
                                    ;
                                  
nopar_func_header :                   func_header_start T_LPAREN T_RPAREN
                                      ;

enum_declaration :                    T_ENUM T_ID enum_body T_SEMI {hashtbl_insert(hashtbl,$2,NULL,scope);}
                                      ;

enum_body :                           T_LBRACE id_list T_RBRACE
                                      ;

id_list :                             id_list T_COMMA T_ID initializer {hashtbl_insert(hashtbl,$3,NULL,scope);}
                                    | T_ID initializer {hashtbl_insert(hashtbl,$1,NULL,scope);}
                                    ;

global_var_declaration :              typename init_variabledefs T_SEMI
                                      ;

init_variabledefs :                   init_variabledefs T_COMMA init_variabledef
                                    | init_variabledef
                                    ;

init_variabledef :                    variabledef initializer
                                      ;

initializer :                         T_ASSIGN init_value
                                    | %empty
                                    ;

init_value :                          sign constant
                                    | sign T_ID {hashtbl_insert(hashtbl,$2,NULL,scope);}
                                    | T_LBRACE init_values T_RBRACE
                                    | error init_values T_RBRACE {yyerror("Missing left drace"); yyerrok;}
                                    | T_LBRACE init_values error    {yyerror("Missing right drace"); yyerrok;}
                                    | T_STRING
                                    ;

sign :                                T_ADDOP 
                                    | %empty
                                    ;

constant :                            T_CCONST 
                                    | T_ICONST 
                                    | T_FCONST
                                    ;

init_values :                         init_values T_COMMA init_value
                                    | init_value
                                    ;

func_declaration :                    short_func_declaration
                                    | full_func_declaration
                                    ;

full_func_declaration :               full_par_func_header T_LBRACE {scope++;} decl_statements T_RBRACE {hashtbl_get(hashtbl,scope);check();}
                                    | nopar_class_func_header T_LBRACE {scope++;} decl_statements T_RBRACE {hashtbl_get(hashtbl,scope);check();}
                                    | nopar_func_header T_LBRACE {scope++;} decl_statements T_RBRACE {hashtbl_get(hashtbl,scope);check();}
                                    ;

full_par_func_header :                class_func_header_start T_LPAREN parameter_list T_RPAREN
                                    | func_header_start T_LPAREN parameter_list T_RPAREN
                                    ;

class_func_header_start :             typename func_class T_ID {hashtbl_insert(hashtbl,$3,NULL,scope);}
                                      ;

func_class :                          T_ID T_METH {hashtbl_insert(hashtbl,$1,NULL,scope);}
                                    ;

parameter_list :                      parameter_list T_COMMA typename pass_variabledef
                                    | typename pass_variabledef
                                    ;

pass_variabledef :                    variabledef
                                    | T_REFER T_ID {hashtbl_insert(hashtbl,$2,NULL,scope);}
                                    ;

nopar_class_func_header :             class_func_header_start T_LPAREN T_RPAREN
                                      ;

decl_statements :                     declarations statements
                                    | declarations
                                    | statements
                                    | %empty  
                                    ;

declarations :                        declarations decltype typename variabledefs T_SEMI
                                    | decltype typename variabledefs T_SEMI
                                    ;

decltype :                            T_STATIC 
                                    | %empty
                                    ;

statements :                          statements statement
                                    | statement
                                      ;

statement :                           expression_statement
                                    | if_statement
                                    | while_statement
                                    | for_statement
                                    | switch_statement
                                    | return_statement
                                    | io_statement
                                    | comp_statement
                                    | T_CONTINUE T_SEMI
                                    | T_CONTINUE error {yyerror("Forgot semicolon"); yyerrok;}
                                    | T_BREAK T_SEMI
                                    | T_BREAK error {yyerror("Forgot semicolon"); yyerrok;}
                                    | T_SEMI
                                    ;

expression_statement :                general_expression T_SEMI 
                                      |general_expression error {yyerror("Forgot semicolon"); yyerrok;}
                                      ;

general_expression :                  general_expression T_COMMA general_expression
                                    | assignment
                                    ;

assignment :                          variable T_ASSIGN assignment
                                    | variable T_ASSIGN T_STRING
                                    | expression
                                    ;

variable :                            variable T_LBRACK general_expression T_RBRACK
                                    | variable T_DOT T_ID {hashtbl_insert(hashtbl,$3,NULL,scope);}
                                    | decltype T_ID {hashtbl_insert(hashtbl,$2,NULL,scope);}
                                    | T_THIS 
                                      ;

expression :                          expression T_OROP expression
                                    | expression T_ANDOP expression
                                    | expression T_EQUOP expression
                                    | expression T_RELOP expression
                                    | expression T_ADDOP expression
                                    | expression T_MULOP expression
                                    | T_NOTOP expression
                                    | T_ADDOP expression
                                    | T_SIZEOP expression
                                    | T_INCDEC variable
                                    | variable T_INCDEC
                                    | variable
                                    | variable T_LPAREN expression_list T_RPAREN
                                    | T_LENGTH T_LPAREN general_expression T_RPAREN
                                    | constant
                                    | T_LPAREN general_expression T_RPAREN
                                    | T_LPAREN standard_type T_RPAREN
                                      ;

expression_list :                     general_expression
                                    | %empty
                                    ;

if_statement :                        T_IF T_LPAREN general_expression T_RPAREN {scope++;} statement if_tail
                                      ;

if_tail :                             T_ELSE statement {hashtbl_get(hashtbl,scope);check();} 
                                    | %empty %prec LOWER_THAN_ELSE
                                    ;

while_statement :                     T_WHILE T_LPAREN general_expression T_RPAREN {scope++;} statement
                                      ;

for_statement :                       T_FOR T_LPAREN optexpr T_SEMI optexpr T_SEMI optexpr T_RPAREN statement
                                      ;

optexpr :                             general_expression
                                    | %empty
                                    ;

switch_statement :                    T_SWITCH T_LPAREN general_expression T_RPAREN switch_tail
                                    ;

switch_tail :                         T_LBRACE {scope++;} decl_cases T_RBRACE {hashtbl_get(hashtbl,scope);check();}
                                    | single_casestatement
                                    ;

decl_cases :                          declarations casestatements
                                    | declarations
                                    | casestatements
                                    | %empty
                                    ;

casestatements :                      casestatements casestatement
                                    | casestatement
                                    ;

casestatement  :                      T_CASE constant T_COLON  casestatement
                                    | T_CASE constant T_COLON statements
                                    | T_DEFAULT T_COLON statements
                                    ;

single_casestatement :                T_CASE constant T_COLON single_casestatement 
                                    | T_CASE constant T_COLON statement
                                    ;

return_statement :                    T_RETURN optexpr T_SEMI
                                      ;

io_statement :                    T_CIN T_INP in_list T_SEMI 
                                    | T_COUT T_OUT out_list T_SEMI
                                      ;

in_list :                             in_list T_INP in_item
                                    | in_item 
                                    ;
in_item :                               variable
                                      ;

out_list :                            out_list T_OUT out_item
                                    | out_item
                                    ;

out_item :                            general_expression
                                    | T_STRING
                                    ;




comp_statement :                      T_LBRACE{scope++;} decl_statements T_RBRACE {hashtbl_get(hashtbl,scope);check();} 
                                      ;

main_function :                       main_header T_LBRACE {scope++;} decl_statements T_RBRACE {hashtbl_get(hashtbl,scope);check();}
                                      ;

main_header :                         T_INT T_MAIN T_LPAREN T_RPAREN
                                      ;
%%

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
 