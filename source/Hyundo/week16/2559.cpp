#include <iostream>
#define MAX 100001
#define endl "\n"

using namespace std;

int sum[MAX];

int main(void)

{
	int max=-1001;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, k;
	cin >> N >> k;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		sum[i + 1] = sum[i] + num;
	}

	for (int i = 0; i < N-k+1; i++)
	{
		if(max<(sum[i+k] - sum[i]))
			max = sum[i + k] - sum[i];
	}

	cout << max << endl;
	return 0;
}
