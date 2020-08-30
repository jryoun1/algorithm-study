#include<iostream>
#include<string>
#define swap(a,b) {int t = a; a = b; b = t;}

void heapify (int arr[], int index, int size){
    int largest = index;
    int left_index = 2 * index + 1;
    int right_index = 2* index + 2;

    if (left_index < size && arr[left_index]> arr[largest])
        largest = left_index;
    if (right_index < size && arr[right_index] > arr[largest])
        largest = right_index;

    if (largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr, largest, size);
    }
}

void heapSort(int arr[], int size){
    //build max heap by making time complexity O(n)
    for(int i = size /2 ; i >= 0 ; i--){
        heapify(arr, i, size);
    }

    //extract the biggest element from max heap and heapify recursively
    for(int i = size -1; i > 0 ; i--){
        swap(arr[i],arr[0]);
        heapify(arr, 0, i);
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
    heapSort(arr, 8);
    printf("\n정렬 후 -> : ");
    for (int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}