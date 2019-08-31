using namespace std;

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>

struct edge
{
    int u,v,w;

    bool operator < (const edge &p) const
    {
        return w<p.w;
    }
};

vector<edge>graph;
int mp,parent[105];

int parent_find(int u)
{
    return (u==parent[u])?u:parent_find(parent[u]);
}

void mst()
{
    int count=0,i,ans=0,s=graph.size();
    sort(graph.begin(),graph.end());

    for(i=1;i<mp;i++)
        parent[i]=i;

    for(i=0;i<s;i++)
    {
        int u=parent_find(graph[i].u);
        int v=parent_find(graph[i].v);

        if(u!=v)
        {
            parent[u]=v;
            count++;
            ans+=graph[i].w;
            if(count==mp-2)
                break;
        }
    }

    if(count==mp-2)
    {
        printf("%d\n",ans);
    }
    else
    {
        printf("Impossible\n");
    }
}

int main()
{
    int t,i,w,Case=1,n;
    string str1,str2;
    scanf("%d",&t);

    while(t--)
    {
        map<string,int>m;
        graph.clear();
        scanf("%d",&n);
        mp=1;

        while(n--)
        {
            cin>>str1>>str2;
            scanf("%d",&w);

            if(!m[str1])
                m[str1]=mp++;
            if(!m[str2])
                m[str2]=mp++;

            edge e;
            e.u=m[str1];
            e.v=m[str2];
            e.w=w;

            graph.push_back(e);
        }

        printf("Case %d: ",Case++);
        mst();
    }

    return 0;
}
