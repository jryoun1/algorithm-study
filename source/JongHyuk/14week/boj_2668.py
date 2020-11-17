from sys import stdin
N=int(stdin.readline())
arr=[0]
for _ in range(N):
    arr.append(int(stdin.readline()))

#방문 여부를 체크할 리스트
visited=[0 for _ in range(N+1)]
#정답의 총 갯수를 저장할 변수
cnt=0

for i in range(1,N+1):
    tmp=i
    visit=[]
    #임시적으로 방문을 체크할 리스트
    tmp_visited=[0 for _ in range(N+1)]
    start_index=i
    if visited[i]==0:
        while True:
            #방문하지 않은 지점일 시에
            if tmp_visited[tmp]==0:
                tmp_visited[tmp]=1
                visit.append(tmp)
                tmp=arr[tmp]
            else:
                #시작점을 기준으로 써클이 형성 되었을떄
                if start_index==tmp:
                    for v in visit:
                        visited[v]=1
                        cnt+=1
                    break
                #써클이 형성되었지만 시작점 기준이 아닐때에는 pass
                #for문으로 모든 점을 순회하기 때문에
                break

print(cnt)
for i in range(1,N+1):
    if visited[i]==1:
        print(i)
        

        

