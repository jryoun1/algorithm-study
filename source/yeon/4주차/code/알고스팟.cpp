// 백준 1261 알고스팟
// cpp solved by bfs using deque
#include <iostream>
#include <deque>
using namespace std;
int map[101][101];
int dist[101][101];
int M,N;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct maze{
    int x, y;
};

void bfs(int x, int y){
    dist[0][0] = 0;
    deque<maze> dq;
    dq.push_back({x,y});
    
    while(!dq.empty()){
        int x = dq.front().x;
        int y = dq.front().y;
        dq.pop_front();

        for (int i = 0; i < 4; i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M){
                if (dist[nx][ny] == -1){
                    if(map[nx][ny] == 0){
                        dq.push_front({nx,ny});
                        dist[nx][ny] = dist[x][y];
                    }
                    else if(map[nx][ny] == 1){
                        dq.push_back({nx,ny});
                        dist[nx][ny] = dist[x][y] + 1;
                    }
                }
            }
        }
    }
    printf("%d\n", dist[N-1][M-1]);
}


int main (void){

    scanf("%d %d",&M, &N);
    for(int i = 0; i< N; i++){
        for (int j = 0; j < M; j++){
            //정수 하나씩 받는거는 %1d
            scanf("%1d",&map[i][j]); 
            dist[i][j] = -1;
        }
    }
    bfs(0,0);
    return 0;
}