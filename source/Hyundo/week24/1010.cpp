#include <iostream>
using namespace std;

int T, N, M;
int mem[33][33] = { 0 };

int dp(int n, int m) {
	//n이 0일 때, n=m일 때 1 반환, 기저
	if (n == 0 || n == m)
		return 1;
	//이미 계산이 완료된 경우
	else if (mem[n][m] != 0) {
		return mem[n][m];
	}
	//점화식 dp[n][m] = dp[n-1][m-1] + dp[n][m-1]
	else {
		mem[n][m] = dp(n - 1, m - 1) + dp(n, m - 1);
		return mem[n][m];
	}
}

int main() {

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> M;
		cout<<dp(N, M)<<endl;
	}
	return 0;
}