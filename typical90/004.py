H, W = map(int, input().split())
A = []
for h in range(H):
    A.append(list(map(int, input().split())))

h_sum = []
w_sum = [0 for i in range(W)]
for a in A:
    h_sum.append(sum(a))
    for w in range(W):
        w_sum[w] += a[w]

sum_list = [list(0 for j in range(W)) for i in range(H)]

for h in range(H):
    for w in range(W):
        sum_list[h][w] = h_sum[h] + w_sum[w] - A[h][w]

for sum in sum_list:
    print(" ".join(str(s) for s in sum))