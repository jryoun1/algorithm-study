#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> selection_sort(vector<int> array, int n)
{
  int i, j, temp, indexMin;
  for (int i = 0; i < n - 1; i++)
  {
    indexMin = i; // 최소값을 찾을 index
    for (int j = i + 1; j < n; j++)
    {
      if (array[indexMin] > array[j]) // 현재 값 이후의 값들과 비교하여 최소값의 위치를 찾음
      {
        indexMin = j;
      }
    }
    swap(array[indexMin], array[i]); // 현재 값과 최소 값 교환
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
    newArr = selection_sort(newArr, newArr.size());
    answer.push_back(newArr[index - 1]);
  }
  return answer;
}