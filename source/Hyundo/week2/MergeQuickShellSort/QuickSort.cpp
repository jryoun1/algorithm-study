#include <iostream>
#include <algorithm>

int Partition(int A[], int Left, int Right);
void QuickSort(int A[], int Left, int Right);

using namespace std;

int main()
{
	int array[10] = { 30,20,40,35,5,10,45,50,25,15 };

	//퀵정렬 수행 ( left = 0(배열의 시작) , right = 9(배열의 끝)
	QuickSort(array, 0, 9);

	//정렬 결과 출력
	for (int j = 0; j < 10; j++)
	{
		cout << array[j] << endl;
	}
	return 0;
}


int Partition(int A[], int left, int right)
{
	int partElem, value, temp;
	partElem = left;
	value = A[partElem];

	//left와 right가 교차할 때까지 반복
	do {
		//A[left]가 분할원소값보다 작으면 left를 반복증가시킴
		do { } while (A[++left] < value);
		//A[right]가 분할원소값보다 크면 right를 반복감소시킴
		do { } while (A[--right] > value);
		//두 값을 교환
		if (left < right) swap(A[left], A[right]);
		else break;
	} while (left<right);

	//분할원소의 자리를 찾아줌
	A[partElem] = A[right];
	A[right] = value;

	return right;
}

void QuickSort(int A[], int left, int right)
{
	if (right > left)
	{
		int middle = Partition(A, left, right + 1);
		//분할원소를 기준으로 왼쪽에서 재정렬
		QuickSort(A, left, middle - 1);
		//분할원소를 기준으로 오른쪽에서 재정렬
		QuickSort(A, middle + 1, right);
	}
}
