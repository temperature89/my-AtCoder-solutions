N = int(input())
A = list(map(int, input().split()))
c100 = 0
c10 = 0
c1 = 0

for a in A:
    change = ((a // 1000) + 1) * 1000 - a
    if a % 1000 == 0:
        change = 0
    c100 += change // 100
    # print(change, c100)
    change %= 100
    c10 += change // 10
    # print(change, c10)
    change %= 10
    c1 += change
    # print(change, c1)
print(c1, c10, c100)