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

#line 4 "main.y"
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	extern FILE *yyin;
	#define YYDEBUG 0
	void yyerror(char *s);
	int yylex(void);
	void success(void);	
	extern int yylineno;

#line 32 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

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
#define INTEGER_TOK 263
#define FLOATING_TOK 264
#define DOUBLE_TOK 265
#define CHAR_TOK 266
#define BREAK_TOK 267
#define DEFAULT_TOK 268
#define RETURN_TOK 269
#define INCLUDE_TOK 270
#define DEFINE_TOK 271
#define MAIN_TOK 272
#define SEMICOLON_TOK 273
#define COMMA_TOK 274
#define DOT_TOK 275
#define LCURLY_TOK 276
#define RCURLY_TOK 277
#define RPAREN_TOK 278
#define LPAREN_TOK 279
#define ARRAY_BRACKET_LTOK 280
#define ARRAY_BRACKET_RTOK 281
#define ADDITION_TOK 282
#define INCREMENT_TOK 283
#define ADDITION_EQUAL_TOK 284
#define MINUS_TOK 285
#define DECREMENT_TOK 286
#define MINUS_EQUAL_TOK 287
#define MULTIPLICATION_TOK 288
#define MULTIPLICATION_EQUAL_TOK 289
#define DIVISION_EQUAL_TOK 290
#define DIVISION_TOK 291
#define MODULO_TOK 292
#define MODULO_EQUAL_TOK 293
#define RIGHT_SHIFT_TOK 294
#define GREATER_THAN_EQUAL_TOK 295
#define GREATER_TOK 296
#define LEFT_SHIFT_TOK 297
#define LESS_THAN_EQUAL_TOK 298
#define LESS_TOK 299
#define EQUAL_COMPARE_TOK 300
#define EQUAL_TOK 301
#define NOT_EQUAL_TOK 302
#define NOT_TOK 303
#define BIT_OR_EQUAL_TOK 304
#define BIT_OR_TOK 305
#define OR_TOK 306
#define AND_TOK 307
#define BIT_AND_EQUAL_TOK 308
#define BIT_AND_TOK 309
#define XOR_TOK 310
#define XOR_EQUAL_TOK 311
#define SPACE_TOK 312
#define COLON_TOK 313
#define ID_TOK 314
#define INT_CONST_TOK 315
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    9,    9,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   11,   12,   13,
   14,    5,    5,   15,   15,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,   20,   20,   21,   21,    6,    6,    6,    6,    6,
    6,    6,   17,   17,   17,   17,   18,   18,   18,   18,
   16,   16,   16,   16,   16,   16,   16,   16,   16,   16,
    4,    4,    8,    8,    8,   19,   22,   22,   22,   22,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    1,    2,    2,    5,    5,    7,    7,
    6,    6,    6,    6,    6,    8,    0,    1,    1,    1,
    1,    1,    3,    3,    3,    3,    0,    2,    2,    2,
    2,    3,    1,    2,    0,    2,    2,    2,    2,    1,
    1,    2,    4,    1,    3,    1,    1,    3,    1,    1,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    1,    1,    1,    1,    3,    3,    3,    3,    3,
    3,    3,    2,    2,    2,    2,    3,    3,    3,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
   11,    4,    7,    5,    0,    4,    1,    1,    3,    0,
};
static const YYINT yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    4,    0,    0,    0,    0,    0,    0,    2,    0,    0,
   46,   65,   44,   47,   49,   50,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   62,   63,
    0,    0,    0,   75,   76,   80,    0,   73,    0,   74,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   51,    5,   33,    0,    6,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   72,   61,   97,    0,    0,   82,
   83,   84,   85,   86,    0,    0,   45,   48,   90,    0,
   87,   78,   88,   79,   89,    0,    0,   52,   53,   54,
   55,   56,   57,   58,   59,   77,   60,   66,   67,   68,
   69,   70,   71,    0,   92,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   18,    0,    0,    0,    0,    0,
    0,   81,   43,    0,    0,    0,    0,   96,    0,    0,
   34,   32,    0,    0,    0,    8,    0,    0,   28,   29,
   30,   31,    0,    0,    0,    0,    0,    0,    0,    0,
   99,    0,    0,    0,    0,    0,    0,   11,   12,   23,
   24,   25,   26,   13,   14,   15,    0,    0,    0,   10,
    9,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   94,    0,   91,    0,   16,   93,
};
static const YYINT yydgoto[] = {                          1,
    2,  116,   19,   20,   66,   21,   22,  185,  140,  146,
  147,  148,  149,  150,  117,   23,   24,   25,   26,   27,
   28,   99,
};
static const YYINT yysindex[] = {                         0,
    0, -156, -272, -258, -256, -250, -264, -303, -281, -279,
    0, -243, -261, -239, -203,   10,    0,    0, -192, -196,
    0,    0,    0,    0,    0,    0,   37, -268, -177, -243,
 -223, -243, -181,  -62, -170, -166, -161, -151,    0,    0,
 -149, -147,   53,    0,    0,    0, -263,    0, -203,    0,
 -203, -203, -203, -203, -227, -203, -203, -203, -203, -203,
   64,    0,    0,    0, -156,    0, -203, -203, -203, -203,
 -203, -203, -203, -203, -203, -203, -203, -203, -203, -203,
 -203, -203, -179, -145, -142, -135, -134, -118, -125, -199,
 -168, -125, -125, -125,    0,    0,    0, -124, -129,    0,
    0,    0,    0,    0, -241, -173,    0,    0,    0,   37,
    0,    0,    0,    0,    0, -156, -122,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -148,    0, -120, -196, -196, -162, -116,
 -144, -141, -138, -137,    0,  -99,  -94,  -92,  -91,  -88,
  -87,    0,    0,  -90,  -76,  -75, -263,    0, -147,   53,
    0,    0, -109, -251,  -52,    0,  -67, -196,    0,    0,
    0,    0, -196, -125, -125, -125, -125, -196, -196, -196,
    0,  -60, -104,  -97,  -63, -196,  -46,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -243,  -84, -156,    0,
    0,  -65,  -47, -156,  -37,  -79, -194,  -33,  -35,  -43,
 -204,  -30,  -21,    0,  -25,    0, -251,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,  261,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -131, -101,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -55,    0,    0,    0,
    0,    0,    0,  -10,   -4,   -3,   -2,   -1,    0,    0,
    0,  -45,  -55,    0,    0,    0,   -5,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    2,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -45,    3,    4,    0,
    0,    4,    4,    4,    0,    0,    0,    5,    0,    0,
    0,    0,    0,    0,    0,  -73,    0,    0,    0,   12,
    0,    0,    0,    0,    0, -262,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    8,   13,   14,   17,
 -152,    0,    0,    0,    0,    0,   -5,    0,    0,    0,
    0,    0,    0,   11,    1,    0,    0,    0,    0,    0,
    0,    0,    0,    4,    4,    4,    4,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   23,    0,
    0,    0,    0,   23,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   11,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  273,    0,    0,  -54,   -8,   -6,   59,    0,  -80,
    0,    0,    0,    0, -114,    9,   70,  243,  -36,  -12,
    0,  144,
};
#define YYTABLESIZE 375
static const YYINT yytable[] = {                         43,
    7,  161,   46,   41,   35,   42,   29,   33,  183,   97,
   36,  154,  155,  156,   35,   35,  184,   43,  109,   43,
   30,   84,   31,   86,   62,   87,   77,   78,   32,   79,
   80,   81,   37,   82,   38,   12,  100,  105,  101,  102,
  103,  104,  110,  111,  112,  113,  114,  115,  107,   34,
   98,  105,   44,  109,  118,  119,  120,  121,  122,  123,
  124,  125,  126,  127,  128,  129,  130,  131,  132,  133,
   39,   40,   39,   40,   45,   15,   64,  152,   48,   65,
   63,   50,  165,  166,  205,   83,  106,   40,   13,  208,
   85,   14,  160,  190,  191,  192,  193,   88,  159,  153,
    3,    4,    5,   91,    6,   47,    7,    8,    9,   10,
   39,   40,   92,  188,  151,   40,   11,   93,  189,  211,
   62,   62,   12,  194,  195,  196,   13,   94,   95,   14,
   96,  201,  135,   57,  134,  136,   59,  141,  142,  143,
  144,   40,  137,  138,  139,   61,   15,  145,  158,  157,
   62,  167,  163,   62,  162,  164,   62,   16,   17,   62,
   62,  168,   62,   62,   62,   62,   62,   62,   62,  169,
   62,   41,  170,   62,   62,  171,  172,   62,  173,  174,
   63,  175,  176,   63,   43,  177,   63,  178,  203,   63,
   63,   47,   63,   63,   63,   63,   63,   63,   63,   62,
   63,  179,  180,   63,   63,  182,  187,   63,   62,  186,
  198,   62,  197,  200,   62,  199,   89,   62,   62,  202,
   62,   49,  206,   62,   51,  207,   52,   53,  204,  209,
   54,   62,   62,  213,  210,   62,  215,  214,   90,   64,
   64,   56,   64,   64,   64,   58,   64,  216,   60,   65,
   65,  217,   65,   65,   65,  218,   65,    7,    7,    7,
    1,    7,   36,    7,    7,    7,    7,    7,   42,   37,
   38,   39,  100,    7,   18,  219,  212,    7,   35,    7,
   17,   27,   98,    7,   81,   19,    7,   95,   47,   35,
   20,   21,   48,   49,   22,   50,   51,  108,   52,   53,
  181,    0,   54,    7,    0,    0,    0,    0,    0,    0,
   55,    0,    0,   56,    7,    7,   57,   58,   67,   59,
   60,   68,    0,   61,   69,    0,    0,   70,   71,    0,
   72,    0,    0,   73,   67,    0,    0,   68,    0,    0,
   69,   74,   75,   70,   71,   76,   72,   49,    0,   73,
   51,    0,   52,   53,    0,    0,   54,   74,    0,    0,
    0,   76,    0,    0,   90,    0,    0,   56,    0,    0,
    0,   58,    0,    0,   60,
};
static const YYINT yycheck[] = {                         12,
    0,  116,   15,   12,  267,   12,  279,  272,  260,  273,
  314,   92,   93,   94,  277,    7,  268,   30,   55,   32,
  279,   30,  279,   32,   16,   32,  295,  296,  279,  298,
  299,  300,  314,  302,  314,  279,   49,  279,   51,   52,
   53,   54,   55,   56,   57,   58,   59,   60,   55,  314,
  314,  279,  314,   90,   67,   68,   69,   70,   71,   72,
   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
  314,  315,  314,  315,  314,  303,  273,   90,  283,  276,
  273,  286,  137,  138,  199,  263,  314,  315,  283,  204,
  314,  286,  105,  174,  175,  176,  177,  279,  105,   91,
  257,  258,  259,  274,  261,  279,  263,  264,  265,  266,
  314,  315,  279,  168,  314,  315,  273,  279,  173,  314,
  273,  274,  279,  178,  179,  180,  283,  279,  278,  286,
  278,  186,  278,  307,  314,  278,  310,  263,  264,  265,
  266,  273,  278,  278,  263,  314,  303,  273,  278,  274,
  282,  314,  301,  285,  277,  276,  288,  314,  315,  291,
  292,  278,  294,  295,  296,  297,  298,  299,  300,  314,
  302,  273,  314,  305,  306,  314,  314,  309,  278,  274,
  282,  274,  274,  285,  197,  274,  288,  278,  197,  291,
  292,  279,  294,  295,  296,  297,  298,  299,  300,  273,
  302,  278,  278,  305,  306,  315,  274,  309,  282,  262,
  315,  285,  273,  277,  288,  313,  279,  291,  292,  266,
  294,  284,  288,  297,  287,  273,  289,  290,  313,  267,
  293,  305,  306,  267,  314,  309,  280,  273,  301,  295,
  296,  304,  298,  299,  300,  308,  302,  278,  311,  295,
  296,  273,  298,  299,  300,  281,  302,  257,  258,  259,
    0,  261,  273,  263,  264,  265,  266,  267,  273,  273,
  273,  273,  278,  273,    2,  217,  207,  277,  277,  279,
  278,  278,  278,  283,  273,  278,  286,  277,  279,  267,
  278,  278,  283,  284,  278,  286,  287,   55,  289,  290,
  157,   -1,  293,  303,   -1,   -1,   -1,   -1,   -1,   -1,
  301,   -1,   -1,  304,  314,  315,  307,  308,  282,  310,
  311,  285,   -1,  314,  288,   -1,   -1,  291,  292,   -1,
  294,   -1,   -1,  297,  282,   -1,   -1,  285,   -1,   -1,
  288,  305,  306,  291,  292,  309,  294,  284,   -1,  297,
  287,   -1,  289,  290,   -1,   -1,  293,  305,   -1,   -1,
   -1,  309,   -1,   -1,  301,   -1,   -1,  304,   -1,   -1,
   -1,  308,   -1,   -1,  311,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 315
#define YYUNDFTOKEN 340
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
"SWITCH_TOK","CASE_TOK","IF_TOK","ELSE_TOK","INTEGER_TOK","FLOATING_TOK",
"DOUBLE_TOK","CHAR_TOK","BREAK_TOK","DEFAULT_TOK","RETURN_TOK","INCLUDE_TOK",
"DEFINE_TOK","MAIN_TOK","SEMICOLON_TOK","COMMA_TOK","DOT_TOK","LCURLY_TOK",
"RCURLY_TOK","RPAREN_TOK","LPAREN_TOK","ARRAY_BRACKET_LTOK",
"ARRAY_BRACKET_RTOK","ADDITION_TOK","INCREMENT_TOK","ADDITION_EQUAL_TOK",
"MINUS_TOK","DECREMENT_TOK","MINUS_EQUAL_TOK","MULTIPLICATION_TOK",
"MULTIPLICATION_EQUAL_TOK","DIVISION_EQUAL_TOK","DIVISION_TOK","MODULO_TOK",
"MODULO_EQUAL_TOK","RIGHT_SHIFT_TOK","GREATER_THAN_EQUAL_TOK","GREATER_TOK",
"LEFT_SHIFT_TOK","LESS_THAN_EQUAL_TOK","LESS_TOK","EQUAL_COMPARE_TOK",
"EQUAL_TOK","NOT_EQUAL_TOK","NOT_TOK","BIT_OR_EQUAL_TOK","BIT_OR_TOK","OR_TOK",
"AND_TOK","BIT_AND_EQUAL_TOK","BIT_AND_TOK","XOR_TOK","XOR_EQUAL_TOK",
"SPACE_TOK","COLON_TOK","ID_TOK","INT_CONST_TOK",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programe",
"programe : function",
"function : function statement",
"function :",
"statement : SEMICOLON_TOK",
"statement : expression SEMICOLON_TOK",
"statement : reserved_word balanced_paran",
"statement : IF_TOK LPAREN_TOK relational_expression RPAREN_TOK balanced_paran",
"statement : IF_TOK LPAREN_TOK arith_expression RPAREN_TOK balanced_paran",
"statement : IF_TOK LPAREN_TOK relational_expression RPAREN_TOK balanced_paran ELSE_TOK balanced_paran",
"statement : SWITCH_TOK LPAREN_TOK ID_TOK RPAREN_TOK LCURLY_TOK case_blocks RCURLY_TOK",
"statement : INTEGER_TOK MAIN_TOK LPAREN_TOK main_args RPAREN_TOK balanced_paran",
"statement : INTEGER_TOK ID_TOK LPAREN_TOK function_args RPAREN_TOK balanced_paran",
"statement : FLOATING_TOK ID_TOK LPAREN_TOK function_args RPAREN_TOK balanced_paran",
"statement : DOUBLE_TOK ID_TOK LPAREN_TOK function_args RPAREN_TOK balanced_paran",
"statement : CHAR_TOK ID_TOK LPAREN_TOK function_args RPAREN_TOK balanced_paran",
"main_args : INTEGER_TOK ID_TOK COMMA_TOK CHAR_TOK MULTIPLICATION_TOK ID_TOK ARRAY_BRACKET_LTOK ARRAY_BRACKET_RTOK",
"main_args :",
"function_args : SEMICOLON_TOK",
"function_args : int_arg",
"function_args : float_arg",
"function_args : double_arg",
"function_args : char_arg",
"function_args : int_arg COMMA_TOK function_args",
"function_args : float_arg COMMA_TOK function_args",
"function_args : double_arg COMMA_TOK function_args",
"function_args : char_arg COMMA_TOK function_args",
"function_args :",
"int_arg : INTEGER_TOK ID_TOK",
"float_arg : FLOATING_TOK ID_TOK",
"double_arg : DOUBLE_TOK ID_TOK",
"char_arg : CHAR_TOK ID_TOK",
"balanced_paran : LCURLY_TOK nested_statement RCURLY_TOK",
"balanced_paran : SEMICOLON_TOK",
"nested_statement : statement nested_statement",
"nested_statement :",
"expression : INTEGER_TOK ID_TOK",
"expression : FLOATING_TOK ID_TOK",
"expression : DOUBLE_TOK ID_TOK",
"expression : CHAR_TOK ID_TOK",
"expression : ID_TOK",
"expression : INT_CONST_TOK",
"expression : INTEGER_TOK assignment_expression",
"expression : INTEGER_TOK assignment_expression COMMA_TOK assignment_expression",
"expression : assignment_expression",
"expression : ID_TOK EQUAL_TOK arith_expression",
"expression : relational_expression",
"expression : unary_expression",
"expression : ID_TOK EQUAL_TOK logic_expression",
"expression : logic_expression",
"expression : func_call",
"expression : ID_TOK assignment_expression",
"arith_expression : operand ADDITION_TOK operand",
"arith_expression : operand MINUS_TOK operand",
"arith_expression : operand MULTIPLICATION_TOK operand",
"arith_expression : operand DIVISION_TOK operand",
"arith_expression : operand MODULO_TOK operand",
"arith_expression : operand RIGHT_SHIFT_TOK operand",
"arith_expression : operand LEFT_SHIFT_TOK operand",
"arith_expression : operand BIT_OR_TOK operand",
"arith_expression : operand BIT_AND_TOK operand",
"arith_expression : LPAREN_TOK arith_expression RPAREN_TOK",
"operand : ID_TOK",
"operand : INT_CONST_TOK",
"rel_operand : operand",
"rel_operand : arith_expression",
"relational_expression : rel_operand GREATER_THAN_EQUAL_TOK operand",
"relational_expression : rel_operand GREATER_TOK operand",
"relational_expression : rel_operand LESS_THAN_EQUAL_TOK operand",
"relational_expression : rel_operand LESS_TOK operand",
"relational_expression : rel_operand EQUAL_COMPARE_TOK operand",
"relational_expression : rel_operand NOT_EQUAL_TOK operand",
"relational_expression : LPAREN_TOK relational_expression RPAREN_TOK",
"unary_expression : ID_TOK INCREMENT_TOK",
"unary_expression : ID_TOK DECREMENT_TOK",
"unary_expression : INCREMENT_TOK ID_TOK",
"unary_expression : DECREMENT_TOK ID_TOK",
"logic_expression : operand OR_TOK operand",
"logic_expression : ID_TOK AND_TOK operand",
"logic_expression : ID_TOK XOR_TOK operand",
"logic_expression : NOT_TOK operand",
"assignment_expression : ID_TOK EQUAL_TOK operand",
"assignment_expression : ID_TOK ADDITION_EQUAL_TOK operand",
"assignment_expression : ID_TOK MINUS_EQUAL_TOK operand",
"assignment_expression : ID_TOK MULTIPLICATION_EQUAL_TOK operand",
"assignment_expression : ID_TOK DIVISION_EQUAL_TOK operand",
"assignment_expression : ID_TOK MODULO_EQUAL_TOK operand",
"assignment_expression : ID_TOK BIT_OR_EQUAL_TOK operand",
"assignment_expression : ID_TOK BIT_AND_EQUAL_TOK operand",
"assignment_expression : ID_TOK XOR_EQUAL_TOK operand",
"assignment_expression : ID_TOK EQUAL_TOK func_call",
"reserved_word : FOR_TOK LPAREN_TOK INTEGER_TOK ID_TOK EQUAL_TOK INT_CONST_TOK SEMICOLON_TOK relational_expression SEMICOLON_TOK unary_expression RPAREN_TOK",
"reserved_word : WHILE_TOK LPAREN_TOK relational_expression RPAREN_TOK",
"case_blocks : CASE_TOK INT_CONST_TOK COLON_TOK nested_statement BREAK_TOK SEMICOLON_TOK case_blocks",
"case_blocks : DEFAULT_TOK COLON_TOK nested_statement BREAK_TOK SEMICOLON_TOK",
"case_blocks :",
"func_call : ID_TOK LPAREN_TOK call_args RPAREN_TOK",
"call_args : SEMICOLON_TOK",
"call_args : ID_TOK",
"call_args : ID_TOK COMMA_TOK call_args",
"call_args :",

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
#line 193 "main.y"

int main(int argc,char *argv[]){
	#if YYDEBUG
		yydebug = 1;
	#endif
	if (argc == 2){
		yyin = fopen(argv[1],"r");
	}
	yyparse();
	fclose(yyin);
	return 0;
}
void yyerror(char *s){
	printf("%s\n","SORRY some syntax error is there. ........ :(");
	fprintf(stderr,"%s: next token of error token %d on line %d\n",s, yychar, yylineno-1);
}

void success(void){
	printf("%s\n","PARSED SUCCESSFULLY .......... :)");
}
#line 510 "y.tab.c"

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
#line 26 "main.y"
	{success();}
break;
#line 716 "y.tab.c"
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
