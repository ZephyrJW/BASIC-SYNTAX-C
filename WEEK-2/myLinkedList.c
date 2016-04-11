//
//  main.c
//  myLinkedList
//
//  Created by mac on 16/4/6.
//  Copyright © 2016年 mac. All rights reserved.
//

//实现链表的建立、输出、删除和插入。
//implement the creation, output, delete, and insert oprations.

#include <stdio.h>
#include <stdlib.h>

struct Student{
    int num;
    float aver;
    struct Student *next;
};

struct Student *_creat(int n){
    struct Student *head,*p1, *p2;
    p1 = p2 = (struct Student *)malloc(sizeof(struct Student));
    printf("请输入第1位学生的学号和平均成绩:");
    scanf("%d,%f",&p1->num,&p1->aver);
    head = NULL;
    
    for (int i=0; i<=n-1; i++) {
        if(i == 0) head = p1;
        else p2->next = p1;
        p2 = p1;
        
        if (i<n-1) {
        p1 = (struct Student *)malloc(sizeof(struct Student));
        //if(i < n-1){
        printf("请输入第%d位学生的学号和成绩:",i+2);
        scanf("%d,%f",&p1->num,&p1->aver);
        }
    }
    p2->next = NULL;
    return head;
}

void printList(struct Student *header){
    while (header != NULL) {
        printf("学号:%d,平均成绩:%.2f\n",header->num,header->aver);
        header = header->next;
    }
}

struct Student *delNode(struct Student *header, int num){
    struct Student *oldHeader = header;
    while (header != NULL) {
        if (num == header->num){
            oldHeader = header->next;
            printf("已删除学号为%d的学生信息!\n",num);
            break;
        }else{
                if (header->next != NULL && num == header->next->num) {
                header->next = header->next->next;
                printf("已删除学号为%d的学生信息!\n",num);
                break;
            }
        }
        header = header->next;
    }
    if(header == NULL) printf("输入信息有误!\n");
    return oldHeader;
}


void addNode(struct Student *header, int num, float score){
    struct Student *new = (struct Student *)malloc(sizeof(struct Student));
    new->num = num;
    new->aver = score;
    new->next = NULL;
    int count = 0;
    
    while (header != NULL) {
        count++;
        if (header->num == num) {
            printf("输入有误!该学号已经存在!\n");
        }
        
        if (num < header->num && count == 1){
            new->next = header;
            header = new;
            break;
        }
        
        if (header->next != NULL){
            if (header->num < num && header->next->num > num){
                new->next = header->next;
                header->next = new;
                break;
            }
        }
        
        if (header->next == NULL && header->num < num) {
            header->next = new;
            break;
        }
        
        header = header->next;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    printf("你要输入几个学生的信息:");
    scanf("%d",&n);
    
    struct Student *header = _creat(n);
    printList(header);
   
    printf("你想删除哪个学生的信息，输入学号:");
    int del_num;
    scanf("%d",&del_num);
    header = delNode(header, del_num);

    printf("请输入你想添加的学生信息--学号,成绩:");
    int add_num;
    float add_aver;
    scanf("%d,%f",&add_num,&add_aver);
    addNode(header,add_num,add_aver);
    
    printf("-------------------\n");
    printList(header);
    
    return 0;
}
