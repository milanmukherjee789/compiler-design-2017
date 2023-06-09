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
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include "error.h"
	#define DEBUG_INFO 1
	#define MAX_FUNCTION 10
	int yylex(void);
	extern char* yytext;
	extern FILE* yyin;
	extern int yylineno;
	int global_scope = 0;
	int var_buffer[100];
	int var_buffer_index = 0;
	int scope_adjust = 0;
	int function_index = 0;
	struct entry{
		int entry_index;
		char var_name;
		int type[10];
		int scope[10];
		int line_no[10];
		int scope_array_index;
		int global_flag;
	}symbol_table[MAX_FUNCTION][122],temp_table[122]; 

	void insert_by_name(char *name);
	int found(char *name);
	void display_table(int table_index);
	int check_for_same_scope(struct entry node1,struct entry node2);
	void check_scope_declaration(char *name,int scope);
	int check_type(char *name1,char *name2);
	int is_number(const char *s);
	void init_symbol_table(void);
	void check_type_assign(char *name,int type,int scope);
	void invalidate_scope_var(int target_scope);

#line 51 "main.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{

	struct s1{
    	int i_type;
    	char *i_val;
    }p;

	struct s2{
		char *name;
		int i_type;
		char *i_val;
	}n;

    struct s3{
    	int i_type;
    }t;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 84 "y.tab.c"

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

