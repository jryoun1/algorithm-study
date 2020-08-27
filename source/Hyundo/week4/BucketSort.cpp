#include<iostream>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 10

float A[MAX] = { 0.86,0.32,0.27,0.12,0.49,0.21,0.62,0.89,0.71,0.87 };
vector<float> B[MAX];

void Print()
{
	cout << endl;
	for (int i = 0; i < MAX; i++){
		printf("%.2f ", A[i]);
	}
	cout << endl;
}

bool desc(float a, float b){
	return a > b;
}

void BucketSort()
{
	for (int i = 0; i < MAX; i++)
		B[(int)(A[i] * MAX)].push_back(A[i]);
	for (int i = 0; i < MAX; i++)
		sort(B[i].begin(), B[i].end(),desc);
	
	int Idx = 0;

	for (int j = 0; j < MAX; j++) {
		while (B[j].empty() == 0) {
			A[Idx] = B[j].back();
			B[j].pop_back();
			Idx++;
		}
	}
}


int main(void)
{
	cout << "[ 정렬 전 ] " << endl;
	Print();
	BucketSort();
	cout << endl;
	cout << "[ 정렬 후 ] " << endl;
	Print();

	return 0;
}

