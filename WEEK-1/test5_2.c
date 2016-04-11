//将一个5*5的矩阵中最大的元素放在中心，四个角分别放置4个最小的元素（顺序为从左到右，从上到下依次从小到大存放），写一个函数实现之。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void set_max(int *p){
	int max=*p, mark = 0;
	for(int i=1;i<25;i++){
		if(*(p+i)>max) {
			max = *(p+i);
			mark = i;
			}
		}
	*(p+mark) = *(p+12);
	*(p+12) = max;
	}

void set_min(int *p, int m){
	int min = *(p+m), mark = m;
	for(int i=m+1;i<25;i++){
		if(*(p+i)<min){
			min = *(p+i);
			mark = i;
			}
		}
	*(p+mark) = *(p+m);
	*(p+m) = min;
	}

int main(){
	int a[5][5];
	int *p = &a[0][0];
	srand(time(NULL));
	for(int i=0;i<25;i++){
		*(p+i) = rand()%50;
		}
	
	set_max(p);
	set_min(p,0);
	set_min(p,1);
	set_min(p,2);
	set_min(p,3);

	int temp;
	temp = *(p+1);
	*(p+1) = *(p+4);
	*(p+4) = temp;

	temp = *(p+2);
	*(p+2) = *(p+20);
	*(p+20) = temp;

	temp = *(p+3);
	*(p+3) = *(p+24);
	*(p+24) = temp;

	for(int i=0;i<25;i++){
		printf("%3d",*(p+i));
		if((i+1)%5 == 0) printf("\n");
		}

	return 0;
	}
