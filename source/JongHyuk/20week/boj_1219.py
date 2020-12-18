# from sys import stdin
# from collections import deque
# N,s,e,M=map(int,stdin.readline().split())
# graph=[[] for _ in range(N)]
# for _ in range(M):
#     start,end,cost=map(int,stdin.readline().split())
#     if end==start:
#         graph[start].append([end,0])
#     else:
#         graph[start].append([end,-cost])
# earn=list(map(int,stdin.readline().split()))

# for i in range(N):
#     for j in range(len(graph[i])):
#         graph[i][j][1]+=earn[graph[i][j][0]]
# def is_gg(s,e):
#     q=deque()
#     q.append(s)
#     flag=True
#     visit[s]=True
#     if s==e:
#         return False
#     while q:
#         s=q.popleft()
#         for target,c in graph[s]:
#             if visit[target] == False:
#                 q.append(target)
#                 visit[target]=True
#                 if target == e:
#                     flag=False
#     return flag


# def bellman():
#     for i in range(N):
#         for j in range(N):
#             for target, cost in graph[j]:
#                 if shortest_route[j] != -float('inf') and shortest_route[target]<cost+shortest_route[j]:
#                     shortest_route[target]=cost+shortest_route[j]
#                     if i==N-1:


# visit=[False for _ in range(N)]
# shortest_route=[float('inf') for _ in range(N)]
# if is_gg(s,e):
#     print('gg')
# else:
#     if s==e:

#     shortest_route[s]=earn[s]
#     if bellman():
#         print(shortest_route[e])

            