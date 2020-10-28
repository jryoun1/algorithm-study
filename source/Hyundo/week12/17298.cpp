#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

#define MAX 1000001

int N;
int NGE[MAX];
stack<std::pair<int, int>> s;

int main() {
	memset(NGE, -1, sizeof(NGE));

	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		//stack이 비어있는 경우에는 push
		if (s.size() == 0) 
			s.push({ tmp, i });
		else {
			//stack 내에 현재의 값보다 더 큰 수가 없거나 stack이 빌 때까지 반복
			while (tmp > s.top().first) {
				//stack내에 있는 값보다 현재 값이 더 크므로 현재 값을 오큰수에 삽입
				NGE[s.top().second] = tmp;
				//stack에 있는 값을 pop
				s.pop();
				if (s.size() == 0) break;
			}
			//stack내에 더 큰 수가 없을 경우에는 현재의 값을 stack에 push
			s.push({ tmp, i });
		}
	}
	for (int i = 0; i < N; i++) cout << NGE[i] << " ";
}
