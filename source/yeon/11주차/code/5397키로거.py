# 백준 5397 키로거
# python solved by 
N = int(input())
for i in range(N):
    beforeCursor, afterCursor = [], []
    keylogger = input()

    for i in range(len(keylogger)):    
        if keylogger[i] == '<':
            if beforeCursor:
                afterCursor.append(beforeCursor.pop())

        elif keylogger[i] == '>':
            if afterCursor:
                beforeCursor.append(afterCursor.pop())
        
        elif keylogger[i] == '-':
            if beforeCursor:
                beforeCursor.pop()
        else:
            beforeCursor.append(keylogger[i])
    beforeCursor.extend(reversed(afterCursor))
    print(''.join(beforeCursor))