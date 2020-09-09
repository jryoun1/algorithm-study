#include <iostream>
using namespace std;

// 연속하는 20일 중 10일동안만 사용 가능

int main()
{
  // L: 사용가능하는 날
  // P: 연속하는 일
  // V: V일짜리 휴가
  // 1 < L < P < V

  int L, P, V;
  int Case = 1;
  while (1)
  {
    cin >> L >> P >> V;
    if (L == P && P == V && V == 0)
    {
      break;
    }
    cout << "Case " << Case << ": " << V / P * L + (V % P > L ? L : V % P) << '\n';
    Case++;
  }

  return 0;
}