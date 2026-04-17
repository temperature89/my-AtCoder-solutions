# N = input()
# num_list = input().split(" ")
# i = 0
# for n in num_list:
#     num_list[i] = int(n)
#     i += 1

# def is_all_even(num_list):
#     for n in num_list:
#         if n % 2 == 1:
#             return False
#     return True

# count = 0
# new_num_list = []
# while is_all_even(num_list):
#     for n in num_list:
#         new_num_list.append(n / 2)
#     count += 1
#     num_list = new_num_list
# print(count)

N = int(input())

A = list(map(int, input().split()))

count = 0

while all(a % 2 == 0 for a in A):
   A = [a // 2 for a in A]
   count += 1
print(count)