// 벡즌 3085 사탕게임
// cpp solved by brute-force
#include <iostream>
#include <algorithm>
using namespace std;
const int dx[] = { 0,1 };
const int dy[] = { 1,0 };
int N, ans;
char board[50][50];

int check() {
	// answer is act like global variable 
	// it save the final max value from this check function
	// cnt is value that count each case 
	int answer = 1, cnt = 1;
	for (int i = 0; i < N; i++) {
		// check every col in board
		for (int j = 0; j < N ; j++) {
			if (board[i][j] == board[i][j + 1]) cnt++;
			else answer = max(answer, cnt), cnt = 1;
		}
		answer = max(answer, cnt), cnt = 1;
		// check every row in board
		for (int j = 0; j < N ; j++) {
			if (board[j][i] == board[j + 1][i]) cnt++;
			else answer = max(answer, cnt), cnt = 1;
		}
		answer = max(answer, cnt), cnt = 1;
	}
	return answer;
}

int main() {
	scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			for (int i = 0; i < 2; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if(nx >= 0 && nx < N && ny >= 0 && ny < N){
				swap(board[x][y], board[nx][ny]);
				ans = max(ans, check());
				swap(board[x][y], board[nx][ny]);
                }
			}
		}
	}
	printf("%d", ans);
	return 0;
}


// // 벡즌 3085 사탕게임
// // cpp solved by bfs
// #include <iostream>
// #include <deque>
// #include <set>
// #include <utility>
// #define swap(a,b){char temp = a; a = b; b = temp;}
// using namespace std;
// int dx[2] = {1,0};
// int dy[2] = {0,1};
// char board[50][50];
// int N =0, answer = 0;
// deque< set < pair<int, int> > > q; 

// void bfs(int x, int y){
//     q.push_front({ make_pair(x,y) });
//     set < pair < int, int>>::iterator it = q.front().begin();
//     while(!q.empty()){
//         pair<int,int> a = *it;
//         int x = a.first;
//         int y = a.second;
//         q.pop_front();
//         for (int i = 0; i < 2; i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if(nx >= 0 && nx < N && ny >= 0 && ny < N){
//                 q.push_front({ make_pair(nx,ny) });
//                 swap(board[nx][ny], board[x][y]);
//                 int col_cnt=1, row_cnt=1, col_cnt1=1, row_cnt1=1;
//                 for(int j=0 ; j<N-1;j++){
//                     if(board[nx][j] == board[nx][j+1]) col_cnt ++;
//                     else col_cnt = 1;
//                     if(board[j][ny] == board[j+1][ny]) row_cnt ++;
//                     else row_cnt = 1;
//                     if(board[x][j] == board[x][j+1]) col_cnt1 ++;
//                     else col_cnt1 = 1;
//                     if(board[j][y] == board[j+1][y]) row_cnt1 ++;
//                     else row_cnt1 = 1;
//                     answer = max(answer,max(max(col_cnt,row_cnt),max(col_cnt1,row_cnt1)));
//                 }
//                 swap(board[nx][ny], board[x][y]);
//             }
//         }
//     }    
//     printf("%d", answer);
// }

// int main(void){
//     scanf("%d", &N);
//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < N; j++){
//             cin >> board[i][j];
//         }
//     }
//     bfs(0,0);
//     return 0;
// }
