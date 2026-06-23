N ,K = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
# print(A)
if K % 2 == 0:
    min = A[int(K / 2)]
    max = A[int(-1 * K / 2 - 1)]
    result = max - min
else:
    # 前を多く取る
    min = A[K // 2 + 1]
    max = A[-1 * K // 2]
    result = max - min
    min = A[K // 2]
    max = A[-1 * K // 2 - 1]
    if result > max - min:
        result = max - min
    
    
    
print(result)