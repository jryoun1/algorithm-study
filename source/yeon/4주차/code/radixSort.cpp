#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#define LEN 8 
using namespace std;

void countingSort(int arr[], int digit){
    int sorted[LEN];
    int count[10] = {0,};

    for(int i = 0; i < LEN; i++){
        int index = arr[i]/digit;
        count[index%10] += 1;
    }

    for(int i = 1; i < 10 ; i ++){
        count[i] += count[i-1];
    }
    
    int a = LEN -1;
    while(a >= 0){
        int index = arr[a] / digit;
        sorted[count[index % 10] - 1] = arr[a];
        count[index % 10] -= 1;
        a--;
    }
    for(int i = 0; i < LEN ; i++){
        arr[i] = sorted[i];
    }
}

void radixSort(int arr[], int len){
    int digit = 1;
    int max_value = *max_element(arr,arr+len);

    while(max_value/digit > 0){
        countingSort(arr,digit);
        digit *= 10;
    }
}

int main(void){
    srand(time(NULL));
    int arr[LEN];
    printf("정렬 전 : ");
    for(int i = 0 ; i < LEN; i++){
        arr[i] = rand()%100+1;
        printf("%d ", arr[i]);
    }
    printf("-> 정렬 후 : ");
    radixSort(arr, LEN);
    for(int i = 0; i< LEN; i++)
        printf("%d ", arr[i]);

    return 0;
}