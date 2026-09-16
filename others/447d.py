S = input()
A_max = S.count("A")
B_max = S.count("B")
C_max = S.count("C")
max_cnt = min(A_max, B_max, C_max)

A_cnt = 0
B_cnt = 0
C_cnt = 0
for s in S:
    if s == "A":
        A_cnt += 1
    elif s == "B" and A_cnt > B_cnt:
        B_cnt += 1
    elif s == "C" and B_cnt > C_cnt:
        C_cnt += 1
    
    # print(s, A_cnt, B_cnt, C_cnt)
    if C_cnt == max_cnt:
        break
print(C_cnt)