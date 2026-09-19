import math
A, B, C = map(int, input().split())
mygcd = math.gcd(A,B,C)
print(sum([i // mygcd - 1 for i in [A,B,C]]))