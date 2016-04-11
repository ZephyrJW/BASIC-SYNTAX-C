#include <stdio.h>

float *check(float (*pointer)[4]){ //开始为*pointer[4]
	float *p;
	p=NULL;
	for(int i=0;i<4;i++){
		if(*(*pointer+i)<60){
			p = *pointer;//开始写成了p = pointer;
			break;
			}
		}
	return p;
	}

int main(){
	float score[][4] = {{40,60,70,80},{70,80,80,90},{100,100,90,50}};
	float (*p1)[4] = score;//写成了*p1[4]
	float *p;

	for (int i=0;i<3;i++){
		p = check(p1+i);
		if(p != NULL){
			for(int j=0;j<4;j++){
				printf("%.2f\t",*(p+j));//本来是*(*p+j)
				}
		printf("\n");
		}
	}
	
	return 0;
	}
