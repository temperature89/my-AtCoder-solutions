N, K = map(int, input().split())
A = list(map(int, input().split()))

KK = K % N
fair_cookie = K // N
A_get = [fair_cookie for _ in range(N)]

A_sorted = sorted(A)

if KK > 0:
    border = A_sorted[KK - 1]
    for i in range(N):
        if A[i] <= border:
            A_get[i] += 1
    

for a in A_get:
    print(a)
    