#include <stdio.h>

struct Student{
	long num;
	char name[20];
	float score[3];
	};

void _print(long number, struct Student *p){
	for(int i=0;i<5;i++){
		if((p+i)->num == number){
			for(int j=0;j<3;j++){
				printf("%.2f ",(*(p+i)).score[j]);
				}
			}
		}
	}

int main(){
	struct Student students[5];
	struct Student *p = students;
	printf("输入五位学生的信息:\n");
	for(int i=0;i<5;i++){
		scanf("%ld", &(p+i)->num);
		scanf("%s", (p+i)->name);
		for(int j=0;j<3;j++){
			scanf("%f",&(p+i)->score[j]);
			}
		}
	
	printf("你想查看学号为几的学生的成绩:");
	long number;
	scanf("%ld",&number);
	_print(number,p);
	printf("\n");
	
	return 0;
	}
