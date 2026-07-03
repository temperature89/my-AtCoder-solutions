# def is_ok(P, mid, n):
#     return P[mid][0] > n

# def binary_search(P, n):
#     left = -1
#     right = len(P)
    
#     while abs(right - left) > 1:
#         mid = (left + right) // 2
#         if is_ok(P, mid, n):
#             right = mid
#         else:
#             left = mid
#     return right
import bisect
N = int(input())
P1 = [[-1,0]]
P2 = [[-1,0]]
for n in range(N):
    num, score = list(map(int, input().split()))
    if num == 1:
        P1.append([n,score])
    else:
        P2.append([n,score])
# print(P1)
# print(P2)
Q = int(input())
LR = [list(map(int, input().split())) for q in range(Q)]
P1_sum = []
P2_sum = []
total = 0
for p1 in P1:
    total += p1[1]
    P1_sum.append([p1[0],total])
total = 0
for p2 in P2:
    total += p2[1]
    P2_sum.append([p2[0],total])
print(P1_sum)
print(P2_sum)
P1_idx = [P1_sum[n][0] for n in range(N)]
P2_idx = [P2_sum[n][0] for n in range(N)]
for lr in LR:
    l = lr[0] - 1
    r = lr[1] - 1
    result = []
    for P in [P1_idx, P2_idx]:
        left = bisect.bisect_left(P,l)
        right = bisect.bisect_right(P, r) - 1
        print(left)
        print(right)
        print(P[right][1] - P[left][1])
        # result.append(P[right] - P)