#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

int N;
int M;
int lesson[MAX];

int main()
{
	cin >> N >> M;
	int tmp;
	int left = 0;
	int right = 0;
	for (int i = 0; i < N; i++) {
		cin >>lesson[i];
		right += lesson[i]; 
		left = left < lesson[i] ? lesson[i] : left;
	}

	while (left <= right) 
	{
		//임의의 블루레이 크기 mid
		//반복문이 돌면서 left값과 right값이 재설정 되면서 mid값도 바뀜
		int mid = (left + right) / 2;

		int sum = 0; 
		int cnt = 0;
		for (int i = 0; i < N; i++){
			if (sum + lesson[i] > mid){
				sum = 0; 
				cnt++; 
			} 
		sum += lesson[i]; 
		} 
		//마지막에 남은 것들의 합이 mid를 넘지 못한 경우 cnt를 더해 블루레이 갯수를 채움
		if (sum != 0) 
			cnt++; 

		cout <<" left = "<< left << " right = " << right<<" ";
		//구한 갯수가 m보다 작거나 같으면 최대값 감소
		if (cnt <= M) 
			right = mid - 1;
		//구한 갯수가 m보다 크면 최솟값 증가
		else 
			left = mid + 1; 

		cout <<" mid = "<< mid <<" cnt = "<<cnt<< endl;
	}

	cout << left << endl;

	return 0;
}