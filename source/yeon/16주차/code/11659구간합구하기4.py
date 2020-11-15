# 백준 11659 구간 합 구하기4
# python solved by prefix sum
import sys
N, M = map(int,sys.stdin.readline().split())
numbers = list(map(int,sys.stdin.readline().split()))
prefixSum = [0] * (N+1)
#구간 합을 미리 저장하는 배열 prefixSum
for i in range(N):
    prefixSum[i+1] = prefixSum[i] + numbers[i]

for _ in range(M):
    i, j = map(int,sys.stdin.readline().split())
    print(prefixSum[j] - prefixSum[i-1])
