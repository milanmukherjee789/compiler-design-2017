%{
	#include<stdio.h>
        #include<string.h>
        #include<stdlib.h>
//	#include "lex.yy.c"
        int yylex(void);
	void yyerror(char *);
        extern int yylineno;
// Scope Computation -------------------------------
        int scope = 0;

// Declarations for Symbol Table Management

    struct node{
        int type;
        int line_no;
        int scope;
        char name[32];
    };
    
    struct node symbol_table[20];
    int sym_table_index = 0;   
    char temp_table[10][64];
    int temp_table_index;
    void put_in_temp_table(char *);
    int search_in_table(char *);
    void move_to_table(int);
    void view_symb();


%}
%token MAINF_TOK LPAREN_TOK RPAREN_TOK LCURLY_TOK RCURLY_TOK INTCONST SEMICOLON_TOK INT_TOK FLOAT_TOK CHAR_TOK ID_TOK COMMA_TOK   
%left INT_TOK FLOAT_TOK CHAR_TOK
%start S


%union{
    struct s1{
               int i_value;
               char place[5];
               char code[300];} v;
    struct s2{char name[64];} n;
    struct s3{int i_type;} t;
};

%type <n> id_token ID_TOK
%type <v>  FLOAT_TOK INT_TOK CHAR_TOK
%type <t>  datatype


%%
S    :  datatype  MAINF_TOK LPAREN_TOK RPAREN_TOK BLOCK        {printf("\nSyntax for Main Function is Ok....\n");
                                                                printf("Scope===>%d\n",scope);}
     ;

BLOCK: LCURLY_TOK {scope = scope+1;printf("\n Scope==>%d", scope);}STATEMENTS BLOCKS RCURLY_TOK    
     ;

BLOCKS: BLOCK {scope = scope-1; printf("\n Scope==>%d", scope);} STATEMENTS BLOCKS                                {}
      |
      ; 

STATEMENTS:STATEMENTS  stmt 
          |
          ;

stmt      :DECLARATION SEMICOLON_TOK       {}
          ; 


DECLARATION:datatype id_token      {printf("\nSyntax of The Declaration Statement is Correct....."); move_to_table($1.i_type);} 
           ;

datatype:    INT_TOK                     {$$.i_type = 1;    printf("type found : %d\n",$$.i_type);	temp_table_index = 0;}
           | FLOAT_TOK                   {$$.i_type = 2;    printf("type found : %d\n",$$.i_type);	temp_table_index = 0;}
           | CHAR_TOK                    {$$.i_type = 3;    printf("type found : %d\n",$$.i_type);	temp_table_index = 0;}
           ;

id_token: id_token COMMA_TOK ID_TOK          {printf("tok %s\n",$3.name);put_in_temp_table($3.name);}
        | ID_TOK                             {printf("tok %s\n",$1.name);put_in_temp_table($1.name);}
        ;



%%
int main()
{
        if(yyparse()==0)printf("\nParsed Successfully");
        else printf("\nParsing Error");

        view_symb();
	return(0);
}

void yyerror(char *p)
{
	printf("Syntax Error");
}
