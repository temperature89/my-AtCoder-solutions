N = int(input())
L = list(map(int, input().split()))
c = 0.5
i = 0
for l in L:
    prev_c = c
    if c > 0:
        c -= l
    else:
        c += l
    if prev_c * c < 0:
        i += 1
print(i)