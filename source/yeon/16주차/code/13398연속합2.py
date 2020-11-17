# 백준 13398 연속합 2
# python solved by prefixSum & dp
N = int(input())
numbers = list(map(int, input().split()))
prefixSum = [[0] * N for _ in range(2)]
prefixSum[0][0], prefixSum[1][0] = numbers[0], numbers[0]
for i in range(1, N):
    # [0][i]는 자기 자신을 뺀 누적합과, 더한 것 중 큰 것을 저장
    prefixSum[0][i] = max(prefixSum[1][i-1], prefixSum[0][i-1]+numbers[i])
    # [1][i]는 누적합들 중에서 큰 값을 저장 이때 이전 값들의 합이 -인 경우를 위해서 numbers[i]와 비교
    prefixSum[1][i] = max(prefixSum[1][i-1]+numbers[i], numbers[i])

print(prefixSum)

_max = -1001
for i in range(2):
    for j in range(N):
        if _max < prefixSum[i][j]:
            _max = prefixSum[i][j]
print(_max)