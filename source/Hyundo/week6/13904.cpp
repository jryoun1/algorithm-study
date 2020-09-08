#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main()
{
	int N;
	int d;
	int w;
	int answer = 0;
	vector<pair<int, int>> Score;
	cin >> N;
	int array[1000] = { 0 };

	for (int i = 0; i < N; i++){
		cin >> d >> w;
		Score.push_back(pair<int, int>(w, d));
	}
	
	sort(Score.begin(), Score.end());

	for (int i = N-1; i >= 0; i--)
	{
		while(Score[i].second>-1)
		{
			if (array[Score[i].second - 1] == 0) {
				array[Score[i].second - 1] = Score[i].first;

				break;
			}
			else
				Score[i].second--;
		}
	}
	for (int i = 0; i < 1000; i++)
	{
		answer += array[i];
	}

	cout << answer << endl;

	return 0;
}