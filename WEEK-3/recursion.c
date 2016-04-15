//
//  main.c
//  recursive
//
//  Created by mac on 16/4/11.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>

int getFactorial(int n){
    if (n<=1) {
        return 1;
    }
    
    return getFactorial(n-1) * n;
}

int getSum(int m){
    if (m>=100) {
        return 100;
    }

    return getSum(m+1) + m;
}

void printTriangle(int blank, int star){
    if (star < 1) {
        return;
    }
//正立的三角形
    printTriangle(blank+1, star-2);
    
    for (int i = 0; i<blank; i++) {
        printf(" ");
    }
    for (int i=0; i<star; i++) {
        printf("*");
    }
    printf("\n");
    
    //printTriangle(blank+1, star-2); 倒置的三角形
}

int main(int argc, const char * argv[]) {
    //递归求阶乘
    int n = getFactorial(5);
    printf("%d\n",n);
    //递归求和
    int m = getSum(1);
    printf("%d\n",m);
    //递归画等边三角形
    printTriangle(0, 5);
    
    
    
    
    return 0;
}
