import heapq
X = int(input())
Q = int(input())
AB = []
for q in range(Q) :
    ab = list(map(int, input().split()))
    AB.append(ab)

first = [-X]
second = []
heapq.heapify(first)
heapq.heapify(second)

for i, ab in enumerate(AB):
    for n in ab:
        if n < -first[0]:
            heapq.heappush(first, -n)
        else:
            heapq.heappush(second, n)
    # print(first, second)
    while len(first) != len(second) + 1:
    # for j in range(10):
        if len(first) > i + 2:
            heapq.heappush(second, -heapq.heappop(first))
        elif len(second) > i + 1:
            heapq.heappush(first, -heapq.heappop(second))
        # print(first, second)
        
    print(-first[0])
        
            