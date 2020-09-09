# 백준 1449 수리공 항승
# python solved by Greedy algorithm
N,L = map(int,input().split())
arr = list(map(int,input().split()))

cnt, tape_range = 0, 0
arr.sort()

# put tape first and set tape_range 
# and check arr element if its in range 
# if they are out of range, put another tape and set again
for i in range(0, len(arr)):
    if arr[i] + 0.5 > tape_range :
        cnt += 1
        tape_range = arr[i] - 0.5 + L

print(cnt)
