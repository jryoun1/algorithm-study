#include<iostream>

#define MAX 29
using namespace std;

int N;
double percentage[4];
bool visited[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


double DFS(int x, int y, int Cnt)
{
	//최대 이동횟수 도달시 1 return;
	if (Cnt == N) return 1.0;

	//방문한 위치 초기화
	visited[x][y] = true;

	double Result = 0.0;

	//상화좌우 이동
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		//이동 위치가 이미 방문 한 적이 있을 경우 skip (이동 경로가 단순하지 않음)
		if (visited[nx][ny] == true) continue;
		//처음 방문하는 위치인 경우
		//이동한 위치에서 DFS 진행
		//현재 이동방향으로 이동할 확률 * 다음 위치에서의 이동 확률
		Result = Result + percentage[i] * DFS(nx, ny, Cnt + 1);
	}

	visited[x][y] = false;
	return Result;
}


int main(void)
{
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		int a; 
		cin >> a;
		percentage[i] = a / 100.0;
	}
	double Answer = DFS(14, 14, 0);
	cout.precision(10);    // 소수점 아래 10자리 까지 설정
	cout << fixed << Answer <<endl; // 소수점 아래 고정 10자리 까지 출력

	return 0;
}