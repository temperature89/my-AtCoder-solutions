s = input()
list = ["maerd", "remaerd", "esare", "resare"]
s = s[::-1]

i = 0
while i < len(s):
    for l in list:
        if s[i:i + len(l)] == l:
            i += len(l)
            break
    else:
        print("NO")
        exit()
print("YES")