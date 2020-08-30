#백준 나무자르기 문제 
import time
start = time.time()

# 기존에 while문 안에서 그냥 계산을 했는데 시간초과가 나와서
# 따로 함수로 빼서 계산을 하였음 (실제로 시간초를 제보니 함수로 따로 빼서하는 것이 더 빨랐음)
def calSum(tree, mid):
    sum = 0
    for i in tree:
        if i - mid > 0:
            sum += i - mid  
    return sum 

n, height = map(int,(input().split()))
tree = list(map(int,input().split()))
left, right = 0, max(tree)
ans = 0
while left <= right :
    mid = (left + right) // 2
    sum = calSum(tree, mid)

    if sum < height:
        right = mid -1
    if sum >= height : 
        ans = mid
        left = mid + 1
print(ans)

print("time : ",time.time()-start) #단위는 초 