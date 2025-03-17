t, p = input().split()
t = int(t)
p = int(p)
result = input().split()
cT = 0
cP = 0
for i in result:
  if(i != 'X'):
    cP += 1
    cT += int(i)

ans = 0
for i in range(1, t):
  result = input().split()
  tT = 0
  tP = 0
  for j in result:
    if(j != 'X'):
      tP += 1
      tT += int(j)
  if tP > cP:
    ans += 1
  else:
    if tP == cP and tT <= cT:
      ans += 1

print(ans)