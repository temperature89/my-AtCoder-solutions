S = input()
 
result = 0
for i, s in enumerate(S):
    if s != "C":
        continue
    if i < (len(S) - 1) / 2:
        result += i + 1
    else:
        result += len(S) - i
print(result)