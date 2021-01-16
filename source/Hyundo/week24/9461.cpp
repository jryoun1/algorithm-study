#include<iostream>

using namespace std;

long long p[101] = { 0 };

long long sol(int n) {

	if (p[n] != 0)
		return p[n];
	else if (n == 0) {
		return 0;
	}
	else if (n < 4) {
		p[n] = 1;
		return 1;
	}
	else if (n < 6) {
		p[n] = 2;
		return 2;
	}
	else{
		p[n] = sol(n - 1) + sol(n - 5);
		return p[n];
	}
}


int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << sol(n) << endl;
	}

	return 0;
}