S = input()

i = 0
j = 1
words = []
while i < len(S):
    while j < len(S) and S[j].islower():
        j += 1
    word = S[i:j + 1]
    words.append([word.lower(), word])
    i = j + 1
    j += 2

words = sorted(words)
result = ""
for word in words:
    result += word[1]
print(result)