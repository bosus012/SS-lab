%{
#include<stdio.h>
#include<stdlib.h>
int dig=0,id=0,op=0,key=0;
extern FILE *yyin;
int yylex();
int yyerror();
%}
%token DIGIT ID KEY OP
%%
input:DIGIT input {dig++;}
|ID input {id++;}
|OP input {op++;}
|KEY input {key++;}
|DIGIT {dig++;}
|ID {id++;}
|OP {op++;}
|KEY {key++;}
;
%%
//#include<stdio.h>
void main()
{
yyin=fopen("sample.c","r");
yyparse();
printf("Key count=%d\n",key);
printf("Operator count=%d\n",op);
printf("Identifier count=%d\n",id);
printf("Digit count=%d\n",dig);
}
int yyerror()
{
printf("INVALID");
return 1;
}