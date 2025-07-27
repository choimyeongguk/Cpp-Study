import sys
input = lambda: sys.stdin.readline().rstrip()


from fractions import Fraction as F

s = input()
d = F(3, 2)
ans = F(0)
for c in s:
    ans *= d
    ans += int(c)

print(int(ans), end=' ')
if ans.denominator!=1:
    print(ans-int(ans))
