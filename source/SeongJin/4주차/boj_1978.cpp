#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 상 하 좌 우 순서로 이동
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int R, C, answer = -9999;
bool check[27] = {
    false,
};
vector<string> board;

void calMax(int x, int y, int count)
{
  for (int i = 0; i < 4; i++)
  {
    if (x + dx[i] >= 0 && x + dx[i] < C && y + dy[i] >= 0 && y + dy[i] < R)
    {
      if (check[board[y + dy[i]][x + dx[i]] - 'A'] == false)
      {
        check[board[y + dy[i]][x + dx[i]] - 'A'] = true;
        calMax(x + dx[i], y + dy[i], count + 1);
        check[board[y + dy[i]][x + dx[i]] - 'A'] = false;
      }
    }
  }
  if (answer < count)
  {
    answer = count;
  }
}

int main()
{
  string input;

  cin >> R >> C;
  for (int i = 0; i < R; i++)
  {
    cin >> input;
    board.push_back(input);
  }

  check[board[0][0] - 'A'] = true;

  calMax(0, 0, 1);

  cout << answer << endl;
  return 0;
}