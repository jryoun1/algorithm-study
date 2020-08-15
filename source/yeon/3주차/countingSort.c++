#include<iostream>
#include<string>
#include<random>
#include<time.h>
#define MAX_NUM 100

void countingSort(int arr[], int len){
    int count_arr[MAX_NUM + 1] = {0,};
    int count_sum[MAX_NUM + 1] = {0,};
    int * sorted_arr = new int [len+1];
    
    for(int i = 0; i < len; i++){
        count_arr[arr[i]] += 1;
    }
    count_sum[0]=count_arr[0];
    for (int i = 1; i < MAX_NUM ; i++){
        count_sum[i] = count_sum[i-1] + count_arr[i];
    }
    
    for(int i = len - 1; i >= 0; i--){
        sorted_arr[count_sum[arr[i]]] = arr[i];
        count_sum[arr[i]] -= 1;
    }

    for(int i = 1; i <= len; i++){
        printf("%d ", sorted_arr[i]);
    }
}

int main(void){
    int arr[8];
    srand(time(NULL));
    printf("정렬 전 -> : ");
    for (int i = 0; i < 8; i++){
        arr[i] = rand()%100+1;
        printf("%d ", arr[i]);
    }
    printf("\n정렬 후 -> : ");
    countingSort(arr, 8);
    
    return 0;
}