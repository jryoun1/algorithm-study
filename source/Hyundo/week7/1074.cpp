#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> check;
int N, r, c;
int answer = 0;


void solution(int h, int x, int y)
{
	if (x == r && y == c)
	{
		cout << answer << endl;
		return;
	}

	if (r > x + h - 1 || c > y + h - 1 || r < x || c < y)
	{
		//cout << x << " " << y << " " << h;
		answer += h * h;
		//cout << answer << endl;
		return;
	}

	solution(h / 2, x, y);
	solution(h / 2, x, y + (h / 2));
	solution(h / 2, x + (h / 2), y);
	solution(h / 2, x + (h / 2), y + (h / 2));

}

int main() {

	cin >> N >> r >> c;

	solution(pow(2, N), 0, 0);

	return 0;
}