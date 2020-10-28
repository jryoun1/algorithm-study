#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

long N;
long K;
long res;

long Search(long left, long right) {
	
	int cnt = 0;
	long mid = (left + right) / 2;
	//기저
	if (left > right)
		return res;
	//구하려는 값이 res일 때
	//res는 1행부터 N행까지 i번째 행에서 min(res/i,N)을 더한 값
	for (int i = 1; i <= N; i++) {
		cnt += min(mid / i, N);
	}

	//구한 값이 K보다 작은 경우 res를 저 작은 범위에서 찾음
	if (K <= cnt) {
		res = mid;
		return Search(left, mid - 1);
	}
	//구한 값이 K보다 큰 경우  res를 더 큰 범위에서 찾음
	else {
		return Search(mid + 1, right);
	}
}


int main()
{
	cin >> N >> K;
	int tmp;
	long left = 1;
	long right = K;

	cout << Search(left, right);





	return 0;
}