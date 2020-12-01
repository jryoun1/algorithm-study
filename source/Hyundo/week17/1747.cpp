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

//에라토스테네스의 체 알고리즘을 이용하여 (1~1100000) 사이의 소수를 primeNum에 저장
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

	//전체 소수의 개수만큼 check
	for (int i = 0; i < primeNum.size(); i++)
	{
		bool check = true;
		//현재 소수가 N보다 작은 경우 진행하지 않는다.
		if (primeNum[i] < N)
			continue;

		//1. 현재 소수가 N보다 큼
		else
		{
			//팰린드롬을 확인하기 위해 int to string
			string str=to_string(primeNum[i]);
			//가장 높은 자리수와 낮은 자리수부터 팰린드롬 확인
			for (int i = 0; i < str.size() / 2 + 1; i++) {
				//2. 팰린드롬 수라면 check = true로 for문 종료
				if (str[i] == str[str.size() - i-1])
					continue;
				else {
					check = false;
					break;
				}
			}

			//(1) (2) 조건에 모두 해당하는 첫번 째 숫자 =(3).가장 작은 수
			//(1)(2)(3) 조건에 해당하는 숫자를 출력하고 반복문을 종료
			if (check == true)
			{
				cout << primeNum[i] << endl;
				break;
			}
		}

	}



	return 0;
}