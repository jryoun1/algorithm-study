#include<iostream>
#include<string>
#define SWAP(a,b) { int temp = a; a =b; b =temp;}
#define LEN 8
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[(low+high)/2];
    while(low <= high){
        while(arr[low] < pivot){
            low++;
        }
        while(arr[high] > pivot){
            high--;
        }
        if(low <= high){
            SWAP(arr[low],arr[high]);
            low++;
            high--;
        }
    }
    return low;
}
void quickSort(int arr[], int low, int high){
    if (high<=low){
        return ;
    }
    int mid = partition(arr,low,high);
    quickSort(arr,low,mid-1);
    quickSort(arr,mid,high);
}
int main (void){
    int arr[LEN]={};
    srand((unsigned)time(NULL));
    printf("정렬 전: ");
    for (int i = 0;i < LEN; i++){
        arr[i]= (std::rand() % 101) + 1;
        printf("%d ", arr[i]);
    }
    quickSort(arr, 0, LEN-1);
    printf("-> 정렬 후: ");
    
    for(int i = 0; i < LEN; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}