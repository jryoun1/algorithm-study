// 백준 1012 유기농배추
// cpp solved by bfs
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int _map[50][50];
int visited[50][50];
int T, ans;
int M, N, K;
stack < pair <int, int > > st;
void bfs(int b, int a){
    st.push({a,b});
    visited[b][a] = 1;
    while(!st.empty()){
        int x, y;
        x = st.top().first;
        y = st.top().second;
        st.pop();
        for (int i = 0; i < 4; i++){
            int nx, ny;
            nx = x + dx[i];
            ny = y + dy[i];

            if(0 <= nx && M > nx && 0 <= ny && N > ny && visited[ny][nx] == 0){
                if(_map[ny][nx] == _map[y][x]){
                    visited[ny][nx] = 1;
                    st.push({nx,ny});
                }
            }
        }
    }
}

int main(void){
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        ans = 0;
        scanf("%d %d %d", &M, &N, &K);
        memset(_map, 0, sizeof(_map));
        memset(visited, 0, sizeof(visited));
        for(int j = 0; j < K; j ++){
            int x, y;
            scanf("%d %d", &x, &y);
            _map[x][y] = 1;
        }

        for(int j = 0; j < M; j++){
            for(int k = 0; k < N; k++){
                if(_map[k][j] == 1 && visited[k][j] == 0){
                    ans ++;
                    bfs(k,j);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}