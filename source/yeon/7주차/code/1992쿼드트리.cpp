// 백준 1992 쿼드트리
// cpp solved by recursive + divide and conquer
#include <iostream>
using namespace std;
int N, arr[64][64];

void quadTree(int x, int y, int n){
    // if there's only one element left
    // print the element 
	if (n==1){
		cout << arr[y][x];
		return;
	}
	bool same = true;
    // by adding check condition in for statement
    // don't have to break when find there's other element in range 
	for(int i = y; i < (y + n) && same; i++)
		for(int j = x; j < (x + n) && same; j++)
			if(arr[i][j] != arr[y][x])
				same = false;

	if(same) cout << arr[y][x] ;
	else {
			cout << "(" ;
			quadTree(x,y,n/2);
			quadTree(x+n/2,y,n/2);
			quadTree(x,y+n/2,n/2);
			quadTree(x+n/2,y+n/2,n/2);
			cout << ")" ;
	}
}


int main(void) {
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%1d", &arr[i][j]);
		}
	}
	quadTree(0,0,N);
	return 0;
}