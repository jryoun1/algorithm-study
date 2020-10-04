// 백준 2343 기타레슨
// cpp solved by binary search
#include<iostream>
#define MAX(a,b) {a > b ? a : b}

int main(void){
    int N, M;
    long long video[100001];
    // low => biggest element in video arr
    // high => sum of all elements in video arr
    long long low = -1, high = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%lld", &video[i]);
        low = MAX(low, video[i]);
        high += video[i];
    }

    while(low <= high){
        // mid is predict value 
        long long mid = (low + high) / 2;
        long long tempSum = 0, cnt = 0;
        for(int i = 0; i < N; i++){
            if(tempSum + video[i] > mid){
                tempSum = 0;
                cnt ++;
            }
            tempSum += video[i];
        }
        if(tempSum != 0) cnt++;
        if(cnt <= M){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    printf("%lld", low);
    return 0;
}