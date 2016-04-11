//
//  main.c
//  WEEK-2 homework
//
//  Created by mac on 16/4/8.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


//1. 实现交换两个变量的值--值传递
void valueSwap(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
    printf("a:%d b:%d\n",a,b);
}
//2、11. 实现交换两个变量的值--地址传递
void addSwap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//3. 去两个数中较大的输出
int maxIn2(int a, int b){
    return a>b ? a : b;
}

//4. 取三个数中最大的输出
int maxIn3(int a, int b, int c){
    return ((a>b? a:b) > c? (a>b? a:b):c);
}

//5. 取得三个数中最小的数
int minIn3(int a, int b, int c){
    return ((a<b ? a:b) < c? (a<b ? a:b):c);
}

//6. 取得两个数中最小的数
int minIn2(int a, int b){
    return a<b? a:b;
}

//7. 两个数组的复制
void arrayCpy(int *b, const int *a, int n){
//    int m = (int)sizeof(b)/sizeof(int);
//    printf("%d\n",m);
    //写成上述形式，显示m的值为2，出错。
    while (n--) {
        *b++ = *a++;
    }
}

//8. 将一个指定的值插入到一个已经默认排好序的数组当中
void arrayInsert(int *a, int b, int n){
    for (int i=0; i<n; i++) {
        if(a[i] <= b) continue;
        int tmp = a[i];
        a[i] = b;
        b = tmp;
    }
}

//9. 将一个指定的值从一个已经默认排好序的数组当中删除
void arrayDel(int *a, int d, int n){
    int deleted = 0;
    for (int i = 0; i<n-1; i++) {
        if (a[i] != d && !deleted) {
            continue;
        }
        //开始没加deleted这类标记，导致1 3 5 7 9删除5变成 1 3 7 7, 也就是说后面的(9!=5)直接跳过了
        deleted = 1;
        a[i] = a[i+1];
    }
    a[n-1] = 0;
}

//10. 实现对任意输入数的累加
int accumu(int a){
    int sum = 0;
    while (a>0) {
        sum += a--;
    }
    return sum;
}

/*12. 用指针变量将数组输出
void printArray(int *p, int n){
    for (int i=0; i<n; i++) {
        printf("%d ",*(p+i));
    }
    printf("\n");
}
*/

//13. 用指针变量， 将字符数组中的小写字符变为大写字符并输出
void toLower(char *a){
    while (*a != 0) {
        if (*a >= 'a' && *a <= 'z') *a -= 32;
        printf("%c",*a);
        a++;
    }
    printf("\n");
}

//14. 用指针变量， 将字符数组中的大写字符变为小写字符并输出
void toUpper(char *a){
    while (*a != 0) {
        if (*a >= 'A' && *a <= 'Z') *a += 32;
        printf("%c",*a);
        a++;
    }
    printf("\n");
}

