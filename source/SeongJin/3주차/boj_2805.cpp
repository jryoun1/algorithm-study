#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
  int N, M;
  int input, index = 0;
  long long cut_tree = 0, cut_now;
  vector<int> trees;
  long long answer;

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    cin >> input;
    trees.push_back(input);
  }

  sort(trees.begin(), trees.end(), greater<int>());

  for (int i = 0; i < N - 1; i++)
  {
    cut_now = (trees[i] - trees[i + 1]) * (i + 1);
    cut_tree += cut_now;
    if (cut_tree >= M)
    {
      if (cut_tree > M)
        cut_tree -= cut_now;
      index = i;
      break;
    }
    index++;
  }

  if (cut_tree == M)
  {
    answer = trees[index + 1];
  }
  else
  {
    answer = trees[index] - ceil((double)(M - cut_tree) / (index + 1));
  }

  cout << answer << endl;
  return 0;
}