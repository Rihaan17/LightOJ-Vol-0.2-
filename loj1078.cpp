using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
        long long int t,Case=1,x,y,temp,cnt;
        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld%lld",&x,&y);

                temp = y;
                cnt=1;

                while(1)
                {
                        if(temp%x==0)
                        break;

                        if(temp>x)
                                temp%=x;
                        temp=temp*10+y;
                        cnt++;
                }

                printf("Case %lld: %lld\n",Case++,cnt);
        }

        return 0;
}
