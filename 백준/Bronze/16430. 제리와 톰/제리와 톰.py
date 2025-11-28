def gcd(a,b):
    return a if b == 0 else gcd(b, a%b)
a,b=map(int,input().split())
g=gcd(b-a,b)
print(f"{(b-a)//g} {b//g}")