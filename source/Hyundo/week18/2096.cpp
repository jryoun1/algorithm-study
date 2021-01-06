#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int colMax[3] = { 0 },  //이전 행(i-1) 의 최댓값 결과 저장
		colMin[3] = { 0 },  //이전 행(i-1) 의 최솟값 결과 저장
		tempMax[3] = { 0 }, //현재 행(i) 의 문제 결과 저장
		tempMin[3] = { 0 }; //현재 행(i) 의 문제 결과 저장

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", tempMax + j);//tempMax 입력받은 값 저장
			tempMin[j] = tempMax[j]; //tempMin 에도 입력받은 값 저장
			tempMax[j] += max(colMax[1], (j == 1) ? max(colMax[0], colMax[2]) : colMax[j]);
			tempMin[j] += min(colMin[1], (j == 1) ? min(colMin[0], colMin[2]) : colMin[j]);
			//j가 0인 경우 (max or min) (S[i-1][0], S[i-1][1])
			//j가 1인 경우 (max or min) (S[i-1][0], S[i-1][1],s[i-1][2])
			//j가 2인 경우 (max or min) (S[i-1][1], S[i-1][2]
			//으로 최대값or최솟값을 지정할 수 있다.
		}
		// colMax, colMin 배열을 temp 배열로 덮어쓰기하여 다음 루프에서 사용
		memcpy(colMax, tempMax, sizeof(int) * 3);
		memcpy(colMin, tempMin, sizeof(int) * 3);
	}
	//가장 마지막 줄에 저장된 MAX 값과 Min 값을 출력한다.
	sort(colMax, colMax + 3);
	sort(colMin, colMin + 3);
	printf("%d %d\n", colMax[2], colMin[0]);
}


