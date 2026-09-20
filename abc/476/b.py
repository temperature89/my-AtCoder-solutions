N = int(input())
S = input()
T = input()

for i in range(N):
    if T[i] == '*':
        pass
    elif T[i] != S[i]:
        print("No")
        exit()
print("Yes")