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
	//방문한 곳을 0으로 초기화
	mem[y][x] = 0;
	//범위를 벗어난 경우 함수 종료
	if (x < 0 || x >=M  || y < 0 || y >= N)
		return;
	//상하좌우 이동하며 DFS를 진행
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
	//test case 갯수에 따른 반복
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
		//입력받은 배추 위치 부분을 1로 초기화
		for (int i = 0; i < K; i++)
		{
			int a, b;
			cin >> a >> b;
			mem[b][a] = 1;
		}

		//반복문이 진행되면서 이전에 재귀적으로 진행되었던 DFS에서 방문하지 않은 새로운 위치 발견시
		//새롭게 DFS를 시작하면서 count를 더해주어 지렁이 필요 개수 체크
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (mem[i][j] != 0) {
					count++;
					DFS(count, j, i);
				}
			}
		}
		//지렁이 개수 출력
		cout << count << endl;
	}

	return 0;
}