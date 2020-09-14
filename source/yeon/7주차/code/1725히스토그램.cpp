// 백준 1725 히스토그램 
// cpp solved by sweeping line using stack
#include<iostream>
#include<stack>
#define max(a,b) (a > b ? a : b)
std::stack<long long> s;
long long N, arr[100001];

long long solution(){
    long long _max = 0;
    // to consider fisrt part by push 0 in stack
    s.push(0);
    // set range 1-N+1 so that it can consider last part
    for (int i = 1; i <= N + 1; i++){
        while(!s.empty() && arr[i] < arr[s.top()]){
            int height = arr[s.top()];
            s.pop();
            int width = i - s.top() -1;
            
            _max = max(_max, (long long)(width * height));
        }
    s.push(i);
    }
    return _max;
}

int main(void){
    scanf("%lld", &N);
    for(int i = 1; i <= N; i++){
        scanf("%lld", &arr[i]);
    }
    printf("%lld",solution());
    return 0;
}