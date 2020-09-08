def push(stack, i, index, max, answer):
    for j in range(index + 1, i + 1):
        stack.append(j)
        answer += "+\n"
    index = i
    comp.append(stack.pop())
    answer += "-\n"

    if len(stack) == 0: max = 0
    else : max = stack[-1]
    return stack, index, max, answer 

if __name__ == "__main__":
    arr = [] # 처음에 입력받는 배열
    comp = [] # pop에서 나오는 숫자들을 저장했다가 나중에 arr와 비교하기 위한 배열 
    stack = [] # 입력받은 배열을 순차적으로 넣었다가 빼보면서 가능한지 해보는 배열 
    answer = "" # +, - 를 저장하여 출력하기 위한 변수 
    max = 0 # 현재 stack 리스트에서의 가장 마지막에 있는 변수
    index = 0 # stack 리스트에 들어왔던 숫자들 중 가장 큰 수를 기억하기 위한 변수 
    
    num = int(input())
    for i in range (0, num):
        n = int(input())
        arr.append(n)
    
    # 사용자로부터 입력 받은 배열의 값을 가지고 for문을 돌림
    for i in arr:
        # stack의 길이가 0 인 경우 
        # 1. 아예 맨 처음에 비어있는 상태인 경우 
        # 2. 원소들이 들어왔다가 pop으로 인해서 빠져나가는 경우
        if i > max :
            stack, index, max, answer = push(stack,i,index,max,answer)
        # 현재 stack 안에 있는 max 값이 arr의 해당 원소보다 큰 경우 
        # 즉, stack 리스트 안에 i 값이 있는 경우  
        elif i <= max:
                comp.append(stack.pop())
                answer = answer + "-\n"
                if len(stack) == 0: max = 0
                else : max = stack[-1]

    if comp != arr:
        print("NO")
    else : 
        print(answer)
