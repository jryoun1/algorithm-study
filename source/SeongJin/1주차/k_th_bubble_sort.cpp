#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> bubble_sort(vector<int> array, int n)
{
  int i, j;
  for (int i = 0; i < n - 1; i++) // n-1번을 반복
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (array[j] > array[j + 1]) // 인접한 값끼리 비교
      {
        swap(array[j], array[j + 1]); // 알고리즘 헤더의 swap 사용
      }
    }
  }
  return array;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
  vector<int> answer;

  for (int testCase = 0; testCase < commands.size(); testCase++)
  {
    vector<int> newArr;
    int index = commands[testCase][2];
    for (int j = commands[testCase][0] - 1; j < commands[testCase][1]; j++)
    {
      newArr.push_back(array[j]);
    }
    newArr = bubble_sort(newArr, newArr.size());
    answer.push_back(newArr[index - 1]);
  }
  return answer;
}