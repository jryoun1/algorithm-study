# 백준 10868 최솟값 
# python solved by segment Tree
import sys
input = sys.stdin.readline
maxInt = sys.maxsize
def init(left, right, node):
    if left == right: 
        rangeMin[node] = arr[left+1]
        return rangeMin[node]
    mid = (left + right)//2
    leftMin = init(left, mid, node*2)
    rightMin = init(mid+1, right, node*2+1)
    rangeMin[node] = min(leftMin, rightMin)
    return rangeMin[node]

def query(left, right, node, nodeLeft, nodeRight):
    if right < nodeLeft or nodeRight < left:
        return maxInt
    if left <= nodeLeft and nodeRight <= right:
        return rangeMin[node]
    mid = (nodeLeft+nodeRight)//2
    return min(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight))

N, M = map(int, input().split())
arr = [0]
for _ in range(N):
    number = int(input())
    arr.append(number)
rangeMin = [0]*4*N
init(0, N-1,1)

for _ in range(M):
    left, right = map(int,input().split())
    print(query(left-1, right-1, 1, 0, N-1))