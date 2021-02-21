#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector< pair<int, int> > time;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) 
		return a.first < b.first;
	//끝나는 시간이 같다면 시작 시간 오름차순 정렬
	return a.second < b.second; 
	//끝나는 시간 오름차순 정렬
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		time.push_back(make_pair(a, b));
	}

	sort(time.begin(), time.end(), compare);

	int lastTime = time[0].second;
	int ans = 1;
	for (int i = 1; i < N; i++){
		//다음회의의 시작시간(time[i].first)이 현재 회의 끝나는시간(time[i-1].second)
		//보다 크거나 같으면 ans++
		//이후에 다음회의의 끝나는시간을 lastTime에 초기화
		if (lastTime <= time[i].first){
			lastTime = time[i].second;
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}