N, x = map(int, input().split())
A = list(map(int, input().split()))
count = 0
c = 0

if A[0] > x:
    count += A[0] - x
    A[0] = x
    
for n, a1 in enumerate(A):
    if n == N - 1:
        break
    a2 = A[n + 1]
    if a1 + a2 > x:
        count += a2 - (x - a1)
        A[n + 1] = x - a1
print(count)