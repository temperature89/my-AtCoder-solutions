s = input()[::-1]
words = ["maerd", "remaerd", "esare", "resare"]

i = 0
while i < len(s):
    for w in words:
        if s[i:i+len(w)] == w:
            i += len(w)
            break
    else:
        print("NO")
        exit()
print("YES")