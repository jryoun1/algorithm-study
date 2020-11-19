#include<iostream>
#include<vector>

using namespace std;

int arr[4000001];

vector<int> primeNum;
vector<int> sumOfPrime;

void aratos() {
	int i = 2;
	for (i = 2; i < 4000001; i++) {
		arr[i] = i;
	}

	for (i = 2; i < 4000001; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j < 4000001; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = 2; i < 4000001; i++)
	{
		if (arr[i] != 0)
			primeNum.push_back(arr[i]);
	}
}

void sumOfPrimeNumber()
{
	sumOfPrime.push_back(primeNum[0]);
	for (int i = 1; i < primeNum.size(); i++)
	{
		sumOfPrime.push_back(primeNum[i] + sumOfPrime[i - 1]);
	}
}


int main()
{
	aratos();
	sumOfPrimeNumber();

	int count=0;
	int N;
	cin >> N;
	int tmp=0;

	for (int i = 0; i < primeNum.size(); i++)
	{
		if (N < primeNum[i])
		{
			tmp = i;
			break;
		}
	}

	for (int i = 0; i<tmp; i++)
	{
		for (int j = i+1; j<tmp; j++)
		{
			if (sumOfPrime[j] - sumOfPrime[i] == N) {
				count++;
			}
		}
	}

	if (arr[N] != 0)
		count++;

	cout << count << endl;

	return 0;
}