//有n个人围成一圈，顺序编号，从第一个人开始报数（从1到3报数），凡报到3的人退出圈子，问最后留下的时原来第几号的人。

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("请输入共有几个人围圈:");
	scanf("%d",&n);

	int *p = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		*(p+i) = 0;
		}
	int *start = p, *end = p+n-1;
	
	int people_remain = n;

	while(people_remain != 1){
		int count = 0;
		while(count != 3){
			while(*p == 1){
				if( p == end) p = start;
				else p++;
				}
			count++;
			if(count == 3){ 
				*p = 1; 
				}
			
			if(p == end){
				p = start;
				}else{p++;}
			}
		people_remain--;
		for(int i=0; i<n;i++){
			printf("%d ",*(start+i));
			}
			printf("\n");
		}

	p = start; //原本没有将start再赋予p，导致结果不对，p在循环后不指向数组头
	for(int i=0;i<n;i++){
		if(*(p+i)==0) printf("原编号为%d的人最后留下来了\n",i+1);
		}
	
	return 0;
	}
