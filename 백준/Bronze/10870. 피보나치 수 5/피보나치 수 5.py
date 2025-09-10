def f(x):
    return x if x<2 else f(x-1)+f(x-2)
print(f(int(input())))