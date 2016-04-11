//在test2_3中，找到有不及格的课程的学生及其学号。

#include <stdio.h>

int main(){
	float score[][4] = {{40,65,70,75},{75,80,85,90},{100,100,90,55}};
	int n;
	float (*p)[4];

	for(int i=0;i<3;i++){
		p = score+i;
		for(int j=0;j<4;j++){
//第一次写了*(p+j) 指针想明白，只是个地址，这里的每个值都是个包含四个元素的数组
			if(*(*p+j)<60){
				printf("No.%d, his score:", i);
				for(int k=0;k<4;k++){ 
					printf("%.2f\t", *((*p)+k));
				}
				printf("\n");
				break;
				}
			}
		}	

	return 0;
	}
