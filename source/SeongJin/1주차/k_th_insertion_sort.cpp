#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> insertion_sort(vector<int> array, int n)
{
  int i, j, temp;
  for (i = 1; i < n; i++)
  {
    temp = array[i]; // 위치를 찾을 값 저장
    j = i - 1;
    while (j >= 0 && array[j] > temp) // 값이 작을경우 기존의 값들을 한칸씩 뒤로 밀어줌
    {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = temp; // 위치를 찾고자 했던 값을 위치에 저장
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
    newArr = insertion_sort(newArr, newArr.size());
    answer.push_back(newArr[index - 1]);
  }
  return answer;
}