%{
#include<stdio.h>
int id=0,op=0,d=0,k=0;
extern FILE * yyin;
int yyerror();
int yylex();
%}
%token ID OP D K
%%
input : K input {k++;}
      | K {k++;}
      | ID input{id++;}
      | ID {id++;}
      | OP input {op++;}
      | OP {op++;}
      | D input {d++;}
      | D {d++;}
      ;
%%
void main()
{
yyin=fopen("program.c","r");
yyparse();
printf("Identifier count is %d \n",id);
printf("Operator count is %d \n",op);
printf("Digits count is %d \n",d);
printf("Keyword count is %d \n",k);
}
int yyerror()
{
printf("Invalid Input \n");
return 0;
}

