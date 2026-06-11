N, K, M = map(int, input().split())
VC = []

for n in range(N):
    c, v = map(int, input().split())
    VC.append([v, c])
VC = sorted(VC, reverse=True)
C_used = [0 for n in range(N)]
score = 0
dup = K - M
for vc in VC:
    if K == 0:
        break
    v = vc[0]
    c = vc[1] - 1
    if C_used[c] == 0:
        M -= 1
        C_used[c] = 1
        K -= 1
        score += v
    elif dup != 0:
        K -= 1
        dup -= 1
        score += v
            
print(score)
    