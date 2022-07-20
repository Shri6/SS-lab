#include<stdio.h>
#include<stdlib.h>

void fifo(char s[], char fa[], int l, int f){
	int i, k, j=0, flag=0, count=0;
	printf("\n\tpage\tframes\t\t\tfaults");
	for(i=0; i<l;i++){
		for(k=0;k<f;k++){
			if(fa[k] == s[i])
				flag=1;
		}
		if(flag==0){
			printf("\n\t%c\t",s[i]);
			fa[j]=s[i];
			j++;
			for(k=0; k<f; k++)
				printf(" %c",fa[k]);
			printf("\t\t\tpage-fault %d", count);
			count++;
		}
		else{
			flag=0;
			printf("\n\t%c\t",s[i]);
			for(k=0; k<f; k++)
				printf(" %c",fa[k]);
			printf("\t\t\tno page-fault");
		}
		if(j==f)
		j=0;
	}
}

void lru(char s[], char fa[], int l, int f){
	int i, j=0, k, flag=0, count=0, m, top=0;
	printf("\n\tpage\tframes\t\t\tfaults");
	for(i=0; i<l; i++){
		for(k=0; k<f; k++){
			if(fa[k] == s[i]){
				flag=1;
				break;
			}
		}
		printf("\n\t%c\t",s[i]);
		if(j!=f && flag!=1){
			fa[top] = s[i];
			j++;
			if(j!=f)
				top++;
		}
		else{
			if(flag!=1){
				for(k=0; k<top; k++)
					fa[k] = fa[k+1];
				fa[top] = s[i];
			}
			if(flag==1){
				for(m=k; m<top; m++)
					fa[m] = fa[m+1];
				fa[top] = s[i];
			}
		}
		for(k=0; k<f; k++)
			printf(" %c", fa[k]);
		if(flag==0){
			printf("\t\t\tpage-fault %d", count);
			count++;
		}
		else
			printf("\t\t\tno page-fault");
		flag=0;
	}
}	

int main(){
	int choice, yn, f, l, i;
	char fa[10], s[25];
	printf("\nEnter the number of empty frames: \n");
	scanf("%d", &f);
	printf("Enter the length of the string: \n");
	scanf("%d", &l);
	printf("Enter the String : \n");
	scanf("%s",s);
	for(i=0; i<f;i++)
		fa[i] = -1;
	do{
		printf("******MENU*******\n");
		printf("1.FIFO\n2.LRU\n3.Exit\nEnter your choice : \n");
		scanf("%d", &choice);
		switch(choice){
			case 1: for(i=0; i<f; i++)
					fa[i] = -1;
				fifo(s,fa,l,f);
				break;
			case 2: for(i=0; i<f; i++)
					fa[i] = -1;
				lru(s,fa,l,f);
				break;
			case 3: exit(0);
		}
		printf("\n\nDo you want to continue? \n1.yes\n2.no\n");
		scanf("%d",&yn);
	}while(yn==1);
	return 0;
}		
