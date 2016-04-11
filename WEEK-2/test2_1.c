//写一个函数建立一个有3名学生数据的单向动态链表。

#include <stdio.h>
#include <stdlib.h>

struct Student{
	long num;
	float score;
	struct Student *next;
	};

int n;

struct Student * _creat(){
	struct Student *head, *p1, *p2;
	p1 = p2 = (struct Student *)malloc(sizeof(struct Student));
	scanf("%ld,%f",&p1->num,&p1->score);
	head = NULL;
	while(p1->num != 0){
		n++;
		if(n == 1) head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = (struct Student *)malloc(sizeof(struct Student));
		scanf("%ld,%f",&p1->num,&p1->score);
		}
	p1->next = NULL;
	return head;
	}

int main(){
	struct Student *pt;
	pt = _creat();
	while(pt != NULL){
		printf("%ld,%.2f\n",pt->num,pt->score);
		pt = pt->next;
		}
//	while(n>0){
//		printf("%ld,%.2f\n",pt->num,pt->score);
//		n--;
//		pt = pt->next;
//		}

	return 0;
	}
