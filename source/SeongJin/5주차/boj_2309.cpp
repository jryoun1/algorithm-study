#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int height[9] = {
      0,
  };
  int arr[9] = {
      0,
  };
  int input;

  for (int i = 0; i < 9; i++)
  {
    cin >> height[i];
    for (int j = 0; j < 9; j++)
    {
      if (i != j)
        arr[j] += input;
    }
  }

  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (i != j && (arr[i] - height[j]) == 100)
      {
        height[i] = -1;
        height[j] = -1;
        sort(height, height + 9);
        for (int i = 2; i < 9; i++)
        {
          cout << height[i] << endl;
        }
        return 0;
      }
    }
  }
}