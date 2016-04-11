#include <stdio.h>
#include <string.h>

void sort(char *pointer[],int n){
	int i,j,k;
	char *temp;
	for(i = 0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(strcmp(pointer[k],pointer[j])>0) k=j;
			}
			if(k!=i){
				temp = pointer[i];
				pointer[i] = pointer[k];
				pointer[k] = temp;
				}
		}
	}

void print(char *pointer[],int n){
	for(int i=0;i<n;i++){
		printf("%s ",pointer[i]);
		}
	printf("\n");
	}



int main(){
	char *name[] = {"JAVA","PYTHON","C"};
	int n=3;
	
	sort(name,n);
	print(name,n);
	
	return 0;
	}
