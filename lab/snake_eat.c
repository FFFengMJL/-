#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SANKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'
/*put a food randomized on a blank cell*/
/*void Put_Money(void)*/
/*out cells of the gird*/
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
int snake_xy[SANKE_MAX_LENGTH][2];/*x是竖，y是横*/
int Money=1;/*游戏区域是否有钱，默认没钱*/
int eat=0;/*表示刚刚是否吃屎*/
void Put_Money(void){/**/
  while(Money){/*区域里面没钱*/
  int x=rand()%10+1;
  int y=rand()%10+1;
  if(map[x][y] == ' '){
    map[x][y]='$';
    Money--;
  }
  }
}

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
        printf("%s\n",map_WIN[i]);
      }
  }
  else if(a == 0){
      for(i=0;i<12;i++){
        printf("%s\n",map_GG[i]);
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

void Output(void){/*no problem*/
  int i;
  Put_Money();
  system("clear");/*清屏*/
  for(i=0;i<12;i++){
      printf("%s\n",map[i]);
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

void Snake_Move(int snakelen){
  char direct=getchar();
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