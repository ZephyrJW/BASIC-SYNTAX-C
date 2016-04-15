//
//  main.c
//  bit manipulation & struct
//
//  Created by mac on 16/4/12.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>

//常用宏macros
//将m的第n位置0   各部分加括号，整个再加括号！！ 命名最好全部大写之
#define setZero(m,n) ((m) &= (~(1<<n)))
//将m的第n位置1
#define setOne(m,n) ((m) |= (1<<n))
//将m的第n位取反
#define revIndexM(m,n) ((m) ^= (1<<n))

int Reverse(int m, int n){
    m ^= 1<<n;
    int tmp = m;
    
    for (int i = 31; i>= 0; i--) {
        // & 之前写的是 &=  过程中m的值不变
        if (m & (1<<i)) {
            printf("1");
        }else{
            printf("0");
        }
        
        if (i%4 ==0) {
            printf(" ");
        }
    }
    printf("\n");
    
    return tmp;
}

// power - exponent
int isPower(unsigned int num) {
    int res = 0;
    for (int i=31; i>=0; i--) {
        if (num & 1<<i) {
            res++;
        }
//        if (res >= 2) {
//            res = 0;
//            break;
//        }
    }

    return res == 1;
}

unsigned int circleMove(unsigned int m, int n){
    for (int i=0; i<n; i++) {
        //unsigned int h = (m & (1<<31)) != 0;
        //m<<1;
        //m |= h;
        if (m & 1<<31) {
            m <<= 1;
            m++;
        }else m <<= 1;
    }
    
    return m;
}
/*
 A 65 0100 0001  大写字符 010x xxxx  所以大写字符和小写字符的ascii码差了32
 a 97 0100 0001  小写字符 011x xxxx  ， 而不是连续存放的
 */



//用位运算进行tolower函数
int myToLower(int c){
    return c >= 'A' && c <='Z' ? (c | 1<<5) : c;
}

int main(int argc, const char * argv[]) {
 /*1 Introduction
    int a = 5;
    // 0000 0101
    //将一个数的第三位 置1， 置0， 取反
    //a |= 8;
    a |= 1<<3;
    printf("%d\n",a);
    //^运算符是，相等的置0，不同的置1...
    a &= ~(1<<3);
    printf("%d\n",a);
    a ^= 1<<3;
    printf("%d\n",a);
    
    int b = 5;
    setOne(b,3);
    printf("%d\n",b);
    setZero(b, 3);
    printf("%d\n",b);
    revIndexM(b, 3);
    printf("%d\n",b);
*/
    // 1. 将一个无符号整数的二进制（4位一组）打印出来
    // 2. 输入m（无符号整数）和n，返回m的第n位取反的结果（函数）
    printf("%d\n", Reverse(5,3));
    // 3. 输入一个数（无符号整数），判断这个数，是否为2的幂（函数）
//    unsigned int num;
//    scanf("%ud", &num);
//    printf("%d\n",isPower(num));
    // 4. 输入m（无符号整数）和n，将m向左循环移动n位，返回移位后的结果（函数） 移出的数字补到尾部去
    printf("%d\n", circleMove(0xf0000001, 4));
    
    return 0;
}
