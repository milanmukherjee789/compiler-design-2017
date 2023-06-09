yacc -d main.y
yacc main.y
lex main.l
gcc lex.yy.c y.tab.c -o main
