# 백준 2098 외판원 순회
# python solved by dp & bitmask & dfs
import sys
sys.setrecursionlimit(10000)
# set INFINITE VALUE
INF = sys.maxsize
N = int(input())
arr = [list(map(int,input().split())) for _ in range(N)]
dp = [[INF] * (1 << N) for _ in range(N)]

def dfs(cur, visit):
    # if it has visited every case
    if visit == (1 << N) -1 :
        # if there's no way to 0 return INF
        if arr[cur][0] == 0 :
            return INF
        # if there's way to 0 return cur-> 0 cost
        else :
            return arr[cur][0]
    
    # if dp already has calculated value
    # use saved value 
    if dp[cur][visit] != INF:
        return dp[cur][visit]
    
    for i in range(1, N):
        # 앞의 조건은 지금까지 방문한 것과 도시중에서 방문하지 않은 곳이 있다면 0
        # 그리고 그 도시가 0이 아니라면 방문을 하는 것이다 (cur -> i 로 가는 길이 있다면)
        if visit&(1 << i) == 0 and arr[cur][i] != 0:
            dp[cur][visit] = min(dp[cur][visit], dfs(i,visit|(1 << i)) + arr[cur][i])
    return dp[cur][visit]

print(dfs(0,1))

# 2193 이친수 
# N = int(input())
# dp = [[0 for _ in range(2)] for _ in range(N)]
# dp[0][0] ,dp[0][1] = 0, 1 
# for i in range(1,N):
#     dp[i][0] = dp[i-1][0] + dp[i-1][1]
#     dp[i][1] = dp[i-1][0]
# print(dp[N-1][0]+dp[N-1][1])


# 1149 RGB 거리
# import sys
# N = int(input())
# cost = [[int(i) for i in sys.stdin.readline().split()] for _ in range(N)]
# dp = [[0 for _ in range(3)] for _ in range(N)]
# dp[0][0], dp[0][1], dp[0][2] = cost[0][0], cost[0][1], cost[0][2]
# for i in range(1,N):
#     for j in range(3):
#         if j == 0: choice = min(dp[i-1][j+1],dp[i-1][j+2])
#         elif j== 1: choice = min(dp[i-1][j-1],dp[i-1][j+1])
#         else : choice = min(dp[i-1][j-1],dp[i-1][j-2])
#         dp[i][j] = cost[i][j] + choice 

# print(min(dp[N-1]))


# 1932 정수 삼각형 
# N = int(input())
# arr = []
# for _ in range(N):
#     num = list(map(int,input().split()))
#     arr.append(num)
# dp = [[0 for _ in range(N+1)] for _ in range(N)]
# dp[0][1] = arr[0][0]
# for i in range(1,N):
#     for j in range(1,len(arr[i])+1):
#         dp[i][j] = arr[i][j-1] + max(dp[i-1][j-1], dp[i-1][j])
# print(max(dp[N-1]))