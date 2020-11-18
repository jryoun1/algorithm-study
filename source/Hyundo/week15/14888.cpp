#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 12

using namespace std;

int N; // 수열의 개수
int arr[MAX]; //수열의 값을 저장하는 배열
int oper[4] = { 0, };//각각의 연산기호의 개수를 저장하는 배열
// + - x /
vector<int> answer; // 각각의 연산에 따른 답들을 저장하는 벡터

//choice 로 들어온 숫자에 따라 맞는 연산을 해주는 함수
int fundamental(int a, int b,int choice) {
	//각각의 연산이 수행된 경우 해당하는 연산의 개수를 하나 줄여준다.
	switch (choice) {
	case 0:
		oper[0]--;
		return a + b;
	case 1:
		oper[1]--;
		return a - b;
	case 2:
		oper[2]--;
		return a * b;
	case 3:
		oper[3]--;
		return a / b;
	default:
		break;
		return 0;
	}

}

void dfs(int x, int sum)
{
	if (x > N-1) {
		answer.push_back(sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] > 0) {
				dfs(x + 1, fundamental(sum, arr[x], i));
			//이전 단계에서 fundamental 내에서 줄인 연산을 다시 복구하여 사용하기 위해
			//해당 연산의 값을 다시 올려주어 다음 연산에서 사용한다.
			oper[i]++;
		}
	}
}



int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	//초기 max와 min 값을 수열 첫번째 값으로 설정한다.
	int max = arr[0];
	int min = arr[0];
	//첫번째 수열의 값을 sum으로 사용하고 두번째 수열부터 sum과의 연산을 진행한다.
	dfs(1, arr[0]);

	//answer 내에 저장된 값중 가장 큰 값과 작은 값을 찾는다.
	max = *max_element(answer.begin(), answer.end());
	min = *min_element(answer.begin(), answer.end());

	//답 출력
	cout << max << endl << min;

	return 0;
}