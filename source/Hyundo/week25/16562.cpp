#include<iostream>
#define MAX 10002

using namespace std;

int N, M, k;

int price[MAX]; //각각의 학생이 원하는 친구비
int root[MAX];  


//1번친구부터 N번친구까지 자기자신을 root로 초기화
void init() {
	for (int i = 1; i <= N; i++)
		root[i] = i;
}

//Union-Find 함수의 find 
int find(int i) {
	if (root[i] == i)
		return i;
	else
		return root[i] = find(root[i]); //경로 압축
}

//Union-Find 함수의 Union (rank 대신 price로 비교(최소비용계산을 위해))
void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y)
		return;
	//두 트리의 루트에 대하여 친구비(price)로 비교
	if (price[x] > price[y])
		root[x] = y;
	else
		root[y] = x;
}


int main() {

	cin >> N >> M >> k;

	init();

	for (int i = 1; i <= N; i++)
		cin >> price[i];
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
		if (root[i] == i)
			answer += price[i];

	if (answer > k)
		cout << "Oh no";
	else
		cout << answer;

	return 0;
}