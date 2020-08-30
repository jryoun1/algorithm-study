// 백준 1182 부분수열의 합
// cpp solved by combinations and brute-force
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arr; // save input from user
vector<vector<int>> result; // save combination result
vector<int> sub;
int N, S;

void combination(int k){
    // if index is same as size of arr
    // push it to result[]
    if(k == N){
        result.push_back(sub);
    }else{
        sub.push_back(arr[k]);
        combination(k+1);
        sub.pop_back();
        combination(k+1);
    }
}

int main(void){
    int num, cnt = 0;
    long long sum;
    
    scanf("%d %d",&N, &S);
    for (int i = 0; i < N; i++){
        scanf("%d", &num);
        arr.push_back(num);
    }

    // start recurisve from index 0 
    combination(0);

    // check is value which prevent counting cnt 
    // even though there's nothing to calculate 
    int check;
    for(int i = 0; i <result.size();i++){
        sum = 0, check = 0;
        for(int j = 0; j < result[i].size();j++){
            sum += result[i][j];
            check++;
        }
        if(sum == S && check > 0) cnt++;
    }
    printf("%d", cnt);
    return 0;
}