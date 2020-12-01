from sys import stdin
import copy
N=int(stdin.readline())

for n in range(N):
    line=[int(x) for x in stdin.readline().split()]
    #첫 시작은 이전 dp배열이 없으므로 입력받은 line리스트를 그대로 dp배열에 넣어준다.
    if n==0:
        dpMax=copy.deepcopy(line)
        dpMin=copy.deepcopy(line)
    #dp를 max,min각각 갱신해 나간다.
    #메모리 제한 때문에 dp를 1행으로 유지하며 갱신시켜나간다.
    else:
        tmpMax=copy.deepcopy(dpMax)
        tmpMin=copy.deepcopy(dpMin)
    
        for i in range(3):
            #인덱스가 0일 때 dpMax는 바로 위의 행에서 인덱스가 0,1 에 해당하는 값들중 최대값+현재 행의 값으로 갱신시켜준다.
            #인덱스가 0일 때 dpMin은 바로 위의 행에서 인덱스가 0,1 에 해당하는 값들중 최소값+현재 행의 값으로 갱신시켜준다
            if i==0:
                dpMax[i]=max(tmpMax[i],tmpMax[i+1])+line[i]
                dpMin[i]=min(tmpMin[i],tmpMin[i+1])+line[i]
            elif i==1:
                dpMax[i]=max(tmpMax[i-1],max(tmpMax[i],tmpMax[i+1]))+line[i]
                dpMin[i]=min(tmpMin[i-1],min(tmpMin[i],tmpMin[i+1]))+line[i]
            else:
                dpMax[i]=max(tmpMax[i],tmpMax[i-1])+line[i]
                dpMin[i]=min(tmpMin[i],tmpMin[i-1])+line[i]

print(max(dpMax),min(dpMin))
            
