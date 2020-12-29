# 백준 1991번 트리 순회
# python solved by 
import sys
input = sys.stdin.readline
class Node:
    def __init__(self, data, left, right):
        self.left = left
        self.right = right
        self.data = data
    def printTree(self):
        print(self.data)

def preorder(node):
    print(node.data, end="")
    if node.left != '.':
        preorder(tree[node.left])
    if node.right != '.':
        preorder(tree[node.right])

def inorder(node):
    if node.left != '.':
        inorder(tree[node.left])
    print(node.data, end="")
    if node.right != '.':
        inorder(tree[node.right])

def postorder(node):
    if node.left != '.':
        postorder(tree[node.left])
    if node.right != '.':
        postorder(tree[node.right])
    print(node.data, end="")
    

N = int(input())
tree = {}
for _ in range(N):
    root, left, right = map(str, input().split())
    tree[root] = Node(data = root, left = left, right = right)

preorder(tree["A"])
print()
inorder(tree["A"])
print()
postorder(tree["A"])
print()