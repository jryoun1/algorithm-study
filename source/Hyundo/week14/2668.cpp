#include<iostream>
#include<algorithm>
using namespace std;
int N;

int ans[101];
int fin[101];
int map[101];//둘째 줄에 이루는 정수들 집합
int visited[101]; //방문 체크
int cnt = 0;

void dfs(int n)
{
	int i;
	//방문 여부 표시
	visited[n] = 1;
	//현재 n 위치의 둘째 줄에 이루는 정수에 대하여 방문 여부 체크
	//방문한 적이 없다면  dfs를 통해 둘 째줄의 정수에 대한 dfs 진행
	if (visited[map[n]] == 0)
		dfs(map[n]);
	//sycle이 돌아온 경우 ans에 정답을 추가해준다.
	else if (fin[map[n]] == 0){
		ans[cnt++] = n;
		//현재 숫자와 둘째 줄의 숫자를 모두 정답에 추가한다.
		for (i = map[n]; i != n; i = map[i])
			ans[cnt++] = i;
	}
	//이후에 sycle에 포함되더라도 ans에 추가되지 않도록 해당 숫자의 fin을 1로 초기화한다.
	//혹은 위 조건에 모두 해당하지 않는 경우에도 sycle에 포함되지 않음으로 fin을 1초 초기화한다.
	fin[n] = 1;
}

int main()
{
	int i, j;
	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> map[i];
	
	for (i = 1; i <= N; i++){
		//이미 방문한 경우 dfs진행 x
		if (visited[i]) continue;
		dfs(i);
	}
	//큰 수의 순서로 출력하기 위해 sort
	sort(ans, ans + cnt);
	cout << cnt << "\n";
	for (i = 0; i < cnt; i++)
		cout << ans[i] << "\n";

	return 0;
}