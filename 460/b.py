import math
T = int(input())
cases = []
for t in range(T):
    cases.append(list(map(int, input().split())))

for case in cases:
    x1, y1, r1 = case[0], case[1], case[2]
    x2, y2, r2 = case[3], case[4], case[5]
    length = (x1 - x2) ** 2 + (y1 - y2) ** 2
    # print(length, r1 + r2)
    if (r1 + r2) ** 2 < length or (r1 - r2) ** 2 > length:
        print("No")
    else:
        print("Yes")