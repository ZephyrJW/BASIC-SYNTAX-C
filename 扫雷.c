//
//  main.c
//  扫雷
//
//  Created by mac on 16/4/2.
//  Copyright © 2016年 mac. All rights reserved.
//

//一些不足：输入可能出界,导致数组越界
/*另外一种思路：
 用两个数组来记录，一个用来记录地雷的位置并且通过该数组中地雷的位置来生成各位置应该generate出来的周边雷数
 ，另外一个数组来记录某个位置是否被翻开过。
 
 输出时，若翻开了（1）则输出地雷数组中的值，若没翻开（0）则输出‘*’
 */

#include <stdio.h>
#include <stdlib.h>

//随机生成十颗地雷，存储它们的坐标
void initbombs(int result[10][2]){
    int x,y;
    
    for (int i=0; i<10; i++) {
        x = arc4random()%9;
        y = arc4random()%9;
        result[i][0]=x;
        result[i][1]=y;
        for (int j=0; j<i; j++) {
            if((result[j][0] == x)&&(result[j][1] == y)){
                i--;
            }
        }
    }
}

//判断输入的坐标是否是地雷的坐标
int _contains_bomb(int _bomb[10][2], int x, int y){
    int res=0;
    for (int i=0; i<10; i++) {
        if ((_bomb[i][0] == x) && (_bomb[i][1] == y)) {
            res = 1;
        }
    }
    return res;
}

//判断玩家输入的坐标，处理后输出结果
int _process(int _bomb[10][2], int x, int y, char map[9][9]){
    int game_over = 0;
//case1: 输入的地址是地雷，游戏结束
    for (int i=0; i<10; i++) {
        if(_contains_bomb(_bomb,x,y)){
            map[x][y] = '*';
            game_over = 1;
            printf("你踩到雷了哈哈哈\nGAME OVER\n");
            break;
        }
    }
    
//case2: 输入的地址不是地雷，输出该点周围8个坐标中包含的地雷数量
    if(map[x][y] != '*'){
        //minor case1:中间的49个点，周围八个都可以输出
        if((x>=1 && x<=7) && (y>=1 && y<=7)){
            int count = 0;
            if(_contains_bomb(_bomb, x-1, y-1)) count++;
            if(_contains_bomb(_bomb, x-1, y)) count++;
            if(_contains_bomb(_bomb, x-1, y+1)) count++;
            if(_contains_bomb(_bomb, x, y-1)) count++;
            if(_contains_bomb(_bomb, x, y+1)) count++;
            if(_contains_bomb(_bomb, x+1, y-1)) count++;
            if(_contains_bomb(_bomb, x+1, y)) count++;
            if(_contains_bomb(_bomb, x+1, y+1)) count++;
            map[x][y] = (count+'0');
        }
        //minor case2:四个角的情况:
        if(x==0 && y==0){
            int count=0;
            if(_contains_bomb(_bomb, x, y+1)) count++;
            if(_contains_bomb(_bomb, x+1, y+1)) count++;
            if(_contains_bomb(_bomb, x+1, y)) count++;
            map[x][y] = (count + '0');
        }
        if (x==0 && y==8) {
            int count=0;
            if(_contains_bomb(_bomb, x, y-1)) count++;
            if(_contains_bomb(_bomb, x+1, y-1)) count++;
            if(_contains_bomb(_bomb, x+1, y)) count++;
            map[x][y] = (count + '0');
        }
        if (x==8 && y==0) {
            int count=0;
            if(_contains_bomb(_bomb, x-1, y)) count++;
            if(_contains_bomb(_bomb, x-1, y+1)) count++;
            if(_contains_bomb(_bomb, x, y+1)) count++;
            map[x][y] = (count + '0');
        }
        if (x==8 && y==8){
            int count=0;
            if(_contains_bomb(_bomb, x-1, y)) count++;
            if(_contains_bomb(_bomb, x-1, y-1)) count++;
            if(_contains_bomb(_bomb, x, y-1)) count++;
            map[x][y] = (count + '0');
        }
        //minor case3:四个边上除了顶点的各情况:
        //a:上边
        if (x==0 && (y>=1 && y<=7)) {
            int count=0;
            if(_contains_bomb(_bomb, x, y-1)) count++;
            if(_contains_bomb(_bomb, x, y+1)) count++;
            if(_contains_bomb(_bomb, x+1, y)) count++;
            if(_contains_bomb(_bomb, x+1, y-1)) count++;
            if(_contains_bomb(_bomb, x+1, y+1)) count++;
            map[x][y] = (count + '0');
        }
        //b:下边
        if (x==8 && (y>=1 && y<=7)) {
            int count=0;
            if(_contains_bomb(_bomb, x, y-1)) count++;
            if(_contains_bomb(_bomb, x, y+1)) count++;
            if(_contains_bomb(_bomb, x-1, y)) count++;
            if(_contains_bomb(_bomb, x-1, y-1)) count++;
            if(_contains_bomb(_bomb, x-1, y+1)) count++;
            map[x][y] = (count + '0');
        }
        //c:左边
        if (y==0 && (y>=1 && y<=7)) {
            int count=0;
            if(_contains_bomb(_bomb, x+1, y)) count++;
            if(_contains_bomb(_bomb, x-1, y)) count++;
            if(_contains_bomb(_bomb, x-1, y+1)) count++;
            if(_contains_bomb(_bomb, x, y+1)) count++;
            if(_contains_bomb(_bomb, x+1, y+1)) count++;
            map[x][y] = (count + '0');
        }
        //c:右边
        if (y==8 && (y>=1 && y<=7)) {
            int count=0;
            if(_contains_bomb(_bomb, x+1, y)) count++;
            if(_contains_bomb(_bomb, x-1, y)) count++;
            if(_contains_bomb(_bomb, x+1, y-1)) count++;
            if(_contains_bomb(_bomb, x, y-1)) count++;
            if(_contains_bomb(_bomb, x-1, y-1)) count++;
            map[x][y] = (count + '0');
        }
    }
    return game_over;
}


int main(int argc, const char * argv[]) {
//初始化地雷所在的位置数组，bombs数组存放地雷在的位置
    int bombs[10][2]={};
    initbombs(bombs);
//  输出所有地雷所在位置的注释
//    for (int i=0; i<10; i++) {
//        for (int j=0; j<2; j++) {
//            printf("%d",bombs[i][j]);
//            if(j==0) printf(",");
//            if(j == 1) printf("\n");
//        }
//    }
//  初始化第一次的图像
    char map[9][9];
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            map[i][j] = '#';
        }
    }
    
    printf("------------initialized----------\n");
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            printf("%3c",map[i][j]);
        }
        printf("\n");
    }

    int _try_times = 0;
    int _gameover = 0;
    
    while(_try_times < 20 && _gameover != 1){
        printf("\n请输入您想知道结果的坐标(以x行y列-x,y-的格式输入):");
        int x,y;
        scanf("%d,%d",&x,&y);
        x--;
        y--;
        
        _gameover = _process(bombs,x,y,map);
        
        //输出此次输入后得到的地雷图map
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                printf("%3c",map[i][j]);
            }
            printf("\n");
        }
        
        _try_times++;
    }
    
    if (_gameover == 0) {
        printf("congratulation! you SURVIVED!\n");
    }
    
    return 0;
}
