%{
  #include "lexer.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <string.h>
  #include <math.h>

  char string_buffer[256];
  int errorCounter = 0;

  void print_token(int token_id);
  int str_to_int(char *str);
  float hex_to_float(char *str);
  float str_to_float(char *str);
  void yyerror(const char *err);
%}

%option noyywrap 
%option case-insensitive
%option yylineno

%x STRING
%x COMMENTS

ID      ^[a-zA-Z]([a-zA-Z0-9_]*[a-zA-Z0-9]|[a-zA-Z0-9]*)
ICONST  ^[1-9][0-9]*|^0X[^0A-Fa-f][0-9A-Fa-f]*|^0O[^0][0-7]*|^0[b|B][^0][0-7]*|0
FCONST  ^(0|[1-9][0-9]*)\.[0-9]*[1-9](E[+-]?[0-9]+)?$|^([1-9][0-9]*)\.(0*[1-9][0-9]*)(E[+-]?[0-9]+)$
CCONST  '[^']*'

%%
"TYPEDEF" { print_token(T_TYPEDEF); return T_TYPEDEF; }
"CHAR" { print_token(T_CHAR); return T_CHAR; }
"INT" { print_token(T_INT); return T_INT; }
"FLOAT" { print_token(T_FLOAT); return T_FLOAT; }
"ENUM" { print_token(T_ENUM); return T_ENUM; }
"CLASS" { print_token(T_CLASS); return T_CLASS; }
"PRIVATE" { print_token(T_PRIVATE); return T_PRIVATE; }
"PROTECTED" { print_token(T_PROTECTED); return T_PROTECTED; }
"PUBLIC" { print_token(T_PUBLIC); return T_PUBLIC; }
"VOID" { print_token(T_VOID); return T_VOID; }
"STATIC" { print_token(T_STATIC); return T_STATIC; }
"CONTINUE" { print_token(T_CONTINUE); return T_CONTINUE; }
"BREAK" { print_token(T_BREAK); return T_BREAK; }
"THIS" { print_token(T_THIS); return T_THIS; }
"IF" { print_token(T_IF); return T_IF; }
"ELSE" { print_token(T_ELSE); return T_ELSE; }
"WHILE" { print_token(T_WHILE); return T_WHILE; }
"FOR" { print_token(T_FOR); return T_FOR; }
"SWITCH" { print_token(T_SWITCH); return T_SWITCH; }
"CASE" { print_token(T_CASE); return T_CASE; }
"DEFAULT" { print_token(T_DEFAULT); return T_DEFAULT; }
"RETURN" { print_token(T_RETURN); return T_RETURN; }
"CIN" { print_token(T_CIN); return T_CIN; }
"COUT" { print_token(T_COUT); return T_COUT; }
"LENGTH" { print_token(T_LENGTH); return T_LENGTH; }
"MAIN" { print_token(T_MAIN); return T_MAIN; }

"||"  { print_token(T_OROP); return T_OROP; }
"&&"  { print_token(T_ANDOP); return T_ANDOP; }
"=="  { print_token(T_EQUOP); return T_EQUOP; }
"!="  { print_token(T_EQUOP); return T_EQUOP; }
">"  { print_token(T_RELOP); return T_RELOP; }
">="  { print_token(T_RELOP); return T_RELOP; }
"<"  { print_token(T_RELOP); return T_RELOP; }
"<="  { print_token(T_RELOP); return T_RELOP; }
"+"  { print_token(T_ADDOP); return T_ADDOP; }
"-"  { print_token(T_ADDOP); return T_ADDOP; }
"*"  { print_token(T_MULOP); return T_MULOP; }
"/"  { print_token(T_MULOP); return T_MULOP; }
"%"  { print_token(T_MULOP); return T_MULOP; }
"!"  { print_token(T_NOTOP); return T_NOTOP; }
"++"  { print_token(T_INCDEC); return T_INCDEC; }
"--"  { print_token(T_INCDEC); return T_INCDEC; }
"SIZEOF" { print_token(T_SIZEOP); return T_SIZEOP; }

