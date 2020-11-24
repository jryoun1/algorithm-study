#include<iostream>
#include<vector>
#define MAX 1000001

using namespace std;

int T;

int arr[MAX];

vector<int> primeNum;


//에라토스테네스의 체 알고리즘을 이용하여 (1~1000001) 사이의 소수를 primeNum에 저장
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
		if(arr[i]!=0)
			primeNum.push_back(arr[i]);
	}
}

void solution(int num)
{
	//범위 내의 숫자가 아니므로  return
	if (num == 0||num==1)
		return;
		
	//입력받은 숫자가 소수라면 "num 1" 형태로 출력
	if (arr[num] != 0) {
		cout << num <<" "<<1<< endl;
		return;
	}

	//입력값을 변형하므로 임의로 저장한 num값
	int tmpNum=num;
	//소인수분해를 진행하였을 때의 각 숫자의 사용 횟수를 저장
	int countNum[MAX] = { 0, };

	for (int i=0;num!=1;) {
		//소인수 분해는 소수로 이루어지므로 입력값 Num을 primeNum 배열의 값들로 나누면서 진행
		//나머지가 0인경우 : 해당 숫자로 소인수 분해가 이루어지는 경우
		if (num % primeNum[i] == 0)
		{
			//나눌 때 사용한 숫자의 개수를 count
			countNum[primeNum[i]]++;
			//숫자를 나누고 난 후 나머지를 num에 저장				
			num = num / primeNum[i];
			//i=0으로 초기화를 통해 해당 소수로 다시 소인수분해가 진행되는 경우를 체크
			i = 0;
			continue;
		}
		//해당 index의 소수로 소인수 분해가 이루어지지 않는 경우 다음 소수로 진행
		else
			i++;
	}


	//출력
	for (int i = 2; i < tmpNum; i++)
	{
		if (countNum[i] != 0)
		{
			cout << i << " " << countNum[i] << endl;
		}
	}

}


int main() {
	cin >> T;

	aratos();

	for (int i = 0; i < T; i++)
	{
		int tmp;
		cin >> tmp;
		solution(tmp);
	}

	return 0;
}