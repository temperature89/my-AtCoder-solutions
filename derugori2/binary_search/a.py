import bisect
N, K = map(int, input().split())
A = list(map(int, input().split()))

if bisect.bisect_left(A, K) > len(A) - 1:
    print(-1)
else:
    print(bisect.bisect_left(A, K))