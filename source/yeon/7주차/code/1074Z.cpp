// 백준 1074 Z 
// cpp solved by divide and conquer
#include<iostream>
int N, r, c;
long long ans = 0;
void solution(int y, int x, int n){
    if (y == r && x == c) {
        printf("%lld\n", ans);
        return;
    }

    // find the location of r,c 
    // if they are in boundary divide 
    // not in booundary just add n*n 
    if (c>= x && c< x+n && r>=y && r< y+n){
        solution(y,x,n/2);
        solution(y,x+n/2,n/2);
        solution(y+n/2,x,n/2);
        solution(y+n/2,x+n/2,n/2);
    }else{
        ans += n * n;
    }
}
int main(void){
    scanf("%d %d %d", &N, &r, &c);
    // 1<<N => 2^N
    solution(0,0,1<<N);
    return 0;
}