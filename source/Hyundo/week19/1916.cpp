#include <cstdio>
#include <vector>
#include <queue>

#define PAIR pair<int, int>

using namespace std;

vector<pair<int, int>> a[1001];
int d[1001];
bool chk[1001];

int main() {
	int n, m;

	//input
	scanf("%d %d", &n, &m); //도시개수 , 버스 개수
	for (int i = 0; i < m; i++) {
		int x, y, z;		// x : 출발 도시 번호 y : 도착 도시 번호 z : 버스 비용
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
	}
	int start, end; //출발점 도시번호 , 도착점 도시번호
	scanf("%d %d", &start, &end);


	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	d[start] = 0;
	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> q;

	q.push(make_pair(0, start));
	while (!q.empty()) {
		int node = q.top().second;
		q.pop();
		if (!chk[node]) {
			chk[node] = true;
			//현재 지점으로부터 연결된 도시 체크
			for (int k = 0; k < a[node].size(); k++) {
				int next = a[node][k].first;
				if (d[next] > d[node] + a[node][k].second) {
					//비용과 비교하여 최소비용으로 초기화
					d[next] = d[node] + a[node][k].second;
					q.push(make_pair(d[next], next));
				}
			}
		}
	}
	printf("%d\n", d[end]);
}
