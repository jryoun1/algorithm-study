def bubbleSort(object):
    for i in range(len(object)-1,-1,-1):
        temp = 0
        for j in range(0,i):
            if object[j] > object[j+1]:
                temp = object[j]
                object[j] = object[j+1]
                object[j+1] = temp

def solution(array, commands):
    answer = []
    for i in commands :
        temp = array[i[0]-1:i[1]]
        bubbleSort(temp)
        answer.append(temp.pop(i[2]-1))
    return answer

# Input Code for bubbleSort
# if __name__ == "__main__":
#     arr = list(map(int,input().split()))
#     bubbleSort(arr)
#     for i in arr:
#         print(i, end=" ")   