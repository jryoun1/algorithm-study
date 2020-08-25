// 백준 1978 알파벳
// cpp solved by dfs 

#include <iostream>
#include <string>
#include <queue>
using namespace std;

char map[21][21];
int R, C, answer;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

// arr that checks visited or not and 
// 26 means 'A' to 'Z' 
bool visited[26]; 

void dfs(int x, int y, int cnt){
    answer = max(answer,cnt);

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < R && ny >= 0 && ny < C){
            // if nx, ny are in the boundary
            // ans if map[nx][ny] are not visited
            if(visited[map[nx][ny] - 'A'] == false){
                // change it to visited and 
                // reapeat dfs until they can't find any other way 
                // and if they can't find way, it will cancel the visited status
                // and came back to right before stage 
                // and look for another way (which is dfs)
                visited[map[nx][ny] - 'A'] = true;
                dfs(nx,ny,cnt + 1);
                visited[map[nx][ny] - 'A'] = false; 
            }
        }
    }
}

int main (void){
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++)
            cin >> map[i][j];
    }
    // first place 0,0 is always visited
    // so setting it as visited≈
    visited[map[0][0]-'A'] = true;
    dfs(0,0,1);
    //bfs(0,0);
    printf("%d\n", answer);
    return 0;
}



// struct maze {
//     int x;
//     int y;
//     string c;
// };

// void bfs(int x, int y){
//     queue<maze> q;
//     string str  = "";
//     str.push_back(map[x][y]);
//     q.push({x,y,str});
//     int answer = 1;
    
//     while(!q.empty()){
//         int x = q.front().x;
//         int y = q.front().y;
//         string ans = q.front().c;
//         q.pop();
//         for(int i = 0; i < 4; i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];

//             if( nx >= 0 && nx < R && ny >=0 && ny < C && ans.find(map[nx][ny]) == -1){
//                 q.push({nx,ny,ans + map[nx][ny]});
//                 cout<<ans+map[nx][ny]  <<endl;
//                 answer = max(answer,int(ans.length())+1);
//             }   
//         }
//     }
//     printf("%d\n", answer);
// }

