#include<iostream>
#include<string>
int cnt =0;

void merge(int arr[], int left, int mid, int right){
    int i = left, j = mid + 1, k = left ;
    int sorted_arr[1000];
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            sorted_arr[k++] = arr[i++];
        }else{
            sorted_arr[k++] = arr[j++];
        }
    }
    if(i>mid){
        for(int m = j; m <= right; m++){
            sorted_arr[k++] = arr[m];
        }
    }else{
         for(int m = i; m<= mid; m++){
            sorted_arr[k++] = arr[m];
        }
    }
      for (int m = left; m <= right; m++) {
        arr[m] = sorted_arr[m];
    }
}
void mergeSort(int arr[], int left, int right){
    int mid =0;
    
    if(left < right){
        cnt++;
        mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid +1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int len = 0;
    std::cin >> len;
    int *arr = new int[len];
    for(int i = 0; i< len ; i++){
        std::cin >> arr[i];
    }
    mergeSort(arr, 0, len - 1);
    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}