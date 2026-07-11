# N, M = map(int, input().split())
# G = [[] for n in range(N)]
# W = [[] for n in range(N)]
# R = [[] for n in range(N)]
# for m in range(M):
#     u, v, w = map(int, input().split())
#     u -= 1
#     v -= 1
#     G[u].append(v)
#     G[v].append(u)
#     W[u].append(w)
#     W[v].append(w)
#     R[u].append[0]
    

# def dfs(s):
#     if R[p] == 1: 
#         return # もう既に出てきた都市であればreturn
#     R[s] = 1
#     for r in G[s]: dfs(r)