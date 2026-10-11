from itertools import combinations
N, W = map(int, input().split())
A = []
B = []
AB = []
for n in range(N):
    a, b = map(int, input().split())
    # A.append(a)
    # B.append(b)
    AB.append([a,b])
# AB.sort()
# print(AB)
ans = 0
for n in range(N):
    for abs in combinations(AB, n+1):
        scr = 0
        v = 0
        for ab in abs:
            scr += ab[0]
            v += ab[1]
        if v <= W:
            ans = max(ans, scr)
print(ans)