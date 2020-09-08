# 백준 2503 숫자야구
# python solved by brute-force

N = int(input())
a, c = [], []

# baseball num can only be from 1-9 
# and it can't have same number in each digit
# so put possible baseball num in list[] a from 123 - 987
for i in range(123,988):
    if str(i)[0] == str(i)[1] or str(i)[1] == str(i)[2] or str(i)[0] == str(i)[2] or str(i)[1] == '0' or str(i)[2] == '0' :
        continue
    else : a.append(i)

for i in range(N):
    num, strike, ball = map(int,input().split())
    for result in a :
        s, b = 0, 0
        result_num = str(result)
        input_num = str(num)

        # compare result_num and input_num's digit whether it is strike or not
        if result_num[0] == input_num[0] : s += 1
        if result_num[1] == input_num[1] : s += 1
        if result_num[2] == input_num[2] : s += 1

        # compare result_num and input_num's digit whether it is ball or not
        if result_num[0] != input_num[0] and result_num[0] == input_num[1] or result_num[0] == input_num[2] : b += 1
        if result_num[1] != input_num[1] and result_num[1] == input_num[0] or result_num[1] == input_num[2] : b += 1
        if result_num[2] != input_num[2] and result_num[2] == input_num[0] or result_num[2] == input_num[1] : b += 1

        # if result_num has same strike and ball 
        # put it into list[] c
        if s == strike and b == ball:
            c.append(result)
    
    # by assign c to a
    # it can erase result_num 
    # which doesn't corresspond to input_num
    a = c
    c = []

print(len(a))

# from itertools import permutations
# arr = [1,2,3,4,5,6,7,8,9]
# possible = list(permutations(arr,3))
# cnt = 0

# def check(one:int, two:int, three:int, strike, ball):
#     global cnt
#     for i in possible[:]:
#         ns, nb = 0, 0
#         cnt += 1
#         n_one = i[0]
#         n_two = i[1]
#         n_three = i[2]
 
#         if n_one == one :
#             ns +=1
#         if n_two == two :
#             ns +=1
#         if n_three == three:
#             ns += 1
        
#         if one != n_one and (one == n_two or one == n_three) :
#             nb += 1
#         if two != n_two and (two == n_one or two == n_three) :
#             nb += 1
#         if three != n_three and (three == n_one or three == n_two) :
#             nb += 1
#         if (ns != strike or nb != ball):
#             possible.remove(i)
#             possible.insert(cnt,0)
            

# N = int(input())
# for i in range(N):
#     num, strike, ball = map(int,input().split())
#     num = str(num)
#     one, two, three = int(num[0]), int(num[1]), int(num[2])
#     check(one, two, three, strike, ball)

# while 0 in possible:
#     possible.remove(0)

# print(len(possible))


