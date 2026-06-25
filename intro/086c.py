N = int(input())
T = [0]
X = [0]
Y = [0]
for n in range(N):
    t, x, y = map(int, input().split())
    T.append(t)
    X.append(x)
    Y.append(y)

for n in range(N):
    t = T[n]
    x = X[n]
    y = Y[n]
    t_next = T[n + 1]
    x_next = X[n + 1]
    y_next = Y[n + 1]
    time = t_next - t
    length = (abs(x_next - x) + abs(y_next - y))
    if not(time >= length and (time - length) % 2 == 0):
        print("No")
        exit()
print("Yes")