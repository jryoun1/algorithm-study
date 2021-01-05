from sys import stdin
N=int(stdin.readline())
tree={}
class Node():
    def __init__(self,data,left,right):
        self.data=data
        self.left=left
        self.right=right

for _ in range(N):
    tmp=stdin.readline().split()
    tree[tmp[0]]=Node(tmp[0],tmp[1],tmp[2])

def preorder(node):
    print(node.data,end='')
    if node.left != '.':
        preorder(tree[node.left])
    if node.right != '.':
        preorder(tree[node.right])

def inorder(node):
    if node.left != '.':
        inorder(tree[node.left])
    print(node.data,end='')
    if node.right != '.':
        inorder(tree[node.right])

def postorder(node):
    if node.left != '.':
        postorder(tree[node.left])
    if node.right != '.':
        postorder(tree[node.right])
    print(node.data,end='')

preorder(tree['A'])
print()
inorder(tree['A'])
print()
postorder(tree['A'])
