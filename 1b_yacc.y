%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
%}
%token NUM ENTER
%left '+' '-'
%left '*' '/'
%%
input: expr ENTER {printf("Result is %d\n",$$);exit(0);}
expr: expr '+' expr {$$=$1+$3;}
|expr '-' expr {$$=$1-$3;}
|expr '*' expr {$$=$1*$3;}
|expr '/' expr {if($3==0) {printf("Divide by zero error");exit(0);}else $$=$1/$3;}
|'(' expr ')' {$$=$2;}
|NUM {$$=$1;}
;
%%
void main()
{
printf("Enter the expression\n");
yyparse();
}
int yyerror()
{
printf("Invalid expression\n");
return 1;
}
