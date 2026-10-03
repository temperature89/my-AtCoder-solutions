N, K = map(int, input().split())
A = list(map(int, input().split()))
# for i in range(0,N - K - 1):
#     begin = i
#     end = i + K + 1
#     area_max = max(A[begin:end])
#     area_min = min(A[begin:end])
#     if begin <= area_min and end >= area_max:
#         print("Yes")
#         exit()

# print("No")

AA = [[a,i] for i,a in enumerate(A)]
AA.sort()
# print(AA)

begin = 0
end = 0

for i in range(N):
    # print(AA[i][1])
    if AA[i][1] != i:
        begin = min(i, AA[i][1])
        end = max(i, AA[i][1])
        
for i in range(N):
    if AA[i][1] != i:
        begin = min(begin, i, AA[i][1])
        end = max(end, i, AA[i][1])
        
if end == -1:
    print("Yes")
else:
    if end - begin + 1 > K:
        print("No")
    else:
        print("Yes")
        
"""
5 3 
3 5 3 3 3

"""