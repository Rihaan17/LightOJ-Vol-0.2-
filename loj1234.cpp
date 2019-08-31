using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define ll long long

double arr[100000+10];

void pre_cal()
{
        ll i,j,k=1,stop;
        double temp=0.0;
        for(i=0;i<=100000000;i+=1000)
        {
                arr[k]=temp;
                stop=i+1000;
                for(j=i+1;j<=stop;j++)
                {
                        arr[k]+=(double)(1.0/j);
                }

                temp=arr[k];
                k++;
        }
}

ll help(ll x)
{
        return x/1000;
}

int main()
{
        pre_cal();
        ll t,n,i,Case=1,stop;
        double ans;
        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld",&n);
                ans=arr[help(n)];

                stop=n%1000;
                for(i=1+(help(n)*1000);i<=n;i++)
                        ans+=(double)(1.0/i);

                printf("Case %lld: %.10lf\n",Case++,ans);
        }

        return 0;
}


