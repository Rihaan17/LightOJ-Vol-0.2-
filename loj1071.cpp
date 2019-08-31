
// UNSOLVED........:(

using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

#define max(a,b) ((a>b)?(a):(b))

int dp[102][102],arr[102][102],m,n;
bool visited[102][102];

int solve1(int i,int j)
{
    if(i==m&&j==n)
    {
        return arr[i][j];
    }

    if(visited[i][j]==true)
        return dp[i][j];

    int r1=0,r2=0;

    if(i+1<=m)
        r1=arr[i][j]+solve1(i+1,j);
    if(j+1<=n)
        r2=arr[i][j]+solve1(i,j+1);

    visited[i][j]=true;

    return dp[i][j]=max(r1,r2);
}

int solve2(int i,int j)
{
    if((i==1&&j==1)||(visited[i][j]==true))
    {
        return arr[i][j];
    }

    if(dp[i][j]!=-1)
        return dp[i][j];

    int r1=0,r2=0;

    if(i-1>=1)
        r1=arr[i][j]+solve2(i-1,j);
    if(j-1>=1)
        r2=arr[i][j]+solve2(i,j-1);

    return dp[i][j]=min(r1,r2);
}

int main()
{
    int T,Case=1;
    scanf("%d",&T);

    while(T--)
    {

        scanf("%d%d",&m,&n);

        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&arr[i][j]);

        memset(visited,false,sizeof(visited));
        int ans1=solve1(1,1);
        memset(dp,-1,sizeof(dp));
        int ans2=solve2(m,n);

        //cout<<ans1<<" "<<ans2<<endl;

        printf("Case %d: %d\n",Case++,ans1+ans2+1);
    }
}

