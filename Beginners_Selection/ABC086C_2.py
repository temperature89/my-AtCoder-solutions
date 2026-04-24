N = int(input())
T = [0]
X = [0]
Y = [0]
for n in range(N):
    t, x, y = map(int, input().split())
    T.append(t)
    X.append(x)
    Y.append(y)

for i in range(N):
    length = abs(X[i + 1] - X[i]) + abs(Y[i + 1] - Y[i])
    tt = T[i + 1] - T[i] 
    if not (length <= tt and (length - tt) % 2 == 0):
        print("No")
        exit()
print("Yes")