#백준1181_단어정렬 
import time
start = time.time()

if __name__ == "__main__":
    num = int(input())
    word_map =[]
    for i in range(num):
        word_map.append(input())
    #set으로 만들어주어서 list에서 중복되는 값들을 unique하게 만들어줌 
    word_set = set(word_map)
    #다시 set에서 list로 변환
    word_map = list(word_set)
    #먼저 길이로 정렬하고 같은 경우, 단어순으로 정렬하도록 lambda식 사용
    word_map.sort(key = lambda x:(len(x),x))
    for i in word_map:
        print(i)

print("time : ",time.time()-start) #단위는 초 