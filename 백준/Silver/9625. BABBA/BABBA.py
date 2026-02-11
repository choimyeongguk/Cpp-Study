K=int(input())
A,B=1,0
for i in range(K):
    B=A+B
    A=B-A
print(A,B)