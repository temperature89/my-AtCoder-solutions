Q = int(input())
top = []
bottom = []
for q in range(Q):
    t, x = map(int, input().split())
    if t == 1:
        top.append(x)
    elif t == 2:
        bottom.append(x)
    else:
        # print(top, bottom)
        if x <= len(top):
            print(top[-x])
        else:
            print(bottom[x - len(top)- 1])