"("   {print_token(T_LPAREN); return T_LPAREN;}
")"   {print_token(T_RPAREN); return T_RPAREN;}
";"   {print_token(T_SEMI); return T_SEMI;}
"."   {print_token(T_DOT); return T_DOT;}
","   {print_token(T_COMMA); return T_COMMA;}
"="   {print_token(T_ASSIGN); return T_ASSIGN;}
":"   {print_token(T_COLON); return T_COLON;}
"["   {print_token(T_LBRACK); return T_LBRACK;}
"]"   {print_token(T_RBRACK); return T_RBRACK;}
"&"   {print_token(T_REFER); return T_REFER;}
"{"   {print_token(T_LBRACE); return T_LBRACE;}
"}"   {print_token(T_RBRACE); return T_RBRACE;}
"::"   {print_token(T_METH); return T_METH;}
">>"   {print_token(T_INP); return T_INP;}
"<<"   {print_token(T_OUT); return T_OUT;}

{ID} { print_token(T_ID); return T_ID; }
{ICONST} { print_token(T_ICONST); return T_ICONST; }
{FCONST} { print_token(T_FCONST); return T_FCONST; }
{CCONST} { print_token(T_CCONST); return T_CCONST; }

[ \t]              { }
\n                 { }

<<EOF>> { print_token(T_EOF); return T_EOF; }
.      { yyerror("UNKNOWN CHARACTER."); }
%%

int main(int argc, char *argv[]) {
    int token;
    if(argc > 1){
        yyin = fopen(argv[1],"r");
        if(yyin == NULL){
            perror ("Error opening file");
            return -1;
        }
    }

    do{
        token = yylex();
    } while(token != T_EOF);

    fclose(yyin);
    yyterminate();

    return 0;
}

void print_token(int token_id) {
    if (token_id == T_ICONST) {
        printf("LINE[%d] INTEGER TOKEN '%s'. Base 10: %d token id: %d\n", yylineno, yytext, str_to_int(yytext), token_id);
    } else if (token_id == T_FCONST) {
        printf("LINE[%d] FLOAT TOKEN '%s'. Base 10: %f token id: %d\n", yylineno, yytext, str_to_float(yytext), token_id);
    } else {
        printf("LINE[%d] TOKEN '%s' (%d)\n", yylineno, yytext, token_id);
    }
}

int str_to_int(char *str) {
    if ((strncmp(str, "0x", 2) == 0) || strncmp(str, "0X", 2) == 0) {
        return (int) strtoll(&str[2], NULL, 16);
    } else {
        return (int) strtoll(str, NULL, 10);
    }
}

float str_to_float(char *str) {
    if ((strncmp(str, "0x", 2) == 0) || strncmp(str, "0X", 2) == 0) {
        return hex_to_float(str);
    } else {
        return strtof(str, NULL);
    }
}

float hex_to_float(char *str) {
    // Implement hexadecimal float conversion here if needed
    return 0.0;
}

void yyerror(const char *err) {
    if (errorCounter < 5) {
        fprintf(stderr, "ERROR: %s on line %d\n", err, yylineno);
        errorCounter++;
    }
}

/* int main(int argc,char *argv[]) {

    int token;
    if(argc > 1){
        yyin = fopen(argv[1],"r");
        if(yyin == NULL){
            perror ("Error opening file");
            return -1;
        }
    }

    do{
        token = yylex();
    } while(token != T_EOF);

    fclose(yyin);
    yyterminate();

    return 0;
}

void print_token(int token_id){

    if(token_id == T_ICONST){

        printf("LINE[%d] INTEGER TOKEN \'%s\'.Base 10: %d token id:%d\n",yylineno,yytext,str_to_int(yytext),token_id);

    }else if(token_id == T_RCONST){ 

        printf("LINE[%d] FLOAT TOKEN \'%s\'.Base 10: %f token id:%d\n",yylineno,yytext,str_to_float(yytext),token_id);

    }else{
        printf("LINE[%d] TOKEN \'%s\' (%d)\n",yylineno,yytext,token_id);
    }
}

int str_to_int(char *str){

    if((strncmp(str,"0x",2) == 0) || strncmp(str,"0X",2) == 0){
        return (int) strtoll(&str[2],NULL,16);
    }else{
        return (int) strtoll(str,NULL,10);
    }

}

float str_to_float(char *str){

    if((strncmp(str,"0x",2) == 0) || strncmp(str,"0X",2) == 0){
        return hex_to_float(str);
    }else{
        return (float) strtof(str, NULL);
    }

}

void yyerror(const char *err){
    
    errorCounter += 1;
    printf("[ERROR - LINE %d] %s\n",yylineno,err);

    if(errorCounter == 5){
        printf("MAXIMUM NUMBER OF ERRORS DETECTED\n");
        exit(EXIT_FAILURE);
    }

    //prospatheia sbhsimo lanthasmenou xaraktira
    yyless(1);
} */