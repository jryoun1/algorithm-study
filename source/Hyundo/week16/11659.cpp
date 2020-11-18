#include <iostream>
#define MAX 100000
#define endl "\n"

using namespace std;

int sum[MAX];

int main(void)

{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			sum[i+1] = sum[i] + num;
		}

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << sum[y] - sum[x-1] << endl;
	}
	return 0;
}
