#include <iostream>

using namespace std;

int solution(int n, int m,int arr[][8])
{
	int sum1 = 0;
	int sum2 = 0;
	// 1=W / 0=B
	if (arr[0][0] == 0){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
					if (arr[i][j] != 0) sum1++;
				else
					if (arr[i][j] != 1) sum1++;
			}
		}
	}
	else{
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
					if (arr[i][j] != 1) sum2++;
				else
					if (arr[i][j] != 0)sum2++;
			}
		}
	}
	if (sum1 > sum2)
		return sum1;
	else
		return sum2;
}

int main()
{
	int arr[8][8] = { {0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,1,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0} };
	printf("%d",solution(8, 8, arr));
	return 0;
}