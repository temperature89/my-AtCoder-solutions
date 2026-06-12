import bisect
N = int(input())
A = list(map(int, input().split()))
Q = int(input())
B = []
for q in range(Q):
    B.append(int(input()))
A = sorted(A)
A.append(float('inf'))

def is_ok(mid, b):
    return A[mid] >= b

# 二分探索
def binary_search(b):
    left = -1
    right = len(A)
    
    while abs(right - left) > 1:
        mid = (left + right) // 2
        if is_ok(mid, b):
            right = mid
        else:
            left = mid
    return left

for b in B:
    left = binary_search(b)
    score_left = abs(A[left] - b)
    score_right = abs(A[left + 1] - b)
    if score_right > score_left:
        print(score_left)
    else:
        print(score_right)
    