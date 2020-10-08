# 백준 3020 개똥벌레
# python solved by dp 
import sys
N, H = map(int,sys.stdin.readline().split())
fromUp = [0 for _ in range(H+1)] #even
fromDown = [0 for _ in range(H+1)] #odd
_sum = [500001]+[0 for _ in range(H)]

for i in range(1, N+1):
    n = int(sys.stdin.readline())
    if i % 2 == 0:
        fromUp[n] += 1
    else:
        fromDown[H - n + 1] += 1

# 아래에서부터 자라는 석순은 큰 숫자보다 아래 숫자일수록 부셔야하는 벽이 많음
# 따라서 i 번째 일때 i+1번째 것까지 더해야함
for i in range(H - 1, 0, -1):
    fromUp[i] += fromUp[i+1]
# 위에서부터 자라는 종유석의 높이를 H - n + 1 로 계산했기 때문에
# 작은 높이일수록 부셔야하는 벽이 적고 큰 숫자일 수록 부셔야하는 벽이 많음
# 따라서 i 번째일 때 i-1번째 벽의 개수를 더해주어야함
for i in range(2, H + 1):
    fromDown[i] += fromDown[i-1]

for i in range(1, H + 1):
    _sum[i] = fromUp[i] + fromDown[i]

ans = min(_sum)
print(ans,_sum.count(ans))


# import sys
# N, H = map(int,sys.stdin.readline().split())
# fromUp = [0 for _ in range(H+1)] #even
# fromDown = [0 for _ in range(H+1)] #odd
# _sum = [500001]+[0 for _ in range(H)]

# for i in range(1, N+1):
#     n = int(sys.stdin.readline())
#     if i % 2 == 0:
#         for j in range(1,n+1):
#             fromUp[j] += 1
#     else:
#         for j in range(1,n+1):
#             fromDown[j] += 1

# _sum[1] = fromDown[1]
# _sum[H] = fromUp[1]
# for i in range(2, H):
#     _sum[i] = fromUp[i] + fromDown[H + 1 -i]

# ans = min(_sum)
# print(ans,_sum.count(ans))