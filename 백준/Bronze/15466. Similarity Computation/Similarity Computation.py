import sys
input = lambda: sys.stdin.readline().rstrip()


for _ in range(int(input())):
    n, m = map(int, input().split())
    s1 = set(map(int, input().split()))
    s2 = set(map(int, input().split()))
    if 2*len(s1 & s2) > len(s1 | s2): print(1)
    else: print(0)