#define FOR_TOK 257
#define WHILE_TOK 258
#define SWITCH_TOK 259
#define CASE_TOK 260
#define IF_TOK 261
#define ELSE_TOK 262
#define BREAK_TOK 263
#define DEFAULT_TOK 264
#define RETURN_TOK 265
#define INCLUDE_TOK 266
#define DEFINE_TOK 267
#define MAIN_TOK 268
#define SEMICOLON_TOK 269
#define COMMA_TOK 270
#define DOT_TOK 271
#define LCURLY_TOK 272
#define RCURLY_TOK 273
#define RPAREN_TOK 274
#define LPAREN_TOK 275
#define ARRAY_BRACKET_LTOK 276
#define ARRAY_BRACKET_RTOK 277
#define ADDITION_TOK 278
#define INCREMENT_TOK 279
#define ADDITION_EQUAL_TOK 280
#define MINUS_TOK 281
#define DECREMENT_TOK 282
#define MINUS_EQUAL_TOK 283
#define MULTIPLICATION_TOK 284
#define MULTIPLICATION_EQUAL_TOK 285
#define DIVISION_EQUAL_TOK 286
#define DIVISION_TOK 287
#define MODULO_TOK 288
#define MODULO_EQUAL_TOK 289
#define RIGHT_SHIFT_TOK 290
#define GREATER_THAN_EQUAL_TOK 291
#define GREATER_TOK 292
#define LEFT_SHIFT_TOK 293
#define LESS_THAN_EQUAL_TOK 294
#define LESS_TOK 295
#define EQUAL_COMPARE_TOK 296
#define EQUAL_TOK 297
#define NOT_EQUAL_TOK 298
#define NOT_TOK 299
#define BIT_OR_EQUAL_TOK 300
#define BIT_OR_TOK 301
#define OR_TOK 302
#define AND_TOK 303
#define BIT_AND_EQUAL_TOK 304
#define BIT_AND_TOK 305
#define XOR_TOK 306
#define XOR_EQUAL_TOK 307
#define SPACE_TOK 308
#define COLON_TOK 309
#define ID_TOK 310
#define INT_CONST_TOK 311
#define INTEGER_TOK 312
#define FLOATING_TOK 313
#define DOUBLE_TOK 314
#define CHAR_TOK 315
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    5,    9,    5,   11,   10,   10,    7,    7,    1,
    1,    1,    1,   13,   15,    8,   14,   14,   12,   12,
   16,   16,   16,   16,   16,   16,   16,   16,   23,   24,
   20,   22,   22,   22,   25,   25,   21,   21,   21,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
   18,   18,   18,   18,   18,   18,   18,   18,   19,   19,
   19,   19,    3,    3,    6,   17,    2,    2,
};
static const YYINT yylen[] = {                            2,
    1,    3,    0,    8,    0,    8,    0,    4,    2,    1,
    1,    1,    1,    0,    0,    6,    3,    0,    2,    0,
    2,    5,   11,    7,    5,    5,    1,    2,    0,    0,
    5,    6,    4,    0,    2,    0,    4,    4,    4,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    1,    3,
    1,    3,    3,    3,    3,    3,    3,    3,    2,    2,
    2,    2,    1,    1,    2,    2,    3,    1,
};
static const YYINT yydefred[] = {                         0,
   10,   11,   12,   13,    0,    0,    1,    0,    0,   68,
    0,    0,    0,    0,    2,    0,    0,   67,    9,    0,
    3,    0,    0,    8,   14,    0,   20,    0,    4,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   20,
   15,   19,    0,    0,   27,    0,    0,    0,    0,    0,
   61,   62,   59,   60,    0,    0,    0,    0,   21,    0,
   28,    0,    0,    0,   63,   64,    0,    0,    0,    0,
    0,    0,    0,   17,   16,    0,    5,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   49,    0,
   39,   37,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   38,    0,    0,   58,   52,   53,   54,   55,   56,
   57,   22,   29,   26,    0,   50,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    6,
    0,    0,    0,   30,   24,    0,    0,   20,    0,    0,
    0,   20,    0,   31,    0,    0,    0,   33,   23,    0,
   35,   32,
};
static const YYINT yydgoto[] = {                          5,
   39,   11,   89,   73,    7,    8,   17,   40,   23,   29,
  103,   30,   27,   41,   58,   42,   43,   68,   44,  114,
   45,  134,  128,  139,  148,
};
static const YYINT yysindex[] = {                       -90,
    0,    0,    0,    0,    0, -262,    0, -254, -258,    0,
 -246,  -90,  -90, -261,    0, -231, -210,    0,    0,  -90,
    0, -215, -173,    0,    0,  -90,    0, -209,    0, -146,
 -213, -206, -136, -134, -133, -207, -180, -271, -166,    0,
    0,    0, -247, -123,    0,  -90,  -90, -268, -158, -268,
    0,    0,    0,    0, -266, -246, -146, -114,    0, -148,
    0, -198, -135, -268,    0,    0, -138, -113, -109, -103,
 -266,  -97, -150,    0,    0,  -96,    0, -132,  -99, -279,
 -279, -279, -279, -279, -279, -173,  -94, -173,    0, -104,
    0,    0, -266, -266, -266, -266, -266, -266, -266, -266,
 -266,    0, -173,  -93,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -81,    0,  -88,  -88,  -88,  -88,
  -88,  -88,  -88,  -88,  -88,  -90, -268, -230, -173,    0,
  -87, -126, -122,    0,    0, -259, -121,    0,  -82, -147,
  -80,    0, -165,    0, -173, -165,  -77,    0,    0, -230,
    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -74,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  198,    0,    0,    0,  -70,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -240,  -70,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -241,    0,    0,    0,
    0,  -72,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -205,    0, -228, -203, -199, -196,
 -172, -153, -151, -149, -145,  198,    0,  -69,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -66,    0,    0, -248,    0,    0,    0,  -69,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    1,  169,  -45,  -10,  199,    0,  164,  -23,    0,   88,
    0,  -38,    0,  162,    0,    0,  173,  -46,   90,    0,
    0,   77,    0,    0,   82,
};
#define YYTABLESIZE 233
static const YYINT yytable[] = {                         26,
    6,   57,   67,   70,   67,    9,   64,   53,   71,   72,
   54,   36,    6,   16,   12,   36,   13,   79,   67,   36,
   22,   59,   37,   14,   36,   55,   28,   51,   66,  132,
   65,   66,   51,  133,  106,  107,  108,  109,  110,  111,
   40,   65,   66,   65,   66,   40,   16,   10,   18,   60,
  140,   25,   25,   25,   25,   25,   66,   25,   25,   20,
   90,   46,  112,   21,  115,   41,   25,   25,   47,   42,
   41,   20,   43,   25,   42,   77,   25,   43,   19,  126,
  131,   67,  117,  118,  119,  120,  121,  122,  123,  124,
  125,   32,   33,   34,   24,   35,   44,  147,   25,  143,
   31,   44,   51,  146,   25,  135,   25,   25,   25,   25,
   32,   33,   34,   36,   35,   45,   37,   46,   92,   47,
   45,  149,   46,   48,   47,   25,   28,   93,   48,   52,
   94,   53,   36,   95,   54,   37,   96,   97,   48,   98,
   49,   50,   99,   10,   38,   61,    1,    2,    3,    4,
  100,   69,   80,   81,  101,   82,   83,   84,   75,   85,
   86,   78,   76,   38,   87,    1,    2,    3,    4,  116,
   88,   91,  102,   93,  105,  127,   94,  113,  104,   95,
  129,  136,   96,   97,  137,   98,  138,  142,   99,   93,
  144,  151,   94,  145,   65,   95,  100,    7,   96,   97,
  101,   98,   18,   34,   99,   49,   36,   56,   49,   62,
   15,   49,  100,  130,   49,   49,  101,   49,   74,   63,
   49,    1,    2,    3,    4,  141,  152,  150,   49,    0,
    0,    0,   49,
};
static const YYINT yycheck[] = {                         23,
    0,   40,   48,   50,   50,  268,  275,  279,  275,   55,
  282,  260,   12,   13,  269,  264,  275,   64,   64,  279,
   20,  269,  282,  270,  273,  297,   26,  269,  269,  260,
  310,  311,  274,  264,   80,   81,   82,   83,   84,   85,
  269,  310,  311,  310,  311,  274,   46,  310,  310,  297,
  310,  257,  258,  259,  260,  261,  297,  263,  264,  270,
   71,  275,   86,  274,   88,  269,  272,  273,  275,  269,
  274,  270,  269,  279,  274,  274,  282,  274,  310,  103,
  127,  127,   93,   94,   95,   96,   97,   98,   99,  100,
  101,  257,  258,  259,  310,  261,  269,  263,  272,  138,
  310,  274,  310,  142,  310,  129,  312,  313,  314,  315,
  257,  258,  259,  279,  261,  269,  282,  269,  269,  269,
  274,  145,  274,  269,  274,  272,  126,  278,  274,  310,
  281,  279,  279,  284,  282,  282,  287,  288,  275,  290,
  275,  275,  293,  310,  310,  269,  312,  313,  314,  315,
  301,  310,  291,  292,  305,  294,  295,  296,  273,  298,
  274,  297,  311,  310,  274,  312,  313,  314,  315,  274,
  274,  269,  269,  278,  274,  269,  281,  272,  311,  284,
  262,  269,  287,  288,  311,  290,  309,  309,  293,  278,
  273,  269,  281,  274,  269,  284,  301,    0,  287,  288,
  305,  290,  273,  273,  293,  278,  273,   39,  281,   46,
   12,  284,  301,  126,  287,  288,  305,  290,   57,   47,
  293,  312,  313,  314,  315,  136,  150,  146,  301,   -1,
   -1,   -1,  305,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 315
#define YYUNDFTOKEN 343
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"FOR_TOK","WHILE_TOK",
"SWITCH_TOK","CASE_TOK","IF_TOK","ELSE_TOK","BREAK_TOK","DEFAULT_TOK",
"RETURN_TOK","INCLUDE_TOK","DEFINE_TOK","MAIN_TOK","SEMICOLON_TOK","COMMA_TOK",
"DOT_TOK","LCURLY_TOK","RCURLY_TOK","RPAREN_TOK","LPAREN_TOK",
"ARRAY_BRACKET_LTOK","ARRAY_BRACKET_RTOK","ADDITION_TOK","INCREMENT_TOK",
"ADDITION_EQUAL_TOK","MINUS_TOK","DECREMENT_TOK","MINUS_EQUAL_TOK",
"MULTIPLICATION_TOK","MULTIPLICATION_EQUAL_TOK","DIVISION_EQUAL_TOK",
"DIVISION_TOK","MODULO_TOK","MODULO_EQUAL_TOK","RIGHT_SHIFT_TOK",
"GREATER_THAN_EQUAL_TOK","GREATER_TOK","LEFT_SHIFT_TOK","LESS_THAN_EQUAL_TOK",
"LESS_TOK","EQUAL_COMPARE_TOK","EQUAL_TOK","NOT_EQUAL_TOK","NOT_TOK",
"BIT_OR_EQUAL_TOK","BIT_OR_TOK","OR_TOK","AND_TOK","BIT_AND_EQUAL_TOK",
"BIT_AND_TOK","XOR_TOK","XOR_EQUAL_TOK","SPACE_TOK","COLON_TOK","ID_TOK",
"INT_CONST_TOK","INTEGER_TOK","FLOATING_TOK","DOUBLE_TOK","CHAR_TOK",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programe",
"programe : function",
"function : global_declaration_statement SEMICOLON_TOK function",
"$$1 :",
"function : data_type MAIN_TOK LPAREN_TOK func_args RPAREN_TOK $$1 statement_block function_declr",
"$$2 :",
"function_declr : data_type ID_TOK LPAREN_TOK func_args RPAREN_TOK $$2 statement_block function_declr",
"function_declr :",
"func_args : func_args COMMA_TOK data_type ID_TOK",
"func_args : data_type ID_TOK",
"data_type : INTEGER_TOK",
"data_type : FLOATING_TOK",
"data_type : DOUBLE_TOK",
"data_type : CHAR_TOK",
"$$3 :",
"$$4 :",
"statement_block : LCURLY_TOK $$3 statement nested_blocks $$4 RCURLY_TOK",
"nested_blocks : statement_block statement nested_blocks",
"nested_blocks :",
"statement : statement actual_statement",
"statement :",
"actual_statement : declaration_statement SEMICOLON_TOK",
"actual_statement : WHILE_TOK LPAREN_TOK relational_expression RPAREN_TOK statement_block",
"actual_statement : FOR_TOK LPAREN_TOK declaration_statement EQUAL_TOK INT_CONST_TOK SEMICOLON_TOK relational_expression SEMICOLON_TOK unary_expression RPAREN_TOK statement_block",
"actual_statement : IF_TOK LPAREN_TOK relational_expression RPAREN_TOK statement_block ELSE_TOK statement_block",
"actual_statement : IF_TOK LPAREN_TOK relational_expression RPAREN_TOK statement_block",
"actual_statement : SWITCH_TOK LPAREN_TOK ID_TOK RPAREN_TOK switch_block",
"actual_statement : assignment_expression",
"actual_statement : unary_expression SEMICOLON_TOK",
"$$5 :",
"$$6 :",
"switch_block : LCURLY_TOK $$5 case_blocks $$6 RCURLY_TOK",
"case_blocks : CASE_TOK INT_CONST_TOK COLON_TOK statement optional_break case_blocks",
"case_blocks : DEFAULT_TOK COLON_TOK statement optional_break",
"case_blocks :",
"optional_break : BREAK_TOK SEMICOLON_TOK",
"optional_break :",
"assignment_expression : ID_TOK EQUAL_TOK arith_expression SEMICOLON_TOK",
"assignment_expression : declaration_statement EQUAL_TOK INT_CONST_TOK SEMICOLON_TOK",
"assignment_expression : ID_TOK EQUAL_TOK operand SEMICOLON_TOK",
"arith_expression : arith_expression ADDITION_TOK arith_expression",
"arith_expression : arith_expression MINUS_TOK arith_expression",
"arith_expression : arith_expression MULTIPLICATION_TOK arith_expression",
"arith_expression : arith_expression DIVISION_TOK arith_expression",
"arith_expression : arith_expression MODULO_TOK arith_expression",
"arith_expression : arith_expression RIGHT_SHIFT_TOK arith_expression",
"arith_expression : arith_expression LEFT_SHIFT_TOK arith_expression",
"arith_expression : arith_expression BIT_OR_TOK arith_expression",
"arith_expression : arith_expression BIT_AND_TOK arith_expression",
"arith_expression : operand",
"arith_expression : LPAREN_TOK arith_expression RPAREN_TOK",
"relational_expression : operand",
"relational_expression : operand GREATER_THAN_EQUAL_TOK operand",
"relational_expression : operand GREATER_TOK operand",
"relational_expression : operand LESS_THAN_EQUAL_TOK operand",
"relational_expression : operand LESS_TOK operand",
"relational_expression : operand EQUAL_COMPARE_TOK operand",
"relational_expression : operand NOT_EQUAL_TOK operand",
"relational_expression : LPAREN_TOK relational_expression RPAREN_TOK",
"unary_expression : ID_TOK INCREMENT_TOK",
"unary_expression : ID_TOK DECREMENT_TOK",
"unary_expression : INCREMENT_TOK ID_TOK",
"unary_expression : DECREMENT_TOK ID_TOK",
"operand : ID_TOK",
"operand : INT_CONST_TOK",
"global_declaration_statement : data_type inline_declaration",
"declaration_statement : data_type inline_declaration",
"inline_declaration : inline_declaration COMMA_TOK ID_TOK",
"inline_declaration : ID_TOK",

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
#line 305 "main.y"

int main(int argc,const char* argv[]){
	init_symbol_table();
	yyin = fopen(argv[1],"r");
	yyparse();
	return 0;
}
void success(void){
	for(int i=0;i <= function_index;i++){
		display_table(i);
	}
	printf("\n\n\t\t\tSUCCESSFULLY PARSED :)\n");
}
void yyerror(char *s){
	printf("SORRY SOME SYNTAX ERROR IS THERE IN LINE ........ :( . THE MESSEGE: %s\n",s);
	for(int i = 0; i < REASON ; i++){
		printf ("%s\n",error_reason[i]);
	}
	for(int i=0;i <= function_index;i++){
		display_table(i);
	}
	exit(1);
}
void init_symbol_table(void){
	for(int table_index = 0;table_index <= MAX_FUNCTION;table_index++){
		for(int i=0;i <= 122;i++){
			symbol_table[table_index][i].entry_index = -1;
		}
	}
	if(DEBUG_INFO){
		printf("Symbol table initialised with NULL\n");
		printf("Each node size of Symbol table is: %ld\n",sizeof(symbol_table[function_index][0]));
	}
}
void insert_by_name(char *name){

	int index = name[0];
	temp_table[index].entry_index = index;
	temp_table[index].var_name = name[0];
	memset((void*)temp_table[index].type,-1,sizeof(int)*10);
	temp_table[index].scope[0] = global_scope;
	temp_table[index].line_no[0] = yylineno;
	temp_table[index].scope_array_index = 0;
}
void assign_type(int t,int flag){
	if(DEBUG_INFO){
		printf("Current scope in assign_type is: %d in line_no: %d\n",global_scope,yylineno);
	}
	struct entry node;
	for(int i = 0;i < var_buffer_index;i++){
		if(var_buffer[i] >= 0){
			node = symbol_table[function_index][var_buffer[i]];
			if(node.var_name == temp_table[var_buffer[i]].var_name){
				if(check_for_same_scope(node,temp_table[var_buffer[i]])){
					yyerror("Variable having same name with same scope");
				}
				else{
					int element = var_buffer[i];
					symbol_table[function_index][element].entry_index = element;
					symbol_table[function_index][element].var_name = temp_table[element].var_name;
					symbol_table[function_index][element].scope[symbol_table[function_index][element].scope_array_index] = global_scope;
					symbol_table[function_index][element].type[global_scope] = t;
					symbol_table[function_index][element].line_no[global_scope] = yylineno;
					symbol_table[function_index][element].scope_array_index++;
					if(flag == 0 && symbol_table[function_index][element].global_flag != 1){
						symbol_table[function_index][element].global_flag = 0;
					}
					else{
						symbol_table[function_index][element].global_flag = 1;
					}
				}
			}
			else{
					int element = var_buffer[i];
					symbol_table[function_index][element].entry_index = element;
					symbol_table[function_index][element].var_name = temp_table[element].var_name;
					symbol_table[function_index][element].scope[symbol_table[function_index][element].scope_array_index] = global_scope;
					symbol_table[function_index][element].type[global_scope] = t;
					symbol_table[function_index][element].line_no[global_scope] = yylineno;
					symbol_table[function_index][element].scope_array_index++;
					if(flag == 0 && symbol_table[function_index][element].global_flag != 1){
						symbol_table[function_index][element].global_flag = 0;
					}
					else{
						symbol_table[function_index][element].global_flag = 1;
					}
			}
		}
		var_buffer[i] = -1;
	}
}
int check_for_same_scope(struct entry node1,struct entry node2){
	if(DEBUG_INFO){
		printf("Current scope in check_for_same_scope is:  %d in line_no: %d\n",global_scope,yylineno);
	}
	if (node1.entry_index == -1){
		return 0;
	}
	else{
		int target_scope = node2.scope[0];
		for(int i = 0;i < node1.scope_array_index;i++){
			if(node1.scope[i] == target_scope){
				return 1;
			}
		}
		return 0;
	}
}
void display_table(int table_index){
	char *decision = NULL;
	printf("\t\t\t%dth %s\n\n",table_index,"SYMBOL TABLE BUILT SO FAR");
	printf("----------------------------------------------------------------------------------------------------\n");
	for(int i=0;i <= 122;i++){
		if(symbol_table[table_index][i].entry_index != -1){
			for(int j=0;j < symbol_table[table_index][i].scope_array_index;j++){
				switch(symbol_table[table_index][i].type[symbol_table[table_index][i].scope[j]]){
					case 0:
						decision = (char*)malloc(sizeof(char) * 12);
						strncpy(decision,(char*)"Invalidated",11);
						break;
					case 1:
						decision = (char*)malloc(sizeof(char) * 4);
						strncpy(decision,(char*)"Int",3);
						break;
					case 2:
						decision = (char*)malloc(sizeof(char) * 5);
						strncpy(decision,(char*)"Float",4);
						break;
					case 3:
						decision = (char*)malloc(sizeof(char) * 6);
						strncpy(decision,(char*)"Double",5);
						break;
					case 4:
						decision = (char*)malloc(sizeof(char) * 5);
						strncpy(decision,(char*)"Char",4);
						break;

				}
				printf("| index: %d name: %c total_of_scope_used: %d type = %s in the scope %d line_no: %d global_flag: %d\t   |\n",symbol_table[table_index][i].entry_index,symbol_table[table_index][i].var_name,symbol_table[table_index][i].scope_array_index,decision,symbol_table[table_index][i].scope[j],symbol_table[table_index][i].line_no[symbol_table[table_index][i].scope[j]],symbol_table[table_index][i].global_flag);
				free(decision);
			}
			printf("----------------------------------------------------------------------------------------------------\n");
		}
	}
}
void check_scope_declaration(char *name,int Scope){
	if(DEBUG_INFO){
		printf("Current scope in check_scope_declaration for %s is:  %d in line no: %d\n",name,global_scope,yylineno);
	}
	if(found(name)){
		if (is_number(name) || symbol_table[function_index][name[0]].type[Scope] != 0){
			return;
		}
		else{
			for(int i = 0; i < Scope ; i++){
				if(symbol_table[function_index][name[0]].type[i] != 0){
					return;
				}
			}
			yyerror("Un-declared till now");
		}
		yyerror("Un-declared till now");
	}
	yyerror("Un-declared till now");
}
int found(char *name){
	return symbol_table[function_index][name[0]].entry_index != -1  || strlen(name) > 1 || is_number(name);
}
int  check_type(char *name1,char *name2){
	if(DEBUG_INFO){
		printf("Current scope in check_type for %s %s is: %d in line_no: %d\n",name1,name2,global_scope,yylineno);
	}
	if (strlen(name1) == 1 && strlen(name2) == 1 && !is_number(name2)){
		for(int i = 0; i < symbol_table[function_index][name1[0]].scope_array_index;i++){
			for(int j = 0; j < symbol_table[function_index][name2[0]].scope_array_index;j++){
				if (symbol_table[function_index][name1[0]].type[symbol_table[function_index][name1[0]].scope[i]] == symbol_table[function_index][name2[0]].type[symbol_table[function_index][name2[0]].scope[j]] && symbol_table[function_index][name1[0]].type[symbol_table[function_index][name1[0]].scope[i]] != 0 )
					return symbol_table[function_index][name1[0]].type[symbol_table[function_index][(int)name1[0]].scope[i]];
			}
		}
		printf("%s === %s\n",name1,name2);
		yyerror("Mismatched Type");
	}
	else if(strlen(name1) == 1){
		if (is_number(name2)){
			for(int i = 0;i < symbol_table[function_index][name1[0]].scope_array_index;i++){
				if(symbol_table[function_index][name1[0]].type[symbol_table[function_index][name1[0]].scope[i]] == 1){
					return 1;
				}
			}
			yyerror("Integer type not found");
		}
		yyerror("String is not allowed");
	}
	else if(strlen(name2) == 1){
		if(is_number(name1)){
			for(int i = 0;i < symbol_table[function_index][name2[0]].scope_array_index;i++){
				if(symbol_table[function_index][name2[0]].type[symbol_table[function_index][name2[0]].scope[i]] == 1){
					return 1;
				}
			}
			yyerror("Integer type not found");
		}
		yyerror("String is not allowed");
	}
	else{
		if(is_number(name1) && is_number(name2)){
			return 1;
		}
		yyerror("Un recognised type of two variables");
	}
}
void check_type_assign(char *name,int type,int scope){
	if(DEBUG_INFO){
		printf("Current scope in check_type_assign is: %d in lineno: %d\n",global_scope,yylineno);
	}
	for(int i = 0;i < symbol_table[function_index][name[0]].scope_array_index;i++){
		if(symbol_table[function_index][name[0]].type[symbol_table[function_index][name[0]].scope[i]] == type){
			return;
		}
	}
	yyerror("Mismatched type of LHS and RHS");
}
int is_number(const char *s)
{
    while (*s) {
        if (isdigit(*s++) == 0) return 0;
    }
    return 1;
}
void invalidate_scope_var(int target_scope){
	if(DEBUG_INFO){
		printf("invalidated target scope: %d\n",target_scope);
	}
	char *str;
	for(int i = 0;i < 122;i++){
		symbol_table[function_index][i].type[target_scope] = 0;
	}
	if(DEBUG_INFO){
		printf("After invalidating .... \n");
	}
	if(DEBUG_INFO){
		for(int i = 0;i <= function_index;i++){
			display_table(i);
		}
	}
}
#line 698 "y.tab.c"

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
#line 75 "main.y"
	{success();}
break;
case 3:
#line 80 "main.y"
	{
		function_index++;
		if(DEBUG_INFO){
			printf("%dth Main Function has been found in line no: %d\n",function_index,yylineno);
		}
	}
break;
case 5:
#line 88 "main.y"
	{
		function_index++;
		if(DEBUG_INFO){
			printf("%dth User Defined Function has been found in line no: %d\n",function_index,yylineno);
		}
	}
break;
case 10:
#line 103 "main.y"
	{yyval.t.i_type = 1;}
break;
case 11:
#line 104 "main.y"
	{yyval.t.i_type = 2; }
break;
case 12:
#line 105 "main.y"
	{yyval.t.i_type = 3; }
break;
case 13:
#line 106 "main.y"
	{yyval.t.i_type = 4; }
break;
case 14:
#line 110 "main.y"
	{
		global_scope += 1;
	}
break;
case 15:
#line 112 "main.y"
	{
		invalidate_scope_var(global_scope);
		global_scope -= 1;
	}
break;
case 26:
#line 134 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
	}
