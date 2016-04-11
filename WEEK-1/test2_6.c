//将若干字符串按字母顺序（由小到大）输出。
#include <stdio.h>
#include <string.h>

void sort(char *strings[],int n){
	int i,j,k;
	char *temp;
	for(int i=0;i<n-1;i++){
		k=i;
		for(int j=i+1;j<n;j++){
			if(strcmp(strings[k],strings[j])>0) k=j;
			}
		if(k!=i){
			temp = strings[i];
			strings[i] = strings[k];
			strings[k] = temp;
			}
		}
	
	}

void print(char *strings[],int n){
	for(int i=0;i<n;i++){
		printf("%s\n",strings[i]);
		}
	
	}

int main(){
	char *strings[] = {"A one and A two", "Scent of A women","Good will Hunting","Die lieben das andern","Walle"};
	int n=5;

	sort(strings, n);
	print(strings,n);

	return 0;
	}
