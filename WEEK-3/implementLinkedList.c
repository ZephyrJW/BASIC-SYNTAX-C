//
//  main.c
//  implementLinkedList
//
//  Created by mac on 16/4/14.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

enum Command {
    Exit = 0,
    CreatList,
    ShowList,
    FindNode,
    InsertNode,
    DeleteNode,
    SelectSort,
    InsertSort,
    ReverseList,
    //BubbleSort,
    DestroyList
};

typedef struct student{
    int age;
    char name[20];
    struct student *next;
} stu;

// 创建节点
stu *creatNode(){
    stu *node = (stu *)malloc(sizeof(stu));
    printf("请输入该人信息，格式为: 年龄 姓名   ");
    scanf("%d %s", &node->age, node->name);
    node->next = NULL;
    return node;
}

// 创建链表
stu *creatList(stu *head){
    if (head){
        printf("已经有链表了，请先销毁再创建!\n");
        return head;
    }
    
    int count;
    printf("要创建几个元素的链表:");
    scanf("%d", &count);
    
    head = creatNode();
    stu *tmp = head;
    while (--count) {
        stu *new = creatNode();
        tmp->next = new;
        tmp = new;
    }
    printf("链表创建成功!\n");
    return head;
}

// 遍历链表打印
void showList (stu *head) {
    if (!head) {
        printf("链表没有创建哦，请先创建链表\n");
        return;
    }
    
    printf("head->");
    while (head) {
        printf("%d %s->", head->age, head->name);
        head = head->next;
    }
    printf("NULL\n");
}

// 销毁链表
stu *destroyList(stu *head){
    if (!head) {
        printf("不存在链表，先创建，再销毁好吗?\n");
        return NULL;
    }
    
    stu *tmp = head;
    while (head) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    printf("链表删除成功!\n");
    return NULL;
}

// 查找节点
stu *findNode(stu *head, int age) {
    if (!head) {
        printf("请先创建链表!\n");
        return NULL;
    }
    
    while (head) {
        if (head->age == age) {
            break;
        }
        head = head->next;
    }
    if (!head) {
        printf("查找不到该信息的节点!\n");
    }
    return head;
}

// 插入(用于插入排序)
stu *insertList(stu *head, stu *new) {
    if (!head) {
        printf("请先建立链表再进行插入操作!\n");
        return NULL;
    }
    
    stu *tmp = head;
    stu *prev = tmp;
    while (tmp) {
        if (tmp->age > new->age) {
            if (tmp == head) {
                new->next = head;
                head = new;
            }else{
                prev->next = new;
                new->next = tmp;
            }
            break;
        }
        
        prev = tmp;
        tmp = tmp->next;
        //注意尾插操作的位置，因为条件是tmp==NULL,而循环判断条件是tmp != null，所以在这
        if (tmp == NULL) {
            prev->next = new;
        }
    }
    return head;
}

// 插入节点
stu *insertNode(stu *head) {
    if (!head) {
        printf("请先建立链表再进行插入操作!\n");
        return NULL;
    }
    stu *new = creatNode();
    head = insertList(head, new);
    return head;
}

// 删除节点
stu *deleteNode(stu *head, int delAge) {
    if (!head) {
        printf("请先创建链表，再进行删除操作!\n");
        return NULL;
    }
    
    stu *tmp = head;
    stu *prev = tmp;
    
    while (tmp) {
        if (tmp->age == delAge) {
            if (tmp == head) {
                head = head->next;
            }else if (tmp->next == NULL) {
                prev->next = NULL;
            }else{
                prev->next = tmp->next;
            }
            free(tmp);
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    
    if (prev->next == NULL) {
        printf("没有该包含该信息的节点!\n");
    }else{
        printf("删除成功!\n");
    }
    return head;
}

// 选择排序，厉害厉害，把结构体变量的指针当成数字来看
void selectSort(stu *head) {
    if (!head) {
        printf("请先创建指针，再进行排序操作!\n");
        return;
    }
    //从大到小排序
    for (stu *i = head; i->next != NULL; i = i->next) {
        for (stu *j = i->next ; j != NULL; j = j->next) {
            if (i->age < j->age) {
                stu tmp = *i;
                *i = *j;
                *j = tmp;
                //先进行结构体整体的交换，再交换i和j的指针 属性!!!
                stu *tmpP = i->next;
                i->next = j->next;
                j->next = tmpP;
            }
        }
    }
    printf("排序完成!\n");
}

// 插入排序
stu *insertSort(stu *head) {
    if (!head) {
        printf("先创建链表，再进行排序吧兄弟!\n");
        return NULL;
    }
    
    stu *newHead = head;
    head = head->next;
    newHead->next = NULL;
    //head = head->next; 本来这句在这，我以为没有影响
    stu *tmp = head;
    
    while (head) {
        head = head->next;
        tmp->next = NULL;
        newHead = insertList(newHead, tmp);
        tmp = head;
    }
    printf("排序完成!\n");
    return newHead;
}

// 冒泡排序  j = n - i -1 不好实现
// 逆序链表
stu *reverseList(stu *head){
    if (!head) {
        printf("请先创建链表，再进行逆序操作!\n");
        return NULL;
    }
    //写的时候要思考有没有漏掉的情况
    stu *lostLink = head->next;
    head->next = NULL;
    while (lostLink) {
        stu *tmp = lostLink->next;
        lostLink->next = head;
        head = lostLink;
        lostLink = tmp;
    }
    
    printf("逆序已完成，按2查看:)\n");
    return head;
}

int main(int argc, const char * argv[]) {
    int shouldContinue = 1;
    int cmd;
    stu *head = NULL;
    while (shouldContinue) {
        //case里不让定义变量
        stu *res;
        int age;
        int delAge;
        
        printf("--------------\n");
        printf("欢迎测试!\n1.创建链表\n2.遍历链表\n3.寻找节点\n4.插入节点\n5.删除节点\n6.选择排序\n7.插入排序\n8.逆序链表\n9.摧毁链表\n0.退出\n");
        printf("请输入指令 : ");
        scanf("%d", &cmd);
        switch (cmd) {
            case Exit:
                shouldContinue = 0;
                if (head) head = destroyList(head);
                break;
            case CreatList:
                head = creatList(head);
                break;
            case ShowList:
                showList(head);
                break;
            case FindNode:
                printf("请输入你想查找信息的年龄:");
                scanf("%d", &age);
                res = findNode(head, age);
                printf("找到的信息为: %s,%d\n", res->name, res->age);
                break;
            case InsertNode:
                head = insertNode(head);
                break;
            case DeleteNode:
                printf("请输入你想删除年龄为几的节点:");
                scanf("%d", &delAge);
                head = deleteNode(head, delAge);
                break;
            case SelectSort:
                selectSort(head);
                break;
            case InsertSort:
                head = insertSort(head);
                break;
            case ReverseList:
                head = reverseList(head);
                break;
            case DestroyList:
                head = destroyList(head);
                break;
            default:
                printf("输入指令错误，请看说明!\n");
                break;
        }
    }
    
    return 0;
}
