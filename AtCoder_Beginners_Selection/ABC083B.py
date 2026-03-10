n, a, b = map(int, input().split(" "))

total = 0
for i in range(n + 1):
    i = str(i)
    sum = 0
    for i_char in i:
        sum += int(i_char)
    if a <= sum and sum <= b:
        total += int(i)
print(total)