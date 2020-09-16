// 백준 2104 부분배열 고르기
// cpp solved by divide and conquer
#include<iostream>
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)
int N, arr[100000];

long long solution(int start, int end){
    // if there's only one element left 
    if (start == end) return (long long)arr[start]*arr[start];

    int mid = (start + end)/2;
    // divide into half recursively and get max value 
    long long _max = max(solution(start,mid),solution(mid+1,end));

    int left = mid, right = mid+1;
    long long _sum = arr[left] + arr[right];
    long long _min = min(arr[left],arr[right]);
    _max = max(_max, (long long)_sum * _min);

    // chek right, left side from the mid
    // and put the bigger element in _sum, _min and caculate the _max
    while((left > start) || (right < end)){
        if((right < end) && ((left == start) || (arr[left-1] < arr[right+1]))){
            right += 1;
            _sum += arr[right];
            _min = min(_min, arr[right]);
        }else{
            left -= 1;
            _sum += arr[left];
            _min = min(_min, arr[left]);
        }
        _max = max(_max, (long long)_sum * _min);
    }
    return _max;
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++) 
        scanf("%d",&arr[i]);

    printf("%lld",solution(0,N-1));
    return 0;
}