// nlongn 방법
/*#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100005];
long long preSum[100005] = {
    0,
};

long long findMax(int left, int right)
{
  if (left == right)
    return arr[left] * arr[left];
  int mid = (left + right) / 2;
  long long ret = max(findMax(left, mid), findMax(mid + 1, right));

  int l = mid;
  int r = mid + 1;
  long long minVal = min(arr[l], arr[r]);
  ret = max(ret, minVal * (preSum[r] - preSum[l]));

  while (left < l || r < right)
  {
    if (r < right && (l == left || arr[l - 1] < arr[r + 1]))
    {
      r += 1;
      minVal = min(minVal, arr[r]);
    }
    else
    {
      l -= 1;
      minVal = min(minVal, arr[l]);
    }
    ret = max(ret, (preSum[r] - preSum[l - 1]) * minVal);
  }
  return ret;
}
int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    preSum[i] += arr[i] + preSum[i - 1];
  }

  cout << findMax(1, n) << endl;
  return 0;
}*/

// O(n) 풀이 근데 O(n) 보다 더 걸릴 듯
// 한 번만 전체 공간을 스캔하면서 마주치는 요소들에 대해 뭔가를 해 주면 정답이 구해지는 형태
#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

long long A[100005];
long long preSum[100005];
stack<pair<int, int>> stk;
int main()
{
  int n;
  cin >> n;
  A[n + 1] = 0;
  long long answer = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> A[i];
    preSum[i] = preSum[i - 1] + A[i];
  }
  for (int i = 1; i <= n + 1; i++)
  {
    while (!stk.empty() && stk.top().first > A[i])
    {
      auto p = stk.top();
      stk.pop();
      int h = p.first;
      int prv = stk.empty() ? 0 : stk.top().second;
      long long test = preSum[i - 1] - preSum[prv];
      long long test2 = (preSum[i - 1] - preSum[prv]) * h;
      answer = max(answer, (preSum[i - 1] - preSum[prv]) * h);
    }
    stk.push({A[i], i});
  }
  cout << answer << endl;
  return 0;
}