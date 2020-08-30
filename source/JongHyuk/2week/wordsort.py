#단어정렬
N=int(input())
word_list=[]
li=[]
for i in range(N):
    word_list.append(input())

word_list=sorted(word_list)
word_list=sorted(word_list,key=lambda x:len(x))
for i in word_list:
    if i not in li:
        li.append(i)
    else:
        continue
    print(i)


