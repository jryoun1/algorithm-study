#include<iostream>
#define MAX 101

using namespace std;

bool map[MAX][MAX];

int main() {

	//input
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			cin >> map[i][j];
	

	//Floyd-Warshall
	for (int i = 0; i < N; i++) {  //i 번째 정점을 경유할 때
		for (int j = 0; j < N; j++) {   //j 정점으로 부터
			for (int k = 0; k < N; k++) {    // k 정점으로 이동
				if (map[j][i] != 0 && map[i][k] != 0)//j->i 연결 여부 확인 && i->k 연결 여부 확인
				{
					map[j][k] = 1;
					//j->i->k 
					//i 정점을 경유하여 j 정점으로부터 k정점으로 경로가 있음
				}
			}
		}
	}

	//output
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << map[i][j]<<" ";
		cout << endl;
	}

}