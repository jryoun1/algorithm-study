/*
1 ~9 는 감소하는 수

    ---
    2자리
    1 1개 
    2 2개
    3 3개
    4 4개
    5 5개
    9 9개

    ---3자리
    1 0개
    2 1개 210
    3 3개 310 320 321
    4 6개 410 420 421 430 431 432
    5 10개 510 520 521 530 531 532 540 541 542 543

    ---4자리
    1 0개
    2 0개
    3 3210 1개
    4 4개
    5 10개
    6 20개
*/
// 이 전꺼 + -10index
/*
10 -> 10 -> 1
11 -> 20 -> 2개
12 -> 30 -> 3개
13 -> 40 -> 4개
14 -> 50 -> 5개
15 -> 60 -> 6개
16 -> 70 -> 7개
17 -> 80 -> 8개
18 -> 90 -> 9개
19 -> 100 -> 0
20 -> 200 -> 10 -> 1개
21 -> 300 -> 10 + 11 -> 3개
22 -> 400 -> 10 + 11 + 12
23 -> 500
24 -> 600
25 -> 700
26 -> 800
27 -> 900 -> 10 ~ 17
28 -> 1000 -> 0
29 -> 2000 -> 0
30 -> 3000 -> 19 + 20 -> 1개 // 3210
31 -> 4000
32 -> 5000
33 -> 6000
34 -> 7000
35 -> 8000
36 -> 9000
37 -> 10000 -> 0
38 -> 20000 -> 0
39 -> 30000 -> 0
40 -> 40000 -> 28 + 29 + 30  -> 1개 // 43210
*/

/*#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
   int n, digit = 0;
   bool flag = false;
   vector<int> des;
   cin >> n;
   des.push_back(0);

   int sum = 0;
   if (n / 10 < 1)
      cout << ((n == 0) ? 0 : 1) << endl;
   else
   {
      for (int i = 1; i <= 9; i++)
      {
         des.push_back(1);
         sum++;
      }
      while (digit < 10)
      {
         for (int i = 0; i < digit; i++)
            des.push_back(0);
         for (int i = 1; i <= 9 - digit; i++)
         {
            des.push_back(des.back() + des[des.size() - 10]);
            sum += des.back();
            if (n <= sum) {
               sum -= des.back();
               flag = true;
               break;
            }
         }
         if (flag == true) break;
         digit++;
      }
      if (n >= sum && digit == 10) cout << -1 << endl;
      else
      {
         unsigned long long answer = pow(10, digit + 1);
         int start = (des.size()-1) % 9;
         if (start == 0) start = 9;
         n -= sum;
         for (unsigned long long i = answer * start; i < answer * (start + 1); i++)
         {
            string tmp = to_string(i);
            flag = true;
            // Todo: 여기 감소하는 수 구해야 함
            for (int j = 0; j < tmp.length(); j++)
            {
               if (tmp[j] <= tmp[j + 1])
               {
                  flag = false;
                  break;
               }
            }
            if (flag == true) {
               n--;
               if (n == 0)
               {
                  answer = i;
                  break;
               }
            }
         }
         cout << answer << endl;
      }
      
   }
   
   return 0;
}*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
  vector<long long> dec_num;
  for (int i = 1; i <= 1023; i++)
  {                    // {0, 1, 2, 3, .. , 9}의 공집합이 아닌 부분집합을 뽑아내기 위해서.
    long long num = 0; // i에 대응되는 감소하는 수
    int tmp_i = i;
    for (int idx = 9; idx >= 0; idx--)
    {
      if (tmp_i % 2 == 1)
        num = 10 * num + idx; // idx를 1의 자리에 넣음
      tmp_i /= 2;
    }
    dec_num.push_back(num); // i에 대응되는 감소하는 수를 list에 넣음
  }
  sort(dec_num.begin(), dec_num.end());
  int N;
  cin >> N;
  if (N > 1022)
    printf("-1");
  else
    printf("%lld", dec_num[N]);
  return 0;
}