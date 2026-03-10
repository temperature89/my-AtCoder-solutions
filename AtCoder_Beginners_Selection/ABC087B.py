a = int(input())
b = int(input())
c = int(input())
x = int(input())

count = 0
for an in range(a + 1):
    a_total = 500 * an
    for bn in range(b + 1):
        b_total = 100 * bn
        for cn in range(c + 1):
            c_total = 50 * cn
            
            total = a_total + b_total + c_total
            if total == x:
                count += 1

print(count)