#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;
int answer=0;

//소수 판별
bool primeCheck(int num) {
	//1은 소수에서 제외
	if (num == 1)
		return false;
	//2부터 num-1까지 나누면서 한번이라도 나머지가 없는 경우 false return(소수가 아님)
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

//조건 함수(현재 answer에 값을 더한 값이 조건에 해당하는지 확인
//조건에 해당하는 경우 현재 루트의 answer값을 새로운 값으로 초기화하여
//다음 단계에서 새로운 answer값으로 진행할 수 있도록 함
bool condition(int a,int x) {
	if (primeCheck(answer * 10 + a)) {
		answer = answer * 10 + a;
		return true;
	}
	else
		return false;
}


void dfs(int x)
{
	//기저
	if (x > N)
	{
		cout << answer<<endl;
		return;
	}
	//현재 answer값의 조건을 파악하고 1~9까지의 값을 더한 새로운 숫자를 통해 dfs를 재귀적으로 진행
	for (int i = 1; i < 10; i++)
	{
		if (condition(i, x)) {
			dfs(x + 1);
			//다음 단계에서 answer값을 다시 사용하기 위해 10으로 나누어주어 원래의 상태로 backtracking하는 과정
			answer /= 10;
		}
	}
	return;
}


int main()
{
	cin >> N;

	dfs(1);

	return 0;
}