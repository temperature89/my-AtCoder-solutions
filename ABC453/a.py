N = int(input())
S = input()
SS = str(S)

for s in S:
    if s == "o":
        SS = SS.lstrip("o")
    else:
        break

print(SS)