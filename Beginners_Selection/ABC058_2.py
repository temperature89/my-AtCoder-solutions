N, Y = map(int, input().split())
i = 0
j = 0
k = 0

def main():
    for i in range(N + 1):
        for j in range(N - i + 1):
            k = N - i - j
            if 10000 * i + 5000 * j + 1000 * k ==  Y:
                print(i, j, k)
                return
    print(-1,-1,-1)
                
main()                