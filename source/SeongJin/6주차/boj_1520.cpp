/*#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// M: 세로의 크기
// N: 가로의 크기
int M, N;

// 지도 정보 저장
vector<vector<int>> map;

int visited[501][501] = {
    0,
};

int answer = 0;

int findMap(int x, int y)
{
  if (x == N - 1 && y == M - 1)
  {
    return 1;
  }
  if (visited[y][x] != -1)
    return visited[y][x];
  visited[y][x] = 0;
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < N && ny >= 0 && ny < M)
    {
      if (map[y][x] > map[ny][nx])
      {
        if (visited[ny][nx] > 0)
        {
          visited[y][x] += visited[ny][nx];
        }
        else
          visited[y][x] += findMap(nx, ny);
      }
    }
  }
  return visited[y][x];
}

int main()
{
  int input;
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> M >> N;

  for (int i = 0; i < M; i++)
  {
    vector<int> temp;
    for (int j = 0; j < N; j++)
    {
      cin >> input;
      temp.push_back(input);
    }
    map.push_back(temp);
  }

  fill(visited[0], visited[501], -1);
  findMap(0, 0);

  cout << visited[0][0] << endl;
  return 0;
}*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// M: 세로의 크기
// N: 가로의 크기
int M, N;

// 지도 정보 저장
vector<vector<int>> map;

int visited[501][501] = {
    0,
};

int answer = 0;

int findMap(int x, int y)
{
  if (x == N - 1 && y == M - 1)
  {
    return 1;
  }
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < N && ny >= 0 && ny < M)
    {
      if (visited[ny][nx] != -1)
      {
        if (map[y][x] > map[ny][nx])
        {
          if (visited[ny][nx] > 0)
          {
            visited[y][x] += visited[ny][nx];
          }
          else
            visited[y][x] += findMap(nx, ny);
        }
      }
    }
  }
  if (visited[y][x] == 0)
  {
    visited[y][x] = -1;
    return 0;
  }
  return visited[y][x];
}

int main()
{
  int input;
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> M >> N;

  for (int i = 0; i < M; i++)
  {
    vector<int> temp;
    for (int j = 0; j < N; j++)
    {
      cin >> input;
      temp.push_back(input);
    }
    map.push_back(temp);
  }

  findMap(0, 0);

  if (visited[0][0] == -1)
    cout << 0 << endl;
  else
    cout << visited[0][0] << endl;
  return 0;
}