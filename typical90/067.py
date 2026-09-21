N, K = list(map(int, input().split()))
for k in range(K):
    N = N - N // 8
    print(N)