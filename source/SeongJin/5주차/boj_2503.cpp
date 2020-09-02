#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  string question;
  int N, strike, ball;
  vector<string> check, temp;
  cin >> N;
  string str;
  for (int i = 100; i < 1000; i++)
  {
    str = to_string(i);
    if (str[1] != '0' && str[2] != '0' && str[0] != str[1] && str[0] != str[2] && str[1] != str[2])
      check.push_back(to_string(i));
  }
  int checkStrike = 0, checkBall = 0;

  for (int i = 0; i < N; i++)
  {
    temp.clear();
    cin >> question >> strike >> ball;
    for (int j = 0; j < check.size(); j++)
    {
      checkStrike = 0, checkBall = 0;
      if (check[j][0] == question[0])
      {
        checkStrike++;
      }
      else if (check[j][0] == question[1] || check[j][0] == question[2])
      {
        checkBall++;
      }
      if (check[j][1] == question[1])
      {
        checkStrike++;
      }
      else if (check[j][1] == question[0] || check[j][1] == question[2])
      {
        checkBall++;
      }
      if (check[j][2] == question[2])
      {
        checkStrike++;
      }
      else if (check[j][2] == question[0] || check[j][2] == question[1])
      {
        checkBall++;
      }
      if (checkStrike == strike && checkBall == ball)
      {
        temp.push_back(check[j]);
      }
    }
    check.clear();
    check = temp;
  }

  cout << check.size() << endl;
  return 0;
}