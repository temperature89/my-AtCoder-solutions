import sys
from itertools import permutations

def main():
    # C++の cin >> のように、すべての入力を空白・改行で区切って一括取得
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    reader = iter(input_data)
    
    N = int(next(reader))
    
    # グラフ G の辺の集合 (C++ の set<pair<int, int>> に相当)
    edges_G = set()
    M_G = int(next(reader))
    for _ in range(M_G):
        u = int(next(reader)) - 1
        v = int(next(reader)) - 1
        edges_G.add((u, v))
        edges_G.add((v, u))  # 逆向きの辺も追加
        
    # グラフ H の辺の集合
    edges_H = set()
    M_H = int(next(reader))
    for _ in range(M_H):
        a = int(next(reader)) - 1
        b = int(next(reader)) - 1
        edges_H.add((a, b))
        edges_H.add((b, a))  # 逆向きの辺も追加
        
    # コスト配列 A の受け取り
    A = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(i + 1, N):
            cost = int(next(reader))
            A[i][j] = cost
            A[j][i] = cost  # 逆向きのコストも追加
            
    # 💡 答えの初期値
    # C++のコードでは 28000000 になっていたけれど、最悪ケースでぴったりその値に
    # なったときに更新漏れが起きるのを防ぐため、Pythonでは float("inf")（無限大）にするのが安全！
    ans = float("inf")
    
    # H の頂点（0 ~ N-1）を G の頂点に対応させる順列をすべて探索
    for P in permutations(range(N)):
        current_sum = 0
        for i in range(N):
            for j in range(i):
                # H に辺 (i, j) があって G に辺 (P[i], P[j]) がない、
                # もしくはその逆の場合にコスト A[i][j] を足す
                has_H = (i, j) in edges_H
                has_G = (P[i], P[j]) in edges_G
                
                if has_H != has_G:
                    current_sum += A[i][j]
                    
        # 最小値を更新
        if current_sum < ans:
            ans = current_sum
            
    print(ans)

if __name__ == '__main__':
    main()