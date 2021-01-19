#include<iostream>
#define MAX 202

using namespace std;

int N, M;
int root[MAX];

void init() {
	for (int i = 1; i <= N; i++)
		root[i] = i;

}

int find(int i) {
	if (root[i] == i)
		return i;
	else
		return root[i] = find(root[i]);

}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y)
		return;
	else
		root[x] = y;
}

int main() {
	cin >> N >> M;
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1)
				merge(i, j);
		}
	}

	//이후 입력값과의 비교를 위한 초기값 설정
	int tmpRoot;
	cin >> tmpRoot;
	int connect=find(tmpRoot);
	bool check = true;

	//입력값에 대하여 root값 비교를 통해 같은 트리 내에 존재하지 않는 경우 도달 불가 -> check = false
	for (int i = 2; i <= M; i++) {
		int tmp;
		cin >> tmp;
		if (find(tmp) != connect) {
			check = false;
		}
	}

	if (check == false)
		cout << "NO";
	else cout << "YES";
}