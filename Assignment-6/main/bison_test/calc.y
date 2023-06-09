%{
	#define YYSTYPE double
	#include <stdio.h>
	extern FILE *yyin;
	extern int yylex();
%}
%token INT_CONST_TOK
%left MINUS_TOK ADDITION_TOK
%left MULTIPLICATION_TOK DIVISION_TOK
%%
	programme:	
		programme statement
		|
		;
	statement:
		"\n"
		| expression "\n" {printf("the value = %f\n",$1);}
		;
	expression:
		INT_CONST_TOK {$$ = $1;printf("int const %f\n",$1);}
		| expression ADDITION_TOK expression  { $$ = $1 + $3; printf("addition = %f\n",$$);};
		| expression MINUS_TOK expression  { $$ = $1 - $3; printf("minus = %f\n",$$);};
		| expression MULTIPLICATION_TOK expression  { $$ = $1 * $3; printf("multiplication = %f\n",$$);};
		| expression DIVISION_TOK expression  { $$ = $1 / $3; printf("division = %f\n",$$);};

		;

%%
int main(int argc,const char *argv[]){
	yyin = fopen(argv[1],"r");
	yyparse();
	fclose(yyin);
	return 0;
}
void yyerror(char *s){
	printf("%s\n","SORRY some syntax error is there. ........ :(");
}