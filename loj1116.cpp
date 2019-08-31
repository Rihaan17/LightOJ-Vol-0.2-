using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>

int main()
{
    long long int T,w,i,a,b;
    int Case=1;
    scanf("%lld",&T);

    while(T--)
    {
        scanf("%lld",&w);

        a=0;
        b=w/2;

        for(i=2;i<=b;i*=2)
        {
            if(w%i==0&&(w/i)%2)
            {
                a=w/i;
                b=i;
                break;
            }
        }
        if(a==0)
        {
            if(w%2==0)
            {
                printf("Case %d: 1 %lld\n",Case++,w);
            }
            else
                printf("Case %d: Impossible\n",Case++);
        }
        else
            printf("Case %d: %lld %lld\n",Case++,a,b);



    }

    return 0;
}
