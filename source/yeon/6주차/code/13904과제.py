# 백준 13904 과제
# python solved by Greedy algorithm + sort

N = int(input())
arr = [list(map(int,input().split())) for _ in range(N)]
result = []
sum,ans = 0,0
# range should be from 1-1000
for i in range(1000,0,-1):
	for j in range(N):
		if arr[j][0] == i:
			result.append(arr[j][1])
	result.sort()
	if result :
		ans = result.pop()
		sum += ans

print(sum)