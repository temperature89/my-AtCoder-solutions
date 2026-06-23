NX = input().split()
N =int(NX[0])
X = NX[1]
if X == "A":
    X = 0
elif X == "B":
    X = 1
elif X == "C":
    X = 2
elif X == "D":
    X = 3
else:
    X = 4

Seats = []
for n in range(N):
    Seats.append(input())

for S in Seats:
    if S[X] == "o":
        print("Yes")
        exit()
print("No")