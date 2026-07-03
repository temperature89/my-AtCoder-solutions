import bisect
N = int(input())
X =  list(map(int, input().split()))
P =  list(map(int, input().split()))
Q = int(input())
L = []
R = []
for q in range(Q):
    l, r = map(int, input().split())
    L.append(l)
    R.append(r)
P_total = []
total = 0
for n in range(N):
    P_total.append(total)
    total += P[n]
P_total.append(total)
# print(X)
# print(P_total)
for q in range(Q):
    left = bisect.bisect_left(X, L[q])
    right = bisect.bisect_right(X, R[q])
    # print(L[q], R[q])
    # print(left, right)
    # print(P_total[left],P_total[right])
    # print("=====")
    print(P_total[right] - P_total[left])