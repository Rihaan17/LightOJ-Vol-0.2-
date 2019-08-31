using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

//vector<int>M;
long M[600000], Lazy[600000],ans;

/*void init(int N)
{
        M.clear();
        int length = (int) (2*pow(2.0,floor((log((double)N)/log(2.0))+1)));
        M.resize(length,0);
}*/

void built_tree(int node, int u, int v)
{
        if(u==v)
        {
                Lazy[node]=M[node]=0;
        }
        else
        {
                int mid = (u+v)/2;
                built_tree(node*2, u, mid);
                built_tree(node*2+1, mid+1,v);

                Lazy[node]=M[node]=0;
        }
}

void update(int node, int left, int right, int u, int v, int value)
{

                if(left>v||right<u)
                        return;

                if(left>=u&&right<=v)
                {
                        if(Lazy[node])
                        {
                                M[node]+= (Lazy[node]*(right-left+1));
                                Lazy[node*2]+=Lazy[node];
                                Lazy[node*2+1]+=Lazy[node];
                        }
                        Lazy[node]=value;
                }

                else
                {
                        if(Lazy[node])
                        {
                                M[node]+=(Lazy[node]*(right-left+1));
                                Lazy[node*2]+=Lazy[node];
                                Lazy[node*2+1]+=Lazy[node];
                                Lazy[node] = 0;
                        }

                        M[node] = M[node] + value*(min(right,v)-max(left,u)+1);

                        int mid = (left+right)/2;

                        update(node*2, left, mid, u, v, value);
                        update(node*2+1, mid+1, right, u, v, value);
                }


}

void query(int node, int left, int right, int u, int v)
{
        if(left>v||right<u)
                return;

        if(left>=u&&right<=v)
        {
                if(Lazy[node])
                {
                        M[node] += (Lazy[node]*(right-left+1));
                        Lazy[node*2]+=Lazy[node];
                        Lazy[node*2+1]+=Lazy[node];
                        Lazy[node] = 0;
                }

                ans+= M[node];
        }
        else
        {
                if(Lazy[node])
                {
                        M[node] +=(Lazy[node]*(right-left+1));
                        Lazy[node*2] += Lazy[node];
                        Lazy[node*2+1] += Lazy[node];
                        Lazy[node] = 0;
                }
                int mid = (left+right)/2;

                query(node*2, left, mid, u, v);
                query(node*2+1, mid+1, right, u, v);
        }

}

int main()
{
        int t,n,x,y,type,Case=1,i,q,v;
        scanf("%d",&t);

        while(t--)
        {
                 printf("Case %d:\n",Case++);

                scanf("%d%d",&n,&q);
                built_tree(1,1,n);

                while(q--)
                {
                        scanf("%d",&type);

                        if(type==0)
                        {
                                scanf("%d %d %d",&x,&y,&v);
                                update(1,1,n,x+1,y+1,v);
                        }
                        else
                        {
                                scanf("%d %d",&x,&y);
                                ans=0;
                                query(1,1,n,x+1,y+1);
                                printf("%ld\n",ans);
                        }
                }
        }

        return 0;
}

/*
2
10 5
0 0 9 10
1 1 6
0 3 7 2
0 4 5 1
1 5 5
20 3
0 10 12 1
1 11 12
1 19 19

*/



/*void update(int node, int left, int right, int u, int v, int value)
{

        if(left>=u&&right<=v)
        {
                M[node]+=value;
                return;
        }

        int mid = (left+right)/2;

        if(u<=mid)
                        update(node*2, left, (left+right)/2, u, v, value);
        if(mid<v)
                        update(node*2+1, (left+right)/2+1, right, u, v,value);
        M[node] = M[node*2]+M[node*2+1];

        /if(left>v||right<u)
                return ;


                if(left==right)
                {
                        M[node]+=value;
                }
                else
                {
                        int mid = (left+right)/2;
                        if(u<=mid)
                                update(node*2, left, (left+right)/2, u, v, value);
                        if(mid<v)
                                update(node*2+1, (left+right)/2+1, right, u, v,value);

                        if(left>=u&&right<=v)
                                M[node] = M[node*2]+M[node*2+1];
                }/
}

int query(int node, int left, int right, int u, int v)
{
        if(left>v||right<u)
                return 0;

        if(left>=u&&right<=v)
                return M[node];

        int p1=0,p2=0;

        p1 += query(node*2, left, (left+right)/2, u, v);
        p2 += query(node*2+1, (left+right)/2+1, right, u, v);

        return p1+p2;
}
*/
