%{
#include"y.tab.h"
%}
%%
a {return A;}
b {return B;}
"\n" {return ENTER;}
. {printf("Invalid input");exit(0);}
%%

int yywrap()
{
return 1;
}