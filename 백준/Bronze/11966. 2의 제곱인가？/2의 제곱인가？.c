#include<stdio.h>
main(int n){scanf("%d",&n);printf("%d",(__builtin_popcount(n)==1));}