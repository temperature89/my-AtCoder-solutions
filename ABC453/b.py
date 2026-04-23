T, X = map(int, input().split(" "))
A = list(map(int, input().split(" ")))

print(0, A[0])
prev_t = A[0]
i = 0
for a in A:
    if abs(prev_t - a) >= X:
        print(i, a)
        prev_t = a
    i += 1