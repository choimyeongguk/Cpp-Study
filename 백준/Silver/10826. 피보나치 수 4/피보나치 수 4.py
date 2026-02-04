n=int(input())
if(n<2):
    print(n)
else:
    prev = 0
    cur = 1
    nxt = 1
    for i in range(n-1):
        nxt = prev + cur
        prev = cur
        cur = nxt
    print(cur)