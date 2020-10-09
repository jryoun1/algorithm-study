// 백준 1021 회전하는 큐
// cpp solved by list
#include<iostream>
#include<algorithm>
#include<vector>
#define MIN(a,b) (a < b ? a : b )
using namespace std;

int main(void){
    int N, M, location[51];
    vector<int> arr;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &location[i]);
    }
    for(int i = 1; i <= N; i++){
        arr.push_back(i);
    }

    int cur = 0, ans = 0;
    int left, right;
    for(int i = 0; i < M; i++){
        auto it = std::find(arr.begin(), arr.end(), location[i]);
        // *it 의 값은 백터에서 해당 원소를 가르키므로 index를 구하기 위해서는
        // distance를 사용해서 index를 구해야함
        auto target = std::distance(arr.begin(), it);
        if(target == cur){
            if(location[i] < N) cur = target;
            else cur = 0;
            arr.erase(arr.begin() + target);
        }else{
            if(cur < target){
                left = cur + arr.size() - target;
                right = target - cur;
            }else{
                left = cur - target;
                right = arr.size() - cur + target;
            }
            ans += MIN(left, right);
            if(location[i] < N) cur = target;
            else cur = 0;
            arr.erase(arr.begin() + target);
        }
    }
    printf("%d", ans);
    return 0;
}