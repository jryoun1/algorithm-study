#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int main(void) {
	string arr[50];
	vector<int> min_cnt;
	int row = 0, col = 0;
	scanf("%d %d", &row, &col);
	
	for(int i = 0; i < row; i++){
		string str;
		cin >> str;
		arr[i] = str;
	}
	
	for (int a = 0; a < row - 7; a++){
		for(int i = 0 ; i < col - 7; i++){
			int b_cnt = 0;
			int w_cnt = 0;
			for (int b = a; b < a + 8; b++){
				for (int j = i; j < i + 8; j++){
					if ((b+j)%2 == 0){
						if(arr[b][j] == 'W') b_cnt ++;
						if(arr[b][j] == 'B') w_cnt ++;
					}
					else{
						if(arr[b][j] == 'B') b_cnt ++;
						if(arr[b][j] == 'W') w_cnt ++;
					}
				}
			}
			min_cnt.push_back(b_cnt);
			min_cnt.push_back(w_cnt);
		}
	}
	sort(min_cnt.begin(),min_cnt.end());
	printf("%d",min_cnt[0]);
	return 0;
}
