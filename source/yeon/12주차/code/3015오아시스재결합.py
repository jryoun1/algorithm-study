# 백준 3015 오아시스 재결합
# python solved by stack
import sys
N = int(sys.stdin.readline())
arr = [int(sys.stdin.readline()) for _ in range(N)]
stack = []
HEIGHT, COUNT = 0, 1
ans = 0

for h in arr:
    # 스택이 비어있지 않고 스택의 top이 h보다 작은 경우에는
    # 전부 pop()해주고 해당 stack의 count를 ans에 더해준다. 
    while stack and stack[-1][HEIGHT] < h:
        ans += stack.pop()[COUNT]
    # 스택이 비어있는 경우에는 높이와, 개수를 넣어줌
    if not stack :
        stack.append((h,1))
    # 스택이 비어있지 않는 경우
    else:
        # 스택의 top의 높이가 h와 같은 경우
        if stack[-1][HEIGHT] == h:
            cnt = stack.pop()[COUNT]
            ans += cnt
            # 스택이 비어있지 않다면, 스택 내 제일 큰 사람과 쌍을 이루므로 ans += 1
            if stack:
                ans += 1
            stack.append((h, cnt+1))
        # 스택의 top의 높이가 h 보다 큰 경우
        # 이경우에는 스택 내 제일 큰 사람과 현재 키가 쌍을 이루기 때문에 ans += 1
        else:
            stack.append((h, 1))
            ans += 1
print(ans)
