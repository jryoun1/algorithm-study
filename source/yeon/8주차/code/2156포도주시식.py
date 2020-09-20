# 백준 2156 포도주 시식
# python solved by dp
N = int(input())
dp = [0]*(N+2)
arr = [0]+[int(input()) for _ in range(N)] + [0]
dp[1], dp[2] = arr[1], arr[1] + arr[2]

# there can be 3 cases
# 1. if not drink N's wine => dp[n] = dp[n-1]
# 2. if drink N's wine and it's first wine => dp[n] = dp[n-2] + arr[n]
# 3. if drink N's wine and it's second wine => dp[n] = dp[n-3] + arr[n-1] + arr[n]
# So find the max value from those three case and save dp[n]
for i in range(3,N+1):
    dp[i] = max(dp[i-1],max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i]))
    
print(dp[N])