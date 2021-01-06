#include<iostream>
#define MAX 30000

using namespace std;

int N, d, k, c;
int arr[MAX];
int kind[3001];

int main()
{
	cin >> N >> d >> k >> c;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	int left=1, right=0, cnt = 0, max = 0;
	int sushi=0;



	while (1) {
		
		++sushi;

		if (sushi >= N+4)
			break;

		if (right == N)
			right = 0;
		if (left == N)
			left = 0;

		
		if (kind[arr[++right]] == 0) {
			cnt++;
		}

		kind[arr[right]]++;

		if (sushi > 4) {
			if (kind[arr[left]] == 1) {
				cnt--;
			}

			kind[arr[left]]--;
			left++;

			if (kind[c] == 0) {
				cnt++;
				if (cnt >= max)
					max = cnt;
				cnt--;
			}

			else
				if (cnt >= max)
					max = cnt;
		}
	}

	cout << max;

	return 0;
}