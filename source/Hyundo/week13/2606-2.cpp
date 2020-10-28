#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define MAX 101

using namespace std;

int N;
int M;
bool mem[MAX] = { 0, };
vector<pair<int, int>> v;


void DFS(int x)
{
	if (mem[v[x].first-1] == 1)
		mem[v[x].second-1] = 1;
	if (mem[v[x].second-1] == 1)
		mem[v[x].first - 1] = 1;
	return;
}

int main()
{
	int cnt = 0;
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}

	sort(v.begin(), v.end());
	
	mem[0] = 1;

	for (int i = 0; i < M; i++)
		DFS(i);


	for (int i = 0; i < N; i++) {
		if (mem[i] == 1)
			cnt++;
	}


	cout << cnt-1;

	return 0;
}