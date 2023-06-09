%{
	#include<stdlib.h>
	#include<string.h>
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include "language.h"
	#define MAX_DERIVATION_STEPS 10
	#define _debug true
	#define true 1
	#define _debugPrint(s) if(_debug) fprintf(stderr,"%s",s)

	int derivationStep = 0;
	char _debugString[1000];
	char _derivationString[1000];
	void generateString(GRAMMAR *g);
	SYMBOL* applyProdRule(SYMBOL *head, GRAMMAR *g);
	STARTEND  duplicateSymbolString(SYMBOL *rhs);
	int isNT(SYMBOL *s, GRAMMAR *g);
	void freeString(STARTEND se);
	GRAMMAR *g;
	extern FILE *yyin;
	int yyerror(char *s);
	int yylex();
	extern char yytext[];
	FILE *grammarOutFile;
	void printGrammar(GRAMMAR *g);
	void printGrammarRuleInString(RULE *r, char str[]);
	void printStringInString(SYMBOL *s, char str[]);
%}

%union {
	char charval;
	SYMBOL *tsymbolP;
	SYMBOL *ntsymbolP;
	RULE *ruleP;
	GRAMMAR *grammarP;
}

%start g
%token <charval> TERMINAL_TOK N_T_TOK
%token LEFT_PAREN COMMA_TOK RIGHT_PAREN OPEN_CURLY CLOSE_CURLY RIGHT_ARROW_TOK
%type <tsymbolP> sigma t_symbol_list t_symbol terminal_string
%type <ntsymbolP> v nt_symbol_list start nt_symbol lhs rhs non_terminal
%type <ruleP> rules rule_list rule
%type <grammarP> g
%%

g: LEFT_PAREN v COMMA_TOK sigma COMMA_TOK rules COMMA_TOK start RIGHT_PAREN {
	GRAMMAR *grammar1;
	fprintf(stderr, "g: LEFT_PAREN v COMMA_TOK sigma COMMA_TOK rules COMMA_TOK start RIGHT_PAREN.\n");
	grammar1 = (GRAMMAR *) malloc(sizeof(GRAMMAR));
	grammar1->v = $2;
	grammar1->sigma = $4;
	grammar1->r = $6;
	grammar1->s = $8;
	g = grammar1;
	};
v: OPEN_CURLY nt_symbol_list CLOSE_CURLY {
	fprintf(stderr, "v: OPEN_CURLY nt_symbol_list CLOSE_CURLY.\n");
	$$ = $2;
	};
t_symbol_list: t_symbol {
	fprintf(stderr, "t_symbol_list: t_symbol.\n");
	$$ = $1;
	}
	| t_symbol_list COMMA_TOK t_symbol {
	SYMBOL *temp;
        temp = $1;
        while(temp->next != NULL)
                temp = temp->next;
        temp->next = $3;
        $3->prev = temp;
        $$ = $1;
	};
nt_symbol_list: nt_symbol {
	$$ = $1;
	}
	| nt_symbol_list COMMA_TOK nt_symbol {
	SYMBOL *temp;
	temp = $1;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = $3;
	$3->prev = temp;
	$$ = $1;
	};
t_symbol: TERMINAL_TOK { 
	SYMBOL *symbol1;
	symbol1 = (SYMBOL *) malloc(sizeof(SYMBOL));
	symbol1->data = $1;
	symbol1->next = NULL;
	symbol1->prev = NULL;
	$$ = symbol1;
	};
nt_symbol: N_T_TOK { 
	SYMBOL *symbol1;
	symbol1 = (SYMBOL *) malloc(sizeof(SYMBOL));
	symbol1->data = $1;
	symbol1->next = NULL;
	symbol1->prev = NULL;
	$$ = symbol1;
	};
sigma: OPEN_CURLY t_symbol_list CLOSE_CURLY {
	$$ = $2;
	};
rules: OPEN_CURLY rule_list CLOSE_CURLY {
	$$ = $2;
	};
rule_list: rule {
	$$ = $1;
	}
	| rule_list COMMA_TOK rule {
	RULE *temp;
        temp = $1;
        while(temp->next != NULL)
                temp = temp->next;
        temp->next = $3;
        $3->prev = temp;
        $$ = $1;
	};
rule: lhs RIGHT_ARROW_TOK rhs {
	RULE *rule1;
	rule1 = (RULE *) malloc(sizeof(RULE));
	rule1->lhs = $1;
	rule1->rhs = $3;
	rule1->next = NULL;
	rule1->prev = NULL;
	$$ = rule1;
	};
lhs: nt_symbol {
	$$ =$1;
	};
rhs: terminal_string non_terminal {
	SYMBOL *temp;
        temp = $1;
        while(temp->next != NULL)
                temp = temp->next;
        temp->next = $2;
        $2->prev = temp;
        $$ = $1;
	}
	| terminal_string {
	$$ = $1;
	};
