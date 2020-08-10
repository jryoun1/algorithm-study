#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
	int num;
	int age;
	string name;
};

bool compare(Person&a, Person&b)
{
	return a.age==b.age ? a.num<b.num : a.age<b.age;
}

void solution(vector<Person>& array)
{
	sort(array.begin(), array.end(), compare);
}

int main()
{
	vector<Person> array;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int age; string name;
		cin >> age >> name;
		array.push_back({ i, age, name });
	}
	solution(array);
	for (int i = 0; i < array.size(); i++)
		cout << array[i].age <<" "<<array[i].name << endl;
	return 0;
}

