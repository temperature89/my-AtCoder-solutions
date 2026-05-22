### K進数全探索 ###
# import sys
# sys.setrecursionlimit(200000)
# sys.set_int_max_str_digits(0)

# N, B, K = map(int, input().split())
# C = list(map(str, input().split()))

# count = 0
# for i in range(K ** N):
#     n = ""
#     for j in range(N):
#         n += C[(i // (K ** j) % K)]
#     print(n)
#     n = int(n)
#     if n % B == 0:
#         print(n)
#         count += 1
# print(count % (10 ** 9 + 7)) 

### Bの倍数を先に出してから判定 ###
N, B, K = map(int, input().split())
C = list(map(str, input().split()))

B_mul = []
i = 0

while B * i < 10 ** N:
    i += 1
    if B * i < 10 ** (N - 1):
        continue
    B_mul.append(str(B * i))
# print(B_mul)

count = 0
for b in B_mul:
    new_b = b
    # print(f"new_b = {new_b}")
    for c in C:
        # print(f"c={c}")
        # print(f"{new_b}")
        new_b = new_b.replace(c, "")
    else:
        if new_b == "":
            count += 1
            # print(b)
            # print("counted")
        
print(count % (10 ** 9 + 7)) 