n, m = map(int, input().split())
c = list(map(int, input().split()))
ab = []
for i in range(n):
    ab.append(tuple(map(int, input().split())))

# 種類別にリストで分類
ab_by_type = []
for i in range(m):
    by_type = []
    for j in range(n):
        if ab[j][0] == i + 1:
            by_type.append(ab[j][1])
    ab_by_type.append(by_type)

total = 0
i = 0
for b in ab_by_type:
    b_total = sum(b)
    total += min(b_total,c[i])
    i += 1

print(total)