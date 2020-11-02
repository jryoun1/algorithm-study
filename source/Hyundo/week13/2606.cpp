#include<iostream>
#define MAX 101

using namespace std;

int N;
int M;
int map[MAX][MAX];
int mem[MAX];
int cnt = 0;


void DFS(int x)
{
	mem[x] = 1;

	for (int i = 1; i <= N; i++) {
		if (mem[i] == 0 && map[x][i] == 1) {
			cnt++;
			DFS(i);
		}
	}
}



int main()
{
	cin >> N;
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	DFS(1);
	cout << cnt;

	return 0;
}