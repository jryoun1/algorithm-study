#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

int main()
{
  int n, m, start_B = 0, start_W = 0;
  char check[2][2] = {{'B', 'W'}, {'W', 'B'}};
  int answer = INT_MAX;
  string input;
  vector<string> board;

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    board.push_back(input);
  }

  for (int i = 0; i <= n - 8; i++)
  {
    for (int j = 0; j <= m - 8; j++)
    {
      for (int k = 0; k < 8; k++)
      {
        for (int q = 0; q < 8; q++)
        {
          // W 시작
          if (board[i + k][j + q] == check[k % 2][q % 2])
            start_W++;

          // B 시작
          if (board[i + k][j + q] == check[(k + 1) % 2][q % 2])
            start_B++;
        }
      }
      int temp = start_W > start_B ? start_B : start_W;
      answer = answer > temp ? temp : answer;
      start_W = 0;
      start_B = 0;
    }
  }
  cout << answer << endl;
  return 0;
}