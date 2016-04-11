//有a个学生，每个学生有b课程的成绩。要求在用户输入学生序号之后，能输出该学生的全部成绩。用指针函数来实现。我们假设3个学生4门课。
#include <stdio.h>

float *get_score(float (*p1)[4], int n){
	return *(p1+n);
	}

int main(){
	float score[][4] = {{60,65,70,75},{70,75,80,85},{85,90,95,100}};
	float *p;

	int n;
	printf("你想查看哪位同学的成绩:");
	scanf("%d",&n);

	p = get_score(score, n);

	for(int i=0;i<4;i++){
		printf("%.2f ", *(p+i));
		}
	printf("\n");
	
	return 0;
	}
