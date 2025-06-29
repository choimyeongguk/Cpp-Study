import sys
input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    s, p = input().split()
    print(len(s.replace(p, "p")))
    
