#include<iostream>
#include<vector>

#define endl "\n"
#define MAX 510
#define INF 987654321
using namespace std;

int N, M;
long long Dist[MAX];
vector<pair<pair<int, int>, int>> Edge;

int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) Dist[i] = INF;
	for (int i = 0; i < M; i++)
	{
		int From, To, Cost;
		cin >> From >> To >> Cost;
		Edge.push_back(make_pair(make_pair(From, To), Cost));
	}

	//첫번째 도시 0
	Dist[1] = 0;
	for (int i = 1; i <= N - 1; i++)
	{
		//각 도시 별 모든 간선에 대해 가중치 계산
		for (int j = 0; j < Edge.size(); j++)
		{
			int From = Edge[j].first.first; //출발위치
			int To = Edge[j].first.second;  //도착위치
			int Cost = Edge[j].second;      //가중치

			if (Dist[From] == INF) continue;

			if (Dist[To] > Dist[From] + Cost) 
				Dist[To] = Dist[From] + Cost;
		}
	}

	for (int i = 0; i < Edge.size(); i++)
	{
		int From = Edge[i].first.first;
		int To = Edge[i].first.second;
		int Cost = Edge[i].second;

		if (Dist[From] == INF) continue;
		//다시 진행하였을 때 더 적은 값이 나오므로
		//음의 사이클을 도는 케이스
		if (Dist[To] > Dist[From] + Cost)
		{
			cout << -1 << endl;
			return;
		}
	}
	
	for (int i = 2; i <= N; i++)
	{
		//계산이 진행된적 없는 위치는 도달할 수 없는 도시
		if (Dist[i] == INF) cout << -1 << endl;
		else cout << Dist[i] << endl;
	}

	return 0;
}
