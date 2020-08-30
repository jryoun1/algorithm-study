#include<iostream>
#include<string>
#include<algorithm>
#include<random>
#define len 8

void insertionSort(int arr[], int first, int last, int gap){
    int index = first + gap;
    while(index <= last){
        int value = arr[index];
        int pos = index;
        while(pos>first && arr[pos-gap]>value){
            arr[pos] = arr[pos-gap];
            pos -= gap;
        }
        arr[pos] = value;
        index += gap;
    }
}

void shellSort(int arr[], int length){
    int gap = length/2;
    while(gap >0){
        for (int i = 0; i<length-1;i++){
            insertionSort(arr,i,length-1,gap);
        }
        gap /= 2;
    }
}

int main(void){
    int list[len] = {0,};
    printf("정렬 전 : ");
    for (int i = 0; i < len; i++){
        list[i] = rand()%101 + 1;
        printf("%d ", list[i]);
    }
    int length = sizeof(list)/sizeof(int);
    shellSort(list, length);
    printf("\n정렬 후 : ");
    for (int i = 0; i < len; i++){
        printf("%d ", list[i]);
    }
    return 0; 
}