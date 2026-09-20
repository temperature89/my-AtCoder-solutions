N, Q = map(int, input().split())
P = list(map(int, input().split()))
A = []
for q in range(Q):
    A.append(int(input()))
rev_A = []
seen = set()
for q in range(Q - 1, -1, -1):
    a = A[q]
    if not a in seen:
        # print(True)
        seen.add(a)
        rev_A.append(a) 
rev_A.reverse()
ans = [p for p in P if p not in seen] + rev_A
print(*ans)
    