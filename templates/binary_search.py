# 調べたい値midが条件を満たしているかどうかを判定する関数
def is_ok(mid):
    return A[mid] > 5

def binary_search():
    left = -1
    right = len(A)
    
    while abs(right - left) > 1:
        mid = (left + right) // 2
        if is_ok(mid):
            right = mid
        else:
            left = mid
    return right

A = [1,2,3,4,5,6,7,8,9]
print(binary_search())