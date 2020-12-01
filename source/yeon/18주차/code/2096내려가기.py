# 백준 2096 내려가기
# python solved by 
import sys, copy
N = int(sys.stdin.readline())
windowMax = list(map(int, sys.stdin.readline().split()))
windowMin = copy.deepcopy(windowMax)
minWindow, maxWindow = [0]*3, [0]*3
for _ in range(N - 1):
    _map = list(map(int, sys.stdin.readline().split()))
    for i in range(3):
        if i == 0:
            maxWindow[i] = max(windowMax[i]+_map[i], windowMax[i+1]+_map[i])
            minWindow[i] = min(windowMin[i]+_map[i], windowMin[i+1]+_map[i])
        elif i == 1:
            maxWindow[i] = max(windowMax[i-1]+_map[i] ,max(windowMax[i]+_map[i], windowMax[i+1]+_map[i]))
            minWindow[i] = min(windowMin[i-1]+_map[i] ,min(windowMin[i]+_map[i], windowMin[i+1]+_map[i]))
        else:
            maxWindow[i] = max(windowMax[i]+_map[i], windowMax[i-1]+_map[i])
            minWindow[i] = min(windowMin[i]+_map[i], windowMin[i-1]+_map[i])
    windowMax = copy.deepcopy(maxWindow)
    windowMin = copy.deepcopy(minWindow)

if N == 1:
    print(max(windowMax), min(windowMin))
else:
    print(max(maxWindow), min(minWindow))