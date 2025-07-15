import sys
input = lambda: sys.stdin.readline().rstrip()

def tm(rules, n, s):
    tape = [2]*15 + s + [2]*15
    head = 15
    state = 1
    for i in range(10):
        try:
            ns, d, ch = rules[(state, tape[head])]
        except:
            return True
        tape[head] = ch
        head += d
        state = ns
        if state == n: return True
    return False
        

for tc in range(int(input())):
    print(f"Machine #{tc+1}:")
    n = int(input())
    state = 1
    rules = dict()
    for s in range(n-1):
        t = input().replace("(", "").replace(")", "").replace(",", "").split()
        t = list(map(int, t))
        for i in range(0, len(t), 3):
            rules[(s+1, i//3)] = (t[i], t[i+1], t[i+2])
    m = int(input())
    for __ in range(m):
        cmd = list(map(int, input().split()))[1:]
        if tm(rules, n, cmd):
            print("yes")
        else:
            print("no")
    
