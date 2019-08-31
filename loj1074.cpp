using namespace std;

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>

#define size 210
#define pr pair<int,int>
#define INF 999999999

pr edge[40010];
int w[size][size],dist[size],nV,nE,flag,jam[size];


void initializing(int s)
{
    int i;
    for(i=1;i<=nV;i++)
    {
        dist[i]=INF;
    }
    dist[s]=0;
}

void update(int u,int v)
{
    if(dist[v]>dist[u]+w[u][v]&&dist[u]!=INF)
    {
        dist[v]=dist[u]+w[u][v];
        flag=0;
    }
}

void bellman_ford(int s)
{
    int i,j,u,v;

    initializing(s);

    for(i=1;i<nV;i++)
    {
        flag=1;
        for(j=0;j<nE;j++)
        {
            update(edge[j].first,edge[j].second);
        }
        if(flag)
            break;
    }

    /*for(i=0;i<nE;i++)
    {
        u=edge[i].first;
        v=edge[i].second;
        if(dist[v]>dist[u]+w[u][v]&&dist[u]!=INF)
            return false;
    }*/

    for(i=0;i<nE;i++)
    {
        u=edge[i].first;
        v=edge[i].second;
        if(dist[v]>dist[u]+w[u][v]&&dist[u]!=INF)
            jam[v]=-1;
    }

    //return true;
}

int main()
{
    int t,u,v,i,dest,q,Case=1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&nV);
        for(i=1;i<=nV;i++)
        {
            scanf("%d",&jam[i]);
        }
        scanf("%d",&nE);

        for(i=0;i<nE;i++)
        {
            scanf("%d%d",&u,&v);
            edge[i].first=u;
            edge[i].second=v;
            w[u][v]=pow((jam[v]-jam[u]),3);
        }

        //bool check=
        bellman_ford(1);

        scanf("%d",&q);

        printf("Case %d:\n",Case++);

        while(q--)
        {
            scanf("%d",&dest);

            if(jam[dest]==-1||dist[dest]<3||dist[dest]>=INF)
            {
               // cout<<dist[dest]<<" "<<check<<endl;
                printf("?\n");
            }
            else
                printf("%d\n",dist[dest]);
        }
    }

    return 0;
}


/*

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cstdlib>

#define FOR(i,n) for(i=1;i<=n;i++)
#define FORa(i,n) for(i=0;i<n;i++)
#define init(i,a,n) for(i=0;i<n;i++)a[i]=i
#define inf 9999999
#define ms0(a) memset(a,0,sizeof(a))
#define msn(a,n) memset(a,n,sizeof(a))
#define LL long long
#define LLU unsigned long long
#define DB double
#define LD long double
#define eps 1e-10
#define SQR(x) ((x)*(x))
#define pb push_back
#define all(x) sort(x.begin(),x.end())
#define inpI ({int a; scanf(" %d", &a); a;})
#define inpD ({DB a; scanf(" %lf", &a); a;})
#define inpLL ({LL a; scanf(" %lld", &a); a;})
#define CS printf("Case %d:\n",cs++)
#define PI 3.1415926535897932384626433832795
int aComp(const void * a, const void * b){return (*(int*)a-*(int*)b );}
int dComp(const void * a, const void * b){return (*(int*)b-*(int*)a );}
//qsort (array,size, sizeof(int), aComp);


using namespace std;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
#define cube(a)((a)*(a)*(a))
#define NODE 205
#define M 205*205

int u[M],v[M],w[M],cost[NODE],d[NODE];
int n,m;

void SPFA()
{

    int i,j,flag;

    msn(d,inf);

    d[1]=0;

    for(i=1;i<n;i++)
    {
        flag=1;
        for(j=0;j<m;j++)
            if(d[ v[j] ]>d[ u[j] ]+ w[j] && d[ u[j] ]!=inf)
                {
                    d[ v[j] ]=d[ u[j] ]+w[j];
                    flag=0;
                }

        if(flag) break;
    }

    FORa(i,m)
        if( (d[ v[i] ]> d[ u[i] ] + w[i]) && d[ u[i] ]!=inf) cost[ v[i] ]=-1;

}

int main()
{


    int T,i,j,k,cs=1;

    T=inpI;

    while(T--)
    {
        n=inpI;

        FOR(i,n)cost[i]=inpI;

        m=inpI;

        FORa(i,m)
        {
            u[i]=inpI,v[i]=inpI;

            w[i]=cube( cost[ v[i] ]- cost[ u[i] ] );

        }

        SPFA();

        n=inpI;

        CS;

        while(n--)
        {
            int x=inpI;

            if(d[ x ]>=inf || d[ x ]<3 || cost[ x ] == -1) printf("?\n");

            else printf("%d\n",d[x]);

        }

    }
    return 0;
}
*/
