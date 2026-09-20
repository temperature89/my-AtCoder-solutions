N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
A = sorted(A)
B = sorted(B, reverse=True)
count = 0
for a in A:
    boarder = a * 2
    if not B:
        break
    if B[-1] <= boarder:
        B.pop()
        count += 1

print(count)