# 백준 1725 히스토그램
# python solved by divide and conquer
def solution(start:int, end:int):
    # if there's only one element left
    if start == end : return arr[start]
    
    mid = (start+end)//2
    _max = max(solution(start,mid),solution(mid+1,end))

    # cnt is set as 2 because it start from adding left and right
    left, right, cnt = mid, mid+1, 2
    _min = min(arr[left], arr[right])
    _max = max(_max, _min * cnt)

    # check right, left side from the mid 
    # renew the _min value after add new element and add cnt
    # renew the _max each cycle
    while left > start or right < end:
        if right < end and (left == start or arr[left-1] < arr[right+1]):
            right += 1
            _min = min(_min,arr[right])
            cnt += 1
        else :
            left -= 1
            _min = min(_min,arr[left])
            cnt += 1
        _max = max(_max, _min * cnt)
    return _max

N = int(input())
arr = []
for i in range(N):
    height = int(input())
    arr.append(height)

print(solution(0,N-1))