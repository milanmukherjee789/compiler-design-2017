yacc -d main.y
yacc -v main.y
lex main.l
gcc -g y.tab.c lex.yy.c -o main
