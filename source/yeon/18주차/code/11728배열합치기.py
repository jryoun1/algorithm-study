# 백준 11728 배열 합치기
# python solved by sort
import sys
N, M = map(int,sys.stdin.readline().split())
arrA = list(map(int,sys.stdin.readline().split()))
arrB = list(map(int,sys.stdin.readline().split()))
arrSum = sorted(arrA + arrB)
for num in arrSum:
    print(num,end=" ")
