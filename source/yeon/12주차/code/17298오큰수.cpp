// 백준 17298 오큰수
// cpp solved by stack
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int N, arr[1000001], ans[1000001];
stack<int> st;
int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    st.push(0);
    for (int i = 0; i < N; i++){
        if(st.empty()){
            st.push(i);
        }

        while(!st.empty() && arr[st.top()] < arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    
    while(!st.empty()){
        ans[st.top()] = -1;
        st.pop();
    }

    for(int i = 0; i < N; i++){
        printf("%d ", ans[i]);
    }
    return 0;
}