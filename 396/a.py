N = int(input())
A = list(map(int, input().split()))

count = 0
c = -1
for a in A:
    if c == a:
        count += 1
        if count == 2:
            print("Yes")
            exit()
    else:
        c = a
        count = 0
print("No")