terminal_string: t_symbol { 
	$$ = $1;
	}
	|terminal_string t_symbol { 
	SYMBOL *temp;
        temp = $1;
        while(temp->next != NULL)
                temp = temp->next;
        temp->next = $2;
        $2->prev = temp;
        $$ = $1;
	}
	;
non_terminal: nt_symbol {
	$$ = $1;
	};
start: nt_symbol{
	$$ = $1;
	};
%%
int yyerror(char *s) {
	fprintf(stderr,"%s\n",s);
	return 0;
}
int main(int argc, char *argv[]) {
	int i;
	
	char errorMessage[MSG_LENGTH];
	if (argc < 3) {
                fprintf(stderr, "Usage: %s -g <grammar file>.\n", argv[0]);
                exit(1);
        }
	for (i = 1; i<argc && strcmp(argv[i], "-g") != 0; i++);

        if (i >= argc-1) {
                fprintf(stderr, "Usage: %s -g <grammar file>.\n", argv[0]);
                exit(1);
        }
	yyin = fopen(argv[i+1], "r");
	if (yyin == NULL) {
                sprintf(errorMessage, "Cannot open file %s ", argv[i+1]);
                perror(errorMessage);
        }
	if(argc == 4) {
		grammarOutFile = fopen(argv[3], "w+");
		if(grammarOutFile == NULL) {
			sprintf(errorMessage, "Cannot open file %s ", argv[3]);
	                perror(errorMessage);
			printf("printing the grammar to stdout");
			grammarOutFile = stdout;
		}
	}
	else
		grammarOutFile = stdout;
	
	yyparse();

	getchar();
	fclose(yyin);
	printGrammar(g);
	fprintf(grammarOutFile, "\n");
        generateString(g);
	fclose(grammarOutFile);
	return 0;
}

void printGrammar(GRAMMAR *g) {
	SYMBOL *s1, *s2;
	RULE *r;
	char ruleString[100];
	fprintf(grammarOutFile,"(");
	fprintf(grammarOutFile,"{");
	s1 = g->v;
	while(1) {
		if(s1->next == NULL) {
			fprintf(grammarOutFile,"%c", s1->data);
			break;
		}
		fprintf(grammarOutFile,"%c,", s1->data);
		s1 = s1->next;
	}
	fprintf(grammarOutFile,"}");
	fprintf(grammarOutFile,",");
	fprintf(grammarOutFile,"{");
	s1 = g->sigma;
        while(1) {
                if(s1->next == NULL) {
                        fprintf(grammarOutFile,"%c", s1->data);
                        break;
                }
                fprintf(grammarOutFile,"%c,", s1->data);
                s1 = s1->next;
        }
	fprintf(grammarOutFile,"}");
	fprintf(grammarOutFile,",");
	fprintf(grammarOutFile,"{");
	r = g->r;
	while(r != NULL) {
		
		printGrammarRuleInString(r, ruleString);
                fprintf(grammarOutFile,"%s", ruleString);
		if(r->next != NULL)
			fprintf(grammarOutFile,",");
		r = r->next;
	}
	fprintf(grammarOutFile,"}");
        fprintf(grammarOutFile,",");
	fprintf(grammarOutFile,"%c", g->s->data);
	fprintf(grammarOutFile,")");
}

void printGrammarRuleInString(RULE *r, char str[]) {
	SYMBOL *s1;
	SYMBOL *s2;
	char tempStr[2];
	s1 = r->lhs;
	s2 = r->rhs;
	str[0] = '\0';
	tempStr[1] = '\0';
	while(s1 != NULL) {
		tempStr[0] = s1->data;
		strcat(str, tempStr);
                s1 = s1->next;
       	}
	strcat(str," -> ");
	while(s2 != NULL) {
		tempStr[0] = s2->data;
		strcat(str, tempStr);
                s2 = s2->next;
       	}
}
void generateString(GRAMMAR *g) {
	SYMBOL *head;
	/* start the derivation with the starting nonterminal of the grammar */
	head = (SYMBOL *) malloc(sizeof(SYMBOL));
	*head = *(g->s);
	head->prev = head->next = NULL;
	printStringInString(head, _derivationString);
        sprintf(_debugString, "Starting the Derivation with %s.\n", _derivationString);
        _debugPrint(_debugString);

	head = applyProdRule(head, g);

	//printStringInString(start, _derivationString);
        //sprintf(_debugString, "AFTER FINAL RETURN TO generateString()\nDerivation string is %s.\n", _derivationString);
        //_debugPrint(_debugString);
}

