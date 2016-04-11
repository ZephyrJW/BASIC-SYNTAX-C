#include <stdio.h>
#include <string.h>

int main(){
	struct Person{
		char name[20];
		int count;
		};
	
	struct Person leaders[] = {"Li",0,"Wang",0,"Zhao",0};
	char vote[20];

	for(int i=0;i<10;i++){
		scanf("%s",vote);
		for(int j=0;j<3;j++){
			if(strcmp(vote,leaders[j].name)==0) leaders[j].count++;
			}
		}

	printf("\nResults:\n");
	for(int i=0;i<3;i++){
		printf("%s : %d\n",leaders[i].name,leaders[i].count);
		}

	
	return 0;
	}
