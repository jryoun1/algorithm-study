#include<iostream>

using namespace std;

int T, N, M;

void solve(int nSite, int mSite) {




}


int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
	}

	long long sum = 0;
	for (int k = 17; k > 0; k--) {
		for (int i = k; i > 0; i--) {
			for (int j = i; j > 0; j--) {
				sum += j;
			}
		}
	}

	cout << sum;
	return 0;
}