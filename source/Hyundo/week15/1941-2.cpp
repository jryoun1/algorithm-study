#include<iostream>
#include<cstring>
#include<string>
#include<queue>

#define endl "\n"
using namespace std;

int MAP[5][5], Answer;
bool Select[25];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1 ,0, 0 };

void Input()
{
	for (int i = 0; i < 5; i++)
	{
		string Inp;
		cin >> Inp;
		for (int j = 0; j < Inp.length(); j++)
		{
			if (Inp[j] == 'Y') MAP[i][j] = 1;
			else if (Inp[j] == 'S') MAP[i][j] = 2;
		}
	}
}

bool MoreThanFour()
{
	int Cnt = 0;
	for (int i = 0; i < 25; i++)
	{
		if (Select[i] == true)
		{
			//idx를 통하여 x좌표와 y좌표를 계산
			int x = i / 5;
			int y = i % 5;
			//계산한 좌표에 해당하는 곳이 2(S)인지 확인
			if (MAP[x][y] == 2) Cnt++;
		}
	}
	//총 S의 개수에 따라 출력
	if (Cnt >= 4) return true;
	else return false;
}

bool Adjacency()
{
	queue <pair<int, int>> Q; ////가장 먼저 나오는 학생의 좌표를 Queue에 저장(시작점)
	bool Check_Select[5][5]; //선택한 학생들을 저장하는 배열
	bool Queue_Select[5][5]; 
	bool Check_Answer = false;

	memset(Queue_Select, false, sizeof(Queue_Select));
	memset(Check_Select, false, sizeof(Check_Select));

	int Tmp = 0;
	for (int i = 0; i < 25; i++)
	{
		//현재 DFS를 통해 선택되어 있는 학생들
		if (Select[i] == true)
		{
			//해당 좌표를 계산
			int x = i / 5;
			int y = i % 5;
			//현재 선택되어 있는 학생들을 2차원 배열에 표시
			Check_Select[x][y] = true;
			//첫 시작점을 지정하기 위해 tmp가 0, 즉 첫 시작일 경우에만 Q 에 저장
			if (Tmp == 0)
			{
				Q.push(make_pair(x, y));
				Queue_Select[x][y] = true;
				//Tmp를 증가시킴으로 인해 이후에는 이부분이 진행되지 않는다.
				Tmp++;
			}
		}
	}

	int Cnt = 1;
	//Q에 값이 있을 때까지만 반복함(BFS)
	while (Q.empty() == 0)
	{
		//x,y에 첫 시작점을 저장
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		//아래 for문에서 Q가 더이상 push되지 않는 경우는 인접해 있지 않기 때문에
		//Q가 더이상 push되지 않게 되고 while문의 조건에 해당하지 않아
		//g현재 반복문이 끝나게됌

		//인접해 있는 학생이 7명이 되었을 경우에 true를 return하도록 check_answer에 저장
		if (Cnt == 7)
		{
			Check_Answer = true;
			break;
		}

		//좌우상하 이동을 진행
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
			{
				//DFS를 통해 선택한 학생 7명에 해당하고 현재 BFS를 통해 탐색한 적이 없는 경우 조건에 해당함
				if (Check_Select[nx][ny] == true && Queue_Select[nx][ny] == false)
				{
					//방문 표시 진행
					Queue_Select[nx][ny] = true;
					Q.push(make_pair(nx, ny));
					//BFS를 통해 방문이 가능한 경우에는 인접해 있는 것이므로 cnt를 올려준다.
					Cnt++;
				}
			}
		}
	}

	if (Check_Answer == true) return true;
	return false;
}

void DFS(int Idx, int Cnt)
{
	//한 점을 기준으로 bfs나 dfs로는 십자가 모양을 찾을 수 없기 때문에
	//25명의 학생 중에서 7명을 뽑고 이곳에 S가 4 이상 포함되었는지와 모두 연결되어있는지를 판단하여 정답을 구함
	//7명이 모두 모인 경우
	if (Cnt == 7)
	{
		//이다솜파가 4명이상인 경우
		if (MoreThanFour() == true)
		{
			//현재 상태가 모두 인접하여 있는 경우 경우의 수 추가
			if (Adjacency() == true) Answer++;
		}
		return;
	}

	for (int i = Idx; i < 25; i++)
	{	
		//이미 이동한 적이 있는 경우 continue;
		if (Select[i] == true) continue;
		//이동 표시
		Select[i] = true;
		//다음 위치로 이동
		DFS(i, Cnt + 1);
		//backtraking
		Select[i] = false;
	}
}

void Solution()
{
	DFS(0, 0);
	cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}
