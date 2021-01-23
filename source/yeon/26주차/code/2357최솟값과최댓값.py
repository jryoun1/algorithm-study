# 백준 2357 최솟값과 최댓값
# python solved by segment Tree
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
intMax = sys.maxsize
intMin = -1
def initMin(left, right, node):
    if left == right: 
        rangeMin[node] = array[left+1]
        return rangeMin[node]
    mid = (left + right) // 2
    leftMin = initMin(left, mid, node*2)
    rightMin = initMin(mid+1, right, node*2 + 1)
    rangeMin[node] = min(leftMin, rightMin)
    return rangeMin[node]

def initMax(left, right, node):
    if left == right:
        rangeMax[node] = array[left+1]
        return rangeMax[node]
    mid = (left+right) // 2
    leftMax = initMax(left, mid, node*2)
    rightMax = initMax(mid+1, right, node*2+1)
    rangeMax[node] = max(leftMax, rightMax)
    return rangeMax[node]

def minQuery(left, right, node, nodeLeft, nodeRight):
    if right < nodeLeft or nodeRight < left:
        return intMax
    if left <= nodeLeft and nodeRight <= right: 
        return rangeMin[node]
    mid = (nodeLeft + nodeRight) // 2
    return min(minQuery(left, right, node*2, nodeLeft, mid), minQuery(left, right, node*2+1, mid+1, nodeRight))

def maxQuery(left, right, node, nodeLeft, nodeRight):
    if right < nodeLeft or nodeRight < left:
        return intMin
    if left <= nodeLeft and nodeRight <= right: 
        return rangeMax[node]
    mid = (nodeLeft + nodeRight) // 2
    return max(maxQuery(left, right, node*2, nodeLeft, mid), maxQuery(left, right, node*2+1, mid+1, nodeRight))

N, M = map(int, input().split())
array = [0]
for _ in range(N):
    number = int(input())
    array.append(number)
rangeMin = [0] * 4 * N
rangeMax = [0] * 4 * N
initMax(0, N-1, 1)
initMin(0, N-1, 1)

for _ in range(M):
    left, right = map(int, input().split())
    print(minQuery(left-1, right-1, 1, 0, N-1), maxQuery(left-1, right-1, 1, 0, N-1))