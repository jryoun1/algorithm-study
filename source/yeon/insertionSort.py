#프로그래머스 k 번쨰 수
#삽입 정렬 함수
def insertionSort(object):
    arr_len = len(object)
    for i in range(1,arr_len): # 0번째 원소는 제외하고, 1번째 원소부터
        min,temp = i, 0
        for j in range(i-1, -1, -1): # 0번째 원소까지 비교하고 작으면 교체 
            if object[min] < object[j]:
                temp = object[min]
                object[min] = object[j]
                object[j] = temp
                min = j 
            
def solution(array, commands):
    answer = []
    for i in commands :
        temp = array[i[0]-1:i[1]]
        insertionSort(temp)
        answer.append(temp.pop(i[2]-1))
    return answer

# if __name__ == "__main__":
#     arr = list(map(int,input().split()))
#     insertionSort(arr)
#     for i in arr:
#         print(i, end = " ")
