//
//  main.c
//  nesting loop
//
//  Created by mac on 16/3/31.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    /*1_1
    int n=10;
    for (int i = 1; i<=n; i++) {
        for (int j=0; j<i; j++) {
            printf("*");
        }
        printf("\n");
    }
    */
    
    /*
    
    int n;
    scanf("%d",&n);
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++) {
            printf(" ");
        }
        for (int j=0; j<=i; j++) {
            printf("*");
        }
        printf("\n");
    }
    */
     
    /*2
    int n=10;
    for (int i=n; i>0; i--) {
        for (int j=0; j<i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    */
    
    /*2_2
    int n;
    scanf("%d",&n);
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            printf(" ");
        }
        for (int j=0; j<n-i; j++) {
            printf("*");
        }
        printf("\n");
    }
    */
    
    /*3_1
    int n;
    scanf("%d",&n);
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++) {
            printf(" ");
        }
        for (int j=0; j<(i+1)*2-1; j++) {
            printf("*");
        }
        printf("\n");
    }
    */
    
    /*3_2
    int n;
    scanf("%d",&n);
    
    for (int i=0; i<n; i++) {
        for (int j=0; j< i; j++) {
            printf(" ");
        }
        for (int j=0; j<(n-i)*2-1; j++) {
            printf("*");
        }
        printf("\n");
    }
    */
    
    /*4_1
    int m,n;
    printf("m行,n列:");
    scanf("%d,%d",&m,&n);
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<i; j++) {
            printf(" ");
        }
        for (int j=0; j<n; j++) {
            printf("*");
        }
        printf("\n");
    }
     */
    
    /*4_2
    int m,n;
    printf("m行,n列:");
    scanf("%d,%d",&m,&n);
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<m-i-1; j++) {
            printf(" ");
        }
        for (int j=0; j<n; j++) {
            printf("*");
        }
        printf("\n");
    }
     */
    
    /*5_1 & 5_2
    int m;
    scanf("%d",&m);
    int n = (m+1)/2;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++) {
            printf(" ");
        }
        for (int j=0; j<(i+1)*2-1; j++) {
            printf("*");
        }
        printf("\n");
    }
    //5_2
    for (int i=0; i<n; i++) {
        for (int j=0; j< i; j++) {
            printf(" ");
        }
        for (int j=0; j<(n-i)*2-1; j++) {
            printf("*");
        }
        printf("\n");
    }
     */
    
    /*6
    int m,n;
    printf("梯形的底和顶m,n:");
    scanf("%d,%d",&m,&n);
    
    int line = (m-n)/2+1;
    
     //for(int i=n/2;i<=m/2;i++)
     
    for (int i=0; i<line; i++) {
        for (int j=0; j<(m-n)/2-i; j++) {
            printf(" ");
        }
        for (int j=0; j<n+i*2; j++) {
            printf("*");
        }
        printf("\n");
    }
    */
     
    /*7
    int m;
    scanf("%d",&m);
    
    for (int i = -(m/2); i<= m/2; i++) {
        for (int j=0; j< (i>0? i:-i); j++) {
            printf(" ");
        }
        for (int j=0; j< (i>0? m-i*2:m+i*2); j++) {
            printf("*");
        }
        printf("\n");
    }
    */
    
    /*8
    int m;
    scanf("%d",&m);
    
    for (int i=0; i<m ; i++) {
        for (int j=0; j<m; j++) {
            int a = i-m/2>0? i-m/2:m/2-i;
            int b = j-m/2>0? j-m/2:m/2-j;
            
            if(a+b == 2) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
     */
    
    //9*9乘法表:
    /*
    printf(" |1");
    for (int i=2; i<=9; i++) {
        printf("%7d", i);
    }
    printf("\n--------------------------------------------------------------\n");
    
    for (int i=1; i<=9; i++) {
        printf("%d| ",i);
        for (int j=1; j<=i; j++) {
            printf("%d*%d=%2d ",j,i,i*j);
        }
        printf("\n");
    }
    */
    
    /*------------------------advanced questions------------------------------*/
   /*1.
    int n, sum=0, mark=0;
    scanf("%d",&n);
    printf("%d = ",n);
    
    for (int i=1; i<=n/2; i++) {
        sum+=i;
        for (int j=i+1; j<=n/2+1; j++) {
            sum+=j;
            if (sum == n) {
                mark = i;
                sum = 0;
                break;
            }
        }
        if (mark != 0) {
            while (sum != n) {
                if(sum+mark == n){
                    printf("%d",mark);
                }else{
                    printf("%d+",mark);
                    }
                sum +=  mark;
                mark++;
            }
            if(mark <= n/2) printf(", ");
            //问题： 怎么能把，正确的输出
        }
        sum = 0;
        mark = 0;
    }
    printf("\n");
    
    */
    
    /*2
    int n;
    scanf("%d",&n);
    
    if(n==1) printf("1");
    else printf("1,");
    for (int i=1; i<=n; i++) {
        for (int j=2; j<=i; j++) {
            if(j==i && i != n) printf("%d,",i);
            if(i == n && j==i)  printf("%d",i);
            if (i%j == 0) {
                break;
            }
        }
    }
    printf("\n");
    */
    
    /*3
    int n,e;
    printf("输入你有多少钱以及几瓶空瓶换一瓶饮料n,e:");
    scanf("%d,%d",&n,&e);
    int m;
    m=n;
    
    while (m/e != 0) {
        n += m/e;
        m = m/e + m%e;
    }
    
    if(m==e-1) n++;
    
    printf("%d\n",n);
    */
    
//    printf(" |");
//    for (int i=0; i<3; i++) {
//        printf("%4c",'a'+i);
//    }
//    printf("\n-----------------\n");
//    for (int i=0; i<3; i++) {
//        printf("%c| \n",'x'+i);
//    }
    
    
    /*4
    char i,j,k; //i,j,k来指代a，b，c三人的对手 scheise
    for (i='x'; i<='z'; i++) {
        for (j='x'; j<='z'; j++) {
            for (k='x'; k<='z'; k++) {
                if(i!=j && i!=k && j!=k && i!='x' && j != 'x' && j!= 'z'){
                    printf("%c,%c,%c\n",i,j,k);
                }
            }
        }
    }
    */
    
    /*5
    int n;
    scanf("%d",&n);
    
    printf("%d = ",n);
    while (n != 1) {
        if (n%2 == 0) {
            n /= 2;
            printf("2");
        }else if (n%3==0){
            n /= 3;
            printf("3");
        }else if (n%5==0){
            n /= 5;
            printf("5");
        }
        if(n != 1) printf("*");
    }
    printf("\n");
    */
//    srand(time(NULL));
//    
//    for (int i=0; i<50; i++) {
//        int a = rand()%50;
//        printf("%3d",a);
//        
//        if ((i+1)%10==0) {
//            printf("\n");
//        }
//    }
    
    
    
    return 0;
}
