#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
#define endl "\n"

using namespace std;

vector<int> arr;

int sum[MAX];
int resultSum[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	int minElementIndex = std::min_element(arr.begin(), arr.end()) - arr.begin();
	vector<int>::iterator iter = arr.begin()+minElementIndex;
	if (*min_element(arr.begin(), arr.end()) < 0) {
		arr.erase(iter);
	}

	for (int i = 0; i < N-1; i++)
	{
		sum[i + 1] = sum[i] + arr[i];
	}

	for (int i = 0; i < N; i++) {
		int max = -1001;
		for (int j = i+1; j < N; j++)
		{
			if (max < (sum[j] - sum[i]))
				max = sum[j] - sum[i];			
		}
		resultSum[i] = max;
	}
	


	cout << *max_element(resultSum,resultSum+N) << endl;
	return 0;
}
