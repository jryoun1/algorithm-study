# 백준 17298 오큰수
# python solved by stack
N = int(input())
arr = list(map(int,input().split()))
# 스택은 처음에 index 0 이 들어갈 것이므로 0을 미리 넣어줌
# ans 같은 경우에는 stack에 남아있는 애들은 전부 -1일 것이므로 미리 -1로 초기화
stack, ans = [0],[-1]*N

for i in range(N):
    # 만약 스택이 비어있다면 stack에 i 추가
	if not stack:
		stack.append(i)
	# stack 안에 원소가 있고 arr[stack.top()] 이 arr[i] 보다 작은 경우
    # 해당 원소는 arr[i]가 오큰수 이므로 ans에 저장하고 stack에서 pop() 
	while stack and arr[stack[-1]] < arr[i]:
		ans[stack[-1]] = arr[i]
		stack.pop()
	stack.append(i)

# 스택에 남아있는 원소들은 오큰수가 없는 것이므로 -1을 넣어줌
while stack:
	ans[stack[-1]] = -1
	stack.pop()

print(' '.join(map(str,ans)))