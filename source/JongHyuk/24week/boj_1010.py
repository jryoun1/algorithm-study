'''
다리가 서로 가로지르는 배치는 있을수 없으므로,
강의 동쪽에 있는 사이트의 개수 중에서 서쪽에 있는 사이트의 갯수만큼
중복을 제외하고(어차피 갯수에 맞게끔 사이트의 수를 뽑아 놓으면 하나의 배치가 완성된다고 가정)
 뽑을 수 있는 갯수를 구하는 문제
'''
from sys import stdin
from math import factorial
tc=int(stdin.readline())

#리스트에서 조합을 뽑아 갯수를 세는 경우는 메모리 초과
# for _ in range(t):
#     N,M=map(int,stdin.readline().split())
#     tmp=[i for i in range(M)]
#     a=list(combinations(tmp,N))
#     print(len(a))

for _ in range(tc):
    west,east=map(int,stdin.readline().split())
    #조합 공식을 이용해 다리의 배치 경우의 수를 구한다
    print(factorial(east)//(factorial(west)*factorial(east-west)))
