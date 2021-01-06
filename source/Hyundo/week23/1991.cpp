#include<iostream>

using namespace std;

char tree[26][2] = { '.', };

void preorder(char root) {
	if (root == '.') return;
	else {
		cout << root;
		preorder(tree[root - 'A'][0]);
		preorder(tree[root - 'A'][1]);
	}
}

void inorder(char root) {
	if (root == '.') return;
	else {
		inorder(tree[root - 'A'][0]);
		cout << root;
		inorder(tree[root - 'A'][1]);
	}
}

void postorder(char root) {
	if (root == '.') return;
	else {
		postorder(tree[root - 'A'][0]);
		postorder(tree[root - 'A'][1]);
		cout << root;
	}
}

int main() {

	int n;
	cin >> n;
	char root, left, right;
	for (int i = 0; i < n; i++)
	{
		cin >> root >> left >> right;
		tree[root - 'A'][0] = left;
		tree[root - 'A'][1] = right;
	}

	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');

	return 0;
}