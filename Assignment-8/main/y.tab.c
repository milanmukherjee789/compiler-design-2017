/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "main.y"
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
#line 38 "main.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	int i_val;
	char *c_val;
	struct expression_type *exp_type;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 69 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INT_CONST_TOK 257
#define ID_TOK 258
#define ELSE_TOK 259
#define WHILE_TOK 260
#define LPAREN_TOK 261
#define RPAREN_TOK 262
#define LCURLY_TOK 263
#define RCURLY_TOK 264
#define IF_TOK 265
#define INTEGER_TOK 266
#define ELSEIF_TOK 267
#define EQUAL_TOK 268
#define SEMICOLON_TOK 269
#define RELATIONAL_TOK 270
#define OR_TOK 271
#define AND_TOK 272
#define NOT_TOK 273
#define ADDITION_TOK 274
#define MINUS_TOK 275
#define MULTIPLICATION_TOK 276
#define DIVISION_TOK 277
#define MODULO_TOK 278
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    8,    8,    7,    7,    7,    7,    7,    7,    2,
    1,    1,    4,    5,    6,    6,    6,    6,    6,    6,
    6,    6,    3,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    5,    5,    7,    2,    2,    4,    3,
    1,    2,    2,    1,    3,    3,    3,    3,    3,    3,
    1,    1,    3,
};
static const YYINT yydefred[] = {                         3,
    0,    0,   22,   14,    0,    0,    0,    0,    0,   21,
    0,    2,    0,    0,    0,   13,    0,    8,    7,    0,
    0,    0,    0,    0,    0,    0,   20,    0,    0,    0,
    0,   17,   18,   19,    0,    0,    0,    9,    0,    4,
    0,    0,    0,   11,    0,   10,   12,    6,
};
static const YYINT yydgoto[] = {                          1,
   43,   40,   25,    9,   10,   11,   12,    2,
};
static const YYINT yysindex[] = {                         0,
    0, -205,    0,    0, -255, -224, -223, -219, -256,    0,
 -212,    0, -224, -254, -224,    0, -224,    0,    0, -224,
 -224, -224, -224, -224, -218, -193,    0, -214, -202, -273,
 -273,    0,    0,    0, -216, -224, -216,    0, -205,    0,
 -188, -201, -215,    0, -216,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,   54,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -243,
 -234,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -203,    1,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  -35,   53,    0,   61,   -6,  -14,    0,
};
#define YYTABLESIZE 267
static const YYINT yytable[] = {                         14,
    5,   42,   22,   23,   24,   13,   26,   27,   26,   48,
   29,   17,   18,   30,   31,   32,   33,   34,   15,   20,
   21,   22,   23,   24,   44,   15,   15,   16,   47,   41,
   15,   15,    3,    4,   16,   16,    6,   15,    4,   16,
   16,    3,    4,   35,    5,    6,   39,   37,   46,    7,
    8,    3,    4,    1,    5,    6,   19,   45,   23,    7,
    8,   20,   21,   22,   23,   24,   38,   28,   16,    0,
    0,   20,   21,   22,   23,   24,   36,    0,    0,    0,
   20,   21,   22,   23,   24,   20,   21,   22,   23,   24,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    5,    5,    0,
    5,    5,    0,    0,    5,    5,    5,
};
static const YYINT yycheck[] = {                          6,
    0,   37,  276,  277,  278,  261,   13,  262,   15,   45,
   17,  268,  269,   20,   21,   22,   23,   24,  262,  274,
  275,  276,  277,  278,   39,  269,  270,  262,   43,   36,
  274,  275,  257,  258,  269,  270,  261,  261,  258,  274,
  275,  257,  258,  262,  260,  261,  263,  262,  264,  265,
  266,  257,  258,    0,  260,  261,  269,  259,  262,  265,
  266,  274,  275,  276,  277,  278,  269,   15,    8,   -1,
   -1,  274,  275,  276,  277,  278,  270,   -1,   -1,   -1,
  274,  275,  276,  277,  278,  274,  275,  276,  277,  278,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,   -1,
  260,  261,   -1,   -1,  264,  265,  266,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#define YYUNDFTOKEN 289
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT_CONST_TOK","ID_TOK",
"ELSE_TOK","WHILE_TOK","LPAREN_TOK","RPAREN_TOK","LCURLY_TOK","RCURLY_TOK",
"IF_TOK","INTEGER_TOK","ELSEIF_TOK","EQUAL_TOK","SEMICOLON_TOK",
"RELATIONAL_TOK","OR_TOK","AND_TOK","NOT_TOK","ADDITION_TOK","MINUS_TOK",
"MULTIPLICATION_TOK","DIVISION_TOK","MODULO_TOK",0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programe",
"programe : function",
"function : function actual_statement",
"function :",
"actual_statement : WHILE_TOK LPAREN_TOK boolean_val RPAREN_TOK statement_block",
"actual_statement : IF_TOK LPAREN_TOK boolean_val RPAREN_TOK statement_block",
"actual_statement : IF_TOK LPAREN_TOK boolean_val RPAREN_TOK statement_block ELSE_TOK statement_block",
"actual_statement : expression SEMICOLON_TOK",
"actual_statement : declaration SEMICOLON_TOK",
"actual_statement : declaration EQUAL_TOK expression SEMICOLON_TOK",
"statement_block : LCURLY_TOK statement RCURLY_TOK",
"statement : actual_statement",
"statement : statement actual_statement",
"declaration : INTEGER_TOK identifier",
"identifier : ID_TOK",
"expression : expression ADDITION_TOK expression",
"expression : expression MINUS_TOK expression",
"expression : expression MULTIPLICATION_TOK expression",
"expression : expression DIVISION_TOK expression",
"expression : expression MODULO_TOK expression",
"expression : LPAREN_TOK expression RPAREN_TOK",
"expression : identifier",
"expression : INT_CONST_TOK",
"boolean_val : expression RELATIONAL_TOK expression",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 390 "main.y"
int main(int argc,const char *argv[]){
	yyin = fopen(argv[1],"r");
	yyparse();
}
void *yyerror(char *s){
	printf("%s\n",s);
}
#line 315 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 60 "main.y"
	{
			printf("Successfully parsed\n");
			deallocate_mem();
		}
break;
case 2:
#line 67 "main.y"
	{printf("\t\t THREE ADDRESS CODE : \n%s\n",yystack.l_mark[0].exp_type->code);}
break;
case 4:
#line 72 "main.y"
	{
			bool = yystack.l_mark[-2].c_val;
			stat = yystack.l_mark[0].c_val;
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
			yyval.exp_type = return_exp;
		}
break;
case 5:
#line 109 "main.y"
	{
			bool = yystack.l_mark[-2].c_val;
			stat = yystack.l_mark[0].c_val;
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
			yyval.exp_type = return_exp;
		}
break;
case 6:
#line 135 "main.y"
	{
			bool = yystack.l_mark[-4].c_val;
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
			char *var = (char *)malloc(strlen(bool)+strlen(yystack.l_mark[-2].c_val)+strlen(yystack.l_mark[0].c_val) + 18 + strlen(begin_label1) + strlen(begin_label2));
			strcat(var,bool);
			strcat(var,"\n");
			strcat(var,begin_label1);
			strcat(var," : ");
			strcat(var,yystack.l_mark[-2].c_val);
			strcat(var,"\n");
			strcat(var,"goto NEXT");
			strcat(var,"\n");
			strcat(var,begin_label2);
			strcat(var," : ");
			strcat(var,yystack.l_mark[0].c_val);
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(2);
			return_exp->address[0] = 'X';
			return_exp->code = (char *)malloc(sizeof(char) * strlen(var));
			strncpy(return_exp->code,var,strlen(var));
			yyval.exp_type = return_exp;
		}
break;
case 7:
#line 168 "main.y"
	{ yyval.exp_type = yystack.l_mark[-1].exp_type;}
break;
case 8:
#line 169 "main.y"
	{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(20);
			return_exp->address = yystack.l_mark[-1].c_val;
			return_exp->code = (char *)malloc(2);
			return_exp->code[0] = 0;
			yyval.exp_type = return_exp;
		}
break;
case 9:
#line 177 "main.y"
	{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(20);
			return_exp->address = gen_var();
			char *var = (char *)malloc(20);
			strcat(var,yystack.l_mark[-3].c_val);
			strcat(var,"=");
			strcat(var,yystack.l_mark[-1].exp_type->address);
			char *temp = (char *)malloc(strlen(yystack.l_mark[-3].c_val) + strlen(yystack.l_mark[-1].exp_type->code) + strlen(var) + 2);
			if (yystack.l_mark[-1].exp_type->code[0] != 0){
				strcat(temp,yystack.l_mark[-1].exp_type->code);
				strcat(temp,"\n");
			}
			strcat(temp,var);
			return_exp->code = temp;
			yyval.exp_type = return_exp;
		}
break;
case 10:
#line 196 "main.y"
	{ yyval.c_val = yystack.l_mark[-1].c_val;}
break;
case 11:
#line 200 "main.y"
	{ yyval.c_val = yystack.l_mark[0].exp_type->code; }
break;
case 12:
#line 201 "main.y"
	{
			char *ret = (char *)malloc(strlen(yystack.l_mark[-1].c_val) + strlen(yystack.l_mark[0].exp_type->code) + 4);
			strcat(ret,yystack.l_mark[-1].c_val);
			strcat(ret,"\n");
			strcat(ret,yystack.l_mark[0].exp_type->code);
			yyval.c_val = ret;
		}
break;
case 13:
#line 210 "main.y"
	{ yyval.c_val = yystack.l_mark[0].c_val;}
break;
case 14:
#line 213 "main.y"
	{ yyval.c_val = yystack.l_mark[0].c_val;}
break;
case 15:
#line 216 "main.y"
	{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			return_exp->address = gen_var();
			char *var = (char *)malloc(sizeof(char) * 20);
			strcat(var,return_exp->address);
			strcat(var,"=");
			strcat(var,yystack.l_mark[-2].exp_type->address);
			strcat(var,"+");
			strcat(var,yystack.l_mark[0].exp_type->address);
			strcat(var,"\n");
			int x = strlen(var);
			char *return_var = (char *)malloc(strlen(yystack.l_mark[-2].exp_type->code)+strlen(yystack.l_mark[0].exp_type->code)+strlen(var)+6);
			if (yystack.l_mark[-2].exp_type->code[0] != 0){
				strcat(return_var,yystack.l_mark[-2].exp_type->code);
				strcat(return_var,"\n");
			}
			if (yystack.l_mark[0].exp_type->code[0] != 0){
				strcat(return_var,yystack.l_mark[0].exp_type->code);
				strcat(return_var,"\n");
			}
			strcat(return_var,var);
			return_exp->code = return_var;
           	yyval.exp_type = return_exp;           
		}
break;
case 16:
#line 241 "main.y"
	{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			return_exp->address = gen_var();
			char *var = (char *)malloc(sizeof(char) * 20);
			strcat(var,return_exp->address);
			strcat(var,"=");
			strcat(var,yystack.l_mark[-2].exp_type->address);
			strcat(var,"-");
			strcat(var,yystack.l_mark[0].exp_type->address);
			strcat(var,"\n");
			int x = strlen(var);
			char *return_var = (char *)malloc(strlen(yystack.l_mark[-2].exp_type->code)+strlen(yystack.l_mark[0].exp_type->code)+strlen(var)+6);
			if (yystack.l_mark[-2].exp_type->code[0] != 0){
				strcat(return_var,yystack.l_mark[-2].exp_type->code);
				strcat(return_var,"\n");
			}
			if (yystack.l_mark[0].exp_type->code[0] != 0){
				strcat(return_var,yystack.l_mark[0].exp_type->code);
				strcat(return_var,"\n");
			}
			strcat(return_var,var);
			return_exp->code = return_var;
           	yyval.exp_type = return_exp;

		}
break;
case 17:
#line 267 "main.y"
	{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			return_exp->address = gen_var();
			char *var = (char *)malloc(sizeof(char) * 20);
			strcat(var,return_exp->address);
			strcat(var,"=");
			strcat(var,yystack.l_mark[-2].exp_type->address);
			strcat(var,"*");
			strcat(var,yystack.l_mark[0].exp_type->address);
			strcat(var,"\n");
			int x = strlen(var);
			char *return_var = (char *)malloc(strlen(yystack.l_mark[-2].exp_type->code)+strlen(yystack.l_mark[0].exp_type->code)+strlen(var)+6);
			if (yystack.l_mark[-2].exp_type->code[0] != 0){
				strcat(return_var,yystack.l_mark[-2].exp_type->code);
				strcat(return_var,"\n");
			}
			if (yystack.l_mark[0].exp_type->code[0] != 0){
				strcat(return_var,yystack.l_mark[0].exp_type->code);
				strcat(return_var,"\n");
			}
			strcat(return_var,var);
			return_exp->code = return_var;
           	yyval.exp_type = return_exp;

		}
break;
case 18:
#line 293 "main.y"
	{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			return_exp->address = gen_var();
			char *var = (char *)malloc(sizeof(char) * 20);
			strcat(var,return_exp->address);
			strcat(var,"=");
			strcat(var,yystack.l_mark[-2].exp_type->address);
			strcat(var,"/");
			strcat(var,yystack.l_mark[0].exp_type->address);
			strcat(var,"\n");
			int x = strlen(var);
			char *return_var = (char *)malloc(strlen(yystack.l_mark[-2].exp_type->code)+strlen(yystack.l_mark[0].exp_type->code)+strlen(var)+6);
			if (yystack.l_mark[-2].exp_type->code[0] != 0){
				strcat(return_var,yystack.l_mark[-2].exp_type->code);
				strcat(return_var,"\n");
			}
			if (yystack.l_mark[0].exp_type->code[0] != 0){
				strcat(return_var,yystack.l_mark[0].exp_type->code);
				strcat(return_var,"\n");
			}
			strcat(return_var,var);
			return_exp->code = return_var;
           	yyval.exp_type = return_exp;

		}
break;
case 19:
#line 319 "main.y"
	{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			return_exp->address = gen_var();
			char *var = (char *)malloc(sizeof(char) * 20);
			strcat(var,return_exp->address);
			strcat(var,"=");
			strcat(var,yystack.l_mark[-2].exp_type->address);
			strcat(var,"%");
			strcat(var,yystack.l_mark[0].exp_type->address);
			strcat(var,"\n");
			int x = strlen(var);
			char *return_var = (char *)malloc(strlen(yystack.l_mark[-2].exp_type->code)+strlen(yystack.l_mark[0].exp_type->code)+strlen(var)+6);
			if (yystack.l_mark[-2].exp_type->code[0] != 0){
				strcat(return_var,yystack.l_mark[-2].exp_type->code);
				strcat(return_var,"\n");
			}
			if (yystack.l_mark[0].exp_type->code[0] != 0){
				strcat(return_var,yystack.l_mark[0].exp_type->code);
				strcat(return_var,"\n");
			}
			strcat(return_var,var);
			return_exp->code = return_var;
           	yyval.exp_type = return_exp;

		}
break;
case 20:
#line 345 "main.y"
	{
			yyval.exp_type = yystack.l_mark[-1].exp_type;

		}
break;
case 21:
#line 349 "main.y"
	{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			return_exp->address = yystack.l_mark[0].c_val;
			return_exp->code = (char *)malloc(sizeof(char) * 2);
			return_exp->code[0] = 0;
			yyval.exp_type = return_exp;
		}
break;
case 22:
#line 357 "main.y"
	{
			return_exp = (struct expression_type *)malloc(sizeof(struct expression_type));
			return_exp->address = (char *)malloc(sizeof(char) * 20);
			char *num = (char *)malloc(sizeof(char) * 20);
			snprintf(num,20,"%d",yystack.l_mark[0].i_val);
			return_exp->address = num;
			return_exp->code = (char *)malloc(sizeof(char) * 2);
			return_exp->code[0] = 0;
			yyval.exp_type = return_exp;
		}
break;
case 23:
#line 369 "main.y"
	{
			char *var = (char *)malloc(strlen(yystack.l_mark[-2].exp_type->code) + strlen(yystack.l_mark[0].exp_type->code) + 40);
			if(yystack.l_mark[-2].exp_type->code[0] != 0){
				strcat(var,yystack.l_mark[-2].exp_type->code);
				strcat(var,"\n");
			}
			if(yystack.l_mark[0].exp_type->code[0] != 0){
				strcat(var,yystack.l_mark[0].exp_type->code);
				strcat(var,"\n");
			}
			char *return_var = (char *)malloc(sizeof(char) * 40);
			strcat(return_var,"if (");
			strcat(return_var,yystack.l_mark[-2].exp_type->address);
			strcat(return_var,yystack.l_mark[-1].c_val);
			strcat(return_var,yystack.l_mark[0].exp_type->address);
			strcat(return_var,") goto TRUE \n goto FALSE");
			strcat(var,return_var);
			yyval.c_val = var;
		}
break;
#line 891 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
