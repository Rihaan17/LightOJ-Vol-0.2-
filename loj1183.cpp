using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

long long int M[600000], lazy[600000];

long long int gcd (long long int a, long long int b)
{
        if(b==0)
                return a;
        return gcd(b,a%b);
}

void built_tree (long long int node, long long int u, long long int v)
{
        if(u==v)
        {
                M[node] = 0;
                lazy[node] = -1;
        }
        else
        {
                built_tree(node*2, u, (u+v)/2);
                built_tree(node*2+1, (u+v)/2+1,v);

               M[node] = 0;
               lazy[node] = -1;
        }
}

void ud(long long int node, long long int a, long long int b)
{
        if(lazy[node]!=-1)
        {
                M[node]=lazy[node]*(b-a+1);
                if(a!=b)
                        lazy[node*2]=lazy[node*2+1]=lazy[node];
                lazy[node]=-1;
        }
}


void update_tree (long long int node, long long int left, long long int right, long long int u, long long int v,long long int value)
{
         ud(node, left, right);

        if(left>v||right<u)
                return ;


        if(left>=u&&right<=v)
        {
                M[node] = (right-left+1)*value;

                if(left!=right)
                        lazy[node*2] = lazy[node*2+1] = value;
        }

        else
        {
                update_tree(node*2, left, (left+right)/2, u, v, value);
                update_tree(node*2+1, (left+right)/2+1, right, u, v, value);
                M[node] = M[node*2]+M[node*2+1];
        }
}

long long int query (long long int node, long long int left, long long int right, long long int u, long long int v)
{
        if(left>v||right<u)
                return 0;

        ud(node, left, right);

        if(left>=u&&right<=v)
        {
                return M[node];
        }

        else
        {
               long long int r1=query(node*2, left, (left+right)/2, u, v);
               long long int r2=query(node*2+1, (left+right)/2+1, right, u, v);
               return r1+r2;
        }
}

int main()
{
        long long int t, Case=1, n, q, type,x,y,value,ans,cnt,temp;

        scanf("%lld",&t);

        while(t--)
        {
                scanf("%lld%lld",&n,&q);

                built_tree(1, 1, n);

                printf("Case %lld:\n",Case++);

                while(q--)
                {
                        scanf("%lld",&type);

                        if(type==1)
                        {
                                scanf("%lld%lld%lld",&x,&y,&value);
                                update_tree(1, 1, n, x+1, y+1, value);
                        }
                        else
                        {
                                scanf("%lld%lld",&x,&y);
                                ans=query(1, 1, n, x+1, y+1);

                                cnt=y-x+1;

                               // cout<<ans<<"    "<<cnt<< "    tushar"<<endl;

                                if(ans%cnt==0)
                                {
                                        printf("%lld\n",ans/cnt);
                                }
                                else
                                {
                                        temp = gcd(ans, cnt);
                                        ans/= temp;
                                        cnt/= temp;
                                        printf("%lld/%lld\n",ans,cnt);
                                }
                        }
                }
        }

        return 0;
}


/*
Sample Input
1
10 6
1 0 6 6
2 0 1
1 1 1 2
2 0 5
1 0 3 7
2 0 1
Sample Output
Case 1:
6
16/3
7
*/
