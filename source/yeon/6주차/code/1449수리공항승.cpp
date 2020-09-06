// 백준 1449 수리공 항승
// cpp solved by Greedy algorithm
#include <iostream>
#include <algorithm>
#define MAX 1000

int main(void){
    int N, L, ans = 0;
    int arr[MAX];
    scanf("%d %d",&N,&L);
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    std::sort(arr, arr+N);
    float tape_range = 0;
    for(int i = 0; i < N; i++){
        if(arr[i] + 0.5 > tape_range){
            ans ++;
            tape_range = arr[i] - 0.5 + L;
        }
    }
    printf("%d",ans);
    return 0;
}