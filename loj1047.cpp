using namespace std;

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

#define min(a,b) ((a<b)?(a):(b))

int dp[21][3],n;


int rgb[21][3];

int minimum(int a,int b,int c)
{
    if(a<=b&&a<=c)
        return a;
    else if(b<=a&&b<=c)
        return b;
    else
        return c;
}

int cheak(int f)
{
    if(f<0)
        return 2;
    return f;
}

int solve(int i,int color)
{
    if(i>n)
        return 0;

    if(dp[i][color]!=-1)
        return dp[i][color];

    return dp[i][color]=rgb[i][color]+min(solve(i+1,cheak(color-1)),solve(i+1,(color+1)%3));
}


int main()
{
    int T,i,Case=1;

    scanf("%d",&T);

    while(T--)
    {

        memset(dp,-1,sizeof(dp));
        //cin>>n;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&rgb[i][0],&rgb[i][1],&rgb[i][2]);
            //cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
        }

        //cout<<"Case "<<Case++<<": "<<minimum(solve(1,0),solve(1,1),solve(1,2))<<endl;
        printf("Case %d: %d\n",Case++,minimum(solve(1,0),solve(1,1),solve(1,2)));
    }
    return 0;
}
