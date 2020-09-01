#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//파이썬과 같은 이분탐색 로직으로 문제를 풀었는데
//int로 선언하여서 통과를 못했는데 
//그 이유가 범위가 크다보니까 sum을 계산할때 overflow가 발생할 수 있음
//따라서 int가 아닌 Long long을 사용하여 해결 
long long cal_sum(vector<long long> arr, long long size, long long mid){
    long long sum = 0;
    for (long long i = 0; i < size; i++){
        if (arr[i] - mid > 0)
            sum += arr[i] - mid;
    }
    return sum;
}
void solution (vector<long long> arr, long long size, long long height){
    long long left = 0, right = *max_element(arr.begin(),arr.end());
    long long mid = 0, sum = 0, ans = 0;
    while(left <= right){
        mid = (left + right)/2;
        sum = cal_sum(arr, size, mid);

        if(sum < height)
            right = mid -1;
        if(sum >= height){
            ans = mid;
            left = mid + 1;
        }
    }
    printf("%lld",ans);
}

int main(void){
    long long num, height = 0;
    scanf("%lld %lld", &num, &height);
    vector<long long> arr ;
    for(long long i = 0; i < num; i++){
        long long n = 0;
        cin >> n;
        arr.push_back(n);
    }
    solution(arr, num, height);
    return 0;
}   
