N = int(input())
h = list(map(int, input().split()))
cost = [0 for n in range(N)]
cost[1] = abs(h[0] - h[1])
for n in range(2, N):
    # cost[n] = min(cost[n - 2] + abs(h[n - 2] - h[n]), cost[n - 1] + abs(h[n - 1] - h[n]))
    cost[n] = min(cost[n - 2] + abs(h[n - 2] - h[n]), cost[n - 1] + abs(h[n - 1] - h[n]))
print(cost[-1])