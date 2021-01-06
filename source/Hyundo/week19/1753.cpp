#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

vector<pair<int, int>> graph[20001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, start;
	cin >> v >> e >> start;
	//정점의 개수, 간선의 개수, 시작 정점의 번호

	int fr, to, w;
	for (int i = 0; i < e; i++)
	{
		cin >> fr >> to >> w;
		//fr : 출발 정점 to : 도착 정점 w : 가중치
		graph[fr].push_back(make_pair(w, to));
	}

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	vector<int> d(v + 1, INF);
	d[start] = 0;

	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		int cur_dist = -cur.first;
		int cur_index = cur.second;
		pq.pop();

		
		if (cur_dist > d[cur_index])
			continue;

		for (int i = 0; i < graph[cur_index].size(); i++)
		{
			int next_dist = graph[cur_index][i].first;
			int next_index = graph[cur_index][i].second;

			if (next_dist + cur_dist < d[next_index])
			{
				d[next_index] = next_dist + cur_dist;
				pq.push(make_pair(-d[next_index], next_index));
			}
		}
	}
	for (int i = 1; i < v + 1; i++)
	{
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}
	return 0;
}