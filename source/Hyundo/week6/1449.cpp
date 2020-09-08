#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, L;
vector<float> tape;

int main() {
	int tmp;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		tape.push_back(tmp);
	}
	
	sort(tape.begin(), tape.end());

	float range = 0;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (tape[i]+0.5 > range){
			range = tape[i] - 0.5 + L;
			answer++;
		}
	}

	cout << answer << endl;

	return 0;
}