#include<stdio.h>
int distance[]={4,1,5,2};
int HowToMove(int lowest){
  int i,min,flag=0;
  for(i=0;i<4;i++){
    if(flag){
      if(distance[i]<distance[min] && distance[i]>=distance[lowest]){
        if(i != lowest){
          min=i;
        }
      }
    }
    else{
      if(distance[i]>=distance[lowest] && i != lowest){
        min=i;
        flag=1;
      }
    }
  }
  return min;
}

int main(){
  int min=1;
  for(int i=1;i<4;i++){
    min=HowToMove(min);
    printf("%d\t",distance[min]);
  }
  printf("\n");
}