#include<iostream>
#define MAX 1000001

using namespace std;

int n, m;
int root[MAX];
int level[MAX];

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

	if (level[x] > level[y])
		root[y] = x;
	else
		root[x] = y;

	if (level[x] == level[y])
		++level[y];
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		root[i] = i;
		level[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		bool c;
		int a, b;
		cin >> c >> a >> b;
		if (c == 1)
		{
			if (find(a) == find(b))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
		else
			merge(a, b);
	}


}