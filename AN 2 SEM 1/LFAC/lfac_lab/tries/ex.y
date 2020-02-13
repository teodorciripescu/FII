%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}

%start start
%token LET OBJTYPE STRINGVAL ARRAYTYPE STRINGTYPE NUMBERTYPE ID NR

%%

start : declaratii { printf("Programul este corect sintactic! \n");}
      ;
declaratii : declaratii declaratie ';'
           | declaratie ';'
           ;

declaratie : LET ID':'STRINGTYPE '=' STRINGVAL 
           | LET ID':'NUMBERTYPE '=' NR
           | LET ID':'ARRAYTYPE '=' '[' ']'
           | LET ID':'ARRAYTYPE '=' '['array']'
           | LET ID':'OBJTYPE '=' '{' '}'
           | LET ID':'OBJTYPE '=' '{'obiect'}'
           ;

array : array ',' array_elem
      | array_elem
      ;

array_elem : STRINGVAL
           | NR
           | '[' ']'
           | '{' '}'
           | '['array']'
           | '{'obiect'}'
           ;

obiect : obiect ',' obiect_elem
       | obiect_elem
       ;

obiect_elem : ID ':' STRINGVAL
            | ID ':' NR
            | ID ':'
            | ID ':' '{' '}'
            | ID ':' '[' ']'
            | ID ':' '{'obiect'}'
            | ID ':' '['array']'
            ;

%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
}