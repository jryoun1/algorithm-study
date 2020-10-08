# 백준 1300 k번째 수 
# python solved by binary search

N, k = int(input()), int(input())
left, right = 1, k

# parametric Search 
# check mid is k'th element or not 
# count the number of element under mid 
# and binary search according to compare result of cnt & k
while left <= right:
    # just set mid as half of arr
    # so time complexity can be log(k)
    mid = (left + right)//2

    cnt = 0
    # count the number of element under mid 
    for i in range(1,N+1):
        cnt += min(mid//i, N)

    # and binary search according to compare result of cnt & k
    if cnt >= k:
        ans = mid
        right = mid -1
    else:
        left = mid + 1

print(ans)