#백준 1018번 체스판 다시 칠하기
row, col = map(int, input().split())
arr = [list(input()) for _ in range(row)]
min_cnt = []

# 정답이 2가지 경우이기 때문에 2가지 경우에 대해서 비교시작
# 처음 위에 2개의 for문은 입력 받은 체스판에서 8x8을 비교해야하는 이동거리
for a in range(row - 7):
	for i in range(col - 7):
		b_cnt = 0 # 맨 처음이 BLACK인 경우와 비교했을 때 다른 것을 카운트
		w_cnt = 0 # 맨 처음이 WHITE인 경우와 비교했을 때 다른 것을 카운트
    # 안에 2개의 for문은 해당 원소부터 8x8을 비교하는 부분
		for b in range(a, a + 8):
			for j in range (i, i + 8):
        # 8x8의 정답 체스판을 보면 행과 열의 합이 홀수일때와 짝수일때의 값으로 비교가 가능
				if (b + j) % 2 == 0 :
					if arr[b][j] == 'W' : b_cnt += 1
					if arr[b][j] == 'B' : w_cnt += 1
				else :
					if arr[b][j] == 'B' : b_cnt += 1
					if arr[b][j] == 'W' : w_cnt += 1
		min_cnt.append(b_cnt)
		min_cnt.append(w_cnt)
		
print(min(min_cnt))
