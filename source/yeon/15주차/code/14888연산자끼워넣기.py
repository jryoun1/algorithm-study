# 백준 14888 연산자 끼워넣기
# python solved by dfs
N = int(input())
number = list(map(int,input().split()))
add, sub, mul, div = map(int,input().split()) # 차례대로 + - x % 의 개수 
_min, _max = 1e9, -1e9 # python에서 1e9 = 1*10^9 = 1000000000

def dfs(n, result, add, sub, mul, div):
    global _min, _max
    if N == n : 
        _max = max(result,_max)
        _min = min(result,_min)
    
    else:
        if add:
            dfs(n+1, result + number[n], add - 1, sub, mul, div)
        if sub:
            dfs(n+1, result - number[n], add, sub - 1, mul, div)
        if mul:
            dfs(n+1, result * number[n], add, sub, mul - 1, div)
        if div:
            dfs(n+1, int(result / number[n]), add, sub, mul, div - 1)

dfs(1,number[0],add,sub,mul,div)
print(_max)
print(_min)