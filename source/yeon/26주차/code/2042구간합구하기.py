# 백준 2042 구간 합 구하기
# python solved by segment Tree
import sys
input = sys.stdin.readline
def init(left, right, node):
    if left == right:
        rangeSum[node] = arr[left+1]
        return rangeSum[node]
    mid = (left + right) // 2
    leftSum = init(left, mid, node*2)
    rightSum = init(mid+1, right, node*2+1)
    rangeSum[node] = leftSum + rightSum
    return rangeSum[node]

def query(left, right, node, nodeLeft, nodeRight):
    if right < nodeLeft or nodeRight < left:
        return 0
    if left <= nodeLeft and nodeRight <= right:
        return rangeSum[node]
    mid = (nodeLeft + nodeRight) // 2
    return query(left, right, node*2, nodeLeft, mid) + query(left, right, node*2+1, mid+1, nodeRight)

def update(index, newValue, node, nodeLeft, nodeRight):
    if index < nodeLeft or nodeRight < index:
        return rangeSum[node]
    if nodeLeft == nodeRight:
        rangeSum[node] = newValue
        return rangeSum[node]
    mid = (nodeLeft + nodeRight) // 2
    rangeSum[node] = update(index, newValue, node*2, nodeLeft, mid) + update(index, newValue, node*2+1, mid+1, nodeRight)
    return rangeSum[node]

N, M, K = map(int, input().split())
arr = [0]
for _ in range(N):
    number = int(input())
    arr.append(number)
rangeSum = [0]*4*N
init(0, N-1, 1)

for _ in range(M+K):
    case, left, right = map(int, input().split())
    if case == 1:
        update(left-1, right, 1, 0, N - 1)
    else:
        print(query(left-1, right-1, 1, 0, N-1))