#include <iostream>

#define MAX 1000001

using namespace std;

long long tree[4*MAX];
//리프 노드 : 사탕 순위별 개수
//부모 노드 : 각각의 순위들에 해당하는 사탕 개수의 합

//top-down방식으로 해당 index까지 찾으면서 노드들에 저장된 하위 노드 data의 총 합을 조정한다.
void update(int node, int start, int end, int index, long long diff){
	if (start > index || index > end)
		return;

	tree[node] += diff;

	cout << node << " : " << tree[node] << endl;

	if (start != end){
		int mid = (start + end) / 2;
		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}
}


int query(int index, int target, int start, int end) {
	if (start == end)
		return start;
	int mid = (start + end) / 2;
	//뽑아야 하는 사탕의 번호보다 왼쪽 트리에 사탕이 더 많을 경우
	//왼쪾 트리 내에서 target에 해당하는 사탕을 뽑을 수 있음
	if (target <= tree[index * 2])
		return query(index * 2, target, start, mid);
	//뽑아야 하는 사탕의 번호보다 왼쪽 트리에 사탕이 더 적을 경우
	//왼쪽 트리에서는 target에 해당하는 사탕을 뽑을 수가 없음
	else
		return query(index * 2 + 1, target - tree[index * 2], mid + 1, end);
	//오른쪽 노드에는 왼쪽 노드에 있는 개수를 제외한 합이 저장되어 있으므로
	//오른쪽 노드에서 해당 target을 찾기 위해서는 왼쪽노드의 합 만큼 제외해야 한다.
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int A;
		cin >> A;
		if (A == 1){
			int B;
			cin >> B;
			int index = query(1, B, 1, MAX);
			cout << index << "\n";
			update(1, 1, MAX, index, -1);
		}

		else{
			int B;
			long long C;
			cin >> B >> C;

			update(1, 1, MAX, B, C);
		}
	}
	return 0;
}