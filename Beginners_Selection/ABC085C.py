n, y = map(int, input().split(" "))

def otosidama(n):
    count = 0
    for i in range(n + 1):
        for j in range(n - i + 1):
            k = n - i - j
            if i + j + k != n:
                continue
            elif i * 10000 + j * 5000 + k * 1000 == y:
                print(i,j,k)
                return
            count += 1
    print(-1,-1,-1)

otosidama(n)