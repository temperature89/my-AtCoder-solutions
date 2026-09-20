N = int(input())
dp = [[0,0,0] for n in range(N+1)]
ans = 0
for n in range(N):
    abc = list(map(int, input().split()))
    for i in range(3):
        other_i = [0,1,2]
        other_i.pop(i)
        dp[n + 1][i] = max([dp[n][j] + abc[i] for j in other_i])
        
print(dp)
print(max(dp[-1]))