a=[int(input())for i in range(5)]
print(a[0]-max((a[i-2]+a[i]-1)//a[i]for i in [3,4]))