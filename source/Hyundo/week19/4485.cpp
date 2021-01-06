#include<iostream>
#include<queue>

using namespace std;

int cave[126][126];
int dist[126][126];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void sol(int N,int TC)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			cin >> cave[i][j];
			dist[i][j] = 999999999;
		}
	}

	priority_queue<pair<int, pair<int, int>>> PQ;
	//PQ = (cost (x,y)) 
	PQ.push(make_pair(cave[0][0], make_pair(0, 0)));
	dist[0][0] = cave[0][0];

	while (PQ.empty() == 0)
	{
		int Cost = PQ.top().first;
		int x = PQ.top().second.first;
		int y = PQ.top().second.second;
		PQ.pop();
		//아래 조건에서 cost가 더 적은 노드가 발견되지 않을경우
		//pop을 계속 진행하게 되며
		//PQ에 더이상 값이 없을 경우 반복문 종료
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N) //이동 범위 제한
			{
				int nCost = Cost + cave[nx][ny];
				//현재위치로부터 상하좌우 이동 시에 cost가 더 적은 노드가 발견되지 않을 경우
				//push가 더이상 진행되지 않음
				if (dist[nx][ny] > nCost)
				{
					//cost가 더 적은 노드가 발견될 경우 더 적은 cost로 값을 초기화
					dist[nx][ny] = nCost;
					PQ.push(make_pair(dist[nx][ny], make_pair(nx, ny)));
					
				}
			}
		}
	}

	cout << "Problem " << TC << ": " << dist[N-1][N-1] << endl;
}


int main()
{
	int tmpN = 0;
	int i = 0;
	while (1)
	{
		i++;
		cin >> tmpN;
		if (tmpN == 0)
			break;
		else
			sol(tmpN,i);
	}



	return 0;
}