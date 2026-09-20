N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

for i,a in enumerate(A):
    if not B[a - 1] == i + 1:
        print("No")
        break
else:
    print("Yes")
    