%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int yylex(void);
	extern FILE *yyin;
	struct expression_type{
		char *code;
		char *address;
	};
	int temporary_var = 1;
	int label_var = 1;
	char *bool,*stat,*begin_label1,*begin_label2;
	struct expression_type *return_exp;
	char* gen_var(void){
		char *temp = (char*)malloc(sizeof(char) * 20);
		char *t = (char *)malloc(10);
		temp[0] = 't';
		snprintf(t,10,"%d",temporary_var);
		strcat(temp,t);
		temporary_var++;
		return temp;
	}
	char* gen_label_var(void){
		char *temp = (char*)malloc(sizeof(char) * 20);
		char *t = (char *)malloc(10);
		temp[0] = 'L';
		snprintf(t,10,"%d",label_var);
		strcat(temp,t);
		label_var++;
		return temp;
	}
	void deallocate_mem(void){
		free(return_exp);
	}	
%}

%union{
	int i_val;
	char *c_val;
	struct expression_type *exp_type;
}
%start programe
%token <i_val> INT_CONST_TOK
%token <c_val> ID_TOK ELSE_TOK WHILE_TOK LPAREN_TOK RPAREN_TOK LCURLY_TOK RCURLY_TOK IF_TOK INTEGER_TOK ELSEIF_TOK
%token <c_val>  EQUAL_TOK SEMICOLON_TOK RELATIONAL_TOK
%type <c_val> programe  statement statement_block boolean_val declaration identifier
%type <exp_type> expression actual_statement

%left OR_TOK
%left AND_TOK
%left NOT_TOK
%left RELATIONAL_TOK
%right EQUAL_TOK
%left ADDITION_TOK MINUS_TOK
%left MULTIPLICATION_TOK DIVISION_TOK MODULO_TOK

