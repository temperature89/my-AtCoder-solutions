from itertools import combinations
N, V = map(int, input().split())
W = list(map(int, input().split()))
WW = []
for i, w in enumerate(W):
    WW.append([w,i+1])
max_happiness = 0
for a, b, c in combinations(WW, 3):
    if a[1] + b[1] + c[1] > V:
        continue
    max_happiness = max(max_happiness, a[0] + b[0] + c[0])
print(max_happiness)