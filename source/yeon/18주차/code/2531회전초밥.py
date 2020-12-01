# 백준 2531 회전초밥 
# python solved by
import sys 
N, d, k, c = map(int, sys.stdin.readline().split())
susi = list(int(sys.stdin.readline()) for _ in range(N))

def countSusi(susi_kind):
    cnt = set(susi_list)
    if c not in cnt:
        susi_kind = max(susi_kind, len(cnt)+1)
    else:
        susi_kind = max(susi_kind, len(cnt))
    return susi_kind

susi_list = susi[-k+1:] + susi[:1]
susi_kind = 0
susi_kind = countSusi(susi_kind)

for i in range(N-1):
    susi_list.pop(0)
    susi_list.append(susi[i+1])
    susi_kind = countSusi(susi_kind)

print(susi_kind)