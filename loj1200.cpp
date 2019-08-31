using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

#define max(a,b) ((a>b)?(a):(b))

int dp[100+5][10000+10],n;

struct info
{
        int c,p,w;
}item[110];

int solve(int it,int w)
{
        if(it>n||w<=0)
                return 0;

        if(dp[it][w]!=-1)
                return dp[it][w];

        int r1=0,r2=0,r3=0;

        if(w-item[it].w>=0)
        {
                r1=solve(it+1,w-item[it].w)+item[it].p;
                r3=solve(it,w-item[it].w)+item[it].p;
        }
        r2=solve(it+1,w);

        return dp[it][w]=max(r1,max(r2,r3));
}

int main()
{
        int t,w,ans,sum,Case=1,i;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&n,&w);

                for(i=1;i<=n;i++)
                {
                        scanf("%d%d%d",&item[i].p,&item[i].c,&item[i].w);
                }

                sum=0;

                for(i=1;i<=n;i++)
                {
                        sum+=(item[i].c*item[i].w);
                }

                if(sum>w)
                {
                        printf("Case %d: Impossible\n",Case++);
                }

                else
                {
                        memset(dp,-1,sizeof(dp));
                        ans=solve(1,w-sum);

                        printf("Case %d: %d\n",Case++,ans);
                }
        }

        return 0;
}
