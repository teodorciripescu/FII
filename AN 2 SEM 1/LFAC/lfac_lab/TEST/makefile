#fisier folosit pentru compilarea lex yacc
	
all:
	yacc -d 2019_2020_var_1.y
	lex 2019_2020__var_1.l
	cc lex.yy.c y.tab.c -ly -ll -o compiler
	./compiler test.txt