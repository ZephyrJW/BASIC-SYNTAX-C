//
//  main.c
//  04.位字段
//
//  Created by YuTengxiao on 16/4/12.
//  Copyright © 2016年 YuTengxiao. All rights reserved.
//

#include <stdio.h>

// 位运算：最关键不是看它整体的值是多少，而是看其中的某一位，或某几位的值。最大的好处，就是节省存储空间。
// 年份 0000 ~ 3199  月1~12
//      年份后两位       日         是否上课         老师编号
// aaaaa bbbbbbb cccc ddddd eeeee   f      ggg      hh
// 年份前两位      月份       班总人数       上课阶段
// 位字段

// aaaa abbb bbbb cccc dddd deee eefg gghh
// 1010 0001 0000 0100 0110 0010 1010 0111
// 位字段
struct bits {
    unsigned int yearP:5;  // yearP占5个bit
    unsigned int yearB:7;
    unsigned int month:4;
    unsigned int day:5;
    unsigned int all:5;
    unsigned int isOnClass:1;
    unsigned int stage:3;
    unsigned int number:2;
};

// cd4c4214
// 1100 1101 0100 1100 0100 0010 0001 0100
// 1100 1101 0100 1100 0100 0010 0001 0100
int main(int argc, const char * argv[]) {
    // 定义一个位字段变量
    struct bits a;
    // 给其中的各个位，进行赋值
    a.yearP = 20;  //
    a.yearB = 16;  //
    a.month = 4;   //
    a.day = 12;    //
    a.all = 10;    //
    a.isOnClass = 1; //
    a.stage = 1;   //
    a.number = 3;  //
    printf("sizeof (a) = %lu\n", sizeof(a));
    printf("%x\n", *(int *)&a);
    printf("今天是%d%d年%d月%d日,现在班级总人数是%d人,是否上课%d,上课阶段%d,老师编号:%d", a.yearP, a.yearB, a.month, a.day, a.all, a.isOnClass, a.stage, a.number);
    return 0;
}
