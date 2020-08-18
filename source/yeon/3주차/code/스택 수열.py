def push(stack , i, Max):
    if(Max == 1): # 즉 아예 맨 처음 비어있는 경우 
        for a in range(Max, i+1):
            stack.push(a)
            print("+")
        Max = i
    else :
        for a in range (Max+1, i+1):
            stack.push(a)
            print("+")
        Max = i


num = int(input())
Max = 1
arr = []
stack = []
for i in range (0, num):
    n = input()
    arr.append(n)

print(arr)
print(arr.index('4'))
print(int(arr[0]))
for i in arr:
    index = stack.index(i)
    if index == -1: #만약 스택안에서 원소를 찾았는데 없는 경우
        push(stack,i, Max) # 해당 원소까지 다시 푸시
    else : 
        if i < Max and stack.index(Max) -1 > index : # 스택 안에서 원소를 찾았는데, 가장 큰 원소보다 작고 바로 전 인덱스가 아닌경우 구현 불가
            print("No")
            break
        else : 
            stack.pop()
            print("-")