//1块钱1瓶饮料， m个空瓶换1瓶饮料， 问n块钱可以喝多少瓶饮料。

#include <stdio.h>

int main(){
	int m,n;
	printf("请输入：几个空瓶换一瓶，共多少钱--");
	scanf("%d,%d",&m,&n);
	printf("%d个空瓶可以换一瓶饮料，共有%d元\n",m,n);
	
	int sum = n;
	while(n>m){
		sum+=n/m;
		n = n/m+n%m;
		}

	sum += (n==m-1);
	//有m-1的空瓶可以接一个空瓶子换一瓶喝了以后再把空瓶还回去。

	printf("共可以喝%d瓶饮料。\n",sum);
	
	return 0;
	}


