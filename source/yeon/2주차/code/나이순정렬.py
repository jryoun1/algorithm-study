#백준 10814 나이순 정렬
if __name__ == "__main__":
    num = int(input())
    arr = []
    
    #사용자로부터 입력 받음 
    for i in range(0,num): 
        n, name = input().split()
        arr.append([int(n),name])

    #입력받은 배열을 정렬하는데 먼저 x[0] : 나이를 기준으로 정렬 하고, 나이가 같으면 x[2] : index를 기준으로 비교하여 정렬
    #python의 sort, sorted는 안정적 정렬임
    arr.sort(key=lambda x: x[0])
    #arr.sort(key=lambda x: (x[0],x[2]))
    
    for n,name in arr:
        print(n,name)
    
