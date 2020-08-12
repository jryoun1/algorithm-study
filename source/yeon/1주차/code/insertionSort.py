#프로그래머스 k 번쨰 수
#삽입 정렬 함수
def insertionSort(object):
    arr_len = len(object)
    for i in range(1,arr_len): # 0번째 원소는 제외하고, 1번째 원소부터
        key,min = object[i],i
        while min > 0 and object[min-1]>key: #앞에 있는 원소들이랑 비교해서 key보다 크면
            object[min] = object[min-1] # 해당 값을 오른쪽으로 이동
            min -= 1
        object[min] = key 
            
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