SYMBOL* applyProdRule(SYMBOL *head, GRAMMAR *g) {
	char output[200];
	RULE *r;
	SYMBOL *temp;
	int matchNT = 0;
	
	if (derivationStep >= MAX_DERIVATION_STEPS) return head;

	temp  = head;
	while(temp != NULL) {
		/* Find out the 1st Nonterminal */
		if((matchNT = isNT(temp, g)) == 1) {
			/* Now temp points to a nonterminal */
			/* All the matching grammar rules will be applied on this nonterminal */
			r = g->r;
			while(r != NULL) {

				/* Find out a grammar rule whose lhs matches with *temp */
				if(temp->data == r->lhs->data) {
					STARTEND se;
					char ruleString[100];


					/* a grammar rule found with matching lhs */

					/* Debug: printing the present derivation */
					printStringInString(head, _derivationString);
					sprintf(_debugString, "BEFORE INSERTING RHS\nDerivation string is %s.\n", _derivationString);
					_debugPrint(_debugString);

					/* Debug: printing the chosen grammar rule */
					printGrammarRuleInString(r, ruleString);
					sprintf(_debugString, "%d. Applying Grammar Rule '%s'.\n", derivationStep, ruleString);
					_debugPrint(_debugString);


					/* duplicate the rule's  rhs  */
					se = duplicateSymbolString(r->rhs);

					/* insert the rhs in place of the nonterminal */
					se.end->next = temp->next;
					if (temp->next != NULL) {
						temp->next->prev = se.end;
					}

					/* if temp points to the first symbol of the string */
					if(temp->prev == NULL) {
						head = se.start;
					} else {
						temp->prev->next = se.start;
						se.start->prev = temp->prev;
					}
					derivationStep++;

					/* Debug: printing */
                                        printStringInString(head, _derivationString);
                                        sprintf(_debugString, "AFTER INSERTING RHS\nDerivation string is %s.\n\n", _derivationString);
                                        _debugPrint(_debugString);

					/* go for the next derivation step */
					head = applyProdRule(head, g);

					/* Debug: printing */
                                        _debugPrint("recursive call to applyProdRule() returns.\n");
                                        printStringInString(head, _derivationString);
                                        sprintf(_debugString, "AFTER RETURNING Derivation string is %s.\n", _derivationString);
                                        _debugPrint(_debugString);

					/* attach temp(nonterminal) back to string, that is detaching rhs(se) */

                                        _debugPrint("Choosing the next possible grammar rule for derivation.\n");
					/* if temp points to the 1st symbol of the derivation string */
					if(temp->prev == NULL) {
						head = temp;
					} else {
						temp->prev->next = temp;
					}
					if (temp->next != NULL)
						temp->next->prev = temp;

					/* Debug: print the derivation string after undoing the present application of grammar rule */
                                        printStringInString(head, _derivationString);
                                        sprintf(_debugString, "AFTER undoing privious application of GR the derivation string is %s.\n", _derivationString);
                                        _debugPrint(_debugString);

					//getchar(); /* pause for a moment */
					/* let us apply the next applicable grammar rule (if any) */
					/* free the duplicated rhs of the last rule */
					freeString(se);
					derivationStep--;
				}
				r = r->next;
			}


			/* the above does all possible expansions of the present non-terminal
			   let us try not to expand this nonterminal now rather try with next ones.
			*/
			/* connect this nonterminal back to the derivation string */
			if (temp->prev != NULL) temp->prev->next = temp; 
			if (temp->next != NULL) temp->next->prev = temp;
		}
		//sprintf(_debugString, "TEMP POINTING TO : %c.\n", temp->data);
	        //_debugPrint(_debugString);
		temp = temp->next;
	}
	printStringInString(head, output);
	fprintf(grammarOutFile,"%s\n", output);
	sprintf(_debugString, "Wrote to output file: %s.\n", output);
	_debugPrint(_debugString);
	//sprintf(_debugString, "head is :%c.\n",head->data);
        //_debugPrint(_debugString);
	return head;
}

void printStringInString(SYMBOL *s, char str[]) {
	int i=0;
	while(s!= NULL) {
		str[i++] = s->data;
		s = s->next;
	}
	str[i] = '\0';
}
void freeString(STARTEND se) {
	SYMBOL *temp1;
	SYMBOL *temp2;
	SYMBOL *temp3;
	temp1 = se.start;
	temp3 = se.end;
	if (temp1 == NULL) return;
	while(temp1 != temp3) {
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	free(temp3);
}
int isNT(SYMBOL *s, GRAMMAR *g) {
	SYMBOL *temp;
	temp = g->v;
	while(temp != NULL) {
		if(s->data == temp->data) {
			sprintf(_debugString, "matched NT : %c.\n",temp->data);
                        _debugPrint(_debugString);
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

STARTEND  duplicateSymbolString(SYMBOL *rhs) {
	STARTEND se;
	SYMBOL *grhs, *temp1;
	se.start = NULL;
	se.end = NULL;
	if (rhs == NULL) return se;

	se.start = grhs = (SYMBOL *) malloc(sizeof(SYMBOL));
        *grhs = *rhs;
	grhs->prev = NULL;
	grhs->next = NULL;

	temp1 = grhs;

	while( rhs->next != NULL) {
		temp1->next = (SYMBOL *) malloc(sizeof(SYMBOL));
		*(temp1->next) = *(rhs->next);
		temp1->next->prev = temp1;
		temp1->next->next = NULL;

		rhs = rhs->next;
		temp1 = temp1->next;
	}
	se.end = temp1;
	return se;
}
