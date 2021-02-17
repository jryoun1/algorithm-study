#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


bool consist(vector<string> book) {
	sort(book.begin(), book.end());
	for (int i = 0; i < book.size() - 1; i++) {
		if (book[i] == book[i + 1].substr(0, book[i].size())) 
			return false;
	}
	return true;
}

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		vector<string> phone;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string num;
			cin >> num;
			phone.push_back(num);
		}
		bool answer = consist(phone);
		if (answer == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
