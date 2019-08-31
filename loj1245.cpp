using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>

#define ll long long

int main()
{
        ll t,n,i,ans,Case=1,temp,temp2;
        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld",&n);

                if(n==1)
                {
                        printf("Case %lld: 1\n",Case++);
                        continue;
                }

                if(n==2)
                {
                        printf("Case %lld: 3\n",Case++);
                        continue;
                }

                if(n==3)
                {
                        printf("Case %lld: 5\n",Case++);
                        continue;
                }

                ans=n; temp=sqrt(n);
                if(n%2) ans+=(n/2)+1;
                else ans+=(n/2);
                for(i=2;i<=temp+1;i++)
                {
                        if(i<temp)
                                ans+=(n/i)+i;

                        if(i>2)
                        {
                                temp2 = (n/(i-1)) - (n/i);
                                temp2--;
                                ans += (temp2*(i-1));
                        }

                        //cout<<ans<<endl;
                }

                if(n/temp!=temp) ans+=(n/temp+temp);
                else ans+=(n/temp);

                printf("Case %lld: %lld\n",Case++,ans);
        }
}

