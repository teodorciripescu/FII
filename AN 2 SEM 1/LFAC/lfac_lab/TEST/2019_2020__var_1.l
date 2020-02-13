%{
#include <stdio.h>
#include "y.tab.h"
%}
valoare 0x(([0-9]+[a-zA-Z]*)|([0-9]*[a-zA-Z]+))
reg "eax"|"ebx"|"ecx"|"edx"|"ebp"|"esp"
%%
"eax"|"ebx"|"ecx"|"edx"|"ebp"|"esp" {return REGISTRU;}
"mov"|"add"|"sub"|"div"|"mul"|"xor"|"cmp" {return OP_REG_VAL;}
"push"|"pop" {return OP_STIVA;}
0x(([0-9]+[a-zA-Z]*)|([0-9]*[a-zA-Z]+)) {return VAL_16;}
"__main" {return MY_MAIN;}
"__loc__"{valoare} {return LOCATIE;}
"jnz __loc__"{valoare} {return JUMP;}
"jz __loc__"{valoare} {return JUMP;}
\[{reg}\] {return ZONA_MEM;} 
\[{reg}("+"|"-"){valoare}\] {return ZONA_MEM;}
"ret" {return MY_RETURN;}
"/*"(.|\n)+"*/" ;

[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
%%
 
