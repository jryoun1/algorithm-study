#include<iostream>
#include<string>
#include<queue>

#define endl "\n"
#define MAX 100
using namespace std;

int N, M;
int MAP[MAX][MAX];
int Dist[MAX][MAX];
bool Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void Print()
{
	cout << "#############################" << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Dist[i][j] << " ";
		}
		cout << endl;
	}
	cout << "#############################" << endl;

}

void BFS(int a, int b)
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	Dist[a][b] = 0; //처음 (0,0)의 방문횟수를 0으로 설정

	while (Q.empty() == 0)
	{
		//Print();
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();//마지막에 저장한 값을 pop해주어 더이상 아래 if문의 조건이 해당하지 않아 Q에 값이 들어오지 않을 경우 반복문 종료

		for (int i = 0; i < 4; i++)
		{  //우 {+0,+1} 좌 {+0,-1} 하 {+1,+0} 상 {-1,+0} 순으로 체크
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {


				if (MAP[nx][ny] == 1) //탐색하는 곳이 문일 때
				{
					if (Dist[nx][ny] > Dist[x][y] + 1)
						//(이전에 현재 탐색하는 곳(nx,ny)까지 이동하는데 부순 문의 갯수가 현재 탐색에서 부순문의 갯수보다 많을 경우)
						//이전에 탐색한 값이 현재의 값보다 클 경우
						//or 방문한 적이 없는 경우(초기 저장값)
					{
						Dist[nx][ny] = Dist[x][y] + 1; //이번의 탐색에서 얻은 값에 1을 더해 저장하여 더 적은 양의 문을 부순 경우를 저장해준다.
						Q.push(make_pair(nx, ny)); //다음에 진행할 위치를 Q에 push 한다.
					}
				}
				else if (MAP[nx][ny] == 0) //탐색하는 곳이 문이 아닐 때
				{
					if (Dist[nx][ny] > Dist[x][y]) //이전에 탐색한 값이 현재의 값보다 클 경우 or 방문한 적이 없는 경우(초기 저장값)
					{
						Dist[nx][ny] = Dist[x][y]; //방문한 곳에 현재의 값을 넣어주고
						Q.push(make_pair(nx, ny)); //다음에 진행할 위치를 Q에 push 한다.
					}
				}
			}
		}
	}
}

int main(void)
{

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		string Inp;
		cin >> Inp;
		for (int j = 0; j < Inp.length(); j++)
		{
			MAP[i][j] = Inp[j] - '0';
			Dist[i][j] = 9998; //100,100으로 이루어진 미로에 최대 있을 수 있는 문의 개수
		}
	}
	BFS(0, 0);
	cout << Dist[M - 1][N - 1] << endl;
	//BFS 탐색이 모두 끝나고 부순무의 갯수를 기록한 Dist의 m.n에 저장된 값을 출력

	return 0;
}