%%
	programe:
		function {
			printf("Successfully parsed\n");
			deallocate_mem();
		}
		;

	function:
		function actual_statement {printf("\t\t THREE ADDRESS CODE : \n%s\n",$2->code);}
		| 
		;

	actual_statement:
		WHILE_TOK LPAREN_TOK boolean_val RPAREN_TOK statement_block {
			bool = $3;
			stat = $5;
			begin_label1 = gen_label_var();
			begin_label2 = gen_label_var();
			char *pos = strstr(bool,"TRUE");
			if(pos != NULL){
				strncpy(pos,begin_label2,strlen(begin_label2));
				strncpy(pos+strlen(begin_label2),"    ",(4 - strlen(begin_label2)));
			}
			pos = strstr(bool,"FALSE");
			if (pos != NULL){
				strncpy(pos,"NEXT ",5);
			}
			pos = strstr(stat,"NEXT");
			if (pos != NULL){
				strncpy(pos,begin_label1,strlen(begin_label1));
				strncpy(pos+strlen(begin_label1),"     ",(5 - strlen(begin_label1)));
			}
			char *var = (char *)malloc(strlen(bool) + strlen(stat) + 13 + 2 * strlen(begin_label1) + strlen(begin_label2));
			strcat(var,begin_label1);
			strcat(var," : ");
			strcat(var,bool);
			strcat(var,"\n");
			strcat(var,begin_label2);
			strcat(var," : ");
			strcat(var,stat);
			strcat(var,"\n");
			strcat(var,"goto ");
			strcat(var,begin_label1);
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(2);
			return_exp->address[0] = 'X';
			return_exp->code = (char *)malloc(sizeof(char) * strlen(var));
			strncpy(return_exp->code,var,strlen(var));
			$$ = return_exp;
		}
		| IF_TOK LPAREN_TOK boolean_val RPAREN_TOK statement_block {
			bool = $3;
			stat = $5;
			begin_label1 = gen_label_var();
			char *pos = strstr(bool,"TRUE");
			if (pos != NULL){
				strncpy(pos,begin_label1,strlen(begin_label1));
				strncpy(pos+strlen(begin_label1),"    ",(4 - strlen(begin_label1)));
			}
			pos = strstr(bool,"FALSE");
			if (pos != NULL){
				strncpy(pos,"NEXT ",5);
			}
			char *var = (char *)malloc(strlen(bool)+strlen(stat) + 4 + strlen(begin_label1));
			strcat(var,bool);
			strcat(var,"\n");
			strcat(var,begin_label1);
			strcat(var," : ");
			strcat(var,stat);
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(2);
			return_exp->address[0] = 'X';
			return_exp->code = (char *)malloc(sizeof(char) * strlen(var));
			strncpy(return_exp->code,var,strlen(var));
			$$ = return_exp;
		}
		| IF_TOK LPAREN_TOK boolean_val RPAREN_TOK statement_block ELSE_TOK statement_block {
			bool = $3;
			begin_label1 = gen_label_var();
			char *pos = strstr (bool,"TRUE");		
			if(pos!=NULL){
				strncpy (pos,begin_label1,strlen(begin_label1));
				strncpy (pos+strlen(begin_label1),"    ",(4-strlen(begin_label1)));
			}
			begin_label2 = gen_label_var();
			pos = strstr (bool,"FALSE");
			if(pos!=NULL){
				strncpy (pos,begin_label2,strlen(begin_label2));
				strncpy (pos+strlen(begin_label2),"     ",(5-strlen(begin_label2)));
			}
			char *var = (char *)malloc(strlen(bool)+strlen($5)+strlen($7) + 18 + strlen(begin_label1) + strlen(begin_label2));
			strcat(var,bool);
			strcat(var,"\n");
			strcat(var,begin_label1);
			strcat(var," : ");
			strcat(var,$5);
			strcat(var,"\n");
			strcat(var,"goto NEXT");
			strcat(var,"\n");
			strcat(var,begin_label2);
			strcat(var," : ");
			strcat(var,$7);
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(2);
			return_exp->address[0] = 'X';
			return_exp->code = (char *)malloc(sizeof(char) * strlen(var));
			strncpy(return_exp->code,var,strlen(var));
			$$ = return_exp;
		}
		| expression SEMICOLON_TOK { $$ = $1;}
		| declaration SEMICOLON_TOK {
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(20);
			return_exp->address = $1;
			return_exp->code = (char *)malloc(2);
			return_exp->code[0] = 0;
			$$ = return_exp;
		}
		| declaration EQUAL_TOK expression SEMICOLON_TOK {
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(20);
			return_exp->address = gen_var();
			char *var = (char *)malloc(20);
			strcat(var,$1);
			strcat(var,"=");
			strcat(var,$3->address);
			char *temp = (char *)malloc(strlen($1) + strlen($3->code) + strlen(var) + 2);
			if ($3->code[0] != 0){
				strcat(temp,$3->code);
				strcat(temp,"\n");
			}
			strcat(temp,var);
			return_exp->code = temp;
			$$ = return_exp;
		}
		;
	statement_block:
		LCURLY_TOK statement RCURLY_TOK { $$ = $2;}
		;

	statement:
		actual_statement { $$ = $1->code; }
		| statement actual_statement {
			char *ret = (char *)malloc(strlen($1) + strlen($2->code) + 4);
			strcat(ret,$1);
			strcat(ret,"\n");
			strcat(ret,$2->code);
			$$ = ret;
		}
		;
	declaration:
		INTEGER_TOK identifier { $$ = $2;} 
		;
	identifier:
		ID_TOK { $$ = $1;}
		;
	expression:
		expression ADDITION_TOK expression{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			return_exp->address = gen_var();
			char *var = (char *)malloc(sizeof(char) * 20);
			strcat(var,return_exp->address);
			strcat(var,"=");
			strcat(var,$1->address);
			strcat(var,"+");
			strcat(var,$3->address);
			strcat(var,"\n");
			int x = strlen(var);
			char *return_var = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(var)+6);
			if ($1->code[0] != 0){
				strcat(return_var,$1->code);
				strcat(return_var,"\n");
			}
			if ($3->code[0] != 0){
				strcat(return_var,$3->code);
				strcat(return_var,"\n");
			}
			strcat(return_var,var);
			return_exp->code = return_var;
           	$$ = return_exp;           
		}
		| expression MINUS_TOK expression{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			return_exp->address = gen_var();
			char *var = (char *)malloc(sizeof(char) * 20);
			strcat(var,return_exp->address);
			strcat(var,"=");
			strcat(var,$1->address);
			strcat(var,"-");
			strcat(var,$3->address);
			strcat(var,"\n");
			int x = strlen(var);
			char *return_var = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(var)+6);
			if ($1->code[0] != 0){
				strcat(return_var,$1->code);
				strcat(return_var,"\n");
			}
			if ($3->code[0] != 0){
				strcat(return_var,$3->code);
				strcat(return_var,"\n");
			}
			strcat(return_var,var);
			return_exp->code = return_var;
           	$$ = return_exp;

		}
		| expression MULTIPLICATION_TOK expression{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			return_exp->address = gen_var();
			char *var = (char *)malloc(sizeof(char) * 20);
			strcat(var,return_exp->address);
			strcat(var,"=");
			strcat(var,$1->address);
			strcat(var,"*");
			strcat(var,$3->address);
			strcat(var,"\n");
			int x = strlen(var);
			char *return_var = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(var)+6);
			if ($1->code[0] != 0){
				strcat(return_var,$1->code);
				strcat(return_var,"\n");
			}
			if ($3->code[0] != 0){
				strcat(return_var,$3->code);
				strcat(return_var,"\n");
			}
			strcat(return_var,var);
			return_exp->code = return_var;
           	$$ = return_exp;

		}
		| expression DIVISION_TOK expression{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			return_exp->address = gen_var();
			char *var = (char *)malloc(sizeof(char) * 20);
			strcat(var,return_exp->address);
			strcat(var,"=");
			strcat(var,$1->address);
			strcat(var,"/");
			strcat(var,$3->address);
			strcat(var,"\n");
			int x = strlen(var);
			char *return_var = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(var)+6);
			if ($1->code[0] != 0){
				strcat(return_var,$1->code);
				strcat(return_var,"\n");
			}
			if ($3->code[0] != 0){
				strcat(return_var,$3->code);
				strcat(return_var,"\n");
			}
			strcat(return_var,var);
			return_exp->code = return_var;
           	$$ = return_exp;

		}
		| expression MODULO_TOK expression{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			return_exp->address = gen_var();
			char *var = (char *)malloc(sizeof(char) * 20);
			strcat(var,return_exp->address);
			strcat(var,"=");
			strcat(var,$1->address);
			strcat(var,"%");
			strcat(var,$3->address);
			strcat(var,"\n");
			int x = strlen(var);
			char *return_var = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(var)+6);
			if ($1->code[0] != 0){
				strcat(return_var,$1->code);
				strcat(return_var,"\n");
			}
			if ($3->code[0] != 0){
				strcat(return_var,$3->code);
				strcat(return_var,"\n");
			}
			strcat(return_var,var);
			return_exp->code = return_var;
           	$$ = return_exp;

		}
		| LPAREN_TOK expression RPAREN_TOK{
			$$ = $2;

		} 
		| identifier {
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			return_exp->address = $1;
			return_exp->code = (char *)malloc(sizeof(char) * 2);
			return_exp->code[0] = 0;
			$$ = return_exp;
		}
		| INT_CONST_TOK{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			char *num = (char *)malloc(sizeof(char) * 20);
			snprintf(num,20,"%d",$1);
			return_exp->address = num;
			return_exp->code = (char *)malloc(sizeof(char) * 2);
			return_exp->code[0] = 0;
			$$ = return_exp;
		}
		;
	boolean_val:
		expression RELATIONAL_TOK expression {
			char *var = (char *)malloc(strlen($1->code) + strlen($3->code) + 40);
			if($1->code[0] != 0){
				strcat(var,$1->code);
				strcat(var,"\n");
			}
			if($3->code[0] != 0){
				strcat(var,$3->code);
				strcat(var,"\n");
			}
			char *return_var = (char *)malloc(sizeof(char) * 40);
			strcat(return_var,"if (");
			strcat(return_var,$1->address);
			strcat(return_var,$2);
			strcat(return_var,$3->address);
			strcat(return_var,") goto TRUE \n goto FALSE");
			strcat(var,return_var);
			$$ = var;
		}
		;
%%
int main(int argc,const char *argv[]){
	yyin = fopen(argv[1],"r");
	yyparse();
}
void *yyerror(char *s){
	printf("%s\n",s);
}