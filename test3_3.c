#include <stdio.h>
#include <stdlib.h>

void sort(int *p){
	int i,j,k;
	int temp;
	for(i = 0; i<2; i++){
		k = i;
		for(j = i+1; j<3;j++){
			if(p[k]>p[j]) k=j;
			}
		if(k != i){
			temp = p[i];
			p[i] = p[k];
			p[k] = temp;
			}
		}
	
	}

int main(){
	int *p;
	p = (int *)malloc(sizeof(int)*3);
	printf("enter 3 integers:");
	scanf("%d,%d,%d",&p[0],&p[1],&p[2]);
	sort(p);
	for(int i=0;i<3;i++){
		printf("%d ", *(p+i));
		}
	printf("\n");
	
	return 0;
	}
