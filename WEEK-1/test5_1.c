//写一个函数，将一个3*3的矩阵转置
#include <stdio.h>

void sort(int (*p)[3]){
	int temp;
	for(int i=0; i<3; i++){
		for(int j=0; j<=i; j++){
			temp = *(*(p+i)+j);
			*(*(p+i)+j) = *(*(p+j)+i);
			*(*(p+j)+i) = temp;
			}
		}
	}

void print(int (*p)[3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d  ",*(*(p+i)+j));
			
			}
		printf("\n");
		}
	
	
	}

int main(){
	int a[][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int (*p)[3] = a;

	sort(p);
	print(p);

	return 0;
	}
