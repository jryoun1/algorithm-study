#include<iostream>

#define MAX 101
//첫번째 시도 : 100 이라 설정하였다가 범위오류
//-> 101 로 수정

using namespace std;

char map[MAX][MAX];   //RGB를 모두 인식가능한 일반인을 위한 map
char CBmap[MAX][MAX]; //color blindness를 위한 map
int N;

//일반인들을 위한 DFS
void sol(char color,int x, int y) {
	//1.현재 x,y 가 범위를 벗어나는 경우 return
	map[y][x] = 'x';
	if (x < 0 || x >= N || y < 0 || y >= N)
		return;
	//2,현재 위치에서 찾는 색깔과 동일한 경우 이동
	if (map[y - 1][x] == color)
		sol(color, x, y - 1);
	if (map[y + 1][x] == color)
		sol(color, x, y + 1);
	if (map[y][x - 1] == color)
		sol(color, x - 1, y);
	if (map[y][x + 1] == color)
		sol(color, x + 1, y);

}

//적록생맹을 위한 DFS
void CBsol(char color, int x, int y) {
	//1.현재 x,y 가 범위를 벗어나는 경우 return
	CBmap[y][x] = 'x';
	if (x < 0 || x >= N || y < 0 || y >= N)
		return;
	//2,현재 위치에서 찾는 색깔과 동일한 경우 이동
	if (CBmap[y - 1][x] == color)
		CBsol(color, x, y - 1);
	if (CBmap[y + 1][x] == color)
		CBsol(color, x, y + 1);
	if (CBmap[y][x - 1] == color)
		CBsol(color, x - 1, y);
	if (CBmap[y][x + 1] == color)
		CBsol(color, x + 1, y);
}

int main()
{
	int ans1=0; //일반일을 위한 답 저장
	int ans2=0; //적록생맹인들을 위한 답 저장

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			map[i][j] = tmp[j];
			//적록생맹의 map에는 G대신 R을 기록하여 G와 R을 한 구역으로 배치
			if(tmp[j]=='G')
				CBmap[i][j] = 'R';
			else
				CBmap[i][j] = tmp[j];
		}
	}

	//map 과 CBmap의 모든 위치를 check하면서 
	//재귀함수 sol로 도달하지 않은 위치에서 DFS를 진행하여
	//DFS가 새롭게 도는 위치마다 count를 추가하여 구간별 갯수를 구함
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 'x') {
				ans1++;
				sol(map[i][j], j, i);
			}
			if(CBmap[i][j] != 'x') {
				ans2++;
				CBsol(CBmap[i][j], j, i);
			}
		}
	}

	cout << ans1<<" "<<ans2<<endl;
	return 0;
}