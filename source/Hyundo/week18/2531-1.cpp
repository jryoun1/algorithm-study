#include<iostream>
using namespace std;

int N, d, k, c;
int arr[30003010], kind[3010];

int main(void)
{
	int cnt, max;

	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	//쿠폰 초밥에 대하여 먼저 표시
	kind[c] = 1; cnt = 1;

	//k개만큼 먼저 저장
	for (int i = 0; i < k; i++) {
		//중복되지 않는 종류인 경우 count증가
		if (kind[arr[i]] == 0) cnt++;
		//포함된 종류에 대해 갯수 추가
		kind[arr[i]]++;
		//확인한 것은 배열의 뒤에 저장
		arr[N + i] = arr[i];
	}

	for (int i = 0; i < N; i++) {
		if (cnt > max)
			max = cnt;

		//첫번째 선택에 대한 갯수 감소
		kind[arr[i]]--;
		
		//제거하였을 때 현재 종류가 더이상 포함되지 않는 경우 가짓수 제거
		if (kind[arr[i]] == 0) cnt--;

		//이후 선택한 초밥이 선택된 적이 없는 경우 가짓수 추가
		if (kind[arr[i + k]] == 0) cnt++;
		//추가적인 선택에 대한 갯수 증가
		kind[arr[i + k]]++;
	}


	cout << max;
}