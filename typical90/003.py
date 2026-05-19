import sys

sys.setrecursionlimit(200000)

N = int(input())
A = []
B = []
for n in range(N - 1):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

ad_list = [[] for i in range(N)]
for (a, b) in zip(A, B):
    ad_list[a - 1].append(b - 1)
    ad_list[b - 1].append(a - 1)
# print(ad_list)



# def dfs(v, parent, depth):
#     for g in ad_list[s]:
#         if g != parent:
#             parent = s
#             depth += 1
#             # print(f"s = {s}, g = {g}, route = {route}")
#             search_end(g, parent, depth)
#     depth - 1

# def search_length(s, route):
#     global score
#     for g in ad_list[s]:
#         if not g in route:
#             route.append(g)
#             score = max(len(route), score)
#             # print(f"s = {s}, g = {g}, route = {route}")
#             search_length(g, route)
#     del route[-1]
# end_node = 0
# search_end(0, -1, 0)
# # print("=============================")
# score = 0
# search_length(end_node, [end_node])
# print(score)

def dfs(v, parent, depth):
    far_node = v
    max_depth = depth
    
    for nxt in ad_list[v]:
        if nxt!= parent:
            node, d = dfs(nxt, v, depth + 1)
            if d > max_depth:
                max_depth = d
                far_node = node
    return far_node, max_depth

u, _ = dfs(0, -1, 0)
v, dist = dfs(u, -1, 0)
print(dist + 1)

