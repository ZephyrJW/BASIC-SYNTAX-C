//
//  main.c
//  字符串
//
//  Created by mac on 16/4/6.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>//atoi()
#include <ctype.h> // toupper()  isdigit()

//返回字符串的长度，而尾零不计入长度（0 or '\0'）
int myStrlen(const char *p){
    int count = 0;
    while (*p != 0) {
        count++;
        p++;
    }
    return count;
}

char *myStrchr(const char *s, int n){
    //    while (*s != n) {
    //        s++;
    //    }
    //    return s;

    while(*s != 0 && *s++ != n);
    //开始的时候没有强转，导致会报出警告如下:
    //returning 'const char*'from a function with result type 'char *'discards qualifiers
    //return (char *)s-1;
    return *(s-1) == n ? (char *)s-1 : NULL;
}

char *myStrcpy(char *new, const char *old){
    while (*old != 0) {
        *new = *old;
        new++;
        old++;
    }
    //忘记补0了 也能行  再思考一下 应该是因为b后面全是0 初始化的时候 char b[20]。全是0
    *new = 0;
    return new;
}

char *myStrcat(char *old, char *add){
    char *t = old;
    while (*old++ != 0);
    old--;
    
    while ((*old++ = *add++));

    return t; // old 已经飞了 返回old没有意义哦
}

char *myStrstr(const char *target, const char *goal){
    char *dest = NULL;
    
    while ( *target != 0 ){
        char *goal_try = (char *)goal;
        if (*goal == *target){
            char *target_try = (char *)target;
            while (*target_try++ == *goal_try++);
            if (*(goal_try-1) == 0) {
                dest = (char *)(target);
                //不要忘记了break;
                break;
            }
        }
        target++;
    }
    
    return dest;
}

//cmu
int myStrcmp(const char *a, const char *b){
    /*这样写费劲还不行
    //asu    ucla
    //ucla   ucla
    while (*a != 0 && *b != 0 && *a++ == *b++);
    printf("%d,%d\n",*(a-1),*(b-1));
    return (*(a-1) == 0 || *(b-1) == 0)? (*(a-1) - *(b-1)):*a-*b;
     */
    while (*a++ == *b++) {
//        a++;
//        b++;
        //很重要的边界问题: 同时到底的时候两者都是\0仍然会往后走，不对了。
        if(*a==0 || *b==0)
            break;
    }
    return *(a-1)-*(b-1);
}

//linus strcmp
/*
 int ret = 0
 while(!((ret = *s1 - *s2++) || (!*s1++)))
    ;
 return ret;
 */


void *myMemset(void *a, int i, size_t n){
    char *p = a;
    
    while (n--) {
        *p++ = i;
        //不要忘记移动p
        //p++;
    }
    return a;
}


int myAtoi(const char *s){
    int sum = 0, flag=1;
    while (*s == ' '){
        s++;
    }
    
    if(*s == '+') {
        flag = 1;
        s++;
    }
    else if(*s == '-'){
        flag = -1;
        s++;
    }
    
    while (isdigit(*s)) {
        sum *= 10;
        sum += *s-'0';
        s++;
    }

    return sum*flag;
}


int main(int argc, const char * argv[]) {
    /*1. 使用strlen ， 实现myStrlen
    char a[10] = "hello";
    printf("%lu\n",sizeof(a));
    printf("%lu\n",strlen(a));
    printf("%d\n",myStrlen(a));
        %s是输出字符遇到尾零停止，否则不停
     */
    
    /*2. 实现strchr 在字符串中找到字符
    
    char a[] = "Hello world!";
    char *p = strchr(a, 'o');
    printf("%s\n",p);
    printf("%s\n",myStrchr(a, 'o'));
    */
     
    /*3. 实现strcpy 复制字符串
    char a[] = "this is a!";
    char b[20];
    myStrcpy(b,a);
    //strcpy(b, a);
    printf("%s\n",b);
     */
    
    /*4 实现strcat对两个字符串进行拼接
    char a[] = " Buffalo";
    char b[20] = "Hello";
    //strcat(b, a);
    myStrcat(b,a);
    printf("%s\n",b);
    */
    
    /*5 实现strstr对字符串中字符串的查找
    char a[] = "asdjfel,jfi i123f`_fe";
    char b[] = "i i";
    //char *find = strstr(a, b);
    char *find = myStrstr(a, b);
    printf("%s\n",find);
    */
    
    /*6 实现strcmp
    char a[] = "ucla";
    char b[] = "asu";
    int cmp = strcmp(a, b);
    printf("%d\n",cmp);
    printf("%d\n",myStrcmp(a,b));
    */
    
    
    
    /*7 实现memset
    int a[] = {1, 3, 5, 7, 9};
    myMemset(a, 0, sizeof(a));
    printf("%d\n",a[4]);
    
    char b[] = "bcd";
    //strlen返回的长度不包括尾0 而 sizeof返回的长度带着尾0
    myMemset(b, 'A', strlen(b));
    printf("%s\n",b);
    */
    
    /* 实现atoi
    
    char a[] = "1230";
    printf("%d\n",a[4]);
    printf("%d\n", myAtoi(a));//字符串的尾0是整形的0，ascii码是0 而字符的零是48
    printf("%d\n", atoi(a));
    */
    
    /*1 找出最后一个ccd
    char work1[] = "abccdeccddcccdeccded";
    char *p = strstr(work1, "ccd");
    while (strstr(p+1, "ccd") != NULL) {
        p = strstr(p+1, "ccd");
    }
    printf("%s\n",p);
     */
    
    /*2 找出cdc的个数 cdccdc算两个  cdcdc算一个
    char work2[] = "abccdcdcedcdccdceccdcedcdcdc";
    char *p1 = strstr(work2, "cdc");
    int count = 0;
    
    while (p1!=NULL) {
        count++;
        p1 = strstr(p1+3, "cdc");
    }
    
    printf("%d\n",count); 
    */
    
    /* strtok 使用指南
     char a[] = "number_of_lines";
     char *p = strtok(a,"_");
     printf("%s\n",p);
     
     p = strtok(NULL,"_");
     printf("%s\n",p);
     
     p = strtok(NULL, "_");
     printf("%s\n",p);
     //OFFICIAL GUIDE
     char input[16]="abc,d";
     char *p1;
     //strtok places a NULL terminator in front of the token,if found
     p1=strtok(input,",");
     if(p1)
     printf("%s\n",p1);
     //A second call to strtok using a NULL as the first parameter returns a pointer to the character following the token
     p1=strtok(NULL,",");
     if(p1)
     printf("%s\n",p1);
     // end of test in STRTOK
     */
    
    /* 3
     char a[] = "number_of_lines";
     char *p = strtok(a, "_");
     int count = 1;
     char b[50];
     strcat(b, p);
     
     while(p){
     if(count == 1) {
     count++;
     p = strtok(NULL, "_");
     continue;
     }
     *p = *p - 32;
     strcat(b, p);
     p = strtok(NULL, "_");
     }
     
     printf("%s\n", b);
    */
    
    //number_of_lines -> numberOfLines
    char work3[] = "number_of_lines";
    printf("%lu\n",strlen(work3));
    for (int i=0; i<strlen(work3); i++) {
        if (work3[i] != '_') continue;
        else {
            work3[i+1] -= 32;
            for (int j=i; work3[j] != 0; j++) {
                //无意识的把0也往前提了,因为j+1在最后一个元素时指的恰恰是0
                work3[j] = work3[j+1];
            }
        }
    }
    
    printf("%lu\n",strlen(work3));
    printf("%s\n",work3);

    
    return 0;
}