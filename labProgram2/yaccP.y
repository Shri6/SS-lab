%{
#include<stdio.h>
#include<stdlib.h>
int yyerror();
int yylex();
%}
%token A B ENTER
%%
input:S ENTER {printf("valid String"); exit(0);}
S: C B | B
C: A C | A
 ;
%%
void main()
{
printf("Enter the String");
yyparse();
}
int yyerror()
{
printf("Invalid \n");
return 0;
}
