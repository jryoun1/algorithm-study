// 분할 정복
#include <iostream>
#include <algorithm>
using namespace std;

long long height[100005];

long long findMax(int l, int r)
{
  if (l == r)
    return height[l];
  int mid = (l + r) / 2;
  long long ret = max(findMax(l, mid), findMax(mid + 1, r));

  int left = mid;
  int right = mid + 1;
  long long minVal = min(height[left], height[right]);
  ret = max(ret, minVal * 2);

  while (l < left || right < r)
  {
    if (right < r && (l == left || height[left - 1] < height[right + 1]))
    {
      right += 1;
      minVal = min(minVal, height[right]);
    }
    else
    {
      left -= 1;
      minVal = min(minVal, height[left]);
    }
    ret = max(ret, minVal * (right - left + 1));
  }
  return ret;
}
int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> height[i];
  }

  cout << findMax(1, n) << endl;
  return 0;
}