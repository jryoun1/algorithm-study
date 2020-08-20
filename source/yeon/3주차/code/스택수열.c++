#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

int main(void){
    int len, n =0;
    scanf("%d", &len);
    
    vector<int> v;
    vector<int> comp;
    stack<int> stack;
    string answer = "";
    int max = 0, index = 0;
    
    for(int i = 0; i < len; i++){
        cin >> n;
        v.push_back(n);
        if (v[i] > max){
            for (int j = index + 1; j <= v[i]; j++ ){
                stack.push(j);
                answer += "+\n";
            }
            index = v[i];
            comp.push_back(stack.top());
            stack.pop();
            answer += "-\n";

            if(stack.size()!= 0) max = stack.top();
            else max = 0;
        }
        else{
            comp.push_back(stack.top());
            stack.pop();
            answer += "-\n";
            if(stack.size()!= 0) max = stack.top();
            else max = 0;
        }
    }
    if(v == comp) cout<<answer;
    else printf("NO");

    return 0;
}