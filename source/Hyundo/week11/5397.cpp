#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

string Solve() {
	string text;
	stack <int> stk, temp;

	cin >> text;
	for (int i = 0; i < text.size(); i++) {
		//왼쪽 화살표 입력 시 stk.top 값을 temp에 보낸 후, pop
		if (text[i] == '<') {
			if (stk.empty()) continue;
			else {
				temp.push(stk.top());
				stk.pop();
			}
		}
		//오른쪽 화살표는 반대로 temp.top 값을 stk에 보낸 후, pop
		else if (text[i] == '>') {
			if (temp.empty()) continue;
			else {
				stk.push(temp.top());
				temp.pop();
			}
		}
		//백스페이스는 stk 스택을 pop
		else if (text[i] == '-') {
			if (stk.empty()) continue;
			else stk.pop();
		}
		//이외에는 단순 push 하면 됩니다.
		else
			stk.push(text[i]);
	}

	//result 스트링 문자에 모두 push
	string result;
	while (!temp.empty()) {
		stk.push(temp.top());
		temp.pop();
	}
	while (!stk.empty()) {
		result += stk.top();
		stk.pop();
	}
	//stack은 LIFO 방식이므로 reverse 함수를 이용해 거꾸로 출력
	reverse(result.begin(), result.end());
	return result;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int testcase; 
	cin >> testcase;

	while (testcase--) {
		cout << Solve() << endl;
	}
	return 0;
}
