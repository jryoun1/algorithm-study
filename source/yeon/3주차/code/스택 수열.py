def push(stack , i, Max, answer, cnt):
    # 맨 처음 비어있는 경우에 그만큼 넣어주고 바로 pop을 해주면 됨  
    if(Max == 1): 
        for a in range(1, i+1):
            stack.append(a)
            answer = answer + "+\n"
        comp_arr.append(stack.pop())
        answer = answer + "-\n"
        if len(stack) == 0:
            Max = 0
        else :
            Max = stack[-1]
        cnt = i
    # stack이 비어있지 않고 안에 원소들이 있는 경우에는 
    # cnt(들어왔던 숫자들 중에서 가장 큰 수)보다 1큰 수 부터 i 까지 넣어주면 된다.
    else :
        for a in range (cnt+1, i+1):
            stack.append(a)
            answer = answer + "+\n"
        comp_arr.append(stack.pop())
        answer = answer + "-\n"
        if len(stack) == 0:
            Max = 0
        else :
            Max = stack[-1]
        cnt = i 
        
    return stack, Max, answer, cnt
    
if __name__ == "__main__":
    arr = [] # 처음에 입력받는 배열
    comp_arr = [] # pop에서 나오는 숫자들을 저장했다가 나중에 arr와 비교하기 위한 배열 
    stack = [] # 입력받은 배열을 순차적으로 넣었다가 빼보면서 가능한지 해보는 배열 
    answer = "" # +, - 를 저장하여 출력하기 위한 변수 
    Max = 1 # 현재 stack 리스트에서의 가장 마지막에 있는 변수
    cnt = 0 # stack 리스트에 들어왔던 숫자들 중 가장 큰 수를 기억하기 위한 변수 
    
    num = int(input())
    for i in range (0, num):
        n = int(input())
        arr.append(n)
    
    # 사용자로부터 입력 받은 배열의 값을 가지고 for문을 돌림
    for i in arr:
        # stack의 길이가 0 인 경우 
        # 1. 아예 맨 처음에 비어있는 상태인 경우 
        # 2. 원소들이 들어왔다가 pop으로 인해서 빠져나가는 경우 
        if len(stack) == 0:
        	stack , Max, answer, cnt = push(stack, i, Max, answer, cnt)
        # 현재 stack 안에 있는 Max 값이 arr의 해당 원소보다 큰 경우 
        # 즉, stack 리스트 안에 i 값이 있는 경우  
        elif Max > i:
            # 만약 i의 인덱스가 Max의 인덱스와 차이가 1인 경우 pop을 할 수 있음 
            # 하지만 여기서 4,3의 순으로 pop을 해야하지만 3,4 인경우에도 아래의 if 문을 통과 해버리는 예외 상황 발생 (백준 2번째 입력) 
            # comp_arr에 pop한 원소들을 넣어서 arr 와 비교해서 일치하는 경우만 출력하도록 해결
            if stack.index(i) + 1 == stack.index(Max):
                comp_arr.append(stack.pop())
                Max = stack[-1]
                answer = answer + "-\n"
        # 만약 Max와 i 값이 같으면 그대로 pop해주면 된다.
        elif Max == i :
            comp_arr.append(stack.pop())
            if len(stack) == 0:
                Max = 0
            else :
                Max = stack[-1]
            answer = answer + "-\n"
        # Max가 i 보다 작은 경우
        # 즉, 새롭게 push가 되어야하는 상황 
        elif Max < i :
        	stack , Max, answer, cnt = push(stack, i, Max, answer, cnt)
            
    if comp_arr != arr:
        print("NO")
    else : 
        print(answer)