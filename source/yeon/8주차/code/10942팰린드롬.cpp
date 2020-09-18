// 백준 10942 팰린드롬
// cpp solved by dynamic programming
#include<iostream>
#include<vector>
int N, M, s, e;
int arr[2000];
std::vector<std::vector<int>> dp;

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    // assign nxn size of vector 
    for(int i = 0; i < N; i++){
        std::vector<int>element(N);
        dp.push_back(element);
    }

    // one element must be the palindrome
    for(int i = 0; i < N; i++) 
        dp[i][i] = 1;

    // two element gonna be palindrome 
    // if first and second element is same
    for(int i = 0; i < N-1; i++){
        if(arr[i]==arr[i+1]) 
            dp[i][i+1] = 1;
    }
    
    // if range is more than 3 
    // just check the first and last element are same
    // and check dp[first+1][last-1] == 1 
    for(int l = 2; l < N; l++){
        for(int i = 0; i < N-l; i++){
            if(arr[i]==arr[i+l] && dp[i+1][i+l-1]==1){
                dp[i][i+l] = 1;
            }
        }
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n",dp[s-1][e-1]);
    }
}
