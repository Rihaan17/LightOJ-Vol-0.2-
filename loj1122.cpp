#include<string.h>
#include<stdio.h>

int absolute(int x)
{
        if(x<0) return -x;
        return x;
}

int n,m,arr[11],dp[11][11];


int solve(int ldigit, int no)
{
        if(no==n) return 1;

        if(dp[ldigit][no]!=-1) return dp[ldigit][no];

        int r1=0;

        for(int i=0;i<m;i++)
        {
                if(absolute(arr[i]-ldigit)<=2)
                        r1+=solve(arr[i],no+1);
        }

        return dp[ldigit][no]=r1;
}

int main()
{
        int t,i,Case=1,ans;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&m,&n);

                for(i=0;i<m;i++)
                        scanf("%d",&arr[i]);

                memset(dp,-1,sizeof(dp));

                ans=0;

                for(i=0;i<m;i++)
                        ans+=solve(arr[i],1);

                printf("Case %d: %d\n",Case++,ans);
        }

        return 0;
}





/*using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int absolute(int x)
{
        if(x<0) return -x;
        return x;
}

int n,m,arr[12],dp[12][12];


int solve(int ldigit, int no)
{
        if(no==n) return 1;

        if(dp[ldigit][no]!=-1) return dp[ldigit][no];

        int r1=0;

        for(int i=0;i<m;i++)
        {
                if(absolute(arr[i]-ldigit)<=2)
                        r1+=solve(arr[i],no+1);
        }

        return dp[ldigit][no]=r1;
}

int main()
{
        int t,i,Case=1,ans;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&m,&n);

                for(i=0;i<m;i++)
                        scanf("%d",&arr[i]);

                memset(dp,-1,sizeof(dp));

                ans=0;

                for(i=0;i<m;i++)
                        ans+=solve(arr[i],1);

                printf("Case %d: %d\n",Case++,ans);
        }

        return 0;
}
*/
