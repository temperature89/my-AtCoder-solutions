N, S, L = map(int, input().split())
A = list(map(int, input().split()))
visited_vertex = [False for n in range(N)]
ANS = 0
def search(vertex, length):
    global ANS
    flag = False
    if visited_vertex[vertex] == False:
        flag = True
    visited_vertex[vertex] = True

    
    if vertex == 0:
        adjacent_vertex = [vertex + 1]
    elif vertex == N - 1:
        adjacent_vertex = [vertex - 1]
    else:
        adjacent_vertex = [vertex - 1, vertex + 1]
    
    for next_vertex in adjacent_vertex:
        next_length = A[min(next_vertex, vertex)] + length
        if next_length > L:

            ANS = max(ANS, visited_vertex.count(True))
            if flag == True:
                visited_vertex[vertex] = False
            return
        search(next_vertex, next_length)

    
    # if not vertex == 0:
    #     prev_length = A[vertex - 1] + length
    #     if prev_length > L:
    #         print(visited_vertex)
    #         return
    #     print(vertex, prev_length)
    #     search(vertex - 1, prev_length)
    # if not vertex == N - 1:
    #     next_length = A[vertex] + length
    #     if next_length > L:
    #         print(visited_vertex)
    #         return
    #     print(vertex, next_length)
    #     search(vertex, next_length)
        
search(S - 1, 0)
print(ANS)