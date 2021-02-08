# 백준 1931 회의실 배정
# python
import sys
input = sys.stdin.readline
N = int(input())
lecture = []
for _ in range(N):
    start, end = map(int, input().split())
    lecture.append([start, end])

sorted_lecture = sorted(lecture, key = lambda x: (x[1], x[0]))
count = 1
endTime = sorted_lecture[0][1]
for i in range(N-1):
    if endTime <= sorted_lecture[i+1][0]:
        endTime = sorted_lecture[i+1][1]
        count += 1
print(count)