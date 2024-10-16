N, K = map(int, input().split())
arr = [i for i in range(1, N + 1)]

print('<', end="")
while(len(arr) > 1):
  for i in range(0, K - 1):
    arr.append(arr.pop(0))
  print("{}, ".format(arr.pop(0)), end="")
print("{}>".format(arr.pop(0)))