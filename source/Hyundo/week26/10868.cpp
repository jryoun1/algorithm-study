#include<iostream>
#include<algorithm>

#define MAX 1000001
#define INF 1000000001

using namespace std;

int N, M;
long long arr[MAX];  //주어진 배열
long long tree[MAX * 4]; //주어진 배열을 통해 만들어진 세그먼트 트리를 저장하는 배열


long long init(int left, int right, int node) {
	if (left == right) return tree[node] = arr[left];
	int mid = (left + right) / 2;
	return tree[node] = min(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
}

long long getMin(int node, int left, int right, int start, int end) {
	if (right < start || left > end) return INF;
	if (start >= left && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return min(getMin(node * 2, left, right, start, mid), getMin(node * 2 + 1, left, right, mid + 1, end));
}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init(0, N - 1, 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << getMin(1, a - 1, b - 1, 0, N - 1) << "\n";
	}

}