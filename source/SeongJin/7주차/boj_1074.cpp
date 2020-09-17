#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int n, r, c, answer, s;
  cin >> n >> r >> c;
  while (n)
  {
    int idx;
    s = pow(2, n) / 2;
    if (c < s && r < s)
      idx = 0; // 2사분면
    else if (c >= s && r < s)
      idx = 1; // 1사분면
    else if (c < s && r >= s)
      idx = 2; // 3사분면
    else if (c >= s && r >= s)
      idx = 3; // 4사분면

    c %= s;
    r %= s; // c와 r을 더 작은 사각형으로 세팅

    answer += pow(s, 2) * idx; //ans에 s^2*idx 더해줌
    n--;
  }
  cout << answer << endl;
  return 0;
}