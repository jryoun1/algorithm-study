#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &first, const pair<int, int> &second)
{
  if (first.first == second.first)
    return first.second < second.second;
  else
    return (first.first > second.first);
}
int main()
{
  // N개의 입력 값
  // d: 과제 마감일
  // w: 과제의 점수
  int N, now = 1, d, w, answer = 0;
  vector<pair<int, int>> score;

  // 범위가 크지 않으므로 배열 선언(최대 1000*1000이므로 시간초과 X)
  int solve[1001] = {
      0,
  };
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> d >> w;
    score.push_back({w, d});
  }
  sort(score.begin(), score.end(), cmp);

  for (int i = 0; i < N; i++)
  {
    for (int j = score[i].second; j >= 1; j--)
    {
      if (solve[j] == 0)
      {
        solve[j] = score[i].first;
        break;
      }
    }
  }

  for (int i = 1; i <= 1000; i++)
  {
    answer += solve[i];
  }

  cout << answer << endl;
  return 0;
}