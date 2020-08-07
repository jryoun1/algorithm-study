def shell_sort(list):
    h=len(list)//2
    while h>0:
        for i in range(h):
            #간격동일 시작값 다르게 하기위한 for문
            first = i
            insert_sort(list,first,h)
        h=h//2


def insert_sort(list,first,h):
    index=first+h
    while index<=len(list)-1:
        position=index
        tmp=list[position]
        while list[position-h]>tmp and position>first:
            list[position]=list[position-h]
            position-=h
        list[position]=tmp
        index+=h\




print(shell_sort([9,8,7,6,5,5,4]))