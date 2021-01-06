#include<iostream>
#include<vector>
#define MAX 1000001

using namespace std;

int N, M;
int arrA[MAX], arrB[MAX];
vector<int> result;

int main() {
	std::ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N;i++)
		cin >> arrA[i];
	for (int i = 0; i < M; i++)
		cin >> arrB[i];

	int a=0, b=0;
	//첫번째 배열과 두번째 배열에 각각 포인트를 하나씩 두고 정렬
	while (true)
	{
		if (a>=N)
		{   //a가 이미 끝까지 도달한 경우 나머지는 B 배열로 채운다.
			for (int i = b; i < M; i++)
			{
				result.push_back(arrB[i]);
			}
			break;
		}
		else if (b>=M)
		{   //brk 이미 끝까지 도달한 경우 나머지는 A배열로 채운다.
			for (int i = a; i < N; i++)
			{
				result.push_back(arrA[i]);
			}
			break;
		}
		else if (arrA[a] <= arrB[b])
			result.push_back(arrA[a++]);
		else
			result.push_back(arrB[b++]);
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
}