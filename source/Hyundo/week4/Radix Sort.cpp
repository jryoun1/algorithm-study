#include<iostream>
#include<cstdlib>
#include<ctime>
#include<queue>

#define MAX 100
using namespace std;

queue<int> Q[10];
int maxValue = 911;
int arr[7] = { 567,654,124,457,830,911,555 };

void Print()
{
	cout <<endl;
	int Cnt = 0;
	for (int i = 0; i < 7; i++)
	{
		printf("%6d ", arr[i]);
		Cnt++;
		if (Cnt == 7)
		{
			Cnt = 0;
			cout << endl;
		}
	}
	cout <<endl;
	cout << endl;
}



void RadixSort()
{
	int radix = 1;
	while (1){
		if (radix >= maxValue) break;
		radix = radix * 10;
	}
	for (int i = 1; i < radix; i = i * 10){
		for (int j = 0; j < sizeof(arr) / sizeof(arr[0]); j++){
			int K;
			if (arr[j] < i) K = 0;
			else K = (arr[j] / i) % 10;
			Q[K].push(arr[j]);
		}
		int Idx = 0;
		for (int j = 0; j < 10; j++){
			while (Q[j].empty() == 0){
				arr[Idx] = Q[j].front();
				Q[j].pop();
				Idx++;
			}
		}
		cout <<"[ "<<i<< "의 자리 ] " << endl;
		Print();
	}
}

int main(void)
{


	cout << "[ 정렬 전 ] " << endl;
	Print();
	RadixSort();
	cout << "[ 정렬 후 ] " << endl;
	Print();

	return 0;
}

