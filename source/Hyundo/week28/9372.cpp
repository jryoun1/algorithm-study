#include<iostream>
#include<vector>

using namespace std;

vector<int> plane[10001];
int visited[1001] = { 0 };

int T, N, M;

int num = 0;

void DFS(int p) {

	num++;

	visited[p] = 1;

	for (int i = 0; i < plane[p].size(); i++){
		if(visited[plane[p].at(i)] != 1)
			DFS(plane[p].at(i));
	}

	return;
}


int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			plane[a].push_back(b);
			plane[b].push_back(a);
		}

		DFS(1);
		cout << num-1 <<endl;

		for (int i = 0; i <= N; i++) {
			visited[i] = 0;
			plane[i].clear();
		}

		num = 0;
	}
}