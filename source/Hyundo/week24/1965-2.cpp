#include <iostream>

using namespace std;

int N;
int mem[10001], box[1000];

int dp(int from)
{   //from으로부터 시작하여 가장 많은 박스를 넣을수 있는 양을 반환
	int answer = mem[from + 1];
	if (answer != -1) {
		mem[from + 1] = answer;
		return answer;
	}
	answer = 0;
	//from(현재위치)로부터 1~N-next 거리만큼 떨어진 위치와의 조합 확인
	for (int next = from + 1; next <= N; next++)
		if (from == 0 || box[from] < box[next]) {
			int tmp = dp(next) + 1;
			if (tmp > answer)
				answer = tmp;
		}
	mem[from + 1] = answer;
	return answer;
}

int main(void)
{
	std::fill_n(mem, 1001, -1);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> box[i];
	//첫번째 박스 부터 진행
	cout << dp(0) << endl;

	for (int i = 0; i <= N; i++) {
		cout << i << " : " << mem[i] << endl;
	}

	return 0;

}
