c = 299792458.0
a,b = map(float, input().split())
v = (a+b)/(1+(a*b)/(c*c))
print(v)