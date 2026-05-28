# N, Q = map(int, input().split())
# querys = []
# for q in range(Q):
#     query = list(map(int, input().split()))
#     querys.append(query)

# field = [0 for n in range(N)]
# block = [0 for q in range(Q)]
# block[0] = N
# reset = 0
# builded_block = 0
# continue_builded_block = 0


# for query in querys:
#     command = query[0]
#     if command == 1:
#         n = query[1] - 1
#         field[n] += 1
#         block[field[n] - 1 - reset] -= 1
#         block[field[n] - reset] += 1
#         builded_block += 1
#         if block[0] == 0:
#             # print("reset")
#             reset += 1
#             builded_block -= N
#             block = [block[i + 1] for i in range(Q - 1)]
#             block.append(0)
#     elif command == 2:
#         n = query[1]
#         sum_under_n = sum(block[0:n])
#         # print(block[0:n - 1])
#         print(builded_block - sum_under_n)
#     # print(block)
#     # print(field)
#     # print(f"block = {builded_block}")
        
import sys

def solve():
    # 入力を高速に一括読み込み
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    N = int(input_data[0])
    Q = int(input_data[1])
    
    # cnt[j] : 累積の高さが j 以上であるマスの個数
    # クエリは最大 Q 回なので、累積の高さも最大 Q 付近までしかいかない
    MAX_H = Q + 2
    cnt = [0] * MAX_H
    cnt[0] = N  # 初期状態ではすべてのマス（N個）が「高さ0以上」を満たしている
    
    # A[x] : マス x の「累積の高さ」（1-indexed）
    A = [0] * (N + 1)
    
    k = 0  # これまでに消滅した行数（＝全マスの最小値）
    
    idx = 2
    output = []
    
    for _ in range(Q):
        cmd = int(input_data[idx])
        if cmd == 1:
            x = int(input_data[idx+1])
            idx += 2
            
            # マス x にブロックを積む（累積の高さを1増やす）
            next_h = A[x] + 1
            cnt[next_h] += 1  # 高さ next_h 以上になったマスが1つ増える
            A[x] = next_h
            
            # もしすべてのマス（N個）の累積の高さが k + 1 以上になったら
            # 1行消滅イベントが発生し、基準値 k が 1 増える
            if cnt[k + 1] == N:
                k += 1
                
        elif cmd == 2:
            y = int(input_data[idx+1])
            idx += 2
            
            # 実際の高さが y 以上 ⇔ 累積の高さが y + k 以上
            target_h = y + k
            
            if target_h >= MAX_H:
                output.append("0")
            else:
                output.append(str(cnt[target_h]))
                
    # 結果をまとめて出力
    sys.stdout.write("\n".join(output) + "\n")

if __name__ == '__main__':
    solve()