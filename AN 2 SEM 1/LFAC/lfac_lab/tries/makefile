#fisier folosit pentru compilarea lex yacc
	
all:
	yacc -d ex.y
	lex ex.l
	cc lex.yy.c y.tab.c -ly -ll -o compiler
	./compiler ex.txt