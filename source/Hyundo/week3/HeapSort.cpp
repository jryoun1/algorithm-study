#include<iostream>
#include<algorithm>

using namespace std;

void MakeHeap(int a[], int root, int lastNode);
void pirntHeap(int ary[], int n);

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void HeapSort(int ary[], int n){
	int i;
	//1차원 배열을 히프로 변환
	// n/2 -> n/2-1 ->...-> 1
	// 4,8 -> 3,8 -> 2,8 -> 1,8
	//배열 전체를 완전 이진 나무로 간주하고 이프 노드부터 뿌리노드까지 한 레벨씩 거슬러 올라가면서
	//아래 부분부터 히프 구조를 가지도록 함
	//n개의 노드를 갖는 완전 이진 노드는 n/2개의 잎 노드를 가짐
	printf("--------1차원 배열을 히프로 변환--------\n");
	for (i = n / 2; i > 0; i--) {
		MakeHeap(ary, i - 1, n - 1);
		pirntHeap(ary, 10);
	}
	printf("-----------남은 원소 히프 구성-----------\n");
	//히프에서 최대값을 제거하고
	//남은 원소들로 다시 히프 구성 (n-1)회 반복
	for (i = n-1 ; i > 0; i--) {
		swap(ary[0], ary[i]);
		MakeHeap(ary, 0, i - 1);
		pirntHeap(ary, 10);
	}
}

void MakeHeap(int a[], int root, int lastNode) {
	int parent, leftSon, rightSon, son, rootValue;
	parent = root;
	rootValue = a[root];//히프의 뿌리 
	leftSon = 2 * parent + 1;
	rightSon = leftSon + 1;
	while (leftSon <= lastNode) {
		if (rightSon <= lastNode && a[leftSon] < a[rightSon])
			son = rightSon;
		else
			son = leftSon;
		if (rootValue < a[son]) {
			a[parent] = a[son];
			parent = son;
			leftSon = parent * 2 + 1;
			rightSon = leftSon + 1;
		}
		else break;
	}
	a[parent] = rootValue;
}

int main() {

	int ary[10] = { 15,4,8,11,6,3,1,6,5,17 };
	printf("--------------정렬 전 배열--------------\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", ary[i]);
	}
	printf("\n");
	HeapSort(ary, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", ary[i]);
	}

	return 0;
}

void pirntHeap(int ary[],int n)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", ary[i]);
	}
	printf("\n\n");
}