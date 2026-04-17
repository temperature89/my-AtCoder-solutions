n = int(input())
d_list = []
for i in range(n):
    d_list.append(int(input()))

d_list.sort(reverse=True)
tyded_d_list = []
for d in d_list:
    if d in tyded_d_list:
        continue
    tyded_d_list.append(d)
print(len(tyded_d_list))