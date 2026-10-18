import sys


def solve():
  input = sys.stdin.read
  data = input().split()
  if not data:
    return

  N = int(data[0])
  K = int(data[1])
  T = int(data[2])

  A = [int(x) for x in data[3:]]
  A.sort()

  R = 0
  ans = 0
  i = 0

  while R < T:
    max_end = R
    found = False
    # 現在の右端 R 以下で押された青木君のボタンを調べる
    while i < N and A[i] <= R:
      if A[i] + K > max_end:
        max_end = A[i] + K
      i += 1
      found = True

    # 青木君のボタンで右に進めるなら進む
    if found and max_end > R:
      R = max_end
    else:
      # 進めない場合は高橋君がボタンを追加で押す
      ans += 1
      R += K

  print(ans)


if __name__ == "__main__":
  solve()