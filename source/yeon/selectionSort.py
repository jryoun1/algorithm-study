#프로그래머스 k번째 수 
#선택 정렬 함수
def selection_sort(object):
    min, temp = 0, 0
    for i in range(0,len(object)-1):
        min = i
        for j in range(i+1,len(object)):
            if object[j] < object[min] :
                min = j
        if i != min :
            temp = object[i]
            object[i] = object[min]
            object[min] = temp

def solution(array, commands):
    answer = []
    for i in commands :
        temp = array[i[0]-1:i[1]]
        selection_sort(temp) #temp.sort()사용해서 풀이가능 
        answer.append(temp.pop(i[2]-1))
    return answer

# Input Code for selection_sort 
    # if __name__ == "__main__":
#     selectionArray = list(map(int, input().split()))
#     selection_sort(selectionArray)
#     for i in selectionArray:
#         print(i, end = " ")