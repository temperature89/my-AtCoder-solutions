N, M = map(int, input().split())
G = [[] for n in range(N)]
for m in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)
# print("========")
ans = 0
for n in range(N):
    ctn = 0
    for p in G[n]:
        if p < n:
            # print(n, p)
            ctn += 1
    if ctn == 1:
        # print("!!!!!!!")
        ans += 1
print(ans)