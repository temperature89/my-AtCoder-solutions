M, D = map(int, input().split())
gothec = {1:7,3:3,5:5,7:7,9:9}

for m,d in gothec.items():
    if m == M and d == D:
        print("Yes")
        exit()
print("No")