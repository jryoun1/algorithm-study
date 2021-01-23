# 백준 11505 구간 곱 구하기 
# python solved by segment Tree
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**4)
def init(left, right, node):
    if left == right:
        rangeMul[node] = arr[left+1]
        return rangeMul[node]
    mid = (left + right) // 2
    leftMul = init(left, mid, node*2)
    rightMul = init(mid+1, right, node*2+1)
    rangeMul[node] = leftMul * rightMul % 1000000007
    return rangeMul[node]

def query(left, right, node, nodeLeft, nodeRight):
    if right < nodeLeft or nodeRight < left:
        return 1
    if left <= nodeLeft and nodeRight <= right:
        return rangeMul[node]
    mid = (nodeLeft + nodeRight) // 2
    return query(left,right,node*2,nodeLeft,mid) * query(left, right, node*2+1, mid+1, nodeRight) % 1000000007

def update(index, newValue, node, nodeLeft, nodeRight):
    if index < nodeLeft or nodeRight < index:
        return rangeMul[node]
    if nodeLeft == nodeRight:
        rangeMul[node] = newValue
        return rangeMul[node]
    mid = (nodeLeft + nodeRight) // 2
    rangeMul[node] = update(index, newValue, node*2, nodeLeft, mid) * update(index, newValue, node*2+1, mid+1, nodeRight) % 1000000007
    return rangeMul[node]

N, M, K = map(int, input().split())
arr = [0]
for _ in range(N):
    number = int(input())
    arr.append(number)
rangeMul = [0]*4*N
init(0, N-1, 1)

for _ in range(M+K):
    case, left, right = map(int, input().split())
    if case == 1:
        update(left-1, right, 1, 0, N-1)
    else:
        print(query(left-1, right-1, 1, 0, N-1))
