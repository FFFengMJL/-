#include<stdio.h>

void Bubble_Sort(int arr[], int len){//自前往后比较
    for(int i=len-1; i >= 0; i--){//第一重循环
        for(int t=len-1; t >= len-i ; t--){//第二重循环，次数逐渐递减
            if(arr[t-1] > arr[t]){//交换条件
                int temp = arr[t-1];
                arr[t-1] = arr[t];
                arr[t] = temp;
            }
            for(int k=0;k<len;k++){
                printf("%d\t",arr[k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main(){
    int array[]={33, 56, 17, 8, 95, 22};
    Bubble_Sort(array,6);
    for(int i=0;i<6;i++){
        printf("%d\t",array[i]);
    }
}