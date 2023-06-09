%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "tok.h"
	extern yy_size_t yyleng;
	extern char* yytext;
	int tok_index = 0;
	int comment_line = 0;
	int flag = 1;
	extern int yylineno;
%}
letter [a-zA-Z_]
digit [0-9]
quote ["'"]
start ["/*"]
end ["*/"]
%%
"for" {printf("token = %s line no = %d\n",yytext,yylineno); return FOR_TOK;}
"while" {printf("token = %s line no = %d\n",yytext,yylineno); return WHILE_TOK;}
"switch" {printf("token = %s line no = %d\n",yytext,yylineno); return SWITCH_TOK;}
"case" {printf("token = %s line no = %d\n",yytext,yylineno); return CASE_TOK;}
"if" {printf("token = %s line no = %d\n",yytext,yylineno); return IF_TOK;}
"else" {printf("token = %s line no = %d\n",yytext,yylineno); return ELSE_TOK;}
"int" {printf("token = %s line no = %d\n",yytext,yylineno); return INTEGER_TOK;}
"float" {printf("token = %s line no = %d\n",yytext,yylineno); return FLOATING_TOK;}
"double" {printf("token = %s line no = %d\n",yytext,yylineno); return DOUBLE_TOK;}
"char" {printf("token = %s line no = %d\n",yytext,yylineno); return CHAR_TOK;}
"break" {printf("token = %s line no = %d\n",yytext,yylineno); return BREAK_TOK;}
"default" {printf("token = %s line no = %d\n",yytext,yylineno); return DEFAULT_TOK;}
"return" {printf("token = %s line no = %d\n",yytext,yylineno); return RETURN_TOK;}
"#include" {printf("token = %s line no = %d\n",yytext,yylineno); return INCLUDE_TOK;}
"#define" {printf("token = %s line no = %d\n",yytext,yylineno); return DEFINE_TOK;}
"//". {printf("Single line comment ignoring....... :(\n");}
"/*"(.|\n)*"*/"  {printf("Multiline Comment Ignoring ........ :(%d\n",yylineno);comment_line = yylineno-1,flag = 1;};
";" {printf("token = %s\n",yytext); return SEMICOLON_TOK;}
"," {printf("token = %s lineno = %d\n",yytext,yylineno); return COMMA_TOK;}
"." {printf("token = %s lineno = %d\n",yytext,yylineno); return DOT_TOK;}
"{" {printf("token = %s lineno = %d\n",yytext,yylineno); return LCURLY_TOK;}
"}" {printf("token = %s lineno = %d\n",yytext,yylineno); return RCURLY_TOK;}
"(" {printf("token = %s lineno = %d\n",yytext,yylineno); return LPAREN_TOK;}
")" {printf("token = %s lineno = %d\n",yytext,yylineno); return RPAREN_TOK;}
"[" {printf("token = %s lineno = %d\n",yytext,yylineno); return ARRAY_BRACKET_LTOK;}
"]" {printf("token = %s lineno = %d\n",yytext,yylineno); return  ARRAY_BRACKET_RTOK;}
"++" {printf("token = %s lineno = %d\n",yytext,yylineno); return INCREMENT_TOK;}
"+=" {printf("token = %s lineno = %d\n",yytext,yylineno); return ADDITION_EQUAL_TOK;}
"+" {printf("token = %s lineno = %d\n",yytext,yylineno); return ADDITION_TOK;}
"--" {printf("token = %s lineno = %d\n",yytext,yylineno); return DECREMENT_TOK;}
"-=" {printf("token = %s lineno = %d\n",yytext,yylineno); return MINUS_EQUAL_TOK;}
"-" {printf("token = %s lineno = %d\n",yytext,yylineno); return MINUS_TOK;}
"*=" {printf("token = %s lineno = %d\n",yytext,yylineno); return MULTIPLICATION_EQUAL_TOK;}
"*" {printf("token = %s lineno = %d\n",yytext,yylineno); return MULTIPLICATION_TOK;}
"/=" {printf("token = %s lineno = %d\n",yytext,yylineno); return DIVISION_EQUAL_TOK;}
"/" {printf("token = %s lineno = %d\n",yytext,yylineno); return DIVISION_TOK;}
"%=" {printf("token = %s lineno = %d\n",yytext,yylineno); return MODULO_EQUAL_TOK;}
"%" {printf("token = %s lineno = %d\n",yytext,yylineno); return MODULO_TOK;}
">>" {printf("token = %s lineno = %d\n",yytext,yylineno); return RIGHT_SHIFT_TOK;}
">=" {printf("token = %s lineno = %d\n",yytext,yylineno); return GREATER_THAN_EQUAL_TOK;}
">" {printf("token = %s lineno = %d\n",yytext,yylineno); return GREATER_TOK;}
"<<" {printf("token = %s lineno = %d\n",yytext,yylineno); return LEFT_SHIFT_TOK;}
"<=" {printf("token = %s lineno = %d\n",yytext,yylineno); return LESS_THAN_EQUAL_TOK;;}
"<" {printf("token = %s lineno = %d\n",yytext,yylineno); return LESS_TOK;}
"==" {printf("token = %s lineno = %d\n",yytext,yylineno); return EQUAL_COMPARE_TOK;}
"=" {printf("token = %s lineno = %d\n",yytext,yylineno); return EQUAL_TOK;}
"!=" {printf("token = %s lineno = %d\n",yytext,yylineno); return NOT_EQUAL_TOK;}
"!" {printf("token = %s lineno = %d\n",yytext,yylineno); return NOT_TOK;}
"||" {printf("token = %s lineno = %d\n",yytext,yylineno); return OR_TOK;}
"|=" {printf("token = %s lineno = %d\n",yytext,yylineno); return BIT_OR_EQUAL_TOK;}
"|" {printf("token = %s lineno = %d\n",yytext,yylineno); return BIT_OR_TOK;}
"&&" {printf("token = %s lineno = %d\n",yytext,yylineno); return AND_TOK;}
"&=" {printf("token = %s lineno = %d\n",yytext,yylineno); return BIT_AND_EQUAL_TOK;}
"&" {printf("token = %s lineno = %d\n",yytext,yylineno); return BIT_AND_TOK;}
" " {printf("token = %s(space) lineno = %d\n",yytext,yylineno); return SPACE_TOK;}
":" {printf("token = %s lineno = %d\n",yytext,yylineno); return COLON_TOK;}
[\t]
[\n] {yylineno++;}
{letter}({letter}|{digit})* {printf("token = %s\n",yytext); return ID_TOK;}
{digit}+ {printf("token = %s\n",yytext); return INT_CONST_TOK;}
{digit}+({letter}|{digit})* {return -1;}
%%
int main(int argc,const char* argv[]){
	int parsed_token = -1;
	if (argc < 2){
		printf("No Input File\n");
		return -1;
	}
	yyin = fopen(argv[1],"r");
	while((parsed_token = yylex()) > 0){
		//printf("Token of above word = %d\n",parsed_token);
	}
	printf("Token generation Has been completed. Following are the generated tokens ... :)\n");
	printf("comment line = %d\n",comment_line);
}	
int yywrap(){return 1;}
