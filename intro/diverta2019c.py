N = int(input())
S = [input() for n in range(N)]
count = 0
begin_b = 0
end_a = 0
b_a = 0
for i, s in enumerate(S):
    count += s.count("AB")
    if s[0] == "B" and s[-1] == "A":
        b_a += 1
    elif s[0] == "B":
        begin_b += 1
    elif s[-1] == "A":
        end_a += 1

if begin_b == 0 and end_a == 0:
    count += max(b_a - 1, 0)
else :
    count += b_a + min(begin_b, end_a)
print(count)