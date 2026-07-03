N, M = map(int, input().split())
AB = []
for m in range(M):
    a, b = input().split()
    a = int(a)
    AB.append([a,b])
    
C = [0 for n in range(N)]
for ab in AB:
    a = ab[0] - 1
    b = ab[1]
    if C[a] == 0 and b == "M":
        C[a] = 1
        print("Yes")
    else:
        print("No")