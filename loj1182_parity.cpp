#include<stdio.h>

int main()
{
    int T,l,i=1;
    long long int n;
    scanf("%d",&T);
    while(T--)
    {
        l=0;
        scanf("%lld",&n);
        while(n!=0)
        {
            if(n%2==1)
            l++;
            n=n/2;
        }
        if(l%2==0)
        printf("Case %d: even",i++,l);
        else
        printf("Case %d: odd",i++,l);
        printf("\n");
    }
    return 0;
}
