//
//  main.c
//  switch练习
//
//  Created by mac on 16/3/30.
//  Copyright © 2016年 mac. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
//    char score;
//    scanf("%c", &score);
//    
//    switch (score) {
//        case 'A':
//            printf("excellent\n");
//            break;
//            
//        case 'B':
//            printf("good\n");
//            break;
//            
//        default:
//            printf("default outcome\n");
//            break;
//    }
//    printf("end of switch\n");

//    
//    int month, day;
//    scanf("%d %d", &month, &day);
//    
//    int days_past = day;
//    
//    for (int i=1; i<=month; i++) {
//        switch (i) {
//            case 1:
//                break;
//            case 2:
//            case 4:
//            case 6:
//            case 8:
//            case 9:
//            case 11:
//                days_past += 31;
//                break;
//                
//            case 5:
//            case 7:
//            case 10:
//            case 12:
//                days_past += 30;
//                break;
//            
//            case 3:
//                days_past += 28;
//                break;
//                
//                
//            default:
//                printf("输入错误！\n");
//                break;
//        }
//    }
//    
//    printf("%d\n",days_past);
    
    /*2
    switch (month) {
        case 1:
            days_past += 0;
            break;
            
        case 2:
            days_past += 31;
            break;
            
        case 3:
            days_past += 59;
            break;
            
        case 4:
            days_past += 90;
            break;
            
        case 5:
            days_past += 120;
            break;
            
        case 6:
            days_past += 151;
            break;
            
        case 7:
            days_past += 181;
            break;
            
        case 8:
            days_past += 212;
            break;
            
        case 9:
            days_past += 243;
            break;
            
        case 10:
            days_past += 283;
            break;
            
        case 11:
            days_past += 314;
            break;
            
        case 12:
            days_past += 334;
            break;
        
        default:
            printf("输入有误！\n");
            break;
    }
    
    printf("%d\n", days_past);
    */
    
    /*2
    int a,flag = 1;
    printf("输入一个四位数:");
    scanf("%d",&a);
    if (a<0) {
        a = -a;
        flag = -1;
    }
    
    int new = a%10 * 1000 + (a/10)%10 * 100 + (a/100)%10 * 10 + (a/1000)%10;
    printf("%d\n",new*flag);
    */
    
    //*3
//    int a, flag = 1;
//    printf("输入一个不多于四位的数:");
//    scanf("%d", &a);
//    if(a<0){
//        a = -a;
//        flag = -1;
//    }
//    
//    int new;
//    switch (a/1000) {
//        case 0:
//            switch (a/100) {
//                case 0:
//                    switch (a/10) {
//                        case 0:
//                            new = a;
//                            break;
//                            
//                        default:
//                            new = a%10*10 + (a/10)%10;
//                            break;
//                    }
//                    break;
//                    
//                default:
//                    new = a%10*100 + (a/10)%10 * 10 + (a/100)%10;
//                    break;
//            }
//            break;
//            
//        default:
//            new = a%10 * 1000 + (a/10)%10 * 100 + (a/100)%10 * 10 + (a/1000)%10;
//            break;
//    }
//    
//    printf("%d\n", new*flag);
//    
   
    //*4
    printf("输入一个三位数，判断它是不是水仙花数：");
    int a,b;
    scanf("%d",&a);
    b = (a%10)*(a%10)*(a%10) + (a/10%10)*(a/10%10)*(a/10%10) + (a/100%10)*(a/100%10)*(a/100%10);
    
    switch (a - b) {
        case 0:
            printf("是！\n");
            break;
            
        default:
            printf("不是\n");
            break;
    }

    
//from 5_2 to 5_5
//    int a;
//    scanf("%d",&a);
    /* 5_2:
    switch (a>0) {    //switch condition has boolean value. is it okay?
        case 1:
            printf("正数\n");
            break;
            
        default:
            printf("负数\n");
            break;
    }
    */
    
    /* 5_3:
    switch (a%7) {
        case 0:
            printf("YES\n");
            break;
            
        default:
            printf("NO\n");
            break;
    }
    */
    
    /*5_4
    switch (a%10) {
        case 7:
            printf("YES\n");
            break;
            
        default:
            switch (a/10) {
                case 7:
                    printf("YES\n");
                    break;
                    
                default:
                    printf("No!\n");
                    break;
            }
            break;
    }
    */
    
    /*5_5
    switch (a%7) {
        case 0:
            printf("YES!\n");
            break;
            
        default:
            switch (a%10) {
                case 7:
                    printf("YES!\n");
                    break;
                    
                default:
                    switch (a/10) {
                        case 7:
                            printf("YES!\n");
                            break;
                            
                        default:
                            printf("NO!\n");
                            break;
                    }
                    break;
            }
            break;
    }
     */
    

    
    return 0;
}
