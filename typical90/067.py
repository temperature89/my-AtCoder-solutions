def base8_to_base10(s):
    val = 0
    for char in s:
        digit = ord(char) - ord('0')
        val = val * 8 + digit
    return val

def base10_to_base9(n):
    if n == 0:
        return "0"
    
    res = []
    while n > 0:
        res.append(str(n % 9))
        n //= 9
    
    return "".join(reversed(res))

def solve():
    N, K = input().split()
    K = int(K)

    if N == "0":
        print(0)
        return
    
    curr = N
    for _ in range(K):
        val_10 = base8_to_base10(curr)
        s_9 = base10_to_base9(val_10)
        curr = s_9.replace('8', '5')
    print(curr)

if __name__ == "__main__":
    solve()