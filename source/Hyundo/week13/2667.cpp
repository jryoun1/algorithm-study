#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 26


using namespace std;
int N;
int map[MAX][MAX];
int mem[MAX][MAX];
vector<int> Vcnt;


void DFS(int count,int x, int y) {
	mem[y][x] = 0;
	map[y][x] = count;
	if (x < 0 || x >= N || y < 0 || y >= N)
		return;
	if (mem[y - 1][x] == 1)
		DFS(count, x, y - 1);
	if (mem[y + 1][x] == 1)
		DFS(count, x, y + 1);
	if (mem[y][x - 1] == 1)
		DFS(count, x - 1, y);
	if (mem[y][x + 1] == 1)
		DFS(count, x + 1, y);
}

int main()
{
	int count = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			map[i][j] = tmp[j] - 48;
			mem[i][j] = tmp[j] - 48;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mem[i][j] != 0) {
				count++;
				Vcnt.push_back(0);
				DFS(count, j, i);
			}
		}
	}

	Vcnt.push_back(0);

	cout << Vcnt.size()-1 << endl;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Vcnt[map[i][j]]++;
		}
	}

	sort(Vcnt.begin()+1, Vcnt.end());

	for (int i = 1; i < Vcnt.size(); i++)
		cout << Vcnt[i] << endl;




	return 0;
}