#include <iostream>
#include <vector>

using namespace std;


vector<int> arr;
int S = 0;
int N = 0;
int answer=0;

void DFS(int sum, int start, int cnt)
{
	int tmpStart = start + 1;
	if (start >= N )
	{
		return;
	}
	else if (sum+arr[start] == S && cnt>=1){
		answer++;
	}
	
	int tmpSum=arr[start]+sum;


	DFS(tmpSum, tmpStart, cnt+1);
	DFS(sum, tmpStart, cnt);
}


int main()
{
	int tmp = 0;
	int sum = 0;

	//input (N, S, array[N])
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	DFS(0, 0, 1);

	printf("%d", answer);

	return 0;
}