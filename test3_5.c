#include <stdio.h>
#include <stdlib.h>

int * input(int a[],int n){
	int *p = a;
	for(int i=0;i<n;i++){
		scanf("%d",p+i);
		}
	return p;
	}

void sort(int *p,int n){
	int min = *p,max=*p,flag_min,flag_max;
	for(int i=1;i<n;i++){
		if(*(p+i)<min){
			min = *(p+i);
			flag_min = i;
			}
		if(*(p+i)>max){
			max = *(p+i);
			flag_max = i;
			}
		}
	*(p+flag_min) = *p; *p = min;
	*(p+flag_max) = *(p+n-1); *(p+n-1) = max;
	}

void output(int *p, int n){
	for(int i=0;i<n;i++){
		printf("%d  ",*(p+i));
		}
	printf("\n");
	}

int main(){
	int n = 10;
	int a[n];
	int *p;

	p = input(a,10);
	sort(p,n);
	output(p,n);


	return 0;
	}
