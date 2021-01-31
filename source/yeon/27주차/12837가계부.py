# 백준 12837 가계부
# python solved by segment Tree
import sys
input = sys.stdin.readline
def init(left, right, node):
    if left == right:
        rangeMoney[node] = arr[left+1]
        return rangeMoney[node]
    mid = (left + right) // 2
    leftMul = init(left, mid, node*2)
    rightMul = init(mid+1, right, node*2+1)
    rangeMoney[node] = leftMul + rightMul
    return rangeMoney[node]

def query(left, right, node, nodeLeft, nodeRight):
    if right < nodeLeft or nodeRight < left:
        return 0
    if left <= nodeLeft and nodeRight <= right:
        return rangeMoney[node]
    mid = (nodeLeft + nodeRight) // 2
    return query(left,right,node*2,nodeLeft,mid) + query(left, right, node*2+1, mid+1, nodeRight)

def update(index, newValue, node, nodeLeft, nodeRight):
    if index < nodeLeft or nodeRight < index:
        return rangeMoney[node]
    if nodeLeft == nodeRight:
        rangeMoney[node] += newValue
        return rangeMoney[node]
    mid = (nodeLeft + nodeRight) // 2
    rangeMoney[node] = update(index, newValue, node*2, nodeLeft, mid) + update(index, newValue, node*2+1, mid+1, nodeRight)
    return rangeMoney[node]

N, Q = map(int, input().split())
arr = [0] * (N+1)
rangeMoney = [0] * 4 * N
init(0, N-1, 1)
for _ in range(Q):
    case, a, b = map(int, input().split())
    if case == 1:
        update(a-1, b, 1, 0, N-1)
    else:
        print(query(a-1, b-1, 1, 0, N-1))