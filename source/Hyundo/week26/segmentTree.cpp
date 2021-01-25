#include<iostream>
#define MAX 1000010

using namespace std;

long long arr[MAX];  //주어진 배열
long long tree[MAX * 4]; //주어진 배열을 통해 만들어진 세그먼트 트리를 저장하는 배열

//Segment Tree를 만드는 과정
long long init(int node,int start, int end) {
	//node가 리프 노드인 경우, 리프 노드는 배열의 그 원소를 가져야 하기 때문에 tree[node] = a[start]가 된다.
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	//node의 왼쪽 자식, 오른쪽 자식, 각각의 자식 트리의 합을 저장
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

//합을 구하는 과정
//[start,end] : 현재 node가 담당하고 있는 구간
//[left,right] : 합을 구해야 하는 구간
long long sum(int left, int right, int node, int start, int end) {
	//1. [left,right]와 [start,end]가 겹치지 않는 경우
	// : 더 이상 탐색을 이어나갈 필요가 없음
	if (left > end || right < start) return 0;

	//2. [left,right]rk [start,end] 를 완전히 포함하는 경우
	// : 범위 안에 포함되며 그 자식도 모두 포함되므로 더 이상 자식 노드를 호출할 필요가 없음
	if (left <= start && end <= right) return tree[node];

	//3. [start,end]가 [left,right]를 완전히 포함하는 경우
	//4. [left, right] 와[start, end]가 겹쳐져 있는 경우(1, 2, 3 제외한 나머지 경우)
	// : 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색을 시작
	int mid = (start + end) / 2;
	return sum(left, right, node * 2, start, mid) + sum(left, right, node * 2 + 1, mid+1, end);
}

//수를 변경하는 과정
//어떤 수를 변경할 경우, 그 숫자가 포함된 구간을 담당하는 노드를 모두 변경해야 함
//dif = val - arr[index] (arr[index] : 병경될 숫자,  val : 변경할 숫자 )
void update(int node, int start, int end, int index, long long dif) {
	//1. [start,end]에 index가 포함되지 않는 경우
	if (index < start || index > end) return;

	//2. [start,end]에 index가 포함되는 경우
	// : diff만큼 증가시켜 합을 변경해 주어야 함
	tree[node] += dif;

	//현재 node가 리프 노드가 아닌 경우 자식도 변경해 주어야 하기 대문에 리프 노드인지 검사
	if (start == end) return;
	int mid = (start + end) / 2;
	update(node * 2, start, mid, index, dif);
	update(node * 2 + 1, mid + 1, end, index, dif);
}


int main() {
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init(1, 0, N-1);

	for (int i = 0; i < M+K; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			long long diff = c - arr[b];
			arr[b] = c;
			update(1,0,N-1,b,diff);
		}
		else {
			cout<<sum(b-1,c-1,1,0,N-1)<<endl;
		}
	}

}