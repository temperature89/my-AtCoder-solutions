N = int(input())
A = list(map(int, input().split()))
A.sort()


def check():
    i = 0
    j = 1
    while i < N - 1:
        # print(A[i])
        if A[i] < 0:
            while A[j] > 0:
                j += 1
                # print(f"j:{j}")
                if j > N - 1:
                    if -A[i] > A[i + 1]:
                        A[i] = -A[i]
                        A[i + 1] = -A[i + 1]
                    print(sum(A))
                    return 0
            # print(A[j])
            A[i] = -A[i]
            A[j] = -A[j]
            i = j + 1
            j = i + 1
            # print(A)
        else:
            i += 1
            j = i + 1
    print(sum(A))
check()

# N = int(input())
# A = list(map(int, input().split()))

# # 1. すべての要素の「絶対値」の総和（とりあえず全員プラスにして足す）
# abs_sum = sum(abs(x) for x in A)

# # 2. 最初の数列に含まれる「負の数」の個数を数える
# negative_count = sum(1 for x in A if x < 0)

# # 3. 数列全体の「絶対値の最小値」を探す
# min_abs = min(abs(x) for x in A)

# # 負の数が奇数個なら、一番数字が小さい（絶対値最小の）要素を1つだけマイナスにする
# # （全体からその要素の絶対値を「2倍」引くことで、プラスからマイナスにひっくり返したことになる）
# if negative_count % 2 == 1:
#     print(abs_sum - 2 * min_abs)
# else:
#     print(abs_sum)
    
