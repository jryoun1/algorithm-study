#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;

// 우 하 좌 상 순서로 이동
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, answer = 9999;
bool check[105][105] = {
    false,
};
vector<string> board;

// priority_queue<자료형, Container, 비교함수> 변수명
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int bfs()
{
  while (!pq.empty())
  {
    int x = pq.top().second.second;
    int y = pq.top().second.first;
    int count = pq.top().first;

    pq.pop();
    if (x == N - 1 && y == M - 1)
      return count;
    for (int i = 0; i < 4; i++)
    {
      if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M)
      {
        if (check[y + dy[i]][x + dx[i]] == false)
        {
          pq.push({count + board[y + dy[i]][x + dx[i]] - '0', {y + dy[i], x + dx[i]}});
          check[y + dy[i]][x + dx[i]] = true;
        }
      }
    }
  }
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string input;

  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    cin >> input;
    board.push_back(input);
  }

  check[0][0] = true;
  pq.push(make_pair(0, make_pair(0, 0)));

  cout << bfs() << endl;
  return 0;
}