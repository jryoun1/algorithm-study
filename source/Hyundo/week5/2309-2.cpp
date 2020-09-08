//일곱 난쟁이의 키의 합이 100이 되도록
//주어진 9명의 키중에서 2개를 제외하고
//7명의 키의합이 100인 경우를 찾으면 된다.
//일곱 난쟁이를 찾을 수 없는 경우는 없다고 하였고
//가능한 정답이 여러 가지인 경우에는 아무거나 출력한다. 라는 조건이 있으므로
//그러므로 최초로 합이 100이 되는 경우 답을 출력한다.
//모든 입력 값의 합을 구한 후 두 명의 키만큼을 빼보면서 확인한다.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> height;

void solution() {
	int sum = 0;
	for (int i = 0; i < 9; i++)
		sum += height[i];
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (height[i] + height[j]) == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) {}
					else printf("%d\n", height[k]);
				}
				return;
			}
		}
	}
}

int main() {
	int tmp;
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		height.push_back(tmp);
	}
	sort(height.begin(), height.end());
	solution();
	
	return 0;
}