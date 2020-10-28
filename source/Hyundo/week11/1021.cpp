#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main() {
	int count = 0;
	deque<int> dq;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		dq.push_back(i);

	for (int i = 0; i < M; ++i) {
		int num;
		cin >> num;
		int index = 0;
		for (int i = 0; i < dq.size(); ++i) {
			if (dq[i] == num) {
				index = i;
				break;
			}
		}
		//맨 앞에 있는 값과 뽑으려는 값과의 인덱스 차이 계산
		//2번 연산과 3번 연산중 더 유리한 연산을 찾음
		//2번 연산 실행
		if (index < dq.size() - index) {
			for (;;) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				++count;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		//3번 연산 실행
		else {
			for (;;) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				++count;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	cout << count;
}