#include<iostream>

using namespace std;

long long tree[4 * 1000001] = { 0 };


//node, index, start, end, diff
void update(int node, int index, int start, int end, long long diff) {
	if (start > index || end < index)
		return;

	tree[node] += diff;

	int mid = (start + end) / 2;
	if (start != end)
	{
		update(node * 2, index, start, mid, diff);
		update(node * 2 + 1, index, mid + 1, end, diff);
	}
}

//node, start, end, left, right
long long sum(int node, int start, int end, int left, int right) {

	if (right<start || left>end)
		return 0;
	if (left <= start && right >= end)
		return tree[node];
	
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}



int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < Q; i++) {
		int q1, q2;
		long long q3;
		cin >> q1 >> q2 >> q3;
		if (q1 == 1)
		{
			update(1,q2,1,N,q3);
		}
		else
		{
			cout << sum(1,1,N,q2,q3) << "\n";
		}
	}


	return 0;
}