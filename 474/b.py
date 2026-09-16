N = int(input())
P = list(map(int, input().split()))
j = 1
while j * 10 <= N:
    myrange = min(j * 10, N)
    for i in range((j - 1) * 10, j * 10):
        if not ((j - 1) * 10 <= P[i] and P[i] <= j * 10):
            print("No")
            exit()
    j += 1
print("Yes")
            
    