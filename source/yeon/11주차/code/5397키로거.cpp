// 백준 5397 키로거
// cpp solved by stack
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
stack<int> beforeCursor;
stack<int> afterCursor;
int N;
int main(void){
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        string password;
        cin >> password;

        for(int j = 0; j < password.length(); j++){
            if (password[j] == '<'){
                if(!beforeCursor.empty()){
                    afterCursor.push(beforeCursor.top());
                    beforeCursor.pop();
                }
            }
            else if(password[j] == '>'){
                if(!afterCursor.empty()){
                    beforeCursor.push(afterCursor.top());
                    afterCursor.pop();
                }
            }
            else if(password[j] == '-'){
                if(!beforeCursor.empty()){
                    beforeCursor.pop();
                }
            }
            else{
                beforeCursor.push(password[j]);
            }
        }
        while(!afterCursor.empty()){
            beforeCursor.push(afterCursor.top());
            afterCursor.pop();
        }
        string ans = "";
        while(!beforeCursor.empty()){
            ans += beforeCursor.top();
            beforeCursor.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}