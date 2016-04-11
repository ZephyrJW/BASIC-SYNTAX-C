#include <stdio.h>

int _max(int a, int b){
	return a>b? a:b;
	}

int _min(int a, int b){
	return a>b?b:a;
	}

int _sum(int a, int b){
	return a+b;
	}

int main(){
	int a,b;
	printf("enter a and b:");
	scanf("%d, %d",&a,&b);
	printf("indicate operation,1--max, 2--min, 3--sum:");
	int flag;
	scanf("%d",&flag);

	int (*p)(int ,int);
	if(flag==1) p = _max;
	else if(flag == 2) p = _min;
	else p = _sum;

	printf("%d\n",p(a,b));
	
	return 0;
	}
