%{

#include<stdio.h>
#include "y.tab.h"
%}
caracter [A-Za-z0-9!@$%^&*()~+?\-*]
%%
"/$"(.|\n)+"$/" ;
("i"_[a-zA-Z0-9]+) {yylval.strval=strdup(yytext); return INT;}
("f"_[a-zA-Z0-9]+) {return FLOAT;}
("c"_[a-zA-Z0-9]+) {return CHAR;}
("s"_[a-zA-Z0-9]+) {return STRING;}
("b"_[a-zA-Z0-9]+) {return BOOL;}


"and" {return AND;}
"or" {return OR;}
"not" {return NOT;}
"xor" {return XOR;}
"true" {return TRUE;}
"false" {return FALSE;}

">=" {return MAREEGAL;}
"<=" {return MICEGAL;}


"def" { yylval.strval=strdup(yytext); return DEF;}
"beg" {return BEG;}
"end" {return END;}
"struct_"[a-zA-Z0-9]+ {return STRUCT;}
"const" {return CONST;}

"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}

[1-9][0-9]*|0 {return NR;}
([1-9][0-9]*\.[0-9]+)|(0\.[0-9]+) {return NRF;}
\'{caracter}\' {return CARACTER;}
\"{caracter}+\" {return CUVANT;}


[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
%%

