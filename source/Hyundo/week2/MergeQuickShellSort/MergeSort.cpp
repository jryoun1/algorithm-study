#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Merge(int array[], int low, int mid, int high)
{
	int B[10] = {0};
	int i, leftPtr, rightPtr, bufPtr;
	leftPtr = low;
	rightPtr = mid + 1;
	bufPtr = low;

	//분할 정렬된 리스트의 합병
	while (leftPtr <= mid && rightPtr <= high)
		if (array[leftPtr] < array[rightPtr])
			B[bufPtr++] = array[leftPtr++];
		else
			B[bufPtr++] = array[rightPtr++];

	//남은 값들 복사
	if (leftPtr > mid)
		for (i = rightPtr; i <= high; i++)
			B[bufPtr++] = array[i];
	else
		for (i = leftPtr; i <= mid; i++)
			B[bufPtr++] = array[i];

	//정렬된 임시 배열의 값을 원래 배열에 복사
	for (i = low; i <= high; i++)
		array[i] = B[i];
}

void MergeSort(int array[],int low, int high)
{
	int mid;
	if (low < high) {
		mid = (low + high) / 2; //중간 위치 계산하여 리스트 균등 분할
		MergeSort(array, low, mid); // 앞쪽 부분 리스트 정렬
		MergeSort(array, mid + 1, high); // 뒤쪽 부분 리스트 정렬
		Merge(array, low, mid, high); //정렬된 부분 배열 합병
	}
}


int main()
{
	int array[10] = { 30,20,40,35,5,10,45,50,25,15 };

	MergeSort(array,0,9);
	
	for (int j = 0; j < 10; j++)
	{
		cout << array[j] << endl;
	}
	return 0;
}

