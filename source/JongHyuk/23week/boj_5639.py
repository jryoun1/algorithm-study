import sys
sys.setrecursionlimit(100000)
class Node():
    def __init__(self,key):
        self.key=key
        self.left=None
        self.right=None

class bst:
    def __init__(self):
        self.root=None
    def insert(self,key):
        if self.root ==None:
            self.root=Node(key)
        else:
            current=self.root
            while True:
                if current.key>key:
                    if current.left==None:
                        current.left=Node(key)
                        break
                    current=current.left
                if current.key<key:
                    if current.right==None:
                        current.right=Node(key)
                        break
                    current=current.right
    def postorder(self):
        if self.root is not None:
            self._postorder(self.root)
    def _postorder(self,cur):
        if cur.left is not None:
            self._postorder(cur.left)
        if cur.right is not None:
            self._postorder(cur.right)
        print(cur.key)
tree=bst()
while True:
    try:
        key=int(input())
        tree.insert(key)
    except:
        break
tree.postorder()

