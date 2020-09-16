
import sys
sys.setrecursionlimit(1000000)
def solve(n,x,y):
    if n==2:
        global res
        if x==r and y==c:
            print(res)
            return
        res+=1
        if x+1==r and y==c:
            print(res)
            return
        res+=1
        if x==r and y+1==c:
            print(res)
            return
        res+=1
        if x+1==r and y+1==c:
            print(res)
            return
        res+=1
        return
    solve(n/2,x,y)
    solve(n/2,x,y+n/2)
    solve(n/2,x+n/2,y)
    solve(n/2,x+n/2,y+n/2)
N,r,c=map(int,input().split(' '))
res=0
solve(2**N,0,0)