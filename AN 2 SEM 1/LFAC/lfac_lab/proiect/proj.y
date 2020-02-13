%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
extern FILE* yyin;
extern FILE* yyout;
extern char* yytext;
extern int yylineno;
int yyerror(char* s){
printf("eroare %s linia %d\n",s,yylineno);
}
%}
%union {
int intval;
char* strval;
}
%token BOOL NOT TRUE FALSE
%token INT FLOAT  NR NRF
%token CHAR STRING CARACTER CUVANT
%token MAREEGAL MICEGAL 
%token <strval>DEF BEG END
%token STRUCT CONST
%token IF THEN ELSE WHILE FOR
%left AND
%left OR
%left XOR
%left '*'
%left '/'
%left '%'
%left '+'
%left '-'
%start progr
%%
progr : instructiuni_globale BEG instructiuni END {printf ("input acceptat!\n");}
     ;

instructiuni_globale : instr_globala ';'
                     | instr_globala ';'instructiuni_globale 
                     ;

instructiuni : instr ';'
             | instr ';' instructiuni
             ;

instr_globala : declaratie_functie
              | initializare
              | constanta
              | declaratie_struct
              ;

constanta : CONST INT '~' NR
          | CONST FLOAT '~' NRF
          | CONST BOOL '~' TRUE
          | CONST BOOL '~' FALSE
          | CONST CHAR '~' CARACTER
          | CONST CHAR '[' NR ']' '~' CUVANT
          | CONST STRING '~' CUVANT
          ;

instr : asignare
      | expresie_booleena
      | expresie_aritmetica
      | expresie_str
      | apel_functie
      | daca
      | cat_timp
      | pentru
      ;

declaratie_functie : DEF fnc '(' lista_parametri ')' '{' instructiuni_functii '}'
                   ;

instructiuni_functii : instr ';'
                     | initializare ';'
                     | instr ';' instructiuni_functii
                     | initializare ';' instructiuni_functii
                     ;

lista_parametri : parametru 
                | parametru ',' lista_parametri
                ;

fnc : tip
    ;

tip : INT { fprintf(yyout, "| %s | variabila ",$<strval>$); fprintf(yyout, "| tip : INT |"); }
    | FLOAT
    | CHAR
    | STRING 
    | BOOL 
    ;

parametru : INT
          | FLOAT
          | CHAR
          | STRING
          | BOOL
          | tablou
          ;

tablou : INT '[' NR ']' 
       | FLOAT '[' NR ']' 
       | CHAR '[' NR ']'
       | STRING '[' NR ']'
       | BOOL '[' NR ']'
       | tablou '[' NR ']'
       ;


initializare : DEF tip { fprintf(yyout, "\n"); }
             | DEF tablou
             | DEF INT '~' NR
             | DEF INT '['NR ']' '~' '{' lista_valori_intregi '}'
             | DEF FLOAT '~' NRF
             | DEF FLOAT '['NR ']' '~' '{' lista_valori_reale '}'
             | DEF CHAR '~' CARACTER
             | DEF CHAR '[' NR ']' '~' CUVANT
             | DEF STRING '~' CUVANT
             | DEF STRING '[' NR ']' '~' '{' lista_cuvinte '}'
             | DEF BOOL '~' TRUE
             | DEF BOOL '~' FALSE
             | DEF BOOL '['NR']' '~' '{' lista_valori_booleene '}'
            
             ;
             /*
             | DEF FLOAT intrebare1 '}'
             | DEF INT intrebare2 '}'
             ;



intrebare1 : '[' NR ']' intrebare1 '{' lista_valori_reale '}'
           | '[' NR ']' '[' NR ']'  '~' '{' '{' lista_valori_reale '}' '{' lista_valori_reale '}'
           ;

intrebare2 : '[' NR ']' intrebare2 '{' lista_valori_intregi '}'
           | '[' NR ']' '[' NR ']'  '~' '{' '{' lista_valori_intregi '}' '{' lista_valori_intregi '}'
           ;

*/
lista_valori_reale : expresie_aritmetica
                   | expresie_aritmetica ',' lista_valori_reale
                   ;


