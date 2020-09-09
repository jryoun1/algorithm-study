// 백준 1520 내리막길 
// cpp solved by dfs + dp 

#include <iostream>
#include <string.h>
#define MAX 500
int N,M;
int map[MAX][MAX];
int dp[MAX][MAX];
int dx[] ={1,0,-1,0};
int dy[] ={0,1,0,-1};

int dfs(int x, int y){
    if(x == M-1 && y == N-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && nx <M && ny>=0 && ny<N){
            if(map[x][y] > map[nx][ny]){
                dp[x][y] += dfs(nx,ny);
            }
        }
    }
    return dp[x][y];
}

int main(void){
    scanf("%d %d",&M,&N);
    for(int i = 0; i < M; i++){
        for (int j = 0; j <N; j++){
            scanf("%d", &map[i][j]);
        }
    }
    for(int i = 0; i< M; i++)    
        memset(dp[i],-1,sizeof(int)*N);
    
    printf("%d" ,dfs(0,0));
    return 0;
}