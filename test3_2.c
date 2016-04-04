#include <stdio.h>
#include <stdlib.h>

void check(int *p){
	int i=0;
	printf("failers are:");
	for(;i<5;i++){
		if(*(p+i)<60) printf("%d  ",*(p+i));
	//if(p[i]<60) printf("%d ", p[i]); also does
		}
	printf("\n");
	}


int main(){
	int *p1,i;
	p1 = (int *)malloc(5 * sizeof(int));
	//malloc 必须包含 stdlib头文件， 返回是*void 所以要格式转换
	for(i = 0;i<5;i++){
		scanf("%d",p1+i);
		}
	check(p1);
	
	return 0;
	}
