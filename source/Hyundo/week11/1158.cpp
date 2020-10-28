#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		v.push_back(i);
	vector<int>::iterator it;
	it = v.begin();
	cout << "<";
	while (v.size() != 1) {
		for (int i = 0; i < K - 1; ++i) {
			++it;
			//끝까지 갔을 경우에 원형이므로 begin으로 다시 시작
			if (it == v.end())
				it = v.begin();
		}
		//현 위치로부터 K번째인 제거되는 사람을 출력
		cout << *it << ", ";
		it = v.erase(it);
		if (it == v.end())
			it = v.begin();
	}
	cout << *it << ">";
}