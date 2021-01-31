# 백준 5052 전화번호 목록
# python solved by Trie
import sys
input = sys.stdin.readline
class Node():
    def __init__(self, key, data = None):
        self.key = key
        self.data = data
        self.children = {}
		
class Trie():
    def __init__(self):
        self.head = Node(None)
		
    def insert(self, string):
        cur_node = self.head
        for chr in string:
            if chr not in cur_node.children: # 노드 순차적 검색하며 없으면 노드등록
                cur_node.children[chr] = Node(chr)	
            cur_node = cur_node.children[chr]	# 현재노드를 다음 문자의 노드로 변경
        cur_node.data = string	# 마지막 노드에는 문자열 전체 저장
		
    def search(self, string):
        cur_node = self.head
        for chr in string:
            cur_node = cur_node.children[chr]  # 현재노드를 다음문자로 변경하며 탐색
        if cur_node.children:
            return False
        else:
            return True

T = int(input())
for _ in range(T):
    N = int(input())
    t = Trie()
    number = []
    for _ in range(N):
        n = input().rstrip() # 문자열의 끝 삭제(공백)
        number.append(n)
        t.insert(n)
    result = True
    number.sort()
    for num in number:
        if not t.search(num):
            result = False
            break
    if result:
        print("YES")
    else: 
        print("NO")
