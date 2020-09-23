# 백준 10844 쉬운계단수
# python solved by dp
N = int(input())
MOD, _sum = 1000000000, 0

# assign 11x101 dp arr 
dp = [[0 for _ in range(11)]for _ in range(101)]

# in case of one digit
for i in range(1,10):
    dp[0][i] = 1

# we can find out that 
# dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]
for i in range(1,N+1):
    dp[i][0] = dp[i-1][1]
    dp[i][10] = 0
    for j in range(10):
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD

for i in range(10):
    _sum = (_sum + dp[N-1][i]) % MOD 
print(_sum)