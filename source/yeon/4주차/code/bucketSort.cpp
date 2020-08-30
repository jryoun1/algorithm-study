#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#define LEN 8

using namespace std;

void bucketSort(float arr[], int len){
    vector<float> bucket[8];

    for(int i = 0; i < len; i++){
        int index = len * arr[i];
        bucket[index].push_back(arr[i]);
    }

    for (int i = 0; i < len; i++){
        sort(bucket[i].begin(), bucket[i].end());
    }
    
    int index = 0;
    for (int i = 0; i < len; i++){
        for (int j = 0; j < bucket[i].size(); j++){
            arr[index++] = bucket[i][j];
        }
    }
}

int main(void){
    srand(time(NULL));
    float arr[LEN] = {0.0,};
    for (int i = 0; i < LEN; i++){
        arr[i] = rand() / (float)RAND_MAX * 1.0f ;
    }
    bucketSort(arr, LEN);
    for(int i = 0; i < LEN; i++){
        printf("%f ", arr[i]);
    }
    return 0;
}