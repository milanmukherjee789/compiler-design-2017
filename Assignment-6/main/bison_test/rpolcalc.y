%{
	#define YYSTYPE double
	#include <stdio.h>
	extern FILE *yyin;
	extern int yylex();
%}
%token INT_CONST_TOK ADDITION_TOK MINUS_TOK MULTIPLICATION_TOK DIVISION_TOK
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
		| expression expression ADDITION_TOK { $$ = $1 + $2; printf("addition = %f\n",$$);};
		| expression expression MINUS_TOK { $$ = $1 - $2; printf("minus = %f\n",$$);};
		| expression expression MULTIPLICATION_TOK { $$ = $1 * $2; printf("multiplication = %f\n",$$);};
		| expression expression DIVISION_TOK { $$ = $1 / $2; printf("division = %f\n",$$);};

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