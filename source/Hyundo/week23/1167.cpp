#include<iostream>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

int V;
int answer=0;
int maxNode;

vector<vector<pair<int,int>>> arr(100001);
bool visited[100001] = { 0, };//if( visited[i] = 1)  ->  arleady visited


void DFS(int ver, int dis) {

	//최대 거리 측정 + 가장 먼 leaf node찾기
	if (dis > answer) {
		answer = dis;
		maxNode = ver;
	}

	visited[ver] = 1;

	for (int i = 0; i < arr[ver].size(); i++) {
		//이전에 방문한 적이 있는 노드에서는 더이상진행하지 않음
		if (visited[arr[ver][i].first] != 1)
			DFS(arr[ver][i].first, dis + arr[ver][i].second);
	}
}


int main()
{
	cin >> V;
	int from;
	for (int i = 0; i < V; i++)
	{
		cin >> from;
		int to, dis;
		while (1) {
			cin >> to;
			if (to == -1)
				break;
			else {
				cin >> dis;
				arr[from].push_back({ to,dis });
			}
		}
	}
	//첫번째 DFS .가장 바깥에 있는 정점을 찾는다.
	DFS(1, 0);
	memset(visited, 0, sizeof(visited));
	answer = 0;
	//두번째 DFS . 가장 바깥에 있는 정점으로부터 거리가 가장 먼 정점을 찾는다.
	DFS(maxNode, 0);
	cout << answer;

	return 0;
}