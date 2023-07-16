#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];
void check();
void main()
{
printf("GRAMMAR is E->E+T|T \n T->T*F|F \n F->(E) \n F->ID");
printf("Enter input string");
//gets(a);
scanf("%s",a);
c=strlen(a);
strcpy(act,"SHIFT->");
printf("stack \t input \t action");
for(k=0,i=0;j<c;k++,i++,j++)
{
if(a[j]=='i' && a[j+1]=='d')
{
 stk[i]=a[j];
 stk[i+1]=a[j+1];
 stk[i+2]='\0';
 a[j]=' ';
 a[j+1]=' ';
 printf("\n$%s\t%s$\t%sid",stk,a,act);
 check();
}

else
{
 stk[i]=a[j];
 stk[i+1]='\0';
 a[j]=' ';
 printf("\n$%s\t%s$\t%ssymbols",stk,a,act);
 check();
}// end else
}// end for
}// end main
//--------------------------------------------------------------------------------------------
void check()
{
strcpy(ac,"REDUCE");
//first for
for(z=0;z<c;z++)
 if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
 { 
 stk[z]='F';
 stk[z+1]='\0';
 stk[z+2]='\0';
 printf("\n$%s\t%s$\t%s",stk,a,ac); 
 i=i-2;
 }
//2nd for
 for(z=0;z<c;z++)
 if(stk[z]=='i' && stk[z+1]=='d')
 { 
 stk[z]='F';
 stk[z+1]='\0';
 printf("\n$%s\t%s$\t%s",stk,a,ac); 
 j++;
 }
//3rd for
 for(z=0;z<c;z++)
{
 if(stk[z]=='T' && stk[z+1]=='*' && stk[z+2]=='F')
 { 
 stk[z]='T';
 stk[z+1]='\0';

 stk[z+2]='\0';
 printf("\n$%s\t%s$\t%s",stk,a,ac); 
 i=i-2;
 }
 else if(stk[z]=='F')
 {
 stk[z]='T';
 printf("\n$%s\t%s$\t%s",stk,a,ac); 
 }
}
//4th for
for(z=0;z<c;z++)
{
 if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T' && stk[z+3]=='*')break;
 if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T')
{
 if(a[j+1]=='*')break;
 else
 { 
 stk[z]='E';
 stk[z+1]='\0';
 stk[z+2]='\0';
 printf("\n$%s\t%s$\t%s",stk,a,ac); 
 i=i-2;
 }//end else
}// end if
else if(stk[z]=='T')
 {
 stk[z]='E';
 printf("\n$%s\t%s$\t%s",stk,a,ac); 
 }
}//for ends
}//check()