lista_valori_booleene : expresie_booleena
                      | expresie_booleena ',' lista_valori_booleene
                      ;

lista_valori_intregi : expresie_aritmetica
                     | expresie_aritmetica ',' lista_valori_intregi
                     ;

lista_cuvinte : CUVANT
              | CUVANT ',' lista_cuvinte
              ;

declaratie_struct : DEF STRUCT '(' lista_parametri_struct ')'
                  ;

lista_parametri_struct : parametru 
                       | asignare 
                       | fnc '(' lista_parametri ')'
                       | lista_parametri_struct ',' fnc '(' lista_parametri ')'
                       | lista_parametri_struct ',' parametru 
                       | | lista_parametri_struct ',' asignare
                       ;

asignare : INT '~' expresie_aritmetica
         | INT '['NR ']' '~' '{' lista_valori_intregi '}'
         | FLOAT '~' expresie_aritmetica
         | FLOAT '['NR ']' '~' '{' lista_valori_reale '}'
         | CHAR '~' CARACTER
         | CHAR '[' NR ']' '~' CUVANT
         | STRING '~' CUVANT
         | STRING '[' NR ']' '~' '{' lista_cuvinte '}'
         | BOOL '~' expresie_booleena
         | BOOL '['NR']' '~' '{' lista_valori_booleene '}'
         | INT '~' apel_functie
         | FLOAT '~' apel_functie
         | BOOL '~' apel_functie
         | STRING '~' apel_functie
         | CHAR '~' apel_functie
         ;

expresie_booleena : exp_bool 
                  | expresie_booleena AND expresie_booleena 
                  | expresie_booleena OR expresie_booleena 
                  | expresie_booleena XOR expresie_booleena 
                  | '(' expresie_booleena ')'
                  | NOT '(' expresie_booleena ')'
                  ;

exp_bool : BOOL
         | TRUE
         | FALSE
         | expresie_aritmetica '>'expresie_aritmetica
         | expresie_aritmetica '<'expresie_aritmetica
         | expresie_aritmetica '='expresie_aritmetica
         | expresie_aritmetica '#'expresie_aritmetica
         | expresie_aritmetica MAREEGAL expresie_aritmetica
         | expresie_aritmetica MICEGAL expresie_aritmetica
         ;

expresie_aritmetica : exp_aritm 
                    | expresie_aritmetica '*' expresie_aritmetica
                    | expresie_aritmetica '/' expresie_aritmetica
                    | expresie_aritmetica '%' expresie_aritmetica
                    | expresie_aritmetica '+' expresie_aritmetica
                    | expresie_aritmetica '-' expresie_aritmetica
                    |'(' expresie_aritmetica ')'
                    | '-''(' expresie_aritmetica ')'
                    ;

exp_aritm : NR
          | NRF
          | INT
          | FLOAT
          ;

apel_functie : fnc '(' lista_parametri_extinsa ')'
             ;

lista_parametri_extinsa : parametri_extinsi
                        | parametri_extinsi ',' lista_parametri_extinsa
                        ;

parametri_extinsi : tablou
                  | STRING
                  | CHAR
                  | CARACTER
                  | CUVANT
                  | expresie_aritmetica
                  | expresie_booleena
                  | apel_functie
                  | constanta
                  ;

expresie_str : expresie_str '+' expresie_str
             | expresie_str '*' NR
             | STRING
             | CUVANT
             ;

daca : IF expresie_booleena THEN '{'instructiuni '}'
     | IF expresie_booleena THEN '{' instructiuni '}' ELSE '{' instructiuni '}'
     ;

cat_timp : WHILE expresie_booleena '{' instructiuni '}'
         ;

pentru : FOR asignare ';' expresie_booleena ';' expresie_aritmetica '{' instructiuni '}'
       ;


%%
int main(int argc,char** argv)
{
    yyout=fopen(argv[2],"w");
    yyin=fopen(argv[1],"r");
    fprintf(yyout, "start...\n");
    yyparse();
    fclose(yyout);
}