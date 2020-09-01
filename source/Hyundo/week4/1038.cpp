#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

vector<long long> result;

void dfs(long long num, int digit) {
	if (digit > 9) return ;//최대수 9876543210 10자리 : digit 9
	result.push_back(num); //dfs 함수에 들어온 값은 감소하는 수, result에 push
	//0~10까지 진행 num다음 바로 자릿수보다 큰 경우에만 digit을 증가시켜 dfs진행
	for(int i = 0; i < 10; i++) {
		if (num % 10 > i) {
			dfs(num * 10 + i, digit+1);
		}
	}
	return ;
}
int main() {

	int input;
	scanf("%d", &input);
	for (int i = 0; i < 10; i++)
		dfs(i,0);
	sort(result.begin(), result.end());
	cout << result[input] << endl;
	
}