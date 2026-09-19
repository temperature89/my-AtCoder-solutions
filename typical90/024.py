N, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
cnt = 0
for i in range(N):
    cnt += abs(A[i] - B[i])
if cnt > K:
    print("No")
elif cnt == K:
    print("Yes")
else:
    anko = K - cnt
    if anko % 2 == 0:
        print("Yes")
    else:
        print("No")