//17. 求两行三列的数组元素和
int arraySum(int (*a)[3]){
    int sum = 0;
    for (int i=0; i<2; i++) {
        for (int j= 0; j<3; j++) {
            sum += *(*(a+i)+j);
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    /*1.有问题 和第二题什么意思, 值传递没办法做到交换啊
    static int a, b;
    scanf("%d %d", &a, &b);
    //printf("befor swap : a: %p, b: %p\n", &a, &b);
    valueSwap(a, b);
    printf("a: %d, b: %d\n", a, b);
    */
    
    /*2
    int a,b;
    scanf("%d %d",&a, &b);
    addSwap(&a, &b);
    printf("a: %d, b:%d\n", a, b);
    */
    
    /*3、6
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d\n",maxIn2(a,b));
    printf("%d\n",minIn2(a,b));
    */
    
    /*4、5
    int a,b,c;
    scanf("%d %d %d",&a, &b, &c);
    printf("%d\n",maxIn3(a,b,c));
    printf("%d\n",minIn3(a,b,c));
    */
    
    /*6
    int a[5] = {};
    int b[5];
    //size_t m = sizeof(b);
    //printf("%lu----%lu\n", m--, m);
    for (int i=0; i<5; i++) {
        scanf("%d",&a[i]);
    }
    arrayCpy(b,a,5);
    for (int i=0; i<5; i++) {
        printf("%d ",b[i]);
    }
    printf("\n");
    */
    
    /*8
    int n;
    printf("你要向几元数组内插入元素:");
    scanf("%d",&n);
    int a[n+1];
    printf("请初始化整形数组的%d个元素:",n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    printf("请输入你想插入的元素值:");
    int b;
    scanf("%d",&b);
    
    arrayInsert(a, b, n+1);
    
    for (int i=0; i<n+1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    */
    
    /*9
    printf("你要建立几元的数组:");
    int n;
    scanf("%d",&n);
    printf("请初始化该数组:");
    int a[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("删除那个元素:");
    int d;
    scanf("%d",&d);
    
    arrayDel(a, d, n);
    
    for (int i=0; i<n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    */
    
    /*10
    int a;
    scanf("%d",&a);
    printf("%d\n",accumu(a));
    */
    
    /*12
    int a[5] = {3, 6, 3, 5, 7};
    printArray(a, 5);
    */
    
    /*13
    char a[] = "aeDrW";
    toLower(a);
    */
    
    /*14
     char a[] = "DgWyu";
     toUpper(a);
    */
    
    /*15
    int a = 5;
    int *p = &a;
    printf("%d\n",a);
    scanf("%d", p);
    printf("%d\n",a);
    */
    
    /*16
    int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int *p[10];
    for (int i=0; i<10; i++) {
        p[i] = &a[i];
    }
    for (int i=0; i<10; i++) {
        printf("%d ", *p[i]);
    }
    printf("\n");
    */
    
    /*17
    int a[2][3] = {{23,43,54},{77,2,9}};
    printf("%d\n",arraySum(a));
    */
    
    /*18
    char *p[] = {"23","43","54","77","2","9"};
    int n = (int)sizeof(p)/sizeof(void *);
    for (int i=n-1; i>=0; i--) {
        printf("%s\n",p[i]);
    }
    */
    
    /*19
    char *p[] = {"asdfw","asdwwfr","sdfeqw"};
    int n = sizeof(p)/sizeof(void *);
    for (int i=0; i<n; i++) {
        printf("%s\n",p[i]);
    }
    */
    
    /*20
    char a[20];
    int i=0;
    for (; i<20; i++) {
        scanf("%c",&a[i]);
        //'\n'的ascii码为10
        if (a[i] == 10) break;
    }
    printf("%d\n", i);
    */
    
    /*21
    const char a[20] = "arizona state";
    char b[20];
    strcpy(b, a);
    printf("%s\n%s\n",a,b);
    */
    
    /*22
    char a[20];
    scanf("%s",a);
    printf("%s\n",a);
    memset(a, 'a', strlen(a)+1);
    printf("%s\n",a);
    */
    
    /*23
    char a[20], b[20];
    scanf("%s",a);
    memcpy(b, a, strlen(a)+1);
    printf("a: %s\nb: %s\n",a,b);
    */
    
    /*24
    char a[] = "sgfgeasdfw";
    char b[] = "hhff";
    char *p = strstr(a, b);
    if (p) printf("yes\n");
    else printf("no\n");
    */
    
    /*25
    char a[] = "fgjhwase";
    char b = 'a';
    int i=0;
    for (; i<strlen(a); i++) {
        if(a[i] == b) break;
    }
    if ( i == strlen(a)) printf("没有\n");
    else printf("%d\n",i+1);
    */
    
    /*26
    char a[] = "fgjhwaej";
    char b = 'j';
    int i=0, count =0;
    for (; i<strlen(a); i++) {
        if (a[i] == b) {
            printf("%d\n",i+1);
            count++;
        }
    }
    if (count == 0) printf("没有\n");
    */
    
    /*27
    char a[] = "fgjhwaejwaekkae";
    char b[] = "ae";
    int count = 0;
    char *p = strstr(a, b);
    while (p) {
        count++;
        p = strstr(p+1, b);
    }
    printf("%d\n",count);
    */
    
    /*28
    char *a = "asdfwd";
    char *b = "wd";
    char *c = strstr(a, b);
    printf("%ld\n",c-a+1);
    */
    
    /*29
    char *a = "fgjhwaejh";
    char *b = "jh";
    char *c = strstr(a, b);
    while (c) {
        printf("%ld\n",c-a+1);
        c = strstr(c+1, b);
    }
    */
    
    /*30
    char *a = "sdkfjelkjfsdk";
    int count = 0;
    while (*a != 0){
        count++;
        a++;
    }
    a--;
    while (count-- >= 0) {
        printf("%c",*a--);
    }
    printf("\n");
    */
    
    /*31
//    char a[] = "hhfhhhhff";
//    char *p = a;
//    char b[20];
//    int mark=0;
//    while (*p != 0) {
//        char tmp = *p;
//        b[mark++] = *p;
//        int count = 0;
//        while (*p == tmp) {
//            count++;
//            p++;
//        }
//        b[mark++] = count+'0';
//    }
//    b[mark] = 0;
//    printf("%s\n",b);
    
    char a[] = "hhfhhhhff";
    char *p = a;
    char b[20];
    char *q = b;
    while (*p != 0) {
        char tmp = *p;
        *q++ = *p;
        int count = 0;
        while (*p == tmp) {
            count++;
            p++;
        }
        *q++ = count+'0';
    }
    //之前用q输出怎么也不行，因为q已经走远了啊
    printf("%s\n",b);
*/
    
    /*32
    char a[] = "e5a3f2";
    char res[20];
    char *p = a, *q = res;
    
    while (*p != 0) {
        char tmp = *p++;
        int num = (*p++) - '0';
        while (num--) {
            *q++ = tmp;
        }
    }
    printf("%s\n", res);
     */
    
    /*33
    char a[] = "abcd765bbw1357f123";
    char *p = a;
    int maxCount = 0;
    char *mark = NULL;
    while (*p != 0) {
        if (!isdigit(*p)) {
            p++;
            continue;
        }
        char *q = p;
        int numCount = 1;
        while (isdigit(*p++)) {
            if(*p - *(p-1) == 1) {
                numCount++;
            }else break;
        }
        if(maxCount < numCount){
            maxCount = numCount;
            mark = q;
        }
    }
    
    for (; isdigit(*mark); mark++) {
        if(isdigit(*(mark-1)) && *mark - *(mark-1) != 1) break;
        printf("%c",*mark);
    }
    printf("\n");
     */
    
    /*34
    char a[] = "f2e1i12g21i3";
    char *p = a;
    int maxCount = 0;
    char *mark = NULL;
    while (*p != 0) {
        if (!isdigit(*p)) {
            p++;
            continue;
        }
        char *q = p;
        int numCount = 1;
        while (isdigit(*p++)) {
            if(*(p-1) - *p == 1) {
                numCount++;
            }else break;
        }
        if(maxCount < numCount){
            maxCount = numCount;
            mark = q;
        }
    }
    
    for (; isdigit(*mark); mark++) {
        if(isdigit(*(mark-1)) && *(mark-1) - *mark != 1) break;
        printf("%c",*mark);
    }
    printf("\n");
    */
    
    /*35
    char a[] = "f123fed2wf3210abcd";
    char *p = a;
    int maxCount = 0;
    char *mark = NULL;
    while (*p != 0) {
        if (!isalpha(*p)) {
            p++;
            continue;
        }
        char *q = p;
        int numCount = 1;
        while (isalpha(*p++)) {
            if(*(p-1) - *p == 1) {
                numCount++;
            }else break;
        }
        if(maxCount < numCount){
            maxCount = numCount;
            mark = q;
        }
    }
    
    for (; isalpha(*mark); mark++) {
        if(isalpha(*(mark-1)) && *(mark-1) - *mark != 1) break;
        printf("%c",*mark);
    }
    printf("\n");
    */
    
    /*36
    char a[] = "fe1i12ghi21i3";
    char *p = a;
    int maxCount = 0;
    char *mark = NULL;
    while (*p != 0) {
        if (!isalpha(*p)) {
            p++;
            continue;
        }
        char *q = p;
        int numCount = 1;
        while (isalpha(*p++)) {
            if(*p - *(p-1) == 1) {
                numCount++;
            }else break;
        }
        if(maxCount < numCount){
            maxCount = numCount;
            mark = q;
        }
    }
    
    for (; isalpha(*mark); mark++) {
        if(isalpha(*(mark-1)) && *mark - *(mark-1) != 1) break;
        printf("%c",*mark);
    }
    printf("\n");
    */
    
    /* 37  39
    char a[50];
    char *p = a;
    scanf("%s",a);
    int count = 0;
    while (*p++ != 0) {
        if(isupper(*p)) count++;
    }
    printf("%d\n",count);
    */
    
    /*38
    char a[50];
    char *p = a;
    scanf("%s",a);
    int count = 0;
    while (*p++ != 0) {
        if(islower(*p)) count++;
    }
    printf("%d\n",count);
    */
    
    /*40 41
    char a[50];
    char *p = a;
    scanf("%s",a);
    getchar();
    
    char d;
    scanf("%c", &d);
    
    while (*p != 0) {
        //p++ 不可以先移动p 因为首位也许就是你想删除的字符呢
        if(*p == d){
            char *q = p;
     //嵌套while因为可能出现772WdfWFDGWH3rd - d 的情况 需要删除两个d
            while (*q != 0) {
                *q = *(q+1);
                q++;
            }
            //漏掉一种情况，两个要删除的字符是连着的 只能删除一个。 加下面一句就可以了
        }
        if(*p != d) p++;
    }
    
    printf("%s\n",a);
    */
    
    /*42
    char a[50];
    char *p = a;
    scanf("%s",a);
    getchar();
    
    char d;
    scanf("%c", &d);
    d = isupper(d)? d+32:d;
    
    while ((*p != d || *p != d-32) && *p != 0) {
        p++;
        if(*p == d || *p == d-32){
            char *q = p;
            while (*q != 0) {
                *q = *(q+1);
                q++;
            }
        }
        if(*p == d || *p == d-32) p--;
    }
    
    printf("%s\n",a);
    */
    
    /*43
    char a[50];
    scanf("%s",a);
    char *p = a;
    
    
    while (*p != 0) {
        if (isdigit(*p)){
            char *q = p;
            while (*q++ != 0) {
                *(q-1) = *q;
            }
        }
        if(!isdigit(*p))p++;
    }
    
    printf("%s\n",a);
    */
    
    /*44
    char a[50];
    scanf("%s",a);
    getchar();
    char *p = a;
    char replacement;
    scanf("%c", &replacement);
    getchar();
    char new;
    scanf("%c", &new);
    
    while (*p != 0) {
        if (*p == replacement) {
            *p = new;
        }
        if (*p != replacement) p++;
    }
    
    printf("%s\n",a);
    */
    
    /*45
    char a[50];
    scanf("%s",a);
    int len = (int)strlen(a);
#if 0
    //选择
    for (char *p = a; *p != 0; p++) {
        for (char *q = p+1; *q != 0; q++) {
            if (*p > *q){
                char tmp = *p;
                *p = *q;
                *q = tmp;
            }
        }
    }
#else
    //冒泡
    for (int i= 0; i<len-1; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if(a[j] > a[j+1]){
                char tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
#endif
    printf("%s\n",a);
    */
    
    /*46、47
    char a[50];
    char b[50];
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    getchar();
    
    char *p = a, *q = b, *m = NULL;
    char *q_orginal = b;
    int count = 0;
    //针对a数组的指针有: p，pMark. 因为在for循环内的while循环会使p一直移动，所以每次要循环p时定义一个mark保留当前p的位置以输出或接到上一次循环时到达的位置。
    //针对b数组的指针有: q,q_orginal,qMark(在while循环内部进行移动则不需要它)。作用类似。
    for (; *p != 0; p++) {
        char *pMark = p;
        //printf("\np: %c  \n",*p);
        for (; *q!=0; q++) {
            count = 0;
            //char *qMark = q;
            //printf("  q: %c",*q);
            while (*p == *q) {
                count++;
                p++;
                q++;
               // printf("  count: %d",count);
            }
            if (count > 1) break;
            //q = qMark;
            //p = pMark;
        }
        if (count > 1){
            m = pMark;
            break;
        }
        p = pMark;
        q = q_orginal;
    }
    
    while (count--) {
        printf("%c",*m++);
    }
    printf("\n");
    */
    
    
    /*48 & 49
    char a[20];
    scanf("%s",a);
    getchar();
    printf("%s\n",a);
    
    char *p = (char *)malloc(20*sizeof(char));
    scanf("%s",p);
    getchar();
    printf("%s\n",p);
    */
    
    /*50
    char a[20];
    char b[20];
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    getchar();
    
    printf("%s\n", strlen(a) > strlen(b) ? a : b);
    */
    
    /*51
    char a[40];
    char b[20];
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    getchar();
    
    printf("%s\n", strcat(a, b));
    */
    
    char a[20], b[20], c[20];
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    getchar();
    scanf("%s",c);
    getchar();
    
    printf("最小: %s\n",strcmp(a,b) > 0 ? (strcmp(b,c)>0? c : b ) : (strcmp(a,c)>0? c : a));
    printf("%s\n",strcmp(a, b)>0 ? (strcmp(b, c) > 0 ? b : c) : (strcmp(a, c) ? a : c));
    printf("最大: %s\n", strcmp(a, b) > 0 ? (strcmp(a, c)> 0 ? a : c) : (strcmp(b, c) > 0? b:c));
    
    return 0;
}
