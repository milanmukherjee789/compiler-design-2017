#include <stdio.h>
#define MSG_LENGTH 100
typedef char DATA;
typedef struct sym {
	DATA	data;
	struct sym *next;
	struct sym *prev;
} SYMBOL;

typedef struct startend {
	SYMBOL *start;
	SYMBOL *end;
} STARTEND;
typedef struct rule {
	SYMBOL *lhs;
	SYMBOL *rhs;
	struct rule *next;
	struct rule *prev;
} RULE;

typedef struct grammar {
	SYMBOL *v;
	SYMBOL *sigma;
	RULE *r;
	SYMBOL *s;
} GRAMMAR;
