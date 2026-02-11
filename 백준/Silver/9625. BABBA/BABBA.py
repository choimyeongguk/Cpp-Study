K=int(input())
A=1
B=0
for i in range(K):
    B=A+B
    A=B-A
print(A,B)