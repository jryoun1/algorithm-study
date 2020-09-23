// 백준 10844 쉬운계단수
// cpp solved by dp 
#include<iostream>
#define MOD 1000000000
int main(void){
    // just assign 2x12 arr 
    int N, arr[2][12]={0,};
    scanf("%d", &N);
    int sum = 9;
    
    for(int i = 2; i <11; i++){
        arr[1][i] = 1;
    }

    for(int i = 2; i <= N; i++){
        sum = 0;
        // by using modular calculation, don't have to assign 11x102 size of arr
        // moving up & down so that decrease use of space complexity
        for(int j = 1; j < 11; j++){
            arr[i%2][j] = (arr[(i-1)%2][j-1]+arr[(i-1)%2][j+1]) % MOD;
            sum = (sum + arr[i%2][j]) % MOD;
        }
    }
    printf("%d",sum);
    return 0;
}