# ボールの個数,クエリ数
# クエリはインデックス
n, q = map(int, input().split())
# ボールに書かれた番号リスト
A = list(map(int, input().split()))
sorted_balls = sorted((a, i+1) for i, a in enumerate(A))
query_li = []
for _ in range(q):
    k = int(input())
    B = set(map(int, input().split()))
    
    for val, idx in sorted_balls:
        if idx not in B:
            print(val)
            break