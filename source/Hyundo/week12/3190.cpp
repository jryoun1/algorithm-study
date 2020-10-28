#include<iostream>
#include<utility>
#include<vector>
#define MAX 101

using namespace std;


int dir = 4; // 방향
int N; // 보드 크기
int K; // 사과 개수
int map[MAX][MAX] = { 0, }; //전체 보드
int L; // 방향 변환 횟수

vector<pair<int, char>> pv;

void changeDir(int i) {
	switch (dir) {
	case 1:
		if (pv[i].second == 'L') dir = 3;
		else dir = 4;
		break;
	case 2:
		if (pv[i].second == 'L') dir = 4;
		else dir = 3;
		break;
	case 3:
		if (pv[i].second == 'L') dir = 2;
		else dir = 1;
		break;
	case 4:
		if (pv[i].second == 'L') dir = 1;
		else dir = 2;
		break;
	}
}

void move() {
	
	switch (dir) {
	case 1:
		--x;
		break;
	case 2:
		++x;
		break;
	case 3:
		--y;
		break;
	case 4:
		++y;
		break;
	}

}


int main() {
	bool finish = true;
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		//사과가 있는 위치는 1로 설정
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int a; char b;
		cin >> a >> b;
		pv.push_back(make_pair(a, b));
	}

	int x = 0; //현재 시간

	while (finish) {
		
		//현재 방향으로 이동 : 상/하/좌/우
		//현재 시간에 방향이동을 확인 후 저장
		//1.이동한 칸이 벽에 닿는다면 종료 : 현재 초를 출력하고 반복문 종료
		//2. 몸길이를 늘려 머리를 다음칸에 위치시킴
		//3. 이동하였을 경우 사과 여부확인
		//3-1. 사과가 있을 경우 사과가 없어지고 꼬리는 움직이지 않음
		//3-2. 사과가 없을 경우 몸길이를 줄이고 꼬리가 위치한 칸을 비움

	}



	return 0;
}