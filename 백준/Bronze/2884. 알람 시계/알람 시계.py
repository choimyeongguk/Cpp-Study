H, M = map(int, input().split())
M -= 45
if(M < 0):
  M += 60
  H = 23 if(H == 0) else H-1
print("{} {}".format(H, M))