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
	//방문한 위치 초기화
	//mem 은 방문 여부 기록
	//map 은 단지번호 기록
	mem[y][x] = 0;
	map[y][x] = count;
	//범위 벗어난 경우 return
	if (x < 0 || x >= N || y < 0 || y >= N)
		return;
	//상하좌우
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
		//string으로 입력 받은 값 map 과 mem에 모두 int 로 저장
		for (int j = 0; j < N; j++) {
			map[i][j] = tmp[j] - 48;
			mem[i][j] = tmp[j] - 48;
		}
	}

	//배열의 모든 위치를 check하면서 이전에 DFS를 진행하지 않은(mem[i][j] !=0)
	//위치에 도달했을 경우 단지 개수를 추가하고 새로 발견된 곳에 단지번호를 부여
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mem[i][j] != 0) {
				count++;
				Vcnt.push_back(0);
				DFS(count, j, i);
			}
		}
	}
	//out of bound 방지
	Vcnt.push_back(0);
	//총 단지수 출력
	cout << Vcnt.size()-1 << endl;

	//map 을 체크하여 각 단지별 개수를 Vcnt에 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Vcnt[map[i][j]]++;
		}
	}
	//오름차순으로 단지내 집의 수를 출력하기 위해 sort
	sort(Vcnt.begin()+1, Vcnt.end());
	//각 단지내 집의 수 출력
	for (int i = 1; i < Vcnt.size(); i++)
		cout << Vcnt[i] << endl;

	return 0;
}