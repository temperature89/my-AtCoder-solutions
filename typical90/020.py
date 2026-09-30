import math
a,b,c = map(int, input().split())
# up = 10 ** 16
# right = math.log(a, 2) * up
# left = math.log(c, 2) * up
# left *= b
# print(right, left)
# if right < left:
if a < c ** b:
    print("Yes")
else:
    print("No")
    
"""
logA = BlogC
A = C**B
"""