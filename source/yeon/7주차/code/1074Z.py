# 백준 1074번 Z 
# python solved by divide and conquer
N, r, c = map(int,input().split())
ans = 0

def solution(y:int, x:int, n: int):
    global ans
    if y == r and x == c : 
        print(ans) 
        return 
    
    # find the location of r,c 
    # if they are in boundary divide 
    # not in booundary just add n*n 
    if y <= r < y + n and x <= c < x + n :
        solution(y, x, n // 2)
        solution(y, x+n//2, n//2)
        solution(y+n//2, x, n//2)
        solution(y+n//2, x+n//2, n//2)
    else :
        ans += n * n 
        
solution(0,0,1<<N)
