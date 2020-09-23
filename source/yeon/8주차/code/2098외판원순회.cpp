// 백준 2098 외판원 순회
// cpp solved by dp & bitmask & dfs
#include<iostream>
#include<algorithm>
#define MAX 987654321
#define MIN(a,b) {a < b ? a : b}

int N, arr[20][20];
int dp[20][1<<17];

int dfs(int cur, int visit){
    if(visit == (1<<N) - 1){
        if(arr[cur][0] == 0)
            return MAX;
        else  return arr[cur][0];
    }
    
    if(dp[cur][visit] != MAX)
        return dp[cur][visit];
    
    for(int i = 1; i < N; i++){
        if((visit&(1<<i)) == 0 && arr[cur][i] != 0){
            dp[cur][visit] = MIN(dp[cur][visit], dfs(i,(visit|(1<<i))) + arr[cur][i]);
        }
    }
    return dp[cur][visit];
}

int main(void){
    scanf("%d", &N);
    std::fill(&dp[0][0], &dp[N][1<<N], MAX);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d", dfs(0,1));
    return 0;
}