// 백준 2503 숫자야구
// cpp solved by brute-force
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    // result save every possible baseball num
    vector<int> result;
    // temp save baseball num that have been compared with result
    // and have possible of being answer 
    vector<int> temp;
    
    int N, num,strike,ball;
    for (int i = 123; i < 988; i++){
        if(to_string(i)[0] == to_string(i)[1] || to_string(i)[1] == to_string(i)[2] || to_string(i)[0] == to_string(i)[2] || to_string(i)[1] == '0' || to_string(i)[2] == '0')
            continue;
        else result.push_back(i);
    }
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d %d %d", &num, &strike, &ball);
        for (int j = 0; j < result.size(); j++){
            int s = 0, b = 0;
            string result_num = to_string(result[j]);
            string input_num = to_string(num);
            
            if(result_num[0] == input_num[0]) s ++;
            if(result_num[1] == input_num[1]) s ++;
            if(result_num[2] == input_num[2]) s ++;
            if(result_num[0] != input_num[0] && (result_num[0] == input_num[1] || result_num[0] == input_num[2])) b ++;
            if(result_num[1] != input_num[1] && (result_num[1] == input_num[0] || result_num[1] == input_num[2])) b ++;
            if(result_num[2] != input_num[2] && (result_num[2] == input_num[0] || result_num[2] == input_num[1])) b ++;

            if(strike == s && ball == b) temp.push_back(result[j]);
        }
        // to copy vector there 2 way
        // 1 - copy => copy(temp.begin(), temp.end(), result.begin())
        // 2 - assign => result.assign(temp.begin(),temp.end());
        result.assign(temp.begin(),temp.end());
        // to erase all element in vector => clear() 
        temp.clear();
    }
    printf("%d", result.size());
    return 0;
}