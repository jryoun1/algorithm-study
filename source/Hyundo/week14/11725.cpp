#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001

int N;
vector<int> vertex[MAX];
int answer[MAX];
bool visited[MAX];


void DFS(int x) {
	//방문한 노드 true 로 변경
	visited[x] = true;
	//현재 방문한 노드의 연결점을 모두 반복문을 통해 탐색
	for (int i = 0; i < vertex[x].size(); i++) {
		int next = vertex[x][i];
		//방문한 적이 없는 node의 부모 노드를 현재 x로 설정하고
		//방문하기 위해 재귀 접근
		if (visited[next] == false) {
			answer[next] = x;
			DFS(next);
		}
	}
}

int main() {
	cin >> N;
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		vertex[a].push_back(b);
		vertex[b].push_back(a);
	}

	//루트(1) 부터 시작
	DFS(1);

	for (int i = 2; i <= N; i++)
		cout << answer[i] << '\n';

	return 0;
}