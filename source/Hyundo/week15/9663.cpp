#include<iostream>
#include<cstdlib>
#define MAX 16

using namespace std;


int map[MAX] = { 0, };
int N;
int cnt=0;


bool condition(int x)
{
	for (int i = 0; i < x; i++)
	{
		//조건 : 같은 y축선상에 있으면 안됌 + 대각선상에 있으면 안됌
		if (map[x] == map[i] || abs(x - i) == abs(map[x] - map[i]))
			return false;
	}

	return true;
}

void dfs(int x) {

	//주어진 개수를 모두 채운 경우 return 1;
	if (x == N-1) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		//조건에 맞으면 다음 층으로 진행
		map[x] = i;
		if (condition(x)) {
			dfs(x + 1);
		}
		//조건에 맞지 않으면 중단
		else
			return;
	}
}


int main()
{
	cin>>N;

	dfs(0);

	cout << cnt << endl;

	return 0;
}