using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

int dp[1010][1010];
char str[1010];
bool visited[1010][1010];

int solve(int l1,int l2)
{
        if(l1>l2)
                return 0;

        if(visited[l1][l2])
                return dp[l1][l2];

        visited[l1][l2]=true;

        if(str[l1]==str[l2])
                return dp[l1][l2]=solve(l1+1,l2-1);
        else
        {
                return dp[l1][l2]=1+min(solve(l1+1,l2),solve(l1,l2-1));
        }
}

int main()
{
        int t,Case=1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%s",str);
                int l=strlen(str);

                memset(visited,false,sizeof(visited));

                printf("Case %d: %d\n",Case++,solve(0,l-1));
        }

        return 0;
}
