N, Q = map(int, input().split())
S = input()
L = []
R = []
for q in range(Q):
    l, r = list(map(int, input().split()))
    L.append(l)
    R.append(r)
S_cum = [0]
str = ""
AC_count = 0
for i, s in enumerate(S):
    str += s
    if i == 0:
        continue
    elif str[-2] == "A" and str[-1] == "C":
        AC_count += 1
    S_cum.append(AC_count)
for q in range(Q):
    l = L[q] - 1
    r = R[q] - 1
    print(S_cum[r] - S_cum[l])