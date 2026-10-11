import sys

def solve():
    # 1行ずつ高速に読み込む関数に差し替え
    input = sys.stdin.readline
    
    first_line = input().split()
    if not first_line:
        return

    N = int(first_line[0])
    Q = int(first_line[1])
    
    # L, R の読み込み
    L = list(map(int, input().split()))
    R = list(map(int, input().split()))

    # 配列サイズを N-1 で確保
    L_min = [0 for n in range(N - 1)]
    R_min = [0 for n in range(N - 1)]

    # i 自身を含めた右側の L の最小値
    m = float("inf")
    for i in range(N - 2, -1, -1):
        m = min(m, L[i])
        L_min[i] = m

    # i 自身を含めた左側の R の最小値
    m = float("inf")
    for i in range(0, N - 1):
        m = min(m, R[i])
        R_min[i] = m

    # right_left[s]: マス s から右に飛んで左に戻るコスト
    right_left = [0 for n in range(N - 1)]
    for i in range(0, N - 1):
        right_left[i] = R[i] + L_min[i]

    # left_right[s]: マス s から左に飛んで右に進むコスト
    left_right = [0 for n in range(N)]
    for i in range(1, N):
        left_right[i] = L[i - 1] + R_min[i - 1]

    # クエリの処理（1行ずつ読み込み）
    out = []
    for q in range(Q):
        line = input().split()
        if not line:
            break
        s = int(line[0]) - 1
        t = int(line[1]) - 1

        if s < t:
            # 右方向への移動
            if s == 0:
                out.append(str(R[0]))
            else:
                out.append(str(min(R[s], left_right[s])))
        else:
            # 左方向への移動
            if s == N - 1:
                out.append(str(L[-1]))
            else:
                out.append(str(min(L[s - 1], right_left[s])))
    print(L)
    print(R)
    print(L_min)
    print(R_min)
    print(left_right)
    print(right_left)
    print('\n'.join(out))

if __name__ == '__main__':
    solve()