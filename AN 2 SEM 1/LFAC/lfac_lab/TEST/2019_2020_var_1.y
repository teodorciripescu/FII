%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%start s
%token REGISTRU OP_REG_VAL OP_STIVA VAL_16 MY_MAIN LOCATIE JUMP ZONA_MEM MY_RETURN
%%

s: progr {printf ("input acceptat!\n");}

progr: MY_MAIN ':' com MY_RETURN
     ;
com: com com 
     |OP_REG_VAL REGISTRU ',' REGISTRU
     |OP_REG_VAL REGISTRU ',' VAL_16
     |OP_REG_VAL REGISTRU ',' ZONA_MEM
     |OP_STIVA REGISTRU
     |OP_STIVA VAL_16
     |JUMP
     |LOCATIE ":"
     ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 