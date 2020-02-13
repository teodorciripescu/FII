#fisier folosit pentru compilarea lex yacc
	
all:
	yacc -d proj.y
	lex proj.l
	cc lex.yy.c y.tab.c -ly -ll -o compiler
	./compiler comptest.txt comptestout.txt