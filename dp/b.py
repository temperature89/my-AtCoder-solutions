N, K = map(int, input().split())
h = list(map(int, input().split()))
cost = [10 ** 8 for n in range(N)]
cost[0] = 0
cost[1] = abs(h[0] - h[1])
for n in range(2, N):
    # print([cost[n - k] + abs(h[n - k] - h[n]) for k in range(1, K + 1)])
    cost[n] = min([cost[n - k] + abs(h[n - k] - h[n]) for k in range(1, K + 1)])
print(cost[-1])
# print(cost)