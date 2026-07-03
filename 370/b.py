N = int(input())
A = [[] for n in range(N)]
for n in range(N):
    A[n] = list(map(lambda x: x-1, list(map(int, input().split()))))
i = 0
for j in range(N):
    if i >= j:
        i = A[i][j]
    else:
        i = A[j][i]
print(i + 1)