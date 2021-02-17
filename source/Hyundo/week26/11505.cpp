#include<iostream>
#include<math.h>
#define MAX 1000010
#define MODULER 1000000007

using namespace std;

long long arr[MAX];  //주어진 배열
long long tree[MAX * 4]; //주어진 배열을 통해 만들어진 세그먼트 트리를 저장하는 배열

long long init(int node, int start, int end) {
	//리프노드
	if (start == end) return tree[node] = arr[start] % MODULER;
	int mid = (start + end) / 2;
	return tree[node] = (init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end)) % MODULER;
}

//[start,end] : 현재 node가 담당하고 있는 구간
//[left,right] : 합을 구해야 하는 구간
long long sum(int left, int right, int node, int start, int end) {

	if (left > end || right < start) return 1;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return (sum(left, right, node * 2, start, mid) * sum(left, right, node * 2 + 1, mid + 1, end))%MODULER;
}

long long update(int node, int start, int end, int index, long long num) {
	//범위 내에 포함되지 않는 경우 : update과정없이 반환
	if (index < start || index > end) return tree[node];
	//리프 노드에 도달한 경우 : update과정 진행
	if (start == end) return tree[node] = num;
	//다른 경우 : 하위 트리에서 index에 해당하는 update진행 후 그 결과를 tree에 다시 초기화
	int mid = (start + end) / 2;
	return tree[node]=(update(node * 2, start, mid, index, num) * update(node * 2 + 1, mid + 1, end, index, num))%MODULER;
	
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init(1, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			update(1, 0, N - 1, b, c);
		}
		else {
			cout << sum(b - 1, c - 1, 1, 0, N - 1) % MODULER << "\n";
		}
	}

}