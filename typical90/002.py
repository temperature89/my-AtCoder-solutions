
N = int(input())
X = []

if N % 2 == 1:
    exit()

# 1 << N ... 1をNビット左シフト。この場合は2^N
for i in range(1 << N):
    S = ""
    for j in range(N - 1, -1, -1):
        # & 1(0...00001)をすることで右端以外のビットを消す
        if (i >> j) & 1 == 0:
            S += "("
        else:
            S += ")"
        
    b = 0
    e = 0    
    for s in S:
        if s == "(":
            b += 1
        else:
            e += 1
        if b < e:
            break
    else:
        if b == e:
            print(S)

