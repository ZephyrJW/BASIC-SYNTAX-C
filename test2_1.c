#include <stdio.h>
int _min(int a, int b){
	return a>b? b:a;
	}

int _max(int a, int b){
	return a>b? a:b;
	}


int main(){
	printf("先输入两个数，若求最小值，再键入0。求最大值则键入1:");
	int a,b,flag;
	scanf("%d,%d,%d",&a,&b,&flag);

	int (*p)(int,int);
//	flag == 0? (p = _min): (p = _max);
	p = (flag == 0)? _min:_max;
	
	printf("result: %d\n",*p(a,b));
	
	return 0;
	}
