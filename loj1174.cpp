using namespace std;

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>

#define max(a,b) ((a>b)? (a):(b))

vector<int>graph[105];
bool visited[105];

int bfs(int s,int d)
{
    if(s==d)
        return 0;
    memset(visited,false,sizeof(visited));
    int cost[105],i,u;
    queue<int>Q;
    visited[s]=true;
    Q.push(s);
    cost[s]=0;

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();

        for(i=0;i<graph[u].size();i++)
        {
            if(visited[graph[u][i]]==false)
            {
                visited[graph[u][i]]=true;
                if(graph[u][i]==d)
                    return cost[u]+1;
                cost[graph[u][i]]=cost[u]+1;
                Q.push(graph[u][i]);
            }
        }
    }
}

int main()
{
    int t,u,v,e,n,s,d,Case=1,i,dst1[105],dst2[105];

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&e);

        for(i=0;i<e;i++)
        {
            scanf("%d%d",&u,&v);

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        scanf("%d%d",&s,&d);

        int ans=0,x,y;

        for(i=0;i<n;i++)
        {
            x=bfs(s,i);
            y=bfs(d,i);
           // cout<<x<<" "<<y<<endl;
            ans=max(ans,x+y);
        }

        printf("Case %d: %d\n",Case++,ans);

        for(i=0;i<=n;i++)
            graph[i].clear();
    }

    return 0;
}











/*using namespace std;

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdio>
#include <utility>

#define INF 100000500
#define min(a,b) ((a<b)?(a):(b))


vector<int>edge[205];
int cost[205],N,i;

void dijkstra (int s) {

    priority_queue<int>Q;

    for(int i=0;i<N;i++)
        cost[i] = INF;
    cost[s] = 0;
    Q.push(s);

    while(!Q.empty())
    {
        long long int u = Q.top();
       // cout<<u<<endl;
        Q.pop();

        for(i=0;i<edge[u].size();i++)
        {
            long long int v = edge[u][i];

            if(cost[v]>(1+cost[u]))
            {
                cost[v]=1+cost[u];
                Q.push(v);
            }
        }
    }
}

int cost_counter(int x)
{
    if(x==0)
        return 0;
    return cost[x]+cost_counter(x-1);
}

int main()
{
    int T,e,ans,Case=1,u,v;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&e);

        for(i=0;i<=e;i++)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        dijkstra(0);
        ans=0;
        for(i=N-1;i>0;i--)
            ans+=cost[i];
       //ans = cost_counter(N-1);

        printf("Case %d: %d\n",Case++,ans);
    }
}*/
