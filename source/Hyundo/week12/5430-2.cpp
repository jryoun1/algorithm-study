#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	int T;
	int n;
	int num;
	string p;
	string arr;
	bool reverse;
	bool error;
	deque<int> d;

	cin >> T;

	while (T--) {
		d.clear();
		num = 0;
		reverse = false;
		error = false;

		cin >> p;
		cin >> n;
		cin >> arr;

		//입력값중 "[" 와 "]"제거
		arr = arr.substr(1, arr.size() - 2);

		for (int i = 0; i < arr.size(); ++i) {
			if (atoi(arr.substr(i, 1).c_str()) != 0 || arr.substr(i, 1).compare("0") == 0) {
				num *= 10;
				num += stoi(arr.substr(i, 1));
			}
			else {
				d.push_back(num);
				num = 0;
			}
		}

		if (num != 0) {
			d.push_back(num);
		}

		for (int i = 0; i < p.size(); ++i) {
			if (p[i] == 'R') {
				reverse = !reverse;
			}
			else if (p[i] == 'D') {
				//현재 비어있는 상태에서 D를 실행할 경우 error 처리
				if (d.empty()) {
					error = true;
					break;
				}
				if (reverse == true) {
					d.pop_back();
				}
				else {
					d.pop_front();
				}
			}
		}

		if (error) {
			cout << "error" << endl;
			continue;
		}

		cout << "[";
		//현재 상태가 reverse 되어 있는 상태가 아니라면 앞에서 삭제
		if (!reverse) {
			while (d.size()) {
				cout << d.front();
				d.pop_front();
				if (d.size()) {
					cout << ",";
				}
			}
		}
		//현재 상태가 reverse가 홀수번 이루어 져서 반대의 상태라면 뒤에서 삭제
		else {
			while (d.size()) {
				cout << d.back();
				d.pop_back();
				if (d.size()) {
					cout << ",";
				}
			}
		}
		cout << "]" << endl;
	}

	return 0;
}