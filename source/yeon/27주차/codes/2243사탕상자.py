# 백준 2243 사탕상자
# python 
import sys
input = sys.stdin.readline
maxNum = 1000100
def update(index, newValue, node, nodeLeft, nodeRight):
    if index < nodeLeft or nodeRight < index:
        return tree[node]
    if nodeLeft == nodeRight:
        tree[node] = newValue
        return tree[node]
    mid = (nodeLeft + nodeRight) // 2
    tree[node] = update(index, newValue, node*2, nodeLeft, mid) + update(index, newValue, node*2+1, mid+1, nodeRight) 
    return tree[node]

def kth(k, left, right, node):
    if left == right: # 리프 노드까지 내려오는 경우
        return left 
    mid = (left + right) // 2
    if tree[node * 2] >= k: # node*2번 노드가 현재 노드의 왼쪽 자식이므로 왼쪽 자식에 포함되는 경우
        return kth(k, left, mid, node*2)
    else: # 그렇지 않은 경우에는 오른쪽 자식에 포함되므로 k- tree[node*2]를 해주면 된다. 
        return kth(k-tree[node*2], mid+1, right, node*2+1) 

N = int(input())
tree = maxNum * 4 * [0]
candy = [0] * maxNum
for _ in range(N):
    a = list(map(int, input().split()))
    if a[0] == 1:
        b = a[1]
        flavor = kth(b, 0, maxNum-1, 1)
        print(flavor)
        candy[b] -= 1
        update(b, candy[b], 1, 0, maxNum-1)
    else:
        b, c = a[1], a[2]
        candy[b] += c
        update(b, candy[b], 1, 0, maxNum-1)
