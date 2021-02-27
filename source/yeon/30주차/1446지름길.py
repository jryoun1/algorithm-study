# 백준 1446 지름길 
import sys
input = sys.stdin.readline

N, D = map(int, input().split())
short_cut = []
for _ in range(N):
    start, end, length = map(int, input().split())
    if end - start >= length and end <= D:
        short_cut.append([start, end, length])

distance = [i for i in range(D+1)]
for i in range(D+1):
    if i != 0:
        distance[i] = min(distance[i], distance[i-1] + 1)
    for j in short_cut:
        if j[0] == i:
            distance[j[1]] = min(distance[j[1]], distance[j[0]]+ j[2])

print(distance[D])