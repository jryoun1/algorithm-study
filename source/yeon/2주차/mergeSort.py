#합병정렬 파이썬 코드
#분할하는 함수
def mergeSort(list):
    if len(list) <=1:
        return list
    mid = int(len(list)/2)

    #왼쪽부분 
    leftList = list[:mid]
    #오른쪽부분
    rightList = list[mid:]

    #재귀 -> 가장 왼쪽부터 분리될때까지 반복
    leftList = mergeSort(leftList)
    rightList = mergeSort(rightList)
    
    #합병
    return merge(leftList,rightList)
   
#정복 (합병) 하는 함수
def merge(leftList, rightList):
    sorted_arr = [] #합병한 정렬을 저장하는 배열
    while len(leftList) > 0 or len(rightList) > 0 :
        #왼쪽 리스트와 오른쪽 리스트 안에 둘다 원소가 있는 경우
        if len(leftList) > 0 and len(rightList) > 0 : 
            if leftList[0] <= rightList[0] :
                sorted_arr.append(leftList[0])
                leftList = leftList[1:]
            else:
                sorted_arr.append(rightList[0])
                rightList = rightList[1:]
        #왼쪽 리스트에만 원소가 남은 경우
        elif len(leftList) > 0 :
            sorted_arr.append(leftList[0])
            leftList = leftList[1:]
        #오른쪽 리스트에만 원소가 남은 경우
        elif len(rightList) > 0:
            sorted_arr.append(rightList[0])
            rightList = rightList[1:]
    return sorted_arr

if __name__ == "__main__":
    arr = list(map(int,input().split()))
    print(mergeSort(arr))

