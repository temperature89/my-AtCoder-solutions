N, M = map(int, input().split())
C = [-1 for i in range(M)]

for n in range(N):
    c, s = map(int, input().split())
    c -= 1
    if s > C[c]:
        C[c] = s

print(*C)