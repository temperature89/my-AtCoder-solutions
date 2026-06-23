N, K, X = map(int, input().split())
A = list(map(int, input().split()))
A = A + [0]
for i in range(N, K - 1, -1):
    A[i] = A[i - 1]
A[K] = X
print(*A)
