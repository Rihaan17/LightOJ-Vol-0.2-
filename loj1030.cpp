/*using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>*/

#include<stdio.h>
#include<string.h>

#define min(a,b) ((a<b)?(a):(b))

int cost[105],N;
double dp[105];
bool cheaque[105];

double solve(int pos)
{
    if(pos==N)
        return cost[pos];

    if(cheaque[pos]==true)
        return dp[pos];

    int cnt = min(6,N-pos);

    double r=0.0;

    for(int i=1;i<=cnt;i++)
    {
        r+=((double)(cost[pos]+solve(pos+i))/cnt);
    }

    cheaque[pos]=true;
    return dp[pos]=r;
}

int main()
{
    int T,n,i,Case=1;
    scanf("%d",&T);

    while(T--)
    {
        memset(cheaque,false,sizeof(cheaque));
        scanf("%d",&N);

        for(i=1;i<=N;i++)
            scanf("%d",&cost[i]);

        printf("Case %d: %.10lf\n",Case++,(double)solve(1));
    }

    return 0;
}
