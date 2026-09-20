S = input()
ans = ""
for s in S:
    ans += s
    ans += "o"
print(ans[:len(ans) - 1])