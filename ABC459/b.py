N = int(input())
S = list(map(str, input().split()))
C = []
for s in S:
    char = ord(s[0])
    if 97 <= char and char <= 99 :
        C.append("2")
    elif 100 <= char and char <= 102:
        C.append("3")
    elif 103 <= char and char <= 105:
        C.append("4")
    elif 106 <= char and char <= 108 :
        C.append("5")
    elif 109 <= char and char <= 111:
        C.append("6")
    elif 112 <= char and char <= 115:
        C.append("7")
    elif 116 <= char and char <= 118:
        C.append("8")
    elif 119 <= char and char <= 122:
        C.append("9")

print("".join(C))
