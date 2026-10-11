N = int(input())
S = input()

cnt = 0
ans = 0
for s in S:
    if s == "R":
        cnt += 1
    else:
        ans = max(ans, cnt)
        cnt = 0
ans = max(ans, cnt)
print(ans)
        