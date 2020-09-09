#include <iostream>
using namespace std;

int main()
{
  // 지불해야하는 값
  int x;

  // 가지고 있는 동전
  int coins[6] = {500, 100, 50, 10, 5, 1};

  cin >> x;

  // answer: 총 개수
  // count: 각 코인의 개수
  // idx: count 배열의 index
  int answer = 0, count[6], idx = 0;

  // foreach 사용
  for (auto coin : coins)
  {
    count[idx] = x / coin;
    x %= coin;
    answer += count[idx];
    idx++;
  }

  cout << "사용한 동전의 총 개수는 " << answer << "개 입니다.\n";

  for (int i = 0; i < 6; i++)
  {
    cout << coins[i] << "원은 " << count[i] << "개 사용하였습니다.\n";
  }
  return 0;
}