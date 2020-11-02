#include <iostream>
#include <string.h>

using namespace std;

int N;
int arr[2001];
int M;

int dp[2001][2001];

bool sol(int s, int e) {

	//이미 확인한 경우
	if (dp[s][e] != -1)
		return dp[s][e];

	//펠린드롬인지 검사
	bool answer = 1;
	for (int i = 0; i <= (e - s) / 2; i++)
	{
		if (arr[s + i-1] != arr[e - i-1]) {
			dp[s][e] = 0;
			answer = 0;
			break;
		}
	}
	dp[s][e] = answer;
	return answer;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 2001; i++) 
		memset(dp[i], -1, sizeof(int) * 2001);

	cin>>N;
	for (int i = 0; i < N; i++)
		cin>>arr[i];
	cin >> M;

	bool ans[1000000];

	int S, E;
	for (int i = 0; i < M; i++)
	{
		cin >> S >> E;
		ans[i] = sol(S, E);
	}

	for (int i = 0; i < M; i++)
	{
		cout<<ans[i]<<"\n";
	}

	return 0;
}