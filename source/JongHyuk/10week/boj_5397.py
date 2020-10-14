from collections import deque

for _ in range(int(input())): ## 테스트 케이스
    ## front, back 이름을 갖는 deque객체 만들기
    front = deque()
    back = deque()

    for item in input():
        ## '<' 입력 받을 경우
        ## front가 비어있다면 아무일도 일어나지 않는다.
        ## 그렇지 않다면 front[-1]값을 back[0]에 추가한다.
        if item == '<':
            if front:
                back.appendleft(front.pop())
        ## '>' 입력 받을 경우
        ## back이 비어있다면 아무일도 일어나지 않는다.
        ## 그렇지 않다면 back[0]값을 front[-1]에 추가한다.
        elif item == '>':
            if back:
                front.append(back.popleft())
        ## '-'를 입력 받을 경우
        ## front가 비어있지 않을 경우, front[-1]을 제거한다.
        elif item == '-':
            if front:
                front.pop()
        ## 그 외, 문자를 입력받는 경우
        ## front[-1]에 추가
        else:
            front.append(item)
    ## front와 back 배열 합치기
    front.extend(back)
    ## print
    print(''.join(front))
