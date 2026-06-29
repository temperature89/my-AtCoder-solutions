H, W = map(int, input().split())
C = [input() for h in range(H)]

def trim(C):
    global endflag
    up_cut_flag = False
    down_cut_flag = False
    if C[0].count(".") == len(C[0]):
        del C[0]
        up_cut_flag = True
    if C[-1].count(".") == len(C[-1]):
        del C[-1]
        down_cut_flag = True
    # print(C)
    left_cut_flag = True
    right_cut_flag = True
    for c in C:
        if c[0] == "#":
            left_cut_flag = False
        if c[-1] == "#":
            right_cut_flag = False
    # print(left_cut_flag, right_cut_flag)
    if left_cut_flag == True:
        for h in range(len(C)):
            C[h] = C[h][1:]
    if right_cut_flag == True:
        for h in range(len(C)):
            C[h] = C[h][:-1]
    # print(C)
    if not (up_cut_flag or down_cut_flag or left_cut_flag or right_cut_flag):
        endflag = True
    return C

endflag = False
while endflag == False:
    C = trim(C)
for c in C:
    print(c)