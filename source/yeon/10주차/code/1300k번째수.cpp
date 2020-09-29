// 백준 1300 k 번째수
// cpp solved by binary search

#include<iostream>
#include<algorithm>
int N, k;

int main(void){
    scanf("%d\n%d", &N,&k);
    int left = 1, right = k, ans = 0;
    while(left <= right){
        int mid = (left + right)/2;

        int cnt = 0;
        for(int i = 1; i < N + 1; i++){
            cnt += std::min(mid/i, N);
        }

        if (cnt >= k){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    
    printf("%d", ans);
    return 0;
}