#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

using namespace std;

//각 진영의 x, y, r 을 담고 있는 클래스
class camp {
public:
	int x, y, r;
	camp() {}
	camp(int x, int y, int r) {
		this->x = x;
		this->y = y;
		this->r = r;
	}
};

int t, n;
camp c[3000];
int root[3000];

int find(int i) {
	if (i == root[i])
		return i;
	else
		return root[i] = find(root[i]);
}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y)
		return;
	else
		root[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin>>c[i].x>>c[i].y>>c[i].r; //
			root[i] = i;
		}

		int cnt = 0;
		//모든 진영에 대하여 서로 비교하여 merge 여부 확인
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int x = c[i].x - c[j].x;
				int y = c[i].y - c[j].y;  
				int r = c[i].r + c[j].r;  //c[i] 점과 c[j] 점의 도달거리의 합
				int d = x * x + y * y; //c[i] 점과 c[j] 점의 중심점 사이 거리(의 제곱)

				//c[i] 점과 c[j] 점의 중심점 사이 거리(의 제곱) 과 c[i] 점과 c[j] 점의 도달거리의 합(의 제곱)
				//비교하여 두 지점이 통신이 가능하다면 merge
				if (d <= r * r) {
					if (find(i) != find(j)) {
						merge(i, j);
						//두 점이 통신이 가능하여 하나의 그룹으로 합쳐졌을 때 cnt++
						cnt++;
					}
				}
			}
		}

		//처음에 주어진 총 그룹의 개수-합쳐진 그룹의 개수 = 적군 진영의 그룹 개수
		cout << n-cnt << endl;
	}
	return 0;
}
