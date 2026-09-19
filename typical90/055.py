from itertools import combinations
N, P, Q = map(int, input().split())
A = list(map(int, input().split()))
ans = 0
for a, b, c, d, e in combinations(A, 5):
    anko = a*b*c*d*e
    if anko % P == Q:
       ans += 1
print(ans) 