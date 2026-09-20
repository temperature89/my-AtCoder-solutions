import bisect
X, N = map(int, input().split())
P = list(map(int, input().split()))

P.sort()

if N == 0:
    print(X)
    exit()

min = 101
result = []
for target in range(1000):
    idx = bisect.bisect(P, target)
    if P[idx - 1] == target:
        continue
    else:
        if min > abs(target - X):
            min = abs(target - X)
            
for target in range(1000):
    idx = bisect.bisect(P, target)
    if P[idx - 1] == target:
        continue
    else:
        if min == abs(target - X):
            result.append(target)
            
result.sort()
print(result[0])