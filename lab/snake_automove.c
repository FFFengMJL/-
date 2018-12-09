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
//#include <sys/types.h>
//#include <sys/wait.h>
#include "./kbhit.c"/*直接加载tty*/

#define SANKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

int GG=0;
int snakelen=5;
int snake_xy[SANKE_MAX_LENGTH][2];/*x是竖，y是横*/
int Money=1,Money_x=0,Money_y=0;/*游戏区域是否有钱，默认没钱*/
int eat=0;/*表示刚刚是否吃屎*/
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

void Gameover(int a){/*将GG修改集成于此，添加了胜利的结算画面*/
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
  char map_WIN[12][12]={
      "***********",
      "*         *",
      "*         *",
      "*         *",
      "*  Y O U  *",
      "*         *",
      "*  W I N  *",
      "*         *",
      "*         *",
      "*         *",
      "*         *",
      "***********"
  };
  system("clear");
  GG=1;
  int i;
  if(a == 1){
      for(i=0;i<12;i++){
        printf("\033[30;47m%s\033[0m\n",map_WIN[i]);
      }
  }
  else if(a == 0){
      for(i=0;i<12;i++){
        printf("\033[30;47m%s\033[0m\n",map_GG[i]);
      }
  }
}

void Put_Money(void){/**/
  while(Money){/*区域里面没钱*/
    srand((unsigned) time(0));
    Money_x=rand()%10+1;
    Money_y=rand()%10+1;
    if(map[Money_x][Money_y] == ' '){
      map[Money_x][Money_y]='$';
      Money--;/*证明已经产生了钱*/
    }
  }
}

void Output(int GG){/*no problem*/
  if(GG == 1){}
  else{
    int i;
    Put_Money();
    system("clear");/*清屏*/
    for(i=0;i<12;i++){
        printf("\033[30;47m%s\033[0m\n",map[i]);
    }
  }
}

void Crush_Foresee(int x_fore,int y_fore){/*康康下一步会不会翻车*/
  if(map[x_fore][y_fore] == '*' || map[x_fore][y_fore] == 'X'){
      Gameover(0);/*撞墙/我 吃 我 自 己的话就GG啦*/
  }
  else if(map[x_fore][y_fore] == '$'){/*判断会吃屎*/
      snakelen++;
      if(snakelen>20){
        Gameover(1);
      }
      eat=1;/*表示即将吃屎*/
      Money=1;/*表示区域即将没钱*/
  }
}

/*x是竖，y是横*/
/*复制除了头之外的蛇的坐标*/
void MoveButHead(void){
  int i;
  if(eat){/*新加的尾巴坐标是（0,0)*/
      eat=0;
  }
  else{
      map[snake_xy[snakelen-1][0]][snake_xy[snakelen-1][1]]=' ';/*将蛇尾消失*/
  }
  for(i=snakelen-1;i>=1;i--){/*倒序赋值，避免逻辑错误*/
      snake_xy[i][0]=snake_xy[i-1][0];
      snake_xy[i][1]=snake_xy[i-1][1];
  }
}

void MoveHead(void){
  map[snake_xy[1][0]][snake_xy[1][1]]='X';/*原本的头变为身子*/
  map[snake_xy[0][0]][snake_xy[0][1]]='H';/*头出现*/
}

void Snake_Move(int snakelen,char direct){
//  char direct=getchar();
  switch(direct){
      case 'a':
      case 'A':if(snake_xy[1][1]+1 != snake_xy[0][1]){/*判断条件：脖子不在头的要转向的方向*/
        Crush_Foresee(snake_xy[0][0],snake_xy[0][1]-1);
        MoveButHead();
        snake_xy[0][1]--;/*头纵坐标-1*/
        MoveHead();
      }break;
      case 'w':
      case 'W':if(snake_xy[1][0]+1 != snake_xy[0][0]){
        Crush_Foresee(snake_xy[0][0]-1,snake_xy[0][1]);
        MoveButHead();
        snake_xy[0][0]-=1;/*头横坐标-1*/
        MoveHead();
      }break;
      case 's':
      case 'S':if((snake_xy[1][0]-1) != (snake_xy[0][0])){
        Crush_Foresee(snake_xy[0][0]+1,snake_xy[0][1]);
        MoveButHead();
        snake_xy[0][0]+=1;/*头横坐标+1*/
        MoveHead();
      }break;
      case 'd':
      case 'D':if(snake_xy[1][1]-1 != snake_xy[0][1]){
        Crush_Foresee(snake_xy[0][0],snake_xy[0][1]+1);
        MoveButHead();
        snake_xy[0][1]++;/*头纵坐标+1*/
        MoveHead();
      }break;
      case 'q':case 'Q':Gameover(0);break;
      default:break;
  }
}

char movable[]={'w','a','s','d'};/*走的方式，与最小值的位置对应*/
int distance[4]={0};
char Auto_Move(int Money_x,int Money_y){
  int former_x=snake_xy[0][0];
  int former_y=snake_xy[0][1];
  distance[0]=abs(snake_xy[0][0]-1-Money_x)+abs(snake_xy[0][1]-Money_y);/**/
  distance[1]=abs(snake_xy[0][0]-Money_x)+abs(snake_xy[0][1]-1-Money_y);
  distance[2]=abs(snake_xy[0][0]+1-Money_x)+abs(snake_xy[0][1]-Money_y);
  distance[3]=abs(snake_xy[0][0]-Money_x)+abs(snake_xy[0][1]+1-Money_y);
  int i,t,min=0;
  for(i=0;i<4;i++){
    min=(distance[i]<distance[min]?i:min);
  }
  Snake_Move(snakelen,movable[min]);
  if(snake_xy[0][0] == former_x && snake_xy[0][1] == former_y){
    for(i=0,t=min,min=0;i<4;i++){
      if(i!=t){
        min=(distance[i]<distance[min]?i:min);
      }
    }
    Snake_Move(snakelen,movable[min]);
  }
//  return movable[min];
}

/*put a food randomized on a blank cell*/




int main(void){
  int tty_set_flag;
  tty_set_flag = tty_set();
  int i;
  int key;
  for(i=0;i<snakelen;i++){/*初始化坐标数组*/
      snake_xy[i][0]=1;
      snake_xy[i][1]=snakelen-i;
  }
  Output(GG);
  while(GG != 1){
    Auto_Move(Money_x,Money_y);
    Output(GG);
    usleep(450000);
  }
  tty_reset();
}