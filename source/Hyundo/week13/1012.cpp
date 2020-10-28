#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 51

using namespace std;

int mem[MAX][MAX] = { 0, };
int T;
int M;
int N;
int K;

void DFS(int count, int x, int y) {
	mem[y][x] = 0;
	if (x < 0 || x >=M  || y < 0 || y >= N)
		return;
	if (mem[y - 1][x] == 1)
		DFS(count, x, y - 1);
	if (mem[y + 1][x] == 1)
		DFS(count, x, y + 1);
	if (mem[y][x - 1] == 1)
		DFS(count, x - 1, y);
	if (mem[y][x + 1] == 1)
		DFS(count, x + 1, y);

	//이부분에서 return을 제공하지 않아 오류 발생
	//-> return 추가 후 성공
	return;
}

int main()
{
	cin >> T;
	for (int A = 0; A < T; A++) {
		int count = 0;
		cin >> M;
		cin >> N;
		cin >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				mem[i][j] = 0;
			}
		}
		
		for (int i = 0; i < K; i++)
		{
			int a, b;
			cin >> a >> b;
			mem[b][a] = 1;
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (mem[i][j] != 0) {
					count++;
					DFS(count, j, i);
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}