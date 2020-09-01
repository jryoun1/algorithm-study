#include<iostream>

using namespace std;

void CountSort(int a[], int n, int b[], int k);

int main()
{
	int arr[8] = { 5,3,4,1,5,4,1,4 };
	int ary[8] = { 0 };
	printf("정렬 전\n");
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}

	CountSort(arr, 8, ary, 5);
	printf("\n정렬 후\n");

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", ary[i]);
	}
	return 0;
}

void CountSort(int a[], int n, int b[], int k)
{
	int i, j;
	int* N = new int[k];

	//N 배열 초기화 (N[] = 범위내의 각 숫자가 나타나는 횟수를 위한 배열)
	for (i = 0; i < k; i++) N[i] = 0;  //O(k)

	//각 키의 개수 저장
	for (j = 0; j < n; j++)  N[a[j]-1] += 1;  //O(n)
	//각 키의 누적 합 저장
	for (i = 1; i < k; i++) N[i] += N[i - 1];  //O(k)
	//정렬 결과를 배열 B에 저장
	//뒤에서부터 정렬하여 안정성을 보장
	for (j = n-1; j >= 0; j--) { 
		b[N[a[j]-1]-1] = a[j];
		N[a[j]-1] -= 1;
	} // O(n)
	//-> O(k)+O(n)=O(max(k,n)
}