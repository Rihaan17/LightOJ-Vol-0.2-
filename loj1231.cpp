using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int dp[55][1005],Mtaka,n;
int coin[55],taken[55];

int solve(int i,int taka)
{
    if(i>=n)
    {
        if(taka==0)
        {
            return 1;
        }
        return 0;
    }

    if(dp[i][taka]!=-1)
        return dp[i][taka];

    int r1=0,r2=0;


    for(int k=0;k<taken[i];k++)
    {
        if(taka-coin[i]*(k+1)>=0)
        {
            r1+=solve(i+1,taka-coin[i]*(k+1))%100000007;
        }
        else
           break;
    }

    r2+=solve(i+1,taka)%100000007;
    return dp[i][taka]=(r1%100000007+r2%100000007)%100000007;
}

int main()
{
    int T,i,Case=1;
    scanf("%d",&T);


    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d%d",&n,&Mtaka);

        for(i=0;i<n;i++)
        {
            scanf("%d",&coin[i]);
        }

        for(i=0;i<n;i++)
        {
            scanf("%d",&taken[i]);
        }

        printf("Case %d: %d\n",Case++,solve(0,Mtaka)%100000007);
    }

    return 0;
}
