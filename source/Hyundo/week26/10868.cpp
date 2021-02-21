#include<iostream>
#include<algorithm>

#define MAX 1000001
#define INF 1000000001

using namespace std;

int N, M;
long long arr[MAX];  //주어진 배열
long long tree[MAX * 4]; //주어진 배열을 통해 만들어진 세그먼트 트리를 저장하는 배열


long long init(int left, int right, int node) {
	//리프 노드 도달 시 arr 배열의 값으로 tree를 초기화
	if (left == right) return tree[node] = arr[left];
	//리프노드 를 제외하고는 자식 노드 중 최솟값으로 tree를 초기화
	int mid = (left + right) / 2;
	return tree[node] = min(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
}

long long getMin(int node, int left, int right, int start, int end) {
	//범위를 벗어나는 경우 최대정수를 return하여 min 함수 대상에서 제외
	if (right < start || left > end) return INF;
	//찾는 범위 내에 현재 노드가 포함되는 경우 노드의 값을 반환
	if (start >= left && end <= right) return tree[node];

	//하위 트리내에서의 최솟값중 최솟값을 반환
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