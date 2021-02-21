#include<iostream>

using namespace std;

int main() {

	int ans = 0;
	int arr[101];
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = N; i > 1; i--)
	{
		if (arr[i] <= arr[i - 1])
		{
			int tmp = arr[i - 1] - arr[i];
			ans += (tmp + 1);
			arr[i - 1] -= (tmp + 1);
		}
	}

	cout << ans << endl;

	return 0;
}