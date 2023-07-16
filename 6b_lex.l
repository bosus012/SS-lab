%{
#include<stdio.h>
#include "y.tab.h"
extern int yylval;
%}
%%
[+\-\*\/] {printf("Operator:%s\n",yytext);return OP;}
[0-9]+ {yylval = atoi(yytext); printf("Digit is %d\n",yylval); return DIGIT;}
"void"|"int"|"main"|"printf" {printf("Keyword:%s\n",yytext);return KEY;}
[a-zA-Z]+ {printf("Identifier:%s\n",yytext);return ID;}
. ;
%%
int yywrap()
{
return 1;
}