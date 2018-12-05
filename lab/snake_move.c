/*  snake_eat.c   */
/**/
/*  Based on file created by Maolin Pan on 12-12-6  */
/*  Created by Jialong Mi on 2018.12  */
/**/
/*  Copyright (c) 2012年 Sun Yat-sen University.  */
/*  All rights reserved   */
/**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SANKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

int GG=0;
char map[12][12]={
  {"***********"},
  {"*XXXXH    *"},
  {"*         *"},
  {"*         *"},
  {"*         *"},
  {"*         *"},
  {"*         *"},
  {"*         *"},
  {"*         *"},
  {"*         *"},
  {"*         *"},
  {"***********"}
};
int snakelen=5;
int snake_xy[SANKE_MAX_LENGTH][2];/*x是竖坐标，y是横坐标*/


void Output(void){/*输出*/
  int i;
  system("clear");/*清屏（Ubuntu版本命令），win版本未尝试*/
  for(i=0;i<12;i++){
      printf("%s\n",map[i]);
  }
}

void Gameover(void){/*游戏结束*/
  char map_GG[12][12]={
      "***********",
      "*         *",
      "*         *",
      "*         *",
      "* G a m e *",
      "*         *",
      "* O v e r *",
      "*         *",
      "*         *",
      "*         *",
      "*         *",
      "***********"
  };
  system("clear");
  int i;
  for(i=0;i<12;i++){
      printf("%s\n",map_GG[i]);
  }
}

/*x是竖，y是横*/
/*复制除了头之外的蛇的坐标*/
void MoveButHead(int snakelen){
  int i;
  map[snake_xy[snakelen-1][0]][snake_xy[snakelen-1][1]]=' ';/*将蛇尾消失*/
  for(i=snakelen-1;i>=1;i--){/*倒序赋值，避免逻辑错误*/
      snake_xy[i][0]=snake_xy[i-1][0];
      snake_xy[i][1]=snake_xy[i-1][1];
  }
}

void MoveHead(void){
  map[snake_xy[1][0]][snake_xy[1][1]]='X';/*原本的头变为身子*/
  map[snake_xy[0][0]][snake_xy[0][1]]='H';/*新的头出现*/
}

void Snake_Move(int snakelen){
  char direct=getchar();
  switch(direct){
      case 'a':
      case 'A':if(snake_xy[1][1]+1 != snake_xy[0][1]){/*判断条件：脖子不在头的要转向的方向*/
        MoveButHead(snakelen);
        snake_xy[0][1]--;/*头Y坐标-1*/
        MoveHead();
      }break;
      case 'w':
      case 'W':if(snake_xy[1][0]+1 != snake_xy[0][0]){
        MoveButHead(snakelen);
        snake_xy[0][0]-=1;/*头X坐标-1*/
        MoveHead();
      }break;
      case 's':
      case 'S':if((snake_xy[1][0]-1) != (snake_xy[0][0])){
        MoveButHead(snakelen);
        snake_xy[0][0]+=1;/*头X坐标+1*/
        MoveHead();
      }break;
      case 'd':
      case 'D':if(snake_xy[1][1]-1 != snake_xy[0][1]){
        MoveButHead(snakelen);
        snake_xy[0][1]++;/*头Y坐标+1*/
        MoveHead();
      }break;
      case 'q':GG=1;Gameover();break;
      default:break;
  }
}

int main(void){
  int i;
  for(i=0;i<snakelen;i++){/*初始化坐标数组*/
      snake_xy[i][0]=1;
      snake_xy[i][1]=snakelen-i;
  }
  while(GG != 1){
      Output();
      Snake_Move(snakelen);
  }
}