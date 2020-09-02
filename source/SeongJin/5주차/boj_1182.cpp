#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int answer = 0;
  vector<long long> subSum;
  int sum = 0;
  int N, S;
  cin >> N >> S;

  int input;
  vector<int> arr;
  for (int i = 0; i < N; i++)
  {
    cin >> input;
    arr.push_back(input);
  }
  int temp, last;
  for (int i = 0; i < N; i++)
  {
    temp = 0;
    subSum.push_back(arr[i]);
    for (int j = 0; j < subSum.size() - 1; j++)
    {
      subSum[j] += arr[i];
    }
    int size = subSum.size();
    for (int j = 0; j < size - 1; j++)
    {
      // 0
      // 0~1 1
      // 0~2 1~2 2 / {0,2} i:2
      // 0~3 1~3 2~3 {0,2,3} 3 / {0,1,3} {1,3} {0,3} i:3
      // 0~4 1~4 2~4 {0,2,3,4} 3~4 {0,1,3,4} {1,3,4} {0,3,4} 4 / {0,1,2,4} {1,2,4} {2,4} {0,2,4} {0,1,4} {1,4} {0,4}
      // 0~5 1~5 2~5 {0,2,3,4,5} 3~5 {0,1,3,4,5} {1,3,4,5} {0,3,4,5} 4~5 {0,1,2,4,5} {1,2,4,5} {2,4,5} {0,2,4,5} 5 /
      if (j != last - 1)
      {
        subSum.push_back(subSum[j] - arr[i - 1]);
        temp++;
      }
    }
    last = subSum.size() - temp;
    for (int j = 0; j < subSum.size(); j++)
    {
      if (subSum[j] == S)
        answer++;
    }
  }
  cout << answer << endl;
}