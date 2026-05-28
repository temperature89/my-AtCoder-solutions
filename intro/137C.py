from collections import defaultdict
N = int(input())
S = [input() for n in range(N)]


list = defaultdict(int)

for s in S:
    s_sorted = "".join(sorted(s))
    list[s_sorted] += 1

count = 0
for s, i in list.items():
    count += i * (i - 1) // 2
    
print(count)