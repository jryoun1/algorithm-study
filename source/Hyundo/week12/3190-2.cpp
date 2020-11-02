#include<iostream>
#include<deque>
#define MAX 101

using namespace std;

class Point {
public:
	int x, y;
	Point() {
		x = y = -1;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int dir = 4; // 방향
int N; // 보드 크기
int K; // 사과 개수
int L; // 방향 변환 개수
int map[MAX][MAX] = { 0, }; //전체 보드
int ax, ay, cTime;
int answer; //현재 시간
char cDir;
deque<Point> snake;
char change[10001];

void changeDir() {
	switch (dir) {
	case 1:
		if (change[answer] == 'L') dir = 3;
		else dir = 4;
		break;
	case 2:
		if (change[answer] == 'L') dir = 4;
		else dir = 3;
		break;
	case 3:
		if (change[answer] == 'L') dir = 2;
		else dir = 1;
		break;
	case 4:
		if (change[answer] == 'L') dir = 1;
		else dir = 2;
		break;
	}
}

Point move(Point now) {
	int x = now.x, y = now.y;
	switch (dir) {
	case 1:
		--x;//좌
		break;
	case 2:
		++x;//우
		break;
	case 3:
		--y;//상
		break;
	case 4:
		++y;//하
		break;
	}
	return Point(x, y);
}

void go() {
	while (true) {
		//현재 시간 방향 체크 , 방향 전환이 있을 경우 방향 전환을 진행
		if (change[answer] == 'L' || change[answer] == 'D') changeDir();
		//현재 위치로부터 현재 방향으로 이동
		Point next = move(snake.front());

		int x = next.x;
		int y = next.y;  
		//다음방향

		//진행할 방향이 벽에 닿았거나 자기 자신의 몸에 닿았을 경우 종료
		if (x < 0 || x >= N || y < 0 || y >= N || map[x][y] == 2) break;

		//머리 늘려주기
		snake.push_front(Point(x, y)); 
		//사과가 없을 경우
		if (map[x][y] == 0) {
			map[snake.back().x][snake.back().y] = 0; //꼬리를 없애주기
			snake.pop_back();
		}
		//현재 뱀이 있는 곳은 모두 2로 변경
		map[x][y] = 2;
		++answer;
	}
	cout << answer + 1 << endl;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> ax >> ay;
		map[ax - 1][ay - 1] = 1;
		//사과 위치 1로 설정
	}
	cin >> L;

	for (int i = 0; i < L; i++) {
		cin >> cTime;
		cin >> cDir;
		change[cTime] = cDir;
	}
	map[0][0] = 2;
	snake.push_back(Point(0, 0));
	go();
	return 0;
}
