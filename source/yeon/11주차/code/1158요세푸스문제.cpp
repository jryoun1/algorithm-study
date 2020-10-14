// 백준 1158 요세푸스문제
// cpp solved by vector
#include<iostream>
#include<vector>
using namespace std;
int N, k;
vector<int> v;
vector<int> ans;
int main(void){
    scanf("%d %d", &N, &k);
    for(int i = 1; i <= N; i++){
        v.push_back(i);
    }
    // cur gonna be the element far from k
    int cur = k - 1;
    printf("<");
    while(v.size()!= 1){
        printf("%d, ", v[cur]);
        v.erase(v.begin() + cur);
        cur = (cur + k - 1) % v.size();
    }
    printf("%d>",v[0]);
    return 0;
}

// int main(void){
//     scanf("%d %d", &N, &k);
//     for(int i = 1; i <= N; i++){
//         v.push_back(i);
//     }

//     printf("<");
//     while(!v.empty()){
//         for(int i = 0; i < k - 1; i++){
//             v.push_back(v.front());
//             v.erase(v.begin());
//         }
//         if(v.size() == 1){
//             printf("%d",v.front());
//         }else{
//             printf("%d, ",v.front());
//         }
//         v.erase(v.begin());
//     }
//     printf(">");
//     return 0;
// }