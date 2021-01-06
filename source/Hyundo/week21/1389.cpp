//케빈 베이컨의 6단계 법칙
//
#include<iostream>
#include<algorithm>

#define MAX 101

using namespace std;

int map[MAX][MAX];

int main() {

	//input
	int N,M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {  
		for (int j = 0; j < N; j++) {
			map[i][j] = N+1;
		}
	}

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		//친구 관계이므로 양방향으로 표시
		map[from-1][to-1] = 1;
		map[to-1][from-1] = 1;
	}

	//Floyd-Warshall
	for (int i = 0; i < N; i++) {  //i 번째 정점을 경유할 때
		for (int j = 0; j < N; j++) {   //j 정점으로 부터
			for (int k = 0; k < N; k++) {    // k 정점으로 이동
				if (j != k && map[j][i] != 0 && map[i][k] != 0)
				{
					//최소 케빈 베이컨의 수를 표 내에서 갱신
					map[j][k] = min(map[j][k],map[j][i] + map[i][k]);
				}
			}
		}
	}

	int max = N*N;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++)
			if (i != j)
				sum += map[i][j];
		//유저 중 케빈 베이컨 수의 합이 가장 적은 번호를 answer에 저장
		if (sum < max) {
			max = sum;
			answer = i+1;
		}
	}

	cout << answer<<endl;
}