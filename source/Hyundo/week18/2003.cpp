#include<iostream>
#define MAX 10001

using namespace std;

int N, M;
int arr[MAX];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int left = 0, right = 0, sum = 0, cnt = 0;
	while (right!=N+1){
		if (sum>=M) sum -= arr[left++];
		else sum += arr[right++];
		if (sum == M)	cnt++;
	}
	cout << cnt;
}