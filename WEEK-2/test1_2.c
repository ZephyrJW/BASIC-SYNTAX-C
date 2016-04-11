#include <stdio.h>

struct student{
	long number;
	char name[20];
	float grades[3];
	float average;
	};

void input(struct student students[3]){
	struct student *p = students;
	for(int i=0;i<3;i++){
		float sum = 0;
		printf("输入第%d名学生的学号:",i+1);
		scanf("%ld",&(p+i)->number);
		printf("输入第%d名学生的姓名:",i+1);
		scanf("%s",(p+i)->name);
		printf("输入第%d名学生的成绩:",i+1);
		for(int j=0;j<3;j++){
			scanf("%f",(p+i)->grades+j);
			sum += (p+i)->grades[j];
			}
		(p+i)->average = sum / 3.0;
		}
	}

	struct student max(struct student students[3]){
		struct student res;
		res = students[0].average>students[1].average? students[0]:students[1];
		res = res.average > students[2].average? res : students[2];
		
		return res;
		}

	void print(struct student best){
		printf("最好的学生的信息为:\n");
		printf("%ld, %s, %.2f",best.number,best.name,best.average);
		
		}


int main(){
	struct student students[3];

	input(students);
	struct student best = max(students);
	print(best);

	return 0;
	}
