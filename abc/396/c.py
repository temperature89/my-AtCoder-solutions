N, M = map(int, input().split())
B = list(map(int, input().split()))
W = list(map(int, input().split()))
B.sort(reverse=True)
W.sort(reverse=True)

# print(B)
# print(W)

score = 0
for n in range(N):
    m = n
    b = B[n]
    if m > M - 1:
        w = -1
    else:
        w = W[m]    
    if w > 0:
        if b > 0 :
            score += b + w
        elif b + w > 0:
            score += b + w    
    elif b > 0:
        score += b
print(score)