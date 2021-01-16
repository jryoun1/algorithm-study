from heapq import heappush, heappop
import sys
input = sys.stdin.readline
inf = sys.maxsize
def dijkstra(start):
    heap = []
    heappush(heap, [0, start])
    d = [inf for i in range(n + 1)]
    d[start] = 0
    while heap:
        we, ne = heappop(heap)
        for n_n, n_w in s[ne]:
            wei = n_w + we
            if d[n_n] > wei:
                d[n_n] = wei
                heappush(heap, [wei, n_n])
    return d
n = int(input())
s = [[] for i in range(n + 1)]
for i in range(1, n + 1):
    a = list(map(int, input().split()))
    for j in range(1, len(a), 2):
        if a[j] != -1:
            s[a[0]].append([a[j], a[j + 1]])
di = dijkstra(1)
print(max(dijkstra(di.index(max(di[1:])))[1:]))