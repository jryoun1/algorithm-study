from collections import Counter
def assignment():
    index=[]
    _max=0
    res=0
    for i in range(_assignment[0][0],0,-1):
        for j in range (len(_assignment)):
            if _assignment[j][0]>=i:
                if _max<_assignment[j][1]:
                    _max=_assignment[j][1]
                    index=j
            else:
                break
            print(i,j,_assignment[j][0],_assignment[j][1])
        print(res)
        if _max !=0:
            res+=_assignment[index][1]
            del _assignment[index]
        _max=0
        
    return res
    



N=int(input())
_assignment=[]
for _ in range(N):
    _assignment.append(list(map(int,input().split(' '))))
_assignment.sort(reverse=True)
print(_assignment)
print(assignment())