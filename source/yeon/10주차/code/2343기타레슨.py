# 백준 2343 기타레슨 
# python solved by binary search

def binarySearch(low : int, high : int):
    while low <= high :
        mid = (low + high) // 2 
        cnt, tempSum = 0, 0
        # 하나씩 담아보면서 mid보다 큰 지 안 큰지 확인해보고
        # 크다면 블루레이 갯수를 추가시켜준다.
        for i in range(N):
            if tempSum + video[i] > mid :
                tempSum = 0
                cnt += 1
            tempSum += video[i]

        # for문을 다 돌고나서 마지막 tempSum이 0이 아닌경우는
        # 가정한 mid값보다 작기때문에 블루레이 갯수가 추가가 안된것이므로
        # 하나를 추가해준다.
        if tempSum != 0 : cnt += 1

        # 블루레이의 개수가 M과 비교하여 high와 low 값을 변경
        if cnt <= M:
            high = mid - 1
        else:
            low = mid + 1
    return low

N, M = map(int,input().split())
video = list(map(int,input().split()))
low, high = max(video), sum(video)
print(binarySearch(low, high))

