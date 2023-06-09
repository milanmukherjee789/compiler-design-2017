%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	extern int yylineno;
%}
letter [a-zA-Z_]
digit [0-9]
%%
"+" {return ADDITION_TOK;}
"-" {return MINUS_TOK;}
"*" { return MULTIPLICATION_TOK;}
"/" {return DIVISION_TOK;}
"%" {return MODULO_TOK;}
"(" {return LPAREN_TOK;}
")" {return RPAREN_TOK;}
";" {return SEMICOLON_TOK;}
"=" {return EQUAL_TOK;}
"if" {return IF_TOK;}
"else" {return ELSE_TOK;}
"while" {return WHILE_TOK;}
"elseif" {return ELSEIF_TOK;}
"{" {return LCURLY_TOK;}
"}" {return RCURLY_TOK;}
">=" {yylval.c_val = strdup(yytext);return RELATIONAL_TOK;}
">" {yylval.c_val = strdup(yytext);return RELATIONAL_TOK;}
"<=" {yylval.c_val = strdup(yytext);return RELATIONAL_TOK;}
"<" {yylval.c_val = strdup(yytext);return RELATIONAL_TOK;}
"int" {return INTEGER_TOK;}
[\t" "]
[\n] {yylineno++;}
{letter}({letter}|{digit})* { 
	char *temp = strdup(yytext);
	yylval.c_val = (char*)malloc(sizeof(char)*yyleng);
	strncpy(yylval.c_val,temp,yyleng);
	temp = NULL;
	return ID_TOK;}
{digit}+ {
	yylval.i_val = atoi(yytext);
	return INT_CONST_TOK;}
{digit}+({letter}|{digit})* {;}
%%
int yywrap(){return 1;}