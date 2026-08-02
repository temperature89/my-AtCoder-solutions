N = int(input())
S = input()
s_mul = []
c = 0
for i, s in enumerate(S):
    if s == 'o':
        c += 1
    s_mul.append(c)
# print(s_mul)
for k in range(N):
    count = 0
    begin = k
    snack = s_mul[k]
    count += k + 1
    # print(snack, count)
    while True:
        # print(count)
        if snack == 0:
            break
        elif begin + snack > N - 1:
            count = N
            break
        count += snack
        b = begin + snack
        snack = s_mul[begin + snack] - s_mul[begin]
        begin = b
        # print(snack, count)
    # print(k, count, 000000)
    print(count)