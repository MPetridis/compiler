%{

  #define  SHOW_TOKENS 0
  #include "syntax.tab.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <string.h>
  #include <math.h>

  char string_buffer[256];
  char comment_buffer[256];
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


ID      [A-Za-z][a-zA-Z0-9_]*[a-zA-Z0-9]|[a-zA-Z]
ICONST  [1-9][0-9]*|0[xX][1-9A-Fa-f]*[0-9A-Fa-f]|0[oO][1-7]*[0-7]*|0[Bb][1]*[0-1]*|0
FCONST  (([1-9][0-9]*|0)?\.([0-9]+[1-9]+|[0-9])([eE](\+|-)?([1-9][0-9]*|0))?)|((0|[1-9][0-9]*)([eE](\+|-)?([1-9][0-9]*|0)))|(0[xX]([0-9A-F][0-9A-F]*)?\.([0-9A-F]+))
CCONST  '[\x20-\x7E']'

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


{ID} { print_token(T_ID); yylval.strval=strdup(yytext); return T_ID; }
{ICONST} { print_token(T_ICONST); yylval.intval=str_to_int(yytext); return T_ICONST; }
{FCONST} { print_token(T_FCONST); yylval.doubleval=str_to_float(yytext); return T_FCONST; }
{CCONST} { print_token(T_CCONST); yylval.charval=yytext[1]; return T_CCONST; }

\"                          { strcpy(string_buffer,"");    BEGIN(STRING)   ;}
<STRING>\"                  { BEGIN(INITIAL);              printf("LINE[%d] STRING TOKEN: %s\n",yylineno,string_buffer);yylval.strval=strdup(string_buffer); return T_STRING;}
<STRING>(\\\n|\\\r\n)       { }      
<STRING>(\\.|[^"\\])        {   
                                if(strlen(yytext) == 2){
                                    if(strcmp(yytext,"\\n") == 0){
                                        strcat(string_buffer,"\n");
                                    }else if(strcmp(yytext,"\\t") == 0){
                                        strcat(string_buffer,"\t");
                                    }else if(strcmp(yytext,"\\b") == 0){
                                        strcat(string_buffer,"\b");
                                    }else if(strcmp(yytext,"\\v") == 0){
                                        strcat(string_buffer,"\v");
                                    }else if(strcmp(yytext,"\\f") == 0){
                                        strcat(string_buffer,"\f");
                                    }else if(strcmp(yytext,"\\r") == 0){
                                        strcat(string_buffer,"\r");
                                    }
                                }else{
                                    strcat(string_buffer,yytext);
                                }                                
                            }
<STRING>(\n|\r\n)           { yyerror("New line found wihtout \\.")        ;}
<STRING><<EOF>>             { yyerror("End of string without closing it.") ;}
<STRING>.                   { yyerror("\nUNKNOWN CHARACTER.")              ;}


\/"*"                       { printf("LINE[%d] Comment Found\n",yylineno);  BEGIN(COMMENTS) ;}
<COMMENTS>(\\.|[^\\])       { }
<COMMENTS>"*"\/             { BEGIN(INITIAL);  printf("LINE[%d] Comment Ended \n",yylineno) ;}
"//".*                      { printf("LINE[%d] Comment Found\n",yylineno); }
[ \t\n]                     {}


<<EOF>>                    { print_token(T_EOF); return T_EOF; }
.                          { yyerror("UNKNOWN CHARACTER."); }
%%



void print_token(int token_id) {
    if(SHOW_TOKENS == 0){
        return;
    }
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
    } else if ((strncmp(str, "0o", 2) == 0) || strncmp(str, "0O", 2) == 0) {
        return (int) strtoll(&str[2], NULL, 8);
    } else if ((strncmp(str, "0b", 2) == 0) || strncmp(str, "0B", 2) == 0) {
        return (int) strtoll(&str[2], NULL, 2);
    } else if (str[0] == '0' && str[1] == '\0') {
        return 0;
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
    unsigned int intValue = 0;
    sscanf(&str[2], "%x", &intValue);  
    float floatValue = *((float*)&intValue); 
    return floatValue;
}


void yyerror(const char *err) {
    if (errorCounter < 5) {
        fprintf(stderr, "ERROR: %s on line %d\n", err, yylineno);
        errorCounter++;
    }
    yyless(1);
}