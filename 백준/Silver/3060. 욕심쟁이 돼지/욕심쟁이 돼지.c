#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int d=0;
        int t;
        scanf("%d",&t);
        for(int j=1;j<=6;j++)
        {
            int m;
            scanf("%d",&m);
            d+=m;
        }
        int k=0;
        while(t>=d)
        {
            d=4*d;
            k++;
        }
        printf("%d\n",k+1);
    }
}