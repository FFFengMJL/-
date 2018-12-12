#include<stdio.h>
int distance[]={1,2,3,4};
int HowToMove(int lowest){
  int i,min=lowest,flag=0;
  for(i=0;i<4;i++){
    if(distance[i]>=distance[min] && min != i && flag ==0){
      min=i;
      flag=1;
    }
    else if(flag){
      min=(distance[min]>distance[i] && distance[i]>distance[lowest])?i:min;
    }
  }
  return min;
}
int main(){
    int min=0;
    for(int i=0;i<4;i++){
        printf("%d\t",distance[i]);
    }
    printf("\n");
    for(int i=1;i<4;i++){
        min=HowToMove(min);
        printf("%d\t",min);
    }
}