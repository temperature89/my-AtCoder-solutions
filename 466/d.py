N, M = map(int, input().split())
RC = []
for m in range(M):
    r, c = map(int, input().split())
    RC.append([r,c])
putted_row = [False] * N
putted_column = [False] * N
ans = 0
for m in range(M - 1, -1,-1):
    r, c = RC[m][0], RC[m][1]
    r -= 1
    c -= 1
    if putted_row[r] == False and putted_column[c] == False:
        ans += 1
    putted_row[r] = True
    putted_column[c] = True
print(ans)