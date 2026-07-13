N = int(input())
count = 0
i = 1
j = 2
k = 0
while i <= N and j <= N:
    print(f"? {i} {j}")
    ans = input()
    if ans == "Yes":
        j += 1
    else:
        k = j - 1
        n = j - i - 1
        count += (j - i - 1 * (j - i - 1 + 1)) / 2 - (k - i - 1 * (k - i - 1 + 1)) / 2
        i += 1
count += (j - i - 1 * (j - i - 1 + 1)) / 2 - (k - i - 1 * (k - i - 1 + 1)) / 2
print(f"! {int(count)}")