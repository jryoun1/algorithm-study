# 백준 2014 부분배열 고르기 
# python solved by divide and conquer

def solution(start, end):
    # if arr divided into last piece 
    if start == end:
        return arr[start]*arr[start]
    
    mid = (start+end) // 2
    # divide into half recursively and get max value
    _max = max(solution(start,mid),solution(mid+1,end))

    left, right = mid, mid+1
    _sum = arr[left] + arr[right]
    _min = min(arr[left],arr[right])
    _max = max(_max, _sum * _min)
    
    # check right, left side from the mid 
    # and put the bigger element in _sum, _min and calculate the _max
    while left > start or right < end :
        if right < end and (left == start or arr[left-1] < arr[right+1]):
            right += 1
            _sum += arr[right]
            _min = min(_min, arr[right])
        else:
            left -= 1
            _sum += arr[left]
            _min = min(_min, arr[left])
        _max = max(_max, _min * _sum)
    
    return _max 

N = int(input())
arr = list(map(int,input().split()))
print(solution(0,N-1))
