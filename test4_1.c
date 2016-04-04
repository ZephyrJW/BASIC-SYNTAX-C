#include <stdio.h>
#include <stdlib.h>

void sort(int *p, int n, int m){
	int temp[m];
	for(int i=0;i<m;i++){
	//	*(p+n-m+i) = temp[i];
		temp[i] = *(p+n-m+i);
	}
	
	for(int i=n-m-1;i>=0;i--){
		//*(p+i+m) = *(p+i);
		p[i+m] = p[i];
		}

	for(int i=0;i<m;i++){
		//*(p+i) = temp[i];
		p[i] = temp[i];
		}
	
	}


int main(){
	int n,m;
	printf("请输入数组得大小，即n:");
	scanf("%d",&n);
	getchar();
	int *p;
	p = (int *)malloc(n * sizeof(int));
	
	for(int i=0;i<n;i++){
		scanf("%d",p+i);
		}
//	printf("%d\n",*p);----1

	printf("请输入m,将前面的n-m个数分别后移m个位置:");
	scanf("%d",&m);
	getchar();

	sort(p,n,m);

	for(int i=0;i<n;i++){
		printf("%d  ", *(p+i));
		}
	printf("\n");
	
	return 0;
	}
