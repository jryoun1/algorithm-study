// 백준 14003 가장 긴 증가하는 부분수열 5
// cpp solved by low_bound & dp 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, a[1000001];
int dp[1000001];
std::vector<int> v;
std::vector<int> ans;
int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i ++){
        scanf("%d", &a[i]);
    }
    v.push_back(a[0]);
    for(int i = 0; i < N; i++){
        if(v.back() < a[i]){
            v.push_back(a[i]);
            dp[i] = v.size() - 1;
        }else{
            int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[pos] = a[i];
            dp[i] = pos;
        }
    }
    int _max = v.size();
    printf("%d\n", _max);

    for(int i = N; i >= 0; i--){
        if(_max < 0) break;
        if(dp[i] == _max - 1){
            ans.push_back(a[i]);
            _max--;
        }
    }
    for(int i = ans.size() - 1; i >= 0; i--){
        printf("%d ", ans[i]);
    }
    return 0;
}