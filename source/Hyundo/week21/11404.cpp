#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAX 101

using namespace std;

int n, m;
int arr[MAX][MAX];


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {        // vectex table 초기화
		for (int j = 0; j < n; j++) {
			arr[i][j] = INF;
		}
	}

	int from, to, weight;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> weight;
		//시작 도시와 도착 도시를 연결하는 노선 중 가중치가 최소값인 것을 저장
		arr[from-1][to-1] = min(arr[from-1][to-1], weight);
	}

	for (int i = 0; i < n; i++) {  //i 번째 정점을 경유할 때
		for (int j = 0; j < n; j++) {   //j 정점으로 부터
			for (int k = 0; k < n; k++) {    // k 정점으로 이동
				if (j != k && arr[j][i] != INF && arr[i][k] != INF) {
					//최소비용으로 갱신
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
				}
			}
		}
	}

	//각각의 비용을 모두 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]== INF)
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}