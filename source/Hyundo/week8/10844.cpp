#include<iostream>
#define MAX 101
#define N 10

using namespace std;
long long dp[N][MAX] = { 0 };
int n;

long long sol(int x, int y) {
	//이미 방문한 경우
	if (dp[x][y] != 0)
		return dp[x][y];
	//기저
	if (y == n - 1) {
		dp[x][y] = 1;
		return dp[x][y];
	}

	if (x == 0)
		dp[x][y] += sol(x + 1, y + 1);
	else if (x == 9)
		dp[x][y] += sol(x - 1, y + 1);
	else {
		dp[x][y] += sol(x - 1, y + 1);
		dp[x][y] += sol(x + 1, y + 1);
	}

	return dp[x][y] % 1000000000;
}


int main() {
	cin >> n;
	long long sum = 0;
	for (int i = 1; i < 10; i++)
		sum += sol(i, 0);

	cout << sum % 1000000000 << endl;
	return 0;
}