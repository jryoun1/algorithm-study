#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> candy;

int N;
int answer = 0;

int startx, starty;
void findRightCandy(int i, int j, int count, bool flag, char last)
{
  if (j < N - 1 && last == candy[i][j + 1])
  {
    findRightCandy(i, j + 1, count + 1, flag, last);
  }
  else if (j < N - 1 && flag == false)
  {
    if (i > 0 && last == candy[i - 1][j + 1])
    {
      flag = true;
      findRightCandy(i, j + 1, count + 1, flag, last);
    }
    else if (i < N - 1 && last == candy[i + 1][j + 1])
    {
      flag = true;
      findRightCandy(i, j + 1, count + 1, flag, last);
    }
  }
  if (j < N - 2 && last == candy[i][j + 2] && flag == false)
  {
    if (answer < count + 1)
    {
      answer = count + 1;
      return;
    }
  }
  if (answer < count)
  {
    answer = count;
  }
}

void findDownCandy(int i, int j, int count, bool flag, char last)
{
  if (i < N - 1 && last == candy[i + 1][j])
  {
    findDownCandy(i + 1, j, count + 1, flag, last);
  }
  else if (i < N - 1 && flag == false)
  {
    if (j > 0 && last == candy[i + 1][j - 1])
    {
      flag = true;
      findDownCandy(i + 1, j, count + 1, flag, last);
    }
    else if (j < N - 1 && last == candy[i + 1][j + 1])
    {
      flag = true;
      findDownCandy(i + 1, j, count + 1, flag, last);
    }
  }
  if (i < N - 2 && last == candy[i + 2][j] && flag == false)
  {
    if (answer < count + 1)
    {
      answer = count + 1;
      return;
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

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> input;
    candy.push_back(input);
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      startx = j;
      starty = i;
      if (j == 0)
      {
        findRightCandy(i, j, 1, false, candy[i][j]);
      }
      else if (j > 0 && candy[i][j] != candy[i][j - 1])
      {
        if ((i > 0 && j < N - 1 && candy[i - 1][j] == candy[i][j + 1]) || j > 0 && j < N - 1 && candy[i][j - 1] == candy[i][j + 1])
          findRightCandy(i, j, 1, true, candy[i][j + 1]);
        else if (i < N - 1 && j < N - 1 && candy[i + 1][j] == candy[i][j + 1])
          findRightCandy(i, j, 1, true, candy[i][j + 1]);
        findRightCandy(i, j, 1, false, candy[i][j]);
      }

      if (i == 0)
      {
        findDownCandy(i, j, 1, false, candy[i][j]);
      }
      else if (i > 0 && candy[i][j] != candy[i - 1][j])
      {
        if ((j > 0 && i < N - 1 && candy[i][j - 1] == candy[i + 1][j]) || i > 0 && i < N - 1 && candy[i - 1][j] == candy[i + 1][j])
          findRightCandy(i, j, 1, true, candy[i + 1][j]);
        else if (j < N - 1 && i < N - 1 && candy[i][j + 1] == candy[i + 1][j])
          findRightCandy(i, j, 1, true, candy[i + 1][j]);

        findDownCandy(i, j, 1, false, candy[i][j]);
      }
    }
  }

  cout << answer << endl;
}