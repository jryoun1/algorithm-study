#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int arr[100001];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr+N);

	int ans = 0;

	for (int i = N-1; i >= 0; i--)
	{
		int tmp = (N - i)*arr[i];
		if (tmp > ans)
			ans = tmp;
	}

	cout << ans<<endl;


	return 0;
}