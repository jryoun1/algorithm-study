# 백준 11660 구간 합 구하기5
# python solved by prefix sum
import sys
N, M = map(int,sys.stdin.readline().split())
numbers = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
prefixSum = [[0] * (N+1) for _ in range(N+1)]
# 구간 합을 미리 저장하는 prefixSum 배열
for i in range(N):
    for j in range(N):
        prefixSum[i+1][j+1] = prefixSum[i][j+1] + prefixSum[i+1][j] - prefixSum[i][j] + numbers[i][j]

for _ in range(M):
    x1, y1, x2, y2 = map(int,sys.stdin.readline().split())
    ans = 0
    print(prefixSum[x2][y2] - prefixSum[x1-1][y2] - prefixSum[x2][y1-1] + prefixSum[x1-1][y1-1])