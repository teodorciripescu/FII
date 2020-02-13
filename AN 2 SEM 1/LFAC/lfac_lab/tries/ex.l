%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"/*"(.|\n)+"*/" ;
"let" {return LET;}
"Object" {return OBJTYPE;}
\"[^\"]+\" {return STRINGVAL;}
"Array" {return ARRAYTYPE;}
"String" {return STRINGTYPE;}
"Number" {return NUMBERTYPE;}
[A-Za-z][A-Za-z0-9]* {return ID;}
[1-9][0-9]*|0 {return NR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
%%