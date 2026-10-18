N, M = map(int, input().split())
S = []
T = []
for n in range(N):
    S.append(input())
for m in range(M):
    T.append(input())
cnt = [0 for i in range(N)]
# print("=======")
for t in T:
    target = 0
    nearList = []
    for s in S:
        # print(s, t)
        if t == s:
            # print(f"clear:{s}, {t}")
            cnt[target] += 1
            nearList = [-1]
            # print(cnt)
            break
        if len(t) != len(s):
            target += 1
            continue
        onetimefrag = False
        for i in range(len(t)):
            if t[i] != s[i]:
                if onetimefrag == True:
                    break
                else:
                    onetimefrag = True
        else:
            nearList.append(target)
        target += 1
    if len(nearList) == 1 and nearList[0] != -1:
        # print(f"near:{s},{t}")
        cnt[nearList[0]] += 1
    # print(cnt)
        
        # print(cnt)
for n in range(N):
    print(cnt[n])
                