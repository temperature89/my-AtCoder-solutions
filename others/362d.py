import heapq
N, M = map(int, input().split())
A = list(map(int, input().split()))

G = [[] for n in range(N)]
for m in range(M):
    u, v, b = map(int, input().split())
    u -= 1
    v -= 1
    G[u].append((v, b))
    G[v].append((u, b))

inf = float('inf')

D[]