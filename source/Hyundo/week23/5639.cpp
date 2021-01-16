#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;

void makeTree(int from, int to) {
	int idx = from + 1;
	if (from == to)
		return;
	//leaf node인 경우 출력
	if(from == to - 1){
		cout << arr[from] << endl;
		return;
	}
	//from(root)를 기준으로 left와 right의 경계점을 찾음
	while (idx < to && arr[idx] < arr[from]) {
		idx++;
	}
	//root를 기준으로 left와 right를 나누어 재귀적으로 진행
	makeTree(from + 1, idx);
	makeTree(idx, to);
	//left와 right내에 출력이 모두 완료된 후에 parent node의 데이터 출력
	cout << arr[from] << endl;
}


int main() {
	int num;
	//입력
	while (cin >> num) {
		if (num == -1)
			break;
		else
			arr.push_back(num);
	}
	//from 0 ~ to arr.size()
	makeTree(0, arr.size());

	return 0;
}