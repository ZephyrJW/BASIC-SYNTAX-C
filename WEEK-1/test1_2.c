#include <stdio.h>

int main(){
	int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int *p = a[0];

	int i,j;
	printf("你想输出i行j列的元素:");
	scanf("%d, %d",&i,&j);

	printf("a[i][j] = %d \n",*(p+i*4+j));


	
	return 0;
	}
