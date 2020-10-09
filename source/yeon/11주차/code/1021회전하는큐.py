# 백준 1021 회전하는큐
# python solved by list
N, M = map(int,input().split())
location = list(map(int,input().split()))
arr = [i for i in range(1,N+1)]

#cur is the index of where queue's head is
cur, ans = 0, 0
for i in range(M):
    #target is the index of where target's index is
    target = arr.index(location[i])
    if target == cur :
        if location[i] < N :
            cur = target
        else : cur = 0
        arr.pop(target)
    else :
        if cur < target :
            left, right = cur + len(arr) - target , target - cur 
        else : 
            left, right = cur - target , len(arr) - cur + target
        ans += min(left,right)
        if location[i] < N :
            cur = target
        else : cur = 0
        arr.pop(target)
print(ans)
