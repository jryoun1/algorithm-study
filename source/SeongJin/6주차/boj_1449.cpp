#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  // N: 물이 새는 곳의 개수
  // L: 테이프의 길이

  int N, L, input, answer;
  vector<int> pipe;

  cin >> N >> L;

  for (int i = 0; i < N; i++)
  {
    cin >> input;
    pipe.push_back(input);
  }
  sort(pipe.begin(), pipe.end());

  double check = pipe[0] - 0.5 + L;
  answer = 1;
  for (int i = 1; i < N; i++)
  {
    if (pipe[i] > check)
    {
      if (pipe[i] + 0.5 > check)
      {
        answer++;
        check = pipe[i] - 0.5 + L;
      }
      else
      {
        answer++;
        check += L;
      }
    }
  }

  cout << answer << endl;
  return 0;
}