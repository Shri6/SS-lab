#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[20], act[20], ac[20], stk[50];
int i=0, c=0, z=0, j=0;
	
	
void check(){
	strcpy(ac, "REDUCE");
	for(z=0; z<c; z++){
		if(stk[z]=='i' && stk[z+1]=='d'){
			stk[z] = 'F';
			stk[z+1] = '\0';
			printf("\n%s\t%s\t%s",stk, s, ac);
			j++;
		}
	}
	for(z=0; z<c; z++){
		if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')'){
			stk[z] = 'F';
			stk[z+1] = '\0';
			stk[z+2] = '\0';
			printf("\n%s\t%s\t%s",stk, s, ac);
			i=i-2;
		}
	}
	for(z=0; z<c; z++){
		if(stk[z] =='T' && stk[z+1]=='*' && stk[z+2] =='F'){
			stk[z] = 'T';
			stk[z+1] = '\0';
			stk[z+2] = '\0';
			printf("\n%s\t%s\t%s",stk, s, ac);
			i=i-2;
		}
		else if(stk[z] == 'F'){
				stk[z] = 'T';
				printf("\n%s\t%s\t%s",stk, s, ac);
			
		}
	}
	for(z=0; z<c; z++){
		if(stk[z] =='E' && stk[z+1]=='+' && stk[z+2] =='T' && stk[z+3] == '*')
			break;
		if(stk[z] =='E' && stk[z+1]=='+' && stk[z+2] =='T'){
			if(s[j+1] == '*')
				break;
			else{
				stk[z] = 'E';
				stk[z+1] = '\0';
				stk[z+2] = '\0';
				printf("\n%s\t%s\t%s",stk, s, ac);
				i=i-2;
			}
		}
		else if(stk[z] == 'T'){
				stk[z] = 'E';
				printf("\n%s\t%s\t%s",stk, s, ac);
			}
		
	}
}

void main(){
	printf("\nThe grammer is\n");
	printf("\nE->E+T|T\nT->T*F|F\nF->(E)|id\n");
	printf("Enter the string :\n");
	gets(s);
	c=strlen(s);
	strcpy(act, "shift->");
	puts("stack \t input \t action");
	for(i=0; j<c; i++, j++){
		if(s[j] == 'i' && s[j+1] == 'd'){
			stk[i] = s[j];
			stk[i+1] =s[j+1];
			stk[i+2] = '\0';
			s[j] = ' ';
			s[j+1] = ' ';
			printf("\n%s\t%s\t%sid",stk, s, act);
			check();
		}
		else{
			stk[i] = s[j];
			stk[i+1] = '\0';
			s[j] = ' ';
			printf("\n%s\t%s\t%ssymbols",stk, s, act);
			check();
		}
	}
}
