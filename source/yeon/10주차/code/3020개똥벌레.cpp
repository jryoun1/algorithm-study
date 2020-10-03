// 백준 3020 개똥벌레
// cpp solved by using lower_bound

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, H, num;
std::vector<int> fromUp;
std::vector<int> fromDown;
std::vector<int> sum;
int main(void){
    scanf("%d %d",&N, &H);
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        if (i % 2 == 0){
            fromUp.push_back(num);
        }else{
            fromDown.push_back(H - num + 1);
        }
    }
    sort(fromUp.begin(),fromUp.end());
    sort(fromDown.begin(), fromDown.end());

    for(int i = 1; i < N+1; i++){
        vector<int>::iterator low = lower_bound(fromUp.begin(), fromUp.end(),i+1);
        vector<int>::iterator high = upper_bound(fromDown.begin(),fromDown.end(),i+1);
        //sum.push_back(fromUp[low - fromUp.begin()] + fromDown[high - fromDown.begin()]);
        cout << fromUp[low - fromUp.begin()] << fromDown[high - fromDown.begin()] << endl;
    }
    return 0;
}

