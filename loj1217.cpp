using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>


#define max(a,b) ((a>b)?(a):(b))

long dp[1010],n,arr[1010];
bool check[1010];

long solve(long i,long finish)
{
        if(i>finish)
                return 0;

        if(check[i])
                return dp[i];

       long r1=arr[i]+solve(i+2,finish);
       long r2=solve(i+1,finish);

       check[i]=true;
       return dp[i]=max(r1,r2);
}

int main()
{
        long i,t,Case=1;
        scanf("%ld",&t);

        while(t--)
        {
                scanf("%ld",&n);

                for(i=1;i<=n;i++)
                        scanf("%ld",&arr[i]);

                memset(check,false,sizeof (check));

                long ans=solve(1,n-1);

                 memset(check,false,sizeof (check));

                 ans=max(ans,solve(2,n));

                printf("Case %ld: %ld\n",Case++,ans);
        }

        return 0;
}
