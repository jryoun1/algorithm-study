// 백준 2156 포도주 시식
// cpp solved by dp
#include<iostream>
#define max(a,b) {a > b ? a : b}
int main(void){
    int N, arr[10003], dp[10003]={0,};
    scanf("%d", &N);
    for(int i = 1; i < N+1;i++){
        scanf("%d",&arr[i]);
    }
    dp[1] = arr[1], dp[2] = arr[1] + arr[2];
    
    // there can be 3 cases
    // 1. if not drink N's wine => dp[n] = dp[n-1]
    // 2. if drink N's wine and it's first wine => dp[n] = dp[n-2] + arr[n]
    // 3. if drink N's wine and it's second wine => dp[n] = dp[n-3] + arr[n-1] + arr[n]
    // So find the max value from those three case and save dp[n]
    for(int i = 3; i < N + 3; i++){
        dp[i] = max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
        dp[i] = max(dp[i], dp[i-1]);
    }
    printf("%d",dp[N]);
    return 0;
}