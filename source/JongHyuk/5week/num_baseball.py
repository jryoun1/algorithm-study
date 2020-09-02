from itertools import permutations

def is_ok(number,target,strike,ball):
    s=0
    b=0
    for i in range(3):
        if number[i]==target[i]:
            s+=1
        elif number[i] in target:
            b+=1
    if str(s)==strike and str(b)== ball:
        return True
    else:
        return False
        

allnum_lst=['1','2','3','4','5','6','7','8','9']
num_lst=list(map(''.join,permutations(allnum_lst,3)))
n=int(input())
for _ in range(n):
    target,strike,ball=input().split(' ')
    for number in num_lst[:]:
        if not is_ok(number,target,strike,ball):
            num_lst.remove(number)
print(len(num_lst))