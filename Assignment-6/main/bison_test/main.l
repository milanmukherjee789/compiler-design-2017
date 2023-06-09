%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
	extern int yylineno;
	extern char *yytext;
	extern double yylval;
%}
digit [0-9]
%%
"+" {return ADDITION_TOK;}
"-" {return MINUS_TOK;}
"*" {return MULTIPLICATION_TOK;}
"/" {return DIVISION_TOK;}
{digit}+ {yylval= atoi(yytext);
			return INT_CONST_TOK;}
%%
int yywrap(){return 1;}