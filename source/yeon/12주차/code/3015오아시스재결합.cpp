// 백준 3015 오아시스 재결합
// cpp solved by stack
#include<iostream>
#include<stack>
using namespace std;
int N, arr[500001];
long long ans = 0;
stack<pair <int, int> > st;

long long solution(){
    for(int i = 0; i < N; i++){
        while(!st.empty() && st.top().first < arr[i]){
            ans += st.top().second;
            st.pop();
        }
        if(st.empty()){
            st.push({arr[i], 1});
        }else{
            if(st.top().first == arr[i]){
                int cnt = st.top().second;
                st.pop();
                ans += cnt;

                if(!st.empty()){
                    ans += 1;
                }
                st.push({arr[i], cnt + 1});
            }else{
                st.push({arr[i], 1});
                ans += 1;
            }
        }
    }
    return ans;
}
int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }
    printf("%lld\n",solution());
    return 0;
}