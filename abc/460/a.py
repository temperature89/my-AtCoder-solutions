N, M = map(int,input().split())

count = 0

while M != 0:
    x = N % M
    M = x
    count += 1
print(count)