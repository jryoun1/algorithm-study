// 백준 3020 개똥벌레
// cpp solved by using lower_bound, upper_bound, binarySearch
// lower_bound, upper_bound 는 이분탐색을 통해 삽입위치를 찾음
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, H, num;
std::vector<int> fromUp;
std::vector<int> fromDown;
std::vector<int> sum;
int result = 200001 , result_cnt = 0;
int main(void){
    scanf("%d %d",&N, &H);
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        if (i % 2 == 0){
            fromUp.push_back(num);
        }else{
            fromDown.push_back(num);
        }
    }
    sort(fromUp.begin(),fromUp.end());
    sort(fromDown.begin(), fromDown.end());

    for(int i = 1; i <= H; i++){
       // 종유석은 하한값 위치를 찾아줌 e.g. 3이면 index를 통해 3이하의 것들의 개수를 알수있음 
       int val = lower_bound(fromDown.begin(), fromDown.end(), i) - fromDown.begin();
       // 석순은 상한값 위치를 찾아줌 e.g. 3이면 index를 통해 h-3 이상인 값을 가지는 것들을 찾아서 더해줌
       val += upper_bound(fromUp.begin(), fromUp.end(), H - i) - fromUp.begin();
      // 위에 val값은 해당 높이 보다 작거나 큰 것들이므로 전체 N 에서 val를 빼주면 해당 높이에서 파괴해야하는 것을 알수있음 
      val = N - val;

       if(result == val){
           result_cnt ++;
       }else if(result > val){
           result = val;
           result_cnt = 1;
       }
    }
    printf("%d %d", result, result_cnt);
    return 0;
}