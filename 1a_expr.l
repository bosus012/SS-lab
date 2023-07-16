%{
#include<stdio.h>
int identifiers=0,operators=0,braces=0,alpha=0,spaces=0;
%}
%%
[a-zA-Z] {alpha++;printf("\nAlphabet:");ECHO;}
[0-9]* {identifiers++;printf("\nIdentifier:");ECHO;}
[+\*] {operators++;printf("\nOperator:");ECHO;}
"(" {braces++;}
")" {braces--;}
[ ] {spaces++;}
. {;}
%%
void main()
{
printf("Enter the expression:");

yylex();
if((braces==0) && (operators==identifiers-1) && alpha==0 && spaces==0)
{
printf("\nValid expression");
printf("\nNumber of operators:%d",operators);
printf("\nNumber of identifiers:%d\n",identifiers);
}
else
printf("\nInvalid expression");
printf("\n");
}
int yywrap()
{
return 1;
}
RESUL