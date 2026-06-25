A,B,C,K = map(int, input().split())
if abs(A - B) > 10 ** 18:
    print("Unfair")

elif K % 2 == 1:
    print(-A + B)
else:
    print(A - B)