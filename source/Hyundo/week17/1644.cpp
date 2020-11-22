#include<iostream>
#include<vector>

#define MAX 4000001

using namespace std;

bool arr[MAX];

vector<int> primeNum;

void aratos() {
	int i = 2;
	arr[1] = 1;
	for (i = 2; i < MAX; i++) {
		if (arr[i] == 1)
			continue;
		for (int j = i + i; j < MAX; j += i) {
			arr[j] = 1;
		}
	}
	for (int i = 2; i <= MAX; i++) {
		if (arr[i] == 0) {
			primeNum.push_back(i);
		}
	}
}

int main()
{
	aratos();
	int count=0;
	int N;

	cin >> N;
	int top = 0,bot = 0,sum = 0;

	int maxIdx = primeNum.size();
	while (bot <= top && top < maxIdx && primeNum[bot] <= N) {
		if (sum < N) {
			sum += primeNum[top++];
		}
		else if (sum >= N) {
			sum -= primeNum[bot++];
		}
		if (sum == N) count++;
	}


	cout << count << endl;

	return 0;
}