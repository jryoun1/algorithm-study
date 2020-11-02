#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 200000

using namespace std;

int N, H;
int A[MAX];//석순 바닥 시작
int B[MAX];//종유석 천장 시작
vector<int> list;

int main()
{
	cin >> N >> H;
	//석순과 종유석 입력
	for (int i = 0; i < N / 2; i++) {
		cin >> A[i] >> B[i];
	}

	int mid = H / 2;
	int min = 0;

	//정렬
	sort(A, A + N / 2);
	sort(B, B + N / 2);

	//각각의 층에서 장애물 개수 측정
	for (int i = 1; i < H+1; i++) {
		int l = 0;
		int r = N / 2 - 1;
		int bottomCnt = 0;
		while (l <= r)
		{
			//정렬된 종유석으로부터 이분 탐색을 통해 부셔야하는 장애물 중 가장 작은 것을 찾음
			//찾은 위치로부터 현재 층에서 부셔야 하는 장애물의 개수를 구함
			mid = (l + r) / 2;
			if (B[mid] >= i)
			{
				bottomCnt = N / 2 - mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		int topCnt = 0;
		
		l = 0;
		r = N / 2 - 1;
		while (l <= r)
		{
			//정렬된 석순으로부터 이분 탐색을 통해 부셔야하는 장애물 중 가장 작은 것을 찾음
			//찾은 위치로부터 현재 층에서 부셔야 하는 장애물의 개수를 구함
			mid = (l + r) / 2;
			if (H-A[mid] < i)
			{
				topCnt = N / 2 - mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		//석순과 종유석의 개수를 합쳐 현재 층에서의 부셔야 하는 장애물 개수 저장
		list.push_back(topCnt + bottomCnt);
	}
	//리스트 내에서 최솟값을 결과값으로 저장
	int res = *min_element(list.begin(), list.end());
	int num = 0;
	//리스트 내에 최솟값과 동일한 값을 찾음
	for (int i = 0; i < list.size(); i++){
		if (list[i] == res)
			num++;
	}
	// 두 값 출력
	cout << res<<" "<<num;

	return 0;
}