# 백준 1965 상자넣기 
# python solved by dp
import sys
from bisect import bisect_left
input = sys.stdin.readline

N = int(input())
boxes = list(map(int, input().split()))
stack = [boxes[0]]

for i in range(N):
    print(stack)
    if stack[-1] < boxes[i]:
        stack.append(boxes[i])
    else:
        stack[bisect_left(stack,boxes[i])] = boxes[i]
print(len(stack))

