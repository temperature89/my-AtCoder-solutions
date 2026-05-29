N, M, Q = map(int, input().split())
graph = [[] for i in range(N)]
for m in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    graph[u].append(v)
    graph[v].append(u)
C = list(map(int, input().split()))

for q in range(Q):
    s = list(map(int, input().split()))
    s[1] -= 1
    color = C[s[1]]
    print(color)
    if s[0] == 1:
        for i in graph[s[1]]:
            C[i] = color
    else:
        C[s[1]] = s[2]