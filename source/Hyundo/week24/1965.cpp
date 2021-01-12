#include<iostream>

using namespace std;


int boxSize[1001];
int mem[1001];
int n;
int answer;

int sol(int from) {
	bool check = false;
	int rePoint = 0;
	int max_in = 0;
	int min = 1001;
	for (int i = from; i >= 1; i--) {
		if (boxSize[i] < min) {
			max_in++;
			min = boxSize[i];
		}
		else {
			if (check == false) {
				mem[i] = -1;
				rePoint = i;
				check = true;
			}
		}
	}
	if (max_in > answer)
		answer = max_in;

	if (check == false) {
		return -1;
	}
	else {
		return rePoint;
	}
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> boxSize[i];
	}

	for (int i = n; i > 0; i--) {
		int tmp = sol(i);
		if (tmp == -1)
			break;
		else {
			i = tmp + 1;
		}

	}

	cout << answer << endl;

	return 0;
}