from collections import defaultdict
N = int(input())
S = input()
counter = defaultdict(int)
atcoder = ["a", "t", "c", "o", "d", "e", "r", ""]
# はじめのaより左を切る
S = S[S.index("a"):]
# atcoderの順番に文字列を抜き出す
S_picked = ""
i = 0
for s in S:
    if s == atcoder[i]:
        S_picked += s
    elif s == atcoder[i + 1]:
        S_picked += s
        i += 1
# print(S_picked)
result = 0
i = 0
j = 0
char_count = [0 for i in range(7)]
while i < len(S_picked):
    while i < len(S_picked) and S_picked[i] != atcoder[j + 1]:
        # if S_picked[i] == atcoder[j]:
        char_count[j] += 1
        i += 1
    j += 1
    # print(char_count)
    if j == 7:
        prod = 1
        for c in char_count:
            prod *= c
        result += prod
        char_count = [0 for i in range(7)]
        j = 0
print(result % (10 ** 9 + 7))