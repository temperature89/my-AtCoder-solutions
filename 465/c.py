N = int(input())
S = input()
A = [n for n in range(1, N + 1)]
S_total = []
total  = 0
for i in range(N - 1, -1, -1):
    if S[i] == "o":
        total += 1
    S_total.append(total)

left = []
right = []
for i in range(N):
    swich = S_total[i]
    if swich % 2 == 0:
        right.append(N - i)
    else:
        left.append(N - i)
right.reverse()
print(*(left + right))