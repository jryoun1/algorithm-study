#include<iostream>
#include<algorithm>

#define MAX 501

using namespace std;

int map[MAX][MAX];

int main() {

	//input
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = N+1;
	

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		map[from - 1][to - 1] = 1;
	}

	//Floyd-Warshall
	for (int i = 0; i < N; i++) {  //i 번째 정점을 경유할 때
		for (int j = 0; j < N; j++) {   //j 정점으로 부터
			for (int k = 0; k < N; k++) {    // k 정점으로 이동
				if (j != k && map[j][i] != 0 && map[i][k] != 0)
				{
					map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
				map[j][i] = map[i][j];


	int answer = 0;
	
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if(map[i][j]!=N+1)
			sum += 1;
		}
		if (sum == N - 1)
			answer++;
	}

	cout << answer;
}