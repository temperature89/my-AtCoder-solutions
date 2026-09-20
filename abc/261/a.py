l1, r1, l2, r2 = map(int, input().split())
length = min(r1, r2) - max(l1, l2)
if length > 0:
    print(length)
else:
    print(0)