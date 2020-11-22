#include<iostream>
#include<algorithm>

#define MAX 100001

using namespace std;

int arr[MAX];
int sum[MAX][2];
//sum[i] = arr[1]~arr[i]까지의 연속합

int main() {
	ios_base::sync_with_stdio(false);
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int result = arr[0];

	for (int i = 0; i < N; i++) {
		sum[i][0] = arr[i];
		sum[i][1] = arr[i];
		if (i != 0) {
			//1.현재 인덱스의 값을 삭제하지 않은 경우
			//(i-1번째까지 연속합 + arr[i]) VS arr[i]
			sum[i][0] = max(sum[i - 1][0] + arr[i], arr[i]);
			//2.현재 인덱스의 값을 삭제했을 경우
			//(i-1번째까지 연속합) VS (i-1)번째에서 삭제를 사용했을 때 연속합 +a[i])
			sum[i][1] = max(sum[i - 1][0], sum[i - 1][1] + arr[i]);

			//현재까지 최대값 result VS 1번(삭제 x) VS 2번(삭제 o)
			result = max(result, max(sum[i][0], sum[i][1]));
		}
	}
	cout << result << '\n';
	return 0;
}