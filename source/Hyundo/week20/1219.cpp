#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <queue>

#define INF 1LL << 60

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ll dist[111];
ll cost[111];
bool getGee[111];
vector<pii> adj[111];//교통 수단 정보 저장

bool visit[111];

int main()
{
	int V, E, start, end;


	//도시의 수 , 시작 도시, 도착 도시, 교통 수단개수
	scanf("%d %d %d %d", &V, &start, &end, &E);
	//교통 수단 정보
	for (int i = 0; i < E; i++)
	{
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);

		adj[from].push_back({ to, val });
	}
	//각 도시에서 벌 수 있는 돈의 최댓값
	for (int i = 0; i < V; i++)
		scanf("%lld", &cost[i]);

	//각 도시별 가중치 -INF로 초기화
	for (int i = 0; i < V; i++)
		dist[i] = -INF;

	//시작 도시의 초기값 저장
	dist[start] = cost[start];

	// 벨만포드
	bool update = true;
	bool ok = false;

	int cnt = 0;
	while (update && cnt != V)
	{	
		update = false;

		for (int i = 0; i < V; i++)
			for (auto j : adj[i])
			{
				//시작위치 버는 돈 + 도착위치 버는 돈 - 교통수단 비용 > 도착위치 현재 값
				if (dist[i] != -INF && dist[i] + cost[j.first] - j.second > dist[j.first])
				{
					dist[j.first] = dist[i] + cost[j.first] - j.second;
					update = true;

					//마지막 위치에서 갱신이 이루어짐
					if (cnt == V - 1)
						//돈을 버는 사이클의 후보에 해당하는 지점들 true 표기
						getGee[i] = true;
				}
			}
		cnt++;
	}

	// bfs
	bool getChk = false;
	
	queue<int> q;
	for (int i = 0; i < V; i++)
		if (getGee[i])
			q.push(i);

	//돈을 버는 사이클의 후보에 해당하는 정점에 대해 bfs로 도착점으로 가는 지 확인
	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		if (visit[here])
			continue;

		visit[here] = true;

		for (int i = 0; i < adj[here].size(); i++)
		{	//정점에 대해 도착점으로 가는 것을 체크
			if (adj[here][i].first == end)
			{
				getChk = true;
				break;
			}
			if (!visit[adj[here][i].first])
				q.push(adj[here][i].first);
		}

		if (getChk)
			break;
	}

	if (dist[end] == -INF)
		printf("gg");
	else if (getChk)
		printf("Gee");
	else
		printf("%lld", dist[end]);


	return 0;
}