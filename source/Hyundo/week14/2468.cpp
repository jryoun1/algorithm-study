#include<iostream>
#define MAX 1000

using namespace std;

int map[MAX][MAX];
int mem[MAX][MAX];
int N;

int a;

void DFS(int x, int y) {
	//방문한 곳을 0으로 초기화
	mem[y][x] = 0;
	//범위를 벗어난 경우 함수 종료
	if (x < 0 || x >= N || y < 0 || y >= N)
		return;
	//상하좌우 이동하며 DFS를 진행
	if (mem[y - 1][x] > a)
		DFS( x, y - 1);
	if (mem[y + 1][x] > a)
		DFS(x, y + 1);
	if (mem[y][x - 1] > a)
		DFS( x - 1, y);
	if (mem[y][x + 1] > a)
		DFS( x + 1, y);

	return;
}


int main()
{	
	int ans = 0;
	int max = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] > max)
				max = map[i][j];
		}
	}

	for (a = 1; a < max+1; a++) {

		int count = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				mem[i][j] = map[i][j];
		


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mem[i][j] > a) {
					count++;
					DFS(j, i);
				}
			}
		}

		

		if (count > ans)
			ans = count;
	}

	if (ans == 0)
		cout << 1;
	else
		cout << ans;
	
	return 0;
}