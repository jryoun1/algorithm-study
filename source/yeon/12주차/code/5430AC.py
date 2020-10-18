# 백준 5430 AC
# python solved by deque
from collections import defaultdict
from collections import deque
T = int(input())
for _ in range(T):
    p = input()
    # D의 개수와 R의 개수를 편하게 세기 위해서 defaultDict사용
    p_count = defaultdict(int)
    for func in p:
        p_count[func] += 1
    
    n = int(input())
    arr = input()
    # []와 , 제거하기 
    arr = arr.replace('[','').replace(']','').split(',')
    # 길이가 0 이 아닐 때만 deque에 넣어주기
    if n > 0:
        dq_arr = deque(map(int,arr))
    # 실제로 reverse를 하지 않기 위해서 선언한 bool 변수 
    R = False

    if p_count['D'] > n :
        print("error")
    elif p_count['D'] == n :
        print([])
    else:
        for i in range(len(p)):
            # 평상시 상태이다가 R이 처음 나오는 경우 
            if p[i] == 'R' and R == False:
                R = True
            # Reverse 되어있는 상태에서 R이 나온 경우
            elif p[i] == 'R' and R == True:
                R = False
            # D 가 나오는 경우
            else:
                # R이 True이면 Reverse 되었기때문에 pop()으로 삭제
                if R == True :
                    dq_arr.pop()
                # R이 False이면 원래 상태이므로 popleft()으로 삭제
                else :
                    dq_arr.popleft()

        # 마지막 출력전에 R의 개수가 홀수면 reverse하여 출력해주어야함
        if p_count['R'] % 2 == 1 :
            dq_arr.reverse()
        print('[',end="")
        print(','.join(map(str,dq_arr)),end="")
        print(']',end="\n")
