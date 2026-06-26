from collections import defaultdict
N = int(input())
S = [input() for n in range(N)]

list = defaultdict(int)

for s in S:
    list[s] += 1
    num = list[s]
    if num == 1:
        print(s)
    else:
        print(f"{s}({num - 1})")