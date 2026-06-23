import bisect
N = int(input())
# LH = []
H = []
L = []
for n in range(N):
    h, l = map(int, input().split())
    L.append(l)
    H.append(h)

H_max = []
max = 0
for i in range(N-1,-1,-1):
    # print(i)
    if max < H[i]:
        max = H[i]
    H_max.append(max)
H_max.reverse()
    
Q = int(input())
T = list(map(int, input().split()))
T = [t + 0.5 for t in T]
# print(L)
for t in T:
    idx = bisect.bisect(L, t)
    print(H_max[idx])