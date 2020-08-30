#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
  return a.first < b.first;
}
int main()
{
  string str;
  int n, age;

  cin >> n;

  vector<pair<int, string>> vecPairStr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> vecPairStr[i].first >> vecPairStr[i].second;
  }

  stable_sort(vecPairStr.begin(), vecPairStr.end(), compare);

  for (int i = 0; i < n; i++)
  {
    cout << vecPairStr[i].first << " " << vecPairStr[i].second << '\n';
  }
  return 0;
}