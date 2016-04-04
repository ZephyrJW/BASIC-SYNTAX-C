#include <stdio.h>

void get_average(float (*p)[5]){
	int n;
	printf("请问你想查看第几门课程的成绩:");
	scanf("%d",&n);
	n--;

	float sum;
	for(int i=0;i<4;i++){
		sum += *(*(p+i)+n);
		}
	printf("%.2f\n",sum/4);
	}

void _low_performance(float (*p)[5]){
	for(int i=0;i<4;i++){
		float sum=0;
		int count = 0;
		for(int j=0;j<5;j++){
			sum += *(*(p+i)+j);
			if(*(*(p+i)+j)<60) count++;
			}
		if(count>=2){
			printf("多于两门不及格的学生是%d:",i);
			printf("成绩为:");
			for(int k=0;k<5;k++){
				if(k==4) {printf("%.2f\n",*(*(p+i)+k));break;}
				printf("%.2f,",*(*(p+i)+k));
				}
			printf("平均成绩为:%.2f\n",sum/5);
			}
		}	
	
	}


int main(){
	float data[4][5];
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			printf("请输入第%d个学生第%d门课的成绩:",i+1,j+1);
			scanf("%f",&data[i][j]);
			}	
	}

	float (*p)[5] = data;

	get_average(p);
	_low_performance(p);	
	
	return 0;
	}
