from collections import defaultdict
N, Q = map(int, input().split())
A = [[] for q in range(Q)]

for q in range(Q):
    L, R, X = map(int, input().split())
    L -= 1
    R -= 1
    X -= 1
    if A[X] == []:
        A[X] = [L,R]
    else:
        A[X] = [min(L,A[X][0]),max(R,A[X][0])]
print(A)