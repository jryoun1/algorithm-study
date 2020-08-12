#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    set<pair<int, string> > setPairStr;
    string str;
    int n;

    cin >> n;

    for (int i=0;i<n;i++)
    {
        cin >> str;
        setPairStr.insert(make_pair(str.length(), str));
    }

    for (auto const &value: setPairStr)
    {
        cout << value.second << endl;
    }
    return 0;
}