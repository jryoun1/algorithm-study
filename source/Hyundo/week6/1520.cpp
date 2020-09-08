#include<iostream>
#include<cstring>

using namespace std;

int M, N;
int arr[500][500];
int visited[500][500];
int xi[4] = { 1,0,-1,0 }; //좌 , 우
int yi[4] = { 0, 1, 0, -1 }; // 하, 상 

int DFS(int m, int n) {

	if (m == M-1 && n == N-1) {
		return 1;
	}
	if (visited[m][n]!=-1) {
		return visited[m][n];
	}

	visited[m][n] = 0;
	for (int i = 0; i < 4; i++)
	{
		//범위를 벗어나지 않는 하에
		//이동전보다 작다면 DFS를 통해 이동가능
		//아닌 경우에는 그냥 return
		if (m + xi[i] >= 0 && m + xi[i] < M && n+ yi[i]>=0 && n + yi[i] < N)
		{
			if (arr[m][n] > arr[m + xi[i]][n + yi[i]]) {
				//cout << m + xi[i] << " " << n + yi[i] << endl;
				visited[m][n]+=DFS(m + xi[i], n + yi[i]);
			}
		}
	}
	return visited[m][n];

}


int main()
{
	cin >> M >> N;
	int tmp=0;
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	memset(visited, -1, sizeof(visited));

	
	cout << DFS(0, 0) << endl;

	return 0;
}