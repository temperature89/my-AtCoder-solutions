# N, X, Y, Z = map(int, input().split())
# A = list(map(int, input().split()))
# B = list(map(int, input().split()))
# passed = []
# Ai = []
# Bi = []
# ABi = []
# i = 0
# for a,b in zip(A,B):
#     Ai.append([a,i])
#     Bi.append([b,i])
#     ABi.append([a+b,i])
#     i += 1
# Ai.sort(reverse=True)
# Bi.sort(reverse=True)
# ABi.sort(reverse=True)

# def remove_pass(x):
#     global passed
#     x_notpassed = []
#     for p in passed:
#         for xx in x:
#             if p != xx[1]:
#                 x_notpassed.append(xx)
#     return x_notpassed

# def check_pass(x, list):
#     global passed
#     i = 0
#     if x != 0:
#         while True:
#             if i < len(list) and list[i + 1][0] == list[i][0]:
#                 passed.append(list[i + 1][1])
#             else:
#                 passed.append(list[i][1])
#             x -= 1
#             if x == 0:
#                 break
#             i += 1

# # 英語
# check_pass(X, Ai)

# # 合格者を削除
# Ai = remove_pass(Ai)
# Bi = remove_pass(Bi)
# ABi = remove_pass(ABi)

# # 数学
# check_pass(Y, Bi)

# Ai = remove_pass(Ai)
# Bi = remove_pass(Bi)
# ABi = remove_pass(ABi)

# # 合計
# check_pass(Z, ABi)

# passed.sort()
# for p in passed:
#     print(p + 1)
import sys

def solve():
    # 入力の受け取り
    N, X, Y, Z = map(int, sys.stdin.readline().split())
    A = list(map(int, sys.stdin.readline().split()))
    B = list(map(int, sys.stdin.readline().split()))
    
    # 各受験生の情報をまとめる: [番号, 数学, 英語, 合計]
    # 番号を 1始まり にするため i+1 としている
    students = []
    for i in range(N):
        students.append([i + 1, A[i], B[i], A[i] + B[i]])
        
    # 合格したかどうかを記録する配列（1-indexed用）
    passed = [False] * (N + 1)
    
    # --- 1段階目: 数学の選考 ---
    # 数学の点数(x[1])の降順（マイナスをつける）、番号(x[0])の昇順
    students.sort(key=lambda x: (-x[1], x[0]))
    count_x = 0
    for s in students:
        if count_x == X:
            break
        if not passed[s[0]]:
            passed[s[0]] = True
            count_x += 1
            
    # --- 2段階目: 英語の選考 ---
    # 英語の点数(x[2])の降順、番号(x[0])の昇順
    students.sort(key=lambda x: (-x[2], x[0]))
    count_y = 0
    for s in students:
        if count_y == Y:
            break
        if not passed[s[0]]:
            passed[s[0]] = True
            count_y += 1
            
    # --- 3段階目: 合計点の選考 ---
    # 合格点の点数(x[3])の降順、番号(x[0])の昇順
    students.sort(key=lambda x: (-x[3], x[0]))
    count_z = 0
    for s in students:
        if count_z == Z:
            break
        if not passed[s[0]]:
            passed[s[0]] = True
            count_z += 1
            
    # --- 出力 ---
    # 合格した人の番号を小さい順に出力
    for i in range(1, N + 1):
        if passed[i]:
            print(i)

if __name__ == '__main__':
    solve()