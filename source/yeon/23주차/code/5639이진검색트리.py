# 백준 5639 이진 검색 트리
# python solved by tree
# import sys
# input = sys.stdin.readline
# class Node:
#     def __init__(self, data):
#         self.data = data
#         self.left = None
#         self.right = None

#     def insert(self, data):
#         if self.data:
#             if data < self.data:
#                 if self.left is None:
#                     self.left = Node(data)
#                 else:
#                     self.left.insert(data)
#             elif data > self.data:
#                 if self.right is None:
#                     self.right = Node(data)
#                 else:
#                     self.right.insert(data)
#         else:
#             self.data = data
    
#     def postorderPrint(self):
#         if self.left:
#             self.left.postorderPrint()
#         if self.right:
#             self.right.postorderPrint()
#         print(self.data)

# count = 0
# while True:
#     if count == 0:
#         rootNumber = int(input())
#         root = Node(rootNumber)
#         count += 1
#     else:
#         try:
#             number = int(input())
#             root.insert(number)
#         except:
#             break
# root.postorderPrint()

# 백준 5639 이진 검색 트리
# python solved by 분할정복 & recursive
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

def postorder(start, end):
    if start > end:
        return
    divide = end + 1
    for i in range(start+1, end+1):
        if post[start] < post[i]:
            divide = i
            break
    postorder(start+1, divide-1)
    postorder(divide, end)
    print(post[start])

post = []
while True:
    try: 
        number = int(input())
        post.append(number)
    except:
        break
postorder(0, len(post)-1)