#버블정렬
def bubble(list):
    for i in range(len(list)-1,0,-1):
        for j in range(0,i):
            if list[j]>=list[j+1]:
                list[j],list[j+1]=list[j+1],list[j]
    return list

#삽입정렬
def insert(list):
    for i in range(1,len(list)):
        index=i
        for j in range(i-1,-1,-1):
            if list[j]>=list[index]:
                list[j],list[index]=list[index],list[j]
                index=j
            else:
                break
    return list

#선택정렬
def selection(list):
    for i in range(1,len(list)):
        index = i-1
        for j in range(i,len(list)):
            if list[j]<list[index]:
                index=j
        tmp=list[index]
        list[index]=list[i-1]
        list[i-1]=tmp
    return list

def solution(array, commands):
    answer = []
    for c in commands:
        tmp=array[c[0]-1:c[1]]
        answer.append(tmp[c[2]-1])

    return answer


array=[1,5,2,6,3,7,4]
commands=[[2,5,3],[4,4,1],[1,7,3]]
print(solution(array,commands))