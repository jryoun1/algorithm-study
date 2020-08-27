def bucket_sort(num):
    # 버킷을 담을 비어 있는 list를 하나 생성한다
    arr = [[] for _ in range(len(num))]

    # 버킷에다 각각 elements들을 넣는다
    # ex. 0.78 * 10 = 7.8
    # int(7.8)을 해서 arr[7] 버킷에 해당 값을 넣는다
    for n in num: 
        index = int(len(num) * n)  
        arr[index].append(n) 
    
    # 각 sub list들을 정렬한다
    for i in range(len(num)):
        arr[i].sort()

    # 각 버킷들을 연결한다
    k = 0
    for i in range(len(num)):
        for j in range(len(arr[i])):
            num[k] = arr[i][j]
            k += 1
            
    return num

number = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68] 
print(number)
bucket = bucket_sort(number)
print(bucket)