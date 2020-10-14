// 백준 2346 풍선 터뜨리기
// cpp solved by vector-pair
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int ,int>> v;

int main(){
    scanf("%d", &N);
    for (int i=1, t; i<=N; i++){
        scanf("%d", &t);
        v.push_back({i, t});
    }
 
    while (!v.empty()){
        cout << v.front().first << ' ';
        int target = v.front().second;
        v.erase(v.begin());
        // in case of target is positive
        if (target > 0){
            for (int i = 0; i < target - 1; i++){
                v.push_back(v.front());
                v.erase(v.begin());
            }
        }
        // in case of target is negative
        else{
            for (int i = 0; i < - target; i++){
                v.insert(v.begin(), v.back());
                v.pop_back();
            }
        }
    }
    return 0;
}
