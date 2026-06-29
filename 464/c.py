N, M = map(int, input().split())
DAB = []
for n in range(N):
    a, d, b = map(int, input().split())
    DAB.append([d,a,b])
DAB.sort(reverse=True)
color_existing = [0 for n in range(N)]
for dab in DAB:
    color_existing[dab[1] - 1] += 1
    
color_total = 0
for c in color_existing:
    if c != 0:
        color_total += 1
# print(DAB)
# print(color_existing)
# print(color_total)

for m in range(1,M + 1):
    # print(DAB)
    if not len(DAB) == 0:
        while len(DAB) != 0 and DAB[-1][0] == m:
            a = DAB[-1][1]
            b = DAB[-1][2]
            color_existing[a - 1] -= 1
            if color_existing[a - 1] == 0:
                color_total -= 1
                
            if color_existing[b - 1] == 0:
                color_total += 1
            color_existing[b - 1] += 1
            del DAB[-1]
    print(color_total)
        