from collections import defaultdict
dict = defaultdict(int)
N = int(input())
ans = []
for n in range(N):
    s = input()
    if dict[s] == 0:
        # ans.append(n + 1)
        print(n + 1)
        dict[s] = 1
# for a in ans:
#     print(a)