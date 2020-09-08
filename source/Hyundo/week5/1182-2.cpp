#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int S = 0;
int N = 0;
int answer = 0;

void DFS(int sum, int idx)
{
	//arr의 범위를 벗어난 경우에는 함수 종료
	if (idx >= N)
	{
		return;
	}
	
	//현재의 인덱스의 수를 더하기 전의 상태를 tmpSum에 저장
	int tmpSum = sum;
	sum += arr[idx];
	
	if (sum== S) {

		answer++;
	}

	DFS(tmpSum, idx + 1); //현재 인덱스의 수를 더하지 않은 결과로 다시 진행
	DFS(sum, idx + 1);    //현재 인덱스의 수를 더한 상태로 다시 진행
}


int main()
{
	int tmp = 0;
	//input
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	DFS(0, 0);
	//정답 출력
	printf("%d", answer);

	return 0;
}