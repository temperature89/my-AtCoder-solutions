H, W = map(int, input().split())

l = [[] for i in range(H)]

for h in range(H):
    for w in range(W):
        n = 4
        if w == 0 :
            n -= 1
        if w == W - 1:
            n -= 1
        if h == 0 :
            n -= 1
        if h == H - 1 :
            n -= 1
        l[h].append(n)

for h in range(H):
    print(*l[h])