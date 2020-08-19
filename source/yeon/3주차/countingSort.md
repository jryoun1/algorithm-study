def push(stack , i, Max, answer, cnt):
    if(Max == 1): # 즉 아예 맨 처음 비어있는 경우 
        for a in range(1, i+1):
            stack.append(a)
            answer = answer + "+\n"
        print(stack.pop())
        answer = answer + "-\n"
        Max = stack[-1]
        cnt = i

    else :
        for a in range (cnt+1, i+1):
            stack.append(a)
            answer = answer + "+\n"
        print(stack.pop())
        answer = answer + "-\n"
        Max = stack[-1]
        cnt = i 
        
    return stack, Max, answer, cnt
    
if __name__ == "__main__":
    num = int(input())
    arr = []
    stack = []
    answer = ""
    Max = 1
    cnt = 0
    
    for i in range (0, num):
        n = int(input())
        arr.append(n)
        
    for i in arr:
        if len(stack) == 0:
        	stack , Max, answer, cnt = push(stack, i, Max, answer, cnt)
        elif Max > i:
            if stack.index(i) + 1 == stack.index(Max):
                print(stack.pop())
                Max = stack[-1]
                answer = answer + "-\n"
            else : 
                answer = answer + "N\n"
        elif Max == i :
        	print(stack.pop())
        	Max = stack[-1]
        	answer = answer + "-\n"
        elif Max < i :
        	stack , Max, answer, cnt = push(stack, i, Max, answer, cnt)
            
    if answer.find("N") != -1 :
        print("NO")
    else : 
        print(answer)