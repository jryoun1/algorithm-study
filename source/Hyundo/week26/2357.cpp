#include<iostream>
#include<algorithm>

#define MAX 1000001
#define INF 1000000001

using namespace std;

int N, M;
long long arr[MAX];
long long treeMin[MAX * 4];
long long treeMax[MAX * 4];


//treeMin에는 하위노드중 최솟값을 treeMax에는 하위 노드 중 최댓값을 저장 
void init(int left, int right, int node) {
	if (left == right) {
		treeMin[node] = treeMax[node] = arr[left];
		return;
	}
	int mid = (left + right) / 2;
	init(left, mid, node * 2);
	init(mid + 1, right, node * 2 + 1);
	treeMin[node] = min(treeMin[node * 2], treeMin[node * 2 + 1]);
	treeMax[node] = max(treeMax[node * 2], treeMax[node * 2 + 1]);
	return;
}

long long getMin(int node, int left, int right, int start, int end) {
	if (right < start || left > end) return INF;
	if (start >= left && end <= right) return treeMin[node];

	int mid = (start + end) / 2;
	return min(getMin(node * 2, left, right, start, mid), getMin(node * 2 + 1, left, right, mid + 1, end));
}

long long getMax(int node, int left, int right, int start, int end) {
	if (right < start || left > end) return 0;
	if (start >= left && end <= right) return treeMax[node];

	int mid = (start + end) / 2;
	return max(getMax(node * 2, left, right, start, mid), getMax(node * 2 + 1, left, right, mid + 1, end));
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
		cout << getMin(1, a - 1, b - 1, 0, N - 1) << " " << getMax(1, a - 1, b - 1, 0, N - 1) << "\n";
	}

}