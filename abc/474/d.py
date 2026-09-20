N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

W = []
win = []
for i in range(N):
    if A[i] > B[i]:
        W.append(10 ** 10)
        win.append(1)
    elif A[i] == B[i]:
        W.append(1)
        win.append(1)
    else:
        W.append(1)
        win.append(-1)

mysum = 0
for i in range(N):
    if win[i] == 1:
        mysum += W[i]
    elif win[i] == 0:
        pass
    else:
        mysum -= W[i]
if mysum <= 0:
    print("No")
else:
    print("Yes")
    print(*W)