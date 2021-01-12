#include <iostream>

using namespace std;

int n, k;
int coins[101];
int mem[10001] = { 0 };
//mem[i] = 합이 i 원이 되도록 하는 경우의 수

void sol() {
	mem[0] = 1;
	//mem[i] 의 i가 0이 된 경우 = 합이 i원이 되도록 만들 수 있다 -> 1
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coins[i]) {
				//mem[j] : 합이 j원이 되도록 하는 경우의 수
				//mem[j-coin[i]] : 합이 j-coin[i] 원이 되도록하는 경우의 수
				//mem[j]=mem[j] + mem[j-coin[i]] : 
				//coin[i] 로 인해 합이 j-coin[i]원이 되는 경우의 수만큼 j원이 되도록 만들 수 있다.
				mem[j] += mem[j - coins[i]];
			}
		}
	}
	cout << mem[k];
}

int main() {
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}

	sol();
	return 0;
}