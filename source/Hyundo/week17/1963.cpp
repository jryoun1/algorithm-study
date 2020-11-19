#include<iostream>
#include<vector>

using namespace std;

int T;

int arr[10001];

void aratos() {
	int i = 2;

	for (i = 2; i < 10000; i++) {
		arr[i] = i;
	}

	for (i = 2; i < 10000; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j < 10000; j += i) {
			arr[j] = 0;
		}
	}
}

void solution(int A, int B)
{
	int answer = 0;




	cout << answer;
}

int main()
{
	aratos();

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int numA, numB;
		cin >> numA >> numB;
		solution(numA, numB);
	}

	return 0;
}