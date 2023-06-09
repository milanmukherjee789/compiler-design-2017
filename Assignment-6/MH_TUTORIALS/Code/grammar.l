%{
#include "language.h"
#include "y.tab.h"
%}
%%
"(" {fprintf(stderr, "yylex() matched LEFT_PAREN.\n"); return LEFT_PAREN;}
"," {fprintf(stderr, "yylex() matched COMM_TOK.\n"); return COMMA_TOK;}
")" {fprintf(stderr, "yylex() matched RIGHT_PAREN.\n"); return RIGHT_PAREN;}
"{" {fprintf(stderr, "yylex() matched OPEN_CURLEY.\n"); return OPEN_CURLY;}
"}" {fprintf(stderr, "yylex() matched CLOSE_CURLEY.\n"); return CLOSE_CURLY;}
[A-Z] {fprintf(stderr, "yylex() matched NON_TERMINAL.\n"); yylval.charval = yytext[0]; return NON_TERMINAL_TOK;}
[a-z] {fprintf(stderr, "yylex() matched TERMINAL.\n"); yylval.charval = yytext[0]; return TERMINAL_TOK;}
"->" {fprintf(stderr, "yylex() matched RIGHT_ARROW.\n"); return RIGHT_ARROW_TOK;}

%%
int yywrap(void) {
	return 1;
}
