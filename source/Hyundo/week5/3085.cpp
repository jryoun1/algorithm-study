//백준 3085번
//for(for)문으로 한개씩 전부 좌우로 바꿔본 후에 체크
//for(for)문으로 한개씩 전부 상하로 바꿔본 후에 체크
//체크 시 가로로 가장 긴 것 한번 세로로 가장 긴 것 한번 체크
//모두 다 종합하여 가장 긴 것을 답으로 채택
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 50
int N;
string board[MAX];

//출력할 답을 저장
int answer = 1;

void solution() {
	//가로로 가장 긴 것 체크
	for (int i = 0; i < N; i++)
	{
		int sum = 1;
		for (int j = 1; j < N; j++){
			if (board[i][j-1] == board[i][j])
				sum++;
			else {
				if(answer < sum)
					answer = sum;
				sum = 1;
			}
		}
		//j가 N까지 확인하였을 때 하나가 추가된 경우 
		//else문으로 들어가지 못하므로 이곳에서 체크
		if (answer < sum)
			answer = sum;

	}
	//세로로 가장 긴 것 체크
	for (int i = 0; i < N; i++)
	{
		int sum = 1;
		for (int j = 0; j < N - 1; j++)
		{
			if (board[j][i] == board[j+1][i])
				sum++;
			else {
				if (answer < sum)
					answer = sum;
				sum = 1;
			}
		}
		//j가 N까지 확인하였을 때 하나가 추가된 경우 
		//else문으로 들어가지 못하므로 이곳에서 체크
		if (answer < sum)
			answer = sum;
	}
}


int main()
{
	//input
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> board[i];
	
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			//좌우로 하나씩 바꿔가면서 체크
			swap(board[i][j], board[i][j + 1]);
			solution();
			swap(board[i][j], board[i][j + 1]);
			//상하로 하나씩 바꿔가면서 체크
			swap(board[j][i], board[j+1][i]);
			solution();
			swap(board[j][i], board[j + 1][i]);
		}
	}

	cout << answer << endl;
	return 0;
}