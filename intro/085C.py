N, Y = map(int, input().split())

def otosidama():
    for i in range(N + 1):
        for j in range(N + 1 - i):
            k = N - i - j
            total = 1000 * i + 5000 * j + 10000 * k
            if total == Y:
                print(k, j, i)
                return
    print(-1, -1, -1)

otosidama()