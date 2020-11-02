#include<iostream>
#include<cstring>

#define endl "\n"
#define MAX 16
#define INF 987654321
using namespace std;

int N, Answer_Bit;
int MAP[MAX][MAX];
int Cost[MAX][1 << MAX];

int Min(int A, int B) { if (A < B) return A; return B; }

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}
	Answer_Bit = (1 << N) - 1;
	//모든 도시를 방문한 상태
}

int DFS(int Cur_Node, int Cur_Bit)
{
	//모든 도시를 방문한 경우
	if (Cur_Bit == Answer_Bit)
	{
		//현재 노드로 돌아올 수 없는 경우 제외
		if (MAP[Cur_Node][0] == 0) return INF;
		else return MAP[Cur_Node][0];
	}

	//이미 방문한 적이 있는지 체크
	if (Cost[Cur_Node][Cur_Bit] != -1) return Cost[Cur_Node][Cur_Bit];
	Cost[Cur_Node][Cur_Bit] = INF;

	for (int i = 0; i < N; i++)
	{
		//이동할 수 없는 경우의 수는 넘김
		if (MAP[Cur_Node][i] == 0) continue;
		//동일한 방문기록을 가지고 있다면 넘김
		if ((Cur_Bit & (1 << i)) == (1 << i)) continue;
		//1>>i (i= 1~N)  을 통해 위에서 제외한 경우의 수로 이동하여 최솟값을 체크
		Cost[Cur_Node][Cur_Bit] = Min(Cost[Cur_Node][Cur_Bit], MAP[Cur_Node][i] + DFS(i, Cur_Bit | 1 << i));
	}

	return Cost[Cur_Node][Cur_Bit];
}

void Solution()
{
	memset(Cost, -1, sizeof(Cost));
	cout << DFS(0, 1) << endl;
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