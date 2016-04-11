//n个人围成一圈，从第1个人开始顺序报号1，2，3。凡报到3者退出圈子，找出最后留在圈子中的人原来的序号。用链表实现。
#include <stdio.h>
#include <stdlib.h>

int main(){
	struct people{
		int num;
		struct people *next;
		};

	int n;
	printf("输入有多少个人在玩这个游戏:");
	scanf("%d",&n);

	struct people *head, *p1, *p2;
	p1 = p2 = (struct people *)malloc(sizeof(struct people));
	p1->num = 1;
	head = NULL;

	for(int i=0;i<=n-1;i++){
		if(i==0) head = p1;
		else p2->next = p1;
		p2 = p1;
		
		p1 = (struct people *)malloc(sizeof(struct people));
		p1->num = i+2;
		}
	p2->next = head;

	//原本用while(head->next != NULL)做循环，报错。
	int count =0, people_remain = n;
	while(people_remain != 1){
		count++;
		if(count == 2){
			head->next = head->next->next;
			people_remain--;
			count = 0;
			}
		head = head->next;
		}

	printf("最后留下的人是:%d\n",head->num);
	return 0;
	}
