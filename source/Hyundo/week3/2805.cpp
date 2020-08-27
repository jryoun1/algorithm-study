

#include <iostream>
#include <algorithm>

using namespace std;


int solution(int* arr, int n, int m)
{
	int high = 0;
	int sum = 0;
	int k = n - 2; //배열의 다음 값과의 차이동안 sum에 더해줄량을 결정해 주기 위해 필요
	sort(arr, arr + n);							  //배열 정렬
	for (high = arr[n - 1] - 1; high >= 0; high--) { //정렬된 배열 중 가장 큰 값을 기준으로
		while (high + 1 == arr[k]) k--;			  //그 다음 배열의 값과의 차이동안
		sum += (n - k - 1);						  //sum에 예상 토목량을 계산하여
		if (sum >= m) break;					  //m과 비교하여 조건이 맞는 경우 
	}
	return high;								  //그 때의 high를 return
}


int main()
{
	int arr[4] = { 20,15,10,17 };
	printf("\n%d\n", solution(arr, 4, 7));
	return 0;
}