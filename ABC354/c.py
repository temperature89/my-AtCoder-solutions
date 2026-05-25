N = int(input())
A = []
C = []
for n in range(N):
    a, c = map(int, input().split())
    A.append(a)
    C.append(c)
# # print(C)
# A_sorted = sorted(A)
# C_sorted = [0 for i in range(N)]
# for i, a in enumerate(A):
#     index = A_sorted.index(a)
#     C_sorted[index] = C[i]
# # print(A_sorted)
# # print(C_sorted)

# prev_c = -1
# remove_c = []
# for i, c in enumerate(C_sorted):
#     if c < prev_c:
#         remove_c.append(prev_c)
#     #     prev_c
        
#     # else:
#     prev_c = c
#     # print(prev_c)

# # print(remove_c)
# C_removed = [i + 1 for i, c in enumerate(C) if not c in remove_c]
# # print(C_removed)

# print(len(C_removed))
# print(*C_removed)

cards = [[A[i], C[i], i + 1] for i in range(N)]
cards.sort()
# print(cards)
survived = []
min = float("inf")
# print("====")

for n in range(N - 1, -1, -1):
    a = cards[n][0]
    c = cards[n][1]
    id = cards[n][2]
    if c < min:
        survived.append(id)
        min= c
        # print(survived)

survived.sort()
print(len(survived))
print(*survived)


"""
6

3 2 29
1 32 101 -
4 46 55 -
6 52 40
2 65 78
5 103 130 

1 32 101 -
2 65 78
3 2 29
4 46 55 -
5 103 130 
6 52 40
"""

"""
((c,a,id),(c...),...)を作成、ソート
"""