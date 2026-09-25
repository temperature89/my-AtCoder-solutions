N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
A.sort()
B.sort()

score = 0
for n in range(N):
    score += abs(A[n] - B[n])
    
print(score)