using namespace std;

#include<iostream>
#include<cstdio>

int main()
{
    long long int temp,T,n,ans,Case=1;

    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        temp = n;
        ans = 0;
        while(temp)
        {
            ans = (ans*10)+(temp%10);
            temp/=10;
        }

        if(ans==n)
            printf("Case %lld: Yes\n",Case++);
        else
            printf("Case %lld: No\n",Case++);
    }

    return 0;
}
