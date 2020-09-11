# 백준 1992 쿼드트리
# python solved by recursive + divide and conquer
N = int(input())
arr = list(input() for _ in range(N))

def quadTree(x,y,n):
	# if there's only one elemnet to see 
	if n == 1: 
		return arr[x][y]
	
	result = []
	for i in range(x,x+n):
		for j in range(y,y+n):
			# if it has different element in range
			if arr[i][j] != arr[x][y]:
				# difference between append and extend
				# append just put itself as an element 
				# extend put most outside part of iterable in tuple, dic, list 
				result.append('(')
				result.extend(quadTree(x,y,n//2))
				result.extend(quadTree(x,y+n//2,n//2))
				result.extend(quadTree(x+n//2,y,n//2))
				result.extend(quadTree(x+n//2,y+n//2,n//2))
				result.append(')')
				
				return result
	
	return arr[x][y]
	
print(''.join(quadTree(0,0,N)))