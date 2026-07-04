x, y, l ,r, a, b = map(int, input().split())

x_time = min(r,b) - max(l,a)
# x_time = max(min(r,b) - max(l,a), 0)
y_time = b - a - x_time
print(x * x_time + y * y_time)