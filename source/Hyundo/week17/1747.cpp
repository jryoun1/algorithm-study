#include<iostream>
#include<vector>
#include<string>

#define MAX 1100000
//입력 값은 1000001로 제한되어 있지만
//100001크거나 같고, 소수이면서 팰린드롬인 수를 찾기 위해
//소수를 저장할 때 범위를 더 크게 잡아야 한다.
using namespace std;

int N;

bool arr[MAX];
vector<int> primeNum;

void aratos() {
	int i = 2;
	for (i = 2; i < MAX; i++) {
		arr[i] = i;
	}

	for (i = 2; i < MAX; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j < MAX; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = 2; i < MAX; i++)
	{
		if (arr[i] != 0)
			primeNum.push_back(i);
	}
}



int main() {

	aratos();

	cin >> N;

	for (int i = 0; i < primeNum.size(); i++)
	{
		bool check = true;
		if (primeNum[i] < N)
			continue;
		else
		{
			string str=to_string(primeNum[i]);
			for (int i = 0; i < str.size() / 2 + 1; i++) {
				if (str[i] == str[str.size() - i-1])
					continue;
				else {
					check = false;
					break;
				}
			}

			if (check == true)
			{
				cout << primeNum[i] << endl;
				break;
			}
		}

	}



	return 0;
}