#include<iostream>
#include<queue>

#define endl "\n"
#define MAX 20
using namespace std;

int R, C, Answer;
char MAP[MAX][MAX];
bool Visit[26];

int dx[] = { 0, 0, 1, -1 }; // 하, 상
int dy[] = { 1, -1, 0, 0 }; // 우, 좌

int Bigger(int A, int B) { if (A > B) return A; return B; }


void DFS(int x, int y, int Cnt)
{
	Answer = Bigger(Answer, Cnt); //최대한 지나갈 수 있는 칸의 수를 결과에 저장

	for (int i = 0; i < 4; i++) //상하좌우로 이동하여 체크
	{ //우 {+0,+1} 좌 {+0,-1} 하 {+1,+0} 상 {-1,+0} 순으로 체크
		int nx = x + dx[i]; 
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < R && ny < C) //최대, 최소 범위를 벗어나지 않았을 때
		{
			if (Visit[MAP[nx][ny] - 'A'] == false) //해당 알파벳을 지난적 없는 경우
			{
				Visit[MAP[nx][ny] - 'A'] = true; //그곳으로 이동하고
				DFS(nx, ny, Cnt + 1); //count를 추가한 후에 해당 위치에서 다시 DFS를 진행하여 체크
				Visit[MAP[nx][ny] - 'A'] = false; //체크한 후에 또 다른 방향을 확인하기 위해 false 체크
			}
		}
	}
}

int main(void)
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> MAP[i][j];
		}
	}

	Visit[MAP[0][0] - 'A'] = true; //처음 시작하는 (0,0) 은 이미 지나친 것으로 체크
	DFS(0, 0, 1);  // x,y=(0,0) , count는 1부터 DFS 시작
	cout << Answer << endl;

	return 0;
}
