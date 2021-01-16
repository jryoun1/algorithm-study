#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define MAX 300001

using namespace std;

vector<vector<int>>map(MAX);
bool visit[MAX];

int n, m, k, x;


void bfs(int start) {
	int dist = 0;
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int q_size = q.size();

		//현재 도시로부터 연결된 모든 도시에 대하여 visit 표시 (1번 이동)
		//현재 q에 담겨 있는 도시 : dist만큼 이동했을 때 도달한 도시
		for (int i = 0; i < q_size; i++) {
			int cur = q.front();
			q.pop();
			//현재 도시에 연결된 모든 도시만큼 반복
			for (int j = 0; j < map[cur].size(); j++)
			{	
				int next = map[cur][j];
				//이미 방문한 도시면 pass
				if (visit[next])continue;
				visit[next] = true;
				q.push(next);
			}
		}
		//현재 도시로부터 연결된 도시에 대하여 1번 이동이 끝났음으로 이동거리 추가
		dist++;
		//만약 현재 이동횟수가 주어진 거리정보 k와 같고 q가 비지 않았다면
		if (dist == k && !q.empty()) {
			priority_queue<int, vector<int>, greater<int>>pq;
			while (!q.empty()) {
				pq.push(q.front());
				q.pop();
			}
			while (!pq.empty()) {
				cout << pq.top() << endl;
				pq.pop();
			}
			return;
		}
	}
	cout << -1;
	return;
}


int main()
{
	cin >> n >> m >> k >> x;
	int c1;
	int c2;
	for (int i = 0; i < m; i++) {
		cin >> c1 >> c2;
		map[c1].push_back(c2);
	}
	bfs(x);

	return 0;
}