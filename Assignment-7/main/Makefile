CC1 = yacc -d
CC2 = lex
CC3 = gcc
CFALGS = -g
parser: 
	$(CC1) main.y
	$(CC2) main.l
	$(CC3) $(CFALGS) lex.yy.c y.tab.c -o main
run:
	./main test_prog.c
clean:	
	rm lex.yy.c y.tab.c main
