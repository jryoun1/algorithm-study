//백준 2503 숫자야구
#pragma warning(disable:4996)
#include<stdio.h>
#include<iostream>
#include<vector>
#include <string>
#include <tuple>
#include<cstring>

using namespace std;

struct inputData
{
	int question;
	int strike;
	int ball;
};
int n;
inputData* arr = new inputData[n];
bool checkIn[987];

void input() {
	int tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].question);
		scanf("%d", &arr[i].strike);
		scanf("%d", &arr[i].ball);
	}
}

int main() {
	//chekIn-> 1로 초기화
	memset(checkIn, 1, sizeof(checkIn));
	input();
	
	string check;
	string checkList;
	int checkStrike = 0;
	int checkBall=0;
	//n개의 질문에대하여
	//k[123~987] 까지의 질문에 대하여 각각 비교해보고 끝까지 true남은 것만 답으로 체크
	for (int i = 0; i < n; i++) {
		for (int k = 123; k <= 987; k++) {
			//현재 질문의 숫자와 k 번째 숫자의 질문을 비교
			check=to_string(arr[i].question);
			checkList = to_string(k);

			//k번째 숫자에 대한 strike와 boll을 확인
			for (int m = 0; m < 3; m++) {
				for (int a = 0; a < 3; a++) {
					if (check[m] == checkList[a]) {
						if (m == a) checkStrike++;
						if (m != a) checkBall++;
					}
				}
			}

			//srike와 boll이 같지 않은 숫자는 경우의 수에서 삭제 (false)
			if (arr[i].strike != checkStrike || arr[i].ball != checkBall)
				checkIn[k] = 0;

			//다음의 k번째 수를 체크하기위해 다시 0으로 초기화 해놓는다.
			checkStrike = 0;
			checkBall = 0;

		}
		//한 n번째 질문에 대하여 123~987 까지의 숫자를 비교해본 결과
	}
	//n개 질문 모두에 대하여 숫자를 대입하여 check(bool)로 상태를 체크한 결과


	//같은 숫자가 한번 더 들어갔거나 0이 들어간 숫자를 모두 제외시킴
	for (int i = 123; i < 987; i++)
	{
		string tmp = to_string(i);
		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]) 
			checkIn[i] = 0;
		if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0) 
			checkIn[i] = 0;
	}

	//true인 경우의 수를 체크
	int Answer = 0;
	for (int i = 123; i <= 987; i++)
	{
		if (checkIn[i] == 1) Answer++;
	}
	printf("%d", Answer);


	return 0;
}