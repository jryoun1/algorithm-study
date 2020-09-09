

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> height;

void solution() {
	int sum=0;
	for (int i = 0; i < 9; i++)
		sum += height[i];
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++){
			if (sum - (height[i] + height[j]) == 100) {
				height.erase(height.begin()+i);
				height.erase(height.begin()+j-1); //i가 이미 erase 된 상태이므로 (j-1) 번째 값을 삭제한다.
				return ;
			}
		}
	}
}

int main() {
	int tmp;
	for (int i = 0; i < 9; i++) {
		cin>>tmp;
		height.push_back(tmp);
	}
	solution();
	sort(height.begin(), height.end());
	for (int i = 0; i < height.size(); i++)
		printf("%d\n", height[i]);
	return 0;
}