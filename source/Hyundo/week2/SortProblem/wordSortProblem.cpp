#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string &a, string &b)
{
	return a.size() == b.size() ? (a < b) : (a.size() < b.size());
}

void solution(vector<string>& array)
{
	sort(array.begin(), array.end(), compare);
	array.erase(unique(array.begin(), array.end()), array.end());
}

int main()
{
	vector<string> array;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		array.push_back(tmp);
	}
	solution(array);
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << endl;
	return 0;
}

