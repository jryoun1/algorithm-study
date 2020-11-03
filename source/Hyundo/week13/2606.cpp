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
	//방문한 노드 1로 초기화
	mem[x] = 1;
	//현재 index x의 node와 다른 노드 와의 연결여부 확인
	//cnt 가 다시 한번 더해지지 않도록 방문한 적이 없는 위치로만 이동
	for (int i = 1; i <= N; i++) {
		if (mem[i] == 0 && map[x][i] == 1) {
			cnt++;
			//바이러스가 걸린 i 컴퓨터에서 다시 진행
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