break;
case 29:
#line 141 "main.y"
	{
		global_scope += 1;
	}
break;
case 30:
#line 143 "main.y"
	{
		global_scope -= 1;
	}
break;
case 37:
#line 157 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-3].n.name,global_scope);
		check_type_assign(yystack.l_mark[-3].n.name,yystack.l_mark[-1].n.i_type,global_scope);

	}
break;
case 38:
#line 162 "main.y"
	{
		if(DEBUG_INFO){
			printf("Declaration statement is correctly parsed at line no %d\n",yylineno);
		}
	}
break;
case 39:
#line 167 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-3].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[-1].n.name,global_scope);
		check_type(yystack.l_mark[-3].n.name,yystack.l_mark[-1].n.name);
	}
break;
case 40:
#line 175 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.n.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 41:
#line 180 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.n.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 42:
#line 185 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.n.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 43:
#line 190 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.n.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 44:
#line 195 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.n.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 45:
#line 200 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.n.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 46:
#line 205 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.n.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 47:
#line 210 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.n.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 48:
#line 215 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		yyval.n.i_type = check_type(yystack.l_mark[-2].n.name,yystack.l_mark[0].n.name);
	}
break;
case 49:
#line 220 "main.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 50:
#line 221 "main.y"
	{}
break;
case 51:
#line 225 "main.y"
	{
		check_scope_declaration(yystack.l_mark[0].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression having only operand has been found in line no: %d\n",yylineno);
		}
	}
