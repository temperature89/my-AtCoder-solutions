X = list(map(int, input().split()))

for i,x in enumerate(X):
    if x == 0:
        print(i + 1)
        exit()