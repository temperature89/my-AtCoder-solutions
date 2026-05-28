N = int(input())
D = []
for n in range(N):
    D.append(int(input()))
D.sort()
# print(D)
prev_d = D[0]
count = 1
for d in D:
    if d != prev_d:
        prev_d = d
        count += 1
print(count)