N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]
M = int(input())

bad = [[False] * N for _ in range(N)]
for _ in range(M):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    bad[x][y] = True
    bad[y][x] = True

visited = [False] * N
ans = float('inf')

def dfs(section, prev_runner, current_time):
    global ans
    if current_time >= ans:
        return
    if section == N:
        ans = min(ans, current_time)
        return
    for runner in range(N):
        if visited[runner]:
            continue
        if prev_runner != -1 and bad[prev_runner][runner]:
            continue
        visited[runner] = True
        dfs(section + 1, runner, current_time + A[runner][section])
        
        visited[runner] = False
    

dfs(0,-1,0)
print(ans if ans != float("inf") else -1)
            
            
    