N = int(input())
Mg = int(input())
G = [[] for n in range(N)]
for mg in range(Mg):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    G[u].append(v)
    G[v].append(u)
Mh = int(input())
H = [[] for n in range(N)]
for mh in range(Mh):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    H[a].append(b)
    H[b].append(a)
A = [[] for n in range(N - 1)]
for n in range(N - 1):
    A[n] = list(map(int, input().split()))
