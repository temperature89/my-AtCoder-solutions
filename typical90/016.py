N = int(input())
abc = list(map(int, input().split()))
a, b, c = map(int, sorted(abc, reverse=True))

L = 9999
ans = float('inf')
for x in range(L+1):
    if a*x>N:
        break
    max_y = min(L - x, (N - a*x) // b)
    for y in range(max_y + 1):
        z = (N - a*x - b*y) // c
        if a*x + b*y + c*z == N:
            ans = min(ans, x+y+z)
print(ans)