#include<iostream>
#include<vector>

#define MAX 4000001

using namespace std;

bool arr[MAX];

vector<int> primeNum;

//에라토스테네스의 체 알고리즘을 이용하여 (1~4000000) 사이의 소수를 primeNum에 저장
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
	//아래 범위를 벗어났을 경우 더 이상 count를 진행하지 않는다.
	while (bot <= top && top < maxIdx && primeNum[bot] <= N) {
		//주어진 N값보다 sum이 작으면 top을 ++하여 다음index의 소수를 더한다.
		if (sum < N) {
			sum += primeNum[top++];
		}
		//주어진 N값보다 sum이 크면 bot을 ++하여 이전index의 소수를 뺀다.
		else if (sum >= N) {
			sum -= primeNum[bot++];
		}
		//소수의 합이 입력값 N과 같은 경우 count를 더해준다.
		if (sum == N) count++;
	}


	cout << count << endl;

	return 0;
}