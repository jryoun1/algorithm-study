from heapq import heappush, heappop
import sys
input = sys.stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
cnt = 1
#한 노드에서 다른 노드로갈때 길이 하나로 정해져 있으므로,
#visit리스트를 사용하여 들렸던 곳은 재방문 하지 않는다.
def bfs():
    dp = [[100000000] * n for i in range(n)]
    dp[0][0] = s[0][0]
    visit = [[0] * n for i in range(n)]
    visit[0][0] = 1
    heap = []
    heappush(heap, [s[0][0], 0, 0])
    while heap:
        c, a, b = heappop(heap)
        for i in range(4):
            x = a + dx[i]
            y = b + dy[i]
            if 0 <= x < n and 0 <= y < n and visit[x][y]==0:
                if c+s[x][y]<dp[x][y]:
                    dp[x][y]=c+s[x][y]
                    heappush(heap, [dp[x][y], x, y])
                    visit[x][y] = 1
    return dp[n - 1][n - 1]
while True:
    n = int(input())
    if n == 0:
        break
    s = []
    for i in range(n):
        s.append(list(map(int, input().split())))
    result = bfs()
    print("Problem %d: %d" % (cnt, result))
    cnt += 1