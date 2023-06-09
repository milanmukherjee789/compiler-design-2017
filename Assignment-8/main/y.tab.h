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
extern YYSTYPE yylval;
