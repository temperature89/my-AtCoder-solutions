n = int(input())
t = [0]
x = [0]
y = [0]

for i in range(n):
    tt, xx, yy = map(int, input().split(" "))
    t.append(tt) 
    x.append(xx) 
    y.append(yy)

for i in range(1,n+1):
    length = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1])
    time = abs(t[i] - t[i-1])
    if not (time - length) % 2 == 0 or time < length:
        print("No")
        exit()
print("Yes")