break;
case 52:
#line 231 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression has been found in line no: %d\n",yylineno);
		}  	
	}
break;
case 53:
#line 237 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression has been found in line no: %d\n",yylineno);
		}			
	}
break;
case 54:
#line 243 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression has been found in line no: %d\n",yylineno);
		}		
	}
break;
case 55:
#line 249 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression has been found in line no: %d\n",yylineno);
		}				
	}
break;
case 56:
#line 255 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression has been found in line no: %d\n",yylineno);
		}			
	}
break;
case 57:
#line 261 "main.y"
	{
		check_scope_declaration(yystack.l_mark[-2].n.name,global_scope);
		if(DEBUG_INFO){
			printf("relational expression has been found in line no: %d\n",yylineno);
		}			
	}
break;
case 59:
#line 271 "main.y"
	{check_scope_declaration(yystack.l_mark[-1].n.name,global_scope);}
break;
case 60:
#line 272 "main.y"
	{check_scope_declaration(yystack.l_mark[-1].n.name,global_scope);}
break;
case 61:
#line 273 "main.y"
	{check_scope_declaration(yystack.l_mark[0].n.name,global_scope);}
break;
case 62:
#line 274 "main.y"
	{check_scope_declaration(yystack.l_mark[0].n.name,global_scope);}
break;
case 63:
#line 278 "main.y"
	{yyval.n = yystack.l_mark[0].n; }
break;
case 64:
#line 279 "main.y"
	{yyval.n = yystack.l_mark[0].n;}
break;
case 65:
#line 283 "main.y"
	{
		assign_type(yystack.l_mark[-1].t.i_type,1);
	}
break;
case 66:
#line 289 "main.y"
	{
		assign_type(yystack.l_mark[-1].t.i_type,0);
	}
break;
case 67:
#line 295 "main.y"
	{
		insert_by_name(yystack.l_mark[0].n.name);
		var_buffer[var_buffer_index++] = yystack.l_mark[0].n.name[0];
	}
break;
case 68:
#line 299 "main.y"
	{
		insert_by_name(yystack.l_mark[0].n.name);
		var_buffer[var_buffer_index++] = yystack.l_mark[0].n.name[0];
	}
break;
#line 1186 "y.tab.c"
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
