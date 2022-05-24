%{
#include<stdio.h>
#include<stdlib.h>
int yyerror();
int yylex();
%}
%left '+' '-'
%left '*' '/'
%token NUMBER ENTER 
%%
input:expr ENTER {printf("Result is %d",$$);exit(0);}
expr: expr '+' expr{$$=$1+$3;}
	| expr '-' expr{$$=$1-$3;}
	| expr '*' expr{$$=$1*$3;}
	| expr '/' expr{if($3 == 0){printf("divide by 0 error");exit(0);}else{$$=$1/$3;}}
	| NUMBER{$$-$1;}
	;
%%
void main()
{
printf("Enter the String");
yyparse();
}
int yyerror()
{
printf("invalid\n");
return 0;
}
