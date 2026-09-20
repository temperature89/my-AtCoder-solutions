N = int(input())
A = list(map(int, input().split()))
top3 = sorted([A[0], A[1], A[2]], reverse=True)
print(top3[2])
for i in range(3, N):
    top3.append(A[i])
    top3.sort(reverse=True)
    top3.pop()
    print(top3[2])