n = int(input())
a = list(map(int, input().split(" ")))
alice_point = 0
bob_point = 0
sorted_a = []

for i in range(n):
    sorted_a.append(a.pop(a.index(max(a))))

sorted_a.append(999)
alice_card = []
bob_card = []
for i in range(0, n, 2):
    alice_card.append(sorted_a[i])
    if sorted_a[i + 1] == 999:
        break
    bob_card.append(sorted_a[i + 1])
alice_point = sum(alice_card)
bob_point = sum(bob_card)
print(alice_point - bob_point)