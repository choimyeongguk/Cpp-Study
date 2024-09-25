def cutChoco(r, c):
  if(r == 1 and c == 1):
    return 0
  if(r < c):
    tmp = r
    r = c
    c = tmp
  return 1 + cutChoco(r-1, c) + cutChoco(1, c)

N, M = map(int, input().split())
#print(cutChoco(N, M))
if(N < M):
  N, M = M, N
print((N-1) + N*(M-1))