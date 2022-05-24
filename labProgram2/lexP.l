%{
#include"y.tab.h"
#include<stdlib.h>
%}
%%
a {return A;}
b {return B;}
"\n" {return ENTER;}
. {printf("Invalid Input"); exit(0);}
%%
