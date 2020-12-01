from sys import stdin
N,d,k,c=map(int,stdin.readline().split())
fish=[]
for _ in range(N):
    fish.append(int(stdin.readline()))
fish=fish+fish
eat_check=[0 for _ in range(d+2)]
kind=0
#첫번째 초밥 묶음을 계산한다.
#먹은 종류의 초밥을 count해줄 eat_check리스트를 초밥 종류만큼 만들고 0으로 세팅한 뒤,
#해당 종류의 초밥이 나올때 마다 갯수를 증가시켜준다.
#만약 해당 초밥묶음에서 쿠폰에 적힌 번호의 초밥이 포함되지 않는경우에,
#_max값을 갱신시켜줄때, 쿠폰에 적힌 번호의 초밥을 더해주면서 갱신한다.
for i in range(k):
    if eat_check[fish[i]]==0:
        kind+=1
        eat_check[fish[i]]+=1
    else:
        eat_check[fish[i]]+=1
_max=0
if eat_check[c]==0:
    _max=max(_max,kind+1)
else:
    _max=max(_max,kind)

#슬라이딩 윈도우 기법을 사용
for i in range(k,N+k):
    #빼줘야 할 초밥의 check를 1 감소 시켜주고,
    eat_check[fish[i-k]]-=1
    #빼준 초밥의 check가 0이면 kind에서 1 감소시킨다.
    if eat_check[fish[i-k]]==0:
        kind-=1
    #더해줄 초밥의 check가 0이면 kind와 해당 초밥의 check를 1씩 증가
    if eat_check[fish[i]]==0:
        kind+=1
        eat_check[fish[i]]+=1
    #0ㅇ아니면 단순히 check만 증가시켜줌
    else:
        eat_check[fish[i]]+=1
    #쿠폰에 적힌 초밥의 포함 여부에따라 _max값을 다르게 갱신시킨다.
    if eat_check[c]==0:
        _max=max(_max,kind+1)
    else:
        _max=max(_max,kind)
    # if _max==k+1:
    #     break
print(_max)





