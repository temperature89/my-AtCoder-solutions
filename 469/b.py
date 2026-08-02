N = int(input())
S = 'x'
S += input() + 'x'
count = 0
if N == 1:
    if S == 'xxx':
        print(1)
        exit()
        
for n in range(1, N + 1):
    if S[n] == 'x' and S[n - 1] == 'x' and S[n + 1] == 'x':
        count += 1
print(count)        
