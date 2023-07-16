%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
%}
%token A B ENTER
%%
input:S ENTER {printf("Correct grammar");exit(0);}
S:C B |B
C:A C|A
;
%%
void main()
{
printf("enter the string");
yyparse();
}
int yyerror()
{
printf("INVALID grammar");
return 1;
}
