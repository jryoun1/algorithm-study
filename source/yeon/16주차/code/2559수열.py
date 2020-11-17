# 백준 2559 수열 
# python solved by prefixSum
import sys
N, K = map(int,sys.stdin.readline().split())
temperatures = list(map(int,sys.stdin.readline().split()))
prefixSum = [0] * (N + 1)

for i in range(N):
    prefixSum[i+1] = prefixSum[i] + temperatures[i]

ans = [prefixSum[K]]
for i in range(K+1 ,N+1):
    ans.append(prefixSum[i] - prefixSum[i-K])
print(max(ans))