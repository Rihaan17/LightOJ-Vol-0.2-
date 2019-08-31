using namespace std;

#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cmath>


vector<int>pf[1010];//[2000];
int cost[1010];//[2000];
bool visited[1010];

void prime_factors(int n)
{
    if(n==2)
        return;
    int i,temp=n;
    if(temp%2==0)
    {
        pf[n].push_back(2);
        temp/=2;
        while(temp%2==0)
        {
            temp/=2;
        }
    }

    for(i=3;i<=sqrt(temp);i+=2)
    {
        if(temp%i==0)
        {
            pf[n].push_back(i);
            temp/=i;
            while(temp%i==0)
            {
                temp/=i;
            }
        }
    }

    if(temp>1&&temp!=n)
        pf[n].push_back(temp);
}

int bfs(int s,int d)
{
    if(s==d)
        return 0;
    if(s>d)
        return -1;
    queue<int>Q;
    //memset(cost,0,sizeof(cost));
    memset(visited,false,sizeof(visited));
    cost[s]=0;
    Q.push(s);
    visited[s]=true;

    while(!Q.empty())
    {
        int u=Q.front();
        int i;
        Q.pop();

        for(i=0;i<pf[u].size();i++)
        {
            int v=pf[u][i]+u;
            if(v>d)
                break;//continue;

            if(visited[v]==false)//cost[v]==0)
            {
                visited[v]=true;
                cost[v]=cost[u]+1;
                if(v==d)
                {
                    return cost[v];
                }
                Q.push(v);
            }

        }
    }

    return -1;
}

int main()
{
    int i,t,s,d,ans,Case=1;
    for(i=1;i<=1000;i++)
        prime_factors(i);

   /* for(int i=0;i<pf[2].size();i++)
        cout<<pf[2][i]<<endl;*/

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&s,&d);

        ans=bfs(s,d);

        printf("Case %d: %d\n",Case++,ans);
    }

    return 0;
}
