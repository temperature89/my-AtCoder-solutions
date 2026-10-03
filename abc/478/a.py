N, M = map(int, input().split())
for i in range(N):
    cnt = M // N
    if i + 1 <= M % N:
        cnt += 1
    print(cnt)