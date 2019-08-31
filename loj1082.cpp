using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

#define sz 100000+10
typedef long long int ll_d;

int arr[sz],M[270000],n;

/*void init_segmentTree(int N)
{
        int i,l = int(2.0*pow(2.0,floor(log((double)N)/log(2.0)+1)));
        for(i=0;i<=l;i++)
                M[i]=0;
}
*/
void built_segment_tree(int node,int u,int v)
{
        if(u==v)
                M[node]=u;
        else
        {
                built_segment_tree(2*node,u,(u+v)/2);
                built_segment_tree(2*node+1,((u+v)/2)+1,v);

                if(arr[M[2*node]]<=arr[M[2*node+1]])
                        M[node]=M[2*node];
                else
                        M[node]=M[2*node+1];
        }
}

int Query(int node,int b,int e,int u,int v)
{
        if(u>e||b>v)
                return -1;

        if(b>=u&&e<=v)
                return M[node];

        int  p1=Query(node*2,b,(b+e)/2,u,v);
        int  p2=Query(node*2+1,(b+e)/2+1,e,u,v);

        if(p1==-1)
                return p2;
        if(p2==-1)
                return p1;
        if(arr[p1]<=arr[p2])
                return p1;
        return p2;
}

int main()
{
        int u,v,t,i,Case=1,q;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d %d",&n,&q);

               // init_segmentTree(n);

                for(i=0;i<n;i++)
                {
                        scanf("%d",&arr[i]);
                }

                built_segment_tree(1,0,n-1);

                printf("Case %d:\n",Case++);

                while(q--)
                {
                        scanf("%d%d",&u,&v);
                        printf("%d\n",arr[Query(1,0,n-1,u-1,v-1)]);
                }
        }

        